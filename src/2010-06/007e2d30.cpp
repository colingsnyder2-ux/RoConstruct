// from server: 100% by auto
// roc 2010-06 007e2d30  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e2d30
//
// 007e2d30  83793400             cmp dword ptr [ecx + 0x34], 0
// 007e2d34  7503                 jne 0x7e2d39
// 007e2d36  33c0                 xor eax, eax
// 007e2d38  c3                   ret 
// 007e2d39  c7412800000000       mov dword ptr [ecx + 0x28], 0
// 007e2d40  83793400             cmp dword ptr [ecx + 0x34], 0
// 007e2d44  7e07                 jle 0x7e2d4d
// 007e2d46  8b4130               mov eax, dword ptr [ecx + 0x30]
// 007e2d49  8b00                 mov eax, dword ptr [eax]
// 007e2d4b  40                   inc eax
// 007e2d4c  c3                   ret 
// 007e2d4d  e9fa4efcff           jmp 0x7a7c4c
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?GetFirstSelectedRowPosition@CXTPReportSelectedRows@@QAEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
