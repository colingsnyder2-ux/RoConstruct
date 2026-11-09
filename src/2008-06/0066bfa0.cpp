// from server: 100% by auto
// roc 2008-06 0066bfa0  unit: RBX::GroupDragTool  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066bfa0
//
// 0066bfa0  83ec18               sub esp, 0x18
// 0066bfa3  d9ee                 fldz 
// 0066bfa5  83c8ff               or eax, 0xffffffff
// 0066bfa8  89442414             mov dword ptr [esp + 0x14], eax
// 0066bfac  dd5c2408             fstp qword ptr [esp + 8]
// 0066bfb0  89442410             mov dword ptr [esp + 0x10], eax
// 0066bfb4  8b442420             mov eax, dword ptr [esp + 0x20]
// 0066bfb8  83e800               sub eax, 0
// 0066bfbb  53                   push ebx
// 0066bfbc  57                   push edi
// 0066bfbd  c744240805000000     mov dword ptr [esp + 8], 5
// 0066bfc5  7443                 je 0x66c00a
// 0066bfc7  83e801               sub eax, 1
// 0066bfca  7429                 je 0x66bff5
// 0066bfcc  83e801               sub eax, 1
// 0066bfcf  755f                 jne 0x66c030
// 0066bfd1  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0066bfd5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0066bfd9  53                   push ebx
// 0066bfda  57                   push edi
// 0066bfdb  e8d0f8ffff           call 0x66b8b0
// 0066bfe0  8d442410             lea eax, [esp + 0x10]
// 0066bfe4  50                   push eax
// 0066bfe5  6a14                 push 0x14
// 0066bfe7  e874feffff           call 0x66be60
// 0066bfec  83c410               add esp, 0x10
// 0066bfef  5f                   pop edi
// 0066bff0  5b                   pop ebx
// 0066bff1  83c418               add esp, 0x18
// 0066bff4  c3                   ret 
// 0066bff5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0066bff9  56                   push esi
// 0066bffa  8b742430             mov esi, dword ptr [esp + 0x30]
// 0066bffe  e87dfdffff           call 0x66bd80
// 0066c003  5e                   pop esi
// 0066c004  5f                   pop edi
// 0066c005  5b                   pop ebx
// 0066c006  83c418               add esp, 0x18
// 0066c009  c3                   ret 
// 0066c00a  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0066c00e  833b04               cmp dword ptr [ebx], 4
// 0066c011  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0066c015  750a                 jne 0x66c021
// 0066c017  53                   push ebx
// 0066c018  57                   push edi
// 0066c019  e892f8ffff           call 0x66b8b0
// 0066c01e  83c408               add esp, 8
// 0066c021  8d4c2408             lea ecx, [esp + 8]
// 0066c025  51                   push ecx
// 0066c026  6a12                 push 0x12
// 0066c028  e833feffff           call 0x66be60
// 0066c02d  83c408               add esp, 8
// 0066c030  5f                   pop edi
// 0066c031  5b                   pop ebx
// 0066c032  83c418               add esp, 0x18
// 0066c035  c3                   ret 
// library lua-5.1.2/lcode.c (function _luaK_prefix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lcode.c
