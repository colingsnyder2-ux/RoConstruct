// from server: 100% by auto
// roc 2011-06 00860010  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860010
//
// 00860010  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860014  85c9                 test ecx, ecx
// 00860016  7503                 jne 0x86001b
// 00860018  33c0                 xor eax, eax
// 0086001a  c3                   ret 
// 0086001b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086001f  8b01                 mov eax, dword ptr [ecx]
// 00860021  8b4058               mov eax, dword ptr [eax + 0x58]
// 00860024  52                   push edx
// 00860025  8b542410             mov edx, dword ptr [esp + 0x10]
// 00860029  52                   push edx
// 0086002a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086002e  6a1e                 push 0x1e
// 00860030  52                   push edx
// 00860031  ffd0                 call eax
// 00860033  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_String@@YAHPAVCXTPPropExchange@@PBDAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
