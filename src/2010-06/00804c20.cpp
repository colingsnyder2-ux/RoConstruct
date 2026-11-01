// from server: 100% by auto
// roc 2010-06 00804c20  unit: CXTCaptionButtonTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804c20
//
// 00804c20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804c24  85c9                 test ecx, ecx
// 00804c26  7503                 jne 0x804c2b
// 00804c28  33c0                 xor eax, eax
// 00804c2a  c3                   ret 
// 00804c2b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c2f  8b01                 mov eax, dword ptr [ecx]
// 00804c31  8b4060               mov eax, dword ptr [eax + 0x60]
// 00804c34  52                   push edx
// 00804c35  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c39  52                   push edx
// 00804c3a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c3e  52                   push edx
// 00804c3f  ffd0                 call eax
// 00804c41  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_RuntimeClass@@YAHPAVCXTPPropExchange@@PBDAAPAUCRuntimeClass@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
