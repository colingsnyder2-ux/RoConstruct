// from server: 100% by auto
// roc 2009-12 00833060  unit: CXTTreeBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833060
//
// 00833060  8b4134               mov eax, dword ptr [ecx + 0x34]
// 00833063  85c0                 test eax, eax
// 00833065  750d                 jne 0x833074
// 00833067  50                   push eax
// 00833068  ff1584cc9800         call dword ptr [0x98cc84]
// 0083306e  85c0                 test eax, eax
// 00833070  0f95c0               setne al
// 00833073  c3                   ret 
// 00833074  8b4020               mov eax, dword ptr [eax + 0x20]
// 00833077  50                   push eax
// 00833078  ff1584cc9800         call dword ptr [0x98cc84]
// 0083307e  85c0                 test eax, eax
// 00833080  0f95c0               setne al
// 00833083  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Init@CXTPTreeBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
