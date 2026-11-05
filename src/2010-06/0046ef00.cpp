// from server: 100% by auto
// roc 2010-06 0046ef00  unit: Scintilla::CScintillaView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046ef00
//
// 0046ef00  8b442404             mov eax, dword ptr [esp + 4]
// 0046ef04  8b5004               mov edx, dword ptr [eax + 4]
// 0046ef07  56                   push esi
// 0046ef08  8b30                 mov esi, dword ptr [eax]
// 0046ef0a  57                   push edi
// 0046ef0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046ef0f  57                   push edi
// 0046ef10  8b780c               mov edi, dword ptr [eax + 0xc]
// 0046ef13  8b4008               mov eax, dword ptr [eax + 8]
// 0046ef16  2bfa                 sub edi, edx
// 0046ef18  57                   push edi
// 0046ef19  2bc6                 sub eax, esi
// 0046ef1b  50                   push eax
// 0046ef1c  52                   push edx
// 0046ef1d  56                   push esi
// 0046ef1e  e84f8e3300           call 0x7a7d72
// 0046ef23  5f                   pop edi
// 0046ef24  5e                   pop esi
// 0046ef25  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
