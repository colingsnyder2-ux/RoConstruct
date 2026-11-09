// from server: 100% by auto
// roc 2011-06 00542050  unit: G3D::Sphere  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542050
//
// 00542050  83ec1c               sub esp, 0x1c
// 00542053  56                   push esi
// 00542054  8b442428             mov eax, dword ptr [esp + 0x28]
// 00542058  f30f105010           movss xmm2, dword ptr [eax + 0x10]
// 0054205d  f30f104014           movss xmm0, dword ptr [eax + 0x14]
// 00542062  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 00542067  f30f104818           movss xmm1, dword ptr [eax + 0x18]
// 0054206c  f30f59e0             mulss xmm4, xmm0
// 00542070  0f28da               movaps xmm3, xmm2
// 00542073  f30f5919             mulss xmm3, dword ptr [ecx]
// 00542077  f30f58dc             addss xmm3, xmm4
// 0054207b  f30f106118           movss xmm4, dword ptr [ecx + 0x18]
// 00542080  f30f59e1             mulss xmm4, xmm1
// 00542084  f30f58dc             addss xmm3, xmm4
// 00542088  f30f10611c           movss xmm4, dword ptr [ecx + 0x1c]
// 0054208d  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 00542093  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 00542098  f30f59d8             mulss xmm3, xmm0
// 0054209c  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 005420a1  f30f59e1             mulss xmm4, xmm1
// 005420a5  f30f594920           mulss xmm1, dword ptr [ecx + 0x20]
// 005420aa  f30f58dc             addss xmm3, xmm4
// 005420ae  f30f58c1             addss xmm0, xmm1
// 005420b2  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 005420b7  f30f59ca             mulss xmm1, xmm2
// 005420bb  f30f58c1             addss xmm0, xmm1
// 005420bf  f30f104808           movss xmm1, dword ptr [eax + 8]
// 005420c4  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 005420c9  0f28e2               movaps xmm4, xmm2
// 005420cc  f30f596104           mulss xmm4, dword ptr [ecx + 4]
// 005420d1  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 005420d6  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 005420db  f30f58dc             addss xmm3, xmm4
// 005420df  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 005420e4  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 005420ea  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 005420ef  f30f59da             mulss xmm3, xmm2
// 005420f3  f30f59e1             mulss xmm4, xmm1
// 005420f7  f30f58dc             addss xmm3, xmm4
// 005420fb  f30f1021             movss xmm4, dword ptr [ecx]
// 005420ff  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00542105  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0054210a  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 0054210f  f30f59e0             mulss xmm4, xmm0
// 00542113  f30f58dc             addss xmm3, xmm4
// 00542117  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 0054211c  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 00542122  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 00542127  f30f59da             mulss xmm3, xmm2
// 0054212b  f30f59e1             mulss xmm4, xmm1
// 0054212f  f30f58dc             addss xmm3, xmm4
// 00542133  0f28e0               movaps xmm4, xmm0
// 00542136  f30f596104           mulss xmm4, dword ptr [ecx + 4]
// 0054213b  f30f58dc             addss xmm3, xmm4
// 0054213f  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 00542145  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0054214a  f30f59d8             mulss xmm3, xmm0
// 0054214e  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 00542153  f30f59c2             mulss xmm0, xmm2
// 00542157  8b742424             mov esi, dword ptr [esp + 0x24]
// 0054215b  f30f58d8             addss xmm3, xmm0
// 0054215f  f30f104114           movss xmm0, dword ptr [ecx + 0x14]
// 00542164  8d442408             lea eax, [esp + 8]
// 00542168  50                   push eax
// 00542169  8d4c2418             lea ecx, [esp + 0x18]
// 0054216d  51                   push ecx
// 0054216e  f30f59c1             mulss xmm0, xmm1
// 00542172  f30f58d8             addss xmm3, xmm0
// 00542176  56                   push esi
// 00542177  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0054217f  f30f115c2428         movss dword ptr [esp + 0x28], xmm3
// 00542185  e8e6f4ffff           call 0x541670
// 0054218a  83c40c               add esp, 0xc
// 0054218d  8bc6                 mov eax, esi
// 0054218f  5e                   pop esi
// 00542190  83c41c               add esp, 0x1c
// 00542193  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toObjectSpace@CoordinateFrame@G3D@@QBE?AVRbxRay@RBX@@ABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
