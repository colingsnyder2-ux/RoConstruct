// from server: 100% by auto
// roc 2011-06 0056bb10  unit: seg_00560000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056bb10
//
// 0056bb10  56                   push esi
// 0056bb11  8b742408             mov esi, dword ptr [esp + 8]
// 0056bb15  85f6                 test esi, esi
// 0056bb17  746b                 je 0x56bb84
// 0056bb19  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056bb1d  53                   push ebx
// 0056bb1e  57                   push edi
// 0056bb1f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056bb23  57                   push edi
// 0056bb24  50                   push eax
// 0056bb25  56                   push esi
// 0056bb26  e885eeffff           call 0x56a9b0
// 0056bb2b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056bb2f  83c40c               add esp, 0xc
// 0056bb32  85db                 test ebx, ebx
// 0056bb34  7417                 je 0x56bb4d
// 0056bb36  85ff                 test edi, edi
// 0056bb38  7613                 jbe 0x56bb4d
// 0056bb3a  57                   push edi
// 0056bb3b  53                   push ebx
// 0056bb3c  56                   push esi
// 0056bb3d  e8feecfeff           call 0x55a840
// 0056bb42  57                   push edi
// 0056bb43  53                   push ebx
// 0056bb44  56                   push esi
// 0056bb45  e8064dfeff           call 0x550850
// 0056bb4a  83c418               add esp, 0x18
// 0056bb4d  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056bb53  8bd0                 mov edx, eax
// 0056bb55  8bc8                 mov ecx, eax
// 0056bb57  c1e918               shr ecx, 0x18
// 0056bb5a  c1ea10               shr edx, 0x10
// 0056bb5d  884c2410             mov byte ptr [esp + 0x10], cl
// 0056bb61  88542411             mov byte ptr [esp + 0x11], dl
// 0056bb65  6a04                 push 4
// 0056bb67  8d542414             lea edx, [esp + 0x14]
// 0056bb6b  8bc8                 mov ecx, eax
// 0056bb6d  52                   push edx
// 0056bb6e  c1e908               shr ecx, 8
// 0056bb71  56                   push esi
// 0056bb72  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056bb76  8844241f             mov byte ptr [esp + 0x1f], al
// 0056bb7a  e8c1ecfeff           call 0x55a840
// 0056bb7f  83c40c               add esp, 0xc
// 0056bb82  5f                   pop edi
// 0056bb83  5b                   pop ebx
// 0056bb84  5e                   pop esi
// 0056bb85  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
