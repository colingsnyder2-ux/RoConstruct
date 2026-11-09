// from server: 100% by auto
// roc 2007-03 0065b100  unit: seg_00650000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065b100
//
// 0065b100  8bc1                 mov eax, ecx
// 0065b102  33c9                 xor ecx, ecx
// 0065b104  89480c               mov dword ptr [eax + 0xc], ecx
// 0065b107  894810               mov dword ptr [eax + 0x10], ecx
// 0065b10a  894808               mov dword ptr [eax + 8], ecx
// 0065b10d  894804               mov dword ptr [eax + 4], ecx
// 0065b110  894814               mov dword ptr [eax + 0x14], ecx
// 0065b113  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0065b117  c700c0837c00         mov dword ptr [eax], 0x7c83c0
// 0065b11d  894818               mov dword ptr [eax + 0x18], ecx
// 0065b120  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
