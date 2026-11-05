// from server: 100% by auto
// roc 2010-06 007cbeb0  unit: CXTPCommandBarsOptions  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cbeb0
//
// 007cbeb0  8b442404             mov eax, dword ptr [esp + 4]
// 007cbeb4  85c0                 test eax, eax
// 007cbeb6  750d                 jne 0x7cbec5
// 007cbeb8  50                   push eax
// 007cbeb9  8b4104               mov eax, dword ptr [ecx + 4]
// 007cbebc  50                   push eax
// 007cbebd  e872101b00           call 0x97cf34
// 007cbec2  c20400               ret 4
// 007cbec5  8b4004               mov eax, dword ptr [eax + 4]
// 007cbec8  50                   push eax
// 007cbec9  8b4104               mov eax, dword ptr [ecx + 4]
// 007cbecc  50                   push eax
// 007cbecd  e862101b00           call 0x97cf34
// 007cbed2  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
