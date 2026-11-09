// from server: 100% by auto
// roc 2012-06 0062e9b0  unit: G3D::Line  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e9b0
//
// 0062e9b0  0f57c0               xorps xmm0, xmm0
// 0062e9b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062e9b7  56                   push esi
// 0062e9b8  8b742408             mov esi, dword ptr [esp + 8]
// 0062e9bc  57                   push edi
// 0062e9bd  8b39                 mov edi, dword ptr [ecx]
// 0062e9bf  8d5608               lea edx, [esi + 8]
// 0062e9c2  8d4604               lea eax, [esi + 4]
// 0062e9c5  52                   push edx
// 0062e9c6  50                   push eax
// 0062e9c7  f30f1100             movss dword ptr [eax], xmm0
// 0062e9cb  8b4728               mov eax, dword ptr [edi + 0x28]
// 0062e9ce  56                   push esi
// 0062e9cf  f30f1106             movss dword ptr [esi], xmm0
// 0062e9d3  f30f1102             movss dword ptr [edx], xmm0
// 0062e9d7  ffd0                 call eax
// 0062e9d9  5f                   pop edi
// 0062e9da  8bc6                 mov eax, esi
// 0062e9dc  5e                   pop esi
// 0062e9dd  c3                   ret 
// library rbx2016-g3d/Vector3.cpp (function ?random@Vector3@G3D@@SA?AV12@AAVRandom@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
