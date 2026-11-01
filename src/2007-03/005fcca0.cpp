// from server: 100% by auto
// roc 2007-03 005fcca0  unit: seg_005f0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcca0
//
// 005fcca0  56                   push esi
// 005fcca1  8b742408             mov esi, dword ptr [esp + 8]
// 005fcca5  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fcca8  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fccab  8d4c2408             lea ecx, [esp + 8]
// 005fccaf  51                   push ecx
// 005fccb0  52                   push edx
// 005fccb1  50                   push eax
// 005fccb2  8b4608               mov eax, dword ptr [esi + 8]
// 005fccb5  ffd0                 call eax
// 005fccb7  83c40c               add esp, 0xc
// 005fccba  85c0                 test eax, eax
// 005fccbc  741d                 je 0x5fccdb
// 005fccbe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fccc2  85c9                 test ecx, ecx
// 005fccc4  7415                 je 0x5fccdb
// 005fccc6  83c1ff               add ecx, -1
// 005fccc9  894604               mov dword ptr [esi + 4], eax
// 005fcccc  890e                 mov dword ptr [esi], ecx
// 005fccce  0fb608               movzx ecx, byte ptr [eax]
// 005fccd1  83c001               add eax, 1
// 005fccd4  894604               mov dword ptr [esi + 4], eax
// 005fccd7  8bc1                 mov eax, ecx
// 005fccd9  5e                   pop esi
// 005fccda  c3                   ret 
// 005fccdb  83c8ff               or eax, 0xffffffff
// 005fccde  5e                   pop esi
// 005fccdf  c3                   ret 
// library lua-5.1.1/lzio.c (function _luaZ_fill)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lzio.c
