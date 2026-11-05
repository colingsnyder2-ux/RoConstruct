// from server: 100% by auto
// roc 2010-06 0046d2f0  unit: Scintilla::CScintillaCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046d2f0
//
// 0046d2f0  56                   push esi
// 0046d2f1  8bf1                 mov esi, ecx
// 0046d2f3  e890af3300           call 0x7a8288
// 0046d2f8  33c0                 xor eax, eax
// 0046d2fa  894654               mov dword ptr [esi + 0x54], eax
// 0046d2fd  894658               mov dword ptr [esi + 0x58], eax
// 0046d300  c7063403a100         mov dword ptr [esi], 0xa10334
// 0046d306  8bc6                 mov eax, esi
// 0046d308  5e                   pop esi
// 0046d309  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
