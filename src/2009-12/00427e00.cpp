// from server: 100% by auto
// roc 2009-12 00427e00  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427e00
//
// 00427e00  8b442404             mov eax, dword ptr [esp + 4]
// 00427e04  83f802               cmp eax, 2
// 00427e07  740d                 je 0x427e16
// 00427e09  83f803               cmp eax, 3
// 00427e0c  7408                 je 0x427e16
// 00427e0e  83f805               cmp eax, 5
// 00427e11  7403                 je 0x427e16
// 00427e13  33c0                 xor eax, eax
// 00427e15  c3                   ret 
// 00427e16  b801000000           mov eax, 1
// 00427e1b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?IsVerticalPosition@@YAHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
