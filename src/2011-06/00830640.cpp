// from server: 100% by auto
// roc 2011-06 00830640  unit: CXTPReportControl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00830640
//
// 00830640  8b442414             mov eax, dword ptr [esp + 0x14]
// 00830644  8b542410             mov edx, dword ptr [esp + 0x10]
// 00830648  50                   push eax
// 00830649  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083064d  52                   push edx
// 0083064e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00830652  50                   push eax
// 00830653  8b442410             mov eax, dword ptr [esp + 0x10]
// 00830657  52                   push edx
// 00830658  50                   push eax
// 00830659  6a00                 push 0
// 0083065b  68f047ac00           push 0xac47f0
// 00830660  e8659afdff           call 0x80a0ca
// 00830665  f7d8                 neg eax
// 00830667  1bc0                 sbb eax, eax
// 00830669  f7d8                 neg eax
// 0083066b  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Create@CXTPReportControl@@QAEHKABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
