// from server: 100% by auto
// roc 2007-08 006d8640  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d8640
//
// 006d8640  56                   push esi
// 006d8641  8bf1                 mov esi, ecx
// 006d8643  8b4604               mov eax, dword ptr [esi + 4]
// 006d8646  50                   push eax
// 006d8647  6a00                 push 0
// 006d8649  e862be0000           call 0x6e44b0
// 006d864e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d8652  894808               mov dword ptr [eax + 8], ecx
// 006d8655  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d8658  85c9                 test ecx, ecx
// 006d865a  740a                 je 0x6d8666
// 006d865c  894104               mov dword ptr [ecx + 4], eax
// 006d865f  894604               mov dword ptr [esi + 4], eax
// 006d8662  5e                   pop esi
// 006d8663  c20400               ret 4
// 006d8666  894608               mov dword ptr [esi + 8], eax
// 006d8669  894604               mov dword ptr [esi + 4], eax
// 006d866c  5e                   pop esi
// 006d866d  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?AddHead@CObList@@QAEPAU__POSITION@@PAVCObject@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
