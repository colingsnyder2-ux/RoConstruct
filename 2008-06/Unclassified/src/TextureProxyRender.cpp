// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RBX::Render::TextureProxy / MegaTextureProxy, optimized RenderLib unit (2008-06, inactive native recovery).
// Image block 007b8180..007b93cf; recovered here: the root constructor 007b8450, shade 007b8500, getIfResolved 007b85e0,
// alphaOnlyVersion 007b8eb0, getSize 007b8f40, MegaTextureProxy(TextureManager&, name) 007b8fb0 (with the inline shade
// slot 007b8fe0 and ??_G 007b9350). resolve 007b8610 / MegaTextureProxy::resolve 007b9000 are not built.
// >>> native-status (generated) -- do not edit >>>
// TextureProxyRender | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 58c15739 | roc native-status --write
#include "RenderLib/TextureProxy2008.h"

namespace RBX
{
	namespace Render
	{
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

		G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::getIfResolved() const
		{
			return texture;
		}

		G3D::ReferenceCountedPointer<TextureProxy> TextureProxy::alphaOnlyVersion()
		{
			return new TextureProxy(this);
		}

		G3D::Vector2 TextureProxy::getSize()
		{
			G3D::ReferenceCountedPointer<G3D::Texture> t = getIfResolved();
			G3D::Vector2 out;
			if (t.notNull())
			{
				out.x = t->texelWidth();
				out.y = t->texelHeight();
			}
			else
			{
				out.y = 0.0f;
				out.x = 0.0f;
			}
			return out;
		}

		MegaTextureProxy::MegaTextureProxy(G3D::TextureManager& textureManager, const std::string& filename)
			: TextureProxy(textureManager, filename, false),
			  scalar(0.0f)
		{
		}
	}
}
