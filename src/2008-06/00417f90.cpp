// from server: 100% by auto
// roc 2008-06 00417f90  unit: VCContent::?$CComContainedObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417f90
//
// 00417f90  8b442404             mov eax, dword ptr [esp + 4]
// 00417f94  8b4008               mov eax, dword ptr [eax + 8]
// 00417f97  8b08                 mov ecx, dword ptr [eax]
// 00417f99  89442404             mov dword ptr [esp + 4], eax
// 00417f9d  8b5104               mov edx, dword ptr [ecx + 4]
// 00417fa0  ffe2                 jmp edx
// library mfc-9.0/atlmfc\src\mfc\oleasmon.cpp (function ?AddRef@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oleasmon.cpp
