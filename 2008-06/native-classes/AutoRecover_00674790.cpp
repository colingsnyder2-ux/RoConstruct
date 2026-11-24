// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

// Minimal Ogre 1.4.5 declarations (only the imported members used here).
namespace Ogre
{
    typedef std::string String;
    class Matrix3;
    class ParticleEmitter;

    class Vector3
    {
    public:
        float x, y, z;
        __declspec(dllimport) static const Vector3 ZERO;
    };

    class Quaternion
    {
    public:
        float w, x, y, z;
        __declspec(dllimport) Quaternion(float fW, float fX, float fY, float fZ);
        __declspec(dllimport) void FromRotationMatrix(const Matrix3& kRot);
        __declspec(dllimport) static const Quaternion IDENTITY;
    };

    class ParticleSystem
    {
    public:
        __declspec(dllimport) unsigned int getNumParticles(void) const;
        __declspec(dllimport) ParticleEmitter* getEmitter(unsigned short index) const;
        __declspec(dllimport) void setParticleQuota(unsigned int quota);
        __declspec(dllimport) void _update(float timeElapsed);
    };

    class ParticleSystemManager
    {
    public:
        __declspec(dllimport) static ParticleSystemManager& getSingleton(void);
        __declspec(dllimport) ParticleSystem* getTemplate(const String& name);
    };

    class MaterialManager
    {
    public:
        __declspec(dllimport) static MaterialManager& getSingleton(void);
    };

    class MemoryDataStream
    {
    public:
        __declspec(dllimport) MemoryDataStream(void* pMem, unsigned int size, bool freeOnClose);
    };

    class StringConverter
    {
    public:
        __declspec(dllimport) static String toString(unsigned int val, unsigned short width,
                                                     char fill, int flags);
    };
}

namespace RBX { namespace LDraw2Lua {
    std::string resolveMapPath(const char* path);
} }

extern "C" int __fastcall fn_006740e0(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);

// INFERRED: embedded material / particle script sources (std::string globals)
extern std::string g_0097db10;
extern std::string g_0097daf4;

// ---- vtable call helpers (thiscall through fastcall with dummy edx) ----
typedef void* (__fastcall *VFn0)(void*, int);
typedef void* (__fastcall *VFn1)(void*, int, int);
typedef void* (__fastcall *VFn2)(void*, int, void*, void*);
typedef void* (__fastcall *VFn3)(void*, int, void*, void*, void*);
typedef void  (__fastcall *VFnF3)(void*, int, float, float, float);
typedef bool  (__fastcall *VFnB)(void*, int);
typedef bool  (__fastcall *VFnS)(void*, int, void*);

static inline void* vslot(void* obj, int off)
{
    return *(void**)(*(char**)obj + off);
}

// SceneNode::getAttachedObject(0) cast to ParticleSystem (MovableObject base at +0x20)
static inline Ogre::ParticleSystem* nodeParticles(void* node)
{
    char* mo = (char*)((VFn1)vslot(node, 0x13c))(node, 0, 0);
    return mo ? (Ogre::ParticleSystem*)(mo - 0x20) : 0;
}

static inline void emitterEnable(Ogre::ParticleEmitter* e, int on)
{
    ((VFn1)vslot(e, 0xa4))(e, 0, on);
}

typedef std::map<std::string, void*> NodeMap;   // map<string, SceneNode*>
typedef std::vector<void*> NodePool;            // vector<SceneNode*>

// INFERRED: sparkle context layout (offsets from disassembly)
#define CTX_SCENE(self)   (*(char**)((char*)(self) + 0x4))
#define CTX_OBJ30(self)   (*(void**)((char*)(self) + 0x30))
#define CTX_ROOT(self)    (*(void**)((char*)(self) + 0xd8))
#define CTX_POOL(self)    (*(NodePool*)((char*)(self) + 0xdc))
#define CTX_MAP(self)     (*(NodeMap*)((char*)(self) + 0xf4))
#define CTX_ROT(self)     (*(Ogre::Matrix3*)((char*)(self) + 0x114))
#define CTX_POS(self)     ((char*)(self) + 0x138)

