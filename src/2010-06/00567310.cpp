// from server: 100% by auto
// roc 2010-06 00567310  unit: seg_00560000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567310
//
// 00567310  51                   push ecx
// 00567311  8b442408             mov eax, dword ptr [esp + 8]
// 00567315  53                   push ebx
// 00567316  57                   push edi
// 00567317  33ff                 xor edi, edi
// 00567319  33db                 xor ebx, ebx
// 0056731b  85c0                 test eax, eax
// 0056731d  0f84ac000000         je 0x5673cf
// 00567323  56                   push esi
// 00567324  8b30                 mov esi, dword ptr [eax]
// 00567326  85f6                 test esi, esi
// 00567328  0f84a0000000         je 0x5673ce
// 0056732e  8b8644020000         mov eax, dword ptr [esi + 0x244]
// 00567334  8944240c             mov dword ptr [esp + 0xc], eax
// 00567338  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056733c  55                   push ebp
// 0056733d  8bae4c020000         mov ebp, dword ptr [esi + 0x24c]
// 00567343  85c0                 test eax, eax
// 00567345  7402                 je 0x567349
// 00567347  8b38                 mov edi, dword ptr [eax]
// 00567349  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056734d  85c0                 test eax, eax
// 0056734f  7402                 je 0x567353
// 00567351  8b18                 mov ebx, dword ptr [eax]
// 00567353  53                   push ebx
// 00567354  57                   push edi
// 00567355  56                   push esi
// 00567356  e8e5fcffff           call 0x567040
// 0056735b  83c40c               add esp, 0xc
// 0056735e  85ff                 test edi, edi
// 00567360  7427                 je 0x567389
// 00567362  6aff                 push -1
// 00567364  6800400000           push 0x4000
// 00567369  57                   push edi
// 0056736a  56                   push esi
// 0056736b  e8c0dcffff           call 0x565030
// 00567370  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00567374  51                   push ecx
// 00567375  55                   push ebp
// 00567376  57                   push edi
// 00567377  e844b10000           call 0x5724c0
// 0056737c  8b542438             mov edx, dword ptr [esp + 0x38]
// 00567380  83c41c               add esp, 0x1c
// 00567383  c70200000000         mov dword ptr [edx], 0
// 00567389  85db                 test ebx, ebx
// 0056738b  7427                 je 0x5673b4
// 0056738d  6aff                 push -1
// 0056738f  6800400000           push 0x4000
// 00567394  53                   push ebx
// 00567395  56                   push esi
// 00567396  e895dcffff           call 0x565030
// 0056739b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056739f  50                   push eax
// 005673a0  55                   push ebp
// 005673a1  53                   push ebx
// 005673a2  e819b10000           call 0x5724c0
// 005673a7  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005673ab  83c41c               add esp, 0x1c
// 005673ae  c70100000000         mov dword ptr [ecx], 0
// 005673b4  8b542410             mov edx, dword ptr [esp + 0x10]
// 005673b8  52                   push edx
// 005673b9  55                   push ebp
// 005673ba  56                   push esi
// 005673bb  e800b10000           call 0x5724c0
// 005673c0  8b442424             mov eax, dword ptr [esp + 0x24]
// 005673c4  83c40c               add esp, 0xc
// 005673c7  c70000000000         mov dword ptr [eax], 0
// 005673cd  5d                   pop ebp
// 005673ce  5e                   pop esi
// 005673cf  5f                   pop edi
// 005673d0  5b                   pop ebx
// 005673d1  59                   pop ecx
// 005673d2  c3                   ret 
// library libpng-1.2.29/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngread.c
