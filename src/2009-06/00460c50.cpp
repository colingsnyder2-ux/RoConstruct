// from server: 100% by auto
// roc 2009-06 00460c50  unit: Scintilla::CScintillaCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00460c50
//
// 00460c50  56                   push esi
// 00460c51  8bf1                 mov esi, ecx
// 00460c53  e8c8862b00           call 0x719320
// 00460c58  33c0                 xor eax, eax
// 00460c5a  894654               mov dword ptr [esi + 0x54], eax
// 00460c5d  894658               mov dword ptr [esi + 0x58], eax
// 00460c60  c70614b18b00         mov dword ptr [esi], 0x8bb114
// 00460c66  8bc6                 mov eax, esi
// 00460c68  5e                   pop esi
// 00460c69  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
