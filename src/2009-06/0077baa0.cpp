// from server: 100% by auto
// roc 2009-06 0077baa0  unit: CXTPTabClientWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077baa0
//
// 0077baa0  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 0077baa6  85c0                 test eax, eax
// 0077baa8  7501                 jne 0x77baab
// 0077baaa  c3                   ret 
// 0077baab  8b80ec000000         mov eax, dword ptr [eax + 0xec]
// 0077bab1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetCommandBars@CXTPTabClientWnd@@UBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
