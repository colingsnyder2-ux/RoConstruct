// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069fd0e is a linker import thunk (jmp [IAT]) into rgmain.dll, not compiled code.
// INFERRED: no class header was provided, so this declares a minimal Ogre::Renderable.
// The body tail-calls a dllimport symbol so /O2 emits "jmp dword ptr [__imp_...]".
// The real thunk comes from linking against rgmain's import library.
namespace Ogre
{
	class Renderable;
}

// INFERRED: stands in for the rgmain.dll export. A one-argument __fastcall passes `this` in ecx, as __thiscall does.
extern "C" __declspec(dllimport) unsigned short __fastcall rgmain_getNumWorldTransforms(const Ogre::Renderable* self);

namespace Ogre
{
	class Renderable
	{
	public:
		virtual unsigned short getNumWorldTransforms(void) const;
	};

	unsigned short Renderable::getNumWorldTransforms(void) const
	{
		return rgmain_getNumWorldTransforms(this);
	}
}
