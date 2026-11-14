// Layout probes for the inactive native RBX::Adorn / RBX::AdornG3D (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_adorn.py compares the immediates with the sizes and
// offsets read from the original (operator new size and inline constructor stores in 0045d850, ??_G 0045d820).
// nativeNewAdornG3D instantiates the header-inline constructor so that this object carries the AdornG3D vtable and
// ??_G built from the current headers (the recorder checks both against 00819d24 / 0045d820).
#include "AppDraw/AdornG3D2008.h"
#include <stddef.h>

struct NativeAdornLayout
{
	static int adornSize() { return sizeof(RBX::Adorn); }
	static int adornG3DSize() { return sizeof(RBX::AdornG3D); }
	static int adornG3DRenderDevice() { return offsetof(RBX::AdornG3D, renderDevice); }
	static int adornG3DTextureManager() { return offsetof(RBX::AdornG3D, textureManager); }
	static int textureManagerSize() { return sizeof(G3D::TextureManager); }
};

#define PROBE(name) int native##name() { return NativeAdornLayout::name(); }
PROBE(adornSize) PROBE(adornG3DSize) PROBE(adornG3DRenderDevice) PROBE(adornG3DTextureManager) PROBE(textureManagerSize)

RBX::Adorn* nativeNewAdornG3D(G3D::RenderDevice* renderDevice)
{
	return new RBX::AdornG3D(renderDevice);
}
