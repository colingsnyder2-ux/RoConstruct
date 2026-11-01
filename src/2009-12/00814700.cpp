// from server: 100% by auto
// roc 2009-12 00814700  unit: MyXTPCommandBars  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814700
//
// 00814700  8b4154               mov eax, dword ptr [ecx + 0x54]
// 00814703  85c0                 test eax, eax
// 00814705  7505                 jne 0x81470c
// 00814707  e9a4bdffff           jmp 0x8104b0
// 0081470c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetImageManager@CXTPCommandBars@@QBEPAVCXTPImageManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
