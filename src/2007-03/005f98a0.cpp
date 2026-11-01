// from server: 100% by auto
// roc 2007-03 005f98a0  unit: seg_005f0000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f98a0
//
// 005f98a0  8b442404             mov eax, dword ptr [esp + 4]
// 005f98a4  8b4010               mov eax, dword ptr [eax + 0x10]
// 005f98a7  80781501             cmp byte ptr [eax + 0x15], 1
// 005f98ab  750f                 jne 0x5f98bc
// 005f98ad  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005f98b1  51                   push ecx
// 005f98b2  50                   push eax
// 005f98b3  e808f1ffff           call 0x5f89c0
// 005f98b8  83c408               add esp, 8
// 005f98bb  c3                   ret 
// 005f98bc  8a5014               mov dl, byte ptr [eax + 0x14]
// 005f98bf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f98c3  8a4105               mov al, byte ptr [ecx + 5]
// 005f98c6  80e203               and dl, 3
// 005f98c9  24f8                 and al, 0xf8
// 005f98cb  0ad0                 or dl, al
// 005f98cd  885105               mov byte ptr [ecx + 5], dl
// 005f98d0  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_barrierf)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
