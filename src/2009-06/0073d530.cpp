// from server: 100% by auto
// roc 2009-06 0073d530  unit: CXTPReportViewPrintOptions  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073d530
//
// 0073d530  56                   push esi
// 0073d531  57                   push edi
// 0073d532  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0073d536  8bf1                 mov esi, ecx
// 0073d538  85ff                 test edi, edi
// 0073d53a  7412                 je 0x73d54e
// 0073d53c  57                   push edi
// 0073d53d  e8ee2d0300           call 0x770330
// 0073d542  8b4740               mov eax, dword ptr [edi + 0x40]
// 0073d545  894640               mov dword ptr [esi + 0x40], eax
// 0073d548  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0073d54b  894e44               mov dword ptr [esi + 0x44], ecx
// 0073d54e  5f                   pop edi
// 0073d54f  5e                   pop esi
// 0073d550  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportPageSetupDialog.cpp (function ?Set@CXTPReportViewPrintOptions@@UAEXPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPageSetupDialog.cpp
