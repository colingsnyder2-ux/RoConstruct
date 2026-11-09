// from server: 100% by auto
// roc 2010-06 00405060  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00405060
//
// 00405060  8b442404             mov eax, dword ptr [esp + 4]
// 00405064  83c004               add eax, 4
// 00405067  89442404             mov dword ptr [esp + 4], eax
// 0040506b  ff2580a39e00         jmp dword ptr [0x9ea380]
// library mfc-9.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlpbag.cpp
