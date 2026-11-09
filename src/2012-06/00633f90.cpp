// from server: 100% by auto
// roc 2012-06 00633f90  unit: G3D::Random  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00633f90
//
// 00633f90  8bc1                 mov eax, ecx
// 00633f92  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00633f96  0fb611               movzx edx, byte ptr [ecx]
// 00633f99  f30f2ac2             cvtsi2ss xmm0, edx
// 00633f9d  f30f1100             movss dword ptr [eax], xmm0
// 00633fa1  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00633fa5  f30f1008             movss xmm1, dword ptr [eax]
// 00633fa9  f30f2ac2             cvtsi2ss xmm0, edx
// 00633fad  f30f114004           movss dword ptr [eax + 4], xmm0
// 00633fb2  0fb65102             movzx edx, byte ptr [ecx + 2]
// 00633fb6  f30f2ac2             cvtsi2ss xmm0, edx
// 00633fba  f30f114008           movss dword ptr [eax + 8], xmm0
// 00633fbf  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 00633fc3  f30f2ac1             cvtsi2ss xmm0, ecx
// 00633fc7  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 00633fcc  f30f1005303bb500     movss xmm0, dword ptr [0xb53b30]
// 00633fd4  f30f59c8             mulss xmm1, xmm0
// 00633fd8  f30f1108             movss dword ptr [eax], xmm1
// 00633fdc  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00633fe1  f30f59c8             mulss xmm1, xmm0
// 00633fe5  f30f114804           movss dword ptr [eax + 4], xmm1
// 00633fea  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00633fef  f30f59c8             mulss xmm1, xmm0
// 00633ff3  f30f114808           movss dword ptr [eax + 8], xmm1
// 00633ff8  f30f10480c           movss xmm1, dword ptr [eax + 0xc]
// 00633ffd  f30f59c8             mulss xmm1, xmm0
// 00634001  f30f11480c           movss dword ptr [eax + 0xc], xmm1
// 00634006  c20400               ret 4
// library rbx2016-g3d/Color4.cpp (function ??0Color4@G3D@@QAE@ABVColor4uint8@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
