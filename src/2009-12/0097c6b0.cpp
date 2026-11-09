// from server: 100% by auto
// roc 2009-12 0097c6b0  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c6b0
//
// 0097c6b0  b9c0aeb900           mov ecx, 0xb9aec0
// 0097c6b5  e8e623eaff           call 0x81eaa0
// 0097c6ba  6830a59800           push 0x98a530
// 0097c6bf  e86582e7ff           call 0x7f4929
// 0097c6c4  59                   pop ecx
// 0097c6c5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
