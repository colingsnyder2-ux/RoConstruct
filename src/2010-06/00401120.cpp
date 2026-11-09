// from server: 100% by auto
// roc 2010-06 00401120  unit: CInsertObjectDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401120
//
// 00401120  0fb7542404           movzx edx, word ptr [esp + 4]
// 00401125  89542404             mov dword ptr [esp + 4], edx
// 00401129  e9286a3a00           jmp 0x7a7b56
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Create@CDialog@@UAEHIPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
