// from server: 100% by auto
// roc 2007-03 006438f0  unit: seg_00640000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006438f0
//
// 006438f0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006438f4  8b542410             mov edx, dword ptr [esp + 0x10]
// 006438f8  50                   push eax
// 006438f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 006438fd  52                   push edx
// 006438fe  8b542410             mov edx, dword ptr [esp + 0x10]
// 00643902  50                   push eax
// 00643903  8b442410             mov eax, dword ptr [esp + 0x10]
// 00643907  52                   push edx
// 00643908  50                   push eax
// 00643909  6a00                 push 0
// 0064390b  68a8577c00           push 0x7c57a8
// 00643910  e859a8fdff           call 0x61e16e
// 00643915  f7d8                 neg eax
// 00643917  1bc0                 sbb eax, eax
// 00643919  f7d8                 neg eax
// 0064391b  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Create@CXTPReportControl@@QAEHKABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
