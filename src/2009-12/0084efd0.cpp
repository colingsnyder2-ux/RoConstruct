// from server: 100% by auto
// roc 2009-12 0084efd0  unit: CXTPPropertyGrid  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084efd0
//
// 0084efd0  85c9                 test ecx, ecx
// 0084efd2  7417                 je 0x84efeb
// 0084efd4  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084efd7  85c0                 test eax, eax
// 0084efd9  7410                 je 0x84efeb
// 0084efdb  6885010000           push 0x185
// 0084efe0  6a00                 push 0
// 0084efe2  6a00                 push 0
// 0084efe4  50                   push eax
// 0084efe5  ff151ccb9800         call dword ptr [0x98cb1c]
// 0084efeb  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?RedrawControl@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
