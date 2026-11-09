// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_imagefourargs_d03d18a9a201d155.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Rect2D.h>
// from server: 81% by king_originala
// roc 2008-06 0064f070  unit: RBX::ImageWidget  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064f070
//
// 0064f070  83ec10               sub esp, 0x10
// 0064f073  56                   push esi
// 0064f074  8bf1                 mov esi, ecx
// 0064f076  8b06                 mov eax, dword ptr [esi]
// 0064f078  8b5054               mov edx, dword ptr [eax + 0x54]
// 0064f07b  ffd2                 call edx
// 0064f07d  84c0                 test al, al
// 0064f07f  742c                 je 0x64f0ad
// 0064f081  6a00                 push 0
// 0064f083  8d442408             lea eax, [esp + 8]
// 0064f087  50                   push eax
// 0064f088  8bce                 mov ecx, esi
// 0064f08a  e88142f2ff           call 0x573310
// 0064f08f  8b16                 mov edx, dword ptr [esi]
// 0064f091  50                   push eax
// 0064f092  8b4278               mov eax, dword ptr [edx + 0x78]
// 0064f095  8bce                 mov ecx, esi
// 0064f097  ffd0                 call eax
// 0064f099  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064f09d  0fb6c8               movzx ecx, al
// 0064f0a0  51                   push ecx
// 0064f0a1  52                   push edx
// 0064f0a2  8d8e48010000         lea ecx, [esi + 0x148]
// 0064f0a8  e8333dffff           call 0x642de0
// 0064f0ad  5e                   pop esi
// 0064f0ae  83c410               add esp, 0x10
// 0064f0b1  c20400               ret 4

typedef G3D::Rect2D Value;

struct Painter {
    void draw(void *, bool, const Value&, int);
};

struct ImageWidget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool enabled();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual bool evaluate();

    char padding[0x144];
    Painter painter;

    Value getValue();
    void render(void *);
};

void ImageWidget::render(void* context) {if(enabled()) painter.draw(context,evaluate(),getValue(),0);}
