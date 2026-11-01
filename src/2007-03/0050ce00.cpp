// from server: 100% by auto
// roc 2007-03 0050ce00  unit: seg_00500000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050ce00
//
// 0050ce00  53                   push ebx
// 0050ce01  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0050ce05  55                   push ebp
// 0050ce06  53                   push ebx
// 0050ce07  e884120000           call 0x50e090
// 0050ce0c  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 0050ce12  83c404               add esp, 4
// 0050ce15  85c0                 test eax, eax
// 0050ce17  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 0050ce1d  7e30                 jle 0x50ce4f
// 0050ce1f  56                   push esi
// 0050ce20  89442410             mov dword ptr [esp + 0x10], eax
// 0050ce24  57                   push edi
// 0050ce25  85ed                 test ebp, ebp
// 0050ce27  8b742418             mov esi, dword ptr [esp + 0x18]
// 0050ce2b  7619                 jbe 0x50ce46
// 0050ce2d  8bfd                 mov edi, ebp
// 0050ce2f  90                   nop 
// 0050ce30  8b06                 mov eax, dword ptr [esi]
// 0050ce32  6a00                 push 0
// 0050ce34  50                   push eax
// 0050ce35  53                   push ebx
// 0050ce36  e825faffff           call 0x50c860
// 0050ce3b  83c40c               add esp, 0xc
// 0050ce3e  83c604               add esi, 4
// 0050ce41  83ef01               sub edi, 1
// 0050ce44  75ea                 jne 0x50ce30
// 0050ce46  836c241401           sub dword ptr [esp + 0x14], 1
// 0050ce4b  75d8                 jne 0x50ce25
// 0050ce4d  5f                   pop edi
// 0050ce4e  5e                   pop esi
// 0050ce4f  5d                   pop ebp
// 0050ce50  5b                   pop ebx
// 0050ce51  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
