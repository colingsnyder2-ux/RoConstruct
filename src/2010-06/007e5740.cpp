// from server: 100% by auto
// roc 2010-06 007e5740  unit: CXTPColorManager  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5740
//
// 007e5740  8b442408             mov eax, dword ptr [esp + 8]
// 007e5744  c70000000000         mov dword ptr [eax], 0
// 007e574a  c7411000000000       mov dword ptr [ecx + 0x10], 0
// 007e5751  33c0                 xor eax, eax
// 007e5753  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnEndLabelEdit@CXTTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
