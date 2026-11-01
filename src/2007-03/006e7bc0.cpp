// from server: 100% by auto
// roc 2007-03 006e7bc0  unit: seg_006e0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7bc0
//
// 006e7bc0  83793000             cmp dword ptr [ecx + 0x30], 0
// 006e7bc4  7511                 jne 0x6e7bd7
// 006e7bc6  e8d5d3f6ff           call 0x654fa0
// 006e7bcb  8bc8                 mov ecx, eax
// 006e7bcd  e8becef6ff           call 0x654a90
// 006e7bd2  85c0                 test eax, eax
// 006e7bd4  7501                 jne 0x6e7bd7
// 006e7bd6  c3                   ret 
// 006e7bd7  b801000000           mov eax, 1
// 006e7bdc  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?IsLunaColorsDisabled@CXTPTabPaintManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
