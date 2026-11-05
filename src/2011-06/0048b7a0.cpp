// from server: 100% by auto
// roc 2011-06 0048b7a0  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048b7a0
//
// 0048b7a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0048b7a4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048b7a8  50                   push eax
// 0048b7a9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048b7ad  52                   push edx
// 0048b7ae  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048b7b2  50                   push eax
// 0048b7b3  52                   push edx
// 0048b7b4  51                   push ecx
// 0048b7b5  ff15c81ba400         call dword ptr [0xa41bc8]
// 0048b7bb  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
