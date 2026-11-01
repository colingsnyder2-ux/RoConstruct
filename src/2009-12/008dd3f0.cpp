// from server: 100% by auto
// roc 2009-12 008dd3f0  unit: CXTColorBase  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd3f0
//
// 008dd3f0  8b442404             mov eax, dword ptr [esp + 4]
// 008dd3f4  56                   push esi
// 008dd3f5  50                   push eax
// 008dd3f6  8bf1                 mov esi, ecx
// 008dd3f8  e8e764f1ff           call 0x7f38e4
// 008dd3fd  85c0                 test eax, eax
// 008dd3ff  7504                 jne 0x8dd405
// 008dd401  5e                   pop esi
// 008dd402  c20400               ret 4
// 008dd405  c6465400             mov byte ptr [esi + 0x54], 0
// 008dd409  b801000000           mov eax, 1
// 008dd40e  5e                   pop esi
// 008dd40f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?PreCreateWindow@CXTPColorBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
