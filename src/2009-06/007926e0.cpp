// from server: 100% by auto
// roc 2009-06 007926e0  unit: PAVCXTPReportColumn::?$CArray  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007926e0
//
// 007926e0  57                   push edi
// 007926e1  8b7c2408             mov edi, dword ptr [esp + 8]
// 007926e5  85ff                 test edi, edi
// 007926e7  7c4a                 jl 0x792733
// 007926e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007926ed  85c0                 test eax, eax
// 007926ef  7c42                 jl 0x792733
// 007926f1  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 007926f4  53                   push ebx
// 007926f5  56                   push esi
// 007926f6  7d2e                 jge 0x792726
// 007926f8  3b4130               cmp eax, dword ptr [ecx + 0x30]
// 007926fb  8d7128               lea esi, [ecx + 0x28]
// 007926fe  7d2e                 jge 0x79272e
// 00792700  8b4e04               mov ecx, dword ptr [esi + 4]
// 00792703  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 00792706  85db                 test ebx, ebx
// 00792708  741c                 je 0x792726
// 0079270a  3bf8                 cmp edi, eax
// 0079270c  7418                 je 0x792726
// 0079270e  7e01                 jle 0x792711
// 00792710  4f                   dec edi
// 00792711  6a01                 push 1
// 00792713  50                   push eax
// 00792714  8bce                 mov ecx, esi
// 00792716  e845fffbff           call 0x752660
// 0079271b  6a01                 push 1
// 0079271d  53                   push ebx
// 0079271e  57                   push edi
// 0079271f  8bce                 mov ecx, esi
// 00792721  e8caf80700           call 0x811ff0
// 00792726  5e                   pop esi
// 00792727  5b                   pop ebx
// 00792728  8bc7                 mov eax, edi
// 0079272a  5f                   pop edi
// 0079272b  c20800               ret 8
// 0079272e  e8b165f8ff           call 0x718ce4
// 00792733  83c8ff               or eax, 0xffffffff
// 00792736  5f                   pop edi
// 00792737  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?ChangeColumnOrder@CXTPReportColumns@@QAEHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
