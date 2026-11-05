// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_imagefourargs_444ad92da4cfd437.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Rect2D.h>
// from server: 82% by king_originala
// roc 2008-06 0064f0c0  unit: RBX::ImageButton  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064f0c0
//
// 0064f0c0  83ec10               sub esp, 0x10
// 0064f0c3  56                   push esi
// 0064f0c4  8bf1                 mov esi, ecx
// 0064f0c6  8b06                 mov eax, dword ptr [esi]
// 0064f0c8  8b5054               mov edx, dword ptr [eax + 0x54]
// 0064f0cb  ffd2                 call edx
// 0064f0cd  84c0                 test al, al
// 0064f0cf  7431                 je 0x64f102
// 0064f0d1  8b8644010000         mov eax, dword ptr [esi + 0x144]
// 0064f0d7  50                   push eax
// 0064f0d8  8d4c2408             lea ecx, [esp + 8]
// 0064f0dc  51                   push ecx
// 0064f0dd  8bce                 mov ecx, esi
// 0064f0df  e82c42f2ff           call 0x573310
// 0064f0e4  8b16                 mov edx, dword ptr [esi]
// 0064f0e6  50                   push eax
// 0064f0e7  8b4278               mov eax, dword ptr [edx + 0x78]
// 0064f0ea  8bce                 mov ecx, esi
// 0064f0ec  ffd0                 call eax
// 0064f0ee  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064f0f2  0fb6c8               movzx ecx, al
// 0064f0f5  51                   push ecx
// 0064f0f6  52                   push edx
// 0064f0f7  8d8e4c010000         lea ecx, [esi + 0x14c]
// 0064f0fd  e8de3cffff           call 0x642de0
// 0064f102  5e                   pop esi
// 0064f103  83c410               add esp, 0x10
// 0064f106  c20400               ret 4

typedef G3D::Rect2D Value;

struct State {
    void update(void *, bool, const Value&, unsigned long);
};

struct ImageButton;

struct ButtonTable {
    void *reserved0[21];
    bool (__thiscall *enabled)(ImageButton *);
    void *reserved1[8];
    bool (__thiscall *accept)(ImageButton *);
};

struct ImageButton {
    ButtonTable *table;
    unsigned char padding0[0x140];
    unsigned long value;
    unsigned long padding1;
    State state;

    Value makeValue();
    void update(void *);
};

void ImageButton::update(void* context) {if(table->enabled(this)) state.update(context,table->accept(this),makeValue(),value);}
