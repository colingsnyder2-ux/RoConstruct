// from server: 100% by auto
// roc 2009-06 004627e0  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004627e0
//
// 004627e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004627e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004627e8  50                   push eax
// 004627e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004627ed  52                   push edx
// 004627ee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004627f2  50                   push eax
// 004627f3  52                   push edx
// 004627f4  51                   push ecx
// 004627f5  ff15a4ed8900         call dword ptr [0x89eda4]
// 004627fb  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
