// from server: 100% by auto
// roc 2009-12 007d17b0  unit: seg_007d0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d17b0
//
// 007d17b0  8b442404             mov eax, dword ptr [esp + 4]
// 007d17b4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d17b8  53                   push ebx
// 007d17b9  55                   push ebp
// 007d17ba  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 007d17be  56                   push esi
// 007d17bf  8b7010               mov esi, dword ptr [eax + 0x10]
// 007d17c2  8b5610               mov edx, dword ptr [esi + 0x10]
// 007d17c5  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d17c8  57                   push edi
// 007d17c9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007d17cd  57                   push edi
// 007d17ce  55                   push ebp
// 007d17cf  51                   push ecx
// 007d17d0  52                   push edx
// 007d17d1  ffd0                 call eax
// 007d17d3  8bd8                 mov ebx, eax
// 007d17d5  83c410               add esp, 0x10
// 007d17d8  85db                 test ebx, ebx
// 007d17da  7513                 jne 0x7d17ef
// 007d17dc  85ff                 test edi, edi
// 007d17de  760f                 jbe 0x7d17ef
// 007d17e0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007d17e4  6a04                 push 4
// 007d17e6  51                   push ecx
// 007d17e7  e86460fcff           call 0x797850
// 007d17ec  83c408               add esp, 8
// 007d17ef  2bfd                 sub edi, ebp
// 007d17f1  017e44               add dword ptr [esi + 0x44], edi
// 007d17f4  5f                   pop edi
// 007d17f5  5e                   pop esi
// 007d17f6  5d                   pop ebp
// 007d17f7  8bc3                 mov eax, ebx
// 007d17f9  5b                   pop ebx
// 007d17fa  c3                   ret 
// library lua-5.1/lmem.c (function _luaM_realloc_)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmem.c
