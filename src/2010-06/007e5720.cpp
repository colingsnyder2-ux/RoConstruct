// from server: 100% by auto
// roc 2010-06 007e5720  unit: CXTPColorManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5720
//
// 007e5720  8b442408             mov eax, dword ptr [esp + 8]
// 007e5724  8b542404             mov edx, dword ptr [esp + 4]
// 007e5728  c70000000000         mov dword ptr [eax], 0
// 007e572e  8b4210               mov eax, dword ptr [edx + 0x10]
// 007e5731  894110               mov dword ptr [ecx + 0x10], eax
// 007e5734  33c0                 xor eax, eax
// 007e5736  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnBeginLabelEdit@CXTTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
