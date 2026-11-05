// from server: 100% by auto
// roc 2009-12 008c0240  unit: CXTPShadowsManager::CShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c0240
//
// 008c0240  8bc1                 mov eax, ecx
// 008c0242  33c9                 xor ecx, ecx
// 008c0244  89480c               mov dword ptr [eax + 0xc], ecx
// 008c0247  894810               mov dword ptr [eax + 0x10], ecx
// 008c024a  894808               mov dword ptr [eax + 8], ecx
// 008c024d  894804               mov dword ptr [eax + 4], ecx
// 008c0250  894814               mov dword ptr [eax + 0x14], ecx
// 008c0253  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c0257  c7000489a000         mov dword ptr [eax], 0xa08904
// 008c025d  894818               mov dword ptr [eax + 0x18], ecx
// 008c0260  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
