#include "v8datamodel/Sky.h"
#include "util/ContentProvider.h"
#include "util/standardout.h"
#include <G3D/GImage.h>

static std::string testImage(const std::string& file, G3D::GImage& master)
{
	G3D::GImage image;
	image.load(file);

	if (image.width != master.width)
		throw std::runtime_error("skybox images have different widths");

	if (image.height != master.height)
		throw std::runtime_error("skybox images have different heights");

	if (image.channels != master.channels)
		throw std::runtime_error("skybox images have different numbers of channels");

	return file;
}

namespace RBX
{
	char* sSky = "Sky";

	Reflection::BoundProp<int, 1> Sky::prop_StarCount("StarCount", "Appearance", &Sky::numStars, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyUp("SkyboxUp", "Appearance", &Sky::skyUp, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyLf("SkyboxLf", "Appearance", &Sky::skyLf, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &Sky::skyRt, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyBk("SkyboxBk", "Appearance", &Sky::skyBk, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyFt("SkyboxFt", "Appearance", &Sky::skyFt, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyDn("SkyboxDn", "Appearance", &Sky::skyDn, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<bool, 1> Sky::prop_CelestialBodiesShown("CelestialBodiesShown", "Appearance", &Sky::drawCelestialBodies, Reflection::PropertyDescriptor::STANDARD);

	Sky::Sky()
		: drawCelestialBodies(true),
		  numStars(3000)
	{
		setName("Sky");

		skyUp = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
		skyLf = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
		skyRt = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
		skyBk = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
		skyFt = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
		skyDn = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
	}

	// Dec 2007 client (OpenRBX v8datamodel/Sky.cpp; ROBLOX 0x005dd020)
	G3D::ReferenceCountedPointer<G3D::Sky> Sky::getG3DSky(Sky* sky)
	{
		if (sky)
		{
			try
			{
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
				G3D::ReferenceCountedPointer<G3D::Sky> g3dSky = G3D::Sky::fromFile(NULL, directory, filenames, sky->drawCelestialBodies, 1.0);
				// setNumStars(sky->numStars): not in this G3D build (6.x); star count stays at G3D's default
				return g3dSky;
			}
			catch (std::exception& e)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, e);
			}
			catch (G3D::GImage::Error& e)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, e.reason.c_str());
			}
		}
		return G3D::Sky::fromFile(NULL, ContentProvider::singleton().assetFolder() + "Sky\\", "null_plainsky512_*.jpg");
	}
}
