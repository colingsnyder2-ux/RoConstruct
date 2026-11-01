// from server: 100% by auto
// roc 2009-12 008418c0  unit: CXTPCustomizeCommandsPage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008418c0
//
// 008418c0  8b442404             mov eax, dword ptr [esp + 4]
// 008418c4  83f804               cmp eax, 4
// 008418c7  740d                 je 0x8418d6
// 008418c9  83f803               cmp eax, 3
// 008418cc  7408                 je 0x8418d6
// 008418ce  83f802               cmp eax, 2
// 008418d1  7403                 je 0x8418d6
// 008418d3  33c0                 xor eax, eax
// 008418d5  c3                   ret 
// 008418d6  b801000000           mov eax, 1
// 008418db  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?IsAnimateType@@YAHW4XTPAnimationType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
