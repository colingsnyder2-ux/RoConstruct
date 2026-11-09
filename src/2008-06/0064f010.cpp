// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_imagefourargs_106486452c33eb0d.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Rect2D.h>
// from server: 85% by king_originala
// roc 2008-06 0064f010  unit: RBX::ImageKeyButton  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064f010
//
// 0064f010  83ec10               sub esp, 0x10
// 0064f013  56                   push esi
// 0064f014  8bf1                 mov esi, ecx
// 0064f016  8b06                 mov eax, dword ptr [esi]
// 0064f018  8b5054               mov edx, dword ptr [eax + 0x54]
// 0064f01b  ffd2                 call edx
// 0064f01d  84c0                 test al, al
// 0064f01f  743f                 je 0x64f060
// 0064f021  80be4c01000000       cmp byte ptr [esi + 0x14c], 0
// 0064f028  b802000000           mov eax, 2
// 0064f02d  7506                 jne 0x64f035
// 0064f02f  8b8644010000         mov eax, dword ptr [esi + 0x144]
// 0064f035  50                   push eax
// 0064f036  8d442408             lea eax, [esp + 8]
// 0064f03a  50                   push eax
// 0064f03b  8bce                 mov ecx, esi
// 0064f03d  e8ce42f2ff           call 0x573310
// 0064f042  8b16                 mov edx, dword ptr [esi]
// 0064f044  50                   push eax
// 0064f045  8b4278               mov eax, dword ptr [edx + 0x78]
// 0064f048  8bce                 mov ecx, esi
// 0064f04a  ffd0                 call eax
// 0064f04c  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064f050  0fb6c8               movzx ecx, al
// 0064f053  51                   push ecx
// 0064f054  52                   push edx
// 0064f055  8d8e50010000         lea ecx, [esi + 0x150]
// 0064f05b  e8803dffff           call 0x642de0
// 0064f060  5e                   pop esi
// 0064f061  83c410               add esp, 0x10
// 0064f064  c20400               ret 4

struct ImageKeyButton;

typedef G3D::Rect2D ImageValue;

struct ImageState {
    void update(void* context, bool active, const ImageValue&, int);
};

struct ImageKeyButtonVTable {
    void* reserved0[21];
    bool (__thiscall *enabled)(ImageKeyButton*);
    void* reserved1[8];
    bool (__thiscall *evaluate)(ImageKeyButton*);
};

struct ImageKeyButton {
    ImageKeyButtonVTable* vtable;
    unsigned char reserved0[0x140];
    int mode;
    unsigned char reserved1[4];
    bool alternate;
    unsigned char reserved2[3];
    ImageState state;

    ImageValue getValue();
    void update(void* context);
};

void ImageKeyButton::update(void* context) {if(vtable->enabled(this)) state.update(context,vtable->evaluate(this),getValue(),alternate?2:mode);}
