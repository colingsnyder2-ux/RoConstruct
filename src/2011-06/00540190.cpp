// from server: 100% by auto
// roc 2011-06 00540190  unit: G3D::MemoryManager  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00540190
//
// 00540190  53                   push ebx
// 00540191  55                   push ebp
// 00540192  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00540196  56                   push esi
// 00540197  57                   push edi
// 00540198  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0054019c  8bdf                 mov ebx, edi
// 0054019e  8d7508               lea esi, [ebp + 8]
// 005401a1  8d5104               lea edx, [ecx + 4]
// 005401a4  2bd9                 sub ebx, ecx
// 005401a6  2be9                 sub ebp, ecx
// 005401a8  8bcf                 mov ecx, edi
// 005401aa  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 005401ae  b803000000           mov eax, 3
// 005401b3  eb0b                 jmp 0x5401c0
// 005401b5  8da42400000000       lea esp, [esp]
// 005401bc  8d642400             lea esp, [esp]
// 005401c0  f30f1042fc           movss xmm0, dword ptr [edx - 4]
// 005401c5  f30f5807             addss xmm0, dword ptr [edi]
// 005401c9  f30f1146f8           movss dword ptr [esi - 8], xmm0
// 005401ce  f30f100413           movss xmm0, dword ptr [ebx + edx]
// 005401d3  f30f5802             addss xmm0, dword ptr [edx]
// 005401d7  f30f11042a           movss dword ptr [edx + ebp], xmm0
// 005401dc  f30f100431           movss xmm0, dword ptr [ecx + esi]
// 005401e1  f30f584204           addss xmm0, dword ptr [edx + 4]
// 005401e6  f30f1106             movss dword ptr [esi], xmm0
// 005401ea  83c70c               add edi, 0xc
// 005401ed  83c20c               add edx, 0xc
// 005401f0  83c60c               add esi, 0xc
// 005401f3  83e801               sub eax, 1
// 005401f6  75c8                 jne 0x5401c0
// 005401f8  8b442414             mov eax, dword ptr [esp + 0x14]
// 005401fc  5f                   pop edi
// 005401fd  5e                   pop esi
// 005401fe  5d                   pop ebp
// 005401ff  5b                   pop ebx
// 00540200  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??HMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
