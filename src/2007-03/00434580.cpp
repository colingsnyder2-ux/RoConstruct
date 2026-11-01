// from server: 100% by auto
// roc 2007-03 00434580  unit: seg_00430000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00434580
//
// 00434580  8b442404             mov eax, dword ptr [esp + 4]
// 00434584  56                   push esi
// 00434585  50                   push eax
// 00434586  8bf1                 mov esi, ecx
// 00434588  e841a51e00           call 0x61eace
// 0043458d  85c0                 test eax, eax
// 0043458f  7504                 jne 0x434595
// 00434591  5e                   pop esi
// 00434592  c20400               ret 4
// 00434595  c6869c00000000       mov byte ptr [esi + 0x9c], 0
// 0043459c  b801000000           mov eax, 1
// 004345a1  5e                   pop esi
// 004345a2  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ?PreCreateWindow@CXTPTreeViewBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
