// from server: 100% by auto
// roc 2010-06 007c87c0  unit: MyXTPCommandBars  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c87c0
//
// 007c87c0  8b4150               mov eax, dword ptr [ecx + 0x50]
// 007c87c3  85c0                 test eax, eax
// 007c87c5  7516                 jne 0x7c87dd
// 007c87c7  3905b054c200         cmp dword ptr [0xc254b0], eax
// 007c87cd  7509                 jne 0x7c87d8
// 007c87cf  50                   push eax
// 007c87d0  e89b59feff           call 0x7ae170
// 007c87d5  83c404               add esp, 4
// 007c87d8  a1b054c200           mov eax, dword ptr [0xc254b0]
// 007c87dd  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetPaintManager@CXTPCommandBars@@QBEPAVCXTPPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
