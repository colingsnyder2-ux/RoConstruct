// from server: 100% by auto
// roc 2009-06 00759ff0  unit: CXTTreeCtrlBase  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759ff0
//
// 00759ff0  56                   push esi
// 00759ff1  8bf1                 mov esi, ecx
// 00759ff3  e868feffff           call 0x759e60
// 00759ff8  c706e46c8f00         mov dword ptr [esi], 0x8f6ce4
// 00759ffe  c746605c6c8f00       mov dword ptr [esi + 0x60], 0x8f6c5c
// 0075a005  89b694000000         mov dword ptr [esi + 0x94], esi
// 0075a00b  8bc6                 mov eax, esi
// 0075a00d  5e                   pop esi
// 0075a00e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeView@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
