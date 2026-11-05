// from server: 100% by auto
// roc 2012-06 0062dd00  unit: G3D::Line  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062dd00
//
// 0062dd00  83ec1c               sub esp, 0x1c
// 0062dd03  56                   push esi
// 0062dd04  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062dd08  f30f105810           movss xmm3, dword ptr [eax + 0x10]
// 0062dd0d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062dd12  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062dd17  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 0062dd1c  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 0062dd21  f30f59c3             mulss xmm0, xmm3
// 0062dd25  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 0062dd2a  f30f59cb             mulss xmm1, xmm3
// 0062dd2e  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 0062dd33  f30f59d3             mulss xmm2, xmm3
// 0062dd37  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 0062dd3c  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 0062dd41  f30f59da             mulss xmm3, xmm2
// 0062dd45  f30f59e1             mulss xmm4, xmm1
// 0062dd49  f30f58dc             addss xmm3, xmm4
// 0062dd4d  f30f1021             movss xmm4, dword ptr [ecx]
// 0062dd51  f30f59e0             mulss xmm4, xmm0
// 0062dd55  f30f58dc             addss xmm3, xmm4
// 0062dd59  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 0062dd5f  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 0062dd64  f30f59d8             mulss xmm3, xmm0
// 0062dd68  0f28e2               movaps xmm4, xmm2
// 0062dd6b  f30f59611c           mulss xmm4, dword ptr [ecx + 0x1c]
// 0062dd70  f30f58dc             addss xmm3, xmm4
// 0062dd74  0f28e1               movaps xmm4, xmm1
// 0062dd77  f30f596110           mulss xmm4, dword ptr [ecx + 0x10]
// 0062dd7c  f30f58dc             addss xmm3, xmm4
// 0062dd80  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 0062dd85  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 0062dd8b  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0062dd90  f30f59d8             mulss xmm3, xmm0
// 0062dd94  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 0062dd99  f30f59c2             mulss xmm0, xmm2
// 0062dd9d  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0062dda2  f30f58d8             addss xmm3, xmm0
// 0062dda6  f30f104114           movss xmm0, dword ptr [ecx + 0x14]
// 0062ddab  f30f59c1             mulss xmm0, xmm1
// 0062ddaf  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062ddb4  f30f58d8             addss xmm3, xmm0
// 0062ddb8  f30f10400c           movss xmm0, dword ptr [eax + 0xc]
// 0062ddbd  f30f115c2410         movss dword ptr [esp + 0x10], xmm3
// 0062ddc3  f30f59e1             mulss xmm4, xmm1
// 0062ddc7  0f28da               movaps xmm3, xmm2
// 0062ddca  f30f5919             mulss xmm3, dword ptr [ecx]
// 0062ddce  f30f58dc             addss xmm3, xmm4
// 0062ddd2  f30f106118           movss xmm4, dword ptr [ecx + 0x18]
// 0062ddd7  f30f59e0             mulss xmm4, xmm0
// 0062dddb  f30f58dc             addss xmm3, xmm4
// 0062dddf  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 0062dde5  0f28da               movaps xmm3, xmm2
// 0062dde8  f30f595904           mulss xmm3, dword ptr [ecx + 4]
// 0062dded  0f28e1               movaps xmm4, xmm1
// 0062ddf0  f30f596110           mulss xmm4, dword ptr [ecx + 0x10]
// 0062ddf5  f30f58dc             addss xmm3, xmm4
// 0062ddf9  0f28e0               movaps xmm4, xmm0
// 0062ddfc  f30f59611c           mulss xmm4, dword ptr [ecx + 0x1c]
// 0062de01  f30f58dc             addss xmm3, xmm4
// 0062de05  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 0062de0b  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0062de10  f30f59da             mulss xmm3, xmm2
// 0062de14  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 0062de19  8b742424             mov esi, dword ptr [esp + 0x24]
// 0062de1d  f30f59d1             mulss xmm2, xmm1
// 0062de21  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 0062de26  8d442408             lea eax, [esp + 8]
// 0062de2a  50                   push eax
// 0062de2b  8d4c2418             lea ecx, [esp + 0x18]
// 0062de2f  f30f58da             addss xmm3, xmm2
// 0062de33  f30f59c8             mulss xmm1, xmm0
// 0062de37  51                   push ecx
// 0062de38  f30f58d9             addss xmm3, xmm1
// 0062de3c  8bce                 mov ecx, esi
// 0062de3e  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0062de46  f30f115c2424         movss dword ptr [esp + 0x24], xmm3
// 0062de4c  e89f150100           call 0x63f3f0
// 0062de51  8bc6                 mov eax, esi
// 0062de53  5e                   pop esi
// 0062de54  83c41c               add esp, 0x1c
// 0062de57  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toObjectSpace@CoordinateFrame@G3D@@QBE?AVPlane@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
