// from server: 100% by auto
// roc 2010-06 007e5970  unit: CXTTreeBase  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5970
//
// 007e5970  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e5973  e866741900           call 0x97cdde
// 007e5978  2408                 and al, 8
// 007e597a  33c9                 xor ecx, ecx
// 007e597c  3c08                 cmp al, 8
// 007e597e  0f94c1               sete cl
// 007e5981  8ac1                 mov al, cl
// 007e5983  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?HasEditLabels@CXTTreeBase@@IBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
