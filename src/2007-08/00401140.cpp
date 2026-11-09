// from server: 100% by auto
// roc 2007-08 00401140  unit: CSettingsDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401140
//
// 00401140  0fb7542404           movzx edx, word ptr [esp + 4]
// 00401145  89542404             mov dword ptr [esp + 4], edx
// 00401149  e9caec2200           jmp 0x62fe18
// library mfc-8.0/atlmfc\src\mfc\dlgclr.cpp (function ?Create@CDialog@@UAEHIPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgclr.cpp
