// from server: 100% by auto
// roc 2011-06 0053b3d0  unit: seg_00530000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053b3d0
//
// 0053b3d0  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053b3d8  f30f5e442408         divss xmm0, dword ptr [esp + 8]
// 0053b3de  8b442404             mov eax, dword ptr [esp + 4]
// 0053b3e2  f30f1009             movss xmm1, dword ptr [ecx]
// 0053b3e6  f30f59c8             mulss xmm1, xmm0
// 0053b3ea  f30f1108             movss dword ptr [eax], xmm1
// 0053b3ee  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0053b3f3  f30f59c8             mulss xmm1, xmm0
// 0053b3f7  f30f114804           movss dword ptr [eax + 4], xmm1
// 0053b3fc  c20800               ret 8
// library rbx2016-g3d/Vector2.cpp (function ??KVector2@G3D@@QBE?AV01@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector2.cpp
