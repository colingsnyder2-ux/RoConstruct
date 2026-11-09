// from server: 100% by auto
// roc 2012-06 0062e110  unit: G3D::Line  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e110
//
// 0062e110  83ec1c               sub esp, 0x1c
// 0062e113  56                   push esi
// 0062e114  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062e118  f30f105010           movss xmm2, dword ptr [eax + 0x10]
// 0062e11d  f30f104014           movss xmm0, dword ptr [eax + 0x14]
// 0062e122  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 0062e127  f30f104818           movss xmm1, dword ptr [eax + 0x18]
// 0062e12c  f30f59e0             mulss xmm4, xmm0
// 0062e130  0f28da               movaps xmm3, xmm2
// 0062e133  f30f5919             mulss xmm3, dword ptr [ecx]
// 0062e137  f30f58dc             addss xmm3, xmm4
// 0062e13b  f30f106118           movss xmm4, dword ptr [ecx + 0x18]
// 0062e140  f30f59e1             mulss xmm4, xmm1
// 0062e144  f30f58dc             addss xmm3, xmm4
// 0062e148  f30f10611c           movss xmm4, dword ptr [ecx + 0x1c]
// 0062e14d  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 0062e153  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 0062e158  f30f59d8             mulss xmm3, xmm0
// 0062e15c  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 0062e161  f30f59e1             mulss xmm4, xmm1
// 0062e165  f30f594920           mulss xmm1, dword ptr [ecx + 0x20]
// 0062e16a  f30f58dc             addss xmm3, xmm4
// 0062e16e  f30f58c1             addss xmm0, xmm1
// 0062e172  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0062e177  f30f59ca             mulss xmm1, xmm2
// 0062e17b  f30f58c1             addss xmm0, xmm1
// 0062e17f  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062e184  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 0062e189  0f28e2               movaps xmm4, xmm2
// 0062e18c  f30f596104           mulss xmm4, dword ptr [ecx + 4]
// 0062e191  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 0062e196  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 0062e19b  f30f58dc             addss xmm3, xmm4
// 0062e19f  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 0062e1a4  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 0062e1aa  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 0062e1af  f30f59da             mulss xmm3, xmm2
// 0062e1b3  f30f59e1             mulss xmm4, xmm1
// 0062e1b7  f30f58dc             addss xmm3, xmm4
// 0062e1bb  f30f1021             movss xmm4, dword ptr [ecx]
// 0062e1bf  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 0062e1c5  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062e1ca  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 0062e1cf  f30f59e0             mulss xmm4, xmm0
// 0062e1d3  f30f58dc             addss xmm3, xmm4
// 0062e1d7  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 0062e1dc  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 0062e1e2  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 0062e1e7  f30f59da             mulss xmm3, xmm2
// 0062e1eb  f30f59e1             mulss xmm4, xmm1
// 0062e1ef  f30f58dc             addss xmm3, xmm4
// 0062e1f3  0f28e0               movaps xmm4, xmm0
// 0062e1f6  f30f596104           mulss xmm4, dword ptr [ecx + 4]
// 0062e1fb  f30f58dc             addss xmm3, xmm4
// 0062e1ff  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 0062e205  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0062e20a  f30f59d8             mulss xmm3, xmm0
// 0062e20e  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 0062e213  f30f59c2             mulss xmm0, xmm2
// 0062e217  8b742424             mov esi, dword ptr [esp + 0x24]
// 0062e21b  f30f58d8             addss xmm3, xmm0
// 0062e21f  f30f104114           movss xmm0, dword ptr [ecx + 0x14]
// 0062e224  8d442408             lea eax, [esp + 8]
// 0062e228  50                   push eax
// 0062e229  8d4c2418             lea ecx, [esp + 0x18]
// 0062e22d  51                   push ecx
// 0062e22e  f30f59c1             mulss xmm0, xmm1
// 0062e232  f30f58d8             addss xmm3, xmm0
// 0062e236  56                   push esi
// 0062e237  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062e23f  f30f115c2428         movss dword ptr [esp + 0x28], xmm3
// 0062e245  e856f6ffff           call 0x62d8a0
// 0062e24a  83c40c               add esp, 0xc
// 0062e24d  8bc6                 mov eax, esi
// 0062e24f  5e                   pop esi
// 0062e250  83c41c               add esp, 0x1c
// 0062e253  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toObjectSpace@CoordinateFrame@G3D@@QBE?AVRbxRay@RBX@@ABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
