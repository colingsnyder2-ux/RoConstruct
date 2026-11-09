// from server: 100% by auto
// roc 2007-08 00404860  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00404860
//
// 00404860  8b442404             mov eax, dword ptr [esp + 4]
// 00404864  83c004               add eax, 4
// 00404867  89442404             mov dword ptr [esp + 4], eax
// 0040486b  ff25ecd27700         jmp dword ptr [0x77d2ec]
// library mfc-8.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlpbag.cpp
