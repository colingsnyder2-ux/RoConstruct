// from server: 100% by auto
// roc 2009-06 007e67e0  unit: CXTPImageEditorPicker  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e67e0
//
// 007e67e0  8b442404             mov eax, dword ptr [esp + 4]
// 007e67e4  56                   push esi
// 007e67e5  57                   push edi
// 007e67e6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e67ea  57                   push edi
// 007e67eb  8bf1                 mov esi, ecx
// 007e67ed  50                   push eax
// 007e67ee  897e54               mov dword ptr [esi + 0x54], edi
// 007e67f1  e8d8580600           call 0x84c0ce
// 007e67f6  8b8f600a0000         mov ecx, dword ptr [edi + 0xa60]
// 007e67fc  6a00                 push 0
// 007e67fe  894e58               mov dword ptr [esi + 0x58], ecx
// 007e6801  8b97640a0000         mov edx, dword ptr [edi + 0xa64]
// 007e6807  6a00                 push 0
// 007e6809  6800000200           push 0x20000
// 007e680e  8bce                 mov ecx, esi
// 007e6810  89565c               mov dword ptr [esi + 0x5c], edx
// 007e6813  e8c027f3ff           call 0x718fd8
// 007e6818  5f                   pop edi
// 007e6819  5e                   pop esi
// 007e681a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Init@CXTPImageEditorPreview@@QAEXIPAVCXTPImageEditorDlg@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
