// from server: 100% by auto
// roc 2010-06 007d7710  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7710
//
// 007d7710  833dd455c20000       cmp dword ptr [0xc255d4], 0
// 007d7717  7410                 je 0x7d7729
// 007d7719  8b442404             mov eax, dword ptr [esp + 4]
// 007d771d  50                   push eax
// 007d771e  e82df2ffff           call 0x7d6950
// 007d7723  83c404               add esp, 4
// 007d7726  c20400               ret 4
// 007d7729  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d7730  7410                 je 0x7d7742
// 007d7732  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d7736  51                   push ecx
// 007d7737  e884b2ffff           call 0x7d29c0
// 007d773c  83c404               add esp, 4
// 007d773f  c20400               ret 4
// 007d7742  68a055c200           push 0xc255a0
// 007d7747  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d774d  8b542404             mov edx, dword ptr [esp + 4]
// 007d7751  52                   push edx
// 007d7752  e84302fdff           call 0x7a799a
// 007d7757  59                   pop ecx
// 007d7758  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
