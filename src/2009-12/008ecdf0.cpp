// from server: 100% by auto
// roc 2009-12 008ecdf0  unit: CXTPRibbonGroup  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ecdf0
//
// 008ecdf0  83ec10               sub esp, 0x10
// 008ecdf3  53                   push ebx
// 008ecdf4  55                   push ebp
// 008ecdf5  8bd9                 mov ebx, ecx
// 008ecdf7  8b4328               mov eax, dword ptr [ebx + 0x28]
// 008ecdfa  56                   push esi
// 008ecdfb  33f6                 xor esi, esi
// 008ecdfd  57                   push edi
// 008ecdfe  85c0                 test eax, eax
// 008ece00  7e61                 jle 0x8ece63
// 008ece02  8b2d5cca9800         mov ebp, dword ptr [0x98ca5c]
// 008ece08  85f6                 test esi, esi
// 008ece0a  7c11                 jl 0x8ece1d
// 008ece0c  3bf0                 cmp esi, eax
// 008ece0e  7d0d                 jge 0x8ece1d
// 008ece10  3b7328               cmp esi, dword ptr [ebx + 0x28]
// 008ece13  7d5a                 jge 0x8ece6f
// 008ece15  8b4324               mov eax, dword ptr [ebx + 0x24]
// 008ece18  8b3cb0               mov edi, dword ptr [eax + esi*4]
// 008ece1b  eb02                 jmp 0x8ece1f
// 008ece1d  33ff                 xor edi, edi
// 008ece1f  8bcf                 mov ecx, edi
// 008ece21  e83ac7ffff           call 0x8e9560
// 008ece26  85c0                 test eax, eax
// 008ece28  7431                 je 0x8ece5b
// 008ece2a  8b5738               mov edx, dword ptr [edi + 0x38]
// 008ece2d  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008ece30  8b473c               mov eax, dword ptr [edi + 0x3c]
// 008ece33  894c2410             mov dword ptr [esp + 0x10], ecx
// 008ece37  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008ece3a  89542414             mov dword ptr [esp + 0x14], edx
// 008ece3e  8b542428             mov edx, dword ptr [esp + 0x28]
// 008ece42  89442418             mov dword ptr [esp + 0x18], eax
// 008ece46  8b442424             mov eax, dword ptr [esp + 0x24]
// 008ece4a  52                   push edx
// 008ece4b  894c2420             mov dword ptr [esp + 0x20], ecx
// 008ece4f  50                   push eax
// 008ece50  8d4c2418             lea ecx, [esp + 0x18]
// 008ece54  51                   push ecx
// 008ece55  ffd5                 call ebp
// 008ece57  85c0                 test eax, eax
// 008ece59  7519                 jne 0x8ece74
// 008ece5b  8b4328               mov eax, dword ptr [ebx + 0x28]
// 008ece5e  46                   inc esi
// 008ece5f  3bf0                 cmp esi, eax
// 008ece61  7ca5                 jl 0x8ece08
// 008ece63  5f                   pop edi
// 008ece64  5e                   pop esi
// 008ece65  5d                   pop ebp
// 008ece66  33c0                 xor eax, eax
// 008ece68  5b                   pop ebx
// 008ece69  83c410               add esp, 0x10
// 008ece6c  c20800               ret 8
// 008ece6f  e8986cf0ff           call 0x7f3b0c
// 008ece74  8bc7                 mov eax, edi
// 008ece76  5f                   pop edi
// 008ece77  5e                   pop esi
// 008ece78  5d                   pop ebp
// 008ece79  5b                   pop ebx
// 008ece7a  83c410               add esp, 0x10
// 008ece7d  c20800               ret 8
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?HitTest@CXTPRibbonGroups@@QBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
