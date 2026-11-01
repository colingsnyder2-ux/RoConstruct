// from server: 100% by auto
// roc 2007-03 0067b380  unit: seg_00670000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b380
//
// 0067b380  8bc1                 mov eax, ecx
// 0067b382  33c9                 xor ecx, ecx
// 0067b384  c7009cd47c00         mov dword ptr [eax], 0x7cd49c
// 0067b38a  894804               mov dword ptr [eax + 4], ecx
// 0067b38d  894808               mov dword ptr [eax + 8], ecx
// 0067b390  894810               mov dword ptr [eax + 0x10], ecx
// 0067b393  c7400c80747800       mov dword ptr [eax + 0xc], 0x787480
// 0067b39a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
