// from server: 100% by auto
// roc 2007-08 004152e0  unit: VCContent::?$CComContainedObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004152e0
//
// 004152e0  8b442404             mov eax, dword ptr [esp + 4]
// 004152e4  8b4008               mov eax, dword ptr [eax + 8]
// 004152e7  8b08                 mov ecx, dword ptr [eax]
// 004152e9  89442404             mov dword ptr [esp + 4], eax
// 004152ed  8b5108               mov edx, dword ptr [ecx + 8]
// 004152f0  ffe2                 jmp edx
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?Release@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
