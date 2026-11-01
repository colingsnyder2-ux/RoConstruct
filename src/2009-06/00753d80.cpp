// from server: 100% by auto
// roc 2009-06 00753d80  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00753d80
//
// 00753d80  83793400             cmp dword ptr [ecx + 0x34], 0
// 00753d84  7503                 jne 0x753d89
// 00753d86  33c0                 xor eax, eax
// 00753d88  c3                   ret 
// 00753d89  c7412800000000       mov dword ptr [ecx + 0x28], 0
// 00753d90  83793400             cmp dword ptr [ecx + 0x34], 0
// 00753d94  7e07                 jle 0x753d9d
// 00753d96  8b4130               mov eax, dword ptr [ecx + 0x30]
// 00753d99  8b00                 mov eax, dword ptr [eax]
// 00753d9b  40                   inc eax
// 00753d9c  c3                   ret 
// 00753d9d  e9424ffcff           jmp 0x718ce4
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?GetFirstSelectedRowPosition@CXTPReportSelectedRows@@QAEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
