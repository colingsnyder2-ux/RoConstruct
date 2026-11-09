// from server: 100% by auto
// roc 2012-06 006485c0  unit: seg_00640000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006485c0
//
// 006485c0  53                   push ebx
// 006485c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006485c5  85db                 test ebx, ebx
// 006485c7  7457                 je 0x648620
// 006485c9  55                   push ebp
// 006485ca  53                   push ebx
// 006485cb  e830080000           call 0x648e00
// 006485d0  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 006485d6  83c404               add esp, 4
// 006485d9  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 006485df  85c0                 test eax, eax
// 006485e1  7e3c                 jle 0x64861f
// 006485e3  56                   push esi
// 006485e4  89442410             mov dword ptr [esp + 0x10], eax
// 006485e8  57                   push edi
// 006485e9  8da42400000000       lea esp, [esp]
// 006485f0  8b742418             mov esi, dword ptr [esp + 0x18]
// 006485f4  85ed                 test ebp, ebp
// 006485f6  761e                 jbe 0x648616
// 006485f8  8bfd                 mov edi, ebp
// 006485fa  8d9b00000000         lea ebx, [ebx]
// 00648600  8b06                 mov eax, dword ptr [esi]
// 00648602  6a00                 push 0
// 00648604  50                   push eax
// 00648605  53                   push ebx
// 00648606  e895faffff           call 0x6480a0
// 0064860b  83c40c               add esp, 0xc
// 0064860e  83c604               add esi, 4
// 00648611  83ef01               sub edi, 1
// 00648614  75ea                 jne 0x648600
// 00648616  836c241401           sub dword ptr [esp + 0x14], 1
// 0064861b  75d3                 jne 0x6485f0
// 0064861d  5f                   pop edi
// 0064861e  5e                   pop esi
// 0064861f  5d                   pop ebp
// 00648620  5b                   pop ebx
// 00648621  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
