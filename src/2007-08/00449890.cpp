// from server: 100% by auto
// roc 2007-08 00449890  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00449890
//
// 00449890  e86d661e00           call 0x62ff02
// 00449895  8b4034               mov eax, dword ptr [eax + 0x34]
// 00449898  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
