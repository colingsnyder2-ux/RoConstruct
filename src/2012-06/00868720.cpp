// from server: 100% by auto
// roc 2012-06 00868720  unit: RBX::MegaClusterPoly  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00868720
//
// 00868720  56                   push esi
// 00868721  8b742408             mov esi, dword ptr [esp + 8]
// 00868725  57                   push edi
// 00868726  8b7904               mov edi, dword ptr [ecx + 4]
// 00868729  3bfe                 cmp edi, esi
// 0086872b  0f84a9000000         je 0x8687da
// 00868731  8b5108               mov edx, dword ptr [ecx + 8]
// 00868734  3bf2                 cmp esi, edx
// 00868736  897104               mov dword ptr [ecx + 4], esi
// 00868739  7e75                 jle 0x8687b0
// 0086873b  85d2                 test edx, edx
// 0086873d  750e                 jne 0x86874d
// 0086873f  57                   push edi
// 00868740  897108               mov dword ptr [ecx + 8], esi
// 00868743  e8282addff           call 0x63b170
// 00868748  5f                   pop edi
// 00868749  5e                   pop esi
// 0086874a  c20800               ret 8
// 0086874d  ba0a000000           mov edx, 0xa
// 00868752  3bf2                 cmp esi, edx
// 00868754  7c4c                 jl 0x8687a2
// 00868756  8b4108               mov eax, dword ptr [ecx + 8]
// 00868759  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 00868761  03c0                 add eax, eax
// 00868763  03c0                 add eax, eax
// 00868765  3d801a0600           cmp eax, 0x61a80
// 0086876a  7e0a                 jle 0x868776
// 0086876c  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 00868774  eb0f                 jmp 0x868785
// 00868776  3d00fa0000           cmp eax, 0xfa00
// 0086877b  7e08                 jle 0x868785
// 0086877d  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 00868785  8b4108               mov eax, dword ptr [ecx + 8]
// 00868788  53                   push ebx
// 00868789  f30f2ac8             cvtsi2ss xmm1, eax
// 0086878d  f30f59c8             mulss xmm1, xmm0
// 00868791  f30f2cd9             cvttss2si ebx, xmm1
// 00868795  2bd8                 sub ebx, eax
// 00868797  8d0433               lea eax, [ebx + esi]
// 0086879a  3bc2                 cmp eax, edx
// 0086879c  894108               mov dword ptr [ecx + 8], eax
// 0086879f  5b                   pop ebx
// 008687a0  7d03                 jge 0x8687a5
// 008687a2  895108               mov dword ptr [ecx + 8], edx
// 008687a5  57                   push edi
// 008687a6  e8c529ddff           call 0x63b170
// 008687ab  5f                   pop edi
// 008687ac  5e                   pop esi
// 008687ad  c20800               ret 8
// 008687b0  b856555555           mov eax, 0x55555556
// 008687b5  f7ea                 imul edx
// 008687b7  8bc2                 mov eax, edx
// 008687b9  c1e81f               shr eax, 0x1f
// 008687bc  03c2                 add eax, edx
// 008687be  3bf0                 cmp esi, eax
// 008687c0  7f18                 jg 0x8687da
// 008687c2  807c241000           cmp byte ptr [esp + 0x10], 0
// 008687c7  7411                 je 0x8687da
// 008687c9  83fe0a               cmp esi, 0xa
// 008687cc  7e0c                 jle 0x8687da
// 008687ce  3bf7                 cmp esi, edi
// 008687d0  7c02                 jl 0x8687d4
// 008687d2  8bf7                 mov esi, edi
// 008687d4  56                   push esi
// 008687d5  e89629ddff           call 0x63b170
// 008687da  5f                   pop edi
// 008687db  5e                   pop esi
// 008687dc  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@I$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
