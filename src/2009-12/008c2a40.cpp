// from server: 100% by auto
// roc 2009-12 008c2a40  unit: CXTPImageEditorDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2a40
//
// 008c2a40  8bc1                 mov eax, ecx
// 008c2a42  33c9                 xor ecx, ecx
// 008c2a44  89480c               mov dword ptr [eax + 0xc], ecx
// 008c2a47  894810               mov dword ptr [eax + 0x10], ecx
// 008c2a4a  894808               mov dword ptr [eax + 8], ecx
// 008c2a4d  894804               mov dword ptr [eax + 4], ecx
// 008c2a50  894814               mov dword ptr [eax + 0x14], ecx
// 008c2a53  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c2a57  c7009c8ea000         mov dword ptr [eax], 0xa08e9c
// 008c2a5d  894818               mov dword ptr [eax + 0x18], ecx
// 008c2a60  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
