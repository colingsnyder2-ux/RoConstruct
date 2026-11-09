// from server: 100% by auto
// roc 2009-12 0060cc80  unit: seg_00600000  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060cc80
//
// 0060cc80  51                   push ecx
// 0060cc81  53                   push ebx
// 0060cc82  57                   push edi
// 0060cc83  8bf8                 mov edi, eax
// 0060cc85  8b1f                 mov ebx, dword ptr [edi]
// 0060cc87  85db                 test ebx, ebx
// 0060cc89  742a                 je 0x60ccb5
// 0060cc8b  8b7f04               mov edi, dword ptr [edi + 4]
// 0060cc8e  85f6                 test esi, esi
// 0060cc90  0f84d8000000         je 0x60cd6e
// 0060cc96  85ff                 test edi, edi
// 0060cc98  0f86d0000000         jbe 0x60cd6e
// 0060cc9e  57                   push edi
// 0060cc9f  53                   push ebx
// 0060cca0  56                   push esi
// 0060cca1  e8ea66ffff           call 0x603390
// 0060cca6  57                   push edi
// 0060cca7  53                   push ebx
// 0060cca8  56                   push esi
// 0060cca9  e8c269ffff           call 0x603670
// 0060ccae  83c418               add esp, 0x18
// 0060ccb1  5f                   pop edi
// 0060ccb2  5b                   pop ebx
// 0060ccb3  59                   pop ecx
// 0060ccb4  c3                   ret 
// 0060ccb5  33db                 xor ebx, ebx
// 0060ccb7  395f08               cmp dword ptr [edi + 8], ebx
// 0060ccba  55                   push ebp
// 0060ccbb  7e52                 jle 0x60cd0f
// 0060ccbd  8d4900               lea ecx, [ecx]
// 0060ccc0  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0060ccc3  8b2c99               mov ebp, dword ptr [ecx + ebx*4]
// 0060ccc6  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0060cccc  8944240c             mov dword ptr [esp + 0xc], eax
// 0060ccd0  85ed                 test ebp, ebp
// 0060ccd2  741b                 je 0x60ccef
// 0060ccd4  85c0                 test eax, eax
// 0060ccd6  7617                 jbe 0x60ccef
// 0060ccd8  50                   push eax
// 0060ccd9  55                   push ebp
// 0060ccda  56                   push esi
// 0060ccdb  e8b066ffff           call 0x603390
// 0060cce0  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060cce4  52                   push edx
// 0060cce5  55                   push ebp
// 0060cce6  56                   push esi
// 0060cce7  e88469ffff           call 0x603670
// 0060ccec  83c418               add esp, 0x18
// 0060ccef  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060ccf2  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 0060ccf5  51                   push ecx
// 0060ccf6  56                   push esi
// 0060ccf7  e8e43f0000           call 0x610ce0
// 0060ccfc  8b5710               mov edx, dword ptr [edi + 0x10]
// 0060ccff  c7049a00000000       mov dword ptr [edx + ebx*4], 0
// 0060cd06  43                   inc ebx
// 0060cd07  83c408               add esp, 8
// 0060cd0a  3b5f08               cmp ebx, dword ptr [edi + 8]
// 0060cd0d  7cb1                 jl 0x60ccc0
// 0060cd0f  33ed                 xor ebp, ebp
// 0060cd11  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0060cd14  740d                 je 0x60cd23
// 0060cd16  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060cd19  50                   push eax
// 0060cd1a  56                   push esi
// 0060cd1b  e8c03f0000           call 0x610ce0
// 0060cd20  83c408               add esp, 8
// 0060cd23  896f10               mov dword ptr [edi + 0x10], ebp
// 0060cd26  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0060cd2c  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0060cd32  3bc8                 cmp ecx, eax
// 0060cd34  7325                 jae 0x60cd5b
// 0060cd36  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0060cd3c  2bc1                 sub eax, ecx
// 0060cd3e  8bd8                 mov ebx, eax
// 0060cd40  3bfd                 cmp edi, ebp
// 0060cd42  7417                 je 0x60cd5b
// 0060cd44  3bdd                 cmp ebx, ebp
// 0060cd46  7613                 jbe 0x60cd5b
// 0060cd48  53                   push ebx
// 0060cd49  57                   push edi
// 0060cd4a  56                   push esi
// 0060cd4b  e84066ffff           call 0x603390
// 0060cd50  53                   push ebx
// 0060cd51  57                   push edi
// 0060cd52  56                   push esi
// 0060cd53  e81869ffff           call 0x603670
// 0060cd58  83c418               add esp, 0x18
// 0060cd5b  8d4e74               lea ecx, [esi + 0x74]
// 0060cd5e  51                   push ecx
// 0060cd5f  e8ac560000           call 0x612410
// 0060cd64  83c404               add esp, 4
// 0060cd67  89aea0000000         mov dword ptr [esi + 0xa0], ebp
// 0060cd6d  5d                   pop ebp
// 0060cd6e  5f                   pop edi
// 0060cd6f  5b                   pop ebx
// 0060cd70  59                   pop ecx
// 0060cd71  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_compressed_data_out)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
