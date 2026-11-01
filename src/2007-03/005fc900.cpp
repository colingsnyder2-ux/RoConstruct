// from server: 100% by auto
// roc 2007-03 005fc900  unit: seg_005f0000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc900
//
// 005fc900  53                   push ebx
// 005fc901  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005fc905  55                   push ebp
// 005fc906  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005fc90a  56                   push esi
// 005fc90b  57                   push edi
// 005fc90c  8d3c9d14000000       lea edi, [ebx*4 + 0x14]
// 005fc913  57                   push edi
// 005fc914  6a00                 push 0
// 005fc916  6a00                 push 0
// 005fc918  55                   push ebp
// 005fc919  e8820a0000           call 0x5fd3a0
// 005fc91e  8bf0                 mov esi, eax
// 005fc920  6a06                 push 6
// 005fc922  56                   push esi
// 005fc923  55                   push ebp
// 005fc924  e8d7cfffff           call 0x5f9900
// 005fc929  8b442438             mov eax, dword ptr [esp + 0x38]
// 005fc92d  83c41c               add esp, 0x1c
// 005fc930  85db                 test ebx, ebx
// 005fc932  c6460600             mov byte ptr [esi + 6], 0
// 005fc936  89460c               mov dword ptr [esi + 0xc], eax
// 005fc939  885e07               mov byte ptr [esi + 7], bl
// 005fc93c  7413                 je 0x5fc951
// 005fc93e  8d0437               lea eax, [edi + esi]
// 005fc941  83eb01               sub ebx, 1
// 005fc944  83e804               sub eax, 4
// 005fc947  85db                 test ebx, ebx
// 005fc949  c70000000000         mov dword ptr [eax], 0
// 005fc94f  75f0                 jne 0x5fc941
// 005fc951  5f                   pop edi
// 005fc952  8bc6                 mov eax, esi
// 005fc954  5e                   pop esi
// 005fc955  5d                   pop ebp
// 005fc956  5b                   pop ebx
// 005fc957  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_newLclosure)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
