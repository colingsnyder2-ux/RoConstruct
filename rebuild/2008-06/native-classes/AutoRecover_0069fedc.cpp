// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// The target at 0x0069fedc is an import thunk: jmp dword ptr [IAT slot] into the Ogre module.
// C++ cannot define a thunk with the same name as a dllimport function.
// INFERRED: a tail call through a dllimport function (same register convention) compiles to
// "jmp dword ptr [__imp_...]", which has the same instruction shape as the original.
// INFERRED: no headers were given, so this minimal class stands in for the real one.

namespace Ogre
{
	class SceneNode;
}

// INFERRED: stand-in for the imported Ogre implementation; this pointer arrives in ecx.
extern "C" __declspec(dllimport) void __fastcall ogre_SceneNode_notifyRootNode_import(Ogre::SceneNode* self);

namespace Ogre
{
	class SceneNode
	{
	public:
		virtual void _notifyRootNode(void);
	};

	void SceneNode::_notifyRootNode(void)
	{
		ogre_SceneNode_notifyRootNode_import(this);
	}
}
