// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069ff60 is a linker-generated import thunk (jmp dword ptr [IAT]) into the
// Ogre DLL, so there is no real body to recover. The Ogre headers are not reachable, so this
// file declares a minimal stand-in class. The member forwards to a dllimport function with the
// same thiscall signature, so /O2 turns the call into a tail jump through the import slot.
namespace Ogre
{
	// INFERRED: stand-in for the DLL-side implementation, reached through the IAT.
	struct SceneNodeImport
	{
		__declspec(dllimport) void flipVisibilityImpl(bool cascade);
	};

	class SceneNode
	{
	public:
		virtual void flipVisibility(bool cascade);
	};

	void SceneNode::flipVisibility(bool cascade)
	{
		reinterpret_cast<SceneNodeImport*>(this)->flipVisibilityImpl(cascade);
	}
}
