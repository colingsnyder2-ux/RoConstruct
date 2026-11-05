// from server: 100% by auto
// roc 2010-06 00882180  unit: CXTPTabManagerItem  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882180
//
// 00882180  83796000             cmp dword ptr [ecx + 0x60], 0
// 00882184  740a                 je 0x882190
// 00882186  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 00882189  8b01                 mov eax, dword ptr [ecx]
// 0088218b  8b5004               mov edx, dword ptr [eax + 4]
// 0088218e  ffe2                 jmp edx
// 00882190  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?Reposition@CXTPTabManagerItem@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
