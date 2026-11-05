// from server: 100% by auto
// roc 2009-12 007cdd00  unit: RBX::PartDropTool  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdd00
//
// 007cdd00  8b442404             mov eax, dword ptr [esp + 4]
// 007cdd04  8b4010               mov eax, dword ptr [eax + 0x10]
// 007cdd07  80781501             cmp byte ptr [eax + 0x15], 1
// 007cdd0b  750f                 jne 0x7cdd1c
// 007cdd0d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007cdd11  51                   push ecx
// 007cdd12  50                   push eax
// 007cdd13  e838f1ffff           call 0x7cce50
// 007cdd18  83c408               add esp, 8
// 007cdd1b  c3                   ret 
// 007cdd1c  8a5014               mov dl, byte ptr [eax + 0x14]
// 007cdd1f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007cdd23  8a4105               mov al, byte ptr [ecx + 5]
// 007cdd26  80e203               and dl, 3
// 007cdd29  24f8                 and al, 0xf8
// 007cdd2b  0ad0                 or dl, al
// 007cdd2d  885105               mov byte ptr [ecx + 5], dl
// 007cdd30  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_barrierf)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
