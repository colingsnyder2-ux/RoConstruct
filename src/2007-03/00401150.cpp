// from server: 100% by auto
// roc 2007-03 00401150  unit: seg_00400000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401150
//
// 00401150  0fb7542404           movzx edx, word ptr [esp + 4]
// 00401155  89542404             mov dword ptr [esp + 4], edx
// 00401159  e94ed12100           jmp 0x61e2ac
// library mfc-8.0/atlmfc\src\mfc\dlgclr.cpp (function ?Create@CDialog@@UAEHIPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgclr.cpp
