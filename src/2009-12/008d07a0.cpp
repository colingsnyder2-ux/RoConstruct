// from server: 100% by auto
// roc 2009-12 008d07a0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d07a0
//
// 008d07a0  56                   push esi
// 008d07a1  8bf1                 mov esi, ecx
// 008d07a3  e8383d0000           call 0x8d44e0
// 008d07a8  c7064ca8a000         mov dword ptr [esi], 0xa0a84c
// 008d07ae  8bc6                 mov eax, esi
// 008d07b0  5e                   pop esi
// 008d07b1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
