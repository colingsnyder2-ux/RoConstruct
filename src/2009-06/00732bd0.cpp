// from server: 100% by auto
// roc 2009-06 00732bd0  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732bd0
//
// 00732bd0  8b442408             mov eax, dword ptr [esp + 8]
// 00732bd4  8b542404             mov edx, dword ptr [esp + 4]
// 00732bd8  50                   push eax
// 00732bd9  8b4104               mov eax, dword ptr [ecx + 4]
// 00732bdc  52                   push edx
// 00732bdd  50                   push eax
// 00732bde  ff15b0e08900         call dword ptr [0x89e0b0]
// 00732be4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?Polygon@CDC@@QAEHPBUtagPOINT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
