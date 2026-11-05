// from server: 100% by auto
// roc 2010-06 00556140  unit: seg_00550000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556140
//
// 00556140  8b442404             mov eax, dword ptr [esp + 4]
// 00556144  53                   push ebx
// 00556145  56                   push esi
// 00556146  57                   push edi
// 00556147  8bd9                 mov ebx, ecx
// 00556149  33ff                 xor edi, edi
// 0055614b  2bd8                 sub ebx, eax
// 0055614d  8bf0                 mov esi, eax
// 0055614f  90                   nop 
// 00556150  33d2                 xor edx, edx
// 00556152  8bce                 mov ecx, esi
// 00556154  f30f10040b           movss xmm0, dword ptr [ebx + ecx]
// 00556159  0f2e01               ucomiss xmm0, dword ptr [ecx]
// 0055615c  9f                   lahf 
// 0055615d  f6c444               test ah, 0x44
// 00556160  7a1a                 jp 0x55617c
// 00556162  42                   inc edx
// 00556163  83c104               add ecx, 4
// 00556166  83fa03               cmp edx, 3
// 00556169  7ce9                 jl 0x556154
// 0055616b  47                   inc edi
// 0055616c  83c60c               add esi, 0xc
// 0055616f  83ff03               cmp edi, 3
// 00556172  7cdc                 jl 0x556150
// 00556174  5f                   pop edi
// 00556175  5e                   pop esi
// 00556176  b001                 mov al, 1
// 00556178  5b                   pop ebx
// 00556179  c20400               ret 4
// 0055617c  5f                   pop edi
// 0055617d  5e                   pop esi
// 0055617e  32c0                 xor al, al
// 00556180  5b                   pop ebx
// 00556181  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??8Matrix3@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
