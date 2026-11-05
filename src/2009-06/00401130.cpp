// from server: 100% by auto
// roc 2009-06 00401130  unit: CInsertObjectDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401130
//
// 00401130  0fb7542404           movzx edx, word ptr [esp + 4]
// 00401135  89542404             mov dword ptr [esp + 4], edx
// 00401139  e9b07a3100           jmp 0x718bee
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Create@CDialog@@UAEHIPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
