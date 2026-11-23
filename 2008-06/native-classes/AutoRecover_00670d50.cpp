// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <map>
#include <string>
#include <math.h>

typedef unsigned long DWORD;

// Provided by OgreVisualEngine.cpp (0x00678510).
DWORD getVideoMemory();

namespace Ogre {
    class ParticleEmitter;
    class ParticleSystem {
    public:
        unsigned int getParticleQuota() const;
        void setParticleQuota(unsigned int quota);
        ParticleEmitter* getEmitter(unsigned short index) const;
    };
}

typedef std::map<std::string, void*> SystemMap;

// INFERRED: layout reconstructed only from the member accesses in the disassembly.
// The real class is unknown; the maps are at 0xb8 and 0xf4 and hold objects
// whose virtual slot 0x13c returns a ParticleSystem subobject at +0x20.
struct ParticleBudgetOwner {
    char pad0[0x44];
    int totalParticles;
    char pad1[0xb8 - 0x48];
    SystemMap systemsA;
    char pad2[0xf4 - 0xb8 - sizeof(SystemMap)];
    SystemMap systemsB;
};

typedef void* (__thiscall *GetPSFn)(void* self, int arg);
typedef float (__thiscall *GetFloatFn)(void* self);
typedef void  (__thiscall *SetFloatFn)(void* self, float v);

static Ogre::ParticleSystem* getPS(void* holder)
{
    void** vtbl = *(void***)holder;
    char* r = (char*)((GetPSFn)vtbl[0x13c / 4])(holder, 0);
    return r ? (Ogre::ParticleSystem*)(r - 0x20) : 0;
}

extern "C" void __fastcall fn_00670d50(ParticleBudgetOwner* self, int unusedEdx)
{
    DWORD vm = getVideoMemory();
    int limit = 10000;
    if (vm < 0x3938700)
        limit = 5000;
    else if (vm > 0x11e1a300)
        limit = 12000;

    self->totalParticles = 0;

    for (SystemMap::const_iterator it = self->systemsA.begin();
         it != self->systemsA.end(); ++it)
    {
        Ogre::ParticleSystem* ps = getPS(it->second);
        self->totalParticles += ps->getParticleQuota();
    }
    for (SystemMap::const_iterator it = self->systemsB.begin();
         it != self->systemsB.end(); ++it)
    {
        Ogre::ParticleSystem* ps = getPS(it->second);
        self->totalParticles += ps->getParticleQuota();
    }

    if (self->totalParticles <= limit)
        return;

    float scale = (float)limit / (float)self->totalParticles;

    for (SystemMap::const_iterator it = self->systemsA.begin();
         it != self->systemsA.end(); ++it)
    {
        Ogre::ParticleSystem* ps = getPS(it->second);
        Ogre::ParticleEmitter* e = ps->getEmitter(0);
        unsigned int quota = ps->getParticleQuota();
        void** vt = *(void***)e;

        float v54 = ((GetFloatFn)vt[0x54 / 4])(e);
        float v58 = ((GetFloatFn)vt[0x58 / 4])(e);
        float vbc = ((GetFloatFn)vt[0xbc / 4])(e);

        ps->setParticleQuota((unsigned int)((float)quota * scale));

        // INFERRED: exponent and constants come from data-section values.
        float p = (float)pow((double)scale, 0.5);
        ((SetFloatFn)vt[0x48 / 4])(e, p * v54);
        ((SetFloatFn)vt[0x4c / 4])(e, p * v58);
        vbc = (scale - 1.0f) * 0.5f + vbc;
        ((SetFloatFn)vt[0xc0 / 4])(e, vbc);
        ((SetFloatFn)vt[0xc4 / 4])(e, vbc);
    }

    for (SystemMap::const_iterator it = self->systemsB.begin();
         it != self->systemsB.end(); ++it)
    {
        Ogre::ParticleSystem* ps = getPS(it->second);
        ps->getEmitter(0);
        ps->setParticleQuota(1);
    }

    self->totalParticles = limit;
}
