// from server: 100% by auto
// roc 2012-06 004ccb20  unit: Ogre::RbxMeshLoader  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ccb20
//
// 004ccb20  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 004ccb28  f30f1009             movss xmm1, dword ptr [ecx]
// 004ccb2c  0f57c8               xorps xmm1, xmm0
// 004ccb2f  8bc2                 mov eax, edx
// 004ccb31  f30f1108             movss dword ptr [eax], xmm1
// 004ccb35  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 004ccb3a  0f57c8               xorps xmm1, xmm0
// 004ccb3d  f30f114804           movss dword ptr [eax + 4], xmm1
// 004ccb42  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 004ccb47  0f57c8               xorps xmm1, xmm0
// 004ccb4a  f30f114808           movss dword ptr [eax + 8], xmm1
// 004ccb4f  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ??GVector3@G3D@@QBI?AV01@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
