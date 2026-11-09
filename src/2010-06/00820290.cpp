// from server: 100% by auto
// roc 2010-06 00820290  unit: CXTPWinThemeWrapper  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820290
//
// 00820290  53                   push ebx
// 00820291  55                   push ebp
// 00820292  56                   push esi
// 00820293  57                   push edi
// 00820294  8bf9                 mov edi, ecx
// 00820296  8b4730               mov eax, dword ptr [edi + 0x30]
// 00820299  33f6                 xor esi, esi
// 0082029b  85c0                 test eax, eax
// 0082029d  7e33                 jle 0x8202d2
// 0082029f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 008202a3  85f6                 test esi, esi
// 008202a5  7c11                 jl 0x8202b8
// 008202a7  3bf0                 cmp esi, eax
// 008202a9  7d0d                 jge 0x8202b8
// 008202ab  3b7730               cmp esi, dword ptr [edi + 0x30]
// 008202ae  7d2b                 jge 0x8202db
// 008202b0  8b472c               mov eax, dword ptr [edi + 0x2c]
// 008202b3  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 008202b6  eb02                 jmp 0x8202ba
// 008202b8  33db                 xor ebx, ebx
// 008202ba  8bcb                 mov ecx, ebx
// 008202bc  e8dfb8fbff           call 0x7dbba0
// 008202c1  85c0                 test eax, eax
// 008202c3  7405                 je 0x8202ca
// 008202c5  85ed                 test ebp, ebp
// 008202c7  7417                 je 0x8202e0
// 008202c9  4d                   dec ebp
// 008202ca  8b4730               mov eax, dword ptr [edi + 0x30]
// 008202cd  46                   inc esi
// 008202ce  3bf0                 cmp esi, eax
// 008202d0  7cd1                 jl 0x8202a3
// 008202d2  5f                   pop edi
// 008202d3  5e                   pop esi
// 008202d4  5d                   pop ebp
// 008202d5  33c0                 xor eax, eax
// 008202d7  5b                   pop ebx
// 008202d8  c20400               ret 4
// 008202db  e86c79f8ff           call 0x7a7c4c
// 008202e0  5f                   pop edi
// 008202e1  5e                   pop esi
// 008202e2  5d                   pop ebp
// 008202e3  8bc3                 mov eax, ebx
// 008202e5  5b                   pop ebx
// 008202e6  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleAt@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportColumns.cpp
