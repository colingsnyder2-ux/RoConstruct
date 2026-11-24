// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0069fd1a is a linker-made import thunk (jmp [IAT]) from rgmain.dll's import lib.
// A thiscall wrapper that tail-calls a dllimport function with the same arguments makes
// /O2 emit `jmp dword ptr [__imp_...]`, which is the same bytes as the thunk.
namespace Ogre
{
	class Renderable;
}

extern "C" __declspec(dllimport) bool __fastcall rgmain_Renderable_getNormaliseNormals(const Ogre::Renderable* self);

namespace Ogre
{
	class Renderable
	{
	public:
		virtual bool getNormaliseNormals(void) const;
	};

	bool Renderable::getNormaliseNormals(void) const
	{
		return rgmain_Renderable_getNormaliseNormals(this);
	}
}
