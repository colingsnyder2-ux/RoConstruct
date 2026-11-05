// from server: 100% by auto
// roc 2010-06 0046ee90  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046ee90
//
// 0046ee90  8b442410             mov eax, dword ptr [esp + 0x10]
// 0046ee94  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046ee98  50                   push eax
// 0046ee99  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046ee9d  52                   push edx
// 0046ee9e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046eea2  50                   push eax
// 0046eea3  52                   push edx
// 0046eea4  51                   push ecx
// 0046eea5  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 0046eeab  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
