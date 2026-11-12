// from server: 100% by auto
// roc 2008-06 004bc720  unit: ProfiledRakPeer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc720
//
// 004bc720  55                   push ebp
// 004bc721  8bec                 mov ebp, esp
// 004bc723  51                   push ecx
// 004bc724  56                   push esi
// 004bc725  57                   push edi
// 004bc726  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004bc72d  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bc730  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bc733  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004bc736  8b06                 mov eax, dword ptr [esi]
// 004bc738  33d2                 xor edx, edx
// 004bc73a  0107                 add dword ptr [edi], eax
// 004bc73c  8b4604               mov eax, dword ptr [esi + 4]
// 004bc73f  114704               adc dword ptr [edi + 4], eax
// 004bc742  8b4608               mov eax, dword ptr [esi + 8]
// 004bc745  114708               adc dword ptr [edi + 8], eax
// 004bc748  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc74b  11470c               adc dword ptr [edi + 0xc], eax
// 004bc74e  e322                 jecxz 0x4bc772
// 004bc750  42                   inc edx
// 004bc751  42                   inc edx
// 004bc752  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bc755  1104d7               adc dword ptr [edi + edx*8], eax
// 004bc758  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bc75c  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bc760  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bc764  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bc768  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bc76c  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bc770  e2de                 loop 0x4bc750
// 004bc772  5f                   pop edi
// 004bc773  5e                   pop esi
// 004bc774  8be5                 mov esp, ebp
// 004bc776  5d                   pop ebp
// 004bc777  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$add@$$BY03I@big@@YAXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
