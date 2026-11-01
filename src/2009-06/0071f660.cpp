// from server: 100% by auto
// roc 2009-06 0071f660  unit: CRobloxControlColorSelector  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071f660
//
// 0071f660  8b01                 mov eax, dword ptr [ecx]
// 0071f662  8b90b8000000         mov edx, dword ptr [eax + 0xb8]
// 0071f668  6a00                 push 0
// 0071f66a  ffd2                 call edx
// 0071f66c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnRemoved@CXTPControl@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
