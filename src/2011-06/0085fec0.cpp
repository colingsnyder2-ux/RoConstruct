// from server: 100% by auto
// roc 2011-06 0085fec0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085fec0
//
// 0085fec0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085fec4  85c9                 test ecx, ecx
// 0085fec6  7503                 jne 0x85fecb
// 0085fec8  33c0                 xor eax, eax
// 0085feca  c3                   ret 
// 0085fecb  8b01                 mov eax, dword ptr [ecx]
// 0085fecd  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085fed0  8d542410             lea edx, [esp + 0x10]
// 0085fed4  52                   push edx
// 0085fed5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085fed9  52                   push edx
// 0085feda  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085fede  6a11                 push 0x11
// 0085fee0  52                   push edx
// 0085fee1  ffd0                 call eax
// 0085fee3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Byte@@YAHPAVCXTPPropExchange@@PBDAAEE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
