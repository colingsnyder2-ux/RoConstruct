// from server: 100% by auto
// roc 2007-08 006c8c30  unit: CXTPControlEditCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006c8c30
//
// 006c8c30  83791400             cmp dword ptr [ecx + 0x14], 0
// 006c8c34  7513                 jne 0x6c8c49
// 006c8c36  8b09                 mov ecx, dword ptr [ecx]
// 006c8c38  e803aef7ff           call 0x643a40
// 006c8c3d  83b88400000000       cmp dword ptr [eax + 0x84], 0
// 006c8c44  7503                 jne 0x6c8c49
// 006c8c46  33c0                 xor eax, eax
// 006c8c48  c3                   ret 
// 006c8c49  b801000000           mov eax, 1
// 006c8c4e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?IsAnimationEnabled@CXTPCommandBarAnimation@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
