// from server: 100% by auto
// roc 2009-12 0088d330  unit: CXTPControlEditCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088d330
//
// 0088d330  83791400             cmp dword ptr [ecx + 0x14], 0
// 0088d334  7513                 jne 0x88d349
// 0088d336  8b09                 mov ecx, dword ptr [ecx]
// 0088d338  e85372f7ff           call 0x804590
// 0088d33d  83b88800000000       cmp dword ptr [eax + 0x88], 0
// 0088d344  7503                 jne 0x88d349
// 0088d346  33c0                 xor eax, eax
// 0088d348  c3                   ret 
// 0088d349  b801000000           mov eax, 1
// 0088d34e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?IsAnimationEnabled@CXTPCommandBarAnimation@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
