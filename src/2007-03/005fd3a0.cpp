// from server: 100% by auto
// roc 2007-03 005fd3a0  unit: seg_005f0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd3a0
//
// 005fd3a0  8b442404             mov eax, dword ptr [esp + 4]
// 005fd3a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fd3a8  53                   push ebx
// 005fd3a9  55                   push ebp
// 005fd3aa  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005fd3ae  56                   push esi
// 005fd3af  8b7010               mov esi, dword ptr [eax + 0x10]
// 005fd3b2  8b5610               mov edx, dword ptr [esi + 0x10]
// 005fd3b5  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fd3b8  57                   push edi
// 005fd3b9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005fd3bd  57                   push edi
// 005fd3be  55                   push ebp
// 005fd3bf  51                   push ecx
// 005fd3c0  52                   push edx
// 005fd3c1  ffd0                 call eax
// 005fd3c3  8bd8                 mov ebx, eax
// 005fd3c5  83c410               add esp, 0x10
// 005fd3c8  85db                 test ebx, ebx
// 005fd3ca  7513                 jne 0x5fd3df
// 005fd3cc  85ff                 test edi, edi
// 005fd3ce  760f                 jbe 0x5fd3df
// 005fd3d0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005fd3d4  6a04                 push 4
// 005fd3d6  51                   push ecx
// 005fd3d7  e8242efcff           call 0x5c0200
// 005fd3dc  83c408               add esp, 8
// 005fd3df  2bfd                 sub edi, ebp
// 005fd3e1  017e44               add dword ptr [esi + 0x44], edi
// 005fd3e4  5f                   pop edi
// 005fd3e5  5e                   pop esi
// 005fd3e6  5d                   pop ebp
// 005fd3e7  8bc3                 mov eax, ebx
// 005fd3e9  5b                   pop ebx
// 005fd3ea  c3                   ret 
// library lua-5.1.1/lmem.c (function _luaM_realloc_)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmem.c
