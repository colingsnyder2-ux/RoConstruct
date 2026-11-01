// from server: 100% by auto
// roc 2009-06 00729500  unit: CXTPCommandBars  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729500
//
// 00729500  8b442408             mov eax, dword ptr [esp + 8]
// 00729504  83f803               cmp eax, 3
// 00729507  7717                 ja 0x729520
// 00729509  8b848190000000       mov eax, dword ptr [ecx + eax*4 + 0x90]
// 00729510  50                   push eax
// 00729511  8b442408             mov eax, dword ptr [esp + 8]
// 00729515  6a00                 push 0
// 00729517  50                   push eax
// 00729518  e883ffffff           call 0x7294a0
// 0072951d  c20800               ret 8
// 00729520  33c0                 xor eax, eax
// 00729522  50                   push eax
// 00729523  50                   push eax
// 00729524  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00729528  50                   push eax
// 00729529  e872ffffff           call 0x7294a0
// 0072952e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?DockCommandBar@CXTPCommandBars@@QAEHPAVCXTPToolBar@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
