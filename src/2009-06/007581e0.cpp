// from server: 100% by auto
// roc 2009-06 007581e0  unit: CXTTreeBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007581e0
//
// 007581e0  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007581e3  85c0                 test eax, eax
// 007581e5  750d                 jne 0x7581f4
// 007581e7  50                   push eax
// 007581e8  ff15e0ed8900         call dword ptr [0x89ede0]
// 007581ee  85c0                 test eax, eax
// 007581f0  0f95c0               setne al
// 007581f3  c3                   ret 
// 007581f4  8b4020               mov eax, dword ptr [eax + 0x20]
// 007581f7  50                   push eax
// 007581f8  ff15e0ed8900         call dword ptr [0x89ede0]
// 007581fe  85c0                 test eax, eax
// 00758200  0f95c0               setne al
// 00758203  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Init@CXTPTreeBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
