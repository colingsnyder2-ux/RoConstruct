// from server: 100% by auto
// roc 2010-06 0055f400  unit: G3D::Line  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0055f400
//
// 0055f400  83ec1c               sub esp, 0x1c
// 0055f403  56                   push esi
// 0055f404  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055f408  f30f105810           movss xmm3, dword ptr [eax + 0x10]
// 0055f40d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0055f412  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0055f417  f30f59cb             mulss xmm1, xmm3
// 0055f41b  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 0055f420  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 0055f425  f30f59c3             mulss xmm0, xmm3
// 0055f429  f30f59d3             mulss xmm2, xmm3
// 0055f42d  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0055f432  f30f59da             mulss xmm3, xmm2
// 0055f436  f30f59e1             mulss xmm4, xmm1
// 0055f43a  f30f58dc             addss xmm3, xmm4
// 0055f43e  f30f1021             movss xmm4, dword ptr [ecx]
// 0055f442  f30f59e0             mulss xmm4, xmm0
// 0055f446  f30f58dc             addss xmm3, xmm4
// 0055f44a  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 0055f44f  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 0055f455  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 0055f45a  f30f59d9             mulss xmm3, xmm1
// 0055f45e  0f28e0               movaps xmm4, xmm0
// 0055f461  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 0055f466  f30f58dc             addss xmm3, xmm4
// 0055f46a  0f28e2               movaps xmm4, xmm2
// 0055f46d  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 0055f472  f30f58dc             addss xmm3, xmm4
// 0055f476  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 0055f47b  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 0055f480  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 0055f486  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 0055f48b  f30f59d9             mulss xmm3, xmm1
// 0055f48f  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0055f494  f30f59c8             mulss xmm1, xmm0
// 0055f498  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 0055f49d  f30f58d9             addss xmm3, xmm1
// 0055f4a1  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0055f4a6  f30f59e1             mulss xmm4, xmm1
// 0055f4aa  f30f59c2             mulss xmm0, xmm2
// 0055f4ae  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0055f4b3  f30f58d8             addss xmm3, xmm0
// 0055f4b7  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 0055f4bc  f30f10400c           movss xmm0, dword ptr [eax + 0xc]
// 0055f4c1  f30f115c2410         movss dword ptr [esp + 0x10], xmm3
// 0055f4c7  0f28da               movaps xmm3, xmm2
// 0055f4ca  f30f5919             mulss xmm3, dword ptr [ecx]
// 0055f4ce  f30f58dc             addss xmm3, xmm4
// 0055f4d2  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 0055f4d7  f30f59e0             mulss xmm4, xmm0
// 0055f4db  f30f58dc             addss xmm3, xmm4
// 0055f4df  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 0055f4e5  0f28d9               movaps xmm3, xmm1
// 0055f4e8  f30f595910           mulss xmm3, dword ptr [ecx + 0x10]
// 0055f4ed  0f28e2               movaps xmm4, xmm2
// 0055f4f0  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 0055f4f5  f30f58dc             addss xmm3, xmm4
// 0055f4f9  0f28e0               movaps xmm4, xmm0
// 0055f4fc  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 0055f501  f30f58dc             addss xmm3, xmm4
// 0055f505  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 0055f50b  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 0055f510  f30f59d9             mulss xmm3, xmm1
// 0055f514  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0055f519  f30f59ca             mulss xmm1, xmm2
// 0055f51d  8b742424             mov esi, dword ptr [esp + 0x24]
// 0055f521  f30f58d9             addss xmm3, xmm1
// 0055f525  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 0055f52a  8d442408             lea eax, [esp + 8]
// 0055f52e  50                   push eax
// 0055f52f  8d4c2418             lea ecx, [esp + 0x18]
// 0055f533  f30f59c8             mulss xmm1, xmm0
// 0055f537  51                   push ecx
// 0055f538  f30f58d9             addss xmm3, xmm1
// 0055f53c  8bce                 mov ecx, esi
// 0055f53e  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0055f546  f30f115c2424         movss dword ptr [esp + 0x24], xmm3
// 0055f54c  e80fe20000           call 0x56d760
// 0055f551  8bc6                 mov eax, esi
// 0055f553  5e                   pop esi
// 0055f554  83c41c               add esp, 0x1c
// 0055f557  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toWorldSpace@CoordinateFrame@G3D@@QBE?AVPlane@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
