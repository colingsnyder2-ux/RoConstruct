// from server: 100% by auto
// roc 2011-06 0074cc30  unit: RBX::BallBallContact  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0074cc30
//
// 0074cc30  56                   push esi
// 0074cc31  8b742408             mov esi, dword ptr [esp + 8]
// 0074cc35  57                   push edi
// 0074cc36  8b7904               mov edi, dword ptr [ecx + 4]
// 0074cc39  3bfe                 cmp edi, esi
// 0074cc3b  0f84a9000000         je 0x74ccea
// 0074cc41  8b5108               mov edx, dword ptr [ecx + 8]
// 0074cc44  3bf2                 cmp esi, edx
// 0074cc46  897104               mov dword ptr [ecx + 4], esi
// 0074cc49  7e75                 jle 0x74ccc0
// 0074cc4b  85d2                 test edx, edx
// 0074cc4d  750e                 jne 0x74cc5d
// 0074cc4f  57                   push edi
// 0074cc50  897108               mov dword ptr [ecx + 8], esi
// 0074cc53  e8d80ee0ff           call 0x54db30
// 0074cc58  5f                   pop edi
// 0074cc59  5e                   pop esi
// 0074cc5a  c20800               ret 8
// 0074cc5d  ba0a000000           mov edx, 0xa
// 0074cc62  3bf2                 cmp esi, edx
// 0074cc64  7c4c                 jl 0x74ccb2
// 0074cc66  8b4108               mov eax, dword ptr [ecx + 8]
// 0074cc69  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 0074cc71  03c0                 add eax, eax
// 0074cc73  03c0                 add eax, eax
// 0074cc75  3d801a0600           cmp eax, 0x61a80
// 0074cc7a  7e0a                 jle 0x74cc86
// 0074cc7c  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 0074cc84  eb0f                 jmp 0x74cc95
// 0074cc86  3d00fa0000           cmp eax, 0xfa00
// 0074cc8b  7e08                 jle 0x74cc95
// 0074cc8d  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 0074cc95  8b4108               mov eax, dword ptr [ecx + 8]
// 0074cc98  53                   push ebx
// 0074cc99  f30f2ac8             cvtsi2ss xmm1, eax
// 0074cc9d  f30f59c8             mulss xmm1, xmm0
// 0074cca1  f30f2cd9             cvttss2si ebx, xmm1
// 0074cca5  2bd8                 sub ebx, eax
// 0074cca7  8d0433               lea eax, [ebx + esi]
// 0074ccaa  3bc2                 cmp eax, edx
// 0074ccac  894108               mov dword ptr [ecx + 8], eax
// 0074ccaf  5b                   pop ebx
// 0074ccb0  7d03                 jge 0x74ccb5
// 0074ccb2  895108               mov dword ptr [ecx + 8], edx
// 0074ccb5  57                   push edi
// 0074ccb6  e8750ee0ff           call 0x54db30
// 0074ccbb  5f                   pop edi
// 0074ccbc  5e                   pop esi
// 0074ccbd  c20800               ret 8
// 0074ccc0  b856555555           mov eax, 0x55555556
// 0074ccc5  f7ea                 imul edx
// 0074ccc7  8bc2                 mov eax, edx
// 0074ccc9  c1e81f               shr eax, 0x1f
// 0074cccc  03c2                 add eax, edx
// 0074ccce  3bf0                 cmp esi, eax
// 0074ccd0  7f18                 jg 0x74ccea
// 0074ccd2  807c241000           cmp byte ptr [esp + 0x10], 0
// 0074ccd7  7411                 je 0x74ccea
// 0074ccd9  83fe0a               cmp esi, 0xa
// 0074ccdc  7e0c                 jle 0x74ccea
// 0074ccde  3bf7                 cmp esi, edi
// 0074cce0  7c02                 jl 0x74cce4
// 0074cce2  8bf7                 mov esi, edi
// 0074cce4  56                   push esi
// 0074cce5  e8460ee0ff           call 0x54db30
// 0074ccea  5f                   pop edi
// 0074cceb  5e                   pop esi
// 0074ccec  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@I$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
