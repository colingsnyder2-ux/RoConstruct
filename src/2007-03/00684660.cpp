// from server: 100% by auto
// roc 2007-03 00684660  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00684660
//
// 00684660  8bc1                 mov eax, ecx
// 00684662  33c9                 xor ecx, ecx
// 00684664  c700a0e37c00         mov dword ptr [eax], 0x7ce3a0
// 0068466a  894804               mov dword ptr [eax + 4], ecx
// 0068466d  894810               mov dword ptr [eax + 0x10], ecx
// 00684670  89480c               mov dword ptr [eax + 0xc], ecx
// 00684673  894808               mov dword ptr [eax + 8], ecx
// 00684676  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
