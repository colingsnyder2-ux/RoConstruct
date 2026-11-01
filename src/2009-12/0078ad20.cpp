// from server: 100% by auto
// roc 2009-12 0078ad20  unit: RBX::UniversalTool  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078ad20
//
// 0078ad20  8bc1                 mov eax, ecx
// 0078ad22  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078ad26  8b11                 mov edx, dword ptr [ecx]
// 0078ad28  8910                 mov dword ptr [eax], edx
// 0078ad2a  8b5104               mov edx, dword ptr [ecx + 4]
// 0078ad2d  895004               mov dword ptr [eax + 4], edx
// 0078ad30  8b4908               mov ecx, dword ptr [ecx + 8]
// 0078ad33  894808               mov dword ptr [eax + 8], ecx
// 0078ad36  85c9                 test ecx, ecx
// 0078ad38  740c                 je 0x78ad46
// 0078ad3a  83c108               add ecx, 8
// 0078ad3d  ba01000000           mov edx, 1
// 0078ad42  f00fc111             lock xadd dword ptr [ecx], edx
// 0078ad46  c20400               ret 4
// library templates-boost-1_34_1/map_int_wp.cpp (function ??0?$pair@$$CBHV?$weak_ptr@UT@@@boost@@@std@@QAE@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_wp.cpp
