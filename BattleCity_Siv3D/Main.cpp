# include <Siv3D.hpp> // Siv3D v0.6.14
# include "behaviortree_cpp/bt_factory.h"

# if SIV3D_BUILD(DEBUG)
# pragma comment(lib, "behaviortree_cppd")
# else
# pragma comment(lib, "behaviortree_cpp")
# endif

using namespace BT;

class SaySomething : public BT::SyncActionNode
{
public:
	SaySomething(const std::string& name, const BT::NodeConfig& config) :
		BT::SyncActionNode(name, config)
	{}

	BT::NodeStatus tick() override
	{
		std::string msg;
		getInput("message", msg);
		//std::cout << msg << std::endl;
		Print << Unicode::Widen(msg);
		return BT::NodeStatus::SUCCESS;
	}

	static BT::PortsList providedPorts()
	{
		return { BT::InputPort<std::string>("message") };
	}
};

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
	ThinkWhatToSay(const std::string& name, const BT::NodeConfig& config) :
		BT::SyncActionNode(name, config)
	{}

	BT::NodeStatus tick() override
	{
		setOutput("text", "The answer is 42");
		return BT::NodeStatus::SUCCESS;
	}

	static BT::PortsList providedPorts()
	{
		return { BT::OutputPort<std::string>("text") };
	}
};

int main2()
{

	BehaviorTreeFactory factory;

	factory.registerNodeType<SaySomething>("SaySomething");
	factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

	auto tree = factory.createTreeFromFile("../my_tree.xml");

	tree.tickWhileRunning();

	return 0;
}

void Main()
{
	main2();

	while (System::Update())
	{

	}
}
