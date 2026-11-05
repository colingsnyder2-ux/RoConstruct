// from server: 100% by auto
// roc 2007-08 00709c60  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00709c60
//
// 00709c60  8bc1                 mov eax, ecx
// 00709c62  33c9                 xor ecx, ecx
// 00709c64  89480c               mov dword ptr [eax + 0xc], ecx
// 00709c67  894810               mov dword ptr [eax + 0x10], ecx
// 00709c6a  894808               mov dword ptr [eax + 8], ecx
// 00709c6d  894804               mov dword ptr [eax + 4], ecx
// 00709c70  894814               mov dword ptr [eax + 0x14], ecx
// 00709c73  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00709c77  c700a4d57d00         mov dword ptr [eax], 0x7dd5a4
// 00709c7d  894818               mov dword ptr [eax + 0x18], ecx
// 00709c80  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
