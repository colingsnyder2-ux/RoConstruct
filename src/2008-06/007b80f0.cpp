// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_texturecacheprivateboolf28db5eaa040084d.cpp

// Candidate translation unit (score above; library headers required).
#include <RenderLib/TextureProxy.h>
#include <G3D/GImage.h>
#include <G3D/Color3.h>
#include <G3D/format.h>
#include <util/StandardOut.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#include <algorithm>

namespace RBX { namespace Render {
// Native 007b8180 consumes two references. 007b82f0 consumes a reference,
// a real 28-byte by-value std::string, and a maximum dimension (cdecl).
void resizeTexture(const G3D::GImage&, const std::string&);
void processTexture(std::string&, std::string, int);

static bool freshScaled(const std::string& scaled, const std::string& original) {
    struct _stat64i32 scaledStatus, originalStatus;
    if (_stat64i32(scaled.c_str(), &scaledStatus) != 0)
        return false;
    _stat64i32(original.c_str(), &originalStatus);
    bool result = scaledStatus.st_mtime >= originalStatus.st_mtime;
    if (!result) _unlink(scaled.c_str());
    return result;
}

G3D::TextureRef TextureProxy::resolve(G3D::RenderDevice* rd) {
#define loadedView (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0x34))
#define textureView (*reinterpret_cast<G3D::TextureRef*>(reinterpret_cast<char*>(this)+0x30))
#define manager (*reinterpret_cast<G3D::TextureManager**>(reinterpret_cast<char*>(this)+0x38))
#define tiledView (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0x3c))
#define rootView (*reinterpret_cast<G3D::ReferenceCountedPointer<TextureProxy>*>(reinterpret_cast<char*>(this)+0x40))
#define shadeView (*reinterpret_cast<G3D::ReferenceCountedPointer<TextureProxy>*>(reinterpret_cast<char*>(this)+0x44))
#define color (*reinterpret_cast<const G3D::Color3*>(reinterpret_cast<char*>(this)+0x48))
#define scale (*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x2c))
    if (!loadedView) {
        if (shadeView.notNull()) {
            char name[1024];
            sprintf(name, "%g%g%g%s", color.r, color.g, color.b, shadeView->filename.c_str());
            textureView = manager->findTexture(name);
            if (textureView.isNull()) {
                static std::string sourceFilename = shadeView->filename;
                static G3D::GImage sourceImage(sourceFilename, G3D::GImage::AUTODETECT);
                if (sourceFilename != shadeView->filename) {
                    sourceFilename = shadeView->filename;
                    sourceImage.load(sourceFilename, G3D::GImage::AUTODETECT);
                }
                G3D::GImage image(sourceImage);
                G3D::Color3uint8 lookup[256];
                for (int i = 0; i < 256; ++i) {
                    lookup[i] = G3D::Color3uint8(i, i, i);
                    shadePixel(G3D::Color3uint8(color), lookup[i]);
                }
                int count = image.width * image.height;
                for (int i = 0; i < count; ++i) {
                    unsigned char* pixel = image.byte() + i*3;
                    *reinterpret_cast<G3D::Color3uint8*>(pixel) = lookup[pixel[0]];
                }
                textureView = G3D::Texture::fromGImage(G3D::format(
                    "Generated bump texture, color = (%3.1f, %3.1f, %3.1f)", color.r, color.g, color.b),
                    image, G3D::TextureFormat::RGB8);
                manager->cacheTexture(textureView, name);
            }
        } else if (rootView.notNull()) {
            typedef G3D::TextureRef (__thiscall *ResolveMethod)(TextureProxy*, G3D::RenderDevice*);
            G3D::TextureRef resolved = reinterpret_cast<ResolveMethod>(
                (*reinterpret_cast<void***>(rootView.getPointer()))[6])(rootView.getPointer(), rd);
            if (resolved.notNull() && !resolved->opaque())
                textureView = resolved->alphaOnlyVersion();
        } else {
            try {
                if (filename == "") {
                    textureView = G3D::Texture::createEmpty(8, 8, "Texture");
                } else if ((filename.find("\\Cache\\", 0, 7) != std::string::npos
                            || filename.find("\\cache\\", 0, 7) != std::string::npos) && scale < 1.0f) {
                    std::string scaled = filename + "scaled.png";
                    int minimum = 100000;
                    if (!freshScaled(scaled, filename)) {
                        if (G3D::GImage::resolveFormat(filename) == G3D::GImage::UNKNOWN)
                            throw std::exception("unknown texture format");
                        G3D::GImage image(filename, G3D::GImage::AUTODETECT);
                        if (image.width > 128 && image.height > 128) {
                            int height = image.height * scale;
                            int width = image.width * scale;
                            minimum = std::min(height, width);
                            resizeTexture(image, scaled);
                        } else {
                            scaled = filename;
                        }
                    }
                    processTexture(scaled, scaled, std::min(minimum, 512));
                    textureView = manager->loadTexture(scaled, G3D::TextureFormat::AUTO,
                        tiledView ? G3D::Texture::TILE : G3D::Texture::TRANSPARENT_BORDER);
                } else {
                    processTexture(filename, filename, 512);
                    textureView = manager->loadTexture(filename, G3D::TextureFormat::AUTO,
                        tiledView ? G3D::Texture::TILE : G3D::Texture::TRANSPARENT_BORDER);
                }
            } catch (const std::exception& error) {
                StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load texture '%s', %s",
                                                filename.c_str(), error.what());
                textureView = 0;
            } catch (...) {
                StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load texture '%s', unknown exception",
                                                filename.c_str());
                textureView = 0;
            }
        }
        rootView = 0;
        shadeView = 0;
        loadedView = true;
    }
    return textureView;
}
} }

#undef loadedView
#undef textureView
#undef rootView
#undef shadeView
#undef color

#undef manager

#undef tiledView

#undef scale
