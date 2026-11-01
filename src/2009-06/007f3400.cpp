// from server: 100% by auto
// roc 2009-06 007f3400  unit: CXTPTabManagerItem  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3400
//
// 007f3400  83796000             cmp dword ptr [ecx + 0x60], 0
// 007f3404  740a                 je 0x7f3410
// 007f3406  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 007f3409  8b01                 mov eax, dword ptr [ecx]
// 007f340b  8b5004               mov edx, dword ptr [eax + 4]
// 007f340e  ffe2                 jmp edx
// 007f3410  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?Reposition@CXTPTabManagerItem@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
