// from server: 100% by auto
// roc 2009-12 00814ce0  unit: CXTPCommandBarKeyboardTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814ce0
//
// 00814ce0  8b442404             mov eax, dword ptr [esp + 4]
// 00814ce4  85c0                 test eax, eax
// 00814ce6  7c14                 jl 0x814cfc
// 00814ce8  3b8184000000         cmp eax, dword ptr [ecx + 0x84]
// 00814cee  7d0c                 jge 0x814cfc
// 00814cf0  8b8980000000         mov ecx, dword ptr [ecx + 0x80]
// 00814cf6  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00814cf9  c20400               ret 4
// 00814cfc  33c0                 xor eax, eax
// 00814cfe  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPCommandBars@@QBEPAVCXTPToolBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
