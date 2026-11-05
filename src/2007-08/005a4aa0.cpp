// from server: 100% by auto
// roc 2007-08 005a4aa0  unit: RBX::VRunService::?$Listener  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a4aa0
//
// 005a4aa0  8b442404             mov eax, dword ptr [esp + 4]
// 005a4aa4  50                   push eax
// 005a4aa5  e8960defff           call 0x495840
// 005a4aaa  83c404               add esp, 4
// 005a4aad  89442404             mov dword ptr [esp + 4], eax
// 005a4ab1  e99afdffff           jmp 0x5a4850
// library mfc-8.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/filetxt.cpp
