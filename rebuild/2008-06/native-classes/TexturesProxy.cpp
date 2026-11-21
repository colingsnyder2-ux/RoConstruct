// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partchunk-profile
// 2008-06 native RBX::Textures::getTextureProxy (inactive), the AppDraw/Textures.cpp row 00677d30 between
// DrawAdorn::handles2d 00677b20 and DrawPrimitives::rawSphere 00677de0. Flags and headers copied from
// GuiDrawImageSize.cpp (its caller silentGetTextureProxyBase 006426f0). Identity: registry
// ?getTextureProxy@Textures@RBX@@SA?AV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@PAVAdorn@2@ABVContentId@2@@Z.
#include "AppDraw/Textures.h"

namespace RBX { extern ContentProvider* guiContentProvider; }   // 00974d74 (defined in GuiContentProviderState.cpp)

namespace RBX
{
	// 00677d30: the ContentId copied by value (std::string copy + Name* +0x1c) into ContentProvider::getFile 00561e30 on
	// guiContentProvider [00974d74] (the 2008 form of the donor ContentProvider::singleton()), then
	// adorn->createTextureProxy(fileName) (Adorn slot 1). The catch block only builds a null pointer
	// (ReferenceCountedPointer(NULL) 004e6030) and destroys no exception object, so the handler catches by reference.
	TextureProxyBaseRef Textures::getTextureProxy(Adorn* adorn, const ContentId& id)
	{
		try
		{
			std::string fileName = guiContentProvider->getFile(id);
			return adorn->createTextureProxy(fileName);
		}
		catch (std::exception&)
		{
			return NULL;
		}
	}
}
