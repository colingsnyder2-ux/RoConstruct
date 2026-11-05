// from server: 100% by auto
// roc 2009-12 008b4870  unit: CXTPDockingPaneSplitterContainer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b4870
//
// 008b4870  8bc1                 mov eax, ecx
// 008b4872  33c9                 xor ecx, ecx
// 008b4874  89480c               mov dword ptr [eax + 0xc], ecx
// 008b4877  894810               mov dword ptr [eax + 0x10], ecx
// 008b487a  894808               mov dword ptr [eax + 8], ecx
// 008b487d  894804               mov dword ptr [eax + 4], ecx
// 008b4880  894814               mov dword ptr [eax + 0x14], ecx
// 008b4883  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008b4887  c700d879a000         mov dword ptr [eax], 0xa079d8
// 008b488d  894818               mov dword ptr [eax + 0x18], ecx
// 008b4890  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
