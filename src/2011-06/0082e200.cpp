// from server: 100% by auto
// roc 2011-06 0082e200  unit: CXTPPrintingDialog  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082e200
//
// 0082e200  8b442404             mov eax, dword ptr [esp + 4]
// 0082e204  83ec10               sub esp, 0x10
// 0082e207  56                   push esi
// 0082e208  50                   push eax
// 0082e209  8bf1                 mov esi, ecx
// 0082e20b  e870c9fdff           call 0x80ab80
// 0082e210  83f8ff               cmp eax, -1
// 0082e213  7509                 jne 0x82e21e
// 0082e215  0bc0                 or eax, eax
// 0082e217  5e                   pop esi
// 0082e218  83c410               add esp, 0x10
// 0082e21b  c20400               ret 4
// 0082e21e  8b16                 mov edx, dword ptr [esi]
// 0082e220  33c0                 xor eax, eax
// 0082e222  50                   push eax
// 0082e223  6a64                 push 0x64
// 0082e225  56                   push esi
// 0082e226  8d4c2410             lea ecx, [esp + 0x10]
// 0082e22a  51                   push ecx
// 0082e22b  89442414             mov dword ptr [esp + 0x14], eax
// 0082e22f  89442418             mov dword ptr [esp + 0x18], eax
// 0082e233  8944241c             mov dword ptr [esp + 0x1c], eax
// 0082e237  89442420             mov dword ptr [esp + 0x20], eax
// 0082e23b  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0082e241  6800000150           push 0x50010000
// 0082e246  8bce                 mov ecx, esi
// 0082e248  ffd0                 call eax
// 0082e24a  8bc8                 mov ecx, eax
// 0082e24c  e8ef230000           call 0x830640
// 0082e251  f7d8                 neg eax
// 0082e253  1bc0                 sbb eax, eax
// 0082e255  f7d8                 neg eax
// 0082e257  48                   dec eax
// 0082e258  5e                   pop esi
// 0082e259  83c410               add esp, 0x10
// 0082e25c  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportView.cpp (function ?OnCreate@CXTPReportView@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportView.cpp
