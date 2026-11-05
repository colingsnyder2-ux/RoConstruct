// from server: 100% by auto
// roc 2007-08 00711600  unit: CXTColorSelectorCtrl  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00711600
//
// 00711600  8bc1                 mov eax, ecx
// 00711602  33c9                 xor ecx, ecx
// 00711604  89480c               mov dword ptr [eax + 0xc], ecx
// 00711607  894810               mov dword ptr [eax + 0x10], ecx
// 0071160a  894808               mov dword ptr [eax + 8], ecx
// 0071160d  894804               mov dword ptr [eax + 4], ecx
// 00711610  894814               mov dword ptr [eax + 0x14], ecx
// 00711613  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00711617  c7002ce57d00         mov dword ptr [eax], 0x7de52c
// 0071161d  894818               mov dword ptr [eax + 0x18], ecx
// 00711620  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
