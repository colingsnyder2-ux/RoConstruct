// from server: 100% by auto
// roc 2010-06 00804a40  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804a40
//
// 00804a40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804a44  85c9                 test ecx, ecx
// 00804a46  7503                 jne 0x804a4b
// 00804a48  33c0                 xor eax, eax
// 00804a4a  c3                   ret 
// 00804a4b  8b01                 mov eax, dword ptr [ecx]
// 00804a4d  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804a50  8d542410             lea edx, [esp + 0x10]
// 00804a54  52                   push edx
// 00804a55  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804a59  52                   push edx
// 00804a5a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804a5e  6a03                 push 3
// 00804a60  52                   push edx
// 00804a61  ffd0                 call eax
// 00804a63  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Long@@YAHPAVCXTPPropExchange@@PBDAAJJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
