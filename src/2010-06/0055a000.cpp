// from server: 100% by auto
// roc 2010-06 0055a000  unit: G3D::BinaryInput  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0055a000
//
// 0055a000  f30f10057876a000     movss xmm0, dword ptr [0xa07678]
// 0055a008  8bc1                 mov eax, ecx
// 0055a00a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055a00e  0fb611               movzx edx, byte ptr [ecx]
// 0055a011  f30f2aca             cvtsi2ss xmm1, edx
// 0055a015  f30f59c8             mulss xmm1, xmm0
// 0055a019  f30f1108             movss dword ptr [eax], xmm1
// 0055a01d  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0055a021  f30f2aca             cvtsi2ss xmm1, edx
// 0055a025  f30f59c8             mulss xmm1, xmm0
// 0055a029  f30f114804           movss dword ptr [eax + 4], xmm1
// 0055a02e  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 0055a032  f30f2ac9             cvtsi2ss xmm1, ecx
// 0055a036  f30f59c8             mulss xmm1, xmm0
// 0055a03a  f30f114808           movss dword ptr [eax + 8], xmm1
// 0055a03f  c20400               ret 4
// library rbx2016-g3d/Color3.cpp (function ??0Color3@G3D@@QAE@ABVColor3uint8@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
