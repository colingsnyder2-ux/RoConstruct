// from server: 100% by auto
// roc 2007-08 00412470  unit: VCContent::?$CComContainedObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412470
//
// 00412470  8b442404             mov eax, dword ptr [esp + 4]
// 00412474  8b4008               mov eax, dword ptr [eax + 8]
// 00412477  8b08                 mov ecx, dword ptr [eax]
// 00412479  89442404             mov dword ptr [esp + 4], eax
// 0041247d  8b5104               mov edx, dword ptr [ecx + 4]
// 00412480  ffe2                 jmp edx
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?AddRef@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
