// from server: 100% by auto
// roc 2009-12 00870670  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870670
//
// 00870670  8bc1                 mov eax, ecx
// 00870672  33c9                 xor ecx, ecx
// 00870674  89480c               mov dword ptr [eax + 0xc], ecx
// 00870677  894810               mov dword ptr [eax + 0x10], ecx
// 0087067a  894808               mov dword ptr [eax + 8], ecx
// 0087067d  894804               mov dword ptr [eax + 4], ecx
// 00870680  894814               mov dword ptr [eax + 0x14], ecx
// 00870683  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00870687  c700680da000         mov dword ptr [eax], 0xa00d68
// 0087068d  894818               mov dword ptr [eax + 0x18], ecx
// 00870690  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
