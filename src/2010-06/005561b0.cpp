// from server: 100% by auto
// roc 2010-06 005561b0  unit: seg_00550000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005561b0
//
// 005561b0  53                   push ebx
// 005561b1  55                   push ebp
// 005561b2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005561b6  56                   push esi
// 005561b7  57                   push edi
// 005561b8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005561bc  8bdf                 mov ebx, edi
// 005561be  8d7508               lea esi, [ebp + 8]
// 005561c1  8d5104               lea edx, [ecx + 4]
// 005561c4  2bd9                 sub ebx, ecx
// 005561c6  2be9                 sub ebp, ecx
// 005561c8  8bcf                 mov ecx, edi
// 005561ca  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 005561ce  b803000000           mov eax, 3
// 005561d3  eb0b                 jmp 0x5561e0
// 005561d5  8da42400000000       lea esp, [esp]
// 005561dc  8d642400             lea esp, [esp]
// 005561e0  f30f1042fc           movss xmm0, dword ptr [edx - 4]
// 005561e5  f30f5807             addss xmm0, dword ptr [edi]
// 005561e9  f30f1146f8           movss dword ptr [esi - 8], xmm0
// 005561ee  f30f100413           movss xmm0, dword ptr [ebx + edx]
// 005561f3  f30f5802             addss xmm0, dword ptr [edx]
// 005561f7  f30f11042a           movss dword ptr [edx + ebp], xmm0
// 005561fc  f30f100431           movss xmm0, dword ptr [ecx + esi]
// 00556201  f30f584204           addss xmm0, dword ptr [edx + 4]
// 00556206  f30f1106             movss dword ptr [esi], xmm0
// 0055620a  83c70c               add edi, 0xc
// 0055620d  83c20c               add edx, 0xc
// 00556210  83c60c               add esi, 0xc
// 00556213  83e801               sub eax, 1
// 00556216  75c8                 jne 0x5561e0
// 00556218  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055621c  5f                   pop edi
// 0055621d  5e                   pop esi
// 0055621e  5d                   pop ebp
// 0055621f  5b                   pop ebx
// 00556220  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??HMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
