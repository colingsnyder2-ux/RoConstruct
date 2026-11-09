// roc 2009-12 00804590  unit: CXTPCommandBar  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00804590
//
// 00804590  56                   push esi
// 00804591  8bf1                 mov esi, ecx
// 00804593  8b8664010000         mov eax, dword ptr [esi + 0x164]
// 00804599  85c0                 test eax, eax
// 0080459b  7538                 jne 0x8045d5
// 0080459d  e82effffff           call 0x8044d0
// 008045a2  85c0                 test eax, eax
// 008045a4  7408                 je 0x8045ae
// 008045a6  8bc8                 mov ecx, eax
// 008045a8  5e                   pop esi
// 008045a9  e932010100           jmp 0x8146e0
// 008045ae  8bce                 mov ecx, esi
// 008045b0  e8ebfeffff           call 0x8044a0
// 008045b5  8b8064010000         mov eax, dword ptr [eax + 0x164]
// 008045bb  85c0                 test eax, eax
// 008045bd  7516                 jne 0x8045d5
// 008045bf  3905a4adb900         cmp dword ptr [0xb9ada4], eax
// 008045c5  7509                 jne 0x8045d0
// 008045c7  50                   push eax
// 008045c8  e893a0ffff           call 0x7fe660
// 008045cd  83c404               add esp, 4
// 008045d0  a1a4adb900           mov eax, dword ptr [0xb9ada4]
// 008045d5  5e                   pop esi
// 008045d6  c3                   ret 
// copied from an identical function in another client (function ?getSomething@CXTPCommandBar@ns_ROCX000003@ns_ROCX00003e@@QAEHXZ)

namespace ns_ROCX000003 {
extern void G1_func_00711680();
void fn_ROCX000003()
{
    G1_func_00711680();
}
}
