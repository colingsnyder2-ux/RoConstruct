// from server: 100% by auto
// roc 2008-06 004bc780  unit: ProfiledRakPeer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc780
//
// 004bc780  55                   push ebp
// 004bc781  8bec                 mov ebp, esp
// 004bc783  51                   push ecx
// 004bc784  56                   push esi
// 004bc785  57                   push edi
// 004bc786  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004bc78d  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bc790  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bc793  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004bc796  8b06                 mov eax, dword ptr [esi]
// 004bc798  33d2                 xor edx, edx
// 004bc79a  0107                 add dword ptr [edi], eax
// 004bc79c  8b4604               mov eax, dword ptr [esi + 4]
// 004bc79f  114704               adc dword ptr [edi + 4], eax
// 004bc7a2  8b4608               mov eax, dword ptr [esi + 8]
// 004bc7a5  114708               adc dword ptr [edi + 8], eax
// 004bc7a8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc7ab  11470c               adc dword ptr [edi + 0xc], eax
// 004bc7ae  e322                 jecxz 0x4bc7d2
// 004bc7b0  42                   inc edx
// 004bc7b1  42                   inc edx
// 004bc7b2  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bc7b5  1104d7               adc dword ptr [edi + edx*8], eax
// 004bc7b8  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bc7bc  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bc7c0  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bc7c4  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bc7c8  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bc7cc  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bc7d0  e2de                 loop 0x4bc7b0
// 004bc7d2  5f                   pop edi
// 004bc7d3  5e                   pop esi
// 004bc7d4  8be5                 mov esp, ebp
// 004bc7d6  5d                   pop ebp
// 004bc7d7  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$add@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
