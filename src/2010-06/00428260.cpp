// from server: 100% by auto
// roc 2010-06 00428260  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428260
//
// 00428260  8b442404             mov eax, dword ptr [esp + 4]
// 00428264  83f802               cmp eax, 2
// 00428267  740d                 je 0x428276
// 00428269  83f803               cmp eax, 3
// 0042826c  7408                 je 0x428276
// 0042826e  83f805               cmp eax, 5
// 00428271  7403                 je 0x428276
// 00428273  33c0                 xor eax, eax
// 00428275  c3                   ret 
// 00428276  b801000000           mov eax, 1
// 0042827b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?IsVerticalPosition@@YAHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
