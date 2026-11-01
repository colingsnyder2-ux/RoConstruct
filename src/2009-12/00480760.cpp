// from server: 100% by auto
// roc 2009-12 00480760  unit: RBX::AdornRbxGfx  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480760
//
// 00480760  83ec14               sub esp, 0x14
// 00480763  56                   push esi
// 00480764  8bf1                 mov esi, ecx
// 00480766  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0048076a  57                   push edi
// 0048076b  7521                 jne 0x48078e
// 0048076d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00480771  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00480774  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00480778  50                   push eax
// 00480779  51                   push ecx
// 0048077a  6a01                 push 1
// 0048077c  57                   push edi
// 0048077d  8bce                 mov ecx, esi
// 0048077f  e8dcf1ffff           call 0x47f960
// 00480784  8bc7                 mov eax, edi
// 00480786  5f                   pop edi
// 00480787  5e                   pop esi
// 00480788  83c414               add esp, 0x14
// 0048078b  c21000               ret 0x10
// 0048078e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00480792  8b5618               mov edx, dword ptr [esi + 0x18]
// 00480795  8b3a                 mov edi, dword ptr [edx]
// 00480797  8b0e                 mov ecx, dword ptr [esi]
// 00480799  53                   push ebx
// 0048079a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004807a0  85c0                 test eax, eax
// 004807a2  7404                 je 0x4807a8
// 004807a4  3bc1                 cmp eax, ecx
// 004807a6  7406                 je 0x4807ae
// 004807a8  ffd3                 call ebx
// 004807aa  8b442428             mov eax, dword ptr [esp + 0x28]
// 004807ae  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004807b2  55                   push ebp
// 004807b3  3bd7                 cmp edx, edi
// 004807b5  753a                 jne 0x4807f1
// 004807b7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004807bb  83c20c               add edx, 0xc
// 004807be  52                   push edx
// 004807bf  57                   push edi
// 004807c0  ff15d8b59800         call dword ptr [0x98b5d8]
// 004807c6  83c408               add esp, 8
// 004807c9  84c0                 test al, al
// 004807cb  0f849a010000         je 0x48096b
// 004807d1  8b442430             mov eax, dword ptr [esp + 0x30]
// 004807d5  57                   push edi
// 004807d6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004807da  50                   push eax
// 004807db  6a01                 push 1
// 004807dd  57                   push edi
// 004807de  8bce                 mov ecx, esi
// 004807e0  e87bf1ffff           call 0x47f960
// 004807e5  5d                   pop ebp
// 004807e6  5b                   pop ebx
// 004807e7  8bc7                 mov eax, edi
// 004807e9  5f                   pop edi
// 004807ea  5e                   pop esi
// 004807eb  83c414               add esp, 0x14
// 004807ee  c21000               ret 0x10
// 004807f1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004807f4  8b0e                 mov ecx, dword ptr [esi]
// 004807f6  85c0                 test eax, eax
// 004807f8  7404                 je 0x4807fe
// 004807fa  3bc1                 cmp eax, ecx
// 004807fc  7406                 je 0x480804
// 004807fe  ffd3                 call ebx
// 00480800  8b542430             mov edx, dword ptr [esp + 0x30]
// 00480804  3bd7                 cmp edx, edi
// 00480806  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0048080a  753e                 jne 0x48084a
// 0048080c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048080f  8b4108               mov eax, dword ptr [ecx + 8]
// 00480812  83c00c               add eax, 0xc
// 00480815  57                   push edi
// 00480816  50                   push eax
// 00480817  ff15d8b59800         call dword ptr [0x98b5d8]
// 0048081d  83c408               add esp, 8
// 00480820  84c0                 test al, al
// 00480822  0f8443010000         je 0x48096b
// 00480828  8b5618               mov edx, dword ptr [esi + 0x18]
// 0048082b  8b4208               mov eax, dword ptr [edx + 8]
// 0048082e  57                   push edi
// 0048082f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00480833  50                   push eax
// 00480834  6a00                 push 0
// 00480836  57                   push edi
// 00480837  8bce                 mov ecx, esi
// 00480839  e822f1ffff           call 0x47f960
// 0048083e  5d                   pop ebp
// 0048083f  5b                   pop ebx
// 00480840  8bc7                 mov eax, edi
// 00480842  5f                   pop edi
// 00480843  5e                   pop esi
// 00480844  83c414               add esp, 0x14
// 00480847  c21000               ret 0x10
// 0048084a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00480850  83c20c               add edx, 0xc
// 00480853  52                   push edx
// 00480854  57                   push edi
// 00480855  ffd5                 call ebp
// 00480857  83c408               add esp, 8
// 0048085a  84c0                 test al, al
// 0048085c  746c                 je 0x4808ca
// 0048085e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00480862  8b542430             mov edx, dword ptr [esp + 0x30]
// 00480866  894c2410             mov dword ptr [esp + 0x10], ecx
// 0048086a  8d4c2410             lea ecx, [esp + 0x10]
// 0048086e  89542414             mov dword ptr [esp + 0x14], edx
// 00480872  e879e7ffff           call 0x47eff0
// 00480877  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0048087b  57                   push edi
// 0048087c  8d430c               lea eax, [ebx + 0xc]
// 0048087f  50                   push eax
// 00480880  8d4e08               lea ecx, [esi + 8]
// 00480883  e8c89fffff           call 0x47a850
// 00480888  84c0                 test al, al
// 0048088a  743e                 je 0x4808ca
// 0048088c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0048088f  80793900             cmp byte ptr [ecx + 0x39], 0
// 00480893  57                   push edi
// 00480894  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00480898  8bce                 mov ecx, esi
// 0048089a  7415                 je 0x4808b1
// 0048089c  53                   push ebx
// 0048089d  6a00                 push 0
// 0048089f  57                   push edi
// 004808a0  e8bbf0ffff           call 0x47f960
// 004808a5  5d                   pop ebp
// 004808a6  5b                   pop ebx
// 004808a7  8bc7                 mov eax, edi
// 004808a9  5f                   pop edi
// 004808aa  5e                   pop esi
// 004808ab  83c414               add esp, 0x14
// 004808ae  c21000               ret 0x10
// 004808b1  8b542434             mov edx, dword ptr [esp + 0x34]
// 004808b5  52                   push edx
// 004808b6  6a01                 push 1
// 004808b8  57                   push edi
// 004808b9  e8a2f0ffff           call 0x47f960
// 004808be  5d                   pop ebp
// 004808bf  5b                   pop ebx
// 004808c0  8bc7                 mov eax, edi
// 004808c2  5f                   pop edi
// 004808c3  5e                   pop esi
// 004808c4  83c414               add esp, 0x14
// 004808c7  c21000               ret 0x10
// 004808ca  8b442430             mov eax, dword ptr [esp + 0x30]
// 004808ce  83c00c               add eax, 0xc
// 004808d1  57                   push edi
// 004808d2  50                   push eax
// 004808d3  ffd5                 call ebp
// 004808d5  83c408               add esp, 8
// 004808d8  84c0                 test al, al
// 004808da  0f848b000000         je 0x48096b
// 004808e0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004808e4  8b542430             mov edx, dword ptr [esp + 0x30]
// 004808e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004808eb  894c2410             mov dword ptr [esp + 0x10], ecx
// 004808ef  8b0e                 mov ecx, dword ptr [esi]
// 004808f1  894c2418             mov dword ptr [esp + 0x18], ecx
// 004808f5  8d4c2410             lea ecx, [esp + 0x10]
// 004808f9  89542414             mov dword ptr [esp + 0x14], edx
// 004808fd  8944241c             mov dword ptr [esp + 0x1c], eax
// 00480901  e87ae7ffff           call 0x47f080
// 00480906  8d542418             lea edx, [esp + 0x18]
// 0048090a  52                   push edx
// 0048090b  8d4c2414             lea ecx, [esp + 0x14]
// 0048090f  e84cba1400           call 0x5cc360
// 00480914  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00480918  84c0                 test al, al
// 0048091a  7511                 jne 0x48092d
// 0048091c  8d430c               lea eax, [ebx + 0xc]
// 0048091f  50                   push eax
// 00480920  57                   push edi
// 00480921  8d4e08               lea ecx, [esi + 8]
// 00480924  e8279fffff           call 0x47a850
// 00480929  84c0                 test al, al
// 0048092b  743e                 je 0x48096b
// 0048092d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00480931  8b4808               mov ecx, dword ptr [eax + 8]
// 00480934  80793900             cmp byte ptr [ecx + 0x39], 0
// 00480938  57                   push edi
// 00480939  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048093d  8bce                 mov ecx, esi
// 0048093f  7415                 je 0x480956
// 00480941  50                   push eax
// 00480942  6a00                 push 0
// 00480944  57                   push edi
// 00480945  e816f0ffff           call 0x47f960
// 0048094a  5d                   pop ebp
// 0048094b  5b                   pop ebx
// 0048094c  8bc7                 mov eax, edi
// 0048094e  5f                   pop edi
// 0048094f  5e                   pop esi
// 00480950  83c414               add esp, 0x14
// 00480953  c21000               ret 0x10
// 00480956  53                   push ebx
// 00480957  6a01                 push 1
// 00480959  57                   push edi
// 0048095a  e801f0ffff           call 0x47f960
// 0048095f  5d                   pop ebp
// 00480960  5b                   pop ebx
// 00480961  8bc7                 mov eax, edi
// 00480963  5f                   pop edi
// 00480964  5e                   pop esi
// 00480965  83c414               add esp, 0x14
// 00480968  c21000               ret 0x10
// 0048096b  57                   push edi
// 0048096c  8d54241c             lea edx, [esp + 0x1c]
// 00480970  52                   push edx
// 00480971  8bce                 mov ecx, esi
// 00480973  e8f8fcffff           call 0x480670
// 00480978  8b10                 mov edx, dword ptr [eax]
// 0048097a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048097e  5d                   pop ebp
// 0048097f  5b                   pop ebx
// 00480980  8911                 mov dword ptr [ecx], edx
// 00480982  8b4004               mov eax, dword ptr [eax + 4]
// 00480985  5f                   pop edi
// 00480986  894104               mov dword ptr [ecx + 4], eax
// 00480989  8bc1                 mov eax, ecx
// 0048098b  5e                   pop esi
// 0048098c  83c414               add esp, 0x14
// 0048098f  c21000               ret 0x10
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
