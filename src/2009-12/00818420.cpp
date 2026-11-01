// from server: 100% by auto
// roc 2009-12 00818420  unit: CXTPReportViewPrintOptions  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00818420
//
// 00818420  56                   push esi
// 00818421  8bf1                 mov esi, ecx
// 00818423  e868490300           call 0x84cd90
// 00818428  33c0                 xor eax, eax
// 0081842a  894640               mov dword ptr [esi + 0x40], eax
// 0081842d  894644               mov dword ptr [esi + 0x44], eax
// 00818430  c706e4429f00         mov dword ptr [esi], 0x9f42e4
// 00818436  8bc6                 mov eax, esi
// 00818438  5e                   pop esi
// 00818439  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportPageSetupDialog.cpp (function ??0CXTPReportViewPrintOptions@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPageSetupDialog.cpp
