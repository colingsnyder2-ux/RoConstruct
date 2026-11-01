// from server: 100% by auto
// roc 2009-06 00729a00  unit: MyXTPCommandBars  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729a00
//
// 00729a00  8b4150               mov eax, dword ptr [ecx + 0x50]
// 00729a03  85c0                 test eax, eax
// 00729a05  7516                 jne 0x729a1d
// 00729a07  39054419a500         cmp dword ptr [0xa51944], eax
// 00729a0d  7509                 jne 0x729a18
// 00729a0f  50                   push eax
// 00729a10  e8ab9dffff           call 0x7237c0
// 00729a15  83c404               add esp, 4
// 00729a18  a14419a500           mov eax, dword ptr [0xa51944]
// 00729a1d  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetPaintManager@CXTPCommandBars@@QBEPAVCXTPPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
