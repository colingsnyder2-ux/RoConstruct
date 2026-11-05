// from server: 100% by auto
// roc 2009-06 00583be0  unit: seg_00580000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583be0
//
// 00583be0  51                   push ecx
// 00583be1  8b442408             mov eax, dword ptr [esp + 8]
// 00583be5  53                   push ebx
// 00583be6  57                   push edi
// 00583be7  33ff                 xor edi, edi
// 00583be9  33db                 xor ebx, ebx
// 00583beb  85c0                 test eax, eax
// 00583bed  0f84ac000000         je 0x583c9f
// 00583bf3  56                   push esi
// 00583bf4  8b30                 mov esi, dword ptr [eax]
// 00583bf6  85f6                 test esi, esi
// 00583bf8  0f84a0000000         je 0x583c9e
// 00583bfe  8b8644020000         mov eax, dword ptr [esi + 0x244]
// 00583c04  8944240c             mov dword ptr [esp + 0xc], eax
// 00583c08  8b442418             mov eax, dword ptr [esp + 0x18]
// 00583c0c  55                   push ebp
// 00583c0d  8bae4c020000         mov ebp, dword ptr [esi + 0x24c]
// 00583c13  85c0                 test eax, eax
// 00583c15  7402                 je 0x583c19
// 00583c17  8b38                 mov edi, dword ptr [eax]
// 00583c19  8b442420             mov eax, dword ptr [esp + 0x20]
// 00583c1d  85c0                 test eax, eax
// 00583c1f  7402                 je 0x583c23
// 00583c21  8b18                 mov ebx, dword ptr [eax]
// 00583c23  53                   push ebx
// 00583c24  57                   push edi
// 00583c25  56                   push esi
// 00583c26  e8e5fcffff           call 0x583910
// 00583c2b  83c40c               add esp, 0xc
// 00583c2e  85ff                 test edi, edi
// 00583c30  7427                 je 0x583c59
// 00583c32  6aff                 push -1
// 00583c34  6800400000           push 0x4000
// 00583c39  57                   push edi
// 00583c3a  56                   push esi
// 00583c3b  e8d0dcffff           call 0x581910
// 00583c40  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00583c44  51                   push ecx
// 00583c45  55                   push ebp
// 00583c46  57                   push edi
// 00583c47  e824af0000           call 0x58eb70
// 00583c4c  8b542438             mov edx, dword ptr [esp + 0x38]
// 00583c50  83c41c               add esp, 0x1c
// 00583c53  c70200000000         mov dword ptr [edx], 0
// 00583c59  85db                 test ebx, ebx
// 00583c5b  7427                 je 0x583c84
// 00583c5d  6aff                 push -1
// 00583c5f  6800400000           push 0x4000
// 00583c64  53                   push ebx
// 00583c65  56                   push esi
// 00583c66  e8a5dcffff           call 0x581910
// 00583c6b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00583c6f  50                   push eax
// 00583c70  55                   push ebp
// 00583c71  53                   push ebx
// 00583c72  e8f9ae0000           call 0x58eb70
// 00583c77  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00583c7b  83c41c               add esp, 0x1c
// 00583c7e  c70100000000         mov dword ptr [ecx], 0
// 00583c84  8b542410             mov edx, dword ptr [esp + 0x10]
// 00583c88  52                   push edx
// 00583c89  55                   push ebp
// 00583c8a  56                   push esi
// 00583c8b  e8e0ae0000           call 0x58eb70
// 00583c90  8b442424             mov eax, dword ptr [esp + 0x24]
// 00583c94  83c40c               add esp, 0xc
// 00583c97  c70000000000         mov dword ptr [eax], 0
// 00583c9d  5d                   pop ebp
// 00583c9e  5e                   pop esi
// 00583c9f  5f                   pop edi
// 00583ca0  5b                   pop ebx
// 00583ca1  59                   pop ecx
// 00583ca2  c3                   ret 
// library libpng-1.2.29/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngread.c
