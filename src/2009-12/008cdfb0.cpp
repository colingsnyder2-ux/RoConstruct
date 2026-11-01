// from server: 100% by auto
// roc 2009-12 008cdfb0  unit: CXTPTabManagerItem  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cdfb0
//
// 008cdfb0  83796000             cmp dword ptr [ecx + 0x60], 0
// 008cdfb4  740a                 je 0x8cdfc0
// 008cdfb6  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 008cdfb9  8b01                 mov eax, dword ptr [ecx]
// 008cdfbb  8b5004               mov edx, dword ptr [eax + 4]
// 008cdfbe  ffe2                 jmp edx
// 008cdfc0  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?Reposition@CXTPTabManagerItem@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
