// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: target is an import thunk (jmp [IAT]) into rgmain.dll. A tail call through a
// dllimport function with the same register args (ecx = this) compiles to the same jmp.
namespace Ogre
{
	class Technique;
	class Renderable;
}

extern "C" __declspec(dllimport) Ogre::Technique* __fastcall fn_0069fcf0(const Ogre::Renderable* self);

namespace Ogre
{
	class Renderable
	{
	public:
		virtual Technique* getTechnique() const;
	};

	Technique* Renderable::getTechnique() const
	{
		return fn_0069fcf0(this);
	}
}
