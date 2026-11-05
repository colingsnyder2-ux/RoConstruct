// from server: 100% by auto
// roc 2011-06 00541110  unit: G3D::MemoryManager  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541110
//
// 00541110  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 00541116  8bc1                 mov eax, ecx
// 00541118  f30f1100             movss dword ptr [eax], xmm0
// 0054111c  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 00541122  f30f114004           movss dword ptr [eax + 4], xmm0
// 00541127  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 0054112d  f30f114008           movss dword ptr [eax + 8], xmm0
// 00541132  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 00541138  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 0054113d  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 00541143  f30f114010           movss dword ptr [eax + 0x10], xmm0
// 00541148  f30f10442418         movss xmm0, dword ptr [esp + 0x18]
// 0054114e  f30f114014           movss dword ptr [eax + 0x14], xmm0
// 00541153  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 00541159  f30f114018           movss dword ptr [eax + 0x18], xmm0
// 0054115e  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 00541164  f30f11401c           movss dword ptr [eax + 0x1c], xmm0
// 00541169  f30f10442424         movss xmm0, dword ptr [esp + 0x24]
// 0054116f  f30f114020           movss dword ptr [eax + 0x20], xmm0
// 00541174  c22400               ret 0x24
// library rbx2016-g3d/Matrix3.cpp (function ??0Matrix3@G3D@@QAE@MMMMMMMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
