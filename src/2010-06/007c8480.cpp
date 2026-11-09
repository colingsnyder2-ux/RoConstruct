// from server: 100% by auto
// roc 2010-06 007c8480  unit: CXTPCommandBar  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8480
//
// 007c8480  56                   push esi
// 007c8481  8bf1                 mov esi, ecx
// 007c8483  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007c8489  e856491b00           call 0x97cde4
// 007c848e  a900004000           test eax, 0x400000
// 007c8493  b801000000           mov eax, 1
// 007c8498  7506                 jne 0x7c84a0
// 007c849a  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 007c84a0  5e                   pop esi
// 007c84a1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsLayoutRTL@CXTPCommandBars@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
