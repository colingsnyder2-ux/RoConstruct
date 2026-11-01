// from server: 100% by auto
// roc 2007-03 006511c0  unit: seg_00650000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006511c0
//
// 006511c0  8b442408             mov eax, dword ptr [esp + 8]
// 006511c4  c70000000000         mov dword ptr [eax], 0
// 006511ca  c7411000000000       mov dword ptr [ecx + 0x10], 0
// 006511d1  33c0                 xor eax, eax
// 006511d3  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnEndLabelEdit@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
