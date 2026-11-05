// from server: 100% by auto
// roc 2011-06 00540120  unit: G3D::MemoryManager  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00540120
//
// 00540120  8b442404             mov eax, dword ptr [esp + 4]
// 00540124  53                   push ebx
// 00540125  56                   push esi
// 00540126  57                   push edi
// 00540127  8bd9                 mov ebx, ecx
// 00540129  33ff                 xor edi, edi
// 0054012b  2bd8                 sub ebx, eax
// 0054012d  8bf0                 mov esi, eax
// 0054012f  90                   nop 
// 00540130  33d2                 xor edx, edx
// 00540132  8bce                 mov ecx, esi
// 00540134  f30f10040b           movss xmm0, dword ptr [ebx + ecx]
// 00540139  0f2e01               ucomiss xmm0, dword ptr [ecx]
// 0054013c  9f                   lahf 
// 0054013d  f6c444               test ah, 0x44
// 00540140  7a1a                 jp 0x54015c
// 00540142  42                   inc edx
// 00540143  83c104               add ecx, 4
// 00540146  83fa03               cmp edx, 3
// 00540149  7ce9                 jl 0x540134
// 0054014b  47                   inc edi
// 0054014c  83c60c               add esi, 0xc
// 0054014f  83ff03               cmp edi, 3
// 00540152  7cdc                 jl 0x540130
// 00540154  5f                   pop edi
// 00540155  5e                   pop esi
// 00540156  b001                 mov al, 1
// 00540158  5b                   pop ebx
// 00540159  c20400               ret 4
// 0054015c  5f                   pop edi
// 0054015d  5e                   pop esi
// 0054015e  32c0                 xor al, al
// 00540160  5b                   pop ebx
// 00540161  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??8Matrix3@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
