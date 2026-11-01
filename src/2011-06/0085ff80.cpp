// from server: 100% by auto
// roc 2011-06 0085ff80  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085ff80
//
// 0085ff80  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085ff84  85c9                 test ecx, ecx
// 0085ff86  7503                 jne 0x85ff8b
// 0085ff88  33c0                 xor eax, eax
// 0085ff8a  c3                   ret 
// 0085ff8b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085ff8f  8b01                 mov eax, dword ptr [ecx]
// 0085ff91  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085ff94  6a00                 push 0
// 0085ff96  52                   push edx
// 0085ff97  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff9b  6a0b                 push 0xb
// 0085ff9d  52                   push edx
// 0085ff9e  ffd0                 call eax
// 0085ffa0  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Bool@@YAHPAVCXTPPropExchange@@PBDAAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
