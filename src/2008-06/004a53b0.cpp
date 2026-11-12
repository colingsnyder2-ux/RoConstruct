// from server: 100% by auto
// roc 2008-06 004a53b0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a53b0
//
// 004a53b0  8b442404             mov eax, dword ptr [esp + 4]
// 004a53b4  56                   push esi
// 004a53b5  8bf1                 mov esi, ecx
// 004a53b7  85c0                 test eax, eax
// 004a53b9  7e6d                 jle 0x4a5428
// 004a53bb  8b0e                 mov ecx, dword ptr [esi]
// 004a53bd  57                   push edi
// 004a53be  8d3c01               lea edi, [ecx + eax]
// 004a53c1  85ff                 test edi, edi
// 004a53c3  7e5a                 jle 0x4a541f
// 004a53c5  8b5604               mov edx, dword ptr [esi + 4]
// 004a53c8  4a                   dec edx
// 004a53c9  8d47ff               lea eax, [edi - 1]
// 004a53cc  83e2f8               and edx, 0xfffffff8
// 004a53cf  83e0f8               and eax, 0xfffffff8
// 004a53d2  3bd0                 cmp edx, eax
// 004a53d4  7d49                 jge 0x4a541f
// 004a53d6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a53d9  03ff                 add edi, edi
// 004a53db  53                   push ebx
// 004a53dc  8d4707               lea eax, [edi + 7]
// 004a53df  8d5e11               lea ebx, [esi + 0x11]
// 004a53e2  c1f803               sar eax, 3
// 004a53e5  3bcb                 cmp ecx, ebx
// 004a53e7  7527                 jne 0x4a5410
// 004a53e9  3d00010000           cmp eax, 0x100
// 004a53ee  7e2e                 jle 0x4a541e
// 004a53f0  50                   push eax
// 004a53f1  ff15b0288000         call dword ptr [0x8028b0]
// 004a53f7  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a53fa  83c107               add ecx, 7
// 004a53fd  c1f903               sar ecx, 3
// 004a5400  51                   push ecx
// 004a5401  53                   push ebx
// 004a5402  50                   push eax
// 004a5403  89460c               mov dword ptr [esi + 0xc], eax
// 004a5406  e8d5c31f00           call 0x6a17e0
// 004a540b  83c410               add esp, 0x10
// 004a540e  eb0e                 jmp 0x4a541e
// 004a5410  50                   push eax
// 004a5411  51                   push ecx
// 004a5412  ff15e0278000         call dword ptr [0x8027e0]
// 004a5418  83c408               add esp, 8
// 004a541b  89460c               mov dword ptr [esi + 0xc], eax
// 004a541e  5b                   pop ebx
// 004a541f  3b7e04               cmp edi, dword ptr [esi + 4]
// 004a5422  7e03                 jle 0x4a5427
// 004a5424  897e04               mov dword ptr [esi + 4], edi
// 004a5427  5f                   pop edi
// 004a5428  5e                   pop esi
// 004a5429  c20400               ret 4
// library openrbx-raknet/BitStream.cpp (function ?AddBitsAndReallocate@BitStream@RakNet@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
