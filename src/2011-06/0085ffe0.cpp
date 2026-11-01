// from server: 100% by auto
// roc 2011-06 0085ffe0  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085ffe0
//
// 0085ffe0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085ffe4  85c9                 test ecx, ecx
// 0085ffe6  7503                 jne 0x85ffeb
// 0085ffe8  33c0                 xor eax, eax
// 0085ffea  c3                   ret 
// 0085ffeb  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085ffef  8b01                 mov eax, dword ptr [ecx]
// 0085fff1  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085fff4  6a00                 push 0
// 0085fff6  52                   push edx
// 0085fff7  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085fffb  6a1e                 push 0x1e
// 0085fffd  52                   push edx
// 0085fffe  ffd0                 call eax
// 00860000  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_String@@YAHPAVCXTPPropExchange@@PBDAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
