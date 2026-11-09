// from server: 100% by auto
// roc 2011-06 00844690  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00844690
//
// 00844690  83793400             cmp dword ptr [ecx + 0x34], 0
// 00844694  7503                 jne 0x844699
// 00844696  33c0                 xor eax, eax
// 00844698  c3                   ret 
// 00844699  c7412800000000       mov dword ptr [ecx + 0x28], 0
// 008446a0  83793400             cmp dword ptr [ecx + 0x34], 0
// 008446a4  7e07                 jle 0x8446ad
// 008446a6  8b4130               mov eax, dword ptr [ecx + 0x30]
// 008446a9  8b00                 mov eax, dword ptr [eax]
// 008446ab  40                   inc eax
// 008446ac  c3                   ret 
// 008446ad  e9585cfcff           jmp 0x80a30a
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?GetFirstSelectedRowPosition@CXTPReportSelectedRows@@QAEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
