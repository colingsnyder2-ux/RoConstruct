// from server: 100% by auto
// roc 2007-03 00404760  unit: seg_00400000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00404760
//
// 00404760  8b442404             mov eax, dword ptr [esp + 4]
// 00404764  83c004               add eax, 4
// 00404767  89442404             mov dword ptr [esp + 4], eax
// 0040476b  ff25acd27700         jmp dword ptr [0x77d2ac]
// library mfc-8.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlpbag.cpp
