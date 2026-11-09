// from server: 100% by auto
// roc 2012-06 0062de60  unit: G3D::Line  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062de60
//
// 0062de60  83ec1c               sub esp, 0x1c
// 0062de63  56                   push esi
// 0062de64  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062de68  f30f105810           movss xmm3, dword ptr [eax + 0x10]
// 0062de6d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062de72  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062de77  f30f59cb             mulss xmm1, xmm3
// 0062de7b  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 0062de80  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 0062de85  f30f59c3             mulss xmm0, xmm3
// 0062de89  f30f59d3             mulss xmm2, xmm3
// 0062de8d  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0062de92  f30f59da             mulss xmm3, xmm2
// 0062de96  f30f59e1             mulss xmm4, xmm1
// 0062de9a  f30f58dc             addss xmm3, xmm4
// 0062de9e  f30f1021             movss xmm4, dword ptr [ecx]
// 0062dea2  f30f59e0             mulss xmm4, xmm0
// 0062dea6  f30f58dc             addss xmm3, xmm4
// 0062deaa  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 0062deaf  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 0062deb5  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 0062deba  f30f59d9             mulss xmm3, xmm1
// 0062debe  0f28e0               movaps xmm4, xmm0
// 0062dec1  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 0062dec6  f30f58dc             addss xmm3, xmm4
// 0062deca  0f28e2               movaps xmm4, xmm2
// 0062decd  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 0062ded2  f30f58dc             addss xmm3, xmm4
// 0062ded6  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 0062dedb  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 0062dee0  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 0062dee6  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 0062deeb  f30f59d9             mulss xmm3, xmm1
// 0062deef  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0062def4  f30f59c8             mulss xmm1, xmm0
// 0062def8  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 0062defd  f30f58d9             addss xmm3, xmm1
// 0062df01  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062df06  f30f59e1             mulss xmm4, xmm1
// 0062df0a  f30f59c2             mulss xmm0, xmm2
// 0062df0e  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0062df13  f30f58d8             addss xmm3, xmm0
// 0062df17  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 0062df1c  f30f10400c           movss xmm0, dword ptr [eax + 0xc]
// 0062df21  f30f115c2410         movss dword ptr [esp + 0x10], xmm3
// 0062df27  0f28da               movaps xmm3, xmm2
// 0062df2a  f30f5919             mulss xmm3, dword ptr [ecx]
// 0062df2e  f30f58dc             addss xmm3, xmm4
// 0062df32  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 0062df37  f30f59e0             mulss xmm4, xmm0
// 0062df3b  f30f58dc             addss xmm3, xmm4
// 0062df3f  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 0062df45  0f28d9               movaps xmm3, xmm1
// 0062df48  f30f595910           mulss xmm3, dword ptr [ecx + 0x10]
// 0062df4d  0f28e2               movaps xmm4, xmm2
// 0062df50  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 0062df55  f30f58dc             addss xmm3, xmm4
// 0062df59  0f28e0               movaps xmm4, xmm0
// 0062df5c  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 0062df61  f30f58dc             addss xmm3, xmm4
// 0062df65  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 0062df6b  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 0062df70  f30f59d9             mulss xmm3, xmm1
// 0062df74  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0062df79  f30f59ca             mulss xmm1, xmm2
// 0062df7d  8b742424             mov esi, dword ptr [esp + 0x24]
// 0062df81  f30f58d9             addss xmm3, xmm1
// 0062df85  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 0062df8a  8d442408             lea eax, [esp + 8]
// 0062df8e  50                   push eax
// 0062df8f  8d4c2418             lea ecx, [esp + 0x18]
// 0062df93  f30f59c8             mulss xmm1, xmm0
// 0062df97  51                   push ecx
// 0062df98  f30f58d9             addss xmm3, xmm1
// 0062df9c  8bce                 mov ecx, esi
// 0062df9e  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0062dfa6  f30f115c2424         movss dword ptr [esp + 0x24], xmm3
// 0062dfac  e83f140100           call 0x63f3f0
// 0062dfb1  8bc6                 mov eax, esi
// 0062dfb3  5e                   pop esi
// 0062dfb4  83c41c               add esp, 0x1c
// 0062dfb7  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toWorldSpace@CoordinateFrame@G3D@@QBE?AVPlane@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
