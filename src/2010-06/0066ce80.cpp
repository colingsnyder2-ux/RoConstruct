// from server: 100% by auto
// roc 2010-06 0066ce80  unit: RBX::RotatePJoint  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066ce80
//
// 0066ce80  8b442404             mov eax, dword ptr [esp + 4]
// 0066ce84  50                   push eax
// 0066ce85  e81604e6ff           call 0x4cd2a0
// 0066ce8a  83c404               add esp, 4
// 0066ce8d  89442404             mov dword ptr [esp + 4], eax
// 0066ce91  e9eaf7ffff           jmp 0x66c680
// library mfc-9.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filetxt.cpp
