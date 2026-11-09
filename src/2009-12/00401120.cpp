// from server: 100% by auto
// roc 2009-12 00401120  unit: CInsertObjectDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401120
//
// 00401120  0fb7542404           movzx edx, word ptr [esp + 4]
// 00401125  89542404             mov dword ptr [esp + 4], edx
// 00401129  e9e8283f00           jmp 0x7f3a16
// library mfc-8.0/atlmfc\src\mfc\dlgclr.cpp (function ?Create@CDialog@@UAEHIPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgclr.cpp
