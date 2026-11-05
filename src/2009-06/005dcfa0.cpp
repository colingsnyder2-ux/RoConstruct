// from server: 100% by auto
// roc 2009-06 005dcfa0  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dcfa0
//
// 005dcfa0  83ec14               sub esp, 0x14
// 005dcfa3  56                   push esi
// 005dcfa4  8bf1                 mov esi, ecx
// 005dcfa6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005dcfaa  57                   push edi
// 005dcfab  7521                 jne 0x5dcfce
// 005dcfad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005dcfb1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005dcfb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dcfb8  50                   push eax
// 005dcfb9  51                   push ecx
// 005dcfba  6a01                 push 1
// 005dcfbc  57                   push edi
// 005dcfbd  8bce                 mov ecx, esi
// 005dcfbf  e81ce8ffff           call 0x5db7e0
// 005dcfc4  8bc7                 mov eax, edi
// 005dcfc6  5f                   pop edi
// 005dcfc7  5e                   pop esi
// 005dcfc8  83c414               add esp, 0x14
// 005dcfcb  c21000               ret 0x10
// 005dcfce  8b442424             mov eax, dword ptr [esp + 0x24]
// 005dcfd2  8b5618               mov edx, dword ptr [esi + 0x18]
// 005dcfd5  8b3a                 mov edi, dword ptr [edx]
// 005dcfd7  8b0e                 mov ecx, dword ptr [esi]
// 005dcfd9  53                   push ebx
// 005dcfda  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 005dcfe0  85c0                 test eax, eax
// 005dcfe2  7404                 je 0x5dcfe8
// 005dcfe4  3bc1                 cmp eax, ecx
// 005dcfe6  7406                 je 0x5dcfee
// 005dcfe8  ffd3                 call ebx
// 005dcfea  8b442428             mov eax, dword ptr [esp + 0x28]
// 005dcfee  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005dcff2  55                   push ebp
// 005dcff3  3bd7                 cmp edx, edi
// 005dcff5  753a                 jne 0x5dd031
// 005dcff7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005dcffb  83c20c               add edx, 0xc
// 005dcffe  52                   push edx
// 005dcfff  57                   push edi
// 005dd000  ff15e0e48900         call dword ptr [0x89e4e0]
// 005dd006  83c408               add esp, 8
// 005dd009  84c0                 test al, al
// 005dd00b  0f849a010000         je 0x5dd1ab
// 005dd011  8b442430             mov eax, dword ptr [esp + 0x30]
// 005dd015  57                   push edi
// 005dd016  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005dd01a  50                   push eax
// 005dd01b  6a01                 push 1
// 005dd01d  57                   push edi
// 005dd01e  8bce                 mov ecx, esi
// 005dd020  e8bbe7ffff           call 0x5db7e0
// 005dd025  5d                   pop ebp
// 005dd026  5b                   pop ebx
// 005dd027  8bc7                 mov eax, edi
// 005dd029  5f                   pop edi
// 005dd02a  5e                   pop esi
// 005dd02b  83c414               add esp, 0x14
// 005dd02e  c21000               ret 0x10
// 005dd031  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005dd034  8b0e                 mov ecx, dword ptr [esi]
// 005dd036  85c0                 test eax, eax
// 005dd038  7404                 je 0x5dd03e
// 005dd03a  3bc1                 cmp eax, ecx
// 005dd03c  7406                 je 0x5dd044
// 005dd03e  ffd3                 call ebx
// 005dd040  8b542430             mov edx, dword ptr [esp + 0x30]
// 005dd044  3bd7                 cmp edx, edi
// 005dd046  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005dd04a  753e                 jne 0x5dd08a
// 005dd04c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005dd04f  8b4108               mov eax, dword ptr [ecx + 8]
// 005dd052  83c00c               add eax, 0xc
// 005dd055  57                   push edi
// 005dd056  50                   push eax
// 005dd057  ff15e0e48900         call dword ptr [0x89e4e0]
// 005dd05d  83c408               add esp, 8
// 005dd060  84c0                 test al, al
// 005dd062  0f8443010000         je 0x5dd1ab
// 005dd068  8b5618               mov edx, dword ptr [esi + 0x18]
// 005dd06b  8b4208               mov eax, dword ptr [edx + 8]
// 005dd06e  57                   push edi
// 005dd06f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005dd073  50                   push eax
// 005dd074  6a00                 push 0
// 005dd076  57                   push edi
// 005dd077  8bce                 mov ecx, esi
// 005dd079  e862e7ffff           call 0x5db7e0
// 005dd07e  5d                   pop ebp
// 005dd07f  5b                   pop ebx
// 005dd080  8bc7                 mov eax, edi
// 005dd082  5f                   pop edi
// 005dd083  5e                   pop esi
// 005dd084  83c414               add esp, 0x14
// 005dd087  c21000               ret 0x10
// 005dd08a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 005dd090  83c20c               add edx, 0xc
// 005dd093  52                   push edx
// 005dd094  57                   push edi
// 005dd095  ffd5                 call ebp
// 005dd097  83c408               add esp, 8
// 005dd09a  84c0                 test al, al
// 005dd09c  746c                 je 0x5dd10a
// 005dd09e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005dd0a2  8b542430             mov edx, dword ptr [esp + 0x30]
// 005dd0a6  894c2410             mov dword ptr [esp + 0x10], ecx
// 005dd0aa  8d4c2410             lea ecx, [esp + 0x10]
// 005dd0ae  89542414             mov dword ptr [esp + 0x14], edx
// 005dd0b2  e8e9bfffff           call 0x5d90a0
// 005dd0b7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005dd0bb  57                   push edi
// 005dd0bc  8d430c               lea eax, [ebx + 0xc]
// 005dd0bf  50                   push eax
// 005dd0c0  8d4e08               lea ecx, [esi + 8]
// 005dd0c3  e848bfffff           call 0x5d9010
// 005dd0c8  84c0                 test al, al
// 005dd0ca  743e                 je 0x5dd10a
// 005dd0cc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005dd0cf  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005dd0d3  57                   push edi
// 005dd0d4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005dd0d8  8bce                 mov ecx, esi
// 005dd0da  7415                 je 0x5dd0f1
// 005dd0dc  53                   push ebx
// 005dd0dd  6a00                 push 0
// 005dd0df  57                   push edi
// 005dd0e0  e8fbe6ffff           call 0x5db7e0
// 005dd0e5  5d                   pop ebp
// 005dd0e6  5b                   pop ebx
// 005dd0e7  8bc7                 mov eax, edi
// 005dd0e9  5f                   pop edi
// 005dd0ea  5e                   pop esi
// 005dd0eb  83c414               add esp, 0x14
// 005dd0ee  c21000               ret 0x10
// 005dd0f1  8b542434             mov edx, dword ptr [esp + 0x34]
// 005dd0f5  52                   push edx
// 005dd0f6  6a01                 push 1
// 005dd0f8  57                   push edi
// 005dd0f9  e8e2e6ffff           call 0x5db7e0
// 005dd0fe  5d                   pop ebp
// 005dd0ff  5b                   pop ebx
// 005dd100  8bc7                 mov eax, edi
// 005dd102  5f                   pop edi
// 005dd103  5e                   pop esi
// 005dd104  83c414               add esp, 0x14
// 005dd107  c21000               ret 0x10
// 005dd10a  8b442430             mov eax, dword ptr [esp + 0x30]
// 005dd10e  83c00c               add eax, 0xc
// 005dd111  57                   push edi
// 005dd112  50                   push eax
// 005dd113  ffd5                 call ebp
// 005dd115  83c408               add esp, 8
// 005dd118  84c0                 test al, al
// 005dd11a  0f848b000000         je 0x5dd1ab
// 005dd120  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005dd124  8b542430             mov edx, dword ptr [esp + 0x30]
// 005dd128  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd12b  894c2410             mov dword ptr [esp + 0x10], ecx
// 005dd12f  8b0e                 mov ecx, dword ptr [esi]
// 005dd131  894c2418             mov dword ptr [esp + 0x18], ecx
// 005dd135  8d4c2410             lea ecx, [esp + 0x10]
// 005dd139  89542414             mov dword ptr [esp + 0x14], edx
// 005dd13d  8944241c             mov dword ptr [esp + 0x1c], eax
// 005dd141  e8eabeffff           call 0x5d9030
// 005dd146  8d542418             lea edx, [esp + 0x18]
// 005dd14a  52                   push edx
// 005dd14b  8d4c2414             lea ecx, [esp + 0x14]
// 005dd14f  e84c630600           call 0x6434a0
// 005dd154  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005dd158  84c0                 test al, al
// 005dd15a  7511                 jne 0x5dd16d
// 005dd15c  8d430c               lea eax, [ebx + 0xc]
// 005dd15f  50                   push eax
// 005dd160  57                   push edi
// 005dd161  8d4e08               lea ecx, [esi + 8]
// 005dd164  e8a7beffff           call 0x5d9010
// 005dd169  84c0                 test al, al
// 005dd16b  743e                 je 0x5dd1ab
// 005dd16d  8b442430             mov eax, dword ptr [esp + 0x30]
// 005dd171  8b4808               mov ecx, dword ptr [eax + 8]
// 005dd174  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005dd178  57                   push edi
// 005dd179  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005dd17d  8bce                 mov ecx, esi
// 005dd17f  7415                 je 0x5dd196
// 005dd181  50                   push eax
// 005dd182  6a00                 push 0
// 005dd184  57                   push edi
// 005dd185  e856e6ffff           call 0x5db7e0
// 005dd18a  5d                   pop ebp
// 005dd18b  5b                   pop ebx
// 005dd18c  8bc7                 mov eax, edi
// 005dd18e  5f                   pop edi
// 005dd18f  5e                   pop esi
// 005dd190  83c414               add esp, 0x14
// 005dd193  c21000               ret 0x10
// 005dd196  53                   push ebx
// 005dd197  6a01                 push 1
// 005dd199  57                   push edi
// 005dd19a  e841e6ffff           call 0x5db7e0
// 005dd19f  5d                   pop ebp
// 005dd1a0  5b                   pop ebx
// 005dd1a1  8bc7                 mov eax, edi
// 005dd1a3  5f                   pop edi
// 005dd1a4  5e                   pop esi
// 005dd1a5  83c414               add esp, 0x14
// 005dd1a8  c21000               ret 0x10
// 005dd1ab  57                   push edi
// 005dd1ac  8d54241c             lea edx, [esp + 0x1c]
// 005dd1b0  52                   push edx
// 005dd1b1  8bce                 mov ecx, esi
// 005dd1b3  e868f2ffff           call 0x5dc420
// 005dd1b8  8b10                 mov edx, dword ptr [eax]
// 005dd1ba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005dd1be  5d                   pop ebp
// 005dd1bf  5b                   pop ebx
// 005dd1c0  8911                 mov dword ptr [ecx], edx
// 005dd1c2  8b4004               mov eax, dword ptr [eax + 4]
// 005dd1c5  5f                   pop edi
// 005dd1c6  894104               mov dword ptr [ecx + 4], eax
// 005dd1c9  8bc1                 mov eax, ecx
// 005dd1cb  5e                   pop esi
// 005dd1cc  83c414               add esp, 0x14
// 005dd1cf  c21000               ret 0x10
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
