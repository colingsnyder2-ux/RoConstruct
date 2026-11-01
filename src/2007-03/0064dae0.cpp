// from server: 100% by auto
// roc 2007-03 0064dae0  unit: seg_00640000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064dae0
//
// 0064dae0  56                   push esi
// 0064dae1  8bf1                 mov esi, ecx
// 0064dae3  85f6                 test esi, esi
// 0064dae5  741c                 je 0x64db03
// 0064dae7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064daeb  e8f074fdff           call 0x624fe0
// 0064daf0  85c0                 test eax, eax
// 0064daf2  7c0f                 jl 0x64db03
// 0064daf4  3b4628               cmp eax, dword ptr [esi + 0x28]
// 0064daf7  7d0a                 jge 0x64db03
// 0064daf9  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0064dafc  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0064daff  5e                   pop esi
// 0064db00  c20400               ret 4
// 0064db03  33c0                 xor eax, eax
// 0064db05  5e                   pop esi
// 0064db06  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?GetItem@CXTPReportRecord@@QBEPAVCXTPReportRecordItem@@PAVCXTPReportColumn@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
