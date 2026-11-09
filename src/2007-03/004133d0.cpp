// from server: 100% by auto
// roc 2007-03 004133d0  unit: seg_00410000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004133d0
//
// 004133d0  8b442404             mov eax, dword ptr [esp + 4]
// 004133d4  8b4008               mov eax, dword ptr [eax + 8]
// 004133d7  8b08                 mov ecx, dword ptr [eax]
// 004133d9  89442404             mov dword ptr [esp + 4], eax
// 004133dd  8b5108               mov edx, dword ptr [ecx + 8]
// 004133e0  ffe2                 jmp edx
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?Release@_AfxBindStatusCallback@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
