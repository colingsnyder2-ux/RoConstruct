// from server: 100% by auto
// roc 2007-03 005ba620  unit: seg_005b0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba620
//
// 005ba620  56                   push esi
// 005ba621  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ba625  57                   push edi
// 005ba626  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005ba62a  56                   push esi
// 005ba62b  57                   push edi
// 005ba62c  e80fe6ffff           call 0x5b8c40
// 005ba631  83c408               add esp, 8
// 005ba634  85c0                 test eax, eax
// 005ba636  7f2f                 jg 0x5ba667
// 005ba638  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005ba63c  85ff                 test edi, edi
// 005ba63e  8b442414             mov eax, dword ptr [esp + 0x14]
// 005ba642  7432                 je 0x5ba676
// 005ba644  85c0                 test eax, eax
// 005ba646  7418                 je 0x5ba660
// 005ba648  8bc8                 mov ecx, eax
// 005ba64a  8d7101               lea esi, [ecx + 1]
// 005ba64d  8d4900               lea ecx, [ecx]
// 005ba650  8a11                 mov dl, byte ptr [ecx]
// 005ba652  83c101               add ecx, 1
// 005ba655  84d2                 test dl, dl
// 005ba657  75f7                 jne 0x5ba650
// 005ba659  2bce                 sub ecx, esi
// 005ba65b  890f                 mov dword ptr [edi], ecx
// 005ba65d  5f                   pop edi
// 005ba65e  5e                   pop esi
// 005ba65f  c3                   ret 
// 005ba660  33c9                 xor ecx, ecx
// 005ba662  890f                 mov dword ptr [edi], ecx
// 005ba664  5f                   pop edi
// 005ba665  5e                   pop esi
// 005ba666  c3                   ret 
// 005ba667  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ba66b  50                   push eax
// 005ba66c  56                   push esi
// 005ba66d  57                   push edi
// 005ba66e  e84dffffff           call 0x5ba5c0
// 005ba673  83c40c               add esp, 0xc
// 005ba676  5f                   pop edi
// 005ba677  5e                   pop esi
// 005ba678  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_optlstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
