// from server: 100% by auto
// roc 2010-06 007adcc0  unit: CXTPPaintManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adcc0
//
// 007adcc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007adcc4  8b542408             mov edx, dword ptr [esp + 8]
// 007adcc8  8b4904               mov ecx, dword ptr [ecx + 4]
// 007adccb  50                   push eax
// 007adccc  8b442408             mov eax, dword ptr [esp + 8]
// 007adcd0  52                   push edx
// 007adcd1  50                   push eax
// 007adcd2  51                   push ecx
// 007adcd3  ff155ca19e00         call dword ptr [0x9ea15c]
// 007adcd9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?GetPaletteEntries@CPalette@@QBEIIIPAUtagPALETTEENTRY@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
