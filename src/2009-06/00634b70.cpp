// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a9bd0  unit: RBX::VScriptContext::?$FactoryProduct  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a9bd0
//
// 005a9bd0  56                   push esi
// 005a9bd1  8b742408             mov esi, dword ptr [esp + 8]
// 005a9bd5  57                   push edi
// 005a9bd6  56                   push esi
// 005a9bd7  e834800600           call 0x611c10
// 005a9bdc  68d09b5a00           push 0x5a9bd0
// 005a9be1  56                   push esi
// 005a9be2  e829880600           call 0x612410
// 005a9be7  68f0d8ffff           push 0xffffd8f0
// 005a9bec  56                   push esi
// 005a9bed  e8fe880600           call 0x6124f0
// 005a9bf2  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005a9bf6  57                   push edi
// 005a9bf7  56                   push esi
// 005a9bf8  e813880600           call 0x612410
// 005a9bfd  6afe                 push -2
// 005a9bff  56                   push esi
// 005a9c00  e8eb880600           call 0x6124f0
// 005a9c05  6aff                 push -1
// 005a9c07  56                   push esi
// 005a9c08  e8f3810600           call 0x611e00
// 005a9c0d  83c42c               add esp, 0x2c
// 005a9c10  85c0                 test eax, eax
// 005a9c12  754c                 jne 0x5a9c60
// 005a9c14  6afe                 push -2
// 005a9c16  56                   push esi
// 005a9c17  e804800600           call 0x611c20
// 005a9c1c  6a04                 push 4
// 005a9c1e  56                   push esi
// 005a9c1f  e81c900600           call 0x612c40
// 005a9c24  83c410               add esp, 0x10
// 005a9c27  85c0                 test eax, eax
// 005a9c29  7402                 je 0x5a9c2d
// 005a9c2b  8938                 mov dword ptr [eax], edi
// 005a9c2d  a1dcb19500           mov eax, dword ptr [0x95b1dc]
// 005a9c32  50                   push eax
// 005a9c33  68f0d8ffff           push 0xffffd8f0
// 005a9c38  56                   push esi
// 005a9c39  e852880600           call 0x612490
// 005a9c3e  6afe                 push -2
// 005a9c40  56                   push esi
// 005a9c41  e8aa8b0600           call 0x6127f0
// 005a9c46  57                   push edi
// 005a9c47  56                   push esi
// 005a9c48  e8c3870600           call 0x612410
// 005a9c4d  6afe                 push -2
// 005a9c4f  56                   push esi
// 005a9c50  e87b810600           call 0x611dd0
// 005a9c55  6afc                 push -4
// 005a9c57  56                   push esi
// 005a9c58  e8b38a0600           call 0x612710
// 005a9c5d  83c42c               add esp, 0x2c
// 005a9c60  6afe                 push -2
// 005a9c62  56                   push esi
// 005a9c63  e808800600           call 0x611c70
// 005a9c68  83c408               add esp, 8
// 005a9c6b  5f                   pop edi
// 005a9c6c  5e                   pop esi
// 005a9c6d  c3                   ret 

extern "C" int __cdecl sub_611c10(void* L);
extern "C" void __cdecl sub_611c20(void* L, int idx);
extern "C" void __cdecl sub_611c70(void* L, int idx);
extern "C" void __cdecl sub_611dd0(void* L, int idx);
extern "C" int __cdecl sub_611e00(void* L, int idx);
extern "C" void __cdecl sub_612410(void* L, int idx);
extern "C" void __cdecl sub_612490(void* L, int idx, void* value);
extern "C" void __cdecl sub_6124f0(void* L, int idx);
extern "C" void __cdecl sub_612710(void* L, int idx);
extern "C" void __cdecl sub_6127f0(void* L, int idx);
extern "C" void* __cdecl sub_612c40(void* L, int size);

extern void* g_95b1dc;

void __cdecl f(void* a, void* b);

void __cdecl f(void* a, void* b)
{
    void* L = a;
    sub_611c10(L);
    sub_612410(L, (int)&f);
    sub_6124f0(L, -10000);
    sub_612410(L, (int)b);
    sub_6124f0(L, -2);
    if (sub_611e00(L, -1) == 0) {
        sub_611c20(L, -2);
        void* p = sub_612c40(L, 4);
        if (p)
            *(void**)p = b;
        sub_612490(L, -10000, g_95b1dc);
        sub_6127f0(L, -2);
        sub_612410(L, (int)b);
        sub_611dd0(L, -2);
        sub_612710(L, -4);
    }
    sub_611c70(L, -2);
}
