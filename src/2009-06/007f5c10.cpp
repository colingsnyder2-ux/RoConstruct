// from server: 100% by auto
// roc 2009-06 007f5c10  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5c10
//
// 007f5c10  83ec20               sub esp, 0x20
// 007f5c13  8b442424             mov eax, dword ptr [esp + 0x24]
// 007f5c17  c704248aa8e400       mov dword ptr [esp], 0xe4a88a
// 007f5c1e  c7442404ffdb7500     mov dword ptr [esp + 4], 0x75dbff
// 007f5c26  c7442408bdcd9f00     mov dword ptr [esp + 8], 0x9fcdbd
// 007f5c2e  c744240cf09e9f00     mov dword ptr [esp + 0xc], 0x9f9ef0
// 007f5c36  c7442410baa6e100     mov dword ptr [esp + 0x10], 0xe1a6ba
// 007f5c3e  c74424149abfb400     mov dword ptr [esp + 0x14], 0xb4bf9a
// 007f5c46  c7442418f7b68300     mov dword ptr [esp + 0x18], 0x83b6f7
// 007f5c4e  c744241cd8abc000     mov dword ptr [esp + 0x1c], 0xc0abd8
// 007f5c56  8b8484000000fc       mov eax, dword ptr [esp + eax*4 - 0x4000000]
// 007f5c5d  83c420               add esp, 0x20
// 007f5c60  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetOneNoteColor@CXTPTabPaintManager@@SAKW4XTPTabOneNoteColor@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
