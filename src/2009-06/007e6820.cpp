// from server: 100% by auto
// roc 2009-06 007e6820  unit: CXTPImageEditorPicker  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e6820
//
// 007e6820  8b442404             mov eax, dword ptr [esp + 4]
// 007e6824  8b542408             mov edx, dword ptr [esp + 8]
// 007e6828  8981600a0000         mov dword ptr [ecx + 0xa60], eax
// 007e682e  8991640a0000         mov dword ptr [ecx + 0xa64], edx
// 007e6834  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetIconSize@CXTPImageEditorDlg@@QAEXVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
