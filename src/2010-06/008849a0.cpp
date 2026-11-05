// from server: 100% by auto
// roc 2010-06 008849a0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008849a0
//
// 008849a0  83ec20               sub esp, 0x20
// 008849a3  8b442424             mov eax, dword ptr [esp + 0x24]
// 008849a7  c704248aa8e400       mov dword ptr [esp], 0xe4a88a
// 008849ae  c7442404ffdb7500     mov dword ptr [esp + 4], 0x75dbff
// 008849b6  c7442408bdcd9f00     mov dword ptr [esp + 8], 0x9fcdbd
// 008849be  c744240cf09e9f00     mov dword ptr [esp + 0xc], 0x9f9ef0
// 008849c6  c7442410baa6e100     mov dword ptr [esp + 0x10], 0xe1a6ba
// 008849ce  c74424149abfb400     mov dword ptr [esp + 0x14], 0xb4bf9a
// 008849d6  c7442418f7b68300     mov dword ptr [esp + 0x18], 0x83b6f7
// 008849de  c744241cd8abc000     mov dword ptr [esp + 0x1c], 0xc0abd8
// 008849e6  8b8484000000fc       mov eax, dword ptr [esp + eax*4 - 0x4000000]
// 008849ed  83c420               add esp, 0x20
// 008849f0  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetOneNoteColor@CXTPTabPaintManager@@SAKW4XTPTabOneNoteColor@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
