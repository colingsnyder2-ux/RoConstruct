// from server: 100% by auto
// roc 2009-06 00406010  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00406010
//
// 00406010  8b442404             mov eax, dword ptr [esp + 4]
// 00406014  83c004               add eax, 4
// 00406017  89442404             mov dword ptr [esp + 4], eax
// 0040601b  ff25d0e18900         jmp dword ptr [0x89e1d0]
// library mfc-9.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlpbag.cpp
