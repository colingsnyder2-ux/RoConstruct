// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RBX::Render::TextureProxy / MegaTextureProxy, optimized RenderLib unit (2008-06, inactive native recovery).
// Image block 007b8180..007b93cf; recovered here: the root constructor 007b8450, shade 007b8500, getIfResolved 007b85e0,
// alphaOnlyVersion 007b8eb0, getSize 007b8f40, MegaTextureProxy(TextureManager&, name) 007b8fb0 (with the inline shade
<<<<<<< HEAD
// slot 007b8fe0 and ??_G 007b9350) and MegaTextureProxy::resolve 007b9000. resolve 007b8610 is not built.
=======
// slot 007b8fe0 and ??_G 007b9350), MegaTextureProxy::resolve 007b9000, and resolve 007b8610 with its unit-local
// helpers 007b80f0 / 007b8180 / 007b82f0 (only resolve calls them; 007b80f0 takes its first argument in edi, so it
// is a static of this unit).
>>>>>>> mew/claude/optimistic-shannon-0xccuy
#include "RenderLib/TextureProxy2008.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/GImage.h>
#include <GLG3D/TextureFormat.h>
<<<<<<< HEAD
#include <algorithm>
=======
#include <G3D/format.h>
#include <leaves2008/StandardOut2008.h>
#include <algorithm>
#include <cstdio>
#include <sys/stat.h>
#include <io.h>

// INFERRED: names of the three unit-local helpers below are descriptive (no symbols); bodies from 007b80f0 /
// 007b8180 / 007b82f0 and their only caller TextureProxy::resolve 007b8610.

// 007b80f0: _stat64i32 both files; true when cached is at least as new as source, else _unlink(cached).
static bool isCacheValid(const std::string& cached, const std::string& source)
{
	struct _stat cachedStat;
	if (_stat(cached.c_str(), &cachedStat) != 0)
		return false;

	struct _stat sourceStat;
	_stat(source.c_str(), &sourceStat);

	bool upToDate = cachedStat.st_mtime >= sourceStat.st_mtime;
	if (!upToDate)
		_unlink(cached.c_str());

	return upToDate;
}

// 007b8180: GImage(width / 2, height / 2, channels) 0050eea0, 2x2 box filter with +2 rounding (edge texels x4),
// then save(filename, PNG) 0050f430.
// INFERRED: external linkage (resolve calls it cdecl with both arguments on the stack, unlike the static 007b80f0).
void saveHalfSize(const G3D::GImage& source, const std::string& filename)
{
	G3D::GImage half(source.width / 2, source.height / 2, source.channels);
	int stride = source.width * source.channels;

	for (int y = 0; y < half.height; ++y)
	{
		for (int x = 0; x < half.width; ++x)
		{
			for (int c = 0; c < half.channels; ++c)
			{
				G3D::uint8* dst = half.byte() + (y * half.width + x) * half.channels + c;
				const G3D::uint8* src = source.byte() + (y * source.width + x) * source.channels * 2 + c;
				int sum;
				if (x * 2 + 1 < source.width && y * 2 + 1 < source.height)
					sum = src[source.channels + stride] + src[stride] + src[0] + src[source.channels];
				else
					sum = src[0] * 4;
				*dst = (sum + 2) >> 2;
			}
		}
	}

	half.save(filename, G3D::GImage::PNG);
}

