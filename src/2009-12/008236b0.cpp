// from server: 100% by auto
// roc 2009-12 008236b0  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008236b0
//
// 008236b0  833da4aeb90000       cmp dword ptr [0xb9aea4], 0
// 008236b7  7410                 je 0x8236c9
// 008236b9  8b442404             mov eax, dword ptr [esp + 4]
// 008236bd  50                   push eax
// 008236be  e82df2ffff           call 0x8228f0
// 008236c3  83c404               add esp, 4
// 008236c6  c20400               ret 4
// 008236c9  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 008236d0  7410                 je 0x8236e2
// 008236d2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008236d6  51                   push ecx
// 008236d7  e884b2ffff           call 0x81e960
// 008236dc  83c404               add esp, 4
// 008236df  c20400               ret 4
// 008236e2  6870aeb900           push 0xb9ae70
// 008236e7  ff1508b29800         call dword ptr [0x98b208]
// 008236ed  8b542404             mov edx, dword ptr [esp + 4]
// 008236f1  52                   push edx
// 008236f2  e86301fdff           call 0x7f385a
// 008236f7  59                   pop ecx
// 008236f8  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
