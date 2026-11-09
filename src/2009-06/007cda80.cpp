// from server: 100% by auto
// roc 2009-06 007cda80  unit: UXTP_DOCKINGPANE_INFO::?$CList  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cda80
//
// 007cda80  56                   push esi
// 007cda81  8bf1                 mov esi, ecx
// 007cda83  8b4604               mov eax, dword ptr [esi + 4]
// 007cda86  50                   push eax
// 007cda87  6a00                 push 0
// 007cda89  e8627d0100           call 0x7e57f0
// 007cda8e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007cda92  894808               mov dword ptr [eax + 8], ecx
// 007cda95  8b4e04               mov ecx, dword ptr [esi + 4]
// 007cda98  85c9                 test ecx, ecx
// 007cda9a  740a                 je 0x7cdaa6
// 007cda9c  894104               mov dword ptr [ecx + 4], eax
// 007cda9f  894604               mov dword ptr [esi + 4], eax
// 007cdaa2  5e                   pop esi
// 007cdaa3  c20400               ret 4
// 007cdaa6  894608               mov dword ptr [esi + 8], eax
// 007cdaa9  894604               mov dword ptr [esi + 4], eax
// 007cdaac  5e                   pop esi
// 007cdaad  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?AddHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAU__POSITION@@PAVCMFCPropertyGridProperty@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
