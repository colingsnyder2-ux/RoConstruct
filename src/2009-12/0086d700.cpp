// from server: 100% by auto
// roc 2009-12 0086d700  unit: PAVCXTPReportColumn::?$CArray  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d700
//
// 0086d700  57                   push edi
// 0086d701  8b7c2408             mov edi, dword ptr [esp + 8]
// 0086d705  85ff                 test edi, edi
// 0086d707  7c4a                 jl 0x86d753
// 0086d709  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0086d70d  85c0                 test eax, eax
// 0086d70f  7c42                 jl 0x86d753
// 0086d711  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 0086d714  53                   push ebx
// 0086d715  56                   push esi
// 0086d716  7d2e                 jge 0x86d746
// 0086d718  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 0086d71b  8d7128               lea esi, [ecx + 0x28]
// 0086d71e  7d2e                 jge 0x86d74e
// 0086d720  8b4e04               mov ecx, dword ptr [esi + 4]
// 0086d723  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 0086d726  85db                 test ebx, ebx
// 0086d728  741c                 je 0x86d746
// 0086d72a  3bf8                 cmp edi, eax
// 0086d72c  7418                 je 0x86d746
// 0086d72e  7e01                 jle 0x86d731
// 0086d730  4f                   dec edi
// 0086d731  6a01                 push 1
// 0086d733  50                   push eax
// 0086d734  8bce                 mov ecx, esi
// 0086d736  e845fbfbff           call 0x82d280
// 0086d73b  6a01                 push 1
// 0086d73d  53                   push ebx
// 0086d73e  57                   push edi
// 0086d73f  8bce                 mov ecx, esi
// 0086d741  e8fa030800           call 0x8edb40
// 0086d746  5e                   pop esi
// 0086d747  5b                   pop ebx
// 0086d748  8bc7                 mov eax, edi
// 0086d74a  5f                   pop edi
// 0086d74b  c20800               ret 8
// 0086d74e  e8b963f8ff           call 0x7f3b0c
// 0086d753  83c8ff               or eax, 0xffffffff
// 0086d756  5f                   pop edi
// 0086d757  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?ChangeColumnOrder@CXTPReportColumns@@QAEHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
