// from server: 100% by auto
// roc 2011-06 00543b80  unit: G3D::BinaryInput  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543b80
//
// 00543b80  56                   push esi
// 00543b81  8b742408             mov esi, dword ptr [esp + 8]
// 00543b85  57                   push edi
// 00543b86  8b7904               mov edi, dword ptr [ecx + 4]
// 00543b89  3bfe                 cmp edi, esi
// 00543b8b  0f84a7000000         je 0x543c38
// 00543b91  8b5108               mov edx, dword ptr [ecx + 8]
// 00543b94  3bf2                 cmp esi, edx
// 00543b96  897104               mov dword ptr [ecx + 4], esi
// 00543b99  7e73                 jle 0x543c0e
// 00543b9b  85d2                 test edx, edx
// 00543b9d  750e                 jne 0x543bad
// 00543b9f  57                   push edi
// 00543ba0  897108               mov dword ptr [ecx + 8], esi
// 00543ba3  e8c8faffff           call 0x543670
// 00543ba8  5f                   pop edi
// 00543ba9  5e                   pop esi
// 00543baa  c20800               ret 8
// 00543bad  ba10000000           mov edx, 0x10
// 00543bb2  3bf2                 cmp esi, edx
// 00543bb4  7c4a                 jl 0x543c00
// 00543bb6  8b4108               mov eax, dword ptr [ecx + 8]
// 00543bb9  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 00543bc1  03c0                 add eax, eax
// 00543bc3  3d801a0600           cmp eax, 0x61a80
// 00543bc8  7e0a                 jle 0x543bd4
// 00543bca  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 00543bd2  eb0f                 jmp 0x543be3
// 00543bd4  3d00fa0000           cmp eax, 0xfa00
// 00543bd9  7e08                 jle 0x543be3
// 00543bdb  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 00543be3  8b4108               mov eax, dword ptr [ecx + 8]
// 00543be6  53                   push ebx
// 00543be7  f30f2ac8             cvtsi2ss xmm1, eax
// 00543beb  f30f59c8             mulss xmm1, xmm0
// 00543bef  f30f2cd9             cvttss2si ebx, xmm1
// 00543bf3  2bd8                 sub ebx, eax
// 00543bf5  8d0433               lea eax, [ebx + esi]
// 00543bf8  3bc2                 cmp eax, edx
// 00543bfa  894108               mov dword ptr [ecx + 8], eax
// 00543bfd  5b                   pop ebx
// 00543bfe  7d03                 jge 0x543c03
// 00543c00  895108               mov dword ptr [ecx + 8], edx
// 00543c03  57                   push edi
// 00543c04  e867faffff           call 0x543670
// 00543c09  5f                   pop edi
// 00543c0a  5e                   pop esi
// 00543c0b  c20800               ret 8
// 00543c0e  b856555555           mov eax, 0x55555556
// 00543c13  f7ea                 imul edx
// 00543c15  8bc2                 mov eax, edx
// 00543c17  c1e81f               shr eax, 0x1f
// 00543c1a  03c2                 add eax, edx
// 00543c1c  3bf0                 cmp esi, eax
// 00543c1e  7f18                 jg 0x543c38
// 00543c20  807c241000           cmp byte ptr [esp + 0x10], 0
// 00543c25  7411                 je 0x543c38
// 00543c27  83fe10               cmp esi, 0x10
// 00543c2a  7e0c                 jle 0x543c38
// 00543c2c  3bf7                 cmp esi, edi
// 00543c2e  7c02                 jl 0x543c32
// 00543c30  8bf7                 mov esi, edi
// 00543c32  56                   push esi
// 00543c33  e838faffff           call 0x543670
// 00543c38  5f                   pop edi
// 00543c39  5e                   pop esi
// 00543c3a  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@G$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
