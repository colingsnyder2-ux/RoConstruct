// from server: 100% by auto
// roc 2007-08 006efe30  unit: CXTPShadowsManager::CShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006efe30
//
// 006efe30  8bc1                 mov eax, ecx
// 006efe32  33c9                 xor ecx, ecx
// 006efe34  89480c               mov dword ptr [eax + 0xc], ecx
// 006efe37  894810               mov dword ptr [eax + 0x10], ecx
// 006efe3a  894808               mov dword ptr [eax + 8], ecx
// 006efe3d  894804               mov dword ptr [eax + 4], ecx
// 006efe40  894814               mov dword ptr [eax + 0x14], ecx
// 006efe43  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006efe47  c70064b17d00         mov dword ptr [eax], 0x7db164
// 006efe4d  894818               mov dword ptr [eax + 0x18], ecx
// 006efe50  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
