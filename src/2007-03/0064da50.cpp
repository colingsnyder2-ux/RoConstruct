// from server: 100% by auto
// roc 2007-03 0064da50  unit: seg_00640000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064da50
//
// 0064da50  8b4940               mov ecx, dword ptr [ecx + 0x40]
// 0064da53  85c9                 test ecx, ecx
// 0064da55  740f                 je 0x64da66
// 0064da57  e8641b0000           call 0x64f5c0
// 0064da5c  85c0                 test eax, eax
// 0064da5e  7e06                 jle 0x64da66
// 0064da60  b801000000           mov eax, 1
// 0064da65  c3                   ret 
// 0064da66  33c0                 xor eax, eax
// 0064da68  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?HasChildren@CXTPReportRecord@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
