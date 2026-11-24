// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target address is the middle of a larger stdcall routine (3 dwords, ret 12).
// The real function's prologue and loop head are not in the disassembly, so they are guessed here.
// INFERRED: no project headers are included because Material2008.h needs OgreMaterial.h, which is not on the include path.

extern "C" int  __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int  __fastcall fn_00545e30(void* self, int unusedEdx, int a1);
extern "C" int  __fastcall fn_005404d0(void* self, int unusedEdx);

// INFERRED: callees without header names.
extern "C" int  __fastcall fn_00540e80(void* self, int unusedEdx);            // UnorderedSet::GetQuantity-like
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);            // ReferenceCountedPointer::zeroPointer
extern "C" void __fastcall fn_004d7db0(void* self, int unusedEdx, void* ref); // SimpleSceneManager::addModel
extern "C" void __fastcall fn_004d8320(void* self, int unusedEdx, void* ref); // SceneManager::removeFromScene
extern "C" void __fastcall fn_00552270(void* self, int unusedEdx);            // AggregateChunk::makeMesh

// INFERRED: RAII wrapper whose destructor calls zeroPointer.
struct RcPtr
{
    void* p;
    RcPtr() : p(0) {}
    ~RcPtr() { fn_00502a70(this, 0); }
};

// INFERRED: object at [ebp-0x44] whose destructor is fn_005404d0.
struct LocalObj
{
    int d[4];
    LocalObj() { d[0] = d[1] = d[2] = d[3] = 0; }
    ~LocalObj() { fn_005404d0(this, 0); }
};

extern "C" void __stdcall fn_00540058(void* self, int a1, int a2)
{
    LocalObj obj;

    // INFERRED: the head of the loop (before 0x53ff10) is unknown; the condition is a guess.
    for (int i = 0; i < a2; ++i)
    {
        RcPtr cur;
        fn_004d8320(self, 0, &cur);
        {
            RcPtr tmp;
        }
        if ((unsigned char)fn_00402410(&cur, 0))
        {
            int q = fn_00540e80(&cur, 0);
            fn_00552270((void*)q, 0);
            RcPtr model;
            fn_00545e30(&model, 0, (int)&cur);
            fn_004d7db0(self, 0, &model);
        }
    }
    (void)a1;
}
