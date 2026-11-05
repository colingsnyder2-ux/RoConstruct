// from server: 100% by auto
// roc 2008-06 00417fb0  unit: VCContent::?$CComContainedObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417fb0
//
// 00417fb0  8b442404             mov eax, dword ptr [esp + 4]
// 00417fb4  8b4008               mov eax, dword ptr [eax + 8]
// 00417fb7  8b08                 mov ecx, dword ptr [eax]
// 00417fb9  89442404             mov dword ptr [esp + 4], eax
// 00417fbd  8b5108               mov edx, dword ptr [ecx + 8]
// 00417fc0  ffe2                 jmp edx
// library mfc-9.0/atlmfc\src\mfc\oleasmon.cpp (function ?Release@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oleasmon.cpp
