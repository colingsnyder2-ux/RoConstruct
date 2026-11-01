// from server: 100% by auto
// roc 2011-06 0085ff50  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085ff50
//
// 0085ff50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085ff54  85c9                 test ecx, ecx
// 0085ff56  7503                 jne 0x85ff5b
// 0085ff58  33c0                 xor eax, eax
// 0085ff5a  c3                   ret 
// 0085ff5b  8b01                 mov eax, dword ptr [ecx]
// 0085ff5d  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085ff60  8d542410             lea edx, [esp + 0x10]
// 0085ff64  52                   push edx
// 0085ff65  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff69  52                   push edx
// 0085ff6a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff6e  6a03                 push 3
// 0085ff70  52                   push edx
// 0085ff71  ffd0                 call eax
// 0085ff73  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Long@@YAHPAVCXTPPropExchange@@PBDAAJJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
