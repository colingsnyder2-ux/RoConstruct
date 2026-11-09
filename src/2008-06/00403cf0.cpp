// from server: 100% by auto
// roc 2008-06 00403cf0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403cf0
//
// 00403cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00403cf4  83c004               add eax, 4
// 00403cf7  89442404             mov dword ptr [esp + 4], eax
// 00403cfb  ff25b0218000         jmp dword ptr [0x8021b0]
// library mfc-9.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlpbag.cpp
