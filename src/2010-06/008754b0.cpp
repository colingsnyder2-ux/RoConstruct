// from server: 100% by auto
// roc 2010-06 008754b0  unit: CXTPImageEditorPicker  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008754b0
//
// 008754b0  8b442404             mov eax, dword ptr [esp + 4]
// 008754b4  56                   push esi
// 008754b5  57                   push edi
// 008754b6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008754ba  57                   push edi
// 008754bb  8bf1                 mov esi, ecx
// 008754bd  50                   push eax
// 008754be  897e54               mov dword ptr [esi + 0x54], edi
// 008754c1  e8b07a1000           call 0x97cf76
// 008754c6  8b8f600a0000         mov ecx, dword ptr [edi + 0xa60]
// 008754cc  6a00                 push 0
// 008754ce  894e58               mov dword ptr [esi + 0x58], ecx
// 008754d1  8b97640a0000         mov edx, dword ptr [edi + 0xa64]
// 008754d7  6a00                 push 0
// 008754d9  6800000200           push 0x20000
// 008754de  8bce                 mov ecx, esi
// 008754e0  89565c               mov dword ptr [esi + 0x5c], edx
// 008754e3  e85e2af3ff           call 0x7a7f46
// 008754e8  5f                   pop edi
// 008754e9  5e                   pop esi
// 008754ea  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Init@CXTPImageEditorPreview@@QAEXIPAVCXTPImageEditorDlg@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
