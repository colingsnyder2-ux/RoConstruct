// from server: 100% by auto
// roc 2009-12 0046b400  unit: Scintilla::CScintillaView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046b400
//
// 0046b400  8b442404             mov eax, dword ptr [esp + 4]
// 0046b404  8b5004               mov edx, dword ptr [eax + 4]
// 0046b407  56                   push esi
// 0046b408  8b30                 mov esi, dword ptr [eax]
// 0046b40a  57                   push edi
// 0046b40b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046b40f  57                   push edi
// 0046b410  8b780c               mov edi, dword ptr [eax + 0xc]
// 0046b413  8b4008               mov eax, dword ptr [eax + 8]
// 0046b416  2bfa                 sub edi, edx
// 0046b418  57                   push edi
// 0046b419  2bc6                 sub eax, esi
// 0046b41b  50                   push eax
// 0046b41c  52                   push edx
// 0046b41d  56                   push esi
// 0046b41e  e80f883800           call 0x7f3c32
// 0046b423  5f                   pop edi
// 0046b424  5e                   pop esi
// 0046b425  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlppg.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlppg.cpp
