// from server: 100% by auto
// roc 2007-03 00702960  unit: seg_00700000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00702960
//
// 00702960  8bc1                 mov eax, ecx
// 00702962  33c9                 xor ecx, ecx
// 00702964  89480c               mov dword ptr [eax + 0xc], ecx
// 00702967  894810               mov dword ptr [eax + 0x10], ecx
// 0070296a  894808               mov dword ptr [eax + 8], ecx
// 0070296d  894804               mov dword ptr [eax + 4], ecx
// 00702970  894814               mov dword ptr [eax + 0x14], ecx
// 00702973  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00702977  c70014d27d00         mov dword ptr [eax], 0x7dd214
// 0070297d  894818               mov dword ptr [eax + 0x18], ecx
// 00702980  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
