// from server: 100% by auto
// roc 2010-06 0080de90  unit: CSelectionCaption  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080de90
//
// 0080de90  8bc1                 mov eax, ecx
// 0080de92  33c9                 xor ecx, ecx
// 0080de94  c7006414a600         mov dword ptr [eax], 0xa61464
// 0080de9a  894804               mov dword ptr [eax + 4], ecx
// 0080de9d  894808               mov dword ptr [eax + 8], ecx
// 0080dea0  894810               mov dword ptr [eax + 0x10], ecx
// 0080dea3  c7400ca02ea000       mov dword ptr [eax + 0xc], 0xa02ea0
// 0080deaa  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
