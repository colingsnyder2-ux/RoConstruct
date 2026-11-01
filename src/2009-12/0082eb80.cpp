// from server: 100% by auto
// roc 2009-12 0082eb80  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082eb80
//
// 0082eb80  83793400             cmp dword ptr [ecx + 0x34], 0
// 0082eb84  7503                 jne 0x82eb89
// 0082eb86  33c0                 xor eax, eax
// 0082eb88  c3                   ret 
// 0082eb89  c7412800000000       mov dword ptr [ecx + 0x28], 0
// 0082eb90  83793400             cmp dword ptr [ecx + 0x34], 0
// 0082eb94  7e07                 jle 0x82eb9d
// 0082eb96  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0082eb99  8b00                 mov eax, dword ptr [eax]
// 0082eb9b  40                   inc eax
// 0082eb9c  c3                   ret 
// 0082eb9d  e96a4ffcff           jmp 0x7f3b0c
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?GetFirstSelectedRowPosition@CXTPReportSelectedRows@@QAEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
