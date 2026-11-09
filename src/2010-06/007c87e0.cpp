// from server: 100% by auto
// roc 2010-06 007c87e0  unit: MyXTPCommandBars  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c87e0
//
// 007c87e0  8b4154               mov eax, dword ptr [ecx + 0x54]
// 007c87e3  85c0                 test eax, eax
// 007c87e5  7505                 jne 0x7c87ec
// 007c87e7  e964bdffff           jmp 0x7c4550
// 007c87ec  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetImageManager@CXTPCommandBars@@QBEPAVCXTPImageManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
