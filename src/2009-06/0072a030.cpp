// from server: 100% by auto
// roc 2009-06 0072a030  unit: CXTPCommandBarKeyboardTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072a030
//
// 0072a030  8b442404             mov eax, dword ptr [esp + 4]
// 0072a034  85c0                 test eax, eax
// 0072a036  7c14                 jl 0x72a04c
// 0072a038  3b8184000000         cmp eax, dword ptr [ecx + 0x84]
// 0072a03e  7d0c                 jge 0x72a04c
// 0072a040  8b8980000000         mov ecx, dword ptr [ecx + 0x80]
// 0072a046  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0072a049  c20400               ret 4
// 0072a04c  33c0                 xor eax, eax
// 0072a04e  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPCommandBars@@QBEPAVCXTPToolBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
