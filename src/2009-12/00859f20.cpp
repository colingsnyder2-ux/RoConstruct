// from server: 100% by auto
// roc 2009-12 00859f20  unit: CSelectionCaption  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859f20
//
// 00859f20  8bc1                 mov eax, ecx
// 00859f22  33c9                 xor ecx, ecx
// 00859f24  c700a4d19f00         mov dword ptr [eax], 0x9fd1a4
// 00859f2a  894804               mov dword ptr [eax + 4], ecx
// 00859f2d  894808               mov dword ptr [eax + 8], ecx
// 00859f30  894810               mov dword ptr [eax + 0x10], ecx
// 00859f33  c7400c18229a00       mov dword ptr [eax + 0xc], 0x9a2218
// 00859f3a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
