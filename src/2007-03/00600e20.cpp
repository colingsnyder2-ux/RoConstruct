// from server: 100% by auto
// roc 2007-03 00600e20  unit: seg_00600000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600e20
//
// 00600e20  53                   push ebx
// 00600e21  56                   push esi
// 00600e22  57                   push edi
// 00600e23  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00600e27  33db                 xor ebx, ebx
// 00600e29  8da42400000000       lea esp, [esp]
// 00600e30  8b349d68097c00       mov esi, dword ptr [ebx*4 + 0x7c0968]
// 00600e37  8bc6                 mov eax, esi
// 00600e39  8d5001               lea edx, [eax + 1]
// 00600e3c  8d642400             lea esp, [esp]
// 00600e40  8a08                 mov cl, byte ptr [eax]
// 00600e42  83c001               add eax, 1
// 00600e45  84c9                 test cl, cl
// 00600e47  75f7                 jne 0x600e40
// 00600e49  2bc2                 sub eax, edx
// 00600e4b  50                   push eax
// 00600e4c  56                   push esi
// 00600e4d  57                   push edi
// 00600e4e  e8cdb8ffff           call 0x5fc720
// 00600e53  80480520             or byte ptr [eax + 5], 0x20
// 00600e57  8acb                 mov cl, bl
// 00600e59  80c101               add cl, 1
// 00600e5c  83c301               add ebx, 1
// 00600e5f  83c40c               add esp, 0xc
// 00600e62  83fb15               cmp ebx, 0x15
// 00600e65  884806               mov byte ptr [eax + 6], cl
// 00600e68  7cc6                 jl 0x600e30
// 00600e6a  5f                   pop edi
// 00600e6b  5e                   pop esi
// 00600e6c  5b                   pop ebx
// 00600e6d  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_init)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
