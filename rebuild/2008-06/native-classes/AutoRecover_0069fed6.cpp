// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target at 0x0069fed6 is a bare import thunk (jmp dword ptr [0x804294]) that
// forwards Ogre::SceneNode::isInSceneGraph to the implementation imported from the Ogre DLL.
// No headers were available, so a minimal SceneNode is declared here. The body tail-calls a
// dllimport __thiscall member (on a stand-in class), which makes the compiler emit
// "jmp dword ptr [__imp_...]" with ecx passed through untouched.

namespace Ogre
{
	// INFERRED: stand-in for the imported implementation; only the IAT jump matters.
	struct ImportedSceneNode
	{
		__declspec(dllimport) bool isInSceneGraphImpl(void) const;
	};

	class SceneNode
	{
	public:
		virtual bool isInSceneGraph(void) const;
	};

	bool SceneNode::isInSceneGraph(void) const
	{
		return reinterpret_cast<const ImportedSceneNode*>(this)->isInSceneGraphImpl();
	}
}
