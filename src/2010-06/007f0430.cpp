// from server: 100% by auto
// roc 2010-06 007f0430  unit: CPatchedControlComboBox  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0430
//
// 007f0430  56                   push esi
// 007f0431  8bf1                 mov esi, ecx
// 007f0433  8b4608               mov eax, dword ptr [esi + 8]
// 007f0436  57                   push edi
// 007f0437  85c0                 test eax, eax
// 007f0439  741d                 je 0x7f0458
// 007f043b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f043f  6a00                 push 0
// 007f0441  51                   push ecx
// 007f0442  ffd0                 call eax
// 007f0444  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f0448  50                   push eax
// 007f0449  57                   push edi
// 007f044a  8bce                 mov ecx, esi
// 007f044c  e87ffdffff           call 0x7f01d0
// 007f0451  8bc7                 mov eax, edi
// 007f0453  5f                   pop edi
// 007f0454  5e                   pop esi
// 007f0455  c20800               ret 8
// 007f0458  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f045c  33c0                 xor eax, eax
// 007f045e  50                   push eax
// 007f045f  57                   push edi
// 007f0460  8bce                 mov ecx, esi
// 007f0462  e869fdffff           call 0x7f01d0
// 007f0467  8bc7                 mov eax, edi
// 007f0469  5f                   pop edi
// 007f046a  5e                   pop esi
// 007f046b  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
