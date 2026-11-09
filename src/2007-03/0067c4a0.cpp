// from server: 100% by auto
// roc 2007-03 0067c4a0  unit: seg_00670000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067c4a0
//
// 0067c4a0  8bc1                 mov eax, ecx
// 0067c4a2  33c9                 xor ecx, ecx
// 0067c4a4  c700d8d57c00         mov dword ptr [eax], 0x7cd5d8
// 0067c4aa  894804               mov dword ptr [eax + 4], ecx
// 0067c4ad  894810               mov dword ptr [eax + 0x10], ecx
// 0067c4b0  89480c               mov dword ptr [eax + 0xc], ecx
// 0067c4b3  894808               mov dword ptr [eax + 8], ecx
// 0067c4b6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
