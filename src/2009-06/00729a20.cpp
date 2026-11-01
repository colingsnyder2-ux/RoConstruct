// from server: 100% by auto
// roc 2009-06 00729a20  unit: MyXTPCommandBars  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729a20
//
// 00729a20  8b4154               mov eax, dword ptr [ecx + 0x54]
// 00729a23  85c0                 test eax, eax
// 00729a25  7505                 jne 0x729a2c
// 00729a27  e994f90000           jmp 0x7393c0
// 00729a2c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetImageManager@CXTPCommandBars@@QBEPAVCXTPImageManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
