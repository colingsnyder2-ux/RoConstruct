// from server: 100% by auto
// roc 2009-12 00789e10  unit: RBX::UniversalTool  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789e10
//
// 00789e10  56                   push esi
// 00789e11  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00789e15  8d860f270000         lea eax, [esi + 0x270f]
// 00789e1b  57                   push edi
// 00789e1c  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00789e20  3d0f270000           cmp eax, 0x270f
// 00789e25  770d                 ja 0x789e34
// 00789e27  57                   push edi
// 00789e28  e873e9ffff           call 0x7887a0
// 00789e2d  83c404               add esp, 4
// 00789e30  8d740601             lea esi, [esi + eax + 1]
// 00789e34  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00789e38  51                   push ecx
// 00789e39  56                   push esi
// 00789e3a  57                   push edi
// 00789e3b  e870ffffff           call 0x789db0
// 00789e40  83c40c               add esp, 0xc
// 00789e43  85c0                 test eax, eax
// 00789e45  7503                 jne 0x789e4a
// 00789e47  5f                   pop edi
// 00789e48  5e                   pop esi
// 00789e49  c3                   ret 
// 00789e4a  56                   push esi
// 00789e4b  57                   push edi
// 00789e4c  e80febffff           call 0x788960
// 00789e51  6a01                 push 1
// 00789e53  6a01                 push 1
// 00789e55  57                   push edi
// 00789e56  e865f6ffff           call 0x7894c0
// 00789e5b  83c414               add esp, 0x14
// 00789e5e  5f                   pop edi
// 00789e5f  b801000000           mov eax, 1
// 00789e64  5e                   pop esi
// 00789e65  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_callmeta)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
