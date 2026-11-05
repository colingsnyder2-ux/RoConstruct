// from server: 100% by auto
// roc 2011-06 00547720  unit: G3D::TextInput::TokenException  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00547720
//
// 00547720  56                   push esi
// 00547721  8b742408             mov esi, dword ptr [esp + 8]
// 00547725  57                   push edi
// 00547726  8b7904               mov edi, dword ptr [ecx + 4]
// 00547729  3bfe                 cmp edi, esi
// 0054772b  0f84a2000000         je 0x5477d3
// 00547731  8b5108               mov edx, dword ptr [ecx + 8]
// 00547734  3bf2                 cmp esi, edx
// 00547736  897104               mov dword ptr [ecx + 4], esi
// 00547739  7e6e                 jle 0x5477a9
// 0054773b  85d2                 test edx, edx
// 0054773d  750e                 jne 0x54774d
// 0054773f  57                   push edi
// 00547740  897108               mov dword ptr [ecx + 8], esi
// 00547743  e8a8ecffff           call 0x5463f0
// 00547748  5f                   pop edi
// 00547749  5e                   pop esi
// 0054774a  c20800               ret 8
// 0054774d  ba20000000           mov edx, 0x20
// 00547752  3bf2                 cmp esi, edx
// 00547754  7c45                 jl 0x54779b
// 00547756  8b4108               mov eax, dword ptr [ecx + 8]
// 00547759  3d801a0600           cmp eax, 0x61a80
// 0054775e  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 00547766  7e0a                 jle 0x547772
// 00547768  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 00547770  eb0f                 jmp 0x547781
// 00547772  3d00fa0000           cmp eax, 0xfa00
// 00547777  7e08                 jle 0x547781
// 00547779  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 00547781  53                   push ebx
// 00547782  f30f2ac8             cvtsi2ss xmm1, eax
// 00547786  f30f59c8             mulss xmm1, xmm0
// 0054778a  f30f2cd9             cvttss2si ebx, xmm1
// 0054778e  2bd8                 sub ebx, eax
// 00547790  8d0433               lea eax, [ebx + esi]
// 00547793  3bc2                 cmp eax, edx
// 00547795  894108               mov dword ptr [ecx + 8], eax
// 00547798  5b                   pop ebx
// 00547799  7d03                 jge 0x54779e
// 0054779b  895108               mov dword ptr [ecx + 8], edx
// 0054779e  57                   push edi
// 0054779f  e84cecffff           call 0x5463f0
// 005477a4  5f                   pop edi
// 005477a5  5e                   pop esi
// 005477a6  c20800               ret 8
// 005477a9  b856555555           mov eax, 0x55555556
// 005477ae  f7ea                 imul edx
// 005477b0  8bc2                 mov eax, edx
// 005477b2  c1e81f               shr eax, 0x1f
// 005477b5  03c2                 add eax, edx
// 005477b7  3bf0                 cmp esi, eax
// 005477b9  7f18                 jg 0x5477d3
// 005477bb  807c241000           cmp byte ptr [esp + 0x10], 0
// 005477c0  7411                 je 0x5477d3
// 005477c2  83fe20               cmp esi, 0x20
// 005477c5  7e0c                 jle 0x5477d3
// 005477c7  3bf7                 cmp esi, edi
// 005477c9  7c02                 jl 0x5477cd
// 005477cb  8bf7                 mov esi, edi
// 005477cd  56                   push esi
// 005477ce  e81decffff           call 0x5463f0
// 005477d3  5f                   pop edi
// 005477d4  5e                   pop esi
// 005477d5  c20800               ret 8
// library rbx2016-g3d/BinaryInput.cpp (function ?resize@?$Array@_N$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
