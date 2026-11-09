// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_espeon_textureproxynativeb30bf89b484e5cdc.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <string>
#include "OgreTexture.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct ControlBlock {
    virtual ~ControlBlock();
    volatile long references;
    void dispose();
};

struct Reference {
    ControlBlock *pointer;
    ~Reference();
};

inline Reference::~Reference()
{
    if (pointer) {
        if (InterlockedDecrement(&pointer->references) == 0) {
            pointer->dispose();
            delete pointer;
        }
        pointer = 0;
    }
}

typedef std::string String;

struct Root {
    virtual ~Root();
};

inline Root::~Root()
{
}

struct Base : Root {
    unsigned char padding[8];
    String name;
    virtual ~Base();
};

inline Base::~Base()
{
}

struct TextureProxy : Base {
    unsigned char padding28[8];
    Reference reference30;
    unsigned char padding34[12];
    Reference reference40;
    Reference reference44;
    unsigned char padding48[12];
    Ogre::TexturePtr texture;
    virtual ~TextureProxy();
};

TextureProxy::~TextureProxy()
{
}
