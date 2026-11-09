// from server: 100% by auto
// roc 2007-08 0063d780  unit: CXTPPaintManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d780
//
// 0063d780  8b442404             mov eax, dword ptr [esp + 4]
// 0063d784  85c0                 test eax, eax
// 0063d786  56                   push esi
// 0063d787  8bf1                 mov esi, ecx
// 0063d789  7513                 jne 0x63d79e
// 0063d78b  50                   push eax
// 0063d78c  ff1548d17700         call dword ptr [0x77d148]
// 0063d792  50                   push eax
// 0063d793  8bce                 mov ecx, esi
// 0063d795  e836ac0f00           call 0x7383d0
// 0063d79a  5e                   pop esi
// 0063d79b  c20400               ret 4
// 0063d79e  8b4004               mov eax, dword ptr [eax + 4]
// 0063d7a1  50                   push eax
// 0063d7a2  ff1548d17700         call dword ptr [0x77d148]
// 0063d7a8  50                   push eax
// 0063d7a9  8bce                 mov ecx, esi
// 0063d7ab  e820ac0f00           call 0x7383d0
// 0063d7b0  5e                   pop esi
// 0063d7b1  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
