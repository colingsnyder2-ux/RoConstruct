// from server: 100% by auto
// roc 2011-06 005528d0  unit: G3D::Sphere  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005528d0
//
// 005528d0  8b5104               mov edx, dword ptr [ecx + 4]
// 005528d3  8b442404             mov eax, dword ptr [esp + 4]
// 005528d7  8910                 mov dword ptr [eax], edx
// 005528d9  8b5108               mov edx, dword ptr [ecx + 8]
// 005528dc  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005528df  895004               mov dword ptr [eax + 4], edx
// 005528e2  894808               mov dword ptr [eax + 8], ecx
// 005528e5  c20400               ret 4
// library rbx2016-g3d/Line.cpp (function ?point@Line@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Line.cpp
