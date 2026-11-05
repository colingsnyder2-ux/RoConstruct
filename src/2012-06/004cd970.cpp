// from server: 100% by auto
// roc 2012-06 004cd970  unit: Ogre::GfxClustererPart  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cd970
//
// 004cd970  56                   push esi
// 004cd971  8bf1                 mov esi, ecx
// 004cd973  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004cd977  57                   push edi
// 004cd978  8b7e04               mov edi, dword ptr [esi + 4]
// 004cd97b  3bf9                 cmp edi, ecx
// 004cd97d  0f84cf000000         je 0x4cda52
// 004cd983  8b5608               mov edx, dword ptr [esi + 8]
// 004cd986  3bca                 cmp ecx, edx
// 004cd988  894e04               mov dword ptr [esi + 4], ecx
// 004cd98b  7e64                 jle 0x4cd9f1
// 004cd98d  85d2                 test edx, edx
// 004cd98f  7506                 jne 0x4cd997
// 004cd991  894e08               mov dword ptr [esi + 8], ecx
// 004cd994  57                   push edi
// 004cd995  eb7f                 jmp 0x4cda16
// 004cd997  ba0a000000           mov edx, 0xa
// 004cd99c  3bca                 cmp ecx, edx
// 004cd99e  7c4b                 jl 0x4cd9eb
// 004cd9a0  8b4608               mov eax, dword ptr [esi + 8]
// 004cd9a3  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 004cd9ab  c1e004               shl eax, 4
// 004cd9ae  3d801a0600           cmp eax, 0x61a80
// 004cd9b3  7e0a                 jle 0x4cd9bf
// 004cd9b5  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 004cd9bd  eb0f                 jmp 0x4cd9ce
// 004cd9bf  3d00fa0000           cmp eax, 0xfa00
// 004cd9c4  7e08                 jle 0x4cd9ce
// 004cd9c6  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 004cd9ce  8b4608               mov eax, dword ptr [esi + 8]
// 004cd9d1  53                   push ebx
// 004cd9d2  f30f2ac8             cvtsi2ss xmm1, eax
// 004cd9d6  f30f59c8             mulss xmm1, xmm0
// 004cd9da  f30f2cd9             cvttss2si ebx, xmm1
// 004cd9de  2bd8                 sub ebx, eax
// 004cd9e0  8d040b               lea eax, [ebx + ecx]
// 004cd9e3  3bc2                 cmp eax, edx
// 004cd9e5  894608               mov dword ptr [esi + 8], eax
// 004cd9e8  5b                   pop ebx
// 004cd9e9  7d03                 jge 0x4cd9ee
// 004cd9eb  895608               mov dword ptr [esi + 8], edx
// 004cd9ee  57                   push edi
// 004cd9ef  eb25                 jmp 0x4cda16
// 004cd9f1  b856555555           mov eax, 0x55555556
// 004cd9f6  f7ea                 imul edx
// 004cd9f8  8bc2                 mov eax, edx
// 004cd9fa  c1e81f               shr eax, 0x1f
// 004cd9fd  03c2                 add eax, edx
// 004cd9ff  3bc8                 cmp ecx, eax
// 004cda01  7f1a                 jg 0x4cda1d
// 004cda03  807c241000           cmp byte ptr [esp + 0x10], 0
// 004cda08  7413                 je 0x4cda1d
// 004cda0a  83f90a               cmp ecx, 0xa
// 004cda0d  7e0e                 jle 0x4cda1d
// 004cda0f  3bcf                 cmp ecx, edi
// 004cda11  7c02                 jl 0x4cda15
// 004cda13  8bcf                 mov ecx, edi
// 004cda15  51                   push ecx
// 004cda16  8bce                 mov ecx, esi
// 004cda18  e8f3f6ffff           call 0x4cd110
// 004cda1d  3b7e04               cmp edi, dword ptr [esi + 4]
// 004cda20  8bcf                 mov ecx, edi
// 004cda22  7d2e                 jge 0x4cda52
// 004cda24  0f57c0               xorps xmm0, xmm0
// 004cda27  c1e704               shl edi, 4
// 004cda2a  8bd7                 mov edx, edi
// 004cda2c  8d642400             lea esp, [esp]
// 004cda30  8b06                 mov eax, dword ptr [esi]
// 004cda32  03c2                 add eax, edx
// 004cda34  7413                 je 0x4cda49
// 004cda36  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 004cda3b  f30f114008           movss dword ptr [eax + 8], xmm0
// 004cda40  f30f114004           movss dword ptr [eax + 4], xmm0
// 004cda45  f30f1100             movss dword ptr [eax], xmm0
// 004cda49  41                   inc ecx
// 004cda4a  83c210               add edx, 0x10
// 004cda4d  3b4e04               cmp ecx, dword ptr [esi + 4]
// 004cda50  7cde                 jl 0x4cda30
// 004cda52  5f                   pop edi
// 004cda53  5e                   pop esi
// 004cda54  c20800               ret 8
// library rbx2016-g3d/GCamera.cpp (function ?resize@?$Array@VVector4@G3D@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GCamera.cpp
