// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069fd3e is only an import thunk (jmp dword ptr [0x804160]) for
// Ogre::Renderable::getPolygonModeOverrideable. The real body lives in the Ogre DLL.
// To get the same `jmp [__imp_...]` tail call, this forwards `this` unchanged to a
// dllimport member of a helper class. The helper name is a stand-in, not the real import.

namespace Ogre
{
	// INFERRED: stand-in for the imported implementation in the Ogre DLL.
	class RenderableImport
	{
	public:
		__declspec(dllimport) bool getPolygonModeOverrideableImpl(void) const;
	};

	class Renderable
	{
	public:
		virtual bool getPolygonModeOverrideable(void) const;
	};

	bool Renderable::getPolygonModeOverrideable(void) const
	{
		return reinterpret_cast<const RenderableImport*>(this)->getPolygonModeOverrideableImpl();
	}
}
