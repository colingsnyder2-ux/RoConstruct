// from server: 100% by auto
// roc 2009-06 00723340  unit: RBX::Network::Players::Plugin  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723340
//
// 00723340  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00723344  8b542408             mov edx, dword ptr [esp + 8]
// 00723348  8b4904               mov ecx, dword ptr [ecx + 4]
// 0072334b  50                   push eax
// 0072334c  8b442408             mov eax, dword ptr [esp + 8]
// 00723350  52                   push edx
// 00723351  50                   push eax
// 00723352  51                   push ecx
// 00723353  ff15d4e08900         call dword ptr [0x89e0d4]
// 00723359  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?GetPaletteEntries@CPalette@@QBEIIIPAUtagPALETTEENTRY@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
