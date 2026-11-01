// from server: 100% by auto
// roc 2009-12 00405650  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00405650
//
// 00405650  8b442404             mov eax, dword ptr [esp + 4]
// 00405654  83c004               add eax, 4
// 00405657  89442404             mov dword ptr [esp + 4], eax
// 0040565b  ff250cb29800         jmp dword ptr [0x98b20c]
// library mfc-8.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlpbag.cpp
