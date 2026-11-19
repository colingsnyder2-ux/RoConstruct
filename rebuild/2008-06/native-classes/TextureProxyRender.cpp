// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RBX::Render::TextureProxy / MegaTextureProxy, optimized RenderLib unit (2008-06, inactive native recovery).
// Image block 007b8180..007b93cf; recovered here: the root constructor 007b8450, shade 007b8500, getIfResolved 007b85e0,
// alphaOnlyVersion 007b8eb0, getSize 007b8f40, MegaTextureProxy(TextureManager&, name) 007b8fb0 (with the inline shade
// slot 007b8fe0 and ??_G 007b9350) and MegaTextureProxy::resolve 007b9000. resolve 007b8610 is not built.
#include "RenderLib/TextureProxy2008.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/GImage.h>
#include <GLG3D/TextureFormat.h>
#include <algorithm>

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

		// 007b9000: one strip per palette colour (at most numStrips = 32, the shared const 0080b350), each shaded
		// through a 256-entry grey ramp (shadePixel 007add10), then Texture::fromGImage 007b8400 ("MegaTexture" 00875d10,
		// TextureFormat::RGB8 0096fab0, DIM_2D, Settings 00472a80 with wrapMode = CLAMP).
		G3D::ReferenceCountedPointer<G3D::Texture> MegaTextureProxy::resolve(G3D::RenderDevice* rd)
		{
			if (!loaded)
			{
				MegaTextureProxy* self = this;
				size_t count = std::min(numStrips, BrickColor::colorPalette().size());

				G3D::GImage strip(filename, G3D::GImage::AUTODETECT);
				int atlasWidth = strip.width * numStrips;
				G3D::GImage atlas(atlasWidth, strip.height, 3);

				for (size_t i = 0; i < count; i++)
				{
					G3D::Color3uint8 color(BrickColor::colorPalette()[i].color3());

					G3D::Color3uint8 colorTable[256];
					for (size_t j = 0; j < 256; j++)
					{
						colorTable[j] = G3D::Color3uint8(j, j, j);
						shadePixel(color, colorTable[j]);
					}

					for (int x = 0; x < strip.width; x++)
					{
						for (int y = 0; y < strip.height; y++)
						{
							const G3D::Color3uint8& src = strip.pixel3(x, y);
							G3D::Color3uint8& dst = atlas.pixel3(x + i * strip.width, y);
							dst = colorTable[src.r];
						}
					}
				}

				G3D::Texture::Settings settings;
				settings.wrapMode = G3D::Texture::CLAMP;
				self->texture = G3D::Texture::fromGImage("MegaTexture", atlas, G3D::TextureFormat::RGB8, G3D::Texture::DIM_2D, settings);
				self->root = NULL;
				self->loaded = true;
			}

			return texture;
		}
	}
}
