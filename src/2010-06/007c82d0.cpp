// from server: 100% by auto
// roc 2010-06 007c82d0  unit: CXTPCommandBars  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c82d0
//
// 007c82d0  8b442408             mov eax, dword ptr [esp + 8]
// 007c82d4  83f803               cmp eax, 3
// 007c82d7  7717                 ja 0x7c82f0
// 007c82d9  8b848190000000       mov eax, dword ptr [ecx + eax*4 + 0x90]
// 007c82e0  50                   push eax
// 007c82e1  8b442408             mov eax, dword ptr [esp + 8]
// 007c82e5  6a00                 push 0
// 007c82e7  50                   push eax
// 007c82e8  e883ffffff           call 0x7c8270
// 007c82ed  c20800               ret 8
// 007c82f0  33c0                 xor eax, eax
// 007c82f2  50                   push eax
// 007c82f3  50                   push eax
// 007c82f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c82f8  50                   push eax
// 007c82f9  e872ffffff           call 0x7c8270
// 007c82fe  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?DockCommandBar@CXTPCommandBars@@QAEHPAVCXTPToolBar@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
