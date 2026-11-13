// native-flags: /O2 /GS- /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// TextureProxyImageLoader2008 | 2008-06 | 4 byte-exact, inactive (not link-selected)
// 4/4 mapped addresses byte-exact | 0 unproved | no mapped strings | by auto (+1) (mixed 2)
// <<< native-status | src 3ff48fc6 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include <winsock2.h>
#include <OgreImage.h>
#include <OgreString.h>
#include <OgreDataStream.h>
#include <G3D/GImage.h>
#include <leaves2008/StandardOut2008.h>
#include <fstream>
#include <cstring>
// INFERRED: loadTexture spelling; original caller TextureProxy::resolve binds007adfb0.
bool loadTexture(const Ogre::String& filename, Ogre::Image& image)
{
    const char* extensions[] = {"png","jpg","gif","bmp","tif","tiff","pbm","pgm","tga","dds","xpm","jig","ico"};
    bool success;
    int i = 0;
    do {
        const char* extension = extensions[i];
        unsigned length = strlen(extension);
        success = filename.substr(filename.length() - length - 1).find(Ogre::String(".") + extension) != Ogre::String::npos;
        if (success)
            break;
    } while (++i < 13);
    if (success) {
        success = true;
        try {
            image.load(filename, "General");
        } catch (...) {
            success = false;
        }
    } else {
    int type = G3D::GImage::resolveFormat(filename);
    if (type == 9) {
        RBX::StandardOut::singleton()->print(static_cast<RBX::MessageType>(3), "Failed to load texture '%s': unknown format", filename.c_str());
        success = false;
    } else {
        const char* ext;
        switch (type) {
        case 0: ext = "jpg"; break;
        case 1: ext = "bmp"; break;
        case 5: ext = "png"; break;
        case 2: ext = "tga"; break;
        case 4: ext = "ico"; break;
        case 3: ext = "pcx"; break;
        case 6: case 7: ext = "ppm"; break;
        }
        try {
            std::ifstream stream;
            stream.open(filename.c_str(), std::ios::in | std::ios::binary);
            Ogre::DataStreamPtr data(new Ogre::FileStreamDataStream(&stream, false));
            image.load(data, ext);
            success = true;
        } catch (...) {
            RBX::StandardOut::singleton()->print(static_cast<RBX::MessageType>(3), "Failed to load texture '%s'", filename.c_str());
            success = false;
        }
    }
    }
    return success;
}