extern "C" void __fastcall fn_00674790(void* self, int unusedEdx)
{
    Ogre::Quaternion q(1.0f, 0.0f, 0.0f, 0.0f);
    q.FromRotationMatrix(CTX_ROT(self));

    void* o30 = CTX_OBJ30(self);
    void* xf = ((VFn2)vslot(o30, 0x188))(o30, 0, CTX_POS(self), &q);
    Ogre::Vector3* p = (Ogre::Vector3*)((VFn0)vslot(xf, 0x70))(xf, 0);
    Ogre::Vector3 pos;
    pos.x = p->x; pos.y = p->y; pos.z = p->z;

    char key[64];
    _snprintf(key, 64, "%.1f %.1f %.1f", (double)pos.x, (double)pos.y, (double)pos.z);

    NodeMap& nodes = CTX_MAP(self);
    if (nodes.find(std::string(key)) != nodes.end())
    {
        Ogre::ParticleSystem* ps = nodeParticles(nodes[std::string(key)]);
        if (ps->getNumParticles() == 0)
        {
            emitterEnable(ps->getEmitter(0), 0);
            ps->setParticleQuota(1);
            nodes.erase(nodes.find(std::string(key)));
        }
        return;
    }

    // collect finished sparkles
    std::vector<NodeMap::iterator> dead;
    for (NodeMap::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        if (nodeParticles(it->second)->getNumParticles() == 0)
            fn_006740e0(&dead, 0, (int)&it);   // dead.push_back(it)
    }
    for (unsigned int i = 0; i < dead.size(); ++i)
    {
        Ogre::ParticleSystem* ps = nodeParticles(dead[i]->second);
        emitterEnable(ps->getEmitter(0), 0);
        nodes.erase(dead[i]);
        ps->setParticleQuota(1);
    }

    // look for a free pooled node
    NodePool& pool = CTX_POOL(self);
    unsigned int idx = 0;
    for (; idx < pool.size(); ++idx)
    {
        Ogre::ParticleSystem* ps = nodeParticles(pool[idx]);
        Ogre::ParticleEmitter* em = ps->getEmitter(0);
        if (!((VFnB)vslot(em, 0xa8))(em, 0))
        {
            void* node = pool[idx];
            nodes[std::string(key)] = node;
            ((VFnF3)vslot(node, 0x68))(node, 0, pos.x, pos.y, pos.z);
            Ogre::ParticleSystem* ps2 = nodeParticles(node);
            emitterEnable(ps2->getEmitter(0), 1);
            ps2->_update(0.1f);   // INFERRED: constant at 0x81839c
            break;
        }
    }
    if (idx != pool.size())
        return;

    // material / template creation on first use
    {
        Ogre::MaterialManager& mm = Ogre::MaterialManager::getSingleton();
        std::string matName("sparkle/sparkleMatl");
        if (!((VFnS)vslot(&mm, 0x58))(&mm, 0, &matName))
        {
            // INFERRED: parse embedded material script, then set sparkle texture
            Ogre::MemoryDataStream* ds = (Ogre::MemoryDataStream*)fn_006a0920(0x34);
            if (ds)
                new (ds) Ogre::MemoryDataStream((void*)g_0097db10.c_str(),
                                                (unsigned int)g_0097db10.size() + 1, false);
            std::string tex = RBX::LDraw2Lua::resolveMapPath("textures\\sparkle.png");
            (void)tex;
        }
        std::string tmplName("sparkle/sparkle1");
        if (Ogre::ParticleSystemManager::getSingleton().getTemplate(tmplName) == 0)
        {
            Ogre::MemoryDataStream* ds = (Ogre::MemoryDataStream*)fn_006a0920(0x34);
            if (ds)
                new (ds) Ogre::MemoryDataStream((void*)g_0097daf4.c_str(),
                                                (unsigned int)g_0097daf4.size() + 1, false);
        }
    }

    char* sceneMgr = *(char**)(CTX_SCENE(self) + 4);
    if (CTX_ROOT(self) == 0)
    {
        void* root = ((VFn0)vslot(sceneMgr, 0xb4))(sceneMgr, 0);
        std::string n = *(std::string*)(sceneMgr + 4) + "rbxsparkle";
        CTX_ROOT(self) = ((VFn3)vslot(root, 0x184))(root, 0, &n,
                              (void*)&Ogre::Vector3::ZERO, (void*)&Ogre::Quaternion::IDENTITY);
    }

    // INFERRED: remainder (truncated disassembly) creates a new pooled sparkle node
    std::string tmpl("sparkle/sparkle1");
    std::string name = *(std::string*)(sceneMgr + 4) + "sparkle"
                       + Ogre::StringConverter::toString(idx, 0, ' ', 0);
    (void)tmpl;
    (void)name;
}
