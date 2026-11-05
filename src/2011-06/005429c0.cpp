// from server: 100% by auto
// roc 2011-06 005429c0  unit: G3D::Sphere  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005429c0
//
// 005429c0  0f57c0               xorps xmm0, xmm0
// 005429c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005429c7  56                   push esi
// 005429c8  8b742408             mov esi, dword ptr [esp + 8]
// 005429cc  57                   push edi
// 005429cd  8b39                 mov edi, dword ptr [ecx]
// 005429cf  8d5608               lea edx, [esi + 8]
// 005429d2  8d4604               lea eax, [esi + 4]
// 005429d5  52                   push edx
// 005429d6  50                   push eax
// 005429d7  f30f1100             movss dword ptr [eax], xmm0
// 005429db  8b4728               mov eax, dword ptr [edi + 0x28]
// 005429de  56                   push esi
// 005429df  f30f1106             movss dword ptr [esi], xmm0
// 005429e3  f30f1102             movss dword ptr [edx], xmm0
// 005429e7  ffd0                 call eax
// 005429e9  5f                   pop edi
// 005429ea  8bc6                 mov eax, esi
// 005429ec  5e                   pop esi
// 005429ed  c3                   ret 
// library rbx2016-g3d/Vector3.cpp (function ?random@Vector3@G3D@@SA?AV12@AAVRandom@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
