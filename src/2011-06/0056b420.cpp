// from server: 100% by auto
// roc 2011-06 0056b420  unit: seg_00560000  size: 678 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056b420
//
// 0056b420  83ec28               sub esp, 0x28
// 0056b423  837c243c04           cmp dword ptr [esp + 0x3c], 4
// 0056b428  56                   push esi
// 0056b429  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056b42d  c644241870           mov byte ptr [esp + 0x18], 0x70
// 0056b432  c644241943           mov byte ptr [esp + 0x19], 0x43
// 0056b437  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0056b43c  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0056b441  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0056b446  7c0e                 jl 0x56b456
// 0056b448  68a05ca800           push 0xa85ca0
// 0056b44d  56                   push esi
// 0056b44e  e88d5fffff           call 0x5613e0
// 0056b453  83c408               add esp, 8
// 0056b456  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0056b45a  53                   push ebx
// 0056b45b  55                   push ebp
// 0056b45c  57                   push edi
// 0056b45d  8d442410             lea eax, [esp + 0x10]
// 0056b461  50                   push eax
// 0056b462  51                   push ecx
// 0056b463  56                   push esi
// 0056b464  e897fbffff           call 0x56b000
// 0056b469  8be8                 mov ebp, eax
// 0056b46b  8b442460             mov eax, dword ptr [esp + 0x60]
// 0056b46f  83c40c               add esp, 0xc
// 0056b472  45                   inc ebp
// 0056b473  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056b477  8d4801               lea ecx, [eax + 1]
// 0056b47a  8d9b00000000         lea ebx, [ebx]
// 0056b480  8a10                 mov dl, byte ptr [eax]
// 0056b482  40                   inc eax
// 0056b483  84d2                 test dl, dl
// 0056b485  75f9                 jne 0x56b480
// 0056b487  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0056b48b  2bc1                 sub eax, ecx
// 0056b48d  33d2                 xor edx, edx
// 0056b48f  85db                 test ebx, ebx
// 0056b491  0f95c2               setne dl
// 0056b494  8d0c9d00000000       lea ecx, [ebx*4]
// 0056b49b  51                   push ecx
// 0056b49c  56                   push esi
// 0056b49d  03d0                 add edx, eax
// 0056b49f  8bfa                 mov edi, edx
// 0056b4a1  8d442f0a             lea eax, [edi + ebp + 0xa]
// 0056b4a5  897c2424             mov dword ptr [esp + 0x24], edi
// 0056b4a9  89442444             mov dword ptr [esp + 0x44], eax
// 0056b4ad  e88e61ffff           call 0x561640
// 0056b4b2  83c408               add esp, 8
// 0056b4b5  33c9                 xor ecx, ecx
// 0056b4b7  89442450             mov dword ptr [esp + 0x50], eax
// 0056b4bb  85db                 test ebx, ebx
// 0056b4bd  7e50                 jle 0x56b50f
// 0056b4bf  8b542458             mov edx, dword ptr [esp + 0x58]
// 0056b4c3  2bd0                 sub edx, eax
// 0056b4c5  8bf8                 mov edi, eax
// 0056b4c7  89542414             mov dword ptr [esp + 0x14], edx
// 0056b4cb  eb07                 jmp 0x56b4d4
// 0056b4cd  8d4900               lea ecx, [ecx]
// 0056b4d0  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056b4d4  8b043a               mov eax, dword ptr [edx + edi]
// 0056b4d7  8d6801               lea ebp, [eax + 1]
// 0056b4da  8d9b00000000         lea ebx, [ebx]
// 0056b4e0  8a10                 mov dl, byte ptr [eax]
// 0056b4e2  40                   inc eax
// 0056b4e3  84d2                 test dl, dl
// 0056b4e5  75f9                 jne 0x56b4e0
// 0056b4e7  2bc5                 sub eax, ebp
// 0056b4e9  8be8                 mov ebp, eax
// 0056b4eb  33d2                 xor edx, edx
// 0056b4ed  8d43ff               lea eax, [ebx - 1]
// 0056b4f0  3bc8                 cmp ecx, eax
// 0056b4f2  0f95c2               setne dl
// 0056b4f5  41                   inc ecx
// 0056b4f6  83c704               add edi, 4
// 0056b4f9  8d042a               lea eax, [edx + ebp]
// 0056b4fc  0144243c             add dword ptr [esp + 0x3c], eax
// 0056b500  3bcb                 cmp ecx, ebx
// 0056b502  8947fc               mov dword ptr [edi - 4], eax
// 0056b505  7cc9                 jl 0x56b4d0
// 0056b507  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056b50b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056b50f  85f6                 test esi, esi
// 0056b511  747b                 je 0x56b58e
// 0056b513  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0056b517  8bc8                 mov ecx, eax
// 0056b519  c1e918               shr ecx, 0x18
// 0056b51c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056b520  8bd0                 mov edx, eax
// 0056b522  8bc8                 mov ecx, eax
// 0056b524  c1ea10               shr edx, 0x10
// 0056b527  8844241f             mov byte ptr [esp + 0x1f], al
// 0056b52b  6a08                 push 8
// 0056b52d  8d442420             lea eax, [esp + 0x20]
// 0056b531  88542421             mov byte ptr [esp + 0x21], dl
// 0056b535  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056b539  50                   push eax
// 0056b53a  c1e908               shr ecx, 8
// 0056b53d  56                   push esi
// 0056b53e  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056b542  8954242c             mov dword ptr [esp + 0x2c], edx
// 0056b546  e8f5f2feff           call 0x55a840
// 0056b54b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056b54f  56                   push esi
// 0056b550  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0056b556  e8d552feff           call 0x550830
// 0056b55b  6a04                 push 4
// 0056b55d  8d542438             lea edx, [esp + 0x38]
// 0056b561  52                   push edx
// 0056b562  56                   push esi
// 0056b563  e8e852feff           call 0x550850
// 0056b568  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0056b56c  83c41c               add esp, 0x1c
// 0056b56f  85c0                 test eax, eax
// 0056b571  741b                 je 0x56b58e
// 0056b573  85ed                 test ebp, ebp
// 0056b575  7617                 jbe 0x56b58e
// 0056b577  55                   push ebp
// 0056b578  50                   push eax
// 0056b579  56                   push esi
// 0056b57a  e8c1f2feff           call 0x55a840
// 0056b57f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056b583  55                   push ebp
// 0056b584  50                   push eax
// 0056b585  56                   push esi
// 0056b586  e8c552feff           call 0x550850
// 0056b58b  83c418               add esp, 0x18
// 0056b58e  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056b592  8bc8                 mov ecx, eax
// 0056b594  c1f918               sar ecx, 0x18
// 0056b597  884c242c             mov byte ptr [esp + 0x2c], cl
// 0056b59b  8bd0                 mov edx, eax
// 0056b59d  c1fa10               sar edx, 0x10
// 0056b5a0  8bc8                 mov ecx, eax
// 0056b5a2  8854242d             mov byte ptr [esp + 0x2d], dl
// 0056b5a6  8844242f             mov byte ptr [esp + 0x2f], al
// 0056b5aa  8b442448             mov eax, dword ptr [esp + 0x48]
// 0056b5ae  c1f908               sar ecx, 8
// 0056b5b1  8bd0                 mov edx, eax
// 0056b5b3  c1fa18               sar edx, 0x18
// 0056b5b6  884c242e             mov byte ptr [esp + 0x2e], cl
// 0056b5ba  88542430             mov byte ptr [esp + 0x30], dl
// 0056b5be  8bc8                 mov ecx, eax
// 0056b5c0  8bd0                 mov edx, eax
// 0056b5c2  c1f910               sar ecx, 0x10
// 0056b5c5  c1fa08               sar edx, 8
// 0056b5c8  88442433             mov byte ptr [esp + 0x33], al
// 0056b5cc  8a44244c             mov al, byte ptr [esp + 0x4c]
// 0056b5d0  884c2431             mov byte ptr [esp + 0x31], cl
// 0056b5d4  88542432             mov byte ptr [esp + 0x32], dl
// 0056b5d8  88442434             mov byte ptr [esp + 0x34], al
// 0056b5dc  885c2435             mov byte ptr [esp + 0x35], bl
// 0056b5e0  85f6                 test esi, esi
// 0056b5e2  743c                 je 0x56b620
// 0056b5e4  6a0a                 push 0xa
// 0056b5e6  8d4c2430             lea ecx, [esp + 0x30]
// 0056b5ea  51                   push ecx
// 0056b5eb  56                   push esi
// 0056b5ec  e84ff2feff           call 0x55a840
// 0056b5f1  6a0a                 push 0xa
// 0056b5f3  8d54243c             lea edx, [esp + 0x3c]
// 0056b5f7  52                   push edx
// 0056b5f8  56                   push esi
// 0056b5f9  e85252feff           call 0x550850
// 0056b5fe  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 0056b602  83c418               add esp, 0x18
// 0056b605  85ed                 test ebp, ebp
// 0056b607  7417                 je 0x56b620
// 0056b609  85ff                 test edi, edi
// 0056b60b  7613                 jbe 0x56b620
// 0056b60d  57                   push edi
// 0056b60e  55                   push ebp
// 0056b60f  56                   push esi
// 0056b610  e82bf2feff           call 0x55a840
// 0056b615  57                   push edi
// 0056b616  55                   push ebp
// 0056b617  56                   push esi
// 0056b618  e83352feff           call 0x550850
// 0056b61d  83c418               add esp, 0x18
// 0056b620  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056b624  50                   push eax
// 0056b625  56                   push esi
// 0056b626  e87560ffff           call 0x5616a0
// 0056b62b  83c408               add esp, 8
// 0056b62e  85db                 test ebx, ebx
// 0056b630  7e45                 jle 0x56b677
// 0056b632  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0056b636  8b442450             mov eax, dword ptr [esp + 0x50]
// 0056b63a  2bc5                 sub eax, ebp
// 0056b63c  8944243c             mov dword ptr [esp + 0x3c], eax
// 0056b640  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0056b644  8b1c28               mov ebx, dword ptr [eax + ebp]
// 0056b647  8b7d00               mov edi, dword ptr [ebp]
// 0056b64a  85f6                 test esi, esi
// 0056b64c  741f                 je 0x56b66d
// 0056b64e  85ff                 test edi, edi
// 0056b650  741b                 je 0x56b66d
// 0056b652  85db                 test ebx, ebx
// 0056b654  7617                 jbe 0x56b66d
// 0056b656  53                   push ebx
// 0056b657  57                   push edi
// 0056b658  56                   push esi
// 0056b659  e8e2f1feff           call 0x55a840
// 0056b65e  53                   push ebx
// 0056b65f  57                   push edi
// 0056b660  56                   push esi
// 0056b661  e8ea51feff           call 0x550850
// 0056b666  8b442454             mov eax, dword ptr [esp + 0x54]
// 0056b66a  83c418               add esp, 0x18
// 0056b66d  83c504               add ebp, 4
// 0056b670  836c244c01           sub dword ptr [esp + 0x4c], 1
// 0056b675  75cd                 jne 0x56b644
// 0056b677  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0056b67b  51                   push ecx
// 0056b67c  56                   push esi
// 0056b67d  e81e60ffff           call 0x5616a0
// 0056b682  83c408               add esp, 8
// 0056b685  5f                   pop edi
// 0056b686  5d                   pop ebp
// 0056b687  5b                   pop ebx
// 0056b688  85f6                 test esi, esi
// 0056b68a  7435                 je 0x56b6c1
// 0056b68c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056b692  8bd0                 mov edx, eax
// 0056b694  c1ea18               shr edx, 0x18
// 0056b697  88542440             mov byte ptr [esp + 0x40], dl
// 0056b69b  8bc8                 mov ecx, eax
// 0056b69d  8bd0                 mov edx, eax
// 0056b69f  88442443             mov byte ptr [esp + 0x43], al
// 0056b6a3  6a04                 push 4
// 0056b6a5  8d442444             lea eax, [esp + 0x44]
// 0056b6a9  50                   push eax
// 0056b6aa  c1e910               shr ecx, 0x10
// 0056b6ad  c1ea08               shr edx, 8
// 0056b6b0  56                   push esi
// 0056b6b1  884c244d             mov byte ptr [esp + 0x4d], cl
// 0056b6b5  8854244e             mov byte ptr [esp + 0x4e], dl
// 0056b6b9  e882f1feff           call 0x55a840
// 0056b6be  83c40c               add esp, 0xc
// 0056b6c1  5e                   pop esi
// 0056b6c2  83c428               add esp, 0x28
// 0056b6c5  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
