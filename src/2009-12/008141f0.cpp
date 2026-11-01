// from server: 100% by auto
// roc 2009-12 008141f0  unit: CXTPCommandBars  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008141f0
//
// 008141f0  8b442408             mov eax, dword ptr [esp + 8]
// 008141f4  83f803               cmp eax, 3
// 008141f7  7717                 ja 0x814210
// 008141f9  8b848190000000       mov eax, dword ptr [ecx + eax*4 + 0x90]
// 00814200  50                   push eax
// 00814201  8b442408             mov eax, dword ptr [esp + 8]
// 00814205  6a00                 push 0
// 00814207  50                   push eax
// 00814208  e883ffffff           call 0x814190
// 0081420d  c20800               ret 8
// 00814210  33c0                 xor eax, eax
// 00814212  50                   push eax
// 00814213  50                   push eax
// 00814214  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00814218  50                   push eax
// 00814219  e872ffffff           call 0x814190
// 0081421e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?DockCommandBar@CXTPCommandBars@@QAEHPAVCXTPToolBar@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
