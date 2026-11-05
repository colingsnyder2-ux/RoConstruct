// from server: 100% by auto
// roc 2007-08 0045d9e0  unit: Scintilla::CScintillaView  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045d9e0
//
// 0045d9e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0045d9e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0045d9e8  50                   push eax
// 0045d9e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045d9ed  52                   push edx
// 0045d9ee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0045d9f2  50                   push eax
// 0045d9f3  52                   push edx
// 0045d9f4  51                   push ecx
// 0045d9f5  ff1578ed7700         call dword ptr [0x77ed78]
// 0045d9fb  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
