// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fe64 is an import thunk (jmp [0x804224]) to rgmain.dll's Ogre::Node::setListener.
// INFERRED: the original had no source here. The linker generated the thunk from the import lib.
// Best analog: a body that tail-calls a dllimport'd __thiscall member with the same argument,
// so /O2 emits a single jmp through the import slot.
namespace Ogre
{
	class Node
	{
	public:
		class Listener;
		virtual void setListener(Listener* listener);
	};

	// INFERRED: stand-in for the rgmain.dll export ?setListener@Node@Ogre@@UAEXPAVListener@12@@Z.
	struct NodeImport
	{
		__declspec(dllimport) void setListener(Node::Listener* listener);
	};

	void Node::setListener(Listener* listener)
	{
		reinterpret_cast<NodeImport*>(this)->setListener(listener);
	}
}
