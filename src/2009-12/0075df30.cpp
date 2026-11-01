// from server: 100% by auto
// roc 2009-12 0075df30  unit: RBX::VLuaDragger::?$FactoryProduct  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075df30
//
// 0075df30  56                   push esi
// 0075df31  57                   push edi
// 0075df32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0075df36  8bf1                 mov esi, ecx
// 0075df38  3bf7                 cmp esi, edi
// 0075df3a  0f84f4000000         je 0x75e034
// 0075df40  53                   push ebx
// 0075df41  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 0075df44  55                   push ebp
// 0075df45  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 0075df48  8bcb                 mov ecx, ebx
// 0075df4a  2bcd                 sub ecx, ebp
// 0075df4c  c1f903               sar ecx, 3
// 0075df4f  85c9                 test ecx, ecx
// 0075df51  7510                 jne 0x75df63
// 0075df53  8bce                 mov ecx, esi
// 0075df55  e846e20500           call 0x7bc1a0
// 0075df5a  5d                   pop ebp
// 0075df5b  5b                   pop ebx
// 0075df5c  5f                   pop edi
// 0075df5d  8bc6                 mov eax, esi
// 0075df5f  5e                   pop esi
// 0075df60  c20400               ret 4
// 0075df63  8b5610               mov edx, dword ptr [esi + 0x10]
// 0075df66  8b460c               mov eax, dword ptr [esi + 0xc]
// 0075df69  2bd0                 sub edx, eax
// 0075df6b  c1fa03               sar edx, 3
// 0075df6e  3bca                 cmp ecx, edx
// 0075df70  7739                 ja 0x75dfab
// 0075df72  50                   push eax
// 0075df73  53                   push ebx
// 0075df74  55                   push ebp
// 0075df75  e866df0500           call 0x7bbee0
// 0075df7a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0075df7e  51                   push ecx
// 0075df7f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0075df82  8d5608               lea edx, [esi + 8]
// 0075df85  52                   push edx
// 0075df86  51                   push ecx
// 0075df87  50                   push eax
// 0075df88  e823edfdff           call 0x73ccb0
// 0075df8d  8b5710               mov edx, dword ptr [edi + 0x10]
// 0075df90  2b570c               sub edx, dword ptr [edi + 0xc]
// 0075df93  8b460c               mov eax, dword ptr [esi + 0xc]
// 0075df96  83c41c               add esp, 0x1c
// 0075df99  5d                   pop ebp
// 0075df9a  c1fa03               sar edx, 3
// 0075df9d  5b                   pop ebx
// 0075df9e  8d0cd0               lea ecx, [eax + edx*8]
// 0075dfa1  5f                   pop edi
// 0075dfa2  894e10               mov dword ptr [esi + 0x10], ecx
// 0075dfa5  8bc6                 mov eax, esi
// 0075dfa7  5e                   pop esi
// 0075dfa8  c20400               ret 4
// 0075dfab  85c0                 test eax, eax
// 0075dfad  7504                 jne 0x75dfb3
// 0075dfaf  33db                 xor ebx, ebx
// 0075dfb1  eb08                 jmp 0x75dfbb
// 0075dfb3  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 0075dfb6  2bd8                 sub ebx, eax
// 0075dfb8  c1fb03               sar ebx, 3
// 0075dfbb  3bcb                 cmp ecx, ebx
// 0075dfbd  772c                 ja 0x75dfeb
// 0075dfbf  8bcd                 mov ecx, ebp
// 0075dfc1  50                   push eax
// 0075dfc2  8d1cd1               lea ebx, [ecx + edx*8]
// 0075dfc5  53                   push ebx
// 0075dfc6  51                   push ecx
// 0075dfc7  e814df0500           call 0x7bbee0
// 0075dfcc  8b5610               mov edx, dword ptr [esi + 0x10]
// 0075dfcf  8b4710               mov eax, dword ptr [edi + 0x10]
// 0075dfd2  83c40c               add esp, 0xc
// 0075dfd5  52                   push edx
// 0075dfd6  50                   push eax
// 0075dfd7  53                   push ebx
// 0075dfd8  8bce                 mov ecx, esi
// 0075dfda  e8d1e00500           call 0x7bc0b0
// 0075dfdf  5d                   pop ebp
// 0075dfe0  5b                   pop ebx
// 0075dfe1  894610               mov dword ptr [esi + 0x10], eax
// 0075dfe4  5f                   pop edi
// 0075dfe5  8bc6                 mov eax, esi
// 0075dfe7  5e                   pop esi
// 0075dfe8  c20400               ret 4
// 0075dfeb  85c0                 test eax, eax
// 0075dfed  7418                 je 0x75e007
// 0075dfef  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0075dff2  51                   push ecx
// 0075dff3  50                   push eax
// 0075dff4  8bce                 mov ecx, esi
// 0075dff6  e8f5ecfdff           call 0x73ccf0
// 0075dffb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0075dffe  51                   push ecx
// 0075dfff  e856580900           call 0x7f385a
// 0075e004  83c404               add esp, 4
// 0075e007  8b4710               mov eax, dword ptr [edi + 0x10]
// 0075e00a  2b470c               sub eax, dword ptr [edi + 0xc]
// 0075e00d  8bce                 mov ecx, esi
// 0075e00f  c1f803               sar eax, 3
// 0075e012  50                   push eax
// 0075e013  e8c8e9f2ff           call 0x68c9e0
// 0075e018  84c0                 test al, al
// 0075e01a  7416                 je 0x75e032
// 0075e01c  8b560c               mov edx, dword ptr [esi + 0xc]
// 0075e01f  8b4710               mov eax, dword ptr [edi + 0x10]
// 0075e022  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0075e025  52                   push edx
// 0075e026  50                   push eax
// 0075e027  51                   push ecx
// 0075e028  8bce                 mov ecx, esi
// 0075e02a  e881e00500           call 0x7bc0b0
// 0075e02f  894610               mov dword ptr [esi + 0x10], eax
// 0075e032  5d                   pop ebp
// 0075e033  5b                   pop ebx
// 0075e034  5f                   pop edi
// 0075e035  8bc6                 mov eax, esi
// 0075e037  5e                   pop esi
// 0075e038  c20400               ret 4
// library templates-boost-1_34_1/vector_sp.cpp (function ??4?$vector@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
