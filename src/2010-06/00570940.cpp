// from server: 100% by auto
// roc 2010-06 00570940  unit: G3D::LineSegment  size: 609 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00570940
//
// 00570940  83ec70               sub esp, 0x70
// 00570943  53                   push ebx
// 00570944  55                   push ebp
// 00570945  bb01000000           mov ebx, 1
// 0057094a  56                   push esi
// 0057094b  8bb42480000000       mov esi, dword ptr [esp + 0x80]
// 00570952  019ee4000000         add dword ptr [esi + 0xe4], ebx
// 00570958  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 0057095e  bd04000000           mov ebp, 4
// 00570963  b802000000           mov eax, 2
// 00570968  ba08000000           mov edx, 8
// 0057096d  57                   push edi
// 0057096e  33ff                 xor edi, edi
// 00570970  897c242c             mov dword ptr [esp + 0x2c], edi
// 00570974  896c2430             mov dword ptr [esp + 0x30], ebp
// 00570978  897c2434             mov dword ptr [esp + 0x34], edi
// 0057097c  89442438             mov dword ptr [esp + 0x38], eax
// 00570980  897c243c             mov dword ptr [esp + 0x3c], edi
// 00570984  895c2440             mov dword ptr [esp + 0x40], ebx
// 00570988  897c2444             mov dword ptr [esp + 0x44], edi
// 0057098c  89542410             mov dword ptr [esp + 0x10], edx
// 00570990  89542414             mov dword ptr [esp + 0x14], edx
// 00570994  896c2418             mov dword ptr [esp + 0x18], ebp
// 00570998  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0057099c  89442420             mov dword ptr [esp + 0x20], eax
// 005709a0  89442424             mov dword ptr [esp + 0x24], eax
// 005709a4  895c2428             mov dword ptr [esp + 0x28], ebx
// 005709a8  897c2464             mov dword ptr [esp + 0x64], edi
// 005709ac  897c2468             mov dword ptr [esp + 0x68], edi
// 005709b0  896c246c             mov dword ptr [esp + 0x6c], ebp
// 005709b4  897c2470             mov dword ptr [esp + 0x70], edi
// 005709b8  89442474             mov dword ptr [esp + 0x74], eax
// 005709bc  897c2478             mov dword ptr [esp + 0x78], edi
// 005709c0  895c247c             mov dword ptr [esp + 0x7c], ebx
// 005709c4  89542448             mov dword ptr [esp + 0x48], edx
// 005709c8  8954244c             mov dword ptr [esp + 0x4c], edx
// 005709cc  89542450             mov dword ptr [esp + 0x50], edx
// 005709d0  896c2454             mov dword ptr [esp + 0x54], ebp
// 005709d4  896c2458             mov dword ptr [esp + 0x58], ebp
// 005709d8  8944245c             mov dword ptr [esp + 0x5c], eax
// 005709dc  89442460             mov dword ptr [esp + 0x60], eax
// 005709e0  3b8ed0000000         cmp ecx, dword ptr [esi + 0xd0]
// 005709e6  0f82ad010000         jb 0x570b99
// 005709ec  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 005709f3  0f84f7000000         je 0x570af0
// 005709f9  89bee4000000         mov dword ptr [esi + 0xe4], edi
// 005709ff  844670               test byte ptr [esi + 0x70], al
// 00570a02  7413                 je 0x570a17
// 00570a04  fe8624010000         inc byte ptr [esi + 0x124]
// 00570a0a  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 00570a10  eb6b                 jmp 0x570a7d
// 00570a12  33ff                 xor edi, edi
// 00570a14  8d6f04               lea ebp, [edi + 4]
// 00570a17  fe8624010000         inc byte ptr [esi + 0x124]
// 00570a1d  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 00570a23  80fb07               cmp bl, 7
// 00570a26  0f83bc000000         jae 0x570ae8
// 00570a2c  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00570a32  0fb6cb               movzx ecx, bl
// 00570a35  03c9                 add ecx, ecx
// 00570a37  03c9                 add ecx, ecx
// 00570a39  2b440c2c             sub eax, dword ptr [esp + ecx + 0x2c]
// 00570a3d  8b7c0c10             mov edi, dword ptr [esp + ecx + 0x10]
// 00570a41  33d2                 xor edx, edx
// 00570a43  8d4438ff             lea eax, [eax + edi - 1]
// 00570a47  f7f7                 div edi
// 00570a49  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 00570a4f  2b540c64             sub edx, dword ptr [esp + ecx + 0x64]
// 00570a53  8b6c0c48             mov ebp, dword ptr [esp + ecx + 0x48]
// 00570a57  8bf8                 mov edi, eax
// 00570a59  8d442aff             lea eax, [edx + ebp - 1]
// 00570a5d  33d2                 xor edx, edx
// 00570a5f  f7f5                 div ebp
// 00570a61  89bed4000000         mov dword ptr [esi + 0xd4], edi
// 00570a67  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00570a6d  85ff                 test edi, edi
// 00570a6f  74a1                 je 0x570a12
// 00570a71  85c0                 test eax, eax
// 00570a73  749d                 je 0x570a12
// 00570a75  33ff                 xor edi, edi
// 00570a77  8d5708               lea edx, [edi + 8]
// 00570a7a  8d6f04               lea ebp, [edi + 4]
// 00570a7d  80fb07               cmp bl, 7
// 00570a80  7366                 jae 0x570ae8
// 00570a82  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 00570a88  3bcf                 cmp ecx, edi
// 00570a8a  0f8409010000         je 0x570b99
// 00570a90  0fb6862b010000       movzx eax, byte ptr [esi + 0x12b]
// 00570a97  0fb69e28010000       movzx ebx, byte ptr [esi + 0x128]
// 00570a9e  0fafc3               imul eax, ebx
// 00570aa1  3bc2                 cmp eax, edx
// 00570aa3  7c20                 jl 0x570ac5
// 00570aa5  c1e803               shr eax, 3
// 00570aa8  0faf86c8000000       imul eax, dword ptr [esi + 0xc8]
// 00570aaf  8bf0                 mov esi, eax
// 00570ab1  46                   inc esi
// 00570ab2  56                   push esi
// 00570ab3  57                   push edi
// 00570ab4  51                   push ecx
// 00570ab5  e82a812300           call 0x7a8be4
// 00570aba  83c40c               add esp, 0xc
// 00570abd  5f                   pop edi
// 00570abe  5e                   pop esi
// 00570abf  5d                   pop ebp
// 00570ac0  5b                   pop ebx
// 00570ac1  83c470               add esp, 0x70
// 00570ac4  c3                   ret 
// 00570ac5  8bb6c8000000         mov esi, dword ptr [esi + 0xc8]
// 00570acb  0faff0               imul esi, eax
// 00570ace  83c607               add esi, 7
// 00570ad1  c1ee03               shr esi, 3
// 00570ad4  46                   inc esi
// 00570ad5  56                   push esi
// 00570ad6  57                   push edi
// 00570ad7  51                   push ecx
// 00570ad8  e807812300           call 0x7a8be4
// 00570add  83c40c               add esp, 0xc
// 00570ae0  5f                   pop edi
// 00570ae1  5e                   pop esi
// 00570ae2  5d                   pop ebp
// 00570ae3  5b                   pop ebx
// 00570ae4  83c470               add esp, 0x70
// 00570ae7  c3                   ret 
// 00570ae8  bb01000000           mov ebx, 1
// 00570aed  8d4900               lea ecx, [ecx]
// 00570af0  8d4674               lea eax, [esi + 0x74]
// 00570af3  55                   push ebp
// 00570af4  50                   push eax
// 00570af5  e8e61b0000           call 0x5726e0
// 00570afa  83c408               add esp, 8
// 00570afd  3bc7                 cmp eax, edi
// 00570aff  7539                 jne 0x570b3a
// 00570b01  39be84000000         cmp dword ptr [esi + 0x84], edi
// 00570b07  75e7                 jne 0x570af0
// 00570b09  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00570b0f  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 00570b15  50                   push eax
// 00570b16  51                   push ecx
// 00570b17  56                   push esi
// 00570b18  e843edffff           call 0x56f860
// 00570b1d  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00570b23  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00570b29  83c40c               add esp, 0xc
// 00570b2c  899680000000         mov dword ptr [esi + 0x80], edx
// 00570b32  898684000000         mov dword ptr [esi + 0x84], eax
// 00570b38  ebb6                 jmp 0x570af0
// 00570b3a  3bc3                 cmp eax, ebx
// 00570b3c  7426                 je 0x570b64
// 00570b3e  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00570b44  3bc7                 cmp eax, edi
// 00570b46  740c                 je 0x570b54
// 00570b48  50                   push eax
// 00570b49  56                   push esi
// 00570b4a  e8610f0000           call 0x571ab0
// 00570b4f  83c408               add esp, 8
// 00570b52  eb9c                 jmp 0x570af0
// 00570b54  68140fa200           push 0xa20f14
// 00570b59  56                   push esi
// 00570b5a  e8510f0000           call 0x571ab0
// 00570b5f  83c408               add esp, 8
// 00570b62  eb8c                 jmp 0x570af0
// 00570b64  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 00570b6a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00570b70  3bc8                 cmp ecx, eax
// 00570b72  7313                 jae 0x570b87
// 00570b74  2bc1                 sub eax, ecx
// 00570b76  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 00570b7c  50                   push eax
// 00570b7d  51                   push ecx
// 00570b7e  56                   push esi
// 00570b7f  e8dcecffff           call 0x56f860
// 00570b84  83c40c               add esp, 0xc
// 00570b87  8d4674               lea eax, [esi + 0x74]
// 00570b8a  50                   push eax
// 00570b8b  e8a0310000           call 0x573d30
// 00570b90  83c404               add esp, 4
// 00570b93  89bea0000000         mov dword ptr [esi + 0xa0], edi
// 00570b99  5f                   pop edi
// 00570b9a  5e                   pop esi
// 00570b9b  5d                   pop ebp
// 00570b9c  5b                   pop ebx
// 00570b9d  83c470               add esp, 0x70
// 00570ba0  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
