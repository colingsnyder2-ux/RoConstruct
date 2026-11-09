// from server: 100% by auto
// roc 2010-06 00876130  unit: CXTPImageEditorDlg::CDlgToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876130
//
// 00876130  56                   push esi
// 00876131  8bf1                 mov esi, ecx
// 00876133  e85021f3ff           call 0x7a8288
// 00876138  33c0                 xor eax, eax
// 0087613a  894654               mov dword ptr [esi + 0x54], eax
// 0087613d  894658               mov dword ptr [esi + 0x58], eax
// 00876140  c706accea600         mov dword ptr [esi], 0xa6ceac
// 00876146  8bc6                 mov eax, esi
// 00876148  5e                   pop esi
// 00876149  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
