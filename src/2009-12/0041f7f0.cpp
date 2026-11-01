// from server: 100% by auto
// roc 2009-12 0041f7f0  unit: RBX::Reflection::$$A6AXPBVPropertyDescriptor::?$signal::slot  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041f7f0
//
// 0041f7f0  56                   push esi
// 0041f7f1  57                   push edi
// 0041f7f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041f7f6  8bf1                 mov esi, ecx
// 0041f7f8  3bf7                 cmp esi, edi
// 0041f7fa  0f84f4000000         je 0x41f8f4
// 0041f800  53                   push ebx
// 0041f801  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 0041f804  55                   push ebp
// 0041f805  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 0041f808  8bcb                 mov ecx, ebx
// 0041f80a  2bcd                 sub ecx, ebp
// 0041f80c  c1f903               sar ecx, 3
// 0041f80f  85c9                 test ecx, ecx
// 0041f811  7510                 jne 0x41f823
// 0041f813  8bce                 mov ecx, esi
// 0041f815  e816feffff           call 0x41f630
// 0041f81a  5d                   pop ebp
// 0041f81b  5b                   pop ebx
// 0041f81c  5f                   pop edi
// 0041f81d  8bc6                 mov eax, esi
// 0041f81f  5e                   pop esi
// 0041f820  c20400               ret 4
// 0041f823  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041f826  8b460c               mov eax, dword ptr [esi + 0xc]
// 0041f829  2bd0                 sub edx, eax
// 0041f82b  c1fa03               sar edx, 3
// 0041f82e  3bca                 cmp ecx, edx
// 0041f830  7739                 ja 0x41f86b
// 0041f832  50                   push eax
// 0041f833  53                   push ebx
// 0041f834  55                   push ebp
// 0041f835  e8c607ffff           call 0x410000
// 0041f83a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0041f83e  51                   push ecx
// 0041f83f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041f842  8d5608               lea edx, [esi + 8]
// 0041f845  52                   push edx
// 0041f846  51                   push ecx
// 0041f847  50                   push eax
// 0041f848  e8533e0a00           call 0x4c36a0
// 0041f84d  8b5710               mov edx, dword ptr [edi + 0x10]
// 0041f850  2b570c               sub edx, dword ptr [edi + 0xc]
// 0041f853  8b460c               mov eax, dword ptr [esi + 0xc]
// 0041f856  83c41c               add esp, 0x1c
// 0041f859  5d                   pop ebp
// 0041f85a  c1fa03               sar edx, 3
// 0041f85d  5b                   pop ebx
// 0041f85e  8d0cd0               lea ecx, [eax + edx*8]
// 0041f861  5f                   pop edi
// 0041f862  894e10               mov dword ptr [esi + 0x10], ecx
// 0041f865  8bc6                 mov eax, esi
// 0041f867  5e                   pop esi
// 0041f868  c20400               ret 4
// 0041f86b  85c0                 test eax, eax
// 0041f86d  7504                 jne 0x41f873
// 0041f86f  33db                 xor ebx, ebx
// 0041f871  eb08                 jmp 0x41f87b
// 0041f873  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 0041f876  2bd8                 sub ebx, eax
// 0041f878  c1fb03               sar ebx, 3
// 0041f87b  3bcb                 cmp ecx, ebx
// 0041f87d  772c                 ja 0x41f8ab
// 0041f87f  8bcd                 mov ecx, ebp
// 0041f881  50                   push eax
// 0041f882  8d1cd1               lea ebx, [ecx + edx*8]
// 0041f885  53                   push ebx
// 0041f886  51                   push ecx
// 0041f887  e87407ffff           call 0x410000
// 0041f88c  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041f88f  8b4710               mov eax, dword ptr [edi + 0x10]
// 0041f892  83c40c               add esp, 0xc
// 0041f895  52                   push edx
// 0041f896  50                   push eax
// 0041f897  53                   push ebx
// 0041f898  8bce                 mov ecx, esi
// 0041f89a  e8d14a0a00           call 0x4c4370
// 0041f89f  5d                   pop ebp
// 0041f8a0  5b                   pop ebx
// 0041f8a1  894610               mov dword ptr [esi + 0x10], eax
// 0041f8a4  5f                   pop edi
// 0041f8a5  8bc6                 mov eax, esi
// 0041f8a7  5e                   pop esi
// 0041f8a8  c20400               ret 4
// 0041f8ab  85c0                 test eax, eax
// 0041f8ad  7418                 je 0x41f8c7
// 0041f8af  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041f8b2  51                   push ecx
// 0041f8b3  50                   push eax
// 0041f8b4  8bce                 mov ecx, esi
// 0041f8b6  e8d5a63c00           call 0x7e9f90
// 0041f8bb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0041f8be  51                   push ecx
// 0041f8bf  e8963f3d00           call 0x7f385a
// 0041f8c4  83c404               add esp, 4
// 0041f8c7  8b4710               mov eax, dword ptr [edi + 0x10]
// 0041f8ca  2b470c               sub eax, dword ptr [edi + 0xc]
// 0041f8cd  8bce                 mov ecx, esi
// 0041f8cf  c1f803               sar eax, 3
// 0041f8d2  50                   push eax
// 0041f8d3  e808d12600           call 0x68c9e0
// 0041f8d8  84c0                 test al, al
// 0041f8da  7416                 je 0x41f8f2
// 0041f8dc  8b560c               mov edx, dword ptr [esi + 0xc]
// 0041f8df  8b4710               mov eax, dword ptr [edi + 0x10]
// 0041f8e2  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0041f8e5  52                   push edx
// 0041f8e6  50                   push eax
// 0041f8e7  51                   push ecx
// 0041f8e8  8bce                 mov ecx, esi
// 0041f8ea  e8814a0a00           call 0x4c4370
// 0041f8ef  894610               mov dword ptr [esi + 0x10], eax
// 0041f8f2  5d                   pop ebp
// 0041f8f3  5b                   pop ebx
// 0041f8f4  5f                   pop edi
// 0041f8f5  8bc6                 mov eax, esi
// 0041f8f7  5e                   pop esi
// 0041f8f8  c20400               ret 4
// library templates-boost-1_34_1/vector_sp.cpp (function ??4?$vector@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
