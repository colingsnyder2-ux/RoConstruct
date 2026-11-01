// from server: 100% by auto
// roc 2011-06 0085fef0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085fef0
//
// 0085fef0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085fef4  85c9                 test ecx, ecx
// 0085fef6  7503                 jne 0x85fefb
// 0085fef8  33c0                 xor eax, eax
// 0085fefa  c3                   ret 
// 0085fefb  8b01                 mov eax, dword ptr [ecx]
// 0085fefd  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085ff00  8d542410             lea edx, [esp + 0x10]
// 0085ff04  52                   push edx
// 0085ff05  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff09  52                   push edx
// 0085ff0a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff0e  6a02                 push 2
// 0085ff10  52                   push edx
// 0085ff11  ffd0                 call eax
// 0085ff13  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Short@@YAHPAVCXTPPropExchange@@PBDAAFF@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
