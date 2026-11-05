// from server: 100% by auto
// roc 2011-06 008100d0  unit: CXTPPaintManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008100d0
//
// 008100d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008100d4  8b542408             mov edx, dword ptr [esp + 8]
// 008100d8  8b4904               mov ecx, dword ptr [ecx + 4]
// 008100db  50                   push eax
// 008100dc  8b442408             mov eax, dword ptr [esp + 8]
// 008100e0  52                   push edx
// 008100e1  50                   push eax
// 008100e2  51                   push ecx
// 008100e3  ff150c01a400         call dword ptr [0xa4010c]
// 008100e9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?GetPaletteEntries@CPalette@@QBEIIIPAUtagPALETTEENTRY@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
