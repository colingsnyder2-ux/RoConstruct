// from server: 100% by auto
// roc 2010-06 00820190  unit: CXTPWinThemeWrapper  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820190
//
// 00820190  53                   push ebx
// 00820191  55                   push ebp
// 00820192  56                   push esi
// 00820193  57                   push edi
// 00820194  8bf9                 mov edi, ecx
// 00820196  8b5f30               mov ebx, dword ptr [edi + 0x30]
// 00820199  33ed                 xor ebp, ebp
// 0082019b  33f6                 xor esi, esi
// 0082019d  85db                 test ebx, ebx
// 0082019f  7e22                 jle 0x8201c3
// 008201a1  85f6                 test esi, esi
// 008201a3  7c19                 jl 0x8201be
// 008201a5  3b7730               cmp esi, dword ptr [edi + 0x30]
// 008201a8  7d14                 jge 0x8201be
// 008201aa  8b472c               mov eax, dword ptr [edi + 0x2c]
// 008201ad  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 008201b0  85c9                 test ecx, ecx
// 008201b2  740a                 je 0x8201be
// 008201b4  e8e7b9fbff           call 0x7dbba0
// 008201b9  85c0                 test eax, eax
// 008201bb  7401                 je 0x8201be
// 008201bd  45                   inc ebp
// 008201be  46                   inc esi
// 008201bf  3bf3                 cmp esi, ebx
// 008201c1  7cde                 jl 0x8201a1
// 008201c3  5f                   pop edi
// 008201c4  5e                   pop esi
// 008201c5  8bc5                 mov eax, ebp
// 008201c7  5d                   pop ebp
// 008201c8  5b                   pop ebx
// 008201c9  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleColumnsCount@CXTPReportColumns@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportColumns.cpp
