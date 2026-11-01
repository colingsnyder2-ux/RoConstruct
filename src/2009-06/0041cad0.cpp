// from server: 100% by auto
// roc 2009-06 0041cad0  unit: CXTTreeCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cad0
//
// 0041cad0  8b442404             mov eax, dword ptr [esp + 4]
// 0041cad4  56                   push esi
// 0041cad5  50                   push eax
// 0041cad6  8bf1                 mov esi, ecx
// 0041cad8  e8dfbf2f00           call 0x718abc
// 0041cadd  85c0                 test eax, eax
// 0041cadf  7504                 jne 0x41cae5
// 0041cae1  5e                   pop esi
// 0041cae2  c20400               ret 4
// 0041cae5  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0041caec  b801000000           mov eax, 1
// 0041caf1  5e                   pop esi
// 0041caf2  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPMarkupTreeCtrl.cpp (function ?PreCreateWindow@CXTPTreeCtrlBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPMarkupTreeCtrl.cpp
