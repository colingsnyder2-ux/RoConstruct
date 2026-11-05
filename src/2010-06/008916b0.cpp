// from server: 100% by auto
// roc 2010-06 008916b0  unit: CXTColorBase  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008916b0
//
// 008916b0  8b442404             mov eax, dword ptr [esp + 4]
// 008916b4  0fb6d0               movzx edx, al
// 008916b7  899168070000         mov dword ptr [ecx + 0x768], edx
// 008916bd  8bd0                 mov edx, eax
// 008916bf  c1ea08               shr edx, 8
// 008916c2  c1e810               shr eax, 0x10
// 008916c5  0fb6d2               movzx edx, dl
// 008916c8  0fb6c0               movzx eax, al
// 008916cb  899170070000         mov dword ptr [ecx + 0x770], edx
// 008916d1  89816c070000         mov dword ptr [ecx + 0x76c], eax
// 008916d7  c744240400000000     mov dword ptr [esp + 4], 0
// 008916df  e94465f1ff           jmp 0x7a7c28
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?UpdateRGB@CXTColorPageCustom@@IAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
