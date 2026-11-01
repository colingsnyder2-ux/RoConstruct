// from server: 100% by auto
// roc 2009-12 008d07e0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d07e0
//
// 008d07e0  83ec20               sub esp, 0x20
// 008d07e3  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d07e7  c704248aa8e400       mov dword ptr [esp], 0xe4a88a
// 008d07ee  c7442404ffdb7500     mov dword ptr [esp + 4], 0x75dbff
// 008d07f6  c7442408bdcd9f00     mov dword ptr [esp + 8], 0x9fcdbd
// 008d07fe  c744240cf09e9f00     mov dword ptr [esp + 0xc], 0x9f9ef0
// 008d0806  c7442410baa6e100     mov dword ptr [esp + 0x10], 0xe1a6ba
// 008d080e  c74424149abfb400     mov dword ptr [esp + 0x14], 0xb4bf9a
// 008d0816  c7442418f7b68300     mov dword ptr [esp + 0x18], 0x83b6f7
// 008d081e  c744241cd8abc000     mov dword ptr [esp + 0x1c], 0xc0abd8
// 008d0826  8b8484000000fc       mov eax, dword ptr [esp + eax*4 - 0x4000000]
// 008d082d  83c420               add esp, 0x20
// 008d0830  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetOneNoteColor@CXTPTabPaintManager@@SAKW4XTPTabOneNoteColor@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
