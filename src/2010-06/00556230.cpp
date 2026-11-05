// from server: 100% by auto
// roc 2010-06 00556230  unit: seg_00550000  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556230
//
// 00556230  83ec18               sub esp, 0x18
// 00556233  8b442420             mov eax, dword ptr [esp + 0x20]
// 00556237  f30f1000             movss xmm0, dword ptr [eax]
// 0055623b  f30f105818           movss xmm3, dword ptr [eax + 0x18]
// 00556240  f30f10600c           movss xmm4, dword ptr [eax + 0xc]
// 00556245  f30f11442420         movss dword ptr [esp + 0x20], xmm0
// 0055624b  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00556250  f30f11442404         movss dword ptr [esp + 4], xmm0
// 00556256  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0055625b  f30f11442408         movss dword ptr [esp + 8], xmm0
// 00556261  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00556266  f30f110424           movss dword ptr [esp], xmm0
// 0055626b  f30f104020           movss xmm0, dword ptr [eax + 0x20]
// 00556270  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00556276  f30f104014           movss xmm0, dword ptr [eax + 0x14]
// 0055627b  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 00556281  f30f104008           movss xmm0, dword ptr [eax + 8]
// 00556286  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055628a  56                   push esi
// 0055628b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00556291  83c104               add ecx, 4
// 00556294  8d5008               lea edx, [eax + 8]
// 00556297  be03000000           mov esi, 3
// 0055629c  8d642400             lea esp, [esp]
// 005562a0  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 005562a5  f30f1041fc           movss xmm0, dword ptr [ecx - 4]
// 005562aa  f30f1011             movss xmm2, dword ptr [ecx]
// 005562ae  0f28e8               movaps xmm5, xmm0
// 005562b1  f30f596c2424         mulss xmm5, dword ptr [esp + 0x24]
// 005562b7  0f28f1               movaps xmm6, xmm1
// 005562ba  f30f59f3             mulss xmm6, xmm3
// 005562be  f30f58ee             addss xmm5, xmm6
// 005562c2  0f28f2               movaps xmm6, xmm2
// 005562c5  f30f59f4             mulss xmm6, xmm4
// 005562c9  f30f58ee             addss xmm5, xmm6
// 005562cd  f30f116af8           movss dword ptr [edx - 8], xmm5
// 005562d2  0f28e8               movaps xmm5, xmm0
// 005562d5  f30f596c2404         mulss xmm5, dword ptr [esp + 4]
// 005562db  f30f59442410         mulss xmm0, dword ptr [esp + 0x10]
// 005562e1  0f28f1               movaps xmm6, xmm1
// 005562e4  f30f59742408         mulss xmm6, dword ptr [esp + 8]
// 005562ea  f30f594c2414         mulss xmm1, dword ptr [esp + 0x14]
// 005562f0  f30f58ee             addss xmm5, xmm6
// 005562f4  0f28f2               movaps xmm6, xmm2
// 005562f7  f30f5974240c         mulss xmm6, dword ptr [esp + 0xc]
// 005562fd  f30f59542418         mulss xmm2, dword ptr [esp + 0x18]
// 00556303  f30f58c1             addss xmm0, xmm1
// 00556307  f30f58ee             addss xmm5, xmm6
// 0055630b  f30f58c2             addss xmm0, xmm2
// 0055630f  f30f116afc           movss dword ptr [edx - 4], xmm5
// 00556314  f30f1102             movss dword ptr [edx], xmm0
// 00556318  83c10c               add ecx, 0xc
// 0055631b  83c20c               add edx, 0xc
// 0055631e  83ee01               sub esi, 1
// 00556321  0f8579ffffff         jne 0x5562a0
// 00556327  5e                   pop esi
// 00556328  83c418               add esp, 0x18
// 0055632b  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??DMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
