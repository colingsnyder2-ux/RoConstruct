// from server: 100% by auto
// roc 2009-06 0073f2a0  unit: CInstanceRecord::CNameItem  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f2a0
//
// 0073f2a0  56                   push esi
// 0073f2a1  8b35dced8900         mov esi, dword ptr [0x89eddc]
// 0073f2a7  57                   push edi
// 0073f2a8  6a00                 push 0
// 0073f2aa  6a00                 push 0
// 0073f2ac  6a00                 push 0
// 0073f2ae  6a00                 push 0
// 0073f2b0  6a17                 push 0x17
// 0073f2b2  ffd6                 call esi
// 0073f2b4  8b3d30ef8900         mov edi, dword ptr [0x89ef30]
// 0073f2ba  f7d8                 neg eax
// 0073f2bc  1bc0                 sbb eax, eax
// 0073f2be  83e006               and eax, 6
// 0073f2c1  83c002               add eax, 2
// 0073f2c4  50                   push eax
// 0073f2c5  ffd7                 call edi
// 0073f2c7  6a00                 push 0
// 0073f2c9  6a00                 push 0
// 0073f2cb  6a00                 push 0
// 0073f2cd  6a00                 push 0
// 0073f2cf  6a17                 push 0x17
// 0073f2d1  ffd6                 call esi
// 0073f2d3  f7d8                 neg eax
// 0073f2d5  1bc0                 sbb eax, eax
// 0073f2d7  83e00c               and eax, 0xc
// 0073f2da  83c004               add eax, 4
// 0073f2dd  50                   push eax
// 0073f2de  ffd7                 call edi
// 0073f2e0  5f                   pop edi
// 0073f2e1  5e                   pop esi
// 0073f2e2  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?DoMouseButtonClick@CXTPReportRecordItem@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
