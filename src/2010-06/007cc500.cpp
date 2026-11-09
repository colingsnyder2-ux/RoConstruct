// from server: 100% by auto
// roc 2010-06 007cc500  unit: CXTPReportViewPrintOptions  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc500
//
// 007cc500  56                   push esi
// 007cc501  8bf1                 mov esi, ecx
// 007cc503  e8c8480300           call 0x800dd0
// 007cc508  33c0                 xor eax, eax
// 007cc50a  894640               mov dword ptr [esi + 0x40], eax
// 007cc50d  894644               mov dword ptr [esi + 0x44], eax
// 007cc510  c706d485a500         mov dword ptr [esi], 0xa585d4
// 007cc516  8bc6                 mov eax, esi
// 007cc518  5e                   pop esi
// 007cc519  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportView.cpp (function ??0CXTPReportViewPrintOptions@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportView.cpp
