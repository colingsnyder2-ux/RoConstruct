// from server: 100% by auto
// roc 2007-03 004133b0  unit: seg_00410000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004133b0
//
// 004133b0  8b442404             mov eax, dword ptr [esp + 4]
// 004133b4  8b4008               mov eax, dword ptr [eax + 8]
// 004133b7  8b08                 mov ecx, dword ptr [eax]
// 004133b9  89442404             mov dword ptr [esp + 4], eax
// 004133bd  8b5104               mov edx, dword ptr [ecx + 4]
// 004133c0  ffe2                 jmp edx
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?AddRef@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
