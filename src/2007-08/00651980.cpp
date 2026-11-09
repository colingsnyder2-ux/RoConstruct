// from server: 100% by auto
// roc 2007-08 00651980  unit: CXTPToolBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00651980
//
// 00651980  8b442404             mov eax, dword ptr [esp + 4]
// 00651984  85c0                 test eax, eax
// 00651986  750d                 jne 0x651995
// 00651988  50                   push eax
// 00651989  8b4104               mov eax, dword ptr [ecx + 4]
// 0065198c  50                   push eax
// 0065198d  e8106b0e00           call 0x7384a2
// 00651992  c20400               ret 4
// 00651995  8b4004               mov eax, dword ptr [eax + 4]
// 00651998  50                   push eax
// 00651999  8b4104               mov eax, dword ptr [ecx + 4]
// 0065199c  50                   push eax
// 0065199d  e8006b0e00           call 0x7384a2
// 006519a2  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
