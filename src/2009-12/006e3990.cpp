// from server: 100% by auto
// roc 2009-12 006e3990  unit: RBX::RotatePJoint  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e3990
//
// 006e3990  8b442404             mov eax, dword ptr [esp + 4]
// 006e3994  50                   push eax
// 006e3995  e816bbe3ff           call 0x51f4b0
// 006e399a  83c404               add esp, 4
// 006e399d  89442404             mov dword ptr [esp + 4], eax
// 006e39a1  e98af7ffff           jmp 0x6e3130
// library mfc-8.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/filetxt.cpp
