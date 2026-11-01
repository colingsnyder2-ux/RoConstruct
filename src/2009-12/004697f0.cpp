// from server: 100% by auto
// roc 2009-12 004697f0  unit: Scintilla::CScintillaCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004697f0
//
// 004697f0  56                   push esi
// 004697f1  8bf1                 mov esi, ecx
// 004697f3  e850a93800           call 0x7f4148
// 004697f8  33c0                 xor eax, eax
// 004697fa  894654               mov dword ptr [esi + 0x54], eax
// 004697fd  894658               mov dword ptr [esi + 0x58], eax
// 00469800  c706c4f69a00         mov dword ptr [esi], 0x9af6c4
// 00469806  8bc6                 mov eax, esi
// 00469808  5e                   pop esi
// 00469809  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
