// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0069fd38 is a linker import thunk (jmp [__imp_...]) from rgmain's import lib.
// The object never defines it, so the thunk bytes can't come from a plain reference.
// This forwards `this` and the stack arg unchanged to a dllimport member of the same
// signature. /O2 tail-calls it, which emits `jmp dword ptr [__imp_...]`.
namespace Ogre
{
	// INFERRED: stand-in for the rgmain.dll export; only the import-slot jump matters.
	class RenderableImport
	{
	public:
		__declspec(dllimport) void setPolygonModeOverrideable(bool override);
	};

	class Renderable
	{
	public:
		virtual ~Renderable() {}
		virtual void setPolygonModeOverrideable(bool override);
	};

	void Renderable::setPolygonModeOverrideable(bool override)
	{
		reinterpret_cast<RenderableImport*>(this)->setPolygonModeOverrideable(override);
	}
}
