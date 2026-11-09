// from server: 100% by auto
// roc 2007-08 0071e080  unit: CXTPDialogBar::CCaptionPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0071e080
//
// 0071e080  8b01                 mov eax, dword ptr [ecx]
// 0071e082  ffa0e0010000         jmp dword ptr [eax + 0x1e0]
// library mfc-8.0/atlmfc\src\mfc\viewhtml.cpp (function ??_9CHtmlView@@$BBOA@AE)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewhtml.cpp
