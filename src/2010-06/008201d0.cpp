// from server: 100% by auto
// roc 2010-06 008201d0  unit: CXTPWinThemeWrapper  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008201d0
//
// 008201d0  53                   push ebx
// 008201d1  55                   push ebp
// 008201d2  56                   push esi
// 008201d3  57                   push edi
// 008201d4  8bf9                 mov edi, ecx
// 008201d6  8b4730               mov eax, dword ptr [edi + 0x30]
// 008201d9  33f6                 xor esi, esi
// 008201db  85c0                 test eax, eax
// 008201dd  7e2e                 jle 0x82020d
// 008201df  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 008201e3  85f6                 test esi, esi
// 008201e5  7c11                 jl 0x8201f8
// 008201e7  3bf0                 cmp esi, eax
// 008201e9  7d0d                 jge 0x8201f8
// 008201eb  3b7730               cmp esi, dword ptr [edi + 0x30]
// 008201ee  7d26                 jge 0x820216
// 008201f0  8b472c               mov eax, dword ptr [edi + 0x2c]
// 008201f3  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 008201f6  eb02                 jmp 0x8201fa
// 008201f8  33db                 xor ebx, ebx
// 008201fa  8bcb                 mov ecx, ebx
// 008201fc  e84f89f9ff           call 0x7b8b50
// 00820201  3bc5                 cmp eax, ebp
// 00820203  7416                 je 0x82021b
// 00820205  8b4730               mov eax, dword ptr [edi + 0x30]
// 00820208  46                   inc esi
// 00820209  3bf0                 cmp esi, eax
// 0082020b  7cd6                 jl 0x8201e3
// 0082020d  5f                   pop edi
// 0082020e  5e                   pop esi
// 0082020f  5d                   pop ebp
// 00820210  33c0                 xor eax, eax
// 00820212  5b                   pop ebx
// 00820213  c20400               ret 4
// 00820216  e8317af8ff           call 0x7a7c4c
// 0082021b  5f                   pop edi
// 0082021c  5e                   pop esi
// 0082021d  5d                   pop ebp
// 0082021e  8bc3                 mov eax, ebx
// 00820220  5b                   pop ebx
// 00820221  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?Find@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportColumns.cpp
