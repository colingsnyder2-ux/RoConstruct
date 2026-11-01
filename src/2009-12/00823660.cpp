// from server: 100% by auto
// roc 2009-12 00823660  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823660
//
// 00823660  833d8caeb90000       cmp dword ptr [0xb9ae8c], 0
// 00823667  7410                 je 0x823679
// 00823669  8b442404             mov eax, dword ptr [esp + 4]
// 0082366d  50                   push eax
// 0082366e  e89df0ffff           call 0x822710
// 00823673  83c404               add esp, 4
// 00823676  c20400               ret 4
// 00823679  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 00823680  7410                 je 0x823692
// 00823682  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00823686  51                   push ecx
// 00823687  e8d4b2ffff           call 0x81e960
// 0082368c  83c404               add esp, 4
// 0082368f  c20400               ret 4
// 00823692  6870aeb900           push 0xb9ae70
// 00823697  ff1508b29800         call dword ptr [0x98b208]
// 0082369d  8b542404             mov edx, dword ptr [esp + 4]
// 008236a1  52                   push edx
// 008236a2  e8b301fdff           call 0x7f385a
// 008236a7  59                   pop ecx
// 008236a8  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
