// from server: 100% by auto
// roc 2011-06 009c5450  unit: seg_009c0000  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c5450
//
// 009c5450  8bc1                 mov eax, ecx
// 009c5452  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009c5456  0fb611               movzx edx, byte ptr [ecx]
// 009c5459  f30f2ac2             cvtsi2ss xmm0, edx
// 009c545d  f30f1100             movss dword ptr [eax], xmm0
// 009c5461  0fb65101             movzx edx, byte ptr [ecx + 1]
// 009c5465  f30f1008             movss xmm1, dword ptr [eax]
// 009c5469  f30f2ac2             cvtsi2ss xmm0, edx
// 009c546d  f30f114004           movss dword ptr [eax + 4], xmm0
// 009c5472  0fb65102             movzx edx, byte ptr [ecx + 2]
// 009c5476  f30f2ac2             cvtsi2ss xmm0, edx
// 009c547a  f30f114008           movss dword ptr [eax + 8], xmm0
// 009c547f  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 009c5483  f30f2ac1             cvtsi2ss xmm0, ecx
// 009c5487  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 009c548c  f30f10052091a600     movss xmm0, dword ptr [0xa69120]
// 009c5494  f30f59c8             mulss xmm1, xmm0
// 009c5498  f30f1108             movss dword ptr [eax], xmm1
// 009c549c  f30f104804           movss xmm1, dword ptr [eax + 4]
// 009c54a1  f30f59c8             mulss xmm1, xmm0
// 009c54a5  f30f114804           movss dword ptr [eax + 4], xmm1
// 009c54aa  f30f104808           movss xmm1, dword ptr [eax + 8]
// 009c54af  f30f59c8             mulss xmm1, xmm0
// 009c54b3  f30f114808           movss dword ptr [eax + 8], xmm1
// 009c54b8  f30f10480c           movss xmm1, dword ptr [eax + 0xc]
// 009c54bd  f30f59c8             mulss xmm1, xmm0
// 009c54c1  f30f11480c           movss dword ptr [eax + 0xc], xmm1
// 009c54c6  c20400               ret 4
// library rbx2016-g3d/Color4.cpp (function ??0Color4@G3D@@QAE@ABVColor4uint8@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
