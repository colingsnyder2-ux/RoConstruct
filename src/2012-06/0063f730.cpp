// from server: 100% by auto
// roc 2012-06 0063f730  unit: G3D::Sphere  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063f730
//
// 0063f730  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0063f733  8b442404             mov eax, dword ptr [esp + 4]
// 0063f737  8910                 mov dword ptr [eax], edx
// 0063f739  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0063f73c  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0063f73f  895004               mov dword ptr [eax + 4], edx
// 0063f742  894808               mov dword ptr [eax + 8], ecx
// 0063f745  c20400               ret 4
// library rbx2016-g3d/Line.cpp (function ?direction@Line@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Line.cpp
