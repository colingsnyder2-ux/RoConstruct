// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fe70 is the import thunk "jmp dword ptr [0x80422c]" for rgmain!?setInitialState@Node@Ogre@@UAEXXZ.
// No Ogre header is available, so a minimal Node declaration is used.
// INFERRED: the real import is the mangled C++ symbol of Ogre::Node::setInitialState exported by rgmain.
// It is modelled here as a dllimport __fastcall function taking only `this` (ecx). With a single
// argument, edx is not touched, so the tail call compiles to a bare jmp [__imp_...].

namespace Ogre
{
	class Node
	{
	public:
		virtual void setInitialState();
	};
}

// INFERRED: stand-in for the imported rgmain export, which takes this in ecx.
extern "C" __declspec(dllimport) void __fastcall rgmain_Ogre_Node_setInitialState(Ogre::Node* self);

void Ogre::Node::setInitialState()
{
	rgmain_Ogre_Node_setInitialState(this);
}
