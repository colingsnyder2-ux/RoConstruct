// from server: 100% by auto
// roc 2009-06 006e4f80  unit: RBX::ScoreHud  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4f80
//
// 006e4f80  83ec14               sub esp, 0x14
// 006e4f83  56                   push esi
// 006e4f84  8bf1                 mov esi, ecx
// 006e4f86  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006e4f8a  57                   push edi
// 006e4f8b  7521                 jne 0x6e4fae
// 006e4f8d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e4f91  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e4f94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e4f98  50                   push eax
// 006e4f99  51                   push ecx
// 006e4f9a  6a01                 push 1
// 006e4f9c  57                   push edi
// 006e4f9d  8bce                 mov ecx, esi
// 006e4f9f  e8aceaffff           call 0x6e3a50
// 006e4fa4  8bc7                 mov eax, edi
// 006e4fa6  5f                   pop edi
// 006e4fa7  5e                   pop esi
// 006e4fa8  83c414               add esp, 0x14
// 006e4fab  c21000               ret 0x10
// 006e4fae  8b442424             mov eax, dword ptr [esp + 0x24]
// 006e4fb2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e4fb5  8b3a                 mov edi, dword ptr [edx]
// 006e4fb7  8b0e                 mov ecx, dword ptr [esi]
// 006e4fb9  53                   push ebx
// 006e4fba  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006e4fc0  85c0                 test eax, eax
// 006e4fc2  7404                 je 0x6e4fc8
// 006e4fc4  3bc1                 cmp eax, ecx
// 006e4fc6  7406                 je 0x6e4fce
// 006e4fc8  ffd3                 call ebx
// 006e4fca  8b442428             mov eax, dword ptr [esp + 0x28]
// 006e4fce  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006e4fd2  55                   push ebp
// 006e4fd3  3bd7                 cmp edx, edi
// 006e4fd5  753a                 jne 0x6e5011
// 006e4fd7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006e4fdb  83c20c               add edx, 0xc
// 006e4fde  52                   push edx
// 006e4fdf  57                   push edi
// 006e4fe0  ff15e0e48900         call dword ptr [0x89e4e0]
// 006e4fe6  83c408               add esp, 8
// 006e4fe9  84c0                 test al, al
// 006e4feb  0f849a010000         je 0x6e518b
// 006e4ff1  8b442430             mov eax, dword ptr [esp + 0x30]
// 006e4ff5  57                   push edi
// 006e4ff6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006e4ffa  50                   push eax
// 006e4ffb  6a01                 push 1
// 006e4ffd  57                   push edi
// 006e4ffe  8bce                 mov ecx, esi
// 006e5000  e84beaffff           call 0x6e3a50
// 006e5005  5d                   pop ebp
// 006e5006  5b                   pop ebx
// 006e5007  8bc7                 mov eax, edi
// 006e5009  5f                   pop edi
// 006e500a  5e                   pop esi
// 006e500b  83c414               add esp, 0x14
// 006e500e  c21000               ret 0x10
// 006e5011  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006e5014  8b0e                 mov ecx, dword ptr [esi]
// 006e5016  85c0                 test eax, eax
// 006e5018  7404                 je 0x6e501e
// 006e501a  3bc1                 cmp eax, ecx
// 006e501c  7406                 je 0x6e5024
// 006e501e  ffd3                 call ebx
// 006e5020  8b542430             mov edx, dword ptr [esp + 0x30]
// 006e5024  3bd7                 cmp edx, edi
// 006e5026  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006e502a  753e                 jne 0x6e506a
// 006e502c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e502f  8b4108               mov eax, dword ptr [ecx + 8]
// 006e5032  83c00c               add eax, 0xc
// 006e5035  57                   push edi
// 006e5036  50                   push eax
// 006e5037  ff15e0e48900         call dword ptr [0x89e4e0]
// 006e503d  83c408               add esp, 8
// 006e5040  84c0                 test al, al
// 006e5042  0f8443010000         je 0x6e518b
// 006e5048  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e504b  8b4208               mov eax, dword ptr [edx + 8]
// 006e504e  57                   push edi
// 006e504f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006e5053  50                   push eax
// 006e5054  6a00                 push 0
// 006e5056  57                   push edi
// 006e5057  8bce                 mov ecx, esi
// 006e5059  e8f2e9ffff           call 0x6e3a50
// 006e505e  5d                   pop ebp
// 006e505f  5b                   pop ebx
// 006e5060  8bc7                 mov eax, edi
// 006e5062  5f                   pop edi
// 006e5063  5e                   pop esi
// 006e5064  83c414               add esp, 0x14
// 006e5067  c21000               ret 0x10
// 006e506a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 006e5070  83c20c               add edx, 0xc
// 006e5073  52                   push edx
// 006e5074  57                   push edi
// 006e5075  ffd5                 call ebp
// 006e5077  83c408               add esp, 8
// 006e507a  84c0                 test al, al
// 006e507c  746c                 je 0x6e50ea
// 006e507e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006e5082  8b542430             mov edx, dword ptr [esp + 0x30]
// 006e5086  894c2410             mov dword ptr [esp + 0x10], ecx
// 006e508a  8d4c2410             lea ecx, [esp + 0x10]
// 006e508e  89542414             mov dword ptr [esp + 0x14], edx
// 006e5092  e889d1ffff           call 0x6e2220
// 006e5097  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006e509b  57                   push edi
// 006e509c  8d430c               lea eax, [ebx + 0xc]
// 006e509f  50                   push eax
// 006e50a0  8d4e08               lea ecx, [esi + 8]
// 006e50a3  e8683fefff           call 0x5d9010
// 006e50a8  84c0                 test al, al
// 006e50aa  743e                 je 0x6e50ea
// 006e50ac  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006e50af  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e50b3  57                   push edi
// 006e50b4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006e50b8  8bce                 mov ecx, esi
// 006e50ba  7415                 je 0x6e50d1
// 006e50bc  53                   push ebx
// 006e50bd  6a00                 push 0
// 006e50bf  57                   push edi
// 006e50c0  e88be9ffff           call 0x6e3a50
// 006e50c5  5d                   pop ebp
// 006e50c6  5b                   pop ebx
// 006e50c7  8bc7                 mov eax, edi
// 006e50c9  5f                   pop edi
// 006e50ca  5e                   pop esi
// 006e50cb  83c414               add esp, 0x14
// 006e50ce  c21000               ret 0x10
// 006e50d1  8b542434             mov edx, dword ptr [esp + 0x34]
// 006e50d5  52                   push edx
// 006e50d6  6a01                 push 1
// 006e50d8  57                   push edi
// 006e50d9  e872e9ffff           call 0x6e3a50
// 006e50de  5d                   pop ebp
// 006e50df  5b                   pop ebx
// 006e50e0  8bc7                 mov eax, edi
// 006e50e2  5f                   pop edi
// 006e50e3  5e                   pop esi
// 006e50e4  83c414               add esp, 0x14
// 006e50e7  c21000               ret 0x10
// 006e50ea  8b442430             mov eax, dword ptr [esp + 0x30]
// 006e50ee  83c00c               add eax, 0xc
// 006e50f1  57                   push edi
// 006e50f2  50                   push eax
// 006e50f3  ffd5                 call ebp
// 006e50f5  83c408               add esp, 8
// 006e50f8  84c0                 test al, al
// 006e50fa  0f848b000000         je 0x6e518b
// 006e5100  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006e5104  8b542430             mov edx, dword ptr [esp + 0x30]
// 006e5108  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e510b  894c2410             mov dword ptr [esp + 0x10], ecx
// 006e510f  8b0e                 mov ecx, dword ptr [esi]
// 006e5111  894c2418             mov dword ptr [esp + 0x18], ecx
// 006e5115  8d4c2410             lea ecx, [esp + 0x10]
// 006e5119  89542414             mov dword ptr [esp + 0x14], edx
// 006e511d  8944241c             mov dword ptr [esp + 0x1c], eax
// 006e5121  e84a32f3ff           call 0x618370
// 006e5126  8d542418             lea edx, [esp + 0x18]
// 006e512a  52                   push edx
// 006e512b  8d4c2414             lea ecx, [esp + 0x14]
// 006e512f  e86ce3f5ff           call 0x6434a0
// 006e5134  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006e5138  84c0                 test al, al
// 006e513a  7511                 jne 0x6e514d
// 006e513c  8d430c               lea eax, [ebx + 0xc]
// 006e513f  50                   push eax
// 006e5140  57                   push edi
// 006e5141  8d4e08               lea ecx, [esi + 8]
// 006e5144  e8c73eefff           call 0x5d9010
// 006e5149  84c0                 test al, al
// 006e514b  743e                 je 0x6e518b
// 006e514d  8b442430             mov eax, dword ptr [esp + 0x30]
// 006e5151  8b4808               mov ecx, dword ptr [eax + 8]
// 006e5154  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e5158  57                   push edi
// 006e5159  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006e515d  8bce                 mov ecx, esi
// 006e515f  7415                 je 0x6e5176
// 006e5161  50                   push eax
// 006e5162  6a00                 push 0
// 006e5164  57                   push edi
// 006e5165  e8e6e8ffff           call 0x6e3a50
// 006e516a  5d                   pop ebp
// 006e516b  5b                   pop ebx
// 006e516c  8bc7                 mov eax, edi
// 006e516e  5f                   pop edi
// 006e516f  5e                   pop esi
// 006e5170  83c414               add esp, 0x14
// 006e5173  c21000               ret 0x10
// 006e5176  53                   push ebx
// 006e5177  6a01                 push 1
// 006e5179  57                   push edi
// 006e517a  e8d1e8ffff           call 0x6e3a50
// 006e517f  5d                   pop ebp
// 006e5180  5b                   pop ebx
// 006e5181  8bc7                 mov eax, edi
// 006e5183  5f                   pop edi
// 006e5184  5e                   pop esi
// 006e5185  83c414               add esp, 0x14
// 006e5188  c21000               ret 0x10
// 006e518b  57                   push edi
// 006e518c  8d54241c             lea edx, [esp + 0x1c]
// 006e5190  52                   push edx
// 006e5191  8bce                 mov ecx, esi
// 006e5193  e8d8f3ffff           call 0x6e4570
// 006e5198  8b10                 mov edx, dword ptr [eax]
// 006e519a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e519e  5d                   pop ebp
// 006e519f  5b                   pop ebx
// 006e51a0  8911                 mov dword ptr [ecx], edx
// 006e51a2  8b4004               mov eax, dword ptr [eax + 4]
// 006e51a5  5f                   pop edi
// 006e51a6  894104               mov dword ptr [ecx + 4], eax
// 006e51a9  8bc1                 mov eax, ecx
// 006e51ab  5e                   pop esi
// 006e51ac  83c414               add esp, 0x14
// 006e51af  c21000               ret 0x10
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
