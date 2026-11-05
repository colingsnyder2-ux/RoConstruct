// from server: 100% by auto
// roc 2010-06 007bde00  unit: CXTPImageManagerResource::CBitmapDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bde00
//
// 007bde00  8b442404             mov eax, dword ptr [esp + 4]
// 007bde04  8b4904               mov ecx, dword ptr [ecx + 4]
// 007bde07  50                   push eax
// 007bde08  51                   push ecx
// 007bde09  ff1538a19e00         call dword ptr [0x9ea138]
// 007bde0f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?DrawFocusRect@CDC@@QAEXPBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
