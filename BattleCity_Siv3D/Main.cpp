# include <Siv3D.hpp> // Siv3D v0.6.14
# include "Scenes/Common.hpp"
# include "Scenes/Game.hpp"
# include "behaviortree_cpp/bt_factory.h"
# include "BT_Nodes/SampleNodes.hpp"
# include "Utils/AssetReader.hpp"


# if SIV3D_BUILD(DEBUG)
# pragma comment(lib, "behaviortree_cppd")
# else
# pragma comment(lib, "behaviortree_cpp")
# endif

using namespace Util;

void Main()
{
	//シーンマネージャーを作成
	App manager;
	//シーンの追加
	manager.add<Game>(State::Game);

	//アセット情報を登録
	AssetReader assetReader(U"asset-list.tsv");
	if (not assetReader.init())
	{
		throw Error{ U"AssetReaderの初期化に失敗しました。" };
	}
	if (not assetReader.registerAsset())
	{
		throw Error{ U"アセットの登録に失敗しました。" };
	}

	BehaviorTreeFactory factory;

	factory.registerNodeType<SaySomething>("SaySomething");
	factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

	auto tree = factory.createTreeFromFile("../my_tree.xml");

	tree.tickWhileRunning();

	while (System::Update())
	{
		//TimeUtilを更新
		updateTimeUtil();

		//シーンに実装された.update() 次に.draw()の順で実行される
		if (not manager.update())
		{
			break;
		}
	}
}
