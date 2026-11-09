// from server: 100% by auto
// roc 2010-06 007d76c0  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d76c0
//
// 007d76c0  833dbc55c20000       cmp dword ptr [0xc255bc], 0
// 007d76c7  7410                 je 0x7d76d9
// 007d76c9  8b442404             mov eax, dword ptr [esp + 4]
// 007d76cd  50                   push eax
// 007d76ce  e89df0ffff           call 0x7d6770
// 007d76d3  83c404               add esp, 4
// 007d76d6  c20400               ret 4
// 007d76d9  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d76e0  7410                 je 0x7d76f2
// 007d76e2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d76e6  51                   push ecx
// 007d76e7  e8d4b2ffff           call 0x7d29c0
// 007d76ec  83c404               add esp, 4
// 007d76ef  c20400               ret 4
// 007d76f2  68a055c200           push 0xc255a0
// 007d76f7  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d76fd  8b542404             mov edx, dword ptr [esp + 4]
// 007d7701  52                   push edx
// 007d7702  e89302fdff           call 0x7a799a
// 007d7707  59                   pop ecx
// 007d7708  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
