// from server: 100% by auto
// roc 2009-12 0096dad0  unit: seg_00960000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096dad0
//
// 0096dad0  b9701ab800           mov ecx, 0xb81a70
// 0096dad5  e89629c0ff           call 0x570470
// 0096dada  68c00a9800           push 0x980ac0
// 0096dadf  e8456ee8ff           call 0x7f4929
// 0096dae4  59                   pop ecx
// 0096dae5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
