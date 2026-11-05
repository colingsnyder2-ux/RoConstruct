// from server: 100% by auto
// roc 2011-06 004a35f0  unit: RBX::DS::CVideoStreamFilter  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004a35f0
//
// 004a35f0  f30f1001             movss xmm0, dword ptr [ecx]
// 004a35f4  8bc2                 mov eax, edx
// 004a35f6  8b542404             mov edx, dword ptr [esp + 4]
// 004a35fa  f30f5c02             subss xmm0, dword ptr [edx]
// 004a35fe  f30f1100             movss dword ptr [eax], xmm0
// 004a3602  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004a3607  f30f5c4204           subss xmm0, dword ptr [edx + 4]
// 004a360c  f30f114004           movss dword ptr [eax + 4], xmm0
// 004a3611  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 004a3616  f30f5c4208           subss xmm0, dword ptr [edx + 8]
// 004a361b  f30f114008           movss dword ptr [eax + 8], xmm0
// 004a3620  c20400               ret 4
// library rbx2016-g3d/AABox.cpp (function ??GVector3@G3D@@QBI?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
