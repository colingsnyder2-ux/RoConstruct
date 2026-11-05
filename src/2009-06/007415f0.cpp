// from server: 100% by auto
// roc 2009-06 007415f0  unit: CXTPReportControl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007415f0
//
// 007415f0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007415f4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007415f8  50                   push eax
// 007415f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 007415fd  52                   push edx
// 007415fe  8b542410             mov edx, dword ptr [esp + 0x10]
// 00741602  50                   push eax
// 00741603  8b442410             mov eax, dword ptr [esp + 0x10]
// 00741607  52                   push edx
// 00741608  50                   push eax
// 00741609  6a00                 push 0
// 0074160b  68c4468f00           push 0x8f46c4
// 00741610  e88f74fdff           call 0x718aa4
// 00741615  f7d8                 neg eax
// 00741617  1bc0                 sbb eax, eax
// 00741619  f7d8                 neg eax
// 0074161b  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Create@CXTPReportControl@@QAEHKABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
