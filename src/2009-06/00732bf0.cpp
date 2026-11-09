// from server: 100% by auto
// roc 2009-06 00732bf0  unit: CXTPImageManagerResource::CBitmapDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732bf0
//
// 00732bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00732bf4  8b4904               mov ecx, dword ptr [ecx + 4]
// 00732bf7  50                   push eax
// 00732bf8  51                   push ecx
// 00732bf9  ff15ace08900         call dword ptr [0x89e0ac]
// 00732bff  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?DrawFocusRect@CDC@@QAEXPBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
