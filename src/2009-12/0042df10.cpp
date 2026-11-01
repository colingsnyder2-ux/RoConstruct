// from server: 100% by auto
// roc 2009-12 0042df10  unit: CClassTreeView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042df10
//
// 0042df10  8b442404             mov eax, dword ptr [esp + 4]
// 0042df14  56                   push esi
// 0042df15  50                   push eax
// 0042df16  8bf1                 mov esi, ecx
// 0042df18  e85f643c00           call 0x7f437c
// 0042df1d  83f8ff               cmp eax, -1
// 0042df20  7506                 jne 0x42df28
// 0042df22  0bc0                 or eax, eax
// 0042df24  5e                   pop esi
// 0042df25  c20400               ret 4
// 0042df28  8b5660               mov edx, dword ptr [esi + 0x60]
// 0042df2b  8b4248               mov eax, dword ptr [edx + 0x48]
// 0042df2e  8d4e60               lea ecx, [esi + 0x60]
// 0042df31  ffd0                 call eax
// 0042df33  33c0                 xor eax, eax
// 0042df35  5e                   pop esi
// 0042df36  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnCreate@CXTPShellTreeBaseCTreeView@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
