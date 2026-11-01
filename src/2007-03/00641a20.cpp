// from server: 100% by auto
// roc 2007-03 00641a20  unit: seg_00640000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00641a20
//
// 00641a20  56                   push esi
// 00641a21  8b35bced7700         mov esi, dword ptr [0x77edbc]
// 00641a27  57                   push edi
// 00641a28  6a00                 push 0
// 00641a2a  6a00                 push 0
// 00641a2c  6a00                 push 0
// 00641a2e  6a00                 push 0
// 00641a30  6a17                 push 0x17
// 00641a32  ffd6                 call esi
// 00641a34  8b3d5cef7700         mov edi, dword ptr [0x77ef5c]
// 00641a3a  f7d8                 neg eax
// 00641a3c  1bc0                 sbb eax, eax
// 00641a3e  83e006               and eax, 6
// 00641a41  83c002               add eax, 2
// 00641a44  50                   push eax
// 00641a45  ffd7                 call edi
// 00641a47  6a00                 push 0
// 00641a49  6a00                 push 0
// 00641a4b  6a00                 push 0
// 00641a4d  6a00                 push 0
// 00641a4f  6a17                 push 0x17
// 00641a51  ffd6                 call esi
// 00641a53  f7d8                 neg eax
// 00641a55  1bc0                 sbb eax, eax
// 00641a57  83e00c               and eax, 0xc
// 00641a5a  83c004               add eax, 4
// 00641a5d  50                   push eax
// 00641a5e  ffd7                 call edi
// 00641a60  5f                   pop edi
// 00641a61  5e                   pop esi
// 00641a62  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?DoMouseButtonClick@CXTPReportRecordItem@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
