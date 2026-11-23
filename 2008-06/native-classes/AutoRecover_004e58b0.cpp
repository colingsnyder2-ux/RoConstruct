// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort draft. Types are local analogs, not authentic headers.
// Not compiled or diffed against the original.
#include <string.h>

struct Vector3 { float x, y, z; };

struct BrickMesh;

// INFERRED: G3D::ReferenceCountedPointer<BrickMesh> analog, a single pointer.
struct MeshPtr { BrickMesh* p; };

extern "C" void fn_00557330(void (*f)(), long* flag); // boost::call_once
extern "C" int __fastcall fn_004ddf80(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_004e2c80(char* self, int unusedEdx, const Vec3* size, int arg2, BrickColorArg color);

// INFERRED: callee names from the disassembly comments.
extern "C" void __fastcall fn_00563090(void* mutex, int unusedEdx);  // GuidRegistryMutex::lock
extern "C" void __fastcall fn_005630e0(void* mutex, int unusedEdx);  // GuidRegistryMutex::unlock
extern "C" int  fn_00515780(int lo, int hi);                         // G3D::iRandom
extern "C" void __fastcall fn_00598fa0(MeshPtr* self, int unusedEdx, BrickMesh* p); // setPointer
extern "C" void __fastcall fn_004e53c0(void* self, int unusedEdx, const Vector3* v,
                                       int a, int b, int c, int d, int e, float f); // BrickMesh ctor
extern "C" void fn_004e5710();                                       // BrickMesh::releaseUnused

extern char g_flag_009413c0;
extern float g_f_00826e80;
extern float g_f_00972758;
extern char g_b_0097275c;
extern char* g_registry_00972754;

extern "C" MeshPtr* fn_004e58b0(MeshPtr* ret, const Vector3* v, int a, int b)
{
    Vector3 local = *v;
    (void)local;
    ret->p = 0;

    char* reg = g_registry_00972754;
    void* mutex = reg + 0x20;
    fn_00563090(mutex, 0);

    int* bucket = (int*)fn_004ddf80(reg, 0, (int)&local);
    int idx;
    if (*bucket == 4) {
        idx = fn_00515780(0, 3);
    } else {
        int r = fn_00515780(0, 8);
        idx = r < 3 ? r : 3;
    }
    BrickMesh** slot = (BrickMesh**)(bucket + 1 + idx);

    fn_00598fa0(ret, 0, *slot);
    if (ret->p == 0) {
        void* mem = (void*)fn_006a0920(0x88);
        BrickMesh* m = 0;
        if (mem) {
            fn_004e53c0(mem, 0, v, a, b, 0, 0, 0, 0.0f);
            m = (BrickMesh*)mem;
        }
        fn_00598fa0(ret, 0, m);
        fn_00598fa0((MeshPtr*)slot, 0, ret->p);
        ++*bucket;
        int* counter = (int*)(reg + 0x2c);
        if (++*counter % 100 == 0) {
            fn_004e5710();
        }
    }
    fn_005630e0(mutex, 0);
    return ret;
}
