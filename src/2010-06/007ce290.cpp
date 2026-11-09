// from server: 100% by auto
// roc 2010-06 007ce290  unit: CInstanceRecord::CNameItem  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce290
//
// 007ce290  56                   push esi
// 007ce291  8b356cba9e00         mov esi, dword ptr [0x9eba6c]
// 007ce297  57                   push edi
// 007ce298  6a00                 push 0
// 007ce29a  6a00                 push 0
// 007ce29c  6a00                 push 0
// 007ce29e  6a00                 push 0
// 007ce2a0  6a17                 push 0x17
// 007ce2a2  ffd6                 call esi
// 007ce2a4  8b3ddcb99e00         mov edi, dword ptr [0x9eb9dc]
// 007ce2aa  f7d8                 neg eax
// 007ce2ac  1bc0                 sbb eax, eax
// 007ce2ae  83e006               and eax, 6
// 007ce2b1  83c002               add eax, 2
// 007ce2b4  50                   push eax
// 007ce2b5  ffd7                 call edi
// 007ce2b7  6a00                 push 0
// 007ce2b9  6a00                 push 0
// 007ce2bb  6a00                 push 0
// 007ce2bd  6a00                 push 0
// 007ce2bf  6a17                 push 0x17
// 007ce2c1  ffd6                 call esi
// 007ce2c3  f7d8                 neg eax
// 007ce2c5  1bc0                 sbb eax, eax
// 007ce2c7  83e00c               and eax, 0xc
// 007ce2ca  83c004               add eax, 4
// 007ce2cd  50                   push eax
// 007ce2ce  ffd7                 call edi
// 007ce2d0  5f                   pop edi
// 007ce2d1  5e                   pop esi
// 007ce2d2  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?DoMouseButtonClick@CXTPReportRecordItem@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
