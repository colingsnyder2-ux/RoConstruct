// from server: 100% by auto
// roc 2011-06 00462610  unit: CRobloxApp  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00462610
//
// 00462610  8b442404             mov eax, dword ptr [esp + 4]
// 00462614  56                   push esi
// 00462615  8bf1                 mov esi, ecx
// 00462617  85c0                 test eax, eax
// 00462619  7513                 jne 0x46262e
// 0046261b  50                   push eax
// 0046261c  ff158401a400         call dword ptr [0xa40184]
// 00462622  50                   push eax
// 00462623  8bce                 mov ecx, esi
// 00462625  e8cc873a00           call 0x80adf6
// 0046262a  5e                   pop esi
// 0046262b  c20400               ret 4
// 0046262e  8b4004               mov eax, dword ptr [eax + 4]
// 00462631  50                   push eax
// 00462632  ff158401a400         call dword ptr [0xa40184]
// 00462638  50                   push eax
// 00462639  8bce                 mov ecx, esi
// 0046263b  e8b6873a00           call 0x80adf6
// 00462640  5e                   pop esi
// 00462641  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
