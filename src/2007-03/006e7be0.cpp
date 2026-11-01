// from server: 100% by auto
// roc 2007-03 006e7be0  unit: seg_006e0000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7be0
//
// 006e7be0  83ec20               sub esp, 0x20
// 006e7be3  8b442424             mov eax, dword ptr [esp + 0x24]
// 006e7be7  c704248aa8e400       mov dword ptr [esp], 0xe4a88a
// 006e7bee  c7442404ffdb7500     mov dword ptr [esp + 4], 0x75dbff
// 006e7bf6  c7442408bdcd9f00     mov dword ptr [esp + 8], 0x9fcdbd
// 006e7bfe  c744240cf09e9f00     mov dword ptr [esp + 0xc], 0x9f9ef0
// 006e7c06  c7442410baa6e100     mov dword ptr [esp + 0x10], 0xe1a6ba
// 006e7c0e  c74424149abfb400     mov dword ptr [esp + 0x14], 0xb4bf9a
// 006e7c16  c7442418f7b68300     mov dword ptr [esp + 0x18], 0x83b6f7
// 006e7c1e  c744241cd8abc000     mov dword ptr [esp + 0x1c], 0xc0abd8
// 006e7c26  8b8484000000fc       mov eax, dword ptr [esp + eax*4 - 0x4000000]
// 006e7c2d  83c420               add esp, 0x20
// 006e7c30  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetOneNoteColor@CXTPTabPaintManager@@SAKW4XTPTabOneNoteColor@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
