// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: layouts from disassembly only; opaque types used for helpers.
struct IterPair { int a, b; };

struct HullSet {
    unsigned total;   // +0
    unsigned count;   // +4
    char sub[1];      // +8 embedded container
    int fn(int limit);
};

extern "C" int __fastcall fn_00540630(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540660(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00552e60(void* self, int unusedEdx, int a1);
extern "C" unsigned __fastcall fn_00552a60(void* self, int unusedEdx);
extern "C" void *fn_00553340(void* self, int arg, unsigned char flag);
extern "C" EdgeFunc fn_00553380(EdgeIter first, EdgeIter last, EdgeFunc func);
extern "C" void __fastcall fn_00541160(void* self, int unusedEdx);
extern "C" bool __fastcall fn_00540f20(void* self, int unusedEdx, void* other);
extern "C" char* __fastcall fn_005462c0(void* self, int unusedEdx);
extern "C" unsigned __fastcall fn_00546320(void* self, int unusedEdx);
extern "C" void __fastcall fn_00514be0(void* self, int unusedEdx, void* src);
extern "C" const unsigned* __cdecl fn_004fd410(const unsigned* a, const unsigned* b);

extern unsigned char g_flag_009739cc;
extern "C" void fn_00552d50();

extern "C" int __fastcall fn_00552bb0(HullSet* self, int unusedEdx, int limit)
{
    int cur[2];
    int end[4];
    int t0[2], t1[2], t2[2], tmp[2];
    if (self->count > 1) {
        fn_00540630(self->sub, 0, (int)cur);
        fn_00540660(self->sub, 0, (int)end);
        for (;;) {
            if (!fn_00540f20(cur, 0, end)) break;
            char* e = fn_005462c0(cur, 0);
            if (fn_00546320(e + 0xc, 0) != 0) {
                unsigned r = rand();
                unsigned n = fn_00546320(fn_005462c0(cur, 0) + 0xc, 0);
                unsigned idx = r % n;
                int* p = (int*)fn_00552e60(fn_005462c0(cur, 0) + 0xc, 0, (int)idx);
                void* obj = (void*)*p;
                int v = (*(int (__fastcall **)(void*))(*(int*)obj + 0x1c))(obj);
                fn_00514be0(fn_005462c0(cur, 0), 0, (void*)(v + 0x24));
            }
            fn_00541160(cur, 0);
        }
        unsigned third = self->total / 0x14;
        unsigned one = 1;
        unsigned lim = *fn_004fd410(&one, &third);
        unsigned iter = 0;
        for (;;) {
            ++iter;
            if (fn_00552a60(self, 0) <= lim) break;
            if (iter == (unsigned)limit) break;
            int* a = fn_00553340(tmp, 0, (int)fn_00552d50, g_flag_009739cc, 0);
            int* b = (int*)fn_00540660(self->sub, 0, (int)t0);
            int* c = (int*)fn_00540630(self->sub, 0, (int)t1);
            fn_00553380(t2, 0, c[0], c[1], 0);
            (void)a; (void)b;
        }
    }
    return (int)(self->sub);
}
