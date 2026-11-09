// from server: 100% by auto
// roc 2009-12 008557a0  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008557a0
//
// 008557a0  8b442404             mov eax, dword ptr [esp + 4]
// 008557a4  85c0                 test eax, eax
// 008557a6  750e                 jne 0x8557b6
// 008557a8  50                   push eax
// 008557a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008557ac  50                   push eax
// 008557ad  ff15f4ca9800         call dword ptr [0x98caf4]
// 008557b3  c20400               ret 4
// 008557b6  8b4020               mov eax, dword ptr [eax + 0x20]
// 008557b9  50                   push eax
// 008557ba  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008557bd  50                   push eax
// 008557be  ff15f4ca9800         call dword ptr [0x98caf4]
// 008557c4  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlinplc.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlinplc.cpp
