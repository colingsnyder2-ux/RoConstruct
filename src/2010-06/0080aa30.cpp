// from server: 100% by auto
// roc 2010-06 0080aa30  unit: CXTPTabClientWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080aa30
//
// 0080aa30  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 0080aa36  85c0                 test eax, eax
// 0080aa38  7501                 jne 0x80aa3b
// 0080aa3a  c3                   ret 
// 0080aa3b  8b80ec000000         mov eax, dword ptr [eax + 0xec]
// 0080aa41  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetCommandBars@CXTPTabClientWnd@@UBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
