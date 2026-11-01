// from server: 100% by auto
// roc 2007-03 00421750  unit: seg_00420000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00421750
//
// 00421750  8b442404             mov eax, dword ptr [esp + 4]
// 00421754  56                   push esi
// 00421755  50                   push eax
// 00421756  8bf1                 mov esi, ecx
// 00421758  e829ca1f00           call 0x61e186
// 0042175d  85c0                 test eax, eax
// 0042175f  7504                 jne 0x421765
// 00421761  5e                   pop esi
// 00421762  c20400               ret 4
// 00421765  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0042176c  b801000000           mov eax, 1
// 00421771  5e                   pop esi
// 00421772  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPMarkupTreeCtrl.cpp (function ?PreCreateWindow@CXTPTreeCtrlBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPMarkupTreeCtrl.cpp
