// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/RenderSurface.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/RenderSurface.h"

#include <algorithm>

namespace RBX {
namespace Render {

// FUNCTION: WEBSERVICE 0x101f7080
// FUNCTION: ROBLOX 0x004a2600
bool materialDepthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
{
	return A->material < B->material || (A->material == B->material && A->z > B->z);
}

// FUNCTION: WEBSERVICE 0x101f70c0
// FUNCTION: ROBLOX 0x004a2640
bool materialPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
{
	return A->material < B->material;
}

// FUNCTION: WEBSERVICE 0x101f70e0
// FUNCTION: ROBLOX 0x004a2660
bool depthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
{
	return A->z < B->z;
}

// FUNCTION: WEBSERVICE 0x101f76c0
// FUNCTION: ROBLOX 0x004a2c40
void sortByMaterialAndDepth(G3D::Array<RenderSurface*>& array)
{
	std::sort(array.begin(), array.end(), materialDepthPtrSortProc);
}

// FUNCTION: WEBSERVICE 0x101f76f0
// FUNCTION: ROBLOX 0x004a2c70
void sortByMaterial(G3D::Array<RenderSurface*>& array)
{
	std::sort(array.begin(), array.end(), materialPtrSortProc);
}

// FUNCTION: WEBSERVICE 0x101f7720
// FUNCTION: ROBLOX 0x004a2ca0
void sortByDepth(G3D::Array<RenderSurface*>& array)
{
	std::sort(array.begin(), array.end(), depthPtrSortProc);
}

} // namespace Render
} // namespace RBX
