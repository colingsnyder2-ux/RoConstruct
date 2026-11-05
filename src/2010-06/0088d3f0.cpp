// from server: 100% by auto
// roc 2010-06 0088d3f0  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d3f0
//
// 0088d3f0  8b442404             mov eax, dword ptr [esp + 4]
// 0088d3f4  56                   push esi
// 0088d3f5  50                   push eax
// 0088d3f6  8bf1                 mov esi, ecx
// 0088d3f8  e827a6f1ff           call 0x7a7a24
// 0088d3fd  85c0                 test eax, eax
// 0088d3ff  7504                 jne 0x88d405
// 0088d401  5e                   pop esi
// 0088d402  c20400               ret 4
// 0088d405  c6465c00             mov byte ptr [esi + 0x5c], 0
// 0088d409  b801000000           mov eax, 1
// 0088d40e  5e                   pop esi
// 0088d40f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?PreCreateWindow@CXTColorHex@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
