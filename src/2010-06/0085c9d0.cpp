// from server: 100% by auto
// roc 2010-06 0085c9d0  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c9d0
//
// 0085c9d0  56                   push esi
// 0085c9d1  8bf1                 mov esi, ecx
// 0085c9d3  8b4604               mov eax, dword ptr [esi + 4]
// 0085c9d6  50                   push eax
// 0085c9d7  6a00                 push 0
// 0085c9d9  e892210300           call 0x88eb70
// 0085c9de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085c9e2  894808               mov dword ptr [eax + 8], ecx
// 0085c9e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0085c9e8  85c9                 test ecx, ecx
// 0085c9ea  740a                 je 0x85c9f6
// 0085c9ec  894104               mov dword ptr [ecx + 4], eax
// 0085c9ef  894604               mov dword ptr [esi + 4], eax
// 0085c9f2  5e                   pop esi
// 0085c9f3  c20400               ret 4
// 0085c9f6  894608               mov dword ptr [esi + 8], eax
// 0085c9f9  894604               mov dword ptr [esi + 4], eax
// 0085c9fc  5e                   pop esi
// 0085c9fd  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?AddHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAU__POSITION@@PAVCMFCPropertyGridProperty@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
