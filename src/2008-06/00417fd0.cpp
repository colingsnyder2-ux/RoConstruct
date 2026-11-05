// from server: 100% by auto
// roc 2008-06 00417fd0  unit: VCContent::?$CComContainedObject  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417fd0
//
// 00417fd0  8b442404             mov eax, dword ptr [esp + 4]
// 00417fd4  8b4008               mov eax, dword ptr [eax + 8]
// 00417fd7  8b08                 mov ecx, dword ptr [eax]
// 00417fd9  89442404             mov dword ptr [esp + 4], eax
// 00417fdd  8b01                 mov eax, dword ptr [ecx]
// 00417fdf  ffe0                 jmp eax
// library mfc-9.0/atlmfc\src\mfc\oleasmon.cpp (function ?QueryInterface@_AfxBindStatusCallback@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oleasmon.cpp
