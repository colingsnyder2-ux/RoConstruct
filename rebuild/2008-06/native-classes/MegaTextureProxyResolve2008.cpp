// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// MegaTextureProxyResolve2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c5ca5cfb | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "RenderLib/TextureProxy2008.h"
#include <G3D/GImage.h>
#include "v8datamodel/BrickColor.h"
#include <OgreTextureManager.h>
#include <OgreImage.h>
#include <OgreLogManager.h>
#include <algorithm>
namespace RBX { namespace RenderNew {
G3D::ReferenceCountedPointer<G3D::Texture> MegaTextureProxy::resolve(G3D::RenderDevice* rd)
{
	if (!loaded) {
		MegaTextureProxy* self = this;
		size_t count = std::min(numStrips, BrickColor::colorPalette().size());

		G3D::GImage strip(filename, G3D::GImage::AUTODETECT);
		int atlasWidth = strip.width * numStrips;
		G3D::GImage atlas(atlasWidth, strip.height, 3);

		for (size_t i = 0; i < count; i++) {
			G3D::Color3uint8 color(BrickColor::colorPalette()[i].color3());

			G3D::Color3uint8 colorTable[256];
			for (size_t j = 0; j < 256; j++) {
				colorTable[j] = G3D::Color3uint8(j, j, j);
				Render::TextureProxy::shadePixel(color, colorTable[j]);
			}

			for (int x = 0; x < strip.width; x++) {
				for (int y = 0; y < strip.height; y++) {
					const G3D::Color3uint8& src = strip.pixel3(x, y);
					G3D::Color3uint8& dst = atlas.pixel3(x + i * strip.width, y);
					dst = colorTable[src.r];
				}
			}
		}

		const char* name = "TextureAtlas";
		ogreTexture = Ogre::TextureManager::getSingleton().getByName(name);

		if (ogreTexture.isNull()) {
			Ogre::Image image;
			image.loadDynamicImage(atlas.byte(), atlas.width, atlas.height, 1, Ogre::PF_BYTE_RGB, false, 1, 0);

			while (true) {
				try {
					ogreTexture = Ogre::TextureManager::getSingleton().create(name, "General");
					ogreTexture->loadImage(image);
					break;
				}
				catch (...) {
					if (image.getWidth() > 512 || image.getHeight() > 512) {
						Ogre::TextureManager::getSingleton().remove(ogreTexture->getHandle());
						image.resize(image.getWidth() / 2, image.getHeight() / 2);
						Ogre::LogManager::getSingleton().logMessage(std::string("Error loading texture. Reduce size to ") + stringify(atlas.width) + "x" + stringify(atlas.height) + " and try again\n");
					}
					else {
						Ogre::LogManager::getSingleton().logMessage(std::string("Give up on loading texture ") + name);
						break;
					}
				}
			}
		}

		self->root = NULL;
		self->loaded = true;
	}

	return texture;
}
} }
