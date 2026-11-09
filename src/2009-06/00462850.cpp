// from server: 100% by auto
// roc 2009-06 00462850  unit: Scintilla::CScintillaView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00462850
//
// 00462850  8b442404             mov eax, dword ptr [esp + 4]
// 00462854  8b5004               mov edx, dword ptr [eax + 4]
// 00462857  56                   push esi
// 00462858  8b30                 mov esi, dword ptr [eax]
// 0046285a  57                   push edi
// 0046285b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046285f  57                   push edi
// 00462860  8b780c               mov edi, dword ptr [eax + 0xc]
// 00462863  8b4008               mov eax, dword ptr [eax + 8]
// 00462866  2bfa                 sub edi, edx
// 00462868  57                   push edi
// 00462869  2bc6                 sub eax, esi
// 0046286b  50                   push eax
// 0046286c  52                   push edx
// 0046286d  56                   push esi
// 0046286e  e897652b00           call 0x718e0a
// 00462873  5f                   pop edi
// 00462874  5e                   pop esi
// 00462875  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
