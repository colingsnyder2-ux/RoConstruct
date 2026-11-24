// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// The original at 0x0069fd26 is a linker import thunk: jmp dword ptr [__imp_...getClipPlanes].
// INFERRED: no Ogre headers were provided, so the declarations below are guesses.
// To make the compiler emit "jmp dword ptr [imp]", the member forwards to a dllimport'ed
// member with the same signature (ecx passes through, so the call becomes a tail jump).
#include <vector>

namespace Ogre
{
	// INFERRED: minimal Plane, only needed to be a complete type for the vector.
	class Plane
	{
	public:
		float normal[3];
		float d;
	};

	// INFERRED: stand-in for the import-library entry of Renderable::getClipPlanes.
	class __declspec(dllimport) RenderableClipPlanesImport
	{
	public:
		const std::vector<Plane>& getClipPlanesImported() const;
	};

	class Renderable
	{
	public:
		virtual const std::vector<Plane>& getClipPlanes() const;
	};

	const std::vector<Plane>& Renderable::getClipPlanes() const
	{
		return reinterpret_cast<const RenderableClipPlanesImport*>(this)->getClipPlanesImported();
	}
}
