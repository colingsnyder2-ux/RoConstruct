// from server: 100% by auto
// roc 2010-06 0041cfa0  unit: CSettingsExplorer  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041cfa0
//
// 0041cfa0  0fb7442404           movzx eax, word ptr [esp + 4]
// 0041cfa5  56                   push esi
// 0041cfa6  50                   push eax
// 0041cfa7  6a04                 push 4
// 0041cfa9  50                   push eax
// 0041cfaa  8bf1                 mov esi, ecx
// 0041cfac  e86db33800           call 0x7a831e
// 0041cfb1  50                   push eax
// 0041cfb2  ff1560bc9e00         call dword ptr [0x9ebc60]
// 0041cfb8  50                   push eax
// 0041cfb9  8bce                 mov ecx, esi
// 0041cfbb  e858b33800           call 0x7a8318
// 0041cfc0  5e                   pop esi
// 0041cfc1  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?LoadMenuA@CMenu@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
