// from server: 100% by auto
// roc 2010-06 007cc530  unit: CXTPReportViewPrintOptions  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc530
//
// 007cc530  56                   push esi
// 007cc531  57                   push edi
// 007cc532  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007cc536  8bf1                 mov esi, ecx
// 007cc538  85ff                 test edi, edi
// 007cc53a  7412                 je 0x7cc54e
// 007cc53c  57                   push edi
// 007cc53d  e81e2c0300           call 0x7ff160
// 007cc542  8b4740               mov eax, dword ptr [edi + 0x40]
// 007cc545  894640               mov dword ptr [esi + 0x40], eax
// 007cc548  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 007cc54b  894e44               mov dword ptr [esi + 0x44], ecx
// 007cc54e  5f                   pop edi
// 007cc54f  5e                   pop esi
// 007cc550  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportView.cpp (function ?Set@CXTPReportViewPrintOptions@@UAEXPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportView.cpp
