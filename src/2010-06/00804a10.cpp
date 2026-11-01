// from server: 100% by auto
// roc 2010-06 00804a10  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804a10
//
// 00804a10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804a14  85c9                 test ecx, ecx
// 00804a16  7503                 jne 0x804a1b
// 00804a18  33c0                 xor eax, eax
// 00804a1a  c3                   ret 
// 00804a1b  8b01                 mov eax, dword ptr [ecx]
// 00804a1d  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804a20  8d542410             lea edx, [esp + 0x10]
// 00804a24  52                   push edx
// 00804a25  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804a29  52                   push edx
// 00804a2a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804a2e  6a02                 push 2
// 00804a30  52                   push edx
// 00804a31  ffd0                 call eax
// 00804a33  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Short@@YAHPAVCXTPPropExchange@@PBDAAFF@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
