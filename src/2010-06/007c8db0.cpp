// from server: 100% by auto
// roc 2010-06 007c8db0  unit: CXTPCommandBarKeyboardTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8db0
//
// 007c8db0  8b442404             mov eax, dword ptr [esp + 4]
// 007c8db4  85c0                 test eax, eax
// 007c8db6  7c14                 jl 0x7c8dcc
// 007c8db8  3b8184000000         cmp eax, dword ptr [ecx + 0x84]
// 007c8dbe  7d0c                 jge 0x7c8dcc
// 007c8dc0  8b8980000000         mov ecx, dword ptr [ecx + 0x80]
// 007c8dc6  8b0481               mov eax, dword ptr [ecx + eax*4]
// 007c8dc9  c20400               ret 4
// 007c8dcc  33c0                 xor eax, eax
// 007c8dce  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPCommandBars@@QBEPAVCXTPToolBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
