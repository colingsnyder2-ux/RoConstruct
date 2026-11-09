// from server: 100% by auto
// roc 2012-06 004c1790  unit: RBX::?1??ViewRbxGfx_InitModule::ViewRbxGfxFactory  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c1790
//
// 004c1790  8b442408             mov eax, dword ptr [esp + 8]
// 004c1794  f30f104804           movss xmm1, dword ptr [eax + 4]
// 004c1799  f30f104008           movss xmm0, dword ptr [eax + 8]
// 004c179e  f30f1010             movss xmm2, dword ptr [eax]
// 004c17a2  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 004c17a7  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 004c17ac  8b442404             mov eax, dword ptr [esp + 4]
// 004c17b0  f30f59d9             mulss xmm3, xmm1
// 004c17b4  f30f59e0             mulss xmm4, xmm0
// 004c17b8  f30f58dc             addss xmm3, xmm4
// 004c17bc  0f28e2               movaps xmm4, xmm2
// 004c17bf  f30f5921             mulss xmm4, dword ptr [ecx]
// 004c17c3  f30f58dc             addss xmm3, xmm4
// 004c17c7  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 004c17cc  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 004c17d1  f30f1118             movss dword ptr [eax], xmm3
// 004c17d5  f30f10590c           movss xmm3, dword ptr [ecx + 0xc]
// 004c17da  f30f59da             mulss xmm3, xmm2
// 004c17de  f30f59e1             mulss xmm4, xmm1
// 004c17e2  f30f58dc             addss xmm3, xmm4
// 004c17e6  f30f106114           movss xmm4, dword ptr [ecx + 0x14]
// 004c17eb  f30f59e0             mulss xmm4, xmm0
// 004c17ef  f30f58dc             addss xmm3, xmm4
// 004c17f3  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 004c17f8  f30f115804           movss dword ptr [eax + 4], xmm3
// 004c17fd  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 004c1802  f30f59da             mulss xmm3, xmm2
// 004c1806  f30f10511c           movss xmm2, dword ptr [ecx + 0x1c]
// 004c180b  f30f59d1             mulss xmm2, xmm1
// 004c180f  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 004c1814  f30f58da             addss xmm3, xmm2
// 004c1818  f30f59c8             mulss xmm1, xmm0
// 004c181c  f30f58d9             addss xmm3, xmm1
// 004c1820  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 004c1825  f30f115808           movss dword ptr [eax + 8], xmm3
// 004c182a  c20800               ret 8
// library rbx2016-g3d/Capsule.cpp (function ?pointToWorldSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
