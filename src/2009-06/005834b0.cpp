// from server: 100% by auto
// roc 2009-06 005834b0  unit: seg_00580000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005834b0
//
// 005834b0  53                   push ebx
// 005834b1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005834b5  85db                 test ebx, ebx
// 005834b7  7457                 je 0x583510
// 005834b9  55                   push ebp
// 005834ba  53                   push ebx
// 005834bb  e830080000           call 0x583cf0
// 005834c0  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 005834c6  83c404               add esp, 4
// 005834c9  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 005834cf  85c0                 test eax, eax
// 005834d1  7e3c                 jle 0x58350f
// 005834d3  56                   push esi
// 005834d4  89442410             mov dword ptr [esp + 0x10], eax
// 005834d8  57                   push edi
// 005834d9  8da42400000000       lea esp, [esp]
// 005834e0  8b742418             mov esi, dword ptr [esp + 0x18]
// 005834e4  85ed                 test ebp, ebp
// 005834e6  761e                 jbe 0x583506
// 005834e8  8bfd                 mov edi, ebp
// 005834ea  8d9b00000000         lea ebx, [ebx]
// 005834f0  8b06                 mov eax, dword ptr [esi]
// 005834f2  6a00                 push 0
// 005834f4  50                   push eax
// 005834f5  53                   push ebx
// 005834f6  e895faffff           call 0x582f90
// 005834fb  83c40c               add esp, 0xc
// 005834fe  83c604               add esi, 4
// 00583501  83ef01               sub edi, 1
// 00583504  75ea                 jne 0x5834f0
// 00583506  836c241401           sub dword ptr [esp + 0x14], 1
// 0058350b  75d3                 jne 0x5834e0
// 0058350d  5f                   pop edi
// 0058350e  5e                   pop esi
// 0058350f  5d                   pop ebp
// 00583510  5b                   pop ebx
// 00583511  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
