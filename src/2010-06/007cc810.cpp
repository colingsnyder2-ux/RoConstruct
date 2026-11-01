// from server: 100% by auto
// roc 2010-06 007cc810  unit: CXTPPrintingDialog  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc810
//
// 007cc810  8b442404             mov eax, dword ptr [esp + 4]
// 007cc814  83ec10               sub esp, 0x10
// 007cc817  56                   push esi
// 007cc818  50                   push eax
// 007cc819  8bf1                 mov esi, ecx
// 007cc81b  e89cbcfdff           call 0x7a84bc
// 007cc820  83f8ff               cmp eax, -1
// 007cc823  7509                 jne 0x7cc82e
// 007cc825  0bc0                 or eax, eax
// 007cc827  5e                   pop esi
// 007cc828  83c410               add esp, 0x10
// 007cc82b  c20400               ret 4
// 007cc82e  8b16                 mov edx, dword ptr [esi]
// 007cc830  33c0                 xor eax, eax
// 007cc832  50                   push eax
// 007cc833  6a64                 push 0x64
// 007cc835  56                   push esi
// 007cc836  8d4c2410             lea ecx, [esp + 0x10]
// 007cc83a  51                   push ecx
// 007cc83b  89442414             mov dword ptr [esp + 0x14], eax
// 007cc83f  89442418             mov dword ptr [esp + 0x18], eax
// 007cc843  8944241c             mov dword ptr [esp + 0x1c], eax
// 007cc847  89442420             mov dword ptr [esp + 0x20], eax
// 007cc84b  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 007cc851  6800000150           push 0x50010000
// 007cc856  8bce                 mov ecx, esi
// 007cc858  ffd0                 call eax
// 007cc85a  8bc8                 mov ecx, eax
// 007cc85c  e8af3c0000           call 0x7d0510
// 007cc861  f7d8                 neg eax
// 007cc863  1bc0                 sbb eax, eax
// 007cc865  f7d8                 neg eax
// 007cc867  48                   dec eax
// 007cc868  5e                   pop esi
// 007cc869  83c410               add esp, 0x10
// 007cc86c  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportView.cpp (function ?OnCreate@CXTPReportView@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportView.cpp
