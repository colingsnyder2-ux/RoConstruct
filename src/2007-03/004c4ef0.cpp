// from server: 90% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/TextureProxy.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/TextureProxy.h"

#include "decomp.h"
#include "util/standardout.h"

#include <G3D/GImage.h>
#include <G3D/format.h>
#include <algorithm>

namespace RBX {
namespace Render {

// STUB: WEBSERVICE 0x10168ea0
void TextureProxy::shadePixel(const G3D::Color3uint8& base, G3D::Color3uint8& lighting)
{
	for (int i = 0; i < 3; i++) {
		int light = lighting[i];
		float color = base[i];

		if (light > 130) {
			float shade = (light - 128.0) / 128.0;
			float a = std::min(shade, 1.0f);
			color = (1.0 - a) * color + 255.0 * a;
		}
		else if (light < 126) {
			float a = light / 128.0;
			a = 0.5 + a * 0.5;
			color = color * a;
		}

		lighting[i] = std::min(std::max(0, G3D::iRound(255.0 * pow(color / 255.0, 1.0))), 255);
	}
}

// FUNCTION: WEBSERVICE 0x10169100
TextureProxyRef TextureProxy::shade(const G3D::Color3& baseColor, const TextureProxyRef& baseTex)
{
	TextureProxy* answer = new TextureProxy(baseTex);

	answer->textureManager = textureManager;
	answer->root = baseTex;
	answer->shadeColor = baseColor;
	answer->shadeTexture = this;

	return answer;
}

// FUNCTION: WEBSERVICE 0x101691d0
G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::getIfResolved() const
{
	return texture;
}

// STUB: WEBSERVICE 0x10169200
G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::resolve(G3D::RenderDevice* rd)
{
	if (!loaded) {
		if (!shadeTexture.isNull()) {
			char encodedFileName[1024];

			sprintf(
				encodedFileName,
				"%g%g%g%s",
				shadeColor.r,
				shadeColor.g,
				shadeColor.b,
				shadeTexture->filename.c_str()
			);

			texture = textureManager->findTexture(encodedFileName);

			if (texture.isNull()) {
				static std::string lastFilename = shadeTexture->filename;
				static G3D::GImage cachedBumpImage(lastFilename, G3D::GImage::AUTODETECT);

				if (lastFilename != shadeTexture->filename) {
					lastFilename = shadeTexture->filename;
					cachedBumpImage.load(lastFilename, G3D::GImage::AUTODETECT);
				}

				G3D::GImage bumpImage(cachedBumpImage);
				G3D::Color3uint8 colorTable[256];

				for (int i = 0; i < 256; i++) {
					colorTable[i].r = colorTable[i].g = colorTable[i].b = i;
					shadePixel(shadeColor, colorTable[i]);
				}

				int numPixels = bumpImage.width * bumpImage.height;

				for (int i = 0; i < numPixels; i++) {
					bumpImage.pixel3()[i] = colorTable[bumpImage.pixel3()[i].r];
				}

				texture = G3D::Texture::fromGImage(
					G3D::format(
						"Generated bump texture, color = (%3.1f, %3.1f, %3.1f)",
						shadeColor.r,
						shadeColor.g,
						shadeColor.b
					),
					bumpImage,
					G3D::TextureFormat::RGB8
				);

				textureManager->cacheTexture(texture, encodedFileName);
			}
		}
		else if (root.isNull()) {
			try {
				if (filename == "") {
					texture = G3D::Texture::createEmpty(8, 8);
				}
				else {
					texture = textureManager->loadTexture(
						filename,
						G3D::TextureFormat::AUTO,
						tiled ? G3D::Texture::TILE : G3D::Texture::TRANSPARENT_BORDER
					);
				}
			}
			catch (std::exception& e) {
				StandardOut::singleton()
					->print(MESSAGE_ERROR, "Failed to load texture '%s', %s", filename.c_str(), e.what());
				texture = NULL;
			}
			catch (...) {
				StandardOut::singleton()
					->print(MESSAGE_ERROR, "Failed to load texture '%s', unknown exception", filename.c_str());
				texture = NULL;
			}
		}
		else {
			G3D::TextureRef t = root->resolve(rd);

			if (!t.isNull() && !t->opaque()) {
				texture = t->alphaOnlyVersion();
			}
		}

		root = NULL;
		shadeTexture = NULL;
		loaded = true;
	}

	return texture;
}

// FUNCTION: WEBSERVICE 0x10169920
TextureProxyRef TextureProxy::alphaOnlyVersion()
{
	return new TextureProxy(this);
}

// FUNCTION: WEBSERVICE 0x101699c0
G3D::Vector2 TextureProxy::getSize()
{
	G3D::TextureRef t = getIfResolved();
	G3D::Vector2 size;

	if (!t.isNull()) {
		size.x = (float) t->texelWidth();
		size.y = (float) t->texelHeight();
	}
	else {
		size.y = 0;
		size.x = 0;
	}

	return size;
}

} // namespace Render
} // namespace RBX
