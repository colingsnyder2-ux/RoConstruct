// from server: 100% by auto
// roc 2011-06 00540210  unit: G3D::MemoryManager  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00540210
//
// 00540210  83ec18               sub esp, 0x18
// 00540213  8b442420             mov eax, dword ptr [esp + 0x20]
// 00540217  f30f1000             movss xmm0, dword ptr [eax]
// 0054021b  f30f105818           movss xmm3, dword ptr [eax + 0x18]
// 00540220  f30f10600c           movss xmm4, dword ptr [eax + 0xc]
// 00540225  f30f11442420         movss dword ptr [esp + 0x20], xmm0
// 0054022b  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00540230  f30f11442404         movss dword ptr [esp + 4], xmm0
// 00540236  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0054023b  f30f11442408         movss dword ptr [esp + 8], xmm0
// 00540241  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00540246  f30f110424           movss dword ptr [esp], xmm0
// 0054024b  f30f104020           movss xmm0, dword ptr [eax + 0x20]
// 00540250  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00540256  f30f104014           movss xmm0, dword ptr [eax + 0x14]
// 0054025b  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 00540261  f30f104008           movss xmm0, dword ptr [eax + 8]
// 00540266  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054026a  56                   push esi
// 0054026b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00540271  83c104               add ecx, 4
// 00540274  8d5008               lea edx, [eax + 8]
// 00540277  be03000000           mov esi, 3
// 0054027c  8d642400             lea esp, [esp]
// 00540280  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00540285  f30f1041fc           movss xmm0, dword ptr [ecx - 4]
// 0054028a  f30f1011             movss xmm2, dword ptr [ecx]
// 0054028e  0f28e8               movaps xmm5, xmm0
// 00540291  f30f596c2424         mulss xmm5, dword ptr [esp + 0x24]
// 00540297  0f28f1               movaps xmm6, xmm1
// 0054029a  f30f59f3             mulss xmm6, xmm3
// 0054029e  f30f58ee             addss xmm5, xmm6
// 005402a2  0f28f2               movaps xmm6, xmm2
// 005402a5  f30f59f4             mulss xmm6, xmm4
// 005402a9  f30f58ee             addss xmm5, xmm6
// 005402ad  f30f116af8           movss dword ptr [edx - 8], xmm5
// 005402b2  0f28e8               movaps xmm5, xmm0
// 005402b5  f30f596c2404         mulss xmm5, dword ptr [esp + 4]
// 005402bb  f30f59442410         mulss xmm0, dword ptr [esp + 0x10]
// 005402c1  0f28f1               movaps xmm6, xmm1
// 005402c4  f30f59742408         mulss xmm6, dword ptr [esp + 8]
// 005402ca  f30f594c2414         mulss xmm1, dword ptr [esp + 0x14]
// 005402d0  f30f58ee             addss xmm5, xmm6
// 005402d4  0f28f2               movaps xmm6, xmm2
// 005402d7  f30f5974240c         mulss xmm6, dword ptr [esp + 0xc]
// 005402dd  f30f59542418         mulss xmm2, dword ptr [esp + 0x18]
// 005402e3  f30f58c1             addss xmm0, xmm1
// 005402e7  f30f58ee             addss xmm5, xmm6
// 005402eb  f30f58c2             addss xmm0, xmm2
// 005402ef  f30f116afc           movss dword ptr [edx - 4], xmm5
// 005402f4  f30f1102             movss dword ptr [edx], xmm0
// 005402f8  83c10c               add ecx, 0xc
// 005402fb  83c20c               add edx, 0xc
// 005402fe  83ee01               sub esi, 1
// 00540301  0f8579ffffff         jne 0x540280
// 00540307  5e                   pop esi
// 00540308  83c418               add esp, 0x18
// 0054030b  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??DMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
