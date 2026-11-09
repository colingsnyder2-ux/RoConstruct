// from server: 100% by auto
// roc 2009-12 00669050  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00669050
//
// 00669050  83ec14               sub esp, 0x14
// 00669053  56                   push esi
// 00669054  8bf1                 mov esi, ecx
// 00669056  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0066905a  57                   push edi
// 0066905b  7521                 jne 0x66907e
// 0066905d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00669061  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00669064  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00669068  50                   push eax
// 00669069  51                   push ecx
// 0066906a  6a01                 push 1
// 0066906c  57                   push edi
// 0066906d  8bce                 mov ecx, esi
// 0066906f  e84ceaffff           call 0x667ac0
// 00669074  8bc7                 mov eax, edi
// 00669076  5f                   pop edi
// 00669077  5e                   pop esi
// 00669078  83c414               add esp, 0x14
// 0066907b  c21000               ret 0x10
// 0066907e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00669082  8b5618               mov edx, dword ptr [esi + 0x18]
// 00669085  8b3a                 mov edi, dword ptr [edx]
// 00669087  8b0e                 mov ecx, dword ptr [esi]
// 00669089  53                   push ebx
// 0066908a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00669090  85c0                 test eax, eax
// 00669092  7404                 je 0x669098
// 00669094  3bc1                 cmp eax, ecx
// 00669096  7406                 je 0x66909e
// 00669098  ffd3                 call ebx
// 0066909a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0066909e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006690a2  55                   push ebp
// 006690a3  3bd7                 cmp edx, edi
// 006690a5  753a                 jne 0x6690e1
// 006690a7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006690ab  83c20c               add edx, 0xc
// 006690ae  52                   push edx
// 006690af  57                   push edi
// 006690b0  ff15d8b59800         call dword ptr [0x98b5d8]
// 006690b6  83c408               add esp, 8
// 006690b9  84c0                 test al, al
// 006690bb  0f849a010000         je 0x66925b
// 006690c1  8b442430             mov eax, dword ptr [esp + 0x30]
// 006690c5  57                   push edi
// 006690c6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006690ca  50                   push eax
// 006690cb  6a01                 push 1
// 006690cd  57                   push edi
// 006690ce  8bce                 mov ecx, esi
// 006690d0  e8ebe9ffff           call 0x667ac0
// 006690d5  5d                   pop ebp
// 006690d6  5b                   pop ebx
// 006690d7  8bc7                 mov eax, edi
// 006690d9  5f                   pop edi
// 006690da  5e                   pop esi
// 006690db  83c414               add esp, 0x14
// 006690de  c21000               ret 0x10
// 006690e1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006690e4  8b0e                 mov ecx, dword ptr [esi]
// 006690e6  85c0                 test eax, eax
// 006690e8  7404                 je 0x6690ee
// 006690ea  3bc1                 cmp eax, ecx
// 006690ec  7406                 je 0x6690f4
// 006690ee  ffd3                 call ebx
// 006690f0  8b542430             mov edx, dword ptr [esp + 0x30]
// 006690f4  3bd7                 cmp edx, edi
// 006690f6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006690fa  753e                 jne 0x66913a
// 006690fc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006690ff  8b4108               mov eax, dword ptr [ecx + 8]
// 00669102  83c00c               add eax, 0xc
// 00669105  57                   push edi
// 00669106  50                   push eax
// 00669107  ff15d8b59800         call dword ptr [0x98b5d8]
// 0066910d  83c408               add esp, 8
// 00669110  84c0                 test al, al
// 00669112  0f8443010000         je 0x66925b
// 00669118  8b5618               mov edx, dword ptr [esi + 0x18]
// 0066911b  8b4208               mov eax, dword ptr [edx + 8]
// 0066911e  57                   push edi
// 0066911f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00669123  50                   push eax
// 00669124  6a00                 push 0
// 00669126  57                   push edi
// 00669127  8bce                 mov ecx, esi
// 00669129  e892e9ffff           call 0x667ac0
// 0066912e  5d                   pop ebp
// 0066912f  5b                   pop ebx
// 00669130  8bc7                 mov eax, edi
// 00669132  5f                   pop edi
// 00669133  5e                   pop esi
// 00669134  83c414               add esp, 0x14
// 00669137  c21000               ret 0x10
// 0066913a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00669140  83c20c               add edx, 0xc
// 00669143  52                   push edx
// 00669144  57                   push edi
// 00669145  ffd5                 call ebp
// 00669147  83c408               add esp, 8
// 0066914a  84c0                 test al, al
// 0066914c  746c                 je 0x6691ba
// 0066914e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00669152  8b542430             mov edx, dword ptr [esp + 0x30]
// 00669156  894c2410             mov dword ptr [esp + 0x10], ecx
// 0066915a  8d4c2410             lea ecx, [esp + 0x10]
// 0066915e  89542414             mov dword ptr [esp + 0x14], edx
// 00669162  e899f70100           call 0x688900
// 00669167  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0066916b  57                   push edi
// 0066916c  8d430c               lea eax, [ebx + 0xc]
// 0066916f  50                   push eax
// 00669170  8d4e08               lea ecx, [esi + 8]
// 00669173  e8d816e1ff           call 0x47a850
// 00669178  84c0                 test al, al
// 0066917a  743e                 je 0x6691ba
// 0066917c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0066917f  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00669183  57                   push edi
// 00669184  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00669188  8bce                 mov ecx, esi
// 0066918a  7415                 je 0x6691a1
// 0066918c  53                   push ebx
// 0066918d  6a00                 push 0
// 0066918f  57                   push edi
// 00669190  e82be9ffff           call 0x667ac0
// 00669195  5d                   pop ebp
// 00669196  5b                   pop ebx
// 00669197  8bc7                 mov eax, edi
// 00669199  5f                   pop edi
// 0066919a  5e                   pop esi
// 0066919b  83c414               add esp, 0x14
// 0066919e  c21000               ret 0x10
// 006691a1  8b542434             mov edx, dword ptr [esp + 0x34]
// 006691a5  52                   push edx
// 006691a6  6a01                 push 1
// 006691a8  57                   push edi
// 006691a9  e812e9ffff           call 0x667ac0
// 006691ae  5d                   pop ebp
// 006691af  5b                   pop ebx
// 006691b0  8bc7                 mov eax, edi
// 006691b2  5f                   pop edi
// 006691b3  5e                   pop esi
// 006691b4  83c414               add esp, 0x14
// 006691b7  c21000               ret 0x10
// 006691ba  8b442430             mov eax, dword ptr [esp + 0x30]
// 006691be  83c00c               add eax, 0xc
// 006691c1  57                   push edi
// 006691c2  50                   push eax
// 006691c3  ffd5                 call ebp
// 006691c5  83c408               add esp, 8
// 006691c8  84c0                 test al, al
// 006691ca  0f848b000000         je 0x66925b
// 006691d0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006691d4  8b542430             mov edx, dword ptr [esp + 0x30]
// 006691d8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006691db  894c2410             mov dword ptr [esp + 0x10], ecx
// 006691df  8b0e                 mov ecx, dword ptr [esi]
// 006691e1  894c2418             mov dword ptr [esp + 0x18], ecx
// 006691e5  8d4c2410             lea ecx, [esp + 0x10]
// 006691e9  89542414             mov dword ptr [esp + 0x14], edx
// 006691ed  8944241c             mov dword ptr [esp + 0x1c], eax
// 006691f1  e82a3ae8ff           call 0x4ecc20
// 006691f6  8d542418             lea edx, [esp + 0x18]
// 006691fa  52                   push edx
// 006691fb  8d4c2414             lea ecx, [esp + 0x14]
// 006691ff  e85c31f6ff           call 0x5cc360
// 00669204  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00669208  84c0                 test al, al
// 0066920a  7511                 jne 0x66921d
// 0066920c  8d430c               lea eax, [ebx + 0xc]
// 0066920f  50                   push eax
// 00669210  57                   push edi
// 00669211  8d4e08               lea ecx, [esi + 8]
// 00669214  e83716e1ff           call 0x47a850
// 00669219  84c0                 test al, al
// 0066921b  743e                 je 0x66925b
// 0066921d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00669221  8b4808               mov ecx, dword ptr [eax + 8]
// 00669224  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00669228  57                   push edi
// 00669229  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0066922d  8bce                 mov ecx, esi
// 0066922f  7415                 je 0x669246
// 00669231  50                   push eax
// 00669232  6a00                 push 0
// 00669234  57                   push edi
// 00669235  e886e8ffff           call 0x667ac0
// 0066923a  5d                   pop ebp
// 0066923b  5b                   pop ebx
// 0066923c  8bc7                 mov eax, edi
// 0066923e  5f                   pop edi
// 0066923f  5e                   pop esi
// 00669240  83c414               add esp, 0x14
// 00669243  c21000               ret 0x10
// 00669246  53                   push ebx
// 00669247  6a01                 push 1
// 00669249  57                   push edi
// 0066924a  e871e8ffff           call 0x667ac0
// 0066924f  5d                   pop ebp
// 00669250  5b                   pop ebx
// 00669251  8bc7                 mov eax, edi
// 00669253  5f                   pop edi
// 00669254  5e                   pop esi
// 00669255  83c414               add esp, 0x14
// 00669258  c21000               ret 0x10
// 0066925b  57                   push edi
// 0066925c  8d54241c             lea edx, [esp + 0x1c]
// 00669260  52                   push edx
// 00669261  8bce                 mov ecx, esi
// 00669263  e858f4ffff           call 0x6686c0
// 00669268  8b10                 mov edx, dword ptr [eax]
// 0066926a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066926e  5d                   pop ebp
// 0066926f  5b                   pop ebx
// 00669270  8911                 mov dword ptr [ecx], edx
// 00669272  8b4004               mov eax, dword ptr [eax + 4]
// 00669275  5f                   pop edi
// 00669276  894104               mov dword ptr [ecx + 4], eax
// 00669279  8bc1                 mov eax, ecx
// 0066927b  5e                   pop esi
// 0066927c  83c414               add esp, 0x14
// 0066927f  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
