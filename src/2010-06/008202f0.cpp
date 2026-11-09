// from server: 100% by auto
// roc 2010-06 008202f0  unit: CXTPWinThemeWrapper  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008202f0
//
// 008202f0  53                   push ebx
// 008202f1  56                   push esi
// 008202f2  57                   push edi
// 008202f3  8bf9                 mov edi, ecx
// 008202f5  8b4730               mov eax, dword ptr [edi + 0x30]
// 008202f8  33f6                 xor esi, esi
// 008202fa  85c0                 test eax, eax
// 008202fc  7e2c                 jle 0x82032a
// 008202fe  8bff                 mov edi, edi
// 00820300  85f6                 test esi, esi
// 00820302  7c11                 jl 0x820315
// 00820304  3bf0                 cmp esi, eax
// 00820306  7d0d                 jge 0x820315
// 00820308  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0082030b  7d23                 jge 0x820330
// 0082030d  8b472c               mov eax, dword ptr [edi + 0x2c]
// 00820310  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 00820313  eb02                 jmp 0x820317
// 00820315  33db                 xor ebx, ebx
// 00820317  8bcb                 mov ecx, ebx
// 00820319  e882b8fbff           call 0x7dbba0
// 0082031e  85c0                 test eax, eax
// 00820320  7513                 jne 0x820335
// 00820322  8b4730               mov eax, dword ptr [edi + 0x30]
// 00820325  46                   inc esi
// 00820326  3bf0                 cmp esi, eax
// 00820328  7cd6                 jl 0x820300
// 0082032a  5f                   pop edi
// 0082032b  5e                   pop esi
// 0082032c  33c0                 xor eax, eax
// 0082032e  5b                   pop ebx
// 0082032f  c3                   ret 
// 00820330  e81779f8ff           call 0x7a7c4c
// 00820335  5f                   pop edi
// 00820336  5e                   pop esi
// 00820337  8bc3                 mov eax, ebx
// 00820339  5b                   pop ebx
// 0082033a  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetFirstVisibleColumn@CXTPReportColumns@@QBEPAVCXTPReportColumn@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportColumns.cpp
