// from server: 100% by auto
// roc 2007-08 006f2600  unit: CXTPImageEditorDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f2600
//
// 006f2600  8bc1                 mov eax, ecx
// 006f2602  33c9                 xor ecx, ecx
// 006f2604  89480c               mov dword ptr [eax + 0xc], ecx
// 006f2607  894810               mov dword ptr [eax + 0x10], ecx
// 006f260a  894808               mov dword ptr [eax + 8], ecx
// 006f260d  894804               mov dword ptr [eax + 4], ecx
// 006f2610  894814               mov dword ptr [eax + 0x14], ecx
// 006f2613  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f2617  c700d4b67d00         mov dword ptr [eax], 0x7db6d4
// 006f261d  894818               mov dword ptr [eax + 0x18], ecx
// 006f2620  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
