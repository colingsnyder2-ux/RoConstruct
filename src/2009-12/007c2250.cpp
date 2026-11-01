// from server: 100% by auto
// roc 2009-12 007c2250  unit: RBX::ImageButton  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c2250
//
// 007c2250  56                   push esi
// 007c2251  8bf1                 mov esi, ecx
// 007c2253  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007c2256  85c0                 test eax, eax
// 007c2258  7460                 je 0x7c22ba
// 007c225a  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c225d  8b5614               mov edx, dword ptr [esi + 0x14]
// 007c2260  8d4408ff             lea eax, [eax + ecx - 1]
// 007c2264  8bc8                 mov ecx, eax
// 007c2266  d1e9                 shr ecx, 1
// 007c2268  3bd1                 cmp edx, ecx
// 007c226a  7702                 ja 0x7c226e
// 007c226c  2bca                 sub ecx, edx
// 007c226e  8b5610               mov edx, dword ptr [esi + 0x10]
// 007c2271  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 007c2274  83e001               and eax, 1
// 007c2277  8d44c104             lea eax, [ecx + eax*8 + 4]
// 007c227b  57                   push edi
// 007c227c  8b38                 mov edi, dword ptr [eax]
// 007c227e  85ff                 test edi, edi
// 007c2280  742a                 je 0x7c22ac
// 007c2282  8d5704               lea edx, [edi + 4]
// 007c2285  83c8ff               or eax, 0xffffffff
// 007c2288  f00fc102             lock xadd dword ptr [edx], eax
// 007c228c  751e                 jne 0x7c22ac
// 007c228e  8b17                 mov edx, dword ptr [edi]
// 007c2290  8b4204               mov eax, dword ptr [edx + 4]
// 007c2293  8bcf                 mov ecx, edi
// 007c2295  ffd0                 call eax
// 007c2297  8d4f08               lea ecx, [edi + 8]
// 007c229a  83caff               or edx, 0xffffffff
// 007c229d  f00fc111             lock xadd dword ptr [ecx], edx
// 007c22a1  7509                 jne 0x7c22ac
// 007c22a3  8b07                 mov eax, dword ptr [edi]
// 007c22a5  8b5008               mov edx, dword ptr [eax + 8]
// 007c22a8  8bcf                 mov ecx, edi
// 007c22aa  ffd2                 call edx
// 007c22ac  83461cff             add dword ptr [esi + 0x1c], -1
// 007c22b0  5f                   pop edi
// 007c22b1  7507                 jne 0x7c22ba
// 007c22b3  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007c22ba  5e                   pop esi
// 007c22bb  c3                   ret 
// library templates-boost-1_34_1/deque_sp.cpp (function ?pop_back@?$deque@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_sp.cpp
