// from server: 100% by auto
// roc 2009-06 007e7450  unit: CXTPImageEditorDlg::CDlgToolBar  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7450
//
// 007e7450  56                   push esi
// 007e7451  8bf1                 mov esi, ecx
// 007e7453  e8c81ef3ff           call 0x719320
// 007e7458  33c0                 xor eax, eax
// 007e745a  894654               mov dword ptr [esi + 0x54], eax
// 007e745d  894658               mov dword ptr [esi + 0x58], eax
// 007e7460  c70654879000         mov dword ptr [esi], 0x908754
// 007e7466  8bc6                 mov eax, esi
// 007e7468  5e                   pop esi
// 007e7469  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ??0CXTPImageEditorPicker@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
