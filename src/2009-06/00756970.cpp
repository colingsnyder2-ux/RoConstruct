// from server: 100% by auto
// roc 2009-06 00756970  unit: CXTTreeBase  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756970
//
// 00756970  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00756973  e864550f00           call 0x84bedc
// 00756978  2408                 and al, 8
// 0075697a  33c9                 xor ecx, ecx
// 0075697c  3c08                 cmp al, 8
// 0075697e  0f94c1               sete cl
// 00756981  8ac1                 mov al, cl
// 00756983  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?HasEditLabels@CXTPTreeBase@@IBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
