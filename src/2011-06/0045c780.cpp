// from server: 100% by auto
// roc 2011-06 0045c780  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c780
//
// 0045c780  e897db3a00           call 0x80a31c
// 0045c785  8b4034               mov eax, dword ptr [eax + 0x34]
// 0045c788  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
