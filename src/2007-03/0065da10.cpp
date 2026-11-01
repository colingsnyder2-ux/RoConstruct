// from server: 100% by auto
// roc 2007-03 0065da10  unit: seg_00650000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065da10
//
// 0065da10  85c9                 test ecx, ecx
// 0065da12  7417                 je 0x65da2b
// 0065da14  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0065da17  85c0                 test eax, eax
// 0065da19  7410                 je 0x65da2b
// 0065da1b  6885010000           push 0x185
// 0065da20  6a00                 push 0
// 0065da22  6a00                 push 0
// 0065da24  50                   push eax
// 0065da25  ff1518ef7700         call dword ptr [0x77ef18]
// 0065da2b  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?RedrawControl@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
