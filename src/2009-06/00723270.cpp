// from server: 100% by auto
// roc 2009-06 00723270  unit: RBX::Network::Players::Plugin  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723270
//
// 00723270  8b442404             mov eax, dword ptr [esp + 4]
// 00723274  56                   push esi
// 00723275  8bf1                 mov esi, ecx
// 00723277  85c0                 test eax, eax
// 00723279  7513                 jne 0x72328e
// 0072327b  50                   push eax
// 0072327c  ff1520e18900         call dword ptr [0x89e120]
// 00723282  50                   push eax
// 00723283  8bce                 mov ecx, esi
// 00723285  e8ac8c1200           call 0x84bf36
// 0072328a  5e                   pop esi
// 0072328b  c20400               ret 4
// 0072328e  8b4004               mov eax, dword ptr [eax + 4]
// 00723291  50                   push eax
// 00723292  ff1520e18900         call dword ptr [0x89e120]
// 00723298  50                   push eax
// 00723299  8bce                 mov ecx, esi
// 0072329b  e8968c1200           call 0x84bf36
// 007232a0  5e                   pop esi
// 007232a1  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
