// from server: 100% by auto
// roc 2012-06 00407240  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00407240
//
// 00407240  8b442404             mov eax, dword ptr [esp + 4]
// 00407244  83c004               add eax, 4
// 00407247  89442404             mov dword ptr [esp + 4], eax
// 0040724b  ff259821b200         jmp dword ptr [0xb22198]
// library mfc-9.0/atlmfc\src\mfc\ctlpbag.cpp (function ?AddRef@CBlobProperty@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlpbag.cpp
