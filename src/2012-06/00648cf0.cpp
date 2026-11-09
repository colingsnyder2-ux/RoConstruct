// from server: 100% by auto
// roc 2012-06 00648cf0  unit: seg_00640000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648cf0
//
// 00648cf0  51                   push ecx
// 00648cf1  8b442408             mov eax, dword ptr [esp + 8]
// 00648cf5  53                   push ebx
// 00648cf6  57                   push edi
// 00648cf7  33ff                 xor edi, edi
// 00648cf9  33db                 xor ebx, ebx
// 00648cfb  85c0                 test eax, eax
// 00648cfd  0f84ac000000         je 0x648daf
// 00648d03  56                   push esi
// 00648d04  8b30                 mov esi, dword ptr [eax]
// 00648d06  85f6                 test esi, esi
// 00648d08  0f84a0000000         je 0x648dae
// 00648d0e  8b8644020000         mov eax, dword ptr [esi + 0x244]
// 00648d14  8944240c             mov dword ptr [esp + 0xc], eax
// 00648d18  8b442418             mov eax, dword ptr [esp + 0x18]
// 00648d1c  55                   push ebp
// 00648d1d  8bae4c020000         mov ebp, dword ptr [esi + 0x24c]
// 00648d23  85c0                 test eax, eax
// 00648d25  7402                 je 0x648d29
// 00648d27  8b38                 mov edi, dword ptr [eax]
// 00648d29  8b442420             mov eax, dword ptr [esp + 0x20]
// 00648d2d  85c0                 test eax, eax
// 00648d2f  7402                 je 0x648d33
// 00648d31  8b18                 mov ebx, dword ptr [eax]
// 00648d33  53                   push ebx
// 00648d34  57                   push edi
// 00648d35  56                   push esi
// 00648d36  e8e5fcffff           call 0x648a20
// 00648d3b  83c40c               add esp, 0xc
// 00648d3e  85ff                 test edi, edi
// 00648d40  7427                 je 0x648d69
// 00648d42  6aff                 push -1
// 00648d44  6800400000           push 0x4000
// 00648d49  57                   push edi
// 00648d4a  56                   push esi
// 00648d4b  e89051ffff           call 0x63dee0
// 00648d50  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00648d54  51                   push ecx
// 00648d55  55                   push ebp
// 00648d56  57                   push edi
// 00648d57  e884560000           call 0x64e3e0
// 00648d5c  8b542438             mov edx, dword ptr [esp + 0x38]
// 00648d60  83c41c               add esp, 0x1c
// 00648d63  c70200000000         mov dword ptr [edx], 0
// 00648d69  85db                 test ebx, ebx
// 00648d6b  7427                 je 0x648d94
// 00648d6d  6aff                 push -1
// 00648d6f  6800400000           push 0x4000
// 00648d74  53                   push ebx
// 00648d75  56                   push esi
// 00648d76  e86551ffff           call 0x63dee0
// 00648d7b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00648d7f  50                   push eax
// 00648d80  55                   push ebp
// 00648d81  53                   push ebx
// 00648d82  e859560000           call 0x64e3e0
// 00648d87  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00648d8b  83c41c               add esp, 0x1c
// 00648d8e  c70100000000         mov dword ptr [ecx], 0
// 00648d94  8b542410             mov edx, dword ptr [esp + 0x10]
// 00648d98  52                   push edx
// 00648d99  55                   push ebp
// 00648d9a  56                   push esi
// 00648d9b  e840560000           call 0x64e3e0
// 00648da0  8b442424             mov eax, dword ptr [esp + 0x24]
// 00648da4  83c40c               add esp, 0xc
// 00648da7  c70000000000         mov dword ptr [eax], 0
// 00648dad  5d                   pop ebp
// 00648dae  5e                   pop esi
// 00648daf  5f                   pop edi
// 00648db0  5b                   pop ebx
// 00648db1  59                   pop ecx
// 00648db2  c3                   ret 
// library libpng-1.2.29/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngread.c
