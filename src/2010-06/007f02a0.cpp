// from server: 100% by auto
// roc 2010-06 007f02a0  unit: CPatchedControlComboBox  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f02a0
//
// 007f02a0  56                   push esi
// 007f02a1  8bf1                 mov esi, ecx
// 007f02a3  8b4604               mov eax, dword ptr [esi + 4]
// 007f02a6  57                   push edi
// 007f02a7  85c0                 test eax, eax
// 007f02a9  741d                 je 0x7f02c8
// 007f02ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f02af  6a00                 push 0
// 007f02b1  51                   push ecx
// 007f02b2  ffd0                 call eax
// 007f02b4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f02b8  50                   push eax
// 007f02b9  57                   push edi
// 007f02ba  8bce                 mov ecx, esi
// 007f02bc  e86fffffff           call 0x7f0230
// 007f02c1  8bc7                 mov eax, edi
// 007f02c3  5f                   pop edi
// 007f02c4  5e                   pop esi
// 007f02c5  c20800               ret 8
// 007f02c8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f02cc  33c0                 xor eax, eax
// 007f02ce  50                   push eax
// 007f02cf  57                   push edi
// 007f02d0  8bce                 mov ecx, esi
// 007f02d2  e859ffffff           call 0x7f0230
// 007f02d7  8bc7                 mov eax, edi
// 007f02d9  5f                   pop edi
// 007f02da  5e                   pop esi
// 007f02db  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
