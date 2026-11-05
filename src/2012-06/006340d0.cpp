// from server: 100% by auto
// roc 2012-06 006340d0  unit: G3D::Random  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006340d0
//
// 006340d0  53                   push ebx
// 006340d1  55                   push ebp
// 006340d2  8bc1                 mov eax, ecx
// 006340d4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006340d8  56                   push esi
// 006340d9  57                   push edi
// 006340da  8d580c               lea ebx, [eax + 0xc]
// 006340dd  8d7924               lea edi, [ecx + 0x24]
// 006340e0  8d7008               lea esi, [eax + 8]
// 006340e3  8d5108               lea edx, [ecx + 8]
// 006340e6  bd03000000           mov ebp, 3
// 006340eb  eb03                 jmp 0x6340f0
// 006340ed  8d4900               lea ecx, [ecx]
// 006340f0  d942f8               fld dword ptr [edx - 8]
// 006340f3  83c20c               add edx, 0xc
// 006340f6  d95ef8               fstp dword ptr [esi - 8]
// 006340f9  83c610               add esi, 0x10
// 006340fc  d942f0               fld dword ptr [edx - 0x10]
// 006340ff  83c704               add edi, 4
// 00634102  d95eec               fstp dword ptr [esi - 0x14]
// 00634105  83c310               add ebx, 0x10
// 00634108  83ed01               sub ebp, 1
// 0063410b  d942f4               fld dword ptr [edx - 0xc]
// 0063410e  d95ef0               fstp dword ptr [esi - 0x10]
// 00634111  d947fc               fld dword ptr [edi - 4]
// 00634114  d95bf0               fstp dword ptr [ebx - 0x10]
// 00634117  75d7                 jne 0x6340f0
// 00634119  0f57c0               xorps xmm0, xmm0
// 0063411c  5f                   pop edi
// 0063411d  5e                   pop esi
// 0063411e  f30f114030           movss dword ptr [eax + 0x30], xmm0
// 00634123  f30f114034           movss dword ptr [eax + 0x34], xmm0
// 00634128  f30f114038           movss dword ptr [eax + 0x38], xmm0
// 0063412d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00634135  5d                   pop ebp
// 00634136  f30f11403c           movss dword ptr [eax + 0x3c], xmm0
// 0063413b  5b                   pop ebx
// 0063413c  c20400               ret 4
// library rbx2016-g3d/Matrix4.cpp (function ??0Matrix4@G3D@@QAE@ABVCoordinateFrame@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
