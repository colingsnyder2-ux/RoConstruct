// from server: 100% by auto
// roc 2008-06 006aeb50  unit: CXTPPaintManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aeb50
//
// 006aeb50  8b442404             mov eax, dword ptr [esp + 4]
// 006aeb54  56                   push esi
// 006aeb55  8bf1                 mov esi, ecx
// 006aeb57  85c0                 test eax, eax
// 006aeb59  7513                 jne 0x6aeb6e
// 006aeb5b  50                   push eax
// 006aeb5c  ff15d0208000         call dword ptr [0x8020d0]
// 006aeb62  50                   push eax
// 006aeb63  8bce                 mov ecx, esi
// 006aeb65  e8dcd41000           call 0x7bc046
// 006aeb6a  5e                   pop esi
// 006aeb6b  c20400               ret 4
// 006aeb6e  8b4004               mov eax, dword ptr [eax + 4]
// 006aeb71  50                   push eax
// 006aeb72  ff15d0208000         call dword ptr [0x8020d0]
// 006aeb78  50                   push eax
// 006aeb79  8bce                 mov ecx, esi
// 006aeb7b  e8c6d41000           call 0x7bc046
// 006aeb80  5e                   pop esi
// 006aeb81  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
