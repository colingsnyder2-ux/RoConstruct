// from server: 100% by auto
// roc 2008-06 006c4920  unit: CXTPToolBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c4920
//
// 006c4920  8b442404             mov eax, dword ptr [esp + 4]
// 006c4924  85c0                 test eax, eax
// 006c4926  750d                 jne 0x6c4935
// 006c4928  50                   push eax
// 006c4929  8b4104               mov eax, dword ptr [ecx + 4]
// 006c492c  50                   push eax
// 006c492d  e84c780f00           call 0x7bc17e
// 006c4932  c20400               ret 4
// 006c4935  8b4004               mov eax, dword ptr [eax + 4]
// 006c4938  50                   push eax
// 006c4939  8b4104               mov eax, dword ptr [ecx + 4]
// 006c493c  50                   push eax
// 006c493d  e83c780f00           call 0x7bc17e
// 006c4942  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
