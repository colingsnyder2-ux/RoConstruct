// from server: 100% by auto
// roc 2010-06 00803030  unit: CXTPPropertyGrid  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803030
//
// 00803030  85c9                 test ecx, ecx
// 00803032  7417                 je 0x80304b
// 00803034  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00803037  85c0                 test eax, eax
// 00803039  7410                 je 0x80304b
// 0080303b  6885010000           push 0x185
// 00803040  6a00                 push 0
// 00803042  6a00                 push 0
// 00803044  50                   push eax
// 00803045  ff15d4b99e00         call dword ptr [0x9eb9d4]
// 0080304b  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?RedrawControl@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
