// from server: 100% by auto
// roc 2009-12 0082ad40  unit: CInstanceRecord  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ad40
//
// 0082ad40  56                   push esi
// 0082ad41  8bf1                 mov esi, ecx
// 0082ad43  85f6                 test esi, esi
// 0082ad45  741c                 je 0x82ad63
// 0082ad47  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0082ad4b  e820abcaff           call 0x4d5870
// 0082ad50  85c0                 test eax, eax
// 0082ad52  7c0f                 jl 0x82ad63
// 0082ad54  3b4628               cmp eax, dword ptr [esi + 0x28]
// 0082ad57  7d0a                 jge 0x82ad63
// 0082ad59  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0082ad5c  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0082ad5f  5e                   pop esi
// 0082ad60  c20400               ret 4
// 0082ad63  33c0                 xor eax, eax
// 0082ad65  5e                   pop esi
// 0082ad66  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?GetItem@CXTPReportRecord@@QBEPAVCXTPReportRecordItem@@PAVCXTPReportColumn@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
