// from server: 100% by auto
// roc 2007-03 00625af0  unit: seg_00620000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625af0
//
// 00625af0  8b442404             mov eax, dword ptr [esp + 4]
// 00625af4  85c0                 test eax, eax
// 00625af6  56                   push esi
// 00625af7  8bf1                 mov esi, ecx
// 00625af9  7513                 jne 0x625b0e
// 00625afb  50                   push eax
// 00625afc  ff15f0d07700         call dword ptr [0x77d0f0]
// 00625b02  50                   push eax
// 00625b03  8bce                 mov ecx, esi
// 00625b05  e8b24f1100           call 0x73aabc
// 00625b0a  5e                   pop esi
// 00625b0b  c20400               ret 4
// 00625b0e  8b4004               mov eax, dword ptr [eax + 4]
// 00625b11  50                   push eax
// 00625b12  ff15f0d07700         call dword ptr [0x77d0f0]
// 00625b18  50                   push eax
// 00625b19  8bce                 mov ecx, esi
// 00625b1b  e89c4f1100           call 0x73aabc
// 00625b20  5e                   pop esi
// 00625b21  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
