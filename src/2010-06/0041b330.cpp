// from server: 100% by auto
// roc 2010-06 0041b330  unit: rbx::signals::connection::slot  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b330
//
// 0041b330  833d9855c20000       cmp dword ptr [0xc25598], 0
// 0041b337  7410                 je 0x41b349
// 0041b339  8b442404             mov eax, dword ptr [esp + 4]
// 0041b33d  50                   push eax
// 0041b33e  e8edfdffff           call 0x41b130
// 0041b343  83c404               add esp, 4
// 0041b346  c20400               ret 4
// 0041b349  689055c200           push 0xc25590
// 0041b34e  ff157ca39e00         call dword ptr [0x9ea37c]
// 0041b354  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041b358  51                   push ecx
// 0041b359  e83cc63800           call 0x7a799a
// 0041b35e  59                   pop ecx
// 0041b35f  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPHeapObjectT@VCXTPReportRowBase@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
