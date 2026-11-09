// from server: 100% by auto
// roc 2010-06 007bdde0  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdde0
//
// 007bdde0  8b442408             mov eax, dword ptr [esp + 8]
// 007bdde4  8b542404             mov edx, dword ptr [esp + 4]
// 007bdde8  50                   push eax
// 007bdde9  8b4104               mov eax, dword ptr [ecx + 4]
// 007bddec  52                   push edx
// 007bdded  50                   push eax
// 007bddee  ff153ca19e00         call dword ptr [0x9ea13c]
// 007bddf4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?Polygon@CDC@@QAEHPBUtagPOINT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
