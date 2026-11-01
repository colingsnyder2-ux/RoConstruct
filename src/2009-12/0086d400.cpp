// from server: 100% by auto
// roc 2009-12 0086d400  unit: CXTCaption  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d400
//
// 0086d400  53                   push ebx
// 0086d401  55                   push ebp
// 0086d402  56                   push esi
// 0086d403  57                   push edi
// 0086d404  8bf9                 mov edi, ecx
// 0086d406  8b5f30               mov ebx, dword ptr [edi + 0x30]
// 0086d409  33ed                 xor ebp, ebp
// 0086d40b  33f6                 xor esi, esi
// 0086d40d  85db                 test ebx, ebx
// 0086d40f  7e22                 jle 0x86d433
// 0086d411  85f6                 test esi, esi
// 0086d413  7c19                 jl 0x86d42e
// 0086d415  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0086d418  7d14                 jge 0x86d42e
// 0086d41a  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0086d41d  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 0086d420  85c9                 test ecx, ecx
// 0086d422  740a                 je 0x86d42e
// 0086d424  e897660400           call 0x8b3ac0
// 0086d429  85c0                 test eax, eax
// 0086d42b  7401                 je 0x86d42e
// 0086d42d  45                   inc ebp
// 0086d42e  46                   inc esi
// 0086d42f  3bf3                 cmp esi, ebx
// 0086d431  7cde                 jl 0x86d411
// 0086d433  5f                   pop edi
// 0086d434  5e                   pop esi
// 0086d435  8bc5                 mov eax, ebp
// 0086d437  5d                   pop ebp
// 0086d438  5b                   pop ebx
// 0086d439  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleColumnsCount@CXTPReportColumns@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
