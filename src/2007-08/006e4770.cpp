// from server: 100% by auto
// roc 2007-08 006e4770  unit: CXTPDockingPaneSplitterContainer  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e4770
//
// 006e4770  56                   push esi
// 006e4771  8bf1                 mov esi, ecx
// 006e4773  8b4608               mov eax, dword ptr [esi + 8]
// 006e4776  6a00                 push 0
// 006e4778  50                   push eax
// 006e4779  e832fdffff           call 0x6e44b0
// 006e477e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e4782  894808               mov dword ptr [eax + 8], ecx
// 006e4785  8b4e08               mov ecx, dword ptr [esi + 8]
// 006e4788  85c9                 test ecx, ecx
// 006e478a  7409                 je 0x6e4795
// 006e478c  8901                 mov dword ptr [ecx], eax
// 006e478e  894608               mov dword ptr [esi + 8], eax
// 006e4791  5e                   pop esi
// 006e4792  c20400               ret 4
// 006e4795  894604               mov dword ptr [esi + 4], eax
// 006e4798  894608               mov dword ptr [esi + 8], eax
// 006e479b  5e                   pop esi
// 006e479c  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?AddTail@CObList@@QAEPAU__POSITION@@PAVCObject@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
