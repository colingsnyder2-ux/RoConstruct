// from server: 100% by auto
// roc 2011-06 0048b810  unit: Scintilla::CScintillaView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048b810
//
// 0048b810  8b442404             mov eax, dword ptr [esp + 4]
// 0048b814  8b5004               mov edx, dword ptr [eax + 4]
// 0048b817  56                   push esi
// 0048b818  8b30                 mov esi, dword ptr [eax]
// 0048b81a  57                   push edi
// 0048b81b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048b81f  57                   push edi
// 0048b820  8b780c               mov edi, dword ptr [eax + 0xc]
// 0048b823  8b4008               mov eax, dword ptr [eax + 8]
// 0048b826  2bfa                 sub edi, edx
// 0048b828  57                   push edi
// 0048b829  2bc6                 sub eax, esi
// 0048b82b  50                   push eax
// 0048b82c  52                   push edx
// 0048b82d  56                   push esi
// 0048b82e  e8fdeb3700           call 0x80a430
// 0048b833  5f                   pop edi
// 0048b834  5e                   pop esi
// 0048b835  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
