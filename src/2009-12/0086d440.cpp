// from server: 100% by auto
// roc 2009-12 0086d440  unit: CXTCaption  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d440
//
// 0086d440  53                   push ebx
// 0086d441  55                   push ebp
// 0086d442  56                   push esi
// 0086d443  57                   push edi
// 0086d444  8bf9                 mov edi, ecx
// 0086d446  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d449  33f6                 xor esi, esi
// 0086d44b  85c0                 test eax, eax
// 0086d44d  7e2e                 jle 0x86d47d
// 0086d44f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0086d453  85f6                 test esi, esi
// 0086d455  7c11                 jl 0x86d468
// 0086d457  3bf0                 cmp esi, eax
// 0086d459  7d0d                 jge 0x86d468
// 0086d45b  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0086d45e  7d26                 jge 0x86d486
// 0086d460  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0086d463  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 0086d466  eb02                 jmp 0x86d46a
// 0086d468  33db                 xor ebx, ebx
// 0086d46a  8bcb                 mov ecx, ebx
// 0086d46c  e8ff83c6ff           call 0x4d5870
// 0086d471  3bc5                 cmp eax, ebp
// 0086d473  7416                 je 0x86d48b
// 0086d475  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d478  46                   inc esi
// 0086d479  3bf0                 cmp esi, eax
// 0086d47b  7cd6                 jl 0x86d453
// 0086d47d  5f                   pop edi
// 0086d47e  5e                   pop esi
// 0086d47f  5d                   pop ebp
// 0086d480  33c0                 xor eax, eax
// 0086d482  5b                   pop ebx
// 0086d483  c20400               ret 4
// 0086d486  e88166f8ff           call 0x7f3b0c
// 0086d48b  5f                   pop edi
// 0086d48c  5e                   pop esi
// 0086d48d  5d                   pop ebp
// 0086d48e  8bc3                 mov eax, ebx
// 0086d490  5b                   pop ebx
// 0086d491  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?Find@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
