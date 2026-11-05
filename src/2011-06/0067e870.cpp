// from server: 100% by auto
// roc 2011-06 0067e870  unit: RBX::KernelJoint  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0067e870
//
// 0067e870  8b442404             mov eax, dword ptr [esp + 4]
// 0067e874  50                   push eax
// 0067e875  e85672e5ff           call 0x4d5ad0
// 0067e87a  83c404               add esp, 4
// 0067e87d  89442404             mov dword ptr [esp + 4], eax
// 0067e881  e98af7ffff           jmp 0x67e010
// library mfc-9.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filetxt.cpp
