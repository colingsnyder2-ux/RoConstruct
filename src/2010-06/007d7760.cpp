// from server: 100% by auto
// roc 2010-06 007d7760  unit: CXTPReportControl  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7760
//
// 007d7760  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d7767  68b055c200           push 0xc255b0
// 007d776c  743b                 je 0x7d77a9
// 007d776e  ff1580a39e00         call dword ptr [0x9ea380]
// 007d7774  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d777b  741c                 je 0x7d7799
// 007d777d  e89eb2ffff           call 0x7d2a20
// 007d7782  8b442404             mov eax, dword ptr [esp + 4]
// 007d7786  8b0dac55c200         mov ecx, dword ptr [0xc255ac]
// 007d778c  50                   push eax
// 007d778d  6a00                 push 0
// 007d778f  51                   push ecx
// 007d7790  ff1510a39e00         call dword ptr [0x9ea310]
// 007d7796  c20400               ret 4
// 007d7799  8b542404             mov edx, dword ptr [esp + 4]
// 007d779d  52                   push edx
// 007d779e  e8df04fdff           call 0x7a7c82
// 007d77a3  83c404               add esp, 4
// 007d77a6  c20400               ret 4
// 007d77a9  ff1580a39e00         call dword ptr [0x9ea380]
// 007d77af  8b442404             mov eax, dword ptr [esp + 4]
// 007d77b3  50                   push eax
// 007d77b4  e8e701fdff           call 0x7a79a0
// 007d77b9  83c404               add esp, 4
// 007d77bc  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??2?$CXTPHeapObjectT@VCCmdTarget@@VCXTPReportDataAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
