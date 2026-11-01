// from server: 100% by auto
// roc 2009-12 0046b390  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046b390
//
// 0046b390  8b442410             mov eax, dword ptr [esp + 0x10]
// 0046b394  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046b398  50                   push eax
// 0046b399  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046b39d  52                   push edx
// 0046b39e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046b3a2  50                   push eax
// 0046b3a3  52                   push edx
// 0046b3a4  51                   push ecx
// 0046b3a5  ff1538ca9800         call dword ptr [0x98ca38]
// 0046b3ab  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
