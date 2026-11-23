// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no verified header available for the G3D/RBX types here, so every callee
// is declared as an opaque extern "C" fn_<addr> per the naming convention. Types and
// field offsets come from the disassembly only. The body is a best-effort sketch and
// has not been compiled or diffed.

struct Ptr { void* p; };  // INFERRED: G3D::ReferenceCountedPointer<T> is one pointer
struct V3 { float x, y, z; };

extern "C" {
void* fn_006a0920(int size);
void* __fastcall fn_00548570(void* self, int edx);
void* __fastcall fn_004e6030(void* self, int edx, void* p);
void __fastcall fn_0054c1d0(void* self, int edx, void* out);
void __fastcall fn_004377b0(void* self, int edx);
void __fastcall fn_00547440(void* self, int edx, void* a, void* b, void* c);
void* __fastcall fn_004dd2e0(void* self, int edx, int prim);
void __fastcall fn_0054ae90(void* self, int edx, int a);
void __fastcall fn_00553850(void* self, int edx, void* out);
void __fastcall fn_00542710(void* self, int edx);
void* __fastcall fn_00542990(void* self, int edx);
void __fastcall fn_00548f80(void* self, int edx, void* a, float b);
void __fastcall fn_00502a70(void* self, int edx);
void __fastcall fn_0054bf70(void* self, int edx);
void* __fastcall fn_0054bfc0(void* self, int edx, int a);
void* __fastcall fn_0054bf90(void* self, int edx);
void* __fastcall fn_0054c030(void* self, int edx, int a);
void* __fastcall fn_0054c000(void* self, int edx);
void* __fastcall fn_004f0820(void* self, int edx, void* other);
}

extern "C" Ptr* fn_00547610(Ptr* result, void* a, void* frame, float* outRadius)
{
    void* raw = fn_006a0920(0x88);
    void* mesh = raw ? fn_00548570(raw, 0) : 0;
    Ptr meshPtr;
    fn_004e6030(&meshPtr, 0, mesh);

    char bounds[12];
    fn_0054c1d0(a, 0, bounds);
    V3 lo, hi;
    fn_004377b0(&lo, 0);
    fn_004377b0(&hi, 0);
    fn_00547440(a, 0, &lo, &hi, 0);

    *outRadius = 0;
    for (int pass = 0; pass < 1; ++pass) {
        void* lraw = fn_006a0920(0x28);
        void* level = lraw ? fn_004dd2e0(lraw, 0, 5) : 0;
        Ptr levelPtr;
        fn_004e6030(&levelPtr, 0, level);
        fn_00502a70(&levelPtr, 0);
    }

    fn_004f0820(result, 0, &meshPtr);
    fn_00502a70(&meshPtr, 0);
    return result;
}
