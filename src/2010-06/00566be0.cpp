// from server: 100% by auto
// roc 2010-06 00566be0  unit: seg_00560000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00566be0
//
// 00566be0  53                   push ebx
// 00566be1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00566be5  85db                 test ebx, ebx
// 00566be7  7457                 je 0x566c40
// 00566be9  55                   push ebp
// 00566bea  53                   push ebx
// 00566beb  e830080000           call 0x567420
// 00566bf0  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 00566bf6  83c404               add esp, 4
// 00566bf9  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 00566bff  85c0                 test eax, eax
// 00566c01  7e3c                 jle 0x566c3f
// 00566c03  56                   push esi
// 00566c04  89442410             mov dword ptr [esp + 0x10], eax
// 00566c08  57                   push edi
// 00566c09  8da42400000000       lea esp, [esp]
// 00566c10  8b742418             mov esi, dword ptr [esp + 0x18]
// 00566c14  85ed                 test ebp, ebp
// 00566c16  761e                 jbe 0x566c36
// 00566c18  8bfd                 mov edi, ebp
// 00566c1a  8d9b00000000         lea ebx, [ebx]
// 00566c20  8b06                 mov eax, dword ptr [esi]
// 00566c22  6a00                 push 0
// 00566c24  50                   push eax
// 00566c25  53                   push ebx
// 00566c26  e895faffff           call 0x5666c0
// 00566c2b  83c40c               add esp, 0xc
// 00566c2e  83c604               add esi, 4
// 00566c31  83ef01               sub edi, 1
// 00566c34  75ea                 jne 0x566c20
// 00566c36  836c241401           sub dword ptr [esp + 0x14], 1
// 00566c3b  75d3                 jne 0x566c10
// 00566c3d  5f                   pop edi
// 00566c3e  5e                   pop esi
// 00566c3f  5d                   pop ebp
// 00566c40  5b                   pop ebx
// 00566c41  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
