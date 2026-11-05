// from server: 100% by auto
// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_unit_afab3054ff45be52.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreImage.h"
#include "OgreString.h"
#include "OgreDataStream.h"
#include <fstream>
#include <string.h>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T>
class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void printf(int type, const char* format, ...);
};
}
extern int classify(const Ogre::String&);
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
    int type = classify(filename);
    if (type == 9) {
        RBX::StandardOut::singleton()->printf(3, "Failed to load texture '%s': unknown format", filename.c_str());
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
            RBX::StandardOut::singleton()->printf(3, "Failed to load texture '%s'", filename.c_str());
            success = false;
        }
    }
    }
    return success;
}
