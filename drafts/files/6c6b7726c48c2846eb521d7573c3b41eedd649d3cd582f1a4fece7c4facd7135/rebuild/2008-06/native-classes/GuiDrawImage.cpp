// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile
// Inactive native GuiDrawImage: donor method bodies checked against original 00642690..00642f04.
#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"

namespace RBX
{
	static G3D::ReferenceCountedPointer<TextureProxyBase> silentGetTextureProxyBase(Adorn* adorn, const ContentId& id)
	{
		if (ContentProvider::singleton().hasContent(id))
			return Textures::getTextureProxy(adorn, id);
		else
			return NULL;
	}

	void GuiDrawImage::render2d(Adorn* adorn, bool enabled, Rect& rect, Widget::WidgetState state)
	{
		if (!enabled)
		{
			draw(adorn, disable, rect, G3D::Color4::clear(), G3D::Color4(1.0f, 1.0f, 1.0f, 0.5f));
		}
		else if (state == Widget::NOTHING)
		{
			draw(adorn, normal, rect, G3D::Color4::clear(), G3D::Color4::clear());
		}
		else if (state != Widget::HOVER && state != Widget::DOWN_AWAY)
		{
			draw(adorn, down, rect, G3D::Color3::blue(), G3D::Color4::clear());
		}
		else
		{
			draw(adorn, hover, rect, G3D::Color3::yellow(), G3D::Color4::clear());
		}
	}

	void GuiDrawImage::draw(Adorn* adorn, G3D::ReferenceCountedPointer<TextureProxyBase> texture, const Rect& rect, const G3D::Color4& behind, const G3D::Color4& inFront)
	{
		G3D::Rect2D rect2D = rect.toRect2D();

		if (texture.notNull())
		{
			adorn->setTexture(0, texture);
			adorn->rect2d(rect2D, G3D::Color4(1.0f, 1.0f, 1.0f, 1.0f));
			adorn->setTexture(0, NULL);
		}
		else if (normal.notNull())
		{
			adorn->rect2d(rect2D, behind);
			draw(adorn, normal, rect, G3D::Color4::clear(), G3D::Color4::clear());
			adorn->rect2d(rect2D, inFront);
		}
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

namespace RBX {
// 00642690: lazily query the normal texture, then retain the image size.
G3D::Vector2 GuiDrawImage::getImageSize() const
{
    if (size.x == 0.0f && size.y == 0.0f && normal.notNull()) {
        G3D::Vector2 imageSize = normal->getSize();
        size = imageSize;
    }
    return size;
}
// 00642b90: asset names are resolved under the original Textures directory.
void GuiDrawImage::setImageFromName(Adorn* adorn, const std::string& name)
{
    ContentId id = ContentId::fromAssets("Textures\\" + name + ".png");
    setImage(adorn, id);
}
}
