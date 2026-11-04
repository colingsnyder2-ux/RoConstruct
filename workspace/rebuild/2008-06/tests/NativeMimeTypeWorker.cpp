#include <G3D/GImage.h>
#include "util/Name.h"
namespace RBX { const Name& getMimeType(const char* filename) { switch (G3D::GImage::resolveFormat(filename)) { case G3D::GImage::JPEG: return Name::declare("image/jpeg",-1); case G3D::GImage::BMP: return Name::declare("image/bmp",-1); case G3D::GImage::ICO: return Name::declare("image/vnd.microsoft.icon",-1); case G3D::GImage::PNG: return Name::declare("image/png",-1); default: return Name::getNullName(); } } }

