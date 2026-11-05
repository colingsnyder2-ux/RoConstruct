// from server: 100% by auto
// roc 2011-06 0055b740  unit: seg_00550000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055b740
//
// 0055b740  53                   push ebx
// 0055b741  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055b745  85db                 test ebx, ebx
// 0055b747  7457                 je 0x55b7a0
// 0055b749  55                   push ebp
// 0055b74a  53                   push ebx
// 0055b74b  e830080000           call 0x55bf80
// 0055b750  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 0055b756  83c404               add esp, 4
// 0055b759  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 0055b75f  85c0                 test eax, eax
// 0055b761  7e3c                 jle 0x55b79f
// 0055b763  56                   push esi
// 0055b764  89442410             mov dword ptr [esp + 0x10], eax
// 0055b768  57                   push edi
// 0055b769  8da42400000000       lea esp, [esp]
// 0055b770  8b742418             mov esi, dword ptr [esp + 0x18]
// 0055b774  85ed                 test ebp, ebp
// 0055b776  761e                 jbe 0x55b796
// 0055b778  8bfd                 mov edi, ebp
// 0055b77a  8d9b00000000         lea ebx, [ebx]
// 0055b780  8b06                 mov eax, dword ptr [esi]
// 0055b782  6a00                 push 0
// 0055b784  50                   push eax
// 0055b785  53                   push ebx
// 0055b786  e895faffff           call 0x55b220
// 0055b78b  83c40c               add esp, 0xc
// 0055b78e  83c604               add esi, 4
// 0055b791  83ef01               sub edi, 1
// 0055b794  75ea                 jne 0x55b780
// 0055b796  836c241401           sub dword ptr [esp + 0x14], 1
// 0055b79b  75d3                 jne 0x55b770
// 0055b79d  5f                   pop edi
// 0055b79e  5e                   pop esi
// 0055b79f  5d                   pop ebp
// 0055b7a0  5b                   pop ebx
// 0055b7a1  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
