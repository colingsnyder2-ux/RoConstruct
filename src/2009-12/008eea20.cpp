// from server: 100% by auto
// roc 2009-12 008eea20  unit: CXTPRibbonBarMorePopupToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eea20
//
// 008eea20  8bc1                 mov eax, ecx
// 008eea22  33c9                 xor ecx, ecx
// 008eea24  c70070dda000         mov dword ptr [eax], 0xa0dd70
// 008eea2a  894808               mov dword ptr [eax + 8], ecx
// 008eea2d  89480c               mov dword ptr [eax + 0xc], ecx
// 008eea30  894810               mov dword ptr [eax + 0x10], ecx
// 008eea33  894814               mov dword ptr [eax + 0x14], ecx
// 008eea36  894804               mov dword ptr [eax + 4], ecx
// 008eea39  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ??0CXTPRibbonScrollableBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonPopups.cpp
