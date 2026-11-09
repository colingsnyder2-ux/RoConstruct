// from server: 100% by auto
// roc 2012-06 0062c390  unit: G3D::Sphere  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c390
//
// 0062c390  53                   push ebx
// 0062c391  55                   push ebp
// 0062c392  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0062c396  56                   push esi
// 0062c397  57                   push edi
// 0062c398  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0062c39c  8bdf                 mov ebx, edi
// 0062c39e  8d7508               lea esi, [ebp + 8]
// 0062c3a1  8d5104               lea edx, [ecx + 4]
// 0062c3a4  2bd9                 sub ebx, ecx
// 0062c3a6  2be9                 sub ebp, ecx
// 0062c3a8  8bcf                 mov ecx, edi
// 0062c3aa  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 0062c3ae  b803000000           mov eax, 3
// 0062c3b3  eb0b                 jmp 0x62c3c0
// 0062c3b5  8da42400000000       lea esp, [esp]
// 0062c3bc  8d642400             lea esp, [esp]
// 0062c3c0  f30f1042fc           movss xmm0, dword ptr [edx - 4]
// 0062c3c5  f30f5807             addss xmm0, dword ptr [edi]
// 0062c3c9  f30f1146f8           movss dword ptr [esi - 8], xmm0
// 0062c3ce  f30f100413           movss xmm0, dword ptr [ebx + edx]
// 0062c3d3  f30f5802             addss xmm0, dword ptr [edx]
// 0062c3d7  f30f11042a           movss dword ptr [edx + ebp], xmm0
// 0062c3dc  f30f100431           movss xmm0, dword ptr [ecx + esi]
// 0062c3e1  f30f584204           addss xmm0, dword ptr [edx + 4]
// 0062c3e6  f30f1106             movss dword ptr [esi], xmm0
// 0062c3ea  83c70c               add edi, 0xc
// 0062c3ed  83c20c               add edx, 0xc
// 0062c3f0  83c60c               add esi, 0xc
// 0062c3f3  83e801               sub eax, 1
// 0062c3f6  75c8                 jne 0x62c3c0
// 0062c3f8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062c3fc  5f                   pop edi
// 0062c3fd  5e                   pop esi
// 0062c3fe  5d                   pop ebp
// 0062c3ff  5b                   pop ebx
// 0062c400  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??HMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
