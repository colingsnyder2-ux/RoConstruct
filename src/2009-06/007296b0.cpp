// from server: 100% by auto
// roc 2009-06 007296b0  unit: CXTPCommandBar  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007296b0
//
// 007296b0  56                   push esi
// 007296b1  8bf1                 mov esi, ecx
// 007296b3  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007296b9  e824281200           call 0x84bee2
// 007296be  a900004000           test eax, 0x400000
// 007296c3  b801000000           mov eax, 1
// 007296c8  7506                 jne 0x7296d0
// 007296ca  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 007296d0  5e                   pop esi
// 007296d1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsLayoutRTL@CXTPCommandBars@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
