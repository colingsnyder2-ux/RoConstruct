// from server: 100% by auto
// roc 2011-06 004068b0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004068b0
//
// 004068b0  8b442404             mov eax, dword ptr [esp + 4]
// 004068b4  83c004               add eax, 4
// 004068b7  89442404             mov dword ptr [esp + 4], eax
// 004068bb  ff254c03a400         jmp dword ptr [0xa4034c]
// library mfc-9.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlpbag.cpp
