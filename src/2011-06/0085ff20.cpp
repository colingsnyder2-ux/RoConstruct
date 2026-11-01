// from server: 100% by auto
// roc 2011-06 0085ff20  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085ff20
//
// 0085ff20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085ff24  85c9                 test ecx, ecx
// 0085ff26  7503                 jne 0x85ff2b
// 0085ff28  33c0                 xor eax, eax
// 0085ff2a  c3                   ret 
// 0085ff2b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085ff2f  8b01                 mov eax, dword ptr [ecx]
// 0085ff31  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085ff34  6a00                 push 0
// 0085ff36  52                   push edx
// 0085ff37  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ff3b  6a03                 push 3
// 0085ff3d  52                   push edx
// 0085ff3e  ffd0                 call eax
// 0085ff40  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Long@@YAHPAVCXTPPropExchange@@PBDAAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
