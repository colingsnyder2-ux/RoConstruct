// from server: 100% by auto
// roc 2009-06 00723360  unit: RBX::Network::Players::Plugin  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723360
//
// 00723360  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00723364  8b4908               mov ecx, dword ptr [ecx + 8]
// 00723367  83ec08               sub esp, 8
// 0072336a  8d0424               lea eax, [esp]
// 0072336d  50                   push eax
// 0072336e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00723372  52                   push edx
// 00723373  50                   push eax
// 00723374  51                   push ecx
// 00723375  ff1550e18900         call dword ptr [0x89e150]
// 0072337b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072337f  8b1424               mov edx, dword ptr [esp]
// 00723382  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00723386  8910                 mov dword ptr [eax], edx
// 00723388  894804               mov dword ptr [eax + 4], ecx
// 0072338b  83c408               add esp, 8
// 0072338e  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxstatusbar.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstatusbar.cpp
