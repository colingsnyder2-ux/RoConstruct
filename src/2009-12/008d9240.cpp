// from server: 100% by auto
// roc 2009-12 008d9240  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d9240
//
// 008d9240  8b442404             mov eax, dword ptr [esp + 4]
// 008d9244  56                   push esi
// 008d9245  50                   push eax
// 008d9246  8bf1                 mov esi, ecx
// 008d9248  e897a6f1ff           call 0x7f38e4
// 008d924d  85c0                 test eax, eax
// 008d924f  7504                 jne 0x8d9255
// 008d9251  5e                   pop esi
// 008d9252  c20400               ret 4
// 008d9255  c6465c00             mov byte ptr [esi + 0x5c], 0
// 008d9259  b801000000           mov eax, 1
// 008d925e  5e                   pop esi
// 008d925f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?PreCreateWindow@CXTPColorHex@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
