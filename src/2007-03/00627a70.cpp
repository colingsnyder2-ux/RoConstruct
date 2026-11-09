// from server: 100% by auto
// roc 2007-03 00627a70  unit: seg_00620000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00627a70
//
// 00627a70  8bc1                 mov eax, ecx
// 00627a72  33c9                 xor ecx, ecx
// 00627a74  c70050347c00         mov dword ptr [eax], 0x7c3450
// 00627a7a  894804               mov dword ptr [eax + 4], ecx
// 00627a7d  894810               mov dword ptr [eax + 0x10], ecx
// 00627a80  89480c               mov dword ptr [eax + 0xc], ecx
// 00627a83  894808               mov dword ptr [eax + 8], ecx
// 00627a86  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
