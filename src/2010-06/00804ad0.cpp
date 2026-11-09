// from server: 100% by auto
// roc 2010-06 00804ad0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804ad0
//
// 00804ad0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804ad4  85c9                 test ecx, ecx
// 00804ad6  7503                 jne 0x804adb
// 00804ad8  33c0                 xor eax, eax
// 00804ada  c3                   ret 
// 00804adb  8b01                 mov eax, dword ptr [ecx]
// 00804add  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804ae0  8d542410             lea edx, [esp + 0x10]
// 00804ae4  52                   push edx
// 00804ae5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804ae9  52                   push edx
// 00804aea  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804aee  6a0b                 push 0xb
// 00804af0  52                   push edx
// 00804af1  ffd0                 call eax
// 00804af3  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Bool@@YAHPAVCXTPPropExchange@@PBDAAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
