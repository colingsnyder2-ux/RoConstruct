// from server: 100% by auto
// roc 2009-12 008c1f10  unit: CXTPImageEditorDlg::CDlgToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1f10
//
// 008c1f10  56                   push esi
// 008c1f11  8bf1                 mov esi, ecx
// 008c1f13  e83022f3ff           call 0x7f4148
// 008c1f18  33c0                 xor eax, eax
// 008c1f1a  894654               mov dword ptr [esi + 0x54], eax
// 008c1f1d  894658               mov dword ptr [esi + 0x58], eax
// 008c1f20  c706c48ba000         mov dword ptr [esi], 0xa08bc4
// 008c1f26  8bc6                 mov eax, esi
// 008c1f28  5e                   pop esi
// 008c1f29  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
