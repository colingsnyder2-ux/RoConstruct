// from server: 100% by auto
// roc 2011-06 00541f00  unit: G3D::Sphere  size: 335 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541f00
//
// 00541f00  83ec34               sub esp, 0x34
// 00541f03  56                   push esi
// 00541f04  57                   push edi
// 00541f05  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00541f09  8d442424             lea eax, [esp + 0x24]
// 00541f0d  8bf1                 mov esi, ecx
// 00541f0f  50                   push eax
// 00541f10  8bcf                 mov ecx, edi
// 00541f12  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00541f1a  e8d1090100           call 0x5528f0
// 00541f1f  f30f1000             movss xmm0, dword ptr [eax]
// 00541f23  f30f105004           movss xmm2, dword ptr [eax + 4]
// 00541f28  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541f2d  f30f106604           movss xmm4, dword ptr [esi + 4]
// 00541f32  f30f59e2             mulss xmm4, xmm2
// 00541f36  0f28d8               movaps xmm3, xmm0
// 00541f39  f30f591e             mulss xmm3, dword ptr [esi]
// 00541f3d  f30f58dc             addss xmm3, xmm4
// 00541f41  0f28e1               movaps xmm4, xmm1
// 00541f44  f30f596608           mulss xmm4, dword ptr [esi + 8]
// 00541f49  f30f58dc             addss xmm3, xmm4
// 00541f4d  f30f106610           movss xmm4, dword ptr [esi + 0x10]
// 00541f52  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 00541f58  f30f105e0c           movss xmm3, dword ptr [esi + 0xc]
// 00541f5d  f30f59d8             mulss xmm3, xmm0
// 00541f61  f30f594618           mulss xmm0, dword ptr [esi + 0x18]
// 00541f66  f30f59e2             mulss xmm4, xmm2
// 00541f6a  f30f59561c           mulss xmm2, dword ptr [esi + 0x1c]
// 00541f6f  f30f58dc             addss xmm3, xmm4
// 00541f73  f30f106614           movss xmm4, dword ptr [esi + 0x14]
// 00541f78  f30f59e1             mulss xmm4, xmm1
// 00541f7c  f30f594e20           mulss xmm1, dword ptr [esi + 0x20]
// 00541f81  8d4c2430             lea ecx, [esp + 0x30]
// 00541f85  f30f58c2             addss xmm0, xmm2
// 00541f89  51                   push ecx
// 00541f8a  f30f58dc             addss xmm3, xmm4
// 00541f8e  f30f58c1             addss xmm0, xmm1
// 00541f92  8bcf                 mov ecx, edi
// 00541f94  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 00541f9a  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 00541fa0  e82b090100           call 0x5528d0
// 00541fa5  f30f1000             movss xmm0, dword ptr [eax]
// 00541fa9  f30f105004           movss xmm2, dword ptr [eax + 4]
// 00541fae  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541fb3  f30f106604           movss xmm4, dword ptr [esi + 4]
// 00541fb8  f30f59e2             mulss xmm4, xmm2
// 00541fbc  0f28d8               movaps xmm3, xmm0
// 00541fbf  f30f591e             mulss xmm3, dword ptr [esi]
// 00541fc3  f30f58dc             addss xmm3, xmm4
// 00541fc7  0f28e1               movaps xmm4, xmm1
// 00541fca  f30f596608           mulss xmm4, dword ptr [esi + 8]
// 00541fcf  f30f58dc             addss xmm3, xmm4
// 00541fd3  f30f585e24           addss xmm3, dword ptr [esi + 0x24]
// 00541fd8  f30f106610           movss xmm4, dword ptr [esi + 0x10]
// 00541fdd  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 00541fe3  f30f105e0c           movss xmm3, dword ptr [esi + 0xc]
// 00541fe8  f30f59d8             mulss xmm3, xmm0
// 00541fec  f30f594618           mulss xmm0, dword ptr [esi + 0x18]
// 00541ff1  f30f59e2             mulss xmm4, xmm2
// 00541ff5  f30f59561c           mulss xmm2, dword ptr [esi + 0x1c]
// 00541ffa  f30f58dc             addss xmm3, xmm4
// 00541ffe  f30f106614           movss xmm4, dword ptr [esi + 0x14]
// 00542003  f30f59e1             mulss xmm4, xmm1
// 00542007  f30f594e20           mulss xmm1, dword ptr [esi + 0x20]
// 0054200c  f30f58c2             addss xmm0, xmm2
// 00542010  8d54240c             lea edx, [esp + 0xc]
// 00542014  52                   push edx
// 00542015  f30f58dc             addss xmm3, xmm4
// 00542019  f30f585e28           addss xmm3, dword ptr [esi + 0x28]
// 0054201e  f30f58c1             addss xmm0, xmm1
// 00542022  f30f58462c           addss xmm0, dword ptr [esi + 0x2c]
// 00542027  8b742444             mov esi, dword ptr [esp + 0x44]
// 0054202b  8d44241c             lea eax, [esp + 0x1c]
// 0054202f  50                   push eax
// 00542030  56                   push esi
// 00542031  f30f115c2428         movss dword ptr [esp + 0x28], xmm3
// 00542037  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 0054203d  e8bef4ffff           call 0x541500
// 00542042  83c40c               add esp, 0xc
// 00542045  5f                   pop edi
// 00542046  8bc6                 mov eax, esi
// 00542048  5e                   pop esi
// 00542049  83c434               add esp, 0x34
// 0054204c  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toWorldSpace@CoordinateFrame@G3D@@QBE?AVLine@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
