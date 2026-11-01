// from server: 100% by auto
// roc 2011-06 00865d00  unit: CXTPTabClientWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00865d00
//
// 00865d00  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 00865d06  85c0                 test eax, eax
// 00865d08  7501                 jne 0x865d0b
// 00865d0a  c3                   ret 
// 00865d0b  8b80ec000000         mov eax, dword ptr [eax + 0xec]
// 00865d11  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetCommandBars@CXTPTabClientWnd@@UBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
