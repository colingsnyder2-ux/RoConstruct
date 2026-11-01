// from server: 100% by auto
// roc 2009-12 0042dee0  unit: CClassTreeView  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042dee0
//
// 0042dee0  8b442404             mov eax, dword ptr [esp + 4]
// 0042dee4  56                   push esi
// 0042dee5  50                   push eax
// 0042dee6  8bf1                 mov esi, ecx
// 0042dee8  e889643c00           call 0x7f4376
// 0042deed  85c0                 test eax, eax
// 0042deef  7504                 jne 0x42def5
// 0042def1  5e                   pop esi
// 0042def2  c20400               ret 4
// 0042def5  c6869c00000000       mov byte ptr [esi + 0x9c], 0
// 0042defc  b801000000           mov eax, 1
// 0042df01  5e                   pop esi
// 0042df02  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ?PreCreateWindow@CXTPTreeViewBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
