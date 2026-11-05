// from server: 100% by auto
// roc 2009-12 007fe120  unit: CXTPPaintManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe120
//
// 007fe120  8b442404             mov eax, dword ptr [esp + 4]
// 007fe124  56                   push esi
// 007fe125  8bf1                 mov esi, ecx
// 007fe127  85c0                 test eax, eax
// 007fe129  7513                 jne 0x7fe13e
// 007fe12b  50                   push eax
// 007fe12c  ff1554b19800         call dword ptr [0x98b154]
// 007fe132  50                   push eax
// 007fe133  8bce                 mov ecx, esi
// 007fe135  e862831200           call 0x92649c
// 007fe13a  5e                   pop esi
// 007fe13b  c20400               ret 4
// 007fe13e  8b4004               mov eax, dword ptr [eax + 4]
// 007fe141  50                   push eax
// 007fe142  ff1554b19800         call dword ptr [0x98b154]
// 007fe148  50                   push eax
// 007fe149  8bce                 mov ecx, esi
// 007fe14b  e84c831200           call 0x92649c
// 007fe150  5e                   pop esi
// 007fe151  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
