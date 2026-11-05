// from server: 100% by auto
// roc 2008-06 006ba6b0  unit: CXTPImageManagerResource::CBitmapDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba6b0
//
// 006ba6b0  8b442404             mov eax, dword ptr [esp + 4]
// 006ba6b4  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ba6b7  50                   push eax
// 006ba6b8  51                   push ecx
// 006ba6b9  ff1588208000         call dword ptr [0x802088]
// 006ba6bf  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?DrawFocusRect@CDC@@QAEXPBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
