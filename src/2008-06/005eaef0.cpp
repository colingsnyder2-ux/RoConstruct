// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_skyboxstatichelper5266aad5e85090ae.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/GImage.h"
#include <string>
#include <stdexcept>
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

std::string validate(const std::string&file,G3D::GImage&master){return testImage(file,master);}
