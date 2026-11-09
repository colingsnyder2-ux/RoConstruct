// from server: 100% by auto
// roc 2010-06 0056e5a0  unit: G3D::LineSegment  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e5a0
//
// 0056e5a0  51                   push ecx
// 0056e5a1  53                   push ebx
// 0056e5a2  57                   push edi
// 0056e5a3  8bf8                 mov edi, eax
// 0056e5a5  8b1f                 mov ebx, dword ptr [edi]
// 0056e5a7  85db                 test ebx, ebx
// 0056e5a9  742a                 je 0x56e5d5
// 0056e5ab  8b7f04               mov edi, dword ptr [edi + 4]
// 0056e5ae  85f6                 test esi, esi
// 0056e5b0  0f84d8000000         je 0x56e68e
// 0056e5b6  85ff                 test edi, edi
// 0056e5b8  0f86d0000000         jbe 0x56e68e
// 0056e5be  57                   push edi
// 0056e5bf  53                   push ebx
// 0056e5c0  56                   push esi
// 0056e5c1  e83a67ffff           call 0x564d00
// 0056e5c6  57                   push edi
// 0056e5c7  53                   push ebx
// 0056e5c8  56                   push esi
// 0056e5c9  e8126affff           call 0x564fe0
// 0056e5ce  83c418               add esp, 0x18
// 0056e5d1  5f                   pop edi
// 0056e5d2  5b                   pop ebx
// 0056e5d3  59                   pop ecx
// 0056e5d4  c3                   ret 
// 0056e5d5  33db                 xor ebx, ebx
// 0056e5d7  395f08               cmp dword ptr [edi + 8], ebx
// 0056e5da  55                   push ebp
// 0056e5db  7e52                 jle 0x56e62f
// 0056e5dd  8d4900               lea ecx, [ecx]
// 0056e5e0  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0056e5e3  8b2c99               mov ebp, dword ptr [ecx + ebx*4]
// 0056e5e6  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0056e5ec  8944240c             mov dword ptr [esp + 0xc], eax
// 0056e5f0  85ed                 test ebp, ebp
// 0056e5f2  741b                 je 0x56e60f
// 0056e5f4  85c0                 test eax, eax
// 0056e5f6  7617                 jbe 0x56e60f
// 0056e5f8  50                   push eax
// 0056e5f9  55                   push ebp
// 0056e5fa  56                   push esi
// 0056e5fb  e80067ffff           call 0x564d00
// 0056e600  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056e604  52                   push edx
// 0056e605  55                   push ebp
// 0056e606  56                   push esi
// 0056e607  e8d469ffff           call 0x564fe0
// 0056e60c  83c418               add esp, 0x18
// 0056e60f  8b4710               mov eax, dword ptr [edi + 0x10]
// 0056e612  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 0056e615  51                   push ecx
// 0056e616  56                   push esi
// 0056e617  e8e43f0000           call 0x572600
// 0056e61c  8b5710               mov edx, dword ptr [edi + 0x10]
// 0056e61f  c7049a00000000       mov dword ptr [edx + ebx*4], 0
// 0056e626  43                   inc ebx
// 0056e627  83c408               add esp, 8
// 0056e62a  3b5f08               cmp ebx, dword ptr [edi + 8]
// 0056e62d  7cb1                 jl 0x56e5e0
// 0056e62f  33ed                 xor ebp, ebp
// 0056e631  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0056e634  740d                 je 0x56e643
// 0056e636  8b4710               mov eax, dword ptr [edi + 0x10]
// 0056e639  50                   push eax
// 0056e63a  56                   push esi
// 0056e63b  e8c03f0000           call 0x572600
// 0056e640  83c408               add esp, 8
// 0056e643  896f10               mov dword ptr [edi + 0x10], ebp
// 0056e646  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0056e64c  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0056e652  3bc8                 cmp ecx, eax
// 0056e654  7325                 jae 0x56e67b
// 0056e656  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0056e65c  2bc1                 sub eax, ecx
// 0056e65e  8bd8                 mov ebx, eax
// 0056e660  3bfd                 cmp edi, ebp
// 0056e662  7417                 je 0x56e67b
// 0056e664  3bdd                 cmp ebx, ebp
// 0056e666  7613                 jbe 0x56e67b
// 0056e668  53                   push ebx
// 0056e669  57                   push edi
// 0056e66a  56                   push esi
// 0056e66b  e89066ffff           call 0x564d00
// 0056e670  53                   push ebx
// 0056e671  57                   push edi
// 0056e672  56                   push esi
// 0056e673  e86869ffff           call 0x564fe0
// 0056e678  83c418               add esp, 0x18
// 0056e67b  8d4e74               lea ecx, [esi + 0x74]
// 0056e67e  51                   push ecx
// 0056e67f  e8ac560000           call 0x573d30
// 0056e684  83c404               add esp, 4
// 0056e687  89aea0000000         mov dword ptr [esi + 0xa0], ebp
// 0056e68d  5d                   pop ebp
// 0056e68e  5f                   pop edi
// 0056e68f  5b                   pop ebx
// 0056e690  59                   pop ecx
// 0056e691  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_compressed_data_out)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
