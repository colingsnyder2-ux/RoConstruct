// from server: 100% by auto
// roc 2009-06 0074ff70  unit: CInstanceRecord  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0074ff70
//
// 0074ff70  56                   push esi
// 0074ff71  8bf1                 mov esi, ecx
// 0074ff73  85f6                 test esi, esi
// 0074ff75  741c                 je 0x74ff93
// 0074ff77  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0074ff7b  e830cfffff           call 0x74ceb0
// 0074ff80  85c0                 test eax, eax
// 0074ff82  7c0f                 jl 0x74ff93
// 0074ff84  3b4628               cmp eax, dword ptr [esi + 0x28]
// 0074ff87  7d0a                 jge 0x74ff93
// 0074ff89  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0074ff8c  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0074ff8f  5e                   pop esi
// 0074ff90  c20400               ret 4
// 0074ff93  33c0                 xor eax, eax
// 0074ff95  5e                   pop esi
// 0074ff96  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?GetItem@CXTPReportRecord@@QBEPAVCXTPReportRecordItem@@PAVCXTPReportColumn@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
