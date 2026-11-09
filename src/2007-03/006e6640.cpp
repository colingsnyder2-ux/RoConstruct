// from server: 100% by auto
// roc 2007-03 006e6640  unit: seg_006e0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e6640
//
// 006e6640  8bc1                 mov eax, ecx
// 006e6642  33c9                 xor ecx, ecx
// 006e6644  c70084997d00         mov dword ptr [eax], 0x7d9984
// 006e664a  894804               mov dword ptr [eax + 4], ecx
// 006e664d  894810               mov dword ptr [eax + 0x10], ecx
// 006e6650  89480c               mov dword ptr [eax + 0xc], ecx
// 006e6653  894808               mov dword ptr [eax + 8], ecx
// 006e6656  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
