// from server: 100% by auto
// roc 2010-06 007cc870  unit: CXTPPrintingDialog  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc870
//
// 007cc870  8b442404             mov eax, dword ptr [esp + 4]
// 007cc874  56                   push esi
// 007cc875  50                   push eax
// 007cc876  8bf1                 mov esi, ecx
// 007cc878  e851bffdff           call 0x7a87ce
// 007cc87d  8b16                 mov edx, dword ptr [esi]
// 007cc87f  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 007cc885  8bce                 mov ecx, esi
// 007cc887  ffd0                 call eax
// 007cc889  85c0                 test eax, eax
// 007cc88b  7403                 je 0x7cc890
// 007cc88d  8b4020               mov eax, dword ptr [eax + 0x20]
// 007cc890  50                   push eax
// 007cc891  ff1528bc9e00         call dword ptr [0x9ebc28]
// 007cc897  85c0                 test eax, eax
// 007cc899  7413                 je 0x7cc8ae
// 007cc89b  8b16                 mov edx, dword ptr [esi]
// 007cc89d  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 007cc8a3  8bce                 mov ecx, esi
// 007cc8a5  ffd0                 call eax
// 007cc8a7  8bc8                 mov ecx, eax
// 007cc8a9  e894b4fdff           call 0x7a7d42
// 007cc8ae  5e                   pop esi
// 007cc8af  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportView.cpp (function ?OnSetFocus@CXTPReportView@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportView.cpp
