// from server: 100% by auto
// roc 2010-06 00804b30  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804b30
//
// 00804b30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804b34  85c9                 test ecx, ecx
// 00804b36  7503                 jne 0x804b3b
// 00804b38  33c0                 xor eax, eax
// 00804b3a  c3                   ret 
// 00804b3b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804b3f  8b01                 mov eax, dword ptr [ecx]
// 00804b41  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804b44  52                   push edx
// 00804b45  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804b49  52                   push edx
// 00804b4a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804b4e  6a1e                 push 0x1e
// 00804b50  52                   push edx
// 00804b51  ffd0                 call eax
// 00804b53  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_String@@YAHPAVCXTPPropExchange@@PBDAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
