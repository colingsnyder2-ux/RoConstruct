// from server: 100% by auto
// roc 2011-06 00820190  unit: CXTPImageManagerResource::CBitmapDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820190
//
// 00820190  8b442404             mov eax, dword ptr [esp + 4]
// 00820194  8b4904               mov ecx, dword ptr [ecx + 4]
// 00820197  50                   push eax
// 00820198  51                   push ecx
// 00820199  ff15e800a400         call dword ptr [0xa400e8]
// 0082019f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?DrawFocusRect@CDC@@QAEXPBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