// 007b82f0: GImage::resolveFormat 0050edb0 (UNKNOWN throws "unknown texture format" 00875c20), GImage(name, format)
// 00510670; halves into target and recurses while larger than maxSize, else saves a copy under target.
static void saveScaled(const std::string& source, std::string target, int maxSize)
{
	G3D::GImage::Format format = G3D::GImage::resolveFormat(source);
	if (format == G3D::GImage::UNKNOWN)
		throw std::exception("unknown texture format");

	G3D::GImage image(source, format);

	if (image.width > maxSize || image.height > maxSize)
	{
		saveHalfSize(image, target);
		saveScaled(target, target, maxSize);
	}
	else if (target != source)
	{
		image.save(target, G3D::GImage::PNG);
	}
}
>>>>>>> mew/claude/optimistic-shannon-0xccuy

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

		// 007b8610: shaded proxies look up "%g%g%g%s" 00875cdc in the TextureManager (findTexture 0047d8d0) and else
		// shade a cached GImage of the source (function-local statics 0097f680 / 0097f66c, guard 0097f69c) through
		// shadePixel 007add10 into fromGImage 007b8400 + cacheTexture 0047e580; plain proxies load filename (empty:
		// createEmpty 8x8 "Texture"; under "\\Cache\\" / "\\cache\\" with scale +0x2c < 1: a "scaled.png" copy) through
		// loadTexture 0047e6e0, logging failures with StandardOut::print 005693a0; alpha proxies take root's
		// alphaOnlyVersion 00474a50 when it is not opaque.
		G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::resolve(G3D::RenderDevice* rd)
		{
			if (!loaded)
			{
				if (shadeTexture.notNull())
				{
					char name[1024];
					sprintf(name, "%g%g%g%s", shadeColor.r, shadeColor.g, shadeColor.b, shadeTexture->filename.c_str());
					texture = textureManager->findTexture(name);

					if (texture.isNull())
					{
						static std::string sourceFilename = shadeTexture->filename;
						static G3D::GImage sourceImage(sourceFilename, G3D::GImage::AUTODETECT);

						if (sourceFilename != shadeTexture->filename)
						{
							sourceFilename = shadeTexture->filename;
							sourceImage.load(sourceFilename, G3D::GImage::AUTODETECT);
						}

						G3D::GImage image(sourceImage);

						G3D::Color3uint8 colorTable[256];
						for (int j = 0; j < 256; ++j)
						{
							colorTable[j].r = colorTable[j].g = colorTable[j].b = j;
							shadePixel(shadeColor, colorTable[j]);
						}

						int count = image.width * image.height;
						for (int i = 0; i < count; ++i)
							image.pixel3()[i] = colorTable[image.pixel3()[i].r];

						texture = G3D::Texture::fromGImage(
							G3D::format("Generated bump texture, color = (%3.1f, %3.1f, %3.1f)", shadeColor.r, shadeColor.g, shadeColor.b),
							image, G3D::TextureFormat::RGB8, G3D::Texture::DIM_2D, G3D::Texture::Settings::defaults());

						textureManager->cacheTexture(texture, name);
					}
				}
				else if (root.isNull())
				{
					try
					{
						if (filename == "")
						{
							texture = G3D::Texture::createEmpty(8, 8);
						}
						else if ((filename.find("\\Cache\\") != std::string::npos || filename.find("\\cache\\") != std::string::npos)
						         && floatProperty < 1.0f)
						{
							std::string scaledName = filename + "scaled.png";
							int size = 100000;

							if (!isCacheValid(scaledName, filename))
							{
								G3D::GImage::Format format = G3D::GImage::resolveFormat(filename);
								if (format == G3D::GImage::UNKNOWN)
									throw std::exception("unknown texture format");

								G3D::GImage image(filename, format);

								if (image.width > 128 && image.height > 128)
								{
									size = std::min((int)(image.width * floatProperty), (int)(image.height * floatProperty));
									saveHalfSize(image, scaledName);
								}
								else
								{
									scaledName = filename;
								}
							}

							saveScaled(scaledName, scaledName, std::min(512, size));
							texture = textureManager->loadTexture(scaledName, G3D::TextureFormat::AUTO,
							                                      tiled ? G3D::Texture::TILE : G3D::Texture::TRANSPARENT_BORDER);
						}
						else
						{
							saveScaled(filename, filename, 512);
							texture = textureManager->loadTexture(filename, G3D::TextureFormat::AUTO,
							                                      tiled ? G3D::Texture::TILE : G3D::Texture::TRANSPARENT_BORDER);
						}
					}
					catch (std::exception& e)
					{
						StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load texture '%s', %s", filename.c_str(), e.what());
						texture = NULL;
					}
					catch (...)
					{
						StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load texture '%s', unknown exception", filename.c_str());
						texture = NULL;
					}
				}
				else
				{
					G3D::ReferenceCountedPointer<G3D::Texture> rootTexture = root->resolve(rd);
					if (rootTexture.notNull() && !rootTexture->opaque())
						texture = rootTexture->alphaOnlyVersion();
				}

				root = NULL;
				shadeTexture = NULL;
				loaded = true;
			}

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
