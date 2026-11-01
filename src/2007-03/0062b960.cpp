// from server: 100% by auto
// roc 2007-03 0062b960  unit: seg_00620000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b960
//
// 0062b960  8b4150               mov eax, dword ptr [ecx + 0x50]
// 0062b963  85c0                 test eax, eax
// 0062b965  7516                 jne 0x62b97d
// 0062b967  3905d4178c00         cmp dword ptr [0x8c17d4], eax
// 0062b96d  7509                 jne 0x62b978
// 0062b96f  50                   push eax
// 0062b970  e84b760000           call 0x632fc0
// 0062b975  83c404               add esp, 4
// 0062b978  a1d4178c00           mov eax, dword ptr [0x8c17d4]
// 0062b97d  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetPaintManager@CXTPCommandBars@@QBEPAVCXTPPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
