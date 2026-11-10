// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::AdornG3D unit (inactive): 00676480..006764b3 (getViewport 00676480, getWidth 006764a0,
// getHeight 006764b0). rbxgs-appdraw was compiled with /fp:fast, so the original pins it with
// #pragma float_control(precise, off) - copied here.
//
// Class and layout come from the vendor header tools/rbxgs/Client/Rendering/AppDraw/include/AppDraw/AdornG3D.h:
// private G3D::RenderDevice* renderDevice; private G3D::TextureManager textureManager; after the RbxGraphics::Adorn
// vptr, so renderDevice is at +4 - which is exactly the [ecx+4] the binary uses. No field or offset is invented.
// Bodies are the vendor overlay originals (rebuild/2008-06/out/RbxgsApp/overlay/Rendering/AppDraw/AdornG3D.cpp).
//
// All three are tail-call forwards to G3D::RenderDevice: getWidth -> 0x478450, getHeight -> 0x478cd0,
// getViewport -> 0x476d60 (the sret is forwarded through, hence the push esi / mov eax,esi / pop esi shape).
// The remaining AdornG3D methods are recorded in work/2008-06/shared-layouts/adorn-g3d-20261107.json.
#pragma float_control(precise, off)
#include "AppDraw/AdornG3D.h"

namespace RBX
{
	int AdornG3D::getWidth() const
	{
		return renderDevice->getWidth();
	}

	int AdornG3D::getHeight() const
	{
		return renderDevice->getHeight();
	}

	G3D::Rect2D AdornG3D::getViewport() const
	{
		return renderDevice->getViewport();
	}
}
