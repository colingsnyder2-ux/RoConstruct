// from server: 100% by auto
// roc 2007-03 0063fb40  unit: seg_00630000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063fb40
//
// 0063fb40  8b442404             mov eax, dword ptr [esp + 4]
// 0063fb44  85c0                 test eax, eax
// 0063fb46  750d                 jne 0x63fb55
// 0063fb48  50                   push eax
// 0063fb49  8b4104               mov eax, dword ptr [ecx + 4]
// 0063fb4c  50                   push eax
// 0063fb4d  e89cb00f00           call 0x73abee
// 0063fb52  c20400               ret 4
// 0063fb55  8b4004               mov eax, dword ptr [eax + 4]
// 0063fb58  50                   push eax
// 0063fb59  8b4104               mov eax, dword ptr [ecx + 4]
// 0063fb5c  50                   push eax
// 0063fb5d  e88cb00f00           call 0x73abee
// 0063fb62  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?SelectObject@CDC@@QAEPAVCBitmap@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
