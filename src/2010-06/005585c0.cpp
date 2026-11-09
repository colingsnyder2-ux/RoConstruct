// from server: 100% by auto
// roc 2010-06 005585c0  unit: seg_00550000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005585c0
//
// 005585c0  8b442404             mov eax, dword ptr [esp + 4]
// 005585c4  53                   push ebx
// 005585c5  56                   push esi
// 005585c6  57                   push edi
// 005585c7  8bd9                 mov ebx, ecx
// 005585c9  33ff                 xor edi, edi
// 005585cb  2bd8                 sub ebx, eax
// 005585cd  8bf0                 mov esi, eax
// 005585cf  90                   nop 
// 005585d0  33d2                 xor edx, edx
// 005585d2  8bce                 mov ecx, esi
// 005585d4  f30f10040b           movss xmm0, dword ptr [ebx + ecx]
// 005585d9  0f2e01               ucomiss xmm0, dword ptr [ecx]
// 005585dc  9f                   lahf 
// 005585dd  f6c444               test ah, 0x44
// 005585e0  7a1a                 jp 0x5585fc
// 005585e2  42                   inc edx
// 005585e3  83c104               add ecx, 4
// 005585e6  83fa04               cmp edx, 4
// 005585e9  7ce9                 jl 0x5585d4
// 005585eb  47                   inc edi
// 005585ec  83c610               add esi, 0x10
// 005585ef  83ff04               cmp edi, 4
// 005585f2  7cdc                 jl 0x5585d0
// 005585f4  5f                   pop edi
// 005585f5  5e                   pop esi
// 005585f6  b001                 mov al, 1
// 005585f8  5b                   pop ebx
// 005585f9  c20400               ret 4
// 005585fc  5f                   pop edi
// 005585fd  5e                   pop esi
// 005585fe  32c0                 xor al, al
// 00558600  5b                   pop ebx
// 00558601  c20400               ret 4
// library rbx2016-g3d/Matrix4.cpp (function ??8Matrix4@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
