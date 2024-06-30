# include <Siv3D.hpp> // Siv3D v0.6.14
# include "behaviortree_cpp/bt_factory.h"
# include "BT_Nodes/SampleNodes.hpp"

# if SIV3D_BUILD(DEBUG)
# pragma comment(lib, "behaviortree_cppd")
# else
# pragma comment(lib, "behaviortree_cpp")
# endif

void Main()
{
	BehaviorTreeFactory factory;

	factory.registerNodeType<SaySomething>("SaySomething");
	factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

	auto tree = factory.createTreeFromFile("../my_tree.xml");

	tree.tickWhileRunning();

	while (System::Update())
	{

	}
}
