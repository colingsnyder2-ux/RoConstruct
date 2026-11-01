// from server: 100% by auto
// roc 2009-12 008315d0  unit: CXTPColorManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008315d0
//
// 008315d0  8b442408             mov eax, dword ptr [esp + 8]
// 008315d4  8b542404             mov edx, dword ptr [esp + 4]
// 008315d8  c70000000000         mov dword ptr [eax], 0
// 008315de  8b4210               mov eax, dword ptr [edx + 0x10]
// 008315e1  894110               mov dword ptr [ecx + 0x10], eax
// 008315e4  33c0                 xor eax, eax
// 008315e6  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnBeginLabelEdit@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
