// from server: 100% by auto
// roc 2009-06 007488a0  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007488a0
//
// 007488a0  833d481aa50000       cmp dword ptr [0xa51a48], 0
// 007488a7  7410                 je 0x7488b9
// 007488a9  8b442404             mov eax, dword ptr [esp + 4]
// 007488ad  50                   push eax
// 007488ae  e8ddf1ffff           call 0x747a90
// 007488b3  83c404               add esp, 4
// 007488b6  c20400               ret 4
// 007488b9  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 007488c0  7410                 je 0x7488d2
// 007488c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007488c6  51                   push ecx
// 007488c7  e8d4b1ffff           call 0x743aa0
// 007488cc  83c404               add esp, 4
// 007488cf  c20400               ret 4
// 007488d2  68141aa500           push 0xa51a14
// 007488d7  ff15a4e18900         call dword ptr [0x89e1a4]
// 007488dd  8b542404             mov edx, dword ptr [esp + 4]
// 007488e1  52                   push edx
// 007488e2  e84b01fdff           call 0x718a32
// 007488e7  59                   pop ecx
// 007488e8  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
