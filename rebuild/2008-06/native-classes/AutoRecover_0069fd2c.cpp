// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0069fd2c is a linker import thunk (jmp [IAT]) into rgmain.dll's
// Ogre::Renderable::getCastsShadows. The body below tail-calls a same-ABI
// dllimport, so /O2 emits `jmp dword ptr [__imp_...]`. The imported class name
// is a stand-in, so the IAT symbol name differs from the original.
namespace Ogre
{
	class __declspec(dllimport) RenderableImp
	{
	public:
		bool getCastsShadows(void) const;
	};

	class Renderable
	{
	public:
		virtual bool getCastsShadows(void) const;
	};

	bool Renderable::getCastsShadows(void) const
	{
		return reinterpret_cast<const RenderableImp*>(this)->getCastsShadows();
	}
}
