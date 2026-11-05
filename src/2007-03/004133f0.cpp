// from server: 100% by auto
// roc 2007-03 004133f0  unit: seg_00410000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004133f0
//
// 004133f0  8b442404             mov eax, dword ptr [esp + 4]
// 004133f4  8b4008               mov eax, dword ptr [eax + 8]
// 004133f7  8b08                 mov ecx, dword ptr [eax]
// 004133f9  89442404             mov dword ptr [esp + 4], eax
// 004133fd  8b01                 mov eax, dword ptr [ecx]
// 004133ff  ffe0                 jmp eax
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?QueryInterface@_AfxBindStatusCallback@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
