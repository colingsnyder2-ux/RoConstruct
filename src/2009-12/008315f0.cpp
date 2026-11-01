// from server: 100% by auto
// roc 2009-12 008315f0  unit: CXTPColorManager  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008315f0
//
// 008315f0  8b442408             mov eax, dword ptr [esp + 8]
// 008315f4  c70000000000         mov dword ptr [eax], 0
// 008315fa  c7411000000000       mov dword ptr [ecx + 0x10], 0
// 00831601  33c0                 xor eax, eax
// 00831603  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnEndLabelEdit@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
