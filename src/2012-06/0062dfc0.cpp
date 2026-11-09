// from server: 100% by auto
// roc 2012-06 0062dfc0  unit: G3D::Line  size: 335 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062dfc0
//
// 0062dfc0  83ec34               sub esp, 0x34
// 0062dfc3  56                   push esi
// 0062dfc4  57                   push edi
// 0062dfc5  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0062dfc9  8d442424             lea eax, [esp + 0x24]
// 0062dfcd  8bf1                 mov esi, ecx
// 0062dfcf  50                   push eax
// 0062dfd0  8bcf                 mov ecx, edi
// 0062dfd2  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0062dfda  e851170100           call 0x63f730
// 0062dfdf  f30f1000             movss xmm0, dword ptr [eax]
// 0062dfe3  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0062dfe8  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062dfed  f30f106604           movss xmm4, dword ptr [esi + 4]
// 0062dff2  f30f59e2             mulss xmm4, xmm2
// 0062dff6  0f28d8               movaps xmm3, xmm0
// 0062dff9  f30f591e             mulss xmm3, dword ptr [esi]
// 0062dffd  f30f58dc             addss xmm3, xmm4
// 0062e001  0f28e1               movaps xmm4, xmm1
// 0062e004  f30f596608           mulss xmm4, dword ptr [esi + 8]
// 0062e009  f30f58dc             addss xmm3, xmm4
// 0062e00d  f30f106610           movss xmm4, dword ptr [esi + 0x10]
// 0062e012  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 0062e018  f30f105e0c           movss xmm3, dword ptr [esi + 0xc]
// 0062e01d  f30f59d8             mulss xmm3, xmm0
// 0062e021  f30f594618           mulss xmm0, dword ptr [esi + 0x18]
// 0062e026  f30f59e2             mulss xmm4, xmm2
// 0062e02a  f30f59561c           mulss xmm2, dword ptr [esi + 0x1c]
// 0062e02f  f30f58dc             addss xmm3, xmm4
// 0062e033  f30f106614           movss xmm4, dword ptr [esi + 0x14]
// 0062e038  f30f59e1             mulss xmm4, xmm1
// 0062e03c  f30f594e20           mulss xmm1, dword ptr [esi + 0x20]
// 0062e041  8d4c2430             lea ecx, [esp + 0x30]
// 0062e045  f30f58c2             addss xmm0, xmm2
// 0062e049  51                   push ecx
// 0062e04a  f30f58dc             addss xmm3, xmm4
// 0062e04e  f30f58c1             addss xmm0, xmm1
// 0062e052  8bcf                 mov ecx, edi
// 0062e054  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 0062e05a  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 0062e060  e8ab160100           call 0x63f710
// 0062e065  f30f1000             movss xmm0, dword ptr [eax]
// 0062e069  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0062e06e  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062e073  f30f106604           movss xmm4, dword ptr [esi + 4]
// 0062e078  f30f59e2             mulss xmm4, xmm2
// 0062e07c  0f28d8               movaps xmm3, xmm0
// 0062e07f  f30f591e             mulss xmm3, dword ptr [esi]
// 0062e083  f30f58dc             addss xmm3, xmm4
// 0062e087  0f28e1               movaps xmm4, xmm1
// 0062e08a  f30f596608           mulss xmm4, dword ptr [esi + 8]
// 0062e08f  f30f58dc             addss xmm3, xmm4
// 0062e093  f30f585e24           addss xmm3, dword ptr [esi + 0x24]
// 0062e098  f30f106610           movss xmm4, dword ptr [esi + 0x10]
// 0062e09d  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 0062e0a3  f30f105e0c           movss xmm3, dword ptr [esi + 0xc]
// 0062e0a8  f30f59d8             mulss xmm3, xmm0
// 0062e0ac  f30f594618           mulss xmm0, dword ptr [esi + 0x18]
// 0062e0b1  f30f59e2             mulss xmm4, xmm2
// 0062e0b5  f30f59561c           mulss xmm2, dword ptr [esi + 0x1c]
// 0062e0ba  f30f58dc             addss xmm3, xmm4
// 0062e0be  f30f106614           movss xmm4, dword ptr [esi + 0x14]
// 0062e0c3  f30f59e1             mulss xmm4, xmm1
// 0062e0c7  f30f594e20           mulss xmm1, dword ptr [esi + 0x20]
// 0062e0cc  f30f58c2             addss xmm0, xmm2
// 0062e0d0  8d54240c             lea edx, [esp + 0xc]
// 0062e0d4  52                   push edx
// 0062e0d5  f30f58dc             addss xmm3, xmm4
// 0062e0d9  f30f585e28           addss xmm3, dword ptr [esi + 0x28]
// 0062e0de  f30f58c1             addss xmm0, xmm1
// 0062e0e2  f30f58462c           addss xmm0, dword ptr [esi + 0x2c]
// 0062e0e7  8b742444             mov esi, dword ptr [esp + 0x44]
// 0062e0eb  8d44241c             lea eax, [esp + 0x1c]
// 0062e0ef  50                   push eax
// 0062e0f0  56                   push esi
// 0062e0f1  f30f115c2428         movss dword ptr [esp + 0x28], xmm3
// 0062e0f7  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 0062e0fd  e86ef6ffff           call 0x62d770
// 0062e102  83c40c               add esp, 0xc
// 0062e105  5f                   pop edi
// 0062e106  8bc6                 mov eax, esi
// 0062e108  5e                   pop esi
// 0062e109  83c434               add esp, 0x34
// 0062e10c  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toWorldSpace@CoordinateFrame@G3D@@QBE?AVLine@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
