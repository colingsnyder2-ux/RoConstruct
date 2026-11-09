// from server: 100% by auto
// roc 2012-06 0063f710  unit: G3D::Sphere  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063f710
//
// 0063f710  8b5104               mov edx, dword ptr [ecx + 4]
// 0063f713  8b442404             mov eax, dword ptr [esp + 4]
// 0063f717  8910                 mov dword ptr [eax], edx
// 0063f719  8b5108               mov edx, dword ptr [ecx + 8]
// 0063f71c  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0063f71f  895004               mov dword ptr [eax + 4], edx
// 0063f722  894808               mov dword ptr [eax + 8], ecx
// 0063f725  c20400               ret 4
// library rbx2016-g3d/Line.cpp (function ?point@Line@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Line.cpp
