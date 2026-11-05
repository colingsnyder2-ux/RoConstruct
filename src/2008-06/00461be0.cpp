// from server: 100% by auto
// roc 2008-06 00461be0  unit: Scintilla::CScintillaView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00461be0
//
// 00461be0  8b442404             mov eax, dword ptr [esp + 4]
// 00461be4  8b5004               mov edx, dword ptr [eax + 4]
// 00461be7  56                   push esi
// 00461be8  8b30                 mov esi, dword ptr [eax]
// 00461bea  57                   push edi
// 00461beb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00461bef  57                   push edi
// 00461bf0  8b780c               mov edi, dword ptr [eax + 0xc]
// 00461bf3  8b4008               mov eax, dword ptr [eax + 8]
// 00461bf6  2bfa                 sub edi, edx
// 00461bf8  57                   push edi
// 00461bf9  2bc6                 sub eax, esi
// 00461bfb  50                   push eax
// 00461bfc  52                   push edx
// 00461bfd  56                   push esi
// 00461bfe  e849ee2300           call 0x6a0a4c
// 00461c03  5f                   pop edi
// 00461c04  5e                   pop esi
// 00461c05  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
