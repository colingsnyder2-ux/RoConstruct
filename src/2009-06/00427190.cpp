// from server: 100% by auto
// roc 2009-06 00427190  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427190
//
// 00427190  8b442404             mov eax, dword ptr [esp + 4]
// 00427194  83f802               cmp eax, 2
// 00427197  740d                 je 0x4271a6
// 00427199  83f803               cmp eax, 3
// 0042719c  7408                 je 0x4271a6
// 0042719e  83f805               cmp eax, 5
// 004271a1  7403                 je 0x4271a6
// 004271a3  33c0                 xor eax, eax
// 004271a5  c3                   ret 
// 004271a6  b801000000           mov eax, 1
// 004271ab  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?IsVerticalPosition@@YAHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
