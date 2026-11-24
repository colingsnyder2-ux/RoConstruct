// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0069fd44 is a one-instruction thunk (jmp dword ptr [0x804164]) into rgmain's
// Ogre::SceneNode::setParent. A same-signature tail call through a dllimport member should make
// /O2 emit the same "jmp dword ptr [__imp_...]".
// INFERRED: the classes are declared minimally here because the exact header path is not known.

namespace Ogre
{
	class Node;

	class SceneNode
	{
	public:
		// INFERRED: stand-in for the imported implementation; its name is arbitrary and only the
		// thiscall signature matters for the tail call.
		__declspec(dllimport) void setParentImported(Node* parent);

	protected:
		virtual void setParent(Node* parent);
	};

	void SceneNode::setParent(Node* parent)
	{
		setParentImported(parent);
	}
}
