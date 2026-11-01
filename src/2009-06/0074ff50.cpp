// from server: 100% by auto
// roc 2009-06 0074ff50  unit: CInstanceRecord  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0074ff50
//
// 0074ff50  8b4940               mov ecx, dword ptr [ecx + 0x40]
// 0074ff53  85c9                 test ecx, ecx
// 0074ff55  740f                 je 0x74ff66
// 0074ff57  e8541f0000           call 0x751eb0
// 0074ff5c  85c0                 test eax, eax
// 0074ff5e  7e06                 jle 0x74ff66
// 0074ff60  b801000000           mov eax, 1
// 0074ff65  c3                   ret 
// 0074ff66  33c0                 xor eax, eax
// 0074ff68  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?HasChildren@CXTPReportRecord@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
