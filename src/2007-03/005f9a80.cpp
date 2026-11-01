// from server: 100% by auto
// roc 2007-03 005f9a80  unit: seg_005f0000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9a80
//
// 005f9a80  8b442404             mov eax, dword ptr [esp + 4]
// 005f9a84  8b4808               mov ecx, dword ptr [eax + 8]
// 005f9a87  83ec08               sub esp, 8
// 005f9a8a  83f903               cmp ecx, 3
// 005f9a8d  7431                 je 0x5f9ac0
// 005f9a8f  83f904               cmp ecx, 4
// 005f9a92  752a                 jne 0x5f9abe
// 005f9a94  8b10                 mov edx, dword ptr [eax]
// 005f9a96  8d0c24               lea ecx, [esp]
// 005f9a99  51                   push ecx
// 005f9a9a  83c210               add edx, 0x10
// 005f9a9d  52                   push edx
// 005f9a9e  e8ede9ffff           call 0x5f8490
// 005f9aa3  83c408               add esp, 8
// 005f9aa6  85c0                 test eax, eax
// 005f9aa8  7414                 je 0x5f9abe
// 005f9aaa  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f9aae  dd0424               fld qword ptr [esp]
// 005f9ab1  dd18                 fstp qword ptr [eax]
// 005f9ab3  c7400803000000       mov dword ptr [eax + 8], 3
// 005f9aba  83c408               add esp, 8
// 005f9abd  c3                   ret 
// 005f9abe  33c0                 xor eax, eax
// 005f9ac0  83c408               add esp, 8
// 005f9ac3  c3                   ret 
// library lua-5.1.1/lvm.c (function _luaV_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
