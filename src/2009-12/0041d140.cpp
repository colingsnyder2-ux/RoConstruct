// from server: 100% by auto
// roc 2009-12 0041d140  unit: CXTTreeCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d140
//
// 0041d140  8b442404             mov eax, dword ptr [esp + 4]
// 0041d144  56                   push esi
// 0041d145  50                   push eax
// 0041d146  8bf1                 mov esi, ecx
// 0041d148  e897673d00           call 0x7f38e4
// 0041d14d  85c0                 test eax, eax
// 0041d14f  7504                 jne 0x41d155
// 0041d151  5e                   pop esi
// 0041d152  c20400               ret 4
// 0041d155  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0041d15c  b801000000           mov eax, 1
// 0041d161  5e                   pop esi
// 0041d162  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPMarkupTreeCtrl.cpp (function ?PreCreateWindow@CXTPTreeCtrlBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPMarkupTreeCtrl.cpp
