// from server: 100% by auto
// roc 2007-08 00412490  unit: VCContent::?$CComContainedObject  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412490
//
// 00412490  8b442404             mov eax, dword ptr [esp + 4]
// 00412494  8b4008               mov eax, dword ptr [eax + 8]
// 00412497  8b08                 mov ecx, dword ptr [eax]
// 00412499  89442404             mov dword ptr [esp + 4], eax
// 0041249d  8b01                 mov eax, dword ptr [ecx]
// 0041249f  ffe0                 jmp eax
// library mfc-8.0/atlmfc\src\mfc\oleasmon.cpp (function ?QueryInterface@_AfxBindStatusCallback@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oleasmon.cpp
