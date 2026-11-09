// from server: 100% by auto
// roc 2009-12 008ce370  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce370
//
// 008ce370  8b01                 mov eax, dword ptr [ecx]
// 008ce372  8b4020               mov eax, dword ptr [eax + 0x20]
// 008ce375  ffe0                 jmp eax
// library mfc-8.0/atlmfc\src\mfc\inet.cpp (function ?GetCreationTime@CGopherFileFind@@UBEHAAVCTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/inet.cpp
