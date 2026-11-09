// from server: 100% by auto
// roc 2009-06 0073cee0  unit: CXTPToolBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073cee0
//
// 0073cee0  8b442404             mov eax, dword ptr [esp + 4]
// 0073cee4  85c0                 test eax, eax
// 0073cee6  750d                 jne 0x73cef5
// 0073cee8  50                   push eax
// 0073cee9  8b4104               mov eax, dword ptr [ecx + 4]
// 0073ceec  50                   push eax
// 0073ceed  e89af11000           call 0x84c08c
// 0073cef2  c20400               ret 4
// 0073cef5  8b4004               mov eax, dword ptr [eax + 4]
// 0073cef8  50                   push eax
// 0073cef9  8b4104               mov eax, dword ptr [ecx + 4]
// 0073cefc  50                   push eax
// 0073cefd  e88af11000           call 0x84c08c
// 0073cf02  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
