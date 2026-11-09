// from server: 100% by auto
// roc 2010-06 0042e4c0  unit: CClassTreeView  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e4c0
//
// 0042e4c0  8b442404             mov eax, dword ptr [esp + 4]
// 0042e4c4  56                   push esi
// 0042e4c5  50                   push eax
// 0042e4c6  8bf1                 mov esi, ecx
// 0042e4c8  e8e99f3700           call 0x7a84b6
// 0042e4cd  85c0                 test eax, eax
// 0042e4cf  7504                 jne 0x42e4d5
// 0042e4d1  5e                   pop esi
// 0042e4d2  c20400               ret 4
// 0042e4d5  c6869c00000000       mov byte ptr [esi + 0x9c], 0
// 0042e4dc  b801000000           mov eax, 1
// 0042e4e1  5e                   pop esi
// 0042e4e2  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ?PreCreateWindow@CXTTreeViewBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
