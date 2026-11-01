// from server: 100% by auto
// roc 2010-06 00804b60  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804b60
//
// 00804b60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804b64  85c9                 test ecx, ecx
// 00804b66  7503                 jne 0x804b6b
// 00804b68  33c0                 xor eax, eax
// 00804b6a  c3                   ret 
// 00804b6b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804b6f  8b01                 mov eax, dword ptr [ecx]
// 00804b71  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804b74  6a00                 push 0
// 00804b76  52                   push edx
// 00804b77  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804b7b  6a05                 push 5
// 00804b7d  52                   push edx
// 00804b7e  ffd0                 call eax
// 00804b80  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Double@@YAHPAVCXTPPropExchange@@PBDAAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
