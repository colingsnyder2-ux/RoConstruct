// from server: 100% by auto
// roc 2012-06 0062c000  unit: G3D::Sphere  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c000
//
// 0062c000  f30f1005303bb500     movss xmm0, dword ptr [0xb53b30]
// 0062c008  8bc1                 mov eax, ecx
// 0062c00a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062c00e  0fb611               movzx edx, byte ptr [ecx]
// 0062c011  f30f2aca             cvtsi2ss xmm1, edx
// 0062c015  f30f59c8             mulss xmm1, xmm0
// 0062c019  f30f1108             movss dword ptr [eax], xmm1
// 0062c01d  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0062c021  f30f2aca             cvtsi2ss xmm1, edx
// 0062c025  f30f59c8             mulss xmm1, xmm0
// 0062c029  f30f114804           movss dword ptr [eax + 4], xmm1
// 0062c02e  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 0062c032  f30f2ac9             cvtsi2ss xmm1, ecx
// 0062c036  f30f59c8             mulss xmm1, xmm0
// 0062c03a  f30f114808           movss dword ptr [eax + 8], xmm1
// 0062c03f  c20400               ret 4
// library rbx2016-g3d/Color3.cpp (function ??0Color3@G3D@@QAE@ABVColor3uint8@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
