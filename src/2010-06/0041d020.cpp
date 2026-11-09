// from server: 100% by auto
// roc 2010-06 0041d020  unit: CXTTreeCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041d020
//
// 0041d020  8b442404             mov eax, dword ptr [esp + 4]
// 0041d024  56                   push esi
// 0041d025  50                   push eax
// 0041d026  8bf1                 mov esi, ecx
// 0041d028  e8f7a93800           call 0x7a7a24
// 0041d02d  85c0                 test eax, eax
// 0041d02f  7504                 jne 0x41d035
// 0041d031  5e                   pop esi
// 0041d032  c20400               ret 4
// 0041d035  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0041d03c  b801000000           mov eax, 1
// 0041d041  5e                   pop esi
// 0041d042  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ?PreCreateWindow@CXTTreeCtrlBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
