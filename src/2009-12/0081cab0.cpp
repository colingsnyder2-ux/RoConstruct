// from server: 100% by auto
// roc 2009-12 0081cab0  unit: CXTPReportControl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081cab0
//
// 0081cab0  8b89ec000000         mov ecx, dword ptr [ecx + 0xec]
// 0081cab6  56                   push esi
// 0081cab7  8b742408             mov esi, dword ptr [esp + 8]
// 0081cabb  56                   push esi
// 0081cabc  e80f0c0500           call 0x86d6d0
// 0081cac1  8bc6                 mov eax, esi
// 0081cac3  5e                   pop esi
// 0081cac4  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?AddColumn@CXTPReportControl@@QAEPAVCXTPReportColumn@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
