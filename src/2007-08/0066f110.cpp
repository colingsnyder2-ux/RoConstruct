// from server: 100% by auto
// roc 2007-08 0066f110  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0066f110
//
// 0066f110  8bc1                 mov eax, ecx
// 0066f112  33c9                 xor ecx, ecx
// 0066f114  89480c               mov dword ptr [eax + 0xc], ecx
// 0066f117  894810               mov dword ptr [eax + 0x10], ecx
// 0066f11a  894808               mov dword ptr [eax + 8], ecx
// 0066f11d  894804               mov dword ptr [eax + 4], ecx
// 0066f120  894814               mov dword ptr [eax + 0x14], ecx
// 0066f123  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0066f127  c70078b37c00         mov dword ptr [eax], 0x7cb378
// 0066f12d  894818               mov dword ptr [eax + 0x18], ecx
// 0066f130  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
