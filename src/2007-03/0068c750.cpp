// from server: 100% by auto
// roc 2007-03 0068c750  unit: seg_00680000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c750
//
// 0068c750  8bc1                 mov eax, ecx
// 0068c752  33c9                 xor ecx, ecx
// 0068c754  89480c               mov dword ptr [eax + 0xc], ecx
// 0068c757  894810               mov dword ptr [eax + 0x10], ecx
// 0068c75a  894808               mov dword ptr [eax + 8], ecx
// 0068c75d  894804               mov dword ptr [eax + 4], ecx
// 0068c760  894814               mov dword ptr [eax + 0x14], ecx
// 0068c763  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068c767  c70010007d00         mov dword ptr [eax], 0x7d0010
// 0068c76d  894818               mov dword ptr [eax + 0x18], ecx
// 0068c770  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
