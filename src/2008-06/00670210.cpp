// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_espeon_textureboundsnative288799b152876954.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreTextureManager.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct ImagePtr;

struct Image {
    virtual void destroy(unsigned);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual ImagePtr resolve(void*);

    volatile long references;
    void* resource;
    Ogre::String name;

    void release();
};

struct ImagePtr {
    Image* pointer;
    ~ImagePtr();
};

inline ImagePtr::~ImagePtr()
{
    if (pointer && InterlockedDecrement(&pointer->references) == 0) {
        pointer->release();
        if (pointer)
            pointer->destroy(1);
    }
}

struct Rectangle {
    float x, y, z, w;

    Rectangle(float, float, float, float);
};

inline Rectangle::Rectangle(float a, float b, float c, float d)
    : x(a), y(b), z(c), w(d)
{
}

struct S {
    void* unused;
    void* context;

    Rectangle f(ImagePtr image);
};

Rectangle S::f(ImagePtr image)
{
    image.pointer->resolve(context);
    Ogre::TexturePtr texture(Ogre::TextureManager::getSingleton().getByName(image.pointer->name));

    unsigned second = texture->getWidth();
    unsigned first = texture->getHeight();
    float height = (float)second;
    float width = (float)first;

    return Rectangle(0.0f, 0.0f, height, width);
}
