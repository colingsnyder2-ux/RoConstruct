// from server: 100% by auto
// roc 2007-03 00632370  unit: seg_00630000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632370
//
// 00632370  8b0dd4178c00         mov ecx, dword ptr [0x8c17d4]
// 00632376  85c9                 test ecx, ecx
// 00632378  7405                 je 0x63237f
// 0063237a  e8f3c2feff           call 0x61e672
// 0063237f  c705d4178c0000000000 mov dword ptr [0x8c17d4], 0
// 00632389  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Done@CXTPPaintManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
