// from server: 100% by auto
// roc 2009-06 00666c00  unit: RBX::RotatePJoint  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00666c00
//
// 00666c00  8b442404             mov eax, dword ptr [esp + 4]
// 00666c04  50                   push eax
// 00666c05  e8a65ce6ff           call 0x4cc8b0
// 00666c0a  83c404               add esp, 4
// 00666c0d  89442404             mov dword ptr [esp + 4], eax
// 00666c11  e98af9ffff           jmp 0x6665a0
// library mfc-9.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filetxt.cpp
