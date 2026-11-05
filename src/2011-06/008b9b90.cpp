// from server: 100% by auto
// roc 2011-06 008b9b90  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b9b90
//
// 008b9b90  56                   push esi
// 008b9b91  8bf1                 mov esi, ecx
// 008b9b93  8b4604               mov eax, dword ptr [esi + 4]
// 008b9b96  50                   push eax
// 008b9b97  6a00                 push 0
// 008b9b99  e8f2670300           call 0x8f0390
// 008b9b9e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008b9ba2  894808               mov dword ptr [eax + 8], ecx
// 008b9ba5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008b9ba8  85c9                 test ecx, ecx
// 008b9baa  740a                 je 0x8b9bb6
// 008b9bac  894104               mov dword ptr [ecx + 4], eax
// 008b9baf  894604               mov dword ptr [esi + 4], eax
// 008b9bb2  5e                   pop esi
// 008b9bb3  c20400               ret 4
// 008b9bb6  894608               mov dword ptr [esi + 8], eax
// 008b9bb9  894604               mov dword ptr [esi + 4], eax
// 008b9bbc  5e                   pop esi
// 008b9bbd  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?AddHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAU__POSITION@@PAVCMFCPropertyGridProperty@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
