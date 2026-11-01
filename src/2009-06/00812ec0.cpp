// from server: 100% by auto
// roc 2009-06 00812ec0  unit: CXTPRibbonBarMorePopupToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00812ec0
//
// 00812ec0  8bc1                 mov eax, ecx
// 00812ec2  33c9                 xor ecx, ecx
// 00812ec4  c70008d09000         mov dword ptr [eax], 0x90d008
// 00812eca  894808               mov dword ptr [eax + 8], ecx
// 00812ecd  89480c               mov dword ptr [eax + 0xc], ecx
// 00812ed0  894810               mov dword ptr [eax + 0x10], ecx
// 00812ed3  894814               mov dword ptr [eax + 0x14], ecx
// 00812ed6  894804               mov dword ptr [eax + 4], ecx
// 00812ed9  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ??0CXTPRibbonScrollableBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonPopups.cpp
