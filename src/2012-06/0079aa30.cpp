// from server: 100% by auto
// roc 2012-06 0079aa30  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0079aa30
//
// 0079aa30  8b442404             mov eax, dword ptr [esp + 4]
// 0079aa34  50                   push eax
// 0079aa35  e8e60cdbff           call 0x54b720
// 0079aa3a  83c404               add esp, 4
// 0079aa3d  89442404             mov dword ptr [esp + 4], eax
// 0079aa41  e9fadbffff           jmp 0x798640
// library mfc-9.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filetxt.cpp
