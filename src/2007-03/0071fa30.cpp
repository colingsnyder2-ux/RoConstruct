// from server: 100% by auto
// roc 2007-03 0071fa30  unit: seg_00710000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071fa30
//
// 0071fa30  8bc1                 mov eax, ecx
// 0071fa32  33c9                 xor ecx, ecx
// 0071fa34  c700403a7e00         mov dword ptr [eax], 0x7e3a40
// 0071fa3a  894804               mov dword ptr [eax + 4], ecx
// 0071fa3d  894810               mov dword ptr [eax + 0x10], ecx
// 0071fa40  89480c               mov dword ptr [eax + 0xc], ecx
// 0071fa43  894808               mov dword ptr [eax + 8], ecx
// 0071fa46  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
