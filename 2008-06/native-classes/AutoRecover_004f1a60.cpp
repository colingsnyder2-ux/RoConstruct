// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were visible, so every type below is a file-local stand-in
// and every callee is declared with the fn_<addr> convention. The result is a best-effort
// reconstruction, not a verified byte match.

struct RcPtr { void* p; };                 // G3D::ReferenceCountedPointer<T> stand-in
struct Color3 { float r, g, b; };

struct MaterialKey {                       // PlayerNativeMaterial::Attributes (INFERRED layout)
    int   kind;
    float a;
    float b;
};

struct WeakRcPtr { void* p; };

struct MapNode {
    char      pad[0x18];
    MaterialKey key;                       // INFERRED
    WeakRcPtr   value;
};

struct RegistryMutex { int dummy; };

struct Registry {
    char pad0[0x20];
    char mapStorage[0x20];                 // std::map<Attributes, WeakRcPtr> lives at +0x20
    RegistryMutex mutex;                   // +0x40
};

struct MaterialObj {                       // INFERRED vtable usage
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(RcPtr tex, Color3 white, float g0, float g1, float x, float a);
};

extern Registry* g_registry;               // [0x972880]
extern long      g_onceFlag;               // [0x972884]
extern float     g_const0;                 // [0x941d5c]
extern float     g_const1;                 // [0x941d60]

extern "C" {
void  fn_00557330(void (*fn)(), long* flag);                      // boost::call_once
void  __fastcall fn_00563090(RegistryMutex* m, int);              // lock
void  __fastcall fn_005630e0(RegistryMutex* m, int);              // unlock
void  __fastcall fn_004f0d40(void* map, int, MapNode** itOut, MaterialKey* key);        // find
RcPtr* __fastcall fn_004e6c00(WeakRcPtr* w, int, RcPtr* out);                           // createStrongPtr
void  __fastcall fn_00598fa0(RcPtr* self, int, void* p);                                // setPointer
void* fn_00551730();                                                                    // new material
const Color3* fn_00514a60();                                                            // Color3::white
WeakRcPtr* __fastcall fn_004f1710(void* map, int, MaterialKey* key);                    // map::operator[]
void  __fastcall fn_004f0c40(WeakRcPtr* self, int, RcPtr* src);                         // weak = strong
void  fn_004f1a00();                                                                    // once init
}

struct GuidLock {
    RegistryMutex* m;
    explicit GuidLock(RegistryMutex* mm) : m(mm) { fn_00563090(m, 0); }
    ~GuidLock() { fn_005630e0(m, 0); }
};

extern "C" RcPtr* __fastcall fn_004f1a60(void* self, int unusedEdx, RcPtr* out, float arg2, float a, float b)
{
    fn_00557330(fn_004f1a00, &g_onceFlag);
    Registry* reg = g_registry;
    GuidLock lock(&reg->mutex);

    MaterialKey key;
    key.kind = 0xc2;
    key.a = a;
    key.b = b;

    out->p = 0;
    void* map = reg->mapStorage;

    MapNode* found = 0;
    fn_004f0d40(map, 0, &found, &key);
    MapNode* endNode = *(MapNode**)((char*)map + 0x18);

    if (found != endNode) {
        RcPtr tmp;
        RcPtr* strong = fn_004e6c00(&found->value, 0, &tmp);
        fn_00598fa0(out, 0, strong->p);
        // tmp released by its destructor (InterlockedDecrement / zeroWeakPointers / delete)
    }

    if (out->p == 0) {
        fn_00598fa0(out, 0, fn_00551730());
        MaterialObj* m = (MaterialObj*)out->p;
        if (a == 1.0f) {
            m->v1();
        } else {
            Color3 white = *fn_00514a60();
            RcPtr copy;
            copy.p = 0;
            fn_00598fa0(&copy, 0, out->p);
            m->v3(copy, white, g_const0, g_const1, arg2, a);
        }
        WeakRcPtr* slot = fn_004f1710(map, 0, &key);
        fn_004f0c40(slot, 0, out);
    }
    return out;
}
