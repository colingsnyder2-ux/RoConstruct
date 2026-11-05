// from server: 100% by auto
// roc 2010-06 0042e4f0  unit: CClassTreeView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e4f0
//
// 0042e4f0  8b442404             mov eax, dword ptr [esp + 4]
// 0042e4f4  56                   push esi
// 0042e4f5  50                   push eax
// 0042e4f6  8bf1                 mov esi, ecx
// 0042e4f8  e8bf9f3700           call 0x7a84bc
// 0042e4fd  83f8ff               cmp eax, -1
// 0042e500  7506                 jne 0x42e508
// 0042e502  0bc0                 or eax, eax
// 0042e504  5e                   pop esi
// 0042e505  c20400               ret 4
// 0042e508  8b5660               mov edx, dword ptr [esi + 0x60]
// 0042e50b  8b4248               mov eax, dword ptr [edx + 0x48]
// 0042e50e  8d4e60               lea ecx, [esi + 0x60]
// 0042e511  ffd0                 call eax
// 0042e513  33c0                 xor eax, eax
// 0042e515  5e                   pop esi
// 0042e516  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnCreate@CXTShellTreeBaseCTreeView@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
