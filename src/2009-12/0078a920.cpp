// from server: 100% by auto
// roc 2009-12 0078a920  unit: RBX::UniversalTool  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a920
//
// 0078a920  56                   push esi
// 0078a921  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a925  57                   push edi
// 0078a926  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078a92a  56                   push esi
// 0078a92b  57                   push edi
// 0078a92c  e85fe0ffff           call 0x788990
// 0078a931  83c408               add esp, 8
// 0078a934  85c0                 test eax, eax
// 0078a936  7f07                 jg 0x78a93f
// 0078a938  8b442414             mov eax, dword ptr [esp + 0x14]
// 0078a93c  5f                   pop edi
// 0078a93d  5e                   pop esi
// 0078a93e  c3                   ret 
// 0078a93f  56                   push esi
// 0078a940  57                   push edi
// 0078a941  e86affffff           call 0x78a8b0
// 0078a946  83c408               add esp, 8
// 0078a949  5f                   pop edi
// 0078a94a  5e                   pop esi
// 0078a94b  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_optinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
