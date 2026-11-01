// from server: 100% by auto
// roc 2010-06 00804b00  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804b00
//
// 00804b00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804b04  85c9                 test ecx, ecx
// 00804b06  7503                 jne 0x804b0b
// 00804b08  33c0                 xor eax, eax
// 00804b0a  c3                   ret 
// 00804b0b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804b0f  8b01                 mov eax, dword ptr [ecx]
// 00804b11  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804b14  6a00                 push 0
// 00804b16  52                   push edx
// 00804b17  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804b1b  6a1e                 push 0x1e
// 00804b1d  52                   push edx
// 00804b1e  ffd0                 call eax
// 00804b20  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_String@@YAHPAVCXTPPropExchange@@PBDAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
