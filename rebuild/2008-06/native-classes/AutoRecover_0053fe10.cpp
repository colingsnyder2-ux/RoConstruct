// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: RenderLib/Material2008.h pulls in OgreMaterial.h, which is not available here.
// To avoid including it I declare a minimal local AggregateChunk with the real
// member name; makeMesh is defined elsewhere (AggregateChunkBuild2008.cpp).
// Assumes makeMesh is non-virtual and not in a namespace.
class AggregateChunk {
public:
    void makeMesh();
};

// INFERRED: all the opaque helper types below are guesses; the symbol names in the
// disassembly comments do not match the real callees.
struct Pair2 { int a; int b; };

extern "C" unsigned dat_00942df8;
extern "C" int dat_00972890;

extern "C" unsigned __fastcall fn_00546320(void* self, int unusedEdx);
extern "C" const unsigned* fn_004fd410(const unsigned* a, const unsigned* b);

extern "C" int __fastcall fn_005528a0(void* self, int unusedEdx, int a1);
extern "C" Pair2* __fastcall fn_00540660(void* self, int unusedEdx, void* a1);
extern "C" Pair2* __fastcall fn_00540630(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_00545da0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_00540780(void* self, int unusedEdx);
extern "C" void* __fastcall fn_00552bb0(void* self, int unusedEdx, int a1);
extern "C" char __fastcall fn_00541120(void* self, int unusedEdx);
extern "C" void* fn_006a0920(int a1);
extern "C" void* __fastcall fn_00551f30(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_00540690(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_00540530(void* self, int unusedEdx, void* a1);
extern "C" char __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int __fastcall fn_00545e30(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_005404d0(void* self, int unusedEdx);

extern "C" int __fastcall fn_00541160(void* self, int unusedEdx);
extern "C" char __fastcall fn_00540f20(void* self, int unusedEdx, void* other);
extern "C" void* __fastcall fn_005462c0(void* self, int unusedEdx);
extern "C" int __fastcall fn_005411a0(void* self, int unusedEdx, void* other);
extern "C" int __fastcall fn_005410b0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540f50(void* self, int unusedEdx);
extern "C" int* __fastcall fn_00541180(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e6030(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00541100(void* self, int unusedEdx, void* a1);
extern "C" char* __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" int __fastcall fn_00502a70(void* self, int unusedEdx);
extern "C" int __fastcall fn_0071f210(void* self, int unusedEdx);
extern "C" int __fastcall fn_004d8320(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_004d7db0(void* self, int unusedEdx, void* a1);

extern "C" void __fastcall fn_0053fe10(char* self, int unusedEdx, void* sceneMgr, int a2, int a3)
{
    void* body = self + 0xc;

    if (fn_00546320(body, 0) * 4 < dat_00942df8)
        return;

    unsigned q = fn_00546320(body, 0) / dat_00942df8;
    unsigned one = 1;
    unsigned v = *fn_004fd410(&one, &q);

    char grid[0x30];
    fn_005528a0(grid, 0, (int)v);

    Pair2 tmpA, tmpB;
    Pair2* pMax = fn_00540660(body, 0, &tmpA);
    Pair2* pMin = fn_00540630(body, 0, &tmpB);
    fn_00545da0(grid, 0, pMin->a, pMin->b, pMax->a, pMax->b);
    fn_00540780(body, 0);

    void* cell = fn_00552bb0(grid, 0, 5);

    Pair2 cur, end;
    fn_00540630(cell, 0, &cur);
    fn_00540660(cell, 0, &end);

    for (;; fn_00541160(&cur, 0))
    {
        if (!fn_00540f20(&cur, 0, &end))
            break;

        Pair2 ib, ie;
        char* inner = (char*)fn_005462c0(&cur, 0) + 0xc;
        fn_00540630(inner, 0, &ib);
        inner = (char*)fn_005462c0(&cur, 0) + 0xc;
        fn_00540660(inner, 0, &ie);

        if (fn_005411a0(&ie, 0, &ib) < 4)
            continue;

        char chunkPtr[4];
        fn_005410b0(chunkPtr, 0);

        for (;; fn_00540f50(&ib, 0))
        {
            if (!fn_00540f20(&ib, 0, &ie))
                break;

            char item[4];
            fn_004e6030(item, 0, *fn_00541180(&ib, 0));

            if (!fn_00541120(chunkPtr, 0))
            {
                void* mem = fn_006a0920(0x108);
                void* obj = 0;
                if (mem)
                    obj = fn_00551f30(mem, 0, item);
                fn_00541100(chunkPtr, 0, obj);
            }

            fn_00540690(fn_00540e80(chunkPtr, 0) + 0xf0, 0, item);
            fn_00540530((char*)fn_0071f210(item, 0) + 0x20, 0, chunkPtr);
            dat_00972890 = dat_00972890 + 1;
            fn_004d8320(sceneMgr, 0, item);
            fn_00502a70(item, 0);
        }

        if (fn_00402410(chunkPtr, 0))
        {
            // INFERRED: AggregateChunk is the object held by the pointer.
            ((AggregateChunk*)fn_00540e80(chunkPtr, 0))->makeMesh();
            char copy[4];
            fn_00545e30(copy, 0, chunkPtr);
            fn_004d7db0(sceneMgr, 0, copy);
            fn_00502a70(copy, 0);
        }
        fn_00502a70(chunkPtr, 0);
    }

    fn_005404d0(grid, 0);
}
