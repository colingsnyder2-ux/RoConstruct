// from server: 100% by auto
// roc 2007-03 00688150  unit: seg_00680000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00688150
//
// 00688150  56                   push esi
// 00688151  8bf1                 mov esi, ecx
// 00688153  8b4620               mov eax, dword ptr [esi + 0x20]
// 00688156  85c0                 test eax, eax
// 00688158  741a                 je 0x688174
// 0068815a  6a00                 push 0
// 0068815c  6a00                 push 0
// 0068815e  6888010000           push 0x188
// 00688163  50                   push eax
// 00688164  ff1550ee7700         call dword ptr [0x77ee50]
// 0068816a  50                   push eax
// 0068816b  8bce                 mov ecx, esi
// 0068816d  e88efdffff           call 0x687f00
// 00688172  5e                   pop esi
// 00688173  c3                   ret 
// 00688174  33c0                 xor eax, eax
// 00688176  5e                   pop esi
// 00688177  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetSelectedItem@CXTPPropertyGridView@@AAEPAVCXTPPropertyGridItem@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
