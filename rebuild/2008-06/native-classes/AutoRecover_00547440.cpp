// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: every callee is declared as an fn_<address> extern, because no native headers were shown.
// INFERRED: the callee names in the disassembly comments are mislabeled by identical-code folding, so the real roles are guessed from usage.
// INFERRED: 0x71f210 is a smart-pointer get(), 0x4dc3d0 is empty(), 0x502a70 is zeroPointer(), 0x540f20 is iterator operator!=.
// INFERRED: exception-unwind state is not reproduced; the smart pointers are released by explicit calls.
// INFERRED: g_009738f0 is a global object (list of vertices) used as a 'this' pointer.

struct V3 { float x, y, z; };
struct Iter { int a, b; };

extern "C" char g_009738f0[];

extern "C" const V3* fn_00510960();
extern "C" V3* __fastcall fn_00514be0(V3* self, int unusedEdx, const V3* src);
extern "C" V3* __fastcall fn_00483410(const V3* self, int unusedEdx, V3* ret);
extern "C" int __fastcall fn_0054c1d0(void* self, int unusedEdx, void* out);
extern "C" int __fastcall fn_00553850(void* self, int unusedEdx, void* out);
extern "C" int __fastcall fn_00542710(void* self, int unusedEdx);
extern "C" void* __fastcall fn_00542990(void* self, int unusedEdx);
extern "C" int __fastcall fn_00548f80(void* self, int unusedEdx, void* out, float t);
extern "C" bool __fastcall fn_00540f20(void* self, int unusedEdx, void* other);
extern "C" void** __fastcall fn_0071f210(void* self, int unusedEdx);
extern "C" bool __fastcall fn_004dc3d0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);
extern "C" unsigned __fastcall fn_00442cd0(void* self, int unusedEdx);
extern "C" int* __fastcall fn_0047f7e0(void* self, int unusedEdx, int i);
extern "C" V3* __fastcall fn_00518b80(void* self, int unusedEdx, int i);
extern "C" V3* __fastcall fn_004766a0(void* self, int unusedEdx, V3* ret, const V3* p);
extern "C" V3* __fastcall fn_00525e60(V3* self, int unusedEdx, V3* ret, const V3* o);
extern "C" V3* __fastcall fn_00525e00(V3* self, int unusedEdx, V3* ret, const V3* o);

typedef void* (__thiscall *VFn1)(void* self, void* out);
typedef void* (__thiscall *VFn0)(void* self);

extern "C" void fn_00547440(void* self, V3* lo, V3* hi)
{
    V3 negInf;
    Iter end;
    Iter it;

    fn_00514be0(lo, 0, fn_00510960());
    fn_00514be0(hi, 0, fn_00483410(fn_00510960(), 0, &negInf));

    fn_0054c1d0(self, 0, &end);
    fn_00553850(self, 0, &it);

    for (;; fn_00542710(&it, 0))
    {
        if (!fn_00540f20(&it, 0, &end))
            break;

        void* elem = fn_00542990(&it, 0);

        void* ref1[1];
        void** o1 = fn_0071f210(elem, 0);
        ((VFn1)((void**)*o1)[6])(o1, ref1);
        if (fn_004dc3d0(ref1, 0)) {
            fn_00502a70(ref1, 0);
            continue;
        }

        void** o2 = fn_0071f210(elem, 0);
        void* cframe = ((VFn0)((void**)*o2)[7])(o2);

        void* ref2[1];
        fn_00548f80(fn_0071f210(ref1, 0), 0, ref2, 0.0f);

        char* list = (char*)fn_0071f210(ref2, 0) + 0xc;
        for (int i = 0; i < (int)fn_00442cd0(list, 0); ++i)
        {
            int idx = *fn_0047f7e0(list, 0, i);
            V3* vert = fn_00518b80((void*)g_009738f0, 0, idx);
            V3 w;
            V3 tmp;
            fn_004766a0(cframe, 0, &w, vert);
            fn_00514be0(hi, 0, fn_00525e60(hi, 0, &tmp, &w));
            fn_00514be0(lo, 0, fn_00525e00(lo, 0, &tmp, &w));
        }

        fn_00502a70(ref2, 0);
        fn_00502a70(ref1, 0);
    }
}
