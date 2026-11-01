// from server: 100% by auto
// roc 2007-03 006513f0  unit: seg_00650000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006513f0
//
// 006513f0  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 006513f3  e8cc970e00           call 0x73abc4
// 006513f8  2408                 and al, 8
// 006513fa  33c9                 xor ecx, ecx
// 006513fc  3c08                 cmp al, 8
// 006513fe  0f94c1               sete cl
// 00651401  8ac1                 mov al, cl
// 00651403  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?HasEditLabels@CXTPTreeBase@@IBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
