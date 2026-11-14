// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partchunk-profile
// 2008-06 native RBX::GuiDrawImage::getImageSize / setImage (inactive): the rows after the Widget unit (00642690,
// 006426f0 silentGetTextureProxyBase, 00642750). GuiDrawImage layout (donor gui/GuiDraw.h, read-only here):
// currentTexture +0x00 (TextureId: std::string + Name* +0x1c), normal +0x20, disable +0x24, hover +0x28, down +0x2c,
// size +0x30. setImageFromName / draw / render2d stay in GuiDrawImage.cpp.
#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"

namespace RBX { extern ContentProvider* guiContentProvider; }   // 00974d74 (identity registry; defined in GuiContentProviderState.cpp; read by 0064271d: hasContent 005624b0)

namespace RBX
{
	// 006426f0: ContentProvider::hasContent(ContentId) by value, then Textures::getTextureProxy 00677d30.
	static G3D::ReferenceCountedPointer<TextureProxyBase> silentGetTextureProxyBase(Adorn* adorn, const ContentId& id)
	{
		if (guiContentProvider->hasContent(id))
			return Textures::getTextureProxy(adorn, id);
		else
			return NULL;
	}

	// 00642690: caches normal->getSize() (TextureProxyBase slot 5) into size while size is zero.
	G3D::Vector2 GuiDrawImage::getImageSize() const
	{
		if (size.isZero() && normal.notNull())
		{
			G3D::Vector2 imageSize = normal->getSize();
			const_cast<GuiDrawImage*>(this)->size = imageSize;
		}

		return size;
	}

	// 00642750: string != currentTexture 0055bd60; resets normal, hover, down, disable (in that order) and size; the
	// "_ovr.png" 0084a840 / "_dn.png" 0084a838 / "_ds.png" 0084a830 variants of the id less its 4-character extension.
	bool GuiDrawImage::setImage(Adorn* adorn, const TextureId& textureId)
	{
		if (textureId != currentTexture)
		{
			currentTexture = textureId;

			normal = NULL;
			hover = NULL;
			down = NULL;
			disable = NULL;

			size = G3D::Vector2(0.0f, 0.0f);

			normal = silentGetTextureProxyBase(adorn, currentTexture);

			if (normal.notNull())
			{
				std::string id = textureId.toString();
				std::string base = id.substr(0, id.size() - 4);

				hover = silentGetTextureProxyBase(adorn, ContentId(base + "_ovr.png"));
				down = silentGetTextureProxyBase(adorn, ContentId(base + "_dn.png"));
				disable = silentGetTextureProxyBase(adorn, ContentId(base + "_ds.png"));
			}
		}

		return normal.notNull();
	}
}
