// from server: 100% by auto
// roc 2009-12 008143a0  unit: CXTPCommandBar  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008143a0
//
// 008143a0  56                   push esi
// 008143a1  8bf1                 mov esi, ecx
// 008143a3  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 008143a9  e8ca201100           call 0x926478
// 008143ae  a900004000           test eax, 0x400000
// 008143b3  b801000000           mov eax, 1
// 008143b8  7506                 jne 0x8143c0
// 008143ba  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 008143c0  5e                   pop esi
// 008143c1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsLayoutRTL@CXTPCommandBars@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
