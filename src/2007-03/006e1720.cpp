// from server: 100% by auto
// roc 2007-03 006e1720  unit: seg_006e0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e1720
//
// 006e1720  8bc1                 mov eax, ecx
// 006e1722  33c9                 xor ecx, ecx
// 006e1724  89480c               mov dword ptr [eax + 0xc], ecx
// 006e1727  894810               mov dword ptr [eax + 0x10], ecx
// 006e172a  894808               mov dword ptr [eax + 8], ecx
// 006e172d  894804               mov dword ptr [eax + 4], ecx
// 006e1730  894814               mov dword ptr [eax + 0x14], ecx
// 006e1733  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006e1737  c700a48c7d00         mov dword ptr [eax], 0x7d8ca4
// 006e173d  894818               mov dword ptr [eax + 0x18], ecx
// 006e1740  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
