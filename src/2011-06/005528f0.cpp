// from server: 100% by auto
// roc 2011-06 005528f0  unit: G3D::Sphere  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005528f0
//
// 005528f0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005528f3  8b442404             mov eax, dword ptr [esp + 4]
// 005528f7  8910                 mov dword ptr [eax], edx
// 005528f9  8b5114               mov edx, dword ptr [ecx + 0x14]
// 005528fc  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005528ff  895004               mov dword ptr [eax + 4], edx
// 00552902  894808               mov dword ptr [eax + 8], ecx
// 00552905  c20400               ret 4
// library rbx2016-g3d/Line.cpp (function ?direction@Line@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Line.cpp
