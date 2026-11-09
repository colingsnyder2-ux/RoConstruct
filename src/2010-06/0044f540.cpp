// from server: 100% by auto
// roc 2010-06 0044f540  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f540
//
// 0044f540  e819873500           call 0x7a7c5e
// 0044f545  8b4034               mov eax, dword ptr [eax + 0x34]
// 0044f548  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
