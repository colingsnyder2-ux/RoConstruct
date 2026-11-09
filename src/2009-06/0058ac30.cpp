// from server: 100% by auto
// roc 2009-06 0058ac30  unit: seg_00580000  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ac30
//
// 0058ac30  51                   push ecx
// 0058ac31  53                   push ebx
// 0058ac32  57                   push edi
// 0058ac33  8bf8                 mov edi, eax
// 0058ac35  8b1f                 mov ebx, dword ptr [edi]
// 0058ac37  85db                 test ebx, ebx
// 0058ac39  742a                 je 0x58ac65
// 0058ac3b  8b7f04               mov edi, dword ptr [edi + 4]
// 0058ac3e  85f6                 test esi, esi
// 0058ac40  0f84d8000000         je 0x58ad1e
// 0058ac46  85ff                 test edi, edi
// 0058ac48  0f86d0000000         jbe 0x58ad1e
// 0058ac4e  57                   push edi
// 0058ac4f  53                   push ebx
// 0058ac50  56                   push esi
// 0058ac51  e88a69ffff           call 0x5815e0
// 0058ac56  57                   push edi
// 0058ac57  53                   push ebx
// 0058ac58  56                   push esi
// 0058ac59  e8626cffff           call 0x5818c0
// 0058ac5e  83c418               add esp, 0x18
// 0058ac61  5f                   pop edi
// 0058ac62  5b                   pop ebx
// 0058ac63  59                   pop ecx
// 0058ac64  c3                   ret 
// 0058ac65  33db                 xor ebx, ebx
// 0058ac67  395f08               cmp dword ptr [edi + 8], ebx
// 0058ac6a  55                   push ebp
// 0058ac6b  7e52                 jle 0x58acbf
// 0058ac6d  8d4900               lea ecx, [ecx]
// 0058ac70  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0058ac73  8b2c99               mov ebp, dword ptr [ecx + ebx*4]
// 0058ac76  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0058ac7c  8944240c             mov dword ptr [esp + 0xc], eax
// 0058ac80  85ed                 test ebp, ebp
// 0058ac82  741b                 je 0x58ac9f
// 0058ac84  85c0                 test eax, eax
// 0058ac86  7617                 jbe 0x58ac9f
// 0058ac88  50                   push eax
// 0058ac89  55                   push ebp
// 0058ac8a  56                   push esi
// 0058ac8b  e85069ffff           call 0x5815e0
// 0058ac90  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058ac94  52                   push edx
// 0058ac95  55                   push ebp
// 0058ac96  56                   push esi
// 0058ac97  e8246cffff           call 0x5818c0
// 0058ac9c  83c418               add esp, 0x18
// 0058ac9f  8b4710               mov eax, dword ptr [edi + 0x10]
// 0058aca2  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 0058aca5  51                   push ecx
// 0058aca6  56                   push esi
// 0058aca7  e804400000           call 0x58ecb0
// 0058acac  8b5710               mov edx, dword ptr [edi + 0x10]
// 0058acaf  c7049a00000000       mov dword ptr [edx + ebx*4], 0
// 0058acb6  43                   inc ebx
// 0058acb7  83c408               add esp, 8
// 0058acba  3b5f08               cmp ebx, dword ptr [edi + 8]
// 0058acbd  7cb1                 jl 0x58ac70
// 0058acbf  33ed                 xor ebp, ebp
// 0058acc1  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0058acc4  740d                 je 0x58acd3
// 0058acc6  8b4710               mov eax, dword ptr [edi + 0x10]
// 0058acc9  50                   push eax
// 0058acca  56                   push esi
// 0058accb  e8e03f0000           call 0x58ecb0
// 0058acd0  83c408               add esp, 8
// 0058acd3  896f10               mov dword ptr [edi + 0x10], ebp
// 0058acd6  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0058acdc  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0058ace2  3bc8                 cmp ecx, eax
// 0058ace4  7325                 jae 0x58ad0b
// 0058ace6  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0058acec  2bc1                 sub eax, ecx
// 0058acee  8bd8                 mov ebx, eax
// 0058acf0  3bfd                 cmp edi, ebp
// 0058acf2  7417                 je 0x58ad0b
// 0058acf4  3bdd                 cmp ebx, ebp
// 0058acf6  7613                 jbe 0x58ad0b
// 0058acf8  53                   push ebx
// 0058acf9  57                   push edi
// 0058acfa  56                   push esi
// 0058acfb  e8e068ffff           call 0x5815e0
// 0058ad00  53                   push ebx
// 0058ad01  57                   push edi
// 0058ad02  56                   push esi
// 0058ad03  e8b86bffff           call 0x5818c0
// 0058ad08  83c418               add esp, 0x18
// 0058ad0b  8d4e74               lea ecx, [esi + 0x74]
// 0058ad0e  51                   push ecx
// 0058ad0f  e8dc560000           call 0x5903f0
// 0058ad14  83c404               add esp, 4
// 0058ad17  89aea0000000         mov dword ptr [esi + 0xa0], ebp
// 0058ad1d  5d                   pop ebp
// 0058ad1e  5f                   pop edi
// 0058ad1f  5b                   pop ebx
// 0058ad20  59                   pop ecx
// 0058ad21  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_compressed_data_out)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
