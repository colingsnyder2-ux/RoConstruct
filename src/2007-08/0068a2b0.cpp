// from server: 100% by auto
// roc 2007-08 0068a2b0  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068a2b0
//
// 0068a2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0068a2b4  85c0                 test eax, eax
// 0068a2b6  750e                 jne 0x68a2c6
// 0068a2b8  50                   push eax
// 0068a2b9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0068a2bc  50                   push eax
// 0068a2bd  ff1574ee7700         call dword ptr [0x77ee74]
// 0068a2c3  c20400               ret 4
// 0068a2c6  8b4020               mov eax, dword ptr [eax + 0x20]
// 0068a2c9  50                   push eax
// 0068a2ca  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0068a2cd  50                   push eax
// 0068a2ce  ff1574ee7700         call dword ptr [0x77ee74]
// 0068a2d4  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlinplc.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlinplc.cpp
