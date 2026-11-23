// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Ogre headers were shown, so the minimal Ogre declarations below are
// local stand-ins. The vtable slots and field offsets come from the disassembly.
#include <string>
#include <stdio.h>

namespace Ogre {

typedef std::string String;

struct ColourValue { float r, g, b, a; };

class Resource;
class Material;
class Technique;
class ResourceLoader;

template <class T>
class SharedPtr {
public:
    T* pRep;
    unsigned int* pUseCount;
    SharedPtr() : pRep(0), pUseCount(0) {}
    virtual ~SharedPtr() { release(); }
    virtual void destroy() {}
    void release() {
        if (pUseCount) {
            if (--(*pUseCount) == 0) destroy();
        }
    }
};

typedef SharedPtr<Resource> ResourcePtr;

class __declspec(dllimport) MaterialPtr : public SharedPtr<Material> {
public:
    MaterialPtr& operator=(const SharedPtr<Resource>& r);
};

class __declspec(dllimport) Pass {
public:
    void setAmbient(float r, float g, float b);
    void setDiffuse(float r, float g, float b, float a);
    void setSpecular(float r, float g, float b, float a);
    void setShininess(float v);
};

class __declspec(dllimport) Technique {
public:
    Pass* getPass(unsigned short index);
};

class __declspec(dllimport) Material {
public:
    Technique* getTechnique(unsigned short index);
    void setLightingEnabled(bool b);
};

#define OGRE_PAD(n) virtual void pad##n() {}

// INFERRED: slot 4 = ResourceManager::create, slot 19 = ResourceManager::getByName
class __declspec(dllimport) MaterialManager {
public:
    static MaterialManager& getSingleton();
    virtual ~MaterialManager();
    OGRE_PAD(1) OGRE_PAD(2) OGRE_PAD(3)
    virtual ResourcePtr create(const String& name, const String& group, bool isManual,
                               ResourceLoader* loader, const void* createParams);
    OGRE_PAD(5) OGRE_PAD(6) OGRE_PAD(7) OGRE_PAD(8) OGRE_PAD(9) OGRE_PAD(10)
    OGRE_PAD(11) OGRE_PAD(12) OGRE_PAD(13) OGRE_PAD(14) OGRE_PAD(15) OGRE_PAD(16)
    OGRE_PAD(17) OGRE_PAD(18)
    virtual ResourcePtr getByName(const String& name);
};

} // namespace Ogre

// INFERRED: unknown owner class; material pointer lives at +0x24
struct AdornColorOwner {
    char pad[0x24];
    Ogre::MaterialPtr material;

    void setupMaterial(const Ogre::ColourValue* c, int n);
};

extern "C" void __fastcall fn_00670400(AdornColorOwner* self, int unusedEdx,
                                       const Ogre::ColourValue* c, int n)
{
    char buf[64];
    _snprintf(buf, 64, "adrnClr%.3f%.3f%.3f%.3f%d",
              (double)c->r, (double)c->g, (double)c->b, (double)c->a, n);

    {
        Ogre::String name(buf);
        self->material = Ogre::MaterialManager::getSingleton().getByName(name);
    }

    if (self->material.pRep == 0) {
        Ogre::String group("General");
        Ogre::String name(buf);
        self->material = Ogre::MaterialManager::getSingleton().create(name, group, false, 0, 0);
    }

    Ogre::Pass* pass = self->material.pRep->getTechnique(0)->getPass(0);
    pass->setAmbient(c->r, c->g, c->b);
    pass->setDiffuse(c->r, c->g, c->b, c->a);
    pass->setSpecular(c->r, c->g, c->b, c->a);
    // INFERRED: shininess constant loaded from .rdata 0x827490; value unknown
    pass->setShininess(10.0f);
    self->material.pRep->setLightingEnabled(true);
}
