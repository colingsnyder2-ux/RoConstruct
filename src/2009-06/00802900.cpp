// from server: 100% by auto
// roc 2009-06 00802900  unit: CXTColorBase  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802900
//
// 00802900  8b442404             mov eax, dword ptr [esp + 4]
// 00802904  56                   push esi
// 00802905  50                   push eax
// 00802906  8bf1                 mov esi, ecx
// 00802908  e8af61f1ff           call 0x718abc
// 0080290d  85c0                 test eax, eax
// 0080290f  7504                 jne 0x802915
// 00802911  5e                   pop esi
// 00802912  c20400               ret 4
// 00802915  c6465400             mov byte ptr [esi + 0x54], 0
// 00802919  b801000000           mov eax, 1
// 0080291e  5e                   pop esi
// 0080291f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?PreCreateWindow@CXTPColorBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
