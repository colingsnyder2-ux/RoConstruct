// from server: 100% by auto
// roc 2007-08 00639d70  unit: CRobloxControlColorSelector  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00639d70
//
// 00639d70  8b01                 mov eax, dword ptr [ecx]
// 00639d72  8b90b8000000         mov edx, dword ptr [eax + 0xb8]
// 00639d78  6a00                 push 0
// 00639d7a  ffd2                 call edx
// 00639d7c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnRemoved@CXTPControl@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
