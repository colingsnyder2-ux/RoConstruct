// from server: 100% by auto
// roc 2011-06 0053fe20  unit: G3D::MemoryManager  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053fe20
//
// 0053fe20  f30f10052091a600     movss xmm0, dword ptr [0xa69120]
// 0053fe28  8bc1                 mov eax, ecx
// 0053fe2a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0053fe2e  0fb611               movzx edx, byte ptr [ecx]
// 0053fe31  f30f2aca             cvtsi2ss xmm1, edx
// 0053fe35  f30f59c8             mulss xmm1, xmm0
// 0053fe39  f30f1108             movss dword ptr [eax], xmm1
// 0053fe3d  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0053fe41  f30f2aca             cvtsi2ss xmm1, edx
// 0053fe45  f30f59c8             mulss xmm1, xmm0
// 0053fe49  f30f114804           movss dword ptr [eax + 4], xmm1
// 0053fe4e  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 0053fe52  f30f2ac9             cvtsi2ss xmm1, ecx
// 0053fe56  f30f59c8             mulss xmm1, xmm0
// 0053fe5a  f30f114808           movss dword ptr [eax + 8], xmm1
// 0053fe5f  c20400               ret 4
// library rbx2016-g3d/Color3.cpp (function ??0Color3@G3D@@QAE@ABVColor3uint8@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
