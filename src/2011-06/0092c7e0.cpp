// from server: 100% by auto
// roc 2011-06 0092c7e0  unit: Ogre::GfxClustererPart  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092c7e0
//
// 0092c7e0  56                   push esi
// 0092c7e1  8bf1                 mov esi, ecx
// 0092c7e3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0092c7e7  57                   push edi
// 0092c7e8  8b7e04               mov edi, dword ptr [esi + 4]
// 0092c7eb  3bf9                 cmp edi, ecx
// 0092c7ed  0f84cf000000         je 0x92c8c2
// 0092c7f3  8b5608               mov edx, dword ptr [esi + 8]
// 0092c7f6  3bca                 cmp ecx, edx
// 0092c7f8  894e04               mov dword ptr [esi + 4], ecx
// 0092c7fb  7e64                 jle 0x92c861
// 0092c7fd  85d2                 test edx, edx
// 0092c7ff  7506                 jne 0x92c807
// 0092c801  894e08               mov dword ptr [esi + 8], ecx
// 0092c804  57                   push edi
// 0092c805  eb7f                 jmp 0x92c886
// 0092c807  ba0a000000           mov edx, 0xa
// 0092c80c  3bca                 cmp ecx, edx
// 0092c80e  7c4b                 jl 0x92c85b
// 0092c810  8b4608               mov eax, dword ptr [esi + 8]
// 0092c813  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 0092c81b  c1e004               shl eax, 4
// 0092c81e  3d801a0600           cmp eax, 0x61a80
// 0092c823  7e0a                 jle 0x92c82f
// 0092c825  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 0092c82d  eb0f                 jmp 0x92c83e
// 0092c82f  3d00fa0000           cmp eax, 0xfa00
// 0092c834  7e08                 jle 0x92c83e
// 0092c836  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 0092c83e  8b4608               mov eax, dword ptr [esi + 8]
// 0092c841  53                   push ebx
// 0092c842  f30f2ac8             cvtsi2ss xmm1, eax
// 0092c846  f30f59c8             mulss xmm1, xmm0
// 0092c84a  f30f2cd9             cvttss2si ebx, xmm1
// 0092c84e  2bd8                 sub ebx, eax
// 0092c850  8d040b               lea eax, [ebx + ecx]
// 0092c853  3bc2                 cmp eax, edx
// 0092c855  894608               mov dword ptr [esi + 8], eax
// 0092c858  5b                   pop ebx
// 0092c859  7d03                 jge 0x92c85e
// 0092c85b  895608               mov dword ptr [esi + 8], edx
// 0092c85e  57                   push edi
// 0092c85f  eb25                 jmp 0x92c886
// 0092c861  b856555555           mov eax, 0x55555556
// 0092c866  f7ea                 imul edx
// 0092c868  8bc2                 mov eax, edx
// 0092c86a  c1e81f               shr eax, 0x1f
// 0092c86d  03c2                 add eax, edx
// 0092c86f  3bc8                 cmp ecx, eax
// 0092c871  7f1a                 jg 0x92c88d
// 0092c873  807c241000           cmp byte ptr [esp + 0x10], 0
// 0092c878  7413                 je 0x92c88d
// 0092c87a  83f90a               cmp ecx, 0xa
// 0092c87d  7e0e                 jle 0x92c88d
// 0092c87f  3bcf                 cmp ecx, edi
// 0092c881  7c02                 jl 0x92c885
// 0092c883  8bcf                 mov ecx, edi
// 0092c885  51                   push ecx
// 0092c886  8bce                 mov ecx, esi
// 0092c888  e823f8ffff           call 0x92c0b0
// 0092c88d  3b7e04               cmp edi, dword ptr [esi + 4]
// 0092c890  8bcf                 mov ecx, edi
// 0092c892  7d2e                 jge 0x92c8c2
// 0092c894  0f57c0               xorps xmm0, xmm0
// 0092c897  c1e704               shl edi, 4
// 0092c89a  8bd7                 mov edx, edi
// 0092c89c  8d642400             lea esp, [esp]
// 0092c8a0  8b06                 mov eax, dword ptr [esi]
// 0092c8a2  03c2                 add eax, edx
// 0092c8a4  7413                 je 0x92c8b9
// 0092c8a6  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 0092c8ab  f30f114008           movss dword ptr [eax + 8], xmm0
// 0092c8b0  f30f114004           movss dword ptr [eax + 4], xmm0
// 0092c8b5  f30f1100             movss dword ptr [eax], xmm0
// 0092c8b9  41                   inc ecx
// 0092c8ba  83c210               add edx, 0x10
// 0092c8bd  3b4e04               cmp ecx, dword ptr [esi + 4]
// 0092c8c0  7cde                 jl 0x92c8a0
// 0092c8c2  5f                   pop edi
// 0092c8c3  5e                   pop esi
// 0092c8c4  c20800               ret 8
// library rbx2016-g3d/GCamera.cpp (function ?resize@?$Array@VVector4@G3D@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GCamera.cpp
