// from server: 100% by auto
// roc 2010-06 00820490  unit: PAVCXTPReportColumn::?$CArray  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820490
//
// 00820490  57                   push edi
// 00820491  8b7c2408             mov edi, dword ptr [esp + 8]
// 00820495  85ff                 test edi, edi
// 00820497  7c4a                 jl 0x8204e3
// 00820499  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0082049d  85c0                 test eax, eax
// 0082049f  7c42                 jl 0x8204e3
// 008204a1  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 008204a4  53                   push ebx
// 008204a5  56                   push esi
// 008204a6  7d2e                 jge 0x8204d6
// 008204a8  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 008204ab  8d7128               lea esi, [ecx + 0x28]
// 008204ae  7d2e                 jge 0x8204de
// 008204b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 008204b3  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 008204b6  85db                 test ebx, ebx
// 008204b8  741c                 je 0x8204d6
// 008204ba  3bf8                 cmp edi, eax
// 008204bc  7418                 je 0x8204d6
// 008204be  7e01                 jle 0x8204c1
// 008204c0  4f                   dec edi
// 008204c1  6a01                 push 1
// 008204c3  50                   push eax
// 008204c4  8bce                 mov ecx, esi
// 008204c6  e87585f9ff           call 0x7b8a40
// 008204cb  6a01                 push 1
// 008204cd  53                   push ebx
// 008204ce  57                   push edi
// 008204cf  8bce                 mov ecx, esi
// 008204d1  e8eab4f8ff           call 0x7ab9c0
// 008204d6  5e                   pop esi
// 008204d7  5b                   pop ebx
// 008204d8  8bc7                 mov eax, edi
// 008204da  5f                   pop edi
// 008204db  c20800               ret 8
// 008204de  e86977f8ff           call 0x7a7c4c
// 008204e3  83c8ff               or eax, 0xffffffff
// 008204e6  5f                   pop edi
// 008204e7  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?ChangeColumnOrder@CXTPReportColumns@@QAEHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportColumns.cpp
