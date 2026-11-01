// from server: 100% by auto
// roc 2009-06 0073d500  unit: CXTPReportViewPrintOptions  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073d500
//
// 0073d500  56                   push esi
// 0073d501  8bf1                 mov esi, ecx
// 0073d503  e8584b0300           call 0x772060
// 0073d508  33c0                 xor eax, eax
// 0073d50a  894640               mov dword ptr [esi + 0x40], eax
// 0073d50d  894644               mov dword ptr [esi + 0x44], eax
// 0073d510  c706243e8f00         mov dword ptr [esi], 0x8f3e24
// 0073d516  8bc6                 mov eax, esi
// 0073d518  5e                   pop esi
// 0073d519  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportPageSetupDialog.cpp (function ??0CXTPReportViewPrintOptions@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPageSetupDialog.cpp
