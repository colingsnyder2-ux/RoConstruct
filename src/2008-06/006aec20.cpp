// from server: 100% by auto
// roc 2008-06 006aec20  unit: CXTPPaintManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aec20
//
// 006aec20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006aec24  8b542408             mov edx, dword ptr [esp + 8]
// 006aec28  8b4904               mov ecx, dword ptr [ecx + 4]
// 006aec2b  50                   push eax
// 006aec2c  8b442408             mov eax, dword ptr [esp + 8]
// 006aec30  52                   push edx
// 006aec31  50                   push eax
// 006aec32  51                   push ecx
// 006aec33  ff15b8208000         call dword ptr [0x8020b8]
// 006aec39  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?GetPaletteEntries@CPalette@@QBEIIIPAUtagPALETTEENTRY@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
