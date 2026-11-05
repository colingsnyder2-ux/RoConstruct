// from server: 100% by auto
// roc 2012-06 004f3a20  unit: Ogre::RbxMeshPartAdapter::??fillVertices::?BA::FileLoader  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f3a20
//
// 004f3a20  56                   push esi
// 004f3a21  8b742408             mov esi, dword ptr [esp + 8]
// 004f3a25  57                   push edi
// 004f3a26  8b7904               mov edi, dword ptr [ecx + 4]
// 004f3a29  3bfe                 cmp edi, esi
// 004f3a2b  0f84a7000000         je 0x4f3ad8
// 004f3a31  8b5108               mov edx, dword ptr [ecx + 8]
// 004f3a34  3bf2                 cmp esi, edx
// 004f3a36  897104               mov dword ptr [ecx + 4], esi
// 004f3a39  7e73                 jle 0x4f3aae
// 004f3a3b  85d2                 test edx, edx
// 004f3a3d  750e                 jne 0x4f3a4d
// 004f3a3f  57                   push edi
// 004f3a40  897108               mov dword ptr [ecx + 8], esi
// 004f3a43  e8d8f7ffff           call 0x4f3220
// 004f3a48  5f                   pop edi
// 004f3a49  5e                   pop esi
// 004f3a4a  c20800               ret 8
// 004f3a4d  ba10000000           mov edx, 0x10
// 004f3a52  3bf2                 cmp esi, edx
// 004f3a54  7c4a                 jl 0x4f3aa0
// 004f3a56  8b4108               mov eax, dword ptr [ecx + 8]
// 004f3a59  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 004f3a61  03c0                 add eax, eax
// 004f3a63  3d801a0600           cmp eax, 0x61a80
// 004f3a68  7e0a                 jle 0x4f3a74
// 004f3a6a  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 004f3a72  eb0f                 jmp 0x4f3a83
// 004f3a74  3d00fa0000           cmp eax, 0xfa00
// 004f3a79  7e08                 jle 0x4f3a83
// 004f3a7b  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 004f3a83  8b4108               mov eax, dword ptr [ecx + 8]
// 004f3a86  53                   push ebx
// 004f3a87  f30f2ac8             cvtsi2ss xmm1, eax
// 004f3a8b  f30f59c8             mulss xmm1, xmm0
// 004f3a8f  f30f2cd9             cvttss2si ebx, xmm1
// 004f3a93  2bd8                 sub ebx, eax
// 004f3a95  8d0433               lea eax, [ebx + esi]
// 004f3a98  3bc2                 cmp eax, edx
// 004f3a9a  894108               mov dword ptr [ecx + 8], eax
// 004f3a9d  5b                   pop ebx
// 004f3a9e  7d03                 jge 0x4f3aa3
// 004f3aa0  895108               mov dword ptr [ecx + 8], edx
// 004f3aa3  57                   push edi
// 004f3aa4  e877f7ffff           call 0x4f3220
// 004f3aa9  5f                   pop edi
// 004f3aaa  5e                   pop esi
// 004f3aab  c20800               ret 8
// 004f3aae  b856555555           mov eax, 0x55555556
// 004f3ab3  f7ea                 imul edx
// 004f3ab5  8bc2                 mov eax, edx
// 004f3ab7  c1e81f               shr eax, 0x1f
// 004f3aba  03c2                 add eax, edx
// 004f3abc  3bf0                 cmp esi, eax
// 004f3abe  7f18                 jg 0x4f3ad8
// 004f3ac0  807c241000           cmp byte ptr [esp + 0x10], 0
// 004f3ac5  7411                 je 0x4f3ad8
// 004f3ac7  83fe10               cmp esi, 0x10
// 004f3aca  7e0c                 jle 0x4f3ad8
// 004f3acc  3bf7                 cmp esi, edi
// 004f3ace  7c02                 jl 0x4f3ad2
// 004f3ad0  8bf7                 mov esi, edi
// 004f3ad2  56                   push esi
// 004f3ad3  e848f7ffff           call 0x4f3220
// 004f3ad8  5f                   pop edi
// 004f3ad9  5e                   pop esi
// 004f3ada  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@G$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
