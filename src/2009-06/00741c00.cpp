// from server: 100% by auto
// roc 2009-06 00741c00  unit: CXTPReportControl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00741c00
//
// 00741c00  8b89ec000000         mov ecx, dword ptr [ecx + 0xec]
// 00741c06  56                   push esi
// 00741c07  8b742408             mov esi, dword ptr [esp + 8]
// 00741c0b  56                   push esi
// 00741c0c  e89f0a0500           call 0x7926b0
// 00741c11  8bc6                 mov eax, esi
// 00741c13  5e                   pop esi
// 00741c14  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?AddColumn@CXTPReportControl@@QAEPAVCXTPReportColumn@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
