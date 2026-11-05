// from server: 100% by auto
// roc 2007-08 00712b70  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00712b70
//
// 00712b70  8bc1                 mov eax, ecx
// 00712b72  33c9                 xor ecx, ecx
// 00712b74  89480c               mov dword ptr [eax + 0xc], ecx
// 00712b77  894810               mov dword ptr [eax + 0x10], ecx
// 00712b7a  894808               mov dword ptr [eax + 8], ecx
// 00712b7d  894804               mov dword ptr [eax + 4], ecx
// 00712b80  894814               mov dword ptr [eax + 0x14], ecx
// 00712b83  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00712b87  c70014e97d00         mov dword ptr [eax], 0x7de914
// 00712b8d  894818               mov dword ptr [eax + 0x18], ecx
// 00712b90  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
