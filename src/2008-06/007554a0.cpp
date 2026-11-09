// from server: 100% by auto
// roc 2008-06 007554a0  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007554a0
//
// 007554a0  56                   push esi
// 007554a1  8bf1                 mov esi, ecx
// 007554a3  8b4604               mov eax, dword ptr [esi + 4]
// 007554a6  50                   push eax
// 007554a7  6a00                 push 0
// 007554a9  e882520100           call 0x76a730
// 007554ae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007554b2  894808               mov dword ptr [eax + 8], ecx
// 007554b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007554b8  85c9                 test ecx, ecx
// 007554ba  740a                 je 0x7554c6
// 007554bc  894104               mov dword ptr [ecx + 4], eax
// 007554bf  894604               mov dword ptr [esi + 4], eax
// 007554c2  5e                   pop esi
// 007554c3  c20400               ret 4
// 007554c6  894608               mov dword ptr [esi + 8], eax
// 007554c9  894604               mov dword ptr [esi + 4], eax
// 007554cc  5e                   pop esi
// 007554cd  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?AddHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAU__POSITION@@PAVCMFCPropertyGridProperty@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
