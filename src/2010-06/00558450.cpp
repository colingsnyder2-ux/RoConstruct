// from server: 100% by auto
// roc 2010-06 00558450  unit: seg_00550000  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558450
//
// 00558450  53                   push ebx
// 00558451  55                   push ebp
// 00558452  8bc1                 mov eax, ecx
// 00558454  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00558458  56                   push esi
// 00558459  57                   push edi
// 0055845a  8d580c               lea ebx, [eax + 0xc]
// 0055845d  8d7924               lea edi, [ecx + 0x24]
// 00558460  8d7008               lea esi, [eax + 8]
// 00558463  8d5108               lea edx, [ecx + 8]
// 00558466  bd03000000           mov ebp, 3
// 0055846b  eb03                 jmp 0x558470
// 0055846d  8d4900               lea ecx, [ecx]
// 00558470  d942f8               fld dword ptr [edx - 8]
// 00558473  83c20c               add edx, 0xc
// 00558476  d95ef8               fstp dword ptr [esi - 8]
// 00558479  83c610               add esi, 0x10
// 0055847c  d942f0               fld dword ptr [edx - 0x10]
// 0055847f  83c704               add edi, 4
// 00558482  d95eec               fstp dword ptr [esi - 0x14]
// 00558485  83c310               add ebx, 0x10
// 00558488  83ed01               sub ebp, 1
// 0055848b  d942f4               fld dword ptr [edx - 0xc]
// 0055848e  d95ef0               fstp dword ptr [esi - 0x10]
// 00558491  d947fc               fld dword ptr [edi - 4]
// 00558494  d95bf0               fstp dword ptr [ebx - 0x10]
// 00558497  75d7                 jne 0x558470
// 00558499  0f57c0               xorps xmm0, xmm0
// 0055849c  5f                   pop edi
// 0055849d  5e                   pop esi
// 0055849e  f30f114030           movss dword ptr [eax + 0x30], xmm0
// 005584a3  f30f114034           movss dword ptr [eax + 0x34], xmm0
// 005584a8  f30f114038           movss dword ptr [eax + 0x38], xmm0
// 005584ad  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 005584b5  5d                   pop ebp
// 005584b6  f30f11403c           movss dword ptr [eax + 0x3c], xmm0
// 005584bb  5b                   pop ebx
// 005584bc  c20400               ret 4
// library rbx2016-g3d/Matrix4.cpp (function ??0Matrix4@G3D@@QAE@ABVCoordinateFrame@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
