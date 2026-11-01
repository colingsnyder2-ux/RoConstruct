// from server: 100% by auto
// roc 2009-12 0081c4a0  unit: CXTPReportControl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081c4a0
//
// 0081c4a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081c4a4  8b542410             mov edx, dword ptr [esp + 0x10]
// 0081c4a8  50                   push eax
// 0081c4a9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081c4ad  52                   push edx
// 0081c4ae  8b542410             mov edx, dword ptr [esp + 0x10]
// 0081c4b2  50                   push eax
// 0081c4b3  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081c4b7  52                   push edx
// 0081c4b8  50                   push eax
// 0081c4b9  6a00                 push 0
// 0081c4bb  68684b9f00           push 0x9f4b68
// 0081c4c0  e80774fdff           call 0x7f38cc
// 0081c4c5  f7d8                 neg eax
// 0081c4c7  1bc0                 sbb eax, eax
// 0081c4c9  f7d8                 neg eax
// 0081c4cb  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Create@CXTPReportControl@@QAEHKABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
