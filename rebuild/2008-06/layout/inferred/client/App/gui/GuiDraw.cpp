#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"

namespace RBX { extern ContentProvider* guiContentProvider; }   // 00974d74 (identity registry; defined in GuiContentProviderState.cpp; read by 0064271d: hasContent 005624b0)

namespace RBX
{
	static G3D::ReferenceCountedPointer<TextureProxyBase> silentGetTextureProxyBase(Adorn* adorn, const ContentId& id)
	{
		if (guiContentProvider->hasContent(id))
			return Textures::getTextureProxy(adorn, id);
		else
			return NULL;
	}

	G3D::Vector2 GuiDrawImage::getImageSize() const
	{
		if (size.isZero() && normal.notNull())
		{
			G3D::Vector2 imageSize = normal->getSize();
			const_cast<GuiDrawImage*>(this)->size = imageSize;
		}

		return size;
	}

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
