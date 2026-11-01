// from server: 100% by auto
// roc 2009-06 0042ced0  unit: CClassTreeView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042ced0
//
// 0042ced0  8b442404             mov eax, dword ptr [esp + 4]
// 0042ced4  56                   push esi
// 0042ced5  50                   push eax
// 0042ced6  8bf1                 mov esi, ecx
// 0042ced8  e871c62e00           call 0x71954e
// 0042cedd  83f8ff               cmp eax, -1
// 0042cee0  7506                 jne 0x42cee8
// 0042cee2  0bc0                 or eax, eax
// 0042cee4  5e                   pop esi
// 0042cee5  c20400               ret 4
// 0042cee8  8b5660               mov edx, dword ptr [esi + 0x60]
// 0042ceeb  8b4248               mov eax, dword ptr [edx + 0x48]
// 0042ceee  8d4e60               lea ecx, [esi + 0x60]
// 0042cef1  ffd0                 call eax
// 0042cef3  33c0                 xor eax, eax
// 0042cef5  5e                   pop esi
// 0042cef6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnCreate@CXTPShellTreeBaseCTreeView@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
