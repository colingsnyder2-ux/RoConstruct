// from server: 100% by auto
// roc 2011-06 00860070  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860070
//
// 00860070  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860074  85c9                 test ecx, ecx
// 00860076  7503                 jne 0x86007b
// 00860078  33c0                 xor eax, eax
// 0086007a  c3                   ret 
// 0086007b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086007f  8b01                 mov eax, dword ptr [ecx]
// 00860081  8b4058               mov eax, dword ptr [eax + 0x58]
// 00860084  6a00                 push 0
// 00860086  52                   push edx
// 00860087  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086008b  6a07                 push 7
// 0086008d  52                   push edx
// 0086008e  ffd0                 call eax
// 00860090  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_DateTime@@YAHPAVCXTPPropExchange@@PBDAAVCOleDateTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
