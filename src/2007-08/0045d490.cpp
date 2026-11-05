// from server: 100% by auto
// roc 2007-08 0045d490  unit: Scintilla::CScintillaView  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045d490
//
// 0045d490  8b01                 mov eax, dword ptr [ecx]
// 0045d492  8b90a8010000         mov edx, dword ptr [eax + 0x1a8]
// 0045d498  6a00                 push 0
// 0045d49a  ffd2                 call edx
// 0045d49c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winsplit.cpp (function ?OnCancelMode@CSplitterWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winsplit.cpp
