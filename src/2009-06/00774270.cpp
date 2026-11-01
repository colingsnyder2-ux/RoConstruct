// from server: 100% by auto
// roc 2009-06 00774270  unit: CXTPPropertyGrid  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00774270
//
// 00774270  85c9                 test ecx, ecx
// 00774272  7417                 je 0x77428b
// 00774274  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00774277  85c0                 test eax, eax
// 00774279  7410                 je 0x77428b
// 0077427b  6885010000           push 0x185
// 00774280  6a00                 push 0
// 00774282  6a00                 push 0
// 00774284  50                   push eax
// 00774285  ff15e8ee8900         call dword ptr [0x89eee8]
// 0077428b  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?RedrawControl@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
