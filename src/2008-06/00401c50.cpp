// from server: 100% by auto
// roc 2008-06 00401c50  unit: VCWorkspace::?$CComObject  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401c50
//
// 00401c50  56                   push esi
// 00401c51  8bf1                 mov esi, ecx
// 00401c53  8b0e                 mov ecx, dword ptr [esi]
// 00401c55  33c0                 xor eax, eax
// 00401c57  85c9                 test ecx, ecx
// 00401c59  7416                 je 0x401c71
// 00401c5b  51                   push ecx
// 00401c5c  ff1508208000         call dword ptr [0x802008]
// 00401c62  c70600000000         mov dword ptr [esi], 0
// 00401c68  c7460400000000       mov dword ptr [esi + 4], 0
// 00401c6f  5e                   pop esi
// 00401c70  c3                   ret 
// 00401c71  894604               mov dword ptr [esi + 4], eax
// 00401c74  5e                   pop esi
// 00401c75  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
