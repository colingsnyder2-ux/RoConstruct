// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided, so the types below are local stand-ins.
// Layout and cast types are guessed from the disassembly. Not compiled or diffed.

struct Vector3;
struct Texture { virtual ~Texture() {} };      // INFERRED: ReferenceCountedPointer<Texture> target
struct BrickMeshBase { virtual ~BrickMeshBase() {} };   // INFERRED: RTTI source type at 0x9413f4
struct BrickMeshDerived : BrickMeshBase {};             // INFERRED: RTTI target type at 0x941418

struct TexturePtr {                            // INFERRED: G3D::ReferenceCountedPointer<Texture>
    Texture* p;
    void setPointer(Texture* t);               // 0x598fa0
};

extern "C" void* fn_006a0920(int a1);          // operator new, 0x88 bytes
extern "C" int __fastcall fn_004e3720(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004e53c0(void* self, int unusedEdx, const Vector3* v,
                                        int a, int b, int c, int d, int e, float f); // BrickMesh ctor

extern bool g_flagA;     // 0x9413c0
extern float g_scratch;  // 0x972758
extern bool g_scratchB;  // 0x97275c

extern "C" TexturePtr* fn_004e54e0(TexturePtr* out, const Vector3* v,
                                   int a, int b, int c, int d, int e, float f)
{
    out->p = 0;
    g_scratchB = false;
    if (g_flagA) {
        g_scratch = 1.0f;   // INFERRED: constant at 0x826e80
        void* mem = fn_006a0920(0x88);
        void* obj = mem ? fn_004e53c0(mem, 0, v, a, b, c, d, e, f) : 0;
        out->setPointer((Texture*)obj);
        g_scratch = 0.0f;
        g_scratchB = true;
        BrickMeshDerived* d2 = dynamic_cast<BrickMeshDerived*>((BrickMeshBase*)out->p);
        fn_004e3720(d2, 0);
        g_scratchB = false;
        return out;
    }
    g_scratch = 0.0f;
    void* mem = fn_006a0920(0x88);
    void* obj = mem ? fn_004e53c0(mem, 0, v, a, b, c, d, e, f) : 0;
    out->setPointer((Texture*)obj);
    return out;
}
