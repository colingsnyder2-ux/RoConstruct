// from server: 100% by auto
// roc 2011-06 00860040  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860040
//
// 00860040  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860044  85c9                 test ecx, ecx
// 00860046  7503                 jne 0x86004b
// 00860048  33c0                 xor eax, eax
// 0086004a  c3                   ret 
// 0086004b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086004f  8b01                 mov eax, dword ptr [ecx]
// 00860051  8b4058               mov eax, dword ptr [eax + 0x58]
// 00860054  6a00                 push 0
// 00860056  52                   push edx
// 00860057  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086005b  6a05                 push 5
// 0086005d  52                   push edx
// 0086005e  ffd0                 call eax
// 00860060  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Double@@YAHPAVCXTPPropExchange@@PBDAAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
