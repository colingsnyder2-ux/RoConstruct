// from server: 100% by auto
// roc 2009-12 008c12a0  unit: CXTPImageEditorPicker  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c12a0
//
// 008c12a0  8b442404             mov eax, dword ptr [esp + 4]
// 008c12a4  56                   push esi
// 008c12a5  57                   push edi
// 008c12a6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008c12aa  57                   push edi
// 008c12ab  8bf1                 mov esi, ecx
// 008c12ad  50                   push eax
// 008c12ae  897e54               mov dword ptr [esi + 0x54], edi
// 008c12b1  e884530600           call 0x92663a
// 008c12b6  8b8f600a0000         mov ecx, dword ptr [edi + 0xa60]
// 008c12bc  6a00                 push 0
// 008c12be  894e58               mov dword ptr [esi + 0x58], ecx
// 008c12c1  8b97640a0000         mov edx, dword ptr [edi + 0xa64]
// 008c12c7  6a00                 push 0
// 008c12c9  6800000200           push 0x20000
// 008c12ce  8bce                 mov ecx, esi
// 008c12d0  89565c               mov dword ptr [esi + 0x5c], edx
// 008c12d3  e8282bf3ff           call 0x7f3e00
// 008c12d8  5f                   pop edi
// 008c12d9  5e                   pop esi
// 008c12da  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Init@CXTPImageEditorPreview@@QAEXIPAVCXTPImageEditorDlg@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
