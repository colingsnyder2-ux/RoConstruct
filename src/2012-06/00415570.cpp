// from server: 100% by Xemicl
// roc 2012-06 00415570  unit: CIDEBrowserView  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415570
//
// 00415570  83ec10               sub esp, 0x10
// 00415573  53                   push ebx
// 00415574  55                   push ebp
// 00415575  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00415579  56                   push esi
// 0041557a  8bd9                 mov ebx, ecx
// 0041557c  57                   push edi
// 0041557d  8db300010000         lea esi, [ebx + 0x100]
// 00415583  33ff                 xor edi, edi
// 00415585  85f6                 test esi, esi
// 00415587  7446                 je 0x4155cf
// 00415589  397e20               cmp dword ptr [esi + 0x20], edi
// 0041558c  7441                 je 0x4155cf
// 0041558e  8b06                 mov eax, dword ptr [esi]
// 00415590  8b9004020000         mov edx, dword ptr [eax + 0x204]
// 00415596  57                   push edi
// 00415597  68cb000000           push 0xcb
// 0041559c  55                   push ebp
// 0041559d  8d4c241c             lea ecx, [esp + 0x1c]
// 004155a1  51                   push ecx
// 004155a2  8bce                 mov ecx, esi
// 004155a4  ffd2                 call edx
// 004155a6  8b7804               mov edi, dword ptr [eax + 4]
// 004155a9  8b08                 mov ecx, dword ptr [eax]
// 004155ab  6a01                 push 1
// 004155ad  57                   push edi
// 004155ae  55                   push ebp
// 004155af  6a00                 push 0
// 004155b1  894c2428             mov dword ptr [esp + 0x28], ecx
// 004155b5  6a00                 push 0
// 004155b7  8bce                 mov ecx, esi
// 004155b9  e81ccf5600           call 0x9824da
// 004155be  8b9320010000         mov edx, dword ptr [ebx + 0x120]
// 004155c4  6a00                 push 0
// 004155c6  6a00                 push 0
// 004155c8  52                   push edx
// 004155c9  ff15ec3bb200         call dword ptr [0xb23bec]
// 004155cf  8d8b9c000000         lea ecx, [ebx + 0x9c]
// 004155d5  85c9                 test ecx, ecx
// 004155d7  741a                 je 0x4155f3
// 004155d9  83792000             cmp dword ptr [ecx + 0x20], 0
// 004155dd  7414                 je 0x4155f3
// 004155df  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004155e3  6a1c                 push 0x1c
// 004155e5  2bc7                 sub eax, edi
// 004155e7  50                   push eax
// 004155e8  55                   push ebp
// 004155e9  57                   push edi
// 004155ea  6a00                 push 0
// 004155ec  6a00                 push 0
// 004155ee  e8e1ce5600           call 0x9824d4
// 004155f3  5f                   pop edi
// 004155f4  5e                   pop esi
// 004155f5  5d                   pop ebp
// 004155f6  5b                   pop ebx
// 004155f7  83c410               add esp, 0x10
// 004155fa  c20c00               ret 0xc
// copied from an identical function in another client (function ?resize@CBrowserView@ns_ROCX00000f@@QAEXHHH@Z)

namespace ns_ROCX00000f {
// from server: 100% by king_originala
// roc 2008-06 0040e040  unit: CBrowserView  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e040
//
// 0040e040  83ec10               sub esp, 0x10
// 0040e043  53                   push ebx
// 0040e044  55                   push ebp
// 0040e045  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0040e049  56                   push esi
// 0040e04a  8bd9                 mov ebx, ecx
// 0040e04c  57                   push edi
// 0040e04d  8db31c010000         lea esi, [ebx + 0x11c]
// 0040e053  33ff                 xor edi, edi
// 0040e055  85f6                 test esi, esi
// 0040e057  7446                 je 0x40e09f
// 0040e059  397e20               cmp dword ptr [esi + 0x20], edi
// 0040e05c  7441                 je 0x40e09f
// 0040e05e  8b06                 mov eax, dword ptr [esi]
// 0040e060  8b9004020000         mov edx, dword ptr [eax + 0x204]
// 0040e066  57                   push edi
// 0040e067  68cb000000           push 0xcb
// 0040e06c  55                   push ebp
// 0040e06d  8d4c241c             lea ecx, [esp + 0x1c]
// 0040e071  51                   push ecx
// 0040e072  8bce                 mov ecx, esi
// 0040e074  ffd2                 call edx
// 0040e076  8b7804               mov edi, dword ptr [eax + 4]
// 0040e079  8b08                 mov ecx, dword ptr [eax]
// 0040e07b  6a01                 push 1
// 0040e07d  57                   push edi
// 0040e07e  55                   push ebp
// 0040e07f  6a00                 push 0
// 0040e081  894c2428             mov dword ptr [esp + 0x28], ecx
// 0040e085  6a00                 push 0
// 0040e087  8bce                 mov ecx, esi
// 0040e089  e8be292900           call 0x6a0a4c
// 0040e08e  8b933c010000         mov edx, dword ptr [ebx + 0x13c]
// 0040e094  6a00                 push 0
// 0040e096  6a00                 push 0
// 0040e098  52                   push edx
// 0040e099  ff15182e8000         call dword ptr [0x802e18]
// 0040e09f  8d8b9c000000         lea ecx, [ebx + 0x9c]
// 0040e0a5  85c9                 test ecx, ecx
// 0040e0a7  741a                 je 0x40e0c3
// 0040e0a9  83792000             cmp dword ptr [ecx + 0x20], 0
// 0040e0ad  7414                 je 0x40e0c3
// 0040e0af  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0040e0b3  6a1c                 push 0x1c
// 0040e0b5  2bc7                 sub eax, edi
// 0040e0b7  50                   push eax
// 0040e0b8  55                   push ebp
// 0040e0b9  57                   push edi
// 0040e0ba  6a00                 push 0
// 0040e0bc  6a00                 push 0
// 0040e0be  e883292900           call 0x6a0a46
// 0040e0c3  5f                   pop edi
// 0040e0c4  5e                   pop esi
// 0040e0c5  5d                   pop ebp
// 0040e0c6  5b                   pop ebx
// 0040e0c7  83c410               add esp, 0x10
// 0040e0ca  c20c00               ret 0xc

struct Control;

struct Size {
    int cx;
    int cy;
};

struct ControlTable {
    void* slots[129];
    Size* (__thiscall* measure)(Control*, Size*, int, int, int);
};

struct Control {
    ControlTable* table;
    char padding[28];
    void* window;
    char remainder[64];

    void __thiscall move(int, int, int, int, int);
    void __thiscall position(void*, int, int, int, int, unsigned int);
};

extern "C" {
    extern int (__stdcall* InvalidateRect)(void*, const void*, int);
}

struct CBrowserView {
    char padding[156];
    Control lower;
    Control upper;

    void resize(int, int, int);
};

void CBrowserView::resize(int unused, int width, int height) {
    int topHeight = 0;
    Control* top = &upper;

    if (top && top->window) {
        Size temporary;
        Size size = *top->table->measure(top, &temporary, width, 203, 0);
        topHeight = size.cy;
        top->move(0, 0, width, topHeight, 1);
        InvalidateRect(upper.window, 0, 0);
    }

    Control* bottom = &lower;
    if (bottom && bottom->window)
        bottom->position(0, 0, topHeight, width, height - topHeight, 28);
}
}
