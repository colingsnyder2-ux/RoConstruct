// from server: 100% by auto
// roc 2009-06 0077ee60  unit: CSelectionCaption  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ee60
//
// 0077ee60  8bc1                 mov eax, ecx
// 0077ee62  33c9                 xor ecx, ecx
// 0077ee64  c700fccc8f00         mov dword ptr [eax], 0x8fccfc
// 0077ee6a  894804               mov dword ptr [eax + 4], ecx
// 0077ee6d  894808               mov dword ptr [eax + 8], ecx
// 0077ee70  894810               mov dword ptr [eax + 0x10], ecx
// 0077ee73  c7400c64f68a00       mov dword ptr [eax + 0xc], 0x8af664
// 0077ee7a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
