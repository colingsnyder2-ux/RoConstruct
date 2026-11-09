// from server: 100% by auto
// roc 2007-08 006e4410  unit: CXTPDockingPaneSplitterContainer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e4410
//
// 006e4410  8bc1                 mov eax, ecx
// 006e4412  33c9                 xor ecx, ecx
// 006e4414  89480c               mov dword ptr [eax + 0xc], ecx
// 006e4417  894810               mov dword ptr [eax + 0x10], ecx
// 006e441a  894808               mov dword ptr [eax + 8], ecx
// 006e441d  894804               mov dword ptr [eax + 4], ecx
// 006e4420  894814               mov dword ptr [eax + 0x14], ecx
// 006e4423  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006e4427  c70068a27d00         mov dword ptr [eax], 0x7da268
// 006e442d  894818               mov dword ptr [eax + 0x18], ecx
// 006e4430  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
