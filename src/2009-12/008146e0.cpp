// from server: 100% by auto
// roc 2009-12 008146e0  unit: MyXTPCommandBars  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008146e0
//
// 008146e0  8b4150               mov eax, dword ptr [ecx + 0x50]
// 008146e3  85c0                 test eax, eax
// 008146e5  7516                 jne 0x8146fd
// 008146e7  3905a4adb900         cmp dword ptr [0xb9ada4], eax
// 008146ed  7509                 jne 0x8146f8
// 008146ef  50                   push eax
// 008146f0  e86b9ffeff           call 0x7fe660
// 008146f5  83c404               add esp, 4
// 008146f8  a1a4adb900           mov eax, dword ptr [0xb9ada4]
// 008146fd  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetPaintManager@CXTPCommandBars@@QBEPAVCXTPPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
