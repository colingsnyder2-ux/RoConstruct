// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partchunk-profile
// 006426f0 RBX::silentGetTextureProxyBase: hit on File->New (GuiDrawImage::setImage 00642750+0x123) but linked as a
// `return 0` stub (the converted 006426f0.obj is a library unit without this function). Body as in
// native-classes/GuiDrawImageSize.cpp (file-local there); the original is an EXTERNAL free function.
#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"

namespace RBX { extern ContentProvider* guiContentProvider; }   // 00974d74

namespace RBX
{
	G3D::ReferenceCountedPointer<TextureProxyBase> silentGetTextureProxyBase(Adorn* adorn, const ContentId& id)
	{
		if (guiContentProvider->hasContent(id))
			return Textures::getTextureProxy(adorn, id);
		else
			return NULL;
	}
}
