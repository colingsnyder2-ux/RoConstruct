// from server: 100% by auto
// roc 2009-12 008e3540  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e3540
//
// 008e3540  8bc1                 mov eax, ecx
// 008e3542  33c9                 xor ecx, ecx
// 008e3544  89480c               mov dword ptr [eax + 0xc], ecx
// 008e3547  894810               mov dword ptr [eax + 0x10], ecx
// 008e354a  894808               mov dword ptr [eax + 8], ecx
// 008e354d  894804               mov dword ptr [eax + 4], ecx
// 008e3550  894814               mov dword ptr [eax + 0x14], ecx
// 008e3553  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e3557  c70064c2a000         mov dword ptr [eax], 0xa0c264
// 008e355d  894818               mov dword ptr [eax + 0x18], ecx
// 008e3560  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
