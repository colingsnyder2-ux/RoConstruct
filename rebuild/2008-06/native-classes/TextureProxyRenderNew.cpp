// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RBX::RenderNew::TextureProxy / MegaTextureProxy / BadConversion, optimized RenderLib unit (2008-06, inactive native
// recovery). Image block 007ad9d0..007aee5f; recovered here: getSize 007adb70, stringify(double) 007adbe0 with the
// BadConversion copy constructor 007adcf0, the root constructor 007ade10, shade 007aded0, ~TextureProxy 007ae3b0,
// MegaTextureProxy(TextureManager&, name) 007ae4b0 and its ??_G 007aea40. resolve 007aec70 /
// MegaTextureProxy::resolve 007ae4e0 and the shading helpers 007ad9d0 / 007ada80 / 007add10 are not built.
#include <sstream>
#include "RenderLib/TextureProxy2008.h"

namespace RBX
{
	namespace RenderNew
	{
		G3D::Vector2 TextureProxy::getSize()
		{
			G3D::Vector2 out;
			if (!ogreTexture.isNull())
			{
				out.x = ogreTexture->getWidth();
				out.y = ogreTexture->getHeight();
			}
			else
			{
				out.y = 0.0f;
				out.x = 0.0f;
			}
			return out;
		}

		std::string stringify(double x)
		{
			std::ostringstream o;
			if (!(o << x))
				throw BadConversion("stringify(double)");
			return o.str();
		}

		TextureProxy::TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root)
			: loaded(false),
			  textureManager(NULL),
			  root(root)
		{
			this->filename = "";
		}

		TextureProxyBaseRef TextureProxy::shade(const G3D::Color3& color, const TextureProxyBaseRef& base)
		{
			TextureProxy* baseTex = dynamic_cast<TextureProxy*>(base.getPointer());
			TextureProxy* newTex = new TextureProxy(baseTex);
			newTex->textureManager = textureManager;
			newTex->root = baseTex;
			newTex->shadeColor = color;
			newTex->shadeTexture = this;
			return newTex;
		}

		TextureProxy::~TextureProxy()
		{
		}

		MegaTextureProxy::MegaTextureProxy(G3D::TextureManager& textureManager, const std::string& filename)
			: TextureProxy(textureManager, filename, false),
			  scalar(0.0f)
		{
		}
	}
}
