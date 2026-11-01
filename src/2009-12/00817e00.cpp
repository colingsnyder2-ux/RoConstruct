// from server: 100% by auto
// roc 2009-12 00817e00  unit: CXTPCommandBarsOptions  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00817e00
//
// 00817e00  8b442404             mov eax, dword ptr [esp + 4]
// 00817e04  85c0                 test eax, eax
// 00817e06  750d                 jne 0x817e15
// 00817e08  50                   push eax
// 00817e09  8b4104               mov eax, dword ptr [ecx + 4]
// 00817e0c  50                   push eax
// 00817e0d  e8e6e71000           call 0x9265f8
// 00817e12  c20400               ret 4
// 00817e15  8b4004               mov eax, dword ptr [eax + 4]
// 00817e18  50                   push eax
// 00817e19  8b4104               mov eax, dword ptr [ecx + 4]
// 00817e1c  50                   push eax
// 00817e1d  e8d6e71000           call 0x9265f8
// 00817e22  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
