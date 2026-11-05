// from server: 100% by auto
// roc 2010-06 0041acb0  unit: CInstanceRecord::CNameItem  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041acb0
//
// 0041acb0  56                   push esi
// 0041acb1  8bf1                 mov esi, ecx
// 0041acb3  e8a8533b00           call 0x7d0060
// 0041acb8  85c0                 test eax, eax
// 0041acba  7411                 je 0x41accd
// 0041acbc  8bce                 mov ecx, esi
// 0041acbe  e89d533b00           call 0x7d0060
// 0041acc3  8b10                 mov edx, dword ptr [eax]
// 0041acc5  5e                   pop esi
// 0041acc6  8bc8                 mov ecx, eax
// 0041acc8  8b5278               mov edx, dword ptr [edx + 0x78]
// 0041accb  ffe2                 jmp edx
// 0041accd  83c8ff               or eax, 0xffffffff
// 0041acd0  5e                   pop esi
// 0041acd1  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportRecordItemText.cpp (function ?AddHyperlink@CXTPReportRecordItem@@UAEHPAVCXTPReportHyperlink@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportRecordItemText.cpp
