// from server: 100% by auto
// roc 2010-06 007e1250  unit: CXTPReportRecords  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e1250
//
// 007e1250  56                   push esi
// 007e1251  8bf1                 mov esi, ecx
// 007e1253  e828fdffff           call 0x7e0f80
// 007e1258  f644240801           test byte ptr [esp + 8], 1
// 007e125d  742c                 je 0x7e128b
// 007e125f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007e1266  740f                 je 0x7e1277
// 007e1268  56                   push esi
// 007e1269  e8c29ec3ff           call 0x41b130
// 007e126e  83c404               add esp, 4
// 007e1271  8bc6                 mov eax, esi
// 007e1273  5e                   pop esi
// 007e1274  c20400               ret 4
// 007e1277  689055c200           push 0xc25590
// 007e127c  ff157ca39e00         call dword ptr [0x9ea37c]
// 007e1282  56                   push esi
// 007e1283  e81267fcff           call 0x7a799a
// 007e1288  83c404               add esp, 4
// 007e128b  8bc6                 mov eax, esi
// 007e128d  5e                   pop esi
// 007e128e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
