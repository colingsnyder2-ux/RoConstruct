// from server: 100% by auto
// roc 2007-03 006511a0  unit: seg_00650000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006511a0
//
// 006511a0  8b442408             mov eax, dword ptr [esp + 8]
// 006511a4  8b542404             mov edx, dword ptr [esp + 4]
// 006511a8  c70000000000         mov dword ptr [eax], 0
// 006511ae  8b4210               mov eax, dword ptr [edx + 0x10]
// 006511b1  894110               mov dword ptr [ecx + 0x10], eax
// 006511b4  33c0                 xor eax, eax
// 006511b6  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnBeginLabelEdit@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
