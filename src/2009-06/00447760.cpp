// from server: 100% by auto
// roc 2009-06 00447760  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447760
//
// 00447760  e891152d00           call 0x718cf6
// 00447765  8b4034               mov eax, dword ptr [eax + 0x34]
// 00447768  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
