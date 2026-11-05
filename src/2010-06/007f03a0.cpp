// from server: 100% by auto
// roc 2010-06 007f03a0  unit: CPatchedControlComboBox  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f03a0
//
// 007f03a0  56                   push esi
// 007f03a1  8bf1                 mov esi, ecx
// 007f03a3  8b4604               mov eax, dword ptr [esi + 4]
// 007f03a6  57                   push edi
// 007f03a7  85c0                 test eax, eax
// 007f03a9  741d                 je 0x7f03c8
// 007f03ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f03af  6a00                 push 0
// 007f03b1  51                   push ecx
// 007f03b2  ffd0                 call eax
// 007f03b4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f03b8  50                   push eax
// 007f03b9  57                   push edi
// 007f03ba  8bce                 mov ecx, esi
// 007f03bc  e80ffeffff           call 0x7f01d0
// 007f03c1  8bc7                 mov eax, edi
// 007f03c3  5f                   pop edi
// 007f03c4  5e                   pop esi
// 007f03c5  c20800               ret 8
// 007f03c8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f03cc  33c0                 xor eax, eax
// 007f03ce  50                   push eax
// 007f03cf  57                   push edi
// 007f03d0  8bce                 mov ecx, esi
// 007f03d2  e8f9fdffff           call 0x7f01d0
// 007f03d7  8bc7                 mov eax, edi
// 007f03d9  5f                   pop edi
// 007f03da  5e                   pop esi
// 007f03db  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
