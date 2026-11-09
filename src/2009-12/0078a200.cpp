// from server: 100% by auto
// roc 2009-12 0078a200  unit: RBX::UniversalTool  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a200
//
// 0078a200  53                   push ebx
// 0078a201  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0078a205  85db                 test ebx, ebx
// 0078a207  7c4a                 jl 0x78a253
// 0078a209  56                   push esi
// 0078a20a  8b742410             mov esi, dword ptr [esp + 0x10]
// 0078a20e  8d860f270000         lea eax, [esi + 0x270f]
// 0078a214  57                   push edi
// 0078a215  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0078a219  3d0f270000           cmp eax, 0x270f
// 0078a21e  770d                 ja 0x78a22d
// 0078a220  57                   push edi
// 0078a221  e87ae5ffff           call 0x7887a0
// 0078a226  83c404               add esp, 4
// 0078a229  8d740601             lea esi, [esi + eax + 1]
// 0078a22d  6a00                 push 0
// 0078a22f  56                   push esi
// 0078a230  57                   push edi
// 0078a231  e85aeeffff           call 0x789090
// 0078a236  53                   push ebx
// 0078a237  56                   push esi
// 0078a238  57                   push edi
// 0078a239  e8d2f0ffff           call 0x789310
// 0078a23e  53                   push ebx
// 0078a23f  57                   push edi
// 0078a240  e83bebffff           call 0x788d80
// 0078a245  6a00                 push 0
// 0078a247  56                   push esi
// 0078a248  57                   push edi
// 0078a249  e8c2f0ffff           call 0x789310
// 0078a24e  83c42c               add esp, 0x2c
// 0078a251  5f                   pop edi
// 0078a252  5e                   pop esi
// 0078a253  5b                   pop ebx
// 0078a254  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_unref)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
