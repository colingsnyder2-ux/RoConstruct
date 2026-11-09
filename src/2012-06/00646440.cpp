// from server: 100% by auto
// roc 2012-06 00646440  unit: seg_00640000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00646440
//
// 00646440  53                   push ebx
// 00646441  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00646445  85db                 test ebx, ebx
// 00646447  744b                 je 0x646494
// 00646449  53                   push ebx
// 0064644a  e8b1290000           call 0x648e00
// 0064644f  83c404               add esp, 4
// 00646452  85c0                 test eax, eax
// 00646454  7e3e                 jle 0x646494
// 00646456  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 0064645c  55                   push ebp
// 0064645d  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00646461  56                   push esi
// 00646462  57                   push edi
// 00646463  89442414             mov dword ptr [esp + 0x14], eax
// 00646467  33f6                 xor esi, esi
// 00646469  8bfd                 mov edi, ebp
// 0064646b  85c9                 test ecx, ecx
// 0064646d  761b                 jbe 0x64648a
// 0064646f  90                   nop 
// 00646470  8b07                 mov eax, dword ptr [edi]
// 00646472  50                   push eax
// 00646473  53                   push ebx
// 00646474  e847f6ffff           call 0x645ac0
// 00646479  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 0064647f  46                   inc esi
// 00646480  83c408               add esp, 8
// 00646483  83c704               add edi, 4
// 00646486  3bf1                 cmp esi, ecx
// 00646488  72e6                 jb 0x646470
// 0064648a  836c241401           sub dword ptr [esp + 0x14], 1
// 0064648f  75d6                 jne 0x646467
// 00646491  5f                   pop edi
// 00646492  5e                   pop esi
// 00646493  5d                   pop ebp
// 00646494  5b                   pop ebx
// 00646495  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
