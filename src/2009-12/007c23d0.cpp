// from server: 100% by auto
// roc 2009-12 007c23d0  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c23d0
//
// 007c23d0  56                   push esi
// 007c23d1  8bf1                 mov esi, ecx
// 007c23d3  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007c23d7  7469                 je 0x7c2442
// 007c23d9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c23dc  8b5610               mov edx, dword ptr [esi + 0x10]
// 007c23df  8bc8                 mov ecx, eax
// 007c23e1  d1e9                 shr ecx, 1
// 007c23e3  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 007c23e6  83e001               and eax, 1
// 007c23e9  8d44c104             lea eax, [ecx + eax*8 + 4]
// 007c23ed  57                   push edi
// 007c23ee  8b38                 mov edi, dword ptr [eax]
// 007c23f0  85ff                 test edi, edi
// 007c23f2  742a                 je 0x7c241e
// 007c23f4  8d5704               lea edx, [edi + 4]
// 007c23f7  83c8ff               or eax, 0xffffffff
// 007c23fa  f00fc102             lock xadd dword ptr [edx], eax
// 007c23fe  751e                 jne 0x7c241e
// 007c2400  8b17                 mov edx, dword ptr [edi]
// 007c2402  8b4204               mov eax, dword ptr [edx + 4]
// 007c2405  8bcf                 mov ecx, edi
// 007c2407  ffd0                 call eax
// 007c2409  8d4f08               lea ecx, [edi + 8]
// 007c240c  83caff               or edx, 0xffffffff
// 007c240f  f00fc111             lock xadd dword ptr [ecx], edx
// 007c2413  7509                 jne 0x7c241e
// 007c2415  8b07                 mov eax, dword ptr [edi]
// 007c2417  8b5008               mov edx, dword ptr [eax + 8]
// 007c241a  8bcf                 mov ecx, edi
// 007c241c  ffd2                 call edx
// 007c241e  ff4618               inc dword ptr [esi + 0x18]
// 007c2421  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007c2424  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c2427  03c9                 add ecx, ecx
// 007c2429  5f                   pop edi
// 007c242a  3bc8                 cmp ecx, eax
// 007c242c  7707                 ja 0x7c2435
// 007c242e  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007c2435  83461cff             add dword ptr [esi + 0x1c], -1
// 007c2439  7507                 jne 0x7c2442
// 007c243b  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007c2442  5e                   pop esi
// 007c2443  c3                   ret 
// library templates-boost-1_34_1/deque_sp.cpp (function ?pop_front@?$deque@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_sp.cpp
