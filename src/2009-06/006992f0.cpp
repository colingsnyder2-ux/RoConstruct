// from server: 100% by auto
// roc 2009-06 006992f0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006992f0
//
// 006992f0  83ec14               sub esp, 0x14
// 006992f3  56                   push esi
// 006992f4  8bf1                 mov esi, ecx
// 006992f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006992fa  57                   push edi
// 006992fb  7521                 jne 0x69931e
// 006992fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00699301  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00699304  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00699308  50                   push eax
// 00699309  51                   push ecx
// 0069930a  6a01                 push 1
// 0069930c  57                   push edi
// 0069930d  8bce                 mov ecx, esi
// 0069930f  e80cba0500           call 0x6f4d20
// 00699314  8bc7                 mov eax, edi
// 00699316  5f                   pop edi
// 00699317  5e                   pop esi
// 00699318  83c414               add esp, 0x14
// 0069931b  c21000               ret 0x10
// 0069931e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00699322  8b5618               mov edx, dword ptr [esi + 0x18]
// 00699325  8b3a                 mov edi, dword ptr [edx]
// 00699327  8b06                 mov eax, dword ptr [esi]
// 00699329  53                   push ebx
// 0069932a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00699330  85c9                 test ecx, ecx
// 00699332  7404                 je 0x699338
// 00699334  3bc8                 cmp ecx, eax
// 00699336  7406                 je 0x69933e
// 00699338  ffd3                 call ebx
// 0069933a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0069933e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00699342  3bc7                 cmp eax, edi
// 00699344  752a                 jne 0x699370
// 00699346  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0069934a  8b0f                 mov ecx, dword ptr [edi]
// 0069934c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0069934f  0f834b010000         jae 0x6994a0
// 00699355  57                   push edi
// 00699356  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0069935a  50                   push eax
// 0069935b  6a01                 push 1
// 0069935d  57                   push edi
// 0069935e  8bce                 mov ecx, esi
// 00699360  e8bbb90500           call 0x6f4d20
// 00699365  5b                   pop ebx
// 00699366  8bc7                 mov eax, edi
// 00699368  5f                   pop edi
// 00699369  5e                   pop esi
// 0069936a  83c414               add esp, 0x14
// 0069936d  c21000               ret 0x10
// 00699370  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00699373  8b16                 mov edx, dword ptr [esi]
// 00699375  85c9                 test ecx, ecx
// 00699377  7404                 je 0x69937d
// 00699379  3bca                 cmp ecx, edx
// 0069937b  740a                 je 0x699387
// 0069937d  ffd3                 call ebx
// 0069937f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00699383  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00699387  3bc7                 cmp eax, edi
// 00699389  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0069938d  752c                 jne 0x6993bb
// 0069938f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00699392  8b4208               mov eax, dword ptr [edx + 8]
// 00699395  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00699398  3b0f                 cmp ecx, dword ptr [edi]
// 0069939a  0f8300010000         jae 0x6994a0
// 006993a0  57                   push edi
// 006993a1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006993a5  50                   push eax
// 006993a6  6a00                 push 0
// 006993a8  57                   push edi
// 006993a9  8bce                 mov ecx, esi
// 006993ab  e870b90500           call 0x6f4d20
// 006993b0  5b                   pop ebx
// 006993b1  8bc7                 mov eax, edi
// 006993b3  5f                   pop edi
// 006993b4  5e                   pop esi
// 006993b5  83c414               add esp, 0x14
// 006993b8  c21000               ret 0x10
// 006993bb  8b17                 mov edx, dword ptr [edi]
// 006993bd  39500c               cmp dword ptr [eax + 0xc], edx
// 006993c0  7663                 jbe 0x699425
// 006993c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006993c6  8d4c240c             lea ecx, [esp + 0xc]
// 006993ca  89442410             mov dword ptr [esp + 0x10], eax
// 006993ce  e81dc70000           call 0x6a5af0
// 006993d3  8b17                 mov edx, dword ptr [edi]
// 006993d5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006993d9  39500c               cmp dword ptr [eax + 0xc], edx
// 006993dc  733c                 jae 0x69941a
// 006993de  8b5008               mov edx, dword ptr [eax + 8]
// 006993e1  807a1500             cmp byte ptr [edx + 0x15], 0
// 006993e5  57                   push edi
// 006993e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006993ea  8bce                 mov ecx, esi
// 006993ec  7414                 je 0x699402
// 006993ee  50                   push eax
// 006993ef  6a00                 push 0
// 006993f1  57                   push edi
// 006993f2  e829b90500           call 0x6f4d20
// 006993f7  5b                   pop ebx
// 006993f8  8bc7                 mov eax, edi
// 006993fa  5f                   pop edi
// 006993fb  5e                   pop esi
// 006993fc  83c414               add esp, 0x14
// 006993ff  c21000               ret 0x10
// 00699402  8b442430             mov eax, dword ptr [esp + 0x30]
// 00699406  50                   push eax
// 00699407  6a01                 push 1
// 00699409  57                   push edi
// 0069940a  e811b90500           call 0x6f4d20
// 0069940f  5b                   pop ebx
// 00699410  8bc7                 mov eax, edi
// 00699412  5f                   pop edi
// 00699413  5e                   pop esi
// 00699414  83c414               add esp, 0x14
// 00699417  c21000               ret 0x10
// 0069941a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0069941e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00699422  39500c               cmp dword ptr [eax + 0xc], edx
// 00699425  7379                 jae 0x6994a0
// 00699427  8b16                 mov edx, dword ptr [esi]
// 00699429  894c240c             mov dword ptr [esp + 0xc], ecx
// 0069942d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00699430  894c2418             mov dword ptr [esp + 0x18], ecx
// 00699434  8d4c240c             lea ecx, [esp + 0xc]
// 00699438  89442410             mov dword ptr [esp + 0x10], eax
// 0069943c  89542414             mov dword ptr [esp + 0x14], edx
// 00699440  e82bfdf4ff           call 0x5e9170
// 00699445  8d442414             lea eax, [esp + 0x14]
// 00699449  50                   push eax
// 0069944a  8d4c2410             lea ecx, [esp + 0x10]
// 0069944e  e84da0faff           call 0x6434a0
// 00699453  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00699457  84c0                 test al, al
// 00699459  7507                 jne 0x699462
// 0069945b  8b17                 mov edx, dword ptr [edi]
// 0069945d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00699460  733e                 jae 0x6994a0
// 00699462  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00699466  8b5008               mov edx, dword ptr [eax + 8]
// 00699469  807a1500             cmp byte ptr [edx + 0x15], 0
// 0069946d  57                   push edi
// 0069946e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00699472  7416                 je 0x69948a
// 00699474  50                   push eax
// 00699475  6a00                 push 0
// 00699477  57                   push edi
// 00699478  8bce                 mov ecx, esi
// 0069947a  e8a1b80500           call 0x6f4d20
// 0069947f  5b                   pop ebx
// 00699480  8bc7                 mov eax, edi
// 00699482  5f                   pop edi
// 00699483  5e                   pop esi
// 00699484  83c414               add esp, 0x14
// 00699487  c21000               ret 0x10
// 0069948a  51                   push ecx
// 0069948b  6a01                 push 1
// 0069948d  57                   push edi
// 0069948e  8bce                 mov ecx, esi
// 00699490  e88bb80500           call 0x6f4d20
// 00699495  5b                   pop ebx
// 00699496  8bc7                 mov eax, edi
// 00699498  5f                   pop edi
// 00699499  5e                   pop esi
// 0069949a  83c414               add esp, 0x14
// 0069949d  c21000               ret 0x10
// 006994a0  57                   push edi
// 006994a1  8d442418             lea eax, [esp + 0x18]
// 006994a5  50                   push eax
// 006994a6  8bce                 mov ecx, esi
// 006994a8  e853fdffff           call 0x699200
// 006994ad  8b10                 mov edx, dword ptr [eax]
// 006994af  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006994b3  5b                   pop ebx
// 006994b4  8911                 mov dword ptr [ecx], edx
// 006994b6  8b4004               mov eax, dword ptr [eax + 4]
// 006994b9  5f                   pop edi
// 006994ba  894104               mov dword ptr [ecx + 4], eax
// 006994bd  8bc1                 mov eax, ecx
// 006994bf  5e                   pop esi
// 006994c0  83c414               add esp, 0x14
// 006994c3  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
