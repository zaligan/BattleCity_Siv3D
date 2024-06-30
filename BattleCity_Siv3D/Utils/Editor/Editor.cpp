# include "Editor.hpp"
# include "NotificationAddon.hpp"
# include "ConfigObjects.hpp"

bool Editor::init()
{
	// アドオンを登録する
	Addon::Register<NotificationAddon>(U"NotificationAddon");

	//画面上に通知を表示しておく時間(秒)
	NotificationAddon::SetLifeTime(10.0);

	//通知の横幅を設定する
	NotificationAddon::SetStyle({ .width = 900 });

	return true;
}

bool Editor::prepareConfigDirectory()
{
	//DirectoryMonitorで監視する config ディレクトリのパスとファイルの拡張子を指定します。
	if (not m_configDirectoryMonitor.init(U"config/", { U"json",U"ini",U"txt"}))
	{
		return false;
	}
	return true;
}

void Editor::registerJSONParser()
{
	// ConfigParser に JSONParser を登録します。
	m_configParser.addJSONParser(SolidColorBackground::DataType, &SolidColorBackground::Parse);
	m_configParser.addJSONParser(CircleObject::DataType, &CircleObject::Parse);
	m_configParser.addJSONParser(TestParsePrint::DataType, &TestParsePrint::Parse);
}

void Editor::update()
{
	m_configDirectoryMonitor.update();

	//変更のあった config ディレクトリを全て調べます。
	for (const auto& changedConfigFile : retrieveChangedConfigFiles())
	{
		// ファイルパスを相対パスに変換します。
		const FilePath friendlyPath = FileSystem::RelativePath(changedConfigFile);
		Editor::ShowInfo(U"configファイル`{}`が更新されました。"_fmt(friendlyPath));

		// 拡張子が .json の場合、JSON ファイルとして読み込みます。
		if (const String extension = FileSystem::Extension(changedConfigFile); (extension == U"json"))
		{
			// パースが失敗（nullptr）なら何もしません。
			if (auto pConfig = m_configParser.parseJSON(changedConfigFile, friendlyPath))
			{
				// パースに成功した場合、configs に追加します。
				m_configs[pConfig->dataType()] = std::move(pConfig);
			}
		}
	}
}

HashTable<String, std::unique_ptr<IConfig>>& Editor::getConfigs()
{
	return m_configs;
}

Array<FilePath> Editor::retrieveChangedConfigFiles()
{
	return m_configDirectoryMonitor.retrieveChangedFiles();
}

void Editor::ShowVerbose([[maybe_unused]]const StringView text)
{
# if SIV3D_BUILD(DEBUG)
	NotificationAddon::Show(text, NotificationAddon::Type::Normal);
# endif
}

void Editor::ShowInfo(const StringView text)
{
	NotificationAddon::Show(text, NotificationAddon::Type::Information);
}

void Editor::ShowSuccess(const StringView text)
{
	NotificationAddon::Show(text, NotificationAddon::Type::Success);
}

void Editor::ShowWarning(const StringView text)
{
	NotificationAddon::Show(text, NotificationAddon::Type::Warning);
}

void Editor::ShowError(const StringView text)
{
	NotificationAddon::Show(text, NotificationAddon::Type::Failure);
}
