// from server: 100% by auto
// roc 2012-06 00627340  unit: seg_00620000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00627340
//
// 00627340  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00627348  f30f5e442408         divss xmm0, dword ptr [esp + 8]
// 0062734e  8b442404             mov eax, dword ptr [esp + 4]
// 00627352  f30f1009             movss xmm1, dword ptr [ecx]
// 00627356  f30f59c8             mulss xmm1, xmm0
// 0062735a  f30f1108             movss dword ptr [eax], xmm1
// 0062735e  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00627363  f30f59c8             mulss xmm1, xmm0
// 00627367  f30f114804           movss dword ptr [eax + 4], xmm1
// 0062736c  c20800               ret 8
// library rbx2016-g3d/Vector2.cpp (function ??KVector2@G3D@@QBE?AV01@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector2.cpp
