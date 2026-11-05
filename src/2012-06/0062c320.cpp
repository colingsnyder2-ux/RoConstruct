// from server: 100% by auto
// roc 2012-06 0062c320  unit: G3D::Sphere  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c320
//
// 0062c320  8b442404             mov eax, dword ptr [esp + 4]
// 0062c324  53                   push ebx
// 0062c325  56                   push esi
// 0062c326  57                   push edi
// 0062c327  8bd9                 mov ebx, ecx
// 0062c329  33ff                 xor edi, edi
// 0062c32b  2bd8                 sub ebx, eax
// 0062c32d  8bf0                 mov esi, eax
// 0062c32f  90                   nop 
// 0062c330  33d2                 xor edx, edx
// 0062c332  8bce                 mov ecx, esi
// 0062c334  f30f10040b           movss xmm0, dword ptr [ebx + ecx]
// 0062c339  0f2e01               ucomiss xmm0, dword ptr [ecx]
// 0062c33c  9f                   lahf 
// 0062c33d  f6c444               test ah, 0x44
// 0062c340  7a1a                 jp 0x62c35c
// 0062c342  42                   inc edx
// 0062c343  83c104               add ecx, 4
// 0062c346  83fa03               cmp edx, 3
// 0062c349  7ce9                 jl 0x62c334
// 0062c34b  47                   inc edi
// 0062c34c  83c60c               add esi, 0xc
// 0062c34f  83ff03               cmp edi, 3
// 0062c352  7cdc                 jl 0x62c330
// 0062c354  5f                   pop edi
// 0062c355  5e                   pop esi
// 0062c356  b001                 mov al, 1
// 0062c358  5b                   pop ebx
// 0062c359  c20400               ret 4
// 0062c35c  5f                   pop edi
// 0062c35d  5e                   pop esi
// 0062c35e  32c0                 xor al, al
// 0062c360  5b                   pop ebx
// 0062c361  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??8Matrix3@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
