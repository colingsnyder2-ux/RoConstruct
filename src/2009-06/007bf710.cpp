// from server: 100% by auto
// roc 2009-06 007bf710  unit: CXTPDockContext  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf710
//
// 007bf710  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bf714  83ec08               sub esp, 8
// 007bf717  53                   push ebx
// 007bf718  55                   push ebp
// 007bf719  56                   push esi
// 007bf71a  8b742418             mov esi, dword ptr [esp + 0x18]
// 007bf71e  57                   push edi
// 007bf71f  50                   push eax
// 007bf720  8bce                 mov ecx, esi
// 007bf722  e871cf0800           call 0x84c698
// 007bf727  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007bf72b  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 007bf72f  53                   push ebx
// 007bf730  55                   push ebp
// 007bf731  8d4c2418             lea ecx, [esp + 0x18]
// 007bf735  51                   push ecx
// 007bf736  8bce                 mov ecx, esi
// 007bf738  8bf8                 mov edi, eax
// 007bf73a  e8cfa1f5ff           call 0x71990e
// 007bf73f  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007bf743  8b442428             mov eax, dword ptr [esp + 0x28]
// 007bf747  03da                 add ebx, edx
// 007bf749  53                   push ebx
// 007bf74a  03e8                 add ebp, eax
// 007bf74c  55                   push ebp
// 007bf74d  8bce                 mov ecx, esi
// 007bf74f  e8b4a1f5ff           call 0x719908
// 007bf754  57                   push edi
// 007bf755  8bce                 mov ecx, esi
// 007bf757  e83ccf0800           call 0x84c698
// 007bf75c  5f                   pop edi
// 007bf75d  5e                   pop esi
// 007bf75e  5d                   pop ebp
// 007bf75f  5b                   pop ebx
// 007bf760  83c408               add esp, 8
// 007bf763  c21800               ret 0x18
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Line@CXTPReportPaintManager@@QAEXPAVCDC@@HHHHPAVCPen@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
