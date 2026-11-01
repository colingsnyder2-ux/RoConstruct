// from server: 100% by auto
// roc 2009-12 00818450  unit: CXTPReportViewPrintOptions  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00818450
//
// 00818450  56                   push esi
// 00818451  57                   push edi
// 00818452  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00818456  8bf1                 mov esi, ecx
// 00818458  85ff                 test edi, edi
// 0081845a  7412                 je 0x81846e
// 0081845c  57                   push edi
// 0081845d  e8ce2c0300           call 0x84b130
// 00818462  8b4740               mov eax, dword ptr [edi + 0x40]
// 00818465  894640               mov dword ptr [esi + 0x40], eax
// 00818468  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0081846b  894e44               mov dword ptr [esi + 0x44], ecx
// 0081846e  5f                   pop edi
// 0081846f  5e                   pop esi
// 00818470  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportPageSetupDialog.cpp (function ?Set@CXTPReportViewPrintOptions@@UAEXPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPageSetupDialog.cpp
