// from server: 100% by auto
// roc 2009-12 007f6590  unit: CXTPPropertyGridItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6590
//
// 007f6590  8b442404             mov eax, dword ptr [esp + 4]
// 007f6594  8b5004               mov edx, dword ptr [eax + 4]
// 007f6597  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007f659a  52                   push edx
// 007f659b  50                   push eax
// 007f659c  ff15d8cb9800         call dword ptr [0x98cbd8]
// 007f65a2  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
