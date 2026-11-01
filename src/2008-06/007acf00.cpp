// from server: 100% by Espeon
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct MaterialPtr {
    void* p;
    void assign(void*);
    MaterialPtr& operator=(const MaterialPtr& o) { assign(o.p);return *this; }
};

struct OgreMaterialPtr { void* fields[3]; __declspec(dllimport) OgreMaterialPtr& operator=(const OgreMaterialPtr&); };

struct Obj {
    char pad0[4];
    char b4;
    MaterialPtr m8;
    MaterialPtr mc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    OgreMaterialPtr m2c;
};

extern "C" void __stdcall sub_598fa0(MaterialPtr* dst, MaterialPtr* src);

struct Level {
    char pad0[4];
    char b4;
    MaterialPtr m8;
    MaterialPtr mc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    OgreMaterialPtr m2c;
    Level* assign(const Obj* o);
};

Level* Level::assign(const Obj* o)
{
    b4 = o->b4;
    _ReadWriteBarrier();
    m8 = o->m8;
    mc = o->mc;
    f10 = o->f10;
    f14 = o->f14;
    f18 = o->f18;
    f1c = o->f1c;
    f20 = o->f20;
    f24 = o->f24;
    f28 = o->f28;
    m2c = o->m2c;
    return this;
}
