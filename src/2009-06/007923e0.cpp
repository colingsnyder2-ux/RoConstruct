// from server: 100% by auto
// roc 2009-06 007923e0  unit: CXTCaption  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007923e0
//
// 007923e0  53                   push ebx
// 007923e1  55                   push ebp
// 007923e2  56                   push esi
// 007923e3  57                   push edi
// 007923e4  8bf9                 mov edi, ecx
// 007923e6  8b5f30               mov ebx, dword ptr [edi + 0x30]
// 007923e9  33ed                 xor ebp, ebp
// 007923eb  33f6                 xor esi, esi
// 007923ed  85db                 test ebx, ebx
// 007923ef  7e22                 jle 0x792413
// 007923f1  85f6                 test esi, esi
// 007923f3  7c19                 jl 0x79240e
// 007923f5  3b7730               cmp esi, dword ptr [edi + 0x30]
// 007923f8  7d14                 jge 0x79240e
// 007923fa  8b472c               mov eax, dword ptr [edi + 0x2c]
// 007923fd  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 00792400  85c9                 test ecx, ecx
// 00792402  740a                 je 0x79240e
// 00792404  e847a9fbff           call 0x74cd50
// 00792409  85c0                 test eax, eax
// 0079240b  7401                 je 0x79240e
// 0079240d  45                   inc ebp
// 0079240e  46                   inc esi
// 0079240f  3bf3                 cmp esi, ebx
// 00792411  7cde                 jl 0x7923f1
// 00792413  5f                   pop edi
// 00792414  5e                   pop esi
// 00792415  8bc5                 mov eax, ebp
// 00792417  5d                   pop ebp
// 00792418  5b                   pop ebx
// 00792419  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleColumnsCount@CXTPReportColumns@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
