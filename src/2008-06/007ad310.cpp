// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_espeon_materiallevelnative3737af79d4bf57eb.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreMaterialManager.h"
#include "OgreMaterial.h"
#include "OgreLogManager.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Control {
    virtual ~Control();
    volatile long count;
    void *object;
    void release();
};

struct Reference {
    Control *p;
    ~Reference();
};

inline Reference::~Reference()
{
    if (p) {
        if (InterlockedDecrement(&p->count) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

struct Base {
    virtual ~Base();
};

inline Base::~Base()
{
}

struct Level : Base {
    unsigned long reserved0;
    Reference first;
    Reference second;
    unsigned char reserved1[28];
    Ogre::MaterialPtr material;
    ~Level();
};

Level::~Level(){
 if(!material.isNull()){
 Ogre::String name(material->getName());
 Ogre::MaterialManager::getSingleton().remove(material->getHandle());
 Ogre::LogManager::getSingleton().logMessage("RBX removed "+name,Ogre::LML_NORMAL,false);
 }
}
