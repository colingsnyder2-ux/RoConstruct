// from server: 100% by auto
// roc 2009-12 0082ad20  unit: CInstanceRecord  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ad20
//
// 0082ad20  8b4940               mov ecx, dword ptr [ecx + 0x40]
// 0082ad23  85c9                 test ecx, ecx
// 0082ad25  740f                 je 0x82ad36
// 0082ad27  e8f41e0000           call 0x82cc20
// 0082ad2c  85c0                 test eax, eax
// 0082ad2e  7e06                 jle 0x82ad36
// 0082ad30  b801000000           mov eax, 1
// 0082ad35  c3                   ret 
// 0082ad36  33c0                 xor eax, eax
// 0082ad38  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecord.cpp (function ?HasChildren@CXTPReportRecord@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecord.cpp
