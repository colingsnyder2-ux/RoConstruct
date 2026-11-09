// from server: 100% by auto
// roc 2011-06 0086b650  unit: VAuthoringSettings::?$FactoryProduct  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086b650
//
// 0086b650  8bc1                 mov eax, ecx
// 0086b652  33c9                 xor ecx, ecx
// 0086b654  c70044bdac00         mov dword ptr [eax], 0xacbd44
// 0086b65a  894804               mov dword ptr [eax + 4], ecx
// 0086b65d  894808               mov dword ptr [eax + 8], ecx
// 0086b660  894810               mov dword ptr [eax + 0x10], ecx
// 0086b663  c7400c90e7a500       mov dword ptr [eax + 0xc], 0xa5e790
// 0086b66a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
