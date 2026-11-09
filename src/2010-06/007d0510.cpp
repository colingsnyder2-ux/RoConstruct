// from server: 100% by auto
// roc 2010-06 007d0510  unit: CXTPReportControl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d0510
//
// 007d0510  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d0514  8b542410             mov edx, dword ptr [esp + 0x10]
// 007d0518  50                   push eax
// 007d0519  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d051d  52                   push edx
// 007d051e  8b542410             mov edx, dword ptr [esp + 0x10]
// 007d0522  50                   push eax
// 007d0523  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d0527  52                   push edx
// 007d0528  50                   push eax
// 007d0529  6a00                 push 0
// 007d052b  68588ea500           push 0xa58e58
// 007d0530  e8d774fdff           call 0x7a7a0c
// 007d0535  f7d8                 neg eax
// 007d0537  1bc0                 sbb eax, eax
// 007d0539  f7d8                 neg eax
// 007d053b  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Create@CXTPReportControl@@QAEHKABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
