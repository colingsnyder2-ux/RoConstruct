// from server: 100% by auto
// roc 2012-06 0062f980  unit: G3D::BinaryInput  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f980
//
// 0062f980  56                   push esi
// 0062f981  8b742408             mov esi, dword ptr [esp + 8]
// 0062f985  57                   push edi
// 0062f986  8b7904               mov edi, dword ptr [ecx + 4]
// 0062f989  3bfe                 cmp edi, esi
// 0062f98b  0f84a2000000         je 0x62fa33
// 0062f991  8b5108               mov edx, dword ptr [ecx + 8]
// 0062f994  3bf2                 cmp esi, edx
// 0062f996  897104               mov dword ptr [ecx + 4], esi
// 0062f999  7e6e                 jle 0x62fa09
// 0062f99b  85d2                 test edx, edx
// 0062f99d  750e                 jne 0x62f9ad
// 0062f99f  57                   push edi
// 0062f9a0  897108               mov dword ptr [ecx + 8], esi
// 0062f9a3  e838fbffff           call 0x62f4e0
// 0062f9a8  5f                   pop edi
// 0062f9a9  5e                   pop esi
// 0062f9aa  c20800               ret 8
// 0062f9ad  ba20000000           mov edx, 0x20
// 0062f9b2  3bf2                 cmp esi, edx
// 0062f9b4  7c45                 jl 0x62f9fb
// 0062f9b6  8b4108               mov eax, dword ptr [ecx + 8]
// 0062f9b9  3d801a0600           cmp eax, 0x61a80
// 0062f9be  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 0062f9c6  7e0a                 jle 0x62f9d2
// 0062f9c8  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 0062f9d0  eb0f                 jmp 0x62f9e1
// 0062f9d2  3d00fa0000           cmp eax, 0xfa00
// 0062f9d7  7e08                 jle 0x62f9e1
// 0062f9d9  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 0062f9e1  53                   push ebx
// 0062f9e2  f30f2ac8             cvtsi2ss xmm1, eax
// 0062f9e6  f30f59c8             mulss xmm1, xmm0
// 0062f9ea  f30f2cd9             cvttss2si ebx, xmm1
// 0062f9ee  2bd8                 sub ebx, eax
// 0062f9f0  8d0433               lea eax, [ebx + esi]
// 0062f9f3  3bc2                 cmp eax, edx
// 0062f9f5  894108               mov dword ptr [ecx + 8], eax
// 0062f9f8  5b                   pop ebx
// 0062f9f9  7d03                 jge 0x62f9fe
// 0062f9fb  895108               mov dword ptr [ecx + 8], edx
// 0062f9fe  57                   push edi
// 0062f9ff  e8dcfaffff           call 0x62f4e0
// 0062fa04  5f                   pop edi
// 0062fa05  5e                   pop esi
// 0062fa06  c20800               ret 8
// 0062fa09  b856555555           mov eax, 0x55555556
// 0062fa0e  f7ea                 imul edx
// 0062fa10  8bc2                 mov eax, edx
// 0062fa12  c1e81f               shr eax, 0x1f
// 0062fa15  03c2                 add eax, edx
// 0062fa17  3bf0                 cmp esi, eax
// 0062fa19  7f18                 jg 0x62fa33
// 0062fa1b  807c241000           cmp byte ptr [esp + 0x10], 0
// 0062fa20  7411                 je 0x62fa33
// 0062fa22  83fe20               cmp esi, 0x20
// 0062fa25  7e0c                 jle 0x62fa33
// 0062fa27  3bf7                 cmp esi, edi
// 0062fa29  7c02                 jl 0x62fa2d
// 0062fa2b  8bf7                 mov esi, edi
// 0062fa2d  56                   push esi
// 0062fa2e  e8adfaffff           call 0x62f4e0
// 0062fa33  5f                   pop edi
// 0062fa34  5e                   pop esi
// 0062fa35  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@_N$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
