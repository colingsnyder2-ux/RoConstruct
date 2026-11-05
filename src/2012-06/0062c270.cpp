// from server: 100% by auto
// roc 2012-06 0062c270  unit: G3D::Sphere  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c270
//
// 0062c270  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 0062c276  f30f1101             movss dword ptr [ecx], xmm0
// 0062c27a  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 0062c280  f30f114104           movss dword ptr [ecx + 4], xmm0
// 0062c285  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 0062c28b  f30f114108           movss dword ptr [ecx + 8], xmm0
// 0062c290  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 0062c296  f30f11410c           movss dword ptr [ecx + 0xc], xmm0
// 0062c29b  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 0062c2a1  f30f114110           movss dword ptr [ecx + 0x10], xmm0
// 0062c2a6  f30f10442418         movss xmm0, dword ptr [esp + 0x18]
// 0062c2ac  f30f114114           movss dword ptr [ecx + 0x14], xmm0
// 0062c2b1  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 0062c2b7  f30f114118           movss dword ptr [ecx + 0x18], xmm0
// 0062c2bc  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 0062c2c2  f30f11411c           movss dword ptr [ecx + 0x1c], xmm0
// 0062c2c7  f30f10442424         movss xmm0, dword ptr [esp + 0x24]
// 0062c2cd  f30f114120           movss dword ptr [ecx + 0x20], xmm0
// 0062c2d2  c22400               ret 0x24
// library rbx2016-g3d/Matrix3.cpp (function ?set@Matrix3@G3D@@QAEXMMMMMMMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
