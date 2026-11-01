// from server: 100% by auto
// roc 2007-03 00652bb0  unit: seg_00650000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652bb0
//
// 00652bb0  8b4134               mov eax, dword ptr [ecx + 0x34]
// 00652bb3  85c0                 test eax, eax
// 00652bb5  750d                 jne 0x652bc4
// 00652bb7  50                   push eax
// 00652bb8  ff1574ed7700         call dword ptr [0x77ed74]
// 00652bbe  85c0                 test eax, eax
// 00652bc0  0f95c0               setne al
// 00652bc3  c3                   ret 
// 00652bc4  8b4020               mov eax, dword ptr [eax + 0x20]
// 00652bc7  50                   push eax
// 00652bc8  ff1574ed7700         call dword ptr [0x77ed74]
// 00652bce  85c0                 test eax, eax
// 00652bd0  0f95c0               setne al
// 00652bd3  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Init@CXTPTreeBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
