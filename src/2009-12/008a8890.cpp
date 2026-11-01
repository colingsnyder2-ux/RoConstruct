// from server: 100% by auto
// roc 2009-12 008a8890  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a8890
//
// 008a8890  56                   push esi
// 008a8891  8bf1                 mov esi, ecx
// 008a8893  8b4604               mov eax, dword ptr [esi + 4]
// 008a8896  50                   push eax
// 008a8897  6a00                 push 0
// 008a8899  e842a20100           call 0x8c2ae0
// 008a889e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a88a2  894808               mov dword ptr [eax + 8], ecx
// 008a88a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a88a8  85c9                 test ecx, ecx
// 008a88aa  740a                 je 0x8a88b6
// 008a88ac  894104               mov dword ptr [ecx + 4], eax
// 008a88af  894604               mov dword ptr [esi + 4], eax
// 008a88b2  5e                   pop esi
// 008a88b3  c20400               ret 4
// 008a88b6  894608               mov dword ptr [esi + 8], eax
// 008a88b9  894604               mov dword ptr [esi + 4], eax
// 008a88bc  5e                   pop esi
// 008a88bd  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?AddHead@CObList@@QAEPAU__POSITION@@PAVCObject@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
