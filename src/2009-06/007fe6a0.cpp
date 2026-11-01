// from server: 100% by auto
// roc 2009-06 007fe6a0  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe6a0
//
// 007fe6a0  8b442404             mov eax, dword ptr [esp + 4]
// 007fe6a4  56                   push esi
// 007fe6a5  50                   push eax
// 007fe6a6  8bf1                 mov esi, ecx
// 007fe6a8  e80fa4f1ff           call 0x718abc
// 007fe6ad  85c0                 test eax, eax
// 007fe6af  7504                 jne 0x7fe6b5
// 007fe6b1  5e                   pop esi
// 007fe6b2  c20400               ret 4
// 007fe6b5  c6465c00             mov byte ptr [esi + 0x5c], 0
// 007fe6b9  b801000000           mov eax, 1
// 007fe6be  5e                   pop esi
// 007fe6bf  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?PreCreateWindow@CXTPColorHex@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
