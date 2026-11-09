// from server: 100% by auto
// roc 2012-06 004c16b0  unit: RBX::?1??ViewRbxGfx_InitModule::ViewRbxGfxFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c16b0
//
// 004c16b0  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 004c16b6  f30f1009             movss xmm1, dword ptr [ecx]
// 004c16ba  f30f59c8             mulss xmm1, xmm0
// 004c16be  8bc2                 mov eax, edx
// 004c16c0  f30f1108             movss dword ptr [eax], xmm1
// 004c16c4  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 004c16c9  f30f59c8             mulss xmm1, xmm0
// 004c16cd  f30f114804           movss dword ptr [eax + 4], xmm1
// 004c16d2  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 004c16d7  f30f59c8             mulss xmm1, xmm0
// 004c16db  f30f114808           movss dword ptr [eax + 8], xmm1
// 004c16e0  c20400               ret 4
// library rbx2016-g3d/AABox.cpp (function ??DVector3@G3D@@QBI?AV01@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
