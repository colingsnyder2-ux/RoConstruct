// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069fd32 is a linker import thunk (jmp [IAT]) for the rgmain.dll export.
// A tail call through a dllimport member with the same thiscall signature
// compiles to the same 6-byte "jmp dword ptr [__imp_...]".
namespace Ogre
{
	class GpuProgramParameters
	{
	public:
		class AutoConstantEntry;
	};

	// INFERRED: stand-in for the imported rgmain implementation (same signature).
	struct RenderableImport
	{
		__declspec(dllimport) void _updateCustomGpuParameter(const GpuProgramParameters::AutoConstantEntry& constantEntry, GpuProgramParameters* params) const;
	};

	class Renderable
	{
	public:
		virtual void _updateCustomGpuParameter(const GpuProgramParameters::AutoConstantEntry& constantEntry, GpuProgramParameters* params) const;
	};

	void Renderable::_updateCustomGpuParameter(const GpuProgramParameters::AutoConstantEntry& constantEntry, GpuProgramParameters* params) const
	{
		reinterpret_cast<const RenderableImport*>(this)->_updateCustomGpuParameter(constantEntry, params);
	}
}
