// from server: 100% by auto
// roc 2011-06 00552260  unit: G3D::Sphere  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00552260
//
// 00552260  53                   push ebx
// 00552261  55                   push ebp
// 00552262  8bc1                 mov eax, ecx
// 00552264  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00552268  56                   push esi
// 00552269  57                   push edi
// 0055226a  8d580c               lea ebx, [eax + 0xc]
// 0055226d  8d7924               lea edi, [ecx + 0x24]
// 00552270  8d7008               lea esi, [eax + 8]
// 00552273  8d5108               lea edx, [ecx + 8]
// 00552276  bd03000000           mov ebp, 3
// 0055227b  eb03                 jmp 0x552280
// 0055227d  8d4900               lea ecx, [ecx]
// 00552280  d942f8               fld dword ptr [edx - 8]
// 00552283  83c20c               add edx, 0xc
// 00552286  d95ef8               fstp dword ptr [esi - 8]
// 00552289  83c610               add esi, 0x10
// 0055228c  d942f0               fld dword ptr [edx - 0x10]
// 0055228f  83c704               add edi, 4
// 00552292  d95eec               fstp dword ptr [esi - 0x14]
// 00552295  83c310               add ebx, 0x10
// 00552298  83ed01               sub ebp, 1
// 0055229b  d942f4               fld dword ptr [edx - 0xc]
// 0055229e  d95ef0               fstp dword ptr [esi - 0x10]
// 005522a1  d947fc               fld dword ptr [edi - 4]
// 005522a4  d95bf0               fstp dword ptr [ebx - 0x10]
// 005522a7  75d7                 jne 0x552280
// 005522a9  0f57c0               xorps xmm0, xmm0
// 005522ac  5f                   pop edi
// 005522ad  5e                   pop esi
// 005522ae  f30f114030           movss dword ptr [eax + 0x30], xmm0
// 005522b3  f30f114034           movss dword ptr [eax + 0x34], xmm0
// 005522b8  f30f114038           movss dword ptr [eax + 0x38], xmm0
// 005522bd  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 005522c5  5d                   pop ebp
// 005522c6  f30f11403c           movss dword ptr [eax + 0x3c], xmm0
// 005522cb  5b                   pop ebx
// 005522cc  c20400               ret 4
// library rbx2016-g3d/Matrix4.cpp (function ??0Matrix4@G3D@@QAE@ABVCoordinateFrame@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
