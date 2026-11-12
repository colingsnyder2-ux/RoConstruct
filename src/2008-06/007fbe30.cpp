// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Sky.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Sky.h"

#include "util/ContentProvider.h"
#include "util/StandardOut.h"

#include <G3D/GImage.h>
#include <GLG3D/Sky.h>
#include <stdexcept>

namespace RBX {

char sSky[] = "Sky";

// FUNCTION: WEBSERVICE 0x10094490
// FUNCTION: ROBLOX 0x005dce00
static std::string testImage(const std::string& filename, G3D::GImage& reference)
{
	G3D::GImage image;
	image.load(filename);

	if (image.width != reference.width) {
		throw std::runtime_error("skybox images have different widths");
	}
	if (image.height != reference.height) {
		throw std::runtime_error("skybox images have different heights");
	}
	if (image.channels != reference.channels) {
		throw std::runtime_error("skybox images have different numbers of channels");
	}

	return filename;
}

using namespace Reflection;

BoundProp<TextureId, 1> Sky::prop_SkyUp("SkyboxUp", "Appearance", &Sky::skyUp);

BoundProp<TextureId, 1> Sky::prop_SkyLf("SkyboxLf", "Appearance", &Sky::skyLf);

BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &Sky::skyRt);

BoundProp<TextureId, 1> Sky::prop_SkyBk("SkyboxBk", "Appearance", &Sky::skyBk);

BoundProp<TextureId, 1> Sky::prop_SkyFt("SkyboxFt", "Appearance", &Sky::skyFt);

BoundProp<TextureId, 1> Sky::prop_SkyDn("SkyboxDn", "Appearance", &Sky::skyDn);

BoundProp<bool, 1> Sky::prop_CelestialBodiesShown("CelestialBodiesShown", "Appearance", &Sky::drawCelestialBodies);

BoundProp<int, 1> Sky::prop_StarCount("StarCount", "Appearance", &Sky::numStars);

// FUNCTION: WEBSERVICE 0x10094700
// FUNCTION: ROBLOX 0x005dd020
G3D::SkyRef Sky::getG3DSky(Sky* sky)
{
	if (sky) {
		try {
			std::string filenames[6];

			{
				filenames[0] = ContentProvider::singleton().getFile(sky->skyFt);
				G3D::GImage image;
				image.load(filenames[0]);
				filenames[1] = testImage(ContentProvider::singleton().getFile(sky->skyBk), image);
				filenames[2] = testImage(ContentProvider::singleton().getFile(sky->skyUp), image);
				filenames[3] = testImage(ContentProvider::singleton().getFile(sky->skyDn), image);
				filenames[4] = testImage(ContentProvider::singleton().getFile(sky->skyRt), image);
				filenames[5] = testImage(ContentProvider::singleton().getFile(sky->skyLf), image);
			}

			std::string directory = ContentProvider::singleton().assetFolder() + "Sky\\";
			G3D::SkyRef g3dSky = G3D::Sky::fromFile(NULL, directory, filenames, sky->drawCelestialBodies, 1.0);

			if (g3dSky.notNull()) {
				g3dSky->setNumStars(sky->numStars);
			}

			return g3dSky;
		}
		catch (std::exception& e) {
			StandardOut::singleton()->print(MESSAGE_WARNING, e);
		}
		catch (G3D::GImage::Error& e) {
			StandardOut::singleton()->print(MESSAGE_WARNING, e.reason.c_str());
		}
	}

	return G3D::Sky::fromFile(NULL, ContentProvider::singleton().assetFolder() + "Sky\\", "null_plainsky512_*.jpg");
}

// FUNCTION: WEBSERVICE 0x10095110
// FUNCTION: ROBLOX 0x005dd970
Sky::Sky() : drawCelestialBodies(true), numStars(3000)
{
	setName("Sky");

	skyUp = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
	skyLf = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
	skyRt = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
	skyBk = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
	skyFt = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
	skyDn = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
}

} // namespace RBX
