// from server: 100% by Intel
// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 004593b0  unit: CRobloxView  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004593b0
//
// 004593b0  53                   push ebx
// 004593b1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004593b5  55                   push ebp
// 004593b6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004593ba  56                   push esi
// 004593bb  57                   push edi
// 004593bc  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004593c0  53                   push ebx
// 004593c1  55                   push ebp
// 004593c2  57                   push edi
// 004593c3  8bf1                 mov esi, ecx
// 004593c5  e8fe782400           call 0x6a0cc8
// 004593ca  85ff                 test edi, edi
// 004593cc  7422                 je 0x4593f0
// 004593ce  8b4654               mov eax, dword ptr [esi + 0x54]
// 004593d1  50                   push eax
// 004593d2  6a01                 push 1
// 004593d4  e8c7c6faff           call 0x405aa0
// 004593d9  83c408               add esp, 8
// 004593dc  6a01                 push 1
// 004593de  8d8eb0000000         lea ecx, [esi + 0xb0]
// 004593e4  e8072a2b00           call 0x70bdf0
// 004593e9  5f                   pop edi
// 004593ea  5e                   pop esi
// 004593eb  5d                   pop ebp
// 004593ec  5b                   pop ebx
// 004593ed  c20c00               ret 0xc
// 004593f0  3beb                 cmp ebp, ebx
// 004593f2  741b                 je 0x45940f
// 004593f4  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004593f7  51                   push ecx
// 004593f8  6a00                 push 0
// 004593fa  e8a1c6faff           call 0x405aa0
// 004593ff  83c408               add esp, 8
// 00459402  6a00                 push 0
// 00459404  8d8eb0000000         lea ecx, [esi + 0xb0]
// 0045940a  e8e1292b00           call 0x70bdf0
// 0045940f  5f                   pop edi
// 00459410  5e                   pop esi
// 00459411  5d                   pop ebp
// 00459412  5b                   pop ebx
// 00459413  c20c00               ret 0xc

extern "C" void __cdecl updateState(int enabled, void* handle);

struct S_func_0070bdf0 {
    void f(int a1);
};

struct CRobloxView {
    char padding0[0x54];
    void* handle;
    char padding1[0x30];
    S_func_0070bdf0 state;

    void baseActivate(int active, void* activated, void* deactivated);
    void activate(int active, void* activated, void* deactivated);
};

void CRobloxView::activate(int active, void* activated, void* deactivated)
{
    baseActivate(active, activated, deactivated);
    if (active) {
        updateState(1, handle);
        state.f(1);
    } else if (activated != deactivated) {
        updateState(0, handle);
        state.f(0);
    }
}
