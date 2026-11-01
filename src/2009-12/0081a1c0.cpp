// from server: 100% by auto
// roc 2009-12 0081a1c0  unit: CInstanceRecord::CNameItem  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a1c0
//
// 0081a1c0  56                   push esi
// 0081a1c1  8b35dccb9800         mov esi, dword ptr [0x98cbdc]
// 0081a1c7  57                   push edi
// 0081a1c8  6a00                 push 0
// 0081a1ca  6a00                 push 0
// 0081a1cc  6a00                 push 0
// 0081a1ce  6a00                 push 0
// 0081a1d0  6a17                 push 0x17
// 0081a1d2  ffd6                 call esi
// 0081a1d4  8b3d24cb9800         mov edi, dword ptr [0x98cb24]
// 0081a1da  f7d8                 neg eax
// 0081a1dc  1bc0                 sbb eax, eax
// 0081a1de  83e006               and eax, 6
// 0081a1e1  83c002               add eax, 2
// 0081a1e4  50                   push eax
// 0081a1e5  ffd7                 call edi
// 0081a1e7  6a00                 push 0
// 0081a1e9  6a00                 push 0
// 0081a1eb  6a00                 push 0
// 0081a1ed  6a00                 push 0
// 0081a1ef  6a17                 push 0x17
// 0081a1f1  ffd6                 call esi
// 0081a1f3  f7d8                 neg eax
// 0081a1f5  1bc0                 sbb eax, eax
// 0081a1f7  83e00c               and eax, 0xc
// 0081a1fa  83c004               add eax, 4
// 0081a1fd  50                   push eax
// 0081a1fe  ffd7                 call edi
// 0081a200  5f                   pop edi
// 0081a201  5e                   pop esi
// 0081a202  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?DoMouseButtonClick@CXTPReportRecordItem@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
