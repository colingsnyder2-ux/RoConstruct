// from server: 100% by auto
// roc 2009-12 00856b00  unit: CXTPTabClientWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856b00
//
// 00856b00  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 00856b06  85c0                 test eax, eax
// 00856b08  7501                 jne 0x856b0b
// 00856b0a  c3                   ret 
// 00856b0b  8b80ec000000         mov eax, dword ptr [eax + 0xec]
// 00856b11  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetCommandBars@CXTPTabClientWnd@@UBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
