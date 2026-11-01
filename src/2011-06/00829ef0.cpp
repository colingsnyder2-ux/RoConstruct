// from server: 100% by auto
// roc 2011-06 00829ef0  unit: CXTPCommandBar  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00829ef0
//
// 00829ef0  56                   push esi
// 00829ef1  8bf1                 mov esi, ecx
// 00829ef3  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00829ef9  e820271a00           call 0x9cc61e
// 00829efe  a900004000           test eax, 0x400000
// 00829f03  b801000000           mov eax, 1
// 00829f08  7506                 jne 0x829f10
// 00829f0a  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00829f10  5e                   pop esi
// 00829f11  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsLayoutRTL@CXTPCommandBars@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
