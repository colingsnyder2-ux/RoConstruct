// from server: 100% by auto
// roc 2007-03 0062b620  unit: seg_00620000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b620
//
// 0062b620  56                   push esi
// 0062b621  8bf1                 mov esi, ecx
// 0062b623  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0062b629  e858f41000           call 0x73aa86
// 0062b62e  a900004000           test eax, 0x400000
// 0062b633  b801000000           mov eax, 1
// 0062b638  7506                 jne 0x62b640
// 0062b63a  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0062b640  5e                   pop esi
// 0062b641  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsLayoutRTL@CXTPCommandBars@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
