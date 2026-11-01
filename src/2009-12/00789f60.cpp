// from server: 100% by auto
// roc 2009-12 00789f60  unit: RBX::UniversalTool  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789f60
//
// 00789f60  55                   push ebp
// 00789f61  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00789f65  56                   push esi
// 00789f66  be01000000           mov esi, 1
// 00789f6b  397504               cmp dword ptr [ebp + 4], esi
// 00789f6e  7e5d                 jle 0x789fcd
// 00789f70  53                   push ebx
// 00789f71  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00789f74  57                   push edi
// 00789f75  6aff                 push -1
// 00789f77  53                   push ebx
// 00789f78  e893ecffff           call 0x788c10
// 00789f7d  83c408               add esp, 8
// 00789f80  89442414             mov dword ptr [esp + 0x14], eax
// 00789f84  bffeffffff           mov edi, 0xfffffffe
// 00789f89  8da42400000000       lea esp, [esp]
// 00789f90  57                   push edi
// 00789f91  53                   push ebx
// 00789f92  e879ecffff           call 0x788c10
// 00789f97  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00789f9a  8bd1                 mov edx, ecx
// 00789f9c  2bd6                 sub edx, esi
// 00789f9e  42                   inc edx
// 00789f9f  83c408               add esp, 8
// 00789fa2  83fa0a               cmp edx, 0xa
// 00789fa5  7d06                 jge 0x789fad
// 00789fa7  39442414             cmp dword ptr [esp + 0x14], eax
// 00789fab  760a                 jbe 0x789fb7
// 00789fad  01442414             add dword ptr [esp + 0x14], eax
// 00789fb1  46                   inc esi
// 00789fb2  4f                   dec edi
// 00789fb3  3bf1                 cmp esi, ecx
// 00789fb5  7cd9                 jl 0x789f90
// 00789fb7  56                   push esi
// 00789fb8  53                   push ebx
// 00789fb9  e8b2f7ffff           call 0x789770
// 00789fbe  83c408               add esp, 8
// 00789fc1  b801000000           mov eax, 1
// 00789fc6  2bc6                 sub eax, esi
// 00789fc8  014504               add dword ptr [ebp + 4], eax
// 00789fcb  5f                   pop edi
// 00789fcc  5b                   pop ebx
// 00789fcd  5e                   pop esi
// 00789fce  5d                   pop ebp
// 00789fcf  c3                   ret 
// library lua-5.1/lauxlib.c (function _adjuststack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
