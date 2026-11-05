// from server: 100% by auto
// roc 2010-06 008a2c00  unit: CXTPRibbonBarMorePopupToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a2c00
//
// 008a2c00  8bc1                 mov eax, ecx
// 008a2c02  33c9                 xor ecx, ecx
// 008a2c04  c7006820a700         mov dword ptr [eax], 0xa72068
// 008a2c0a  894808               mov dword ptr [eax + 8], ecx
// 008a2c0d  89480c               mov dword ptr [eax + 0xc], ecx
// 008a2c10  894810               mov dword ptr [eax + 0x10], ecx
// 008a2c13  894814               mov dword ptr [eax + 0x14], ecx
// 008a2c16  894804               mov dword ptr [eax + 4], ecx
// 008a2c19  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ??0CXTPRibbonScrollableBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPopups.cpp
