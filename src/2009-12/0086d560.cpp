// from server: 100% by auto
// roc 2009-12 0086d560  unit: CXTCaption  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d560
//
// 0086d560  53                   push ebx
// 0086d561  56                   push esi
// 0086d562  57                   push edi
// 0086d563  8bf9                 mov edi, ecx
// 0086d565  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d568  33f6                 xor esi, esi
// 0086d56a  85c0                 test eax, eax
// 0086d56c  7e2c                 jle 0x86d59a
// 0086d56e  8bff                 mov edi, edi
// 0086d570  85f6                 test esi, esi
// 0086d572  7c11                 jl 0x86d585
// 0086d574  3bf0                 cmp esi, eax
// 0086d576  7d0d                 jge 0x86d585
// 0086d578  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0086d57b  7d23                 jge 0x86d5a0
// 0086d57d  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0086d580  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 0086d583  eb02                 jmp 0x86d587
// 0086d585  33db                 xor ebx, ebx
// 0086d587  8bcb                 mov ecx, ebx
// 0086d589  e832650400           call 0x8b3ac0
// 0086d58e  85c0                 test eax, eax
// 0086d590  7513                 jne 0x86d5a5
// 0086d592  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d595  46                   inc esi
// 0086d596  3bf0                 cmp esi, eax
// 0086d598  7cd6                 jl 0x86d570
// 0086d59a  5f                   pop edi
// 0086d59b  5e                   pop esi
// 0086d59c  33c0                 xor eax, eax
// 0086d59e  5b                   pop ebx
// 0086d59f  c3                   ret 
// 0086d5a0  e86765f8ff           call 0x7f3b0c
// 0086d5a5  5f                   pop edi
// 0086d5a6  5e                   pop esi
// 0086d5a7  8bc3                 mov eax, ebx
// 0086d5a9  5b                   pop ebx
// 0086d5aa  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetFirstVisibleColumn@CXTPReportColumns@@QBEPAVCXTPReportColumn@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
