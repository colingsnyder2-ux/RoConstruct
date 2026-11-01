// from server: 100% by auto
// roc 2007-03 0062f2b0  unit: seg_00620000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062f2b0
//
// 0062f2b0  8b01                 mov eax, dword ptr [ecx]
// 0062f2b2  8b90b8000000         mov edx, dword ptr [eax + 0xb8]
// 0062f2b8  6a00                 push 0
// 0062f2ba  ffd2                 call edx
// 0062f2bc  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnRemoved@CXTPControl@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
