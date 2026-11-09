// from server: 100% by auto
// roc 2008-06 00461b70  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00461b70
//
// 00461b70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00461b74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00461b78  50                   push eax
// 00461b79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00461b7d  52                   push edx
// 00461b7e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00461b82  50                   push eax
// 00461b83  52                   push edx
// 00461b84  51                   push ecx
// 00461b85  ff15102d8000         call dword ptr [0x802d10]
// 00461b8b  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
