// from server: 100% by auto
// roc 2009-06 006fdfe0  unit: RBX::AdornRbxGfx  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fdfe0
//
// 006fdfe0  83ec14               sub esp, 0x14
// 006fdfe3  56                   push esi
// 006fdfe4  8bf1                 mov esi, ecx
// 006fdfe6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006fdfea  57                   push edi
// 006fdfeb  7521                 jne 0x6fe00e
// 006fdfed  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006fdff1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006fdff4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fdff8  50                   push eax
// 006fdff9  51                   push ecx
// 006fdffa  6a01                 push 1
// 006fdffc  57                   push edi
// 006fdffd  8bce                 mov ecx, esi
// 006fdfff  e84cf5ffff           call 0x6fd550
// 006fe004  8bc7                 mov eax, edi
// 006fe006  5f                   pop edi
// 006fe007  5e                   pop esi
// 006fe008  83c414               add esp, 0x14
// 006fe00b  c21000               ret 0x10
// 006fe00e  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fe012  8b5618               mov edx, dword ptr [esi + 0x18]
// 006fe015  8b3a                 mov edi, dword ptr [edx]
// 006fe017  8b0e                 mov ecx, dword ptr [esi]
// 006fe019  53                   push ebx
// 006fe01a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006fe020  85c0                 test eax, eax
// 006fe022  7404                 je 0x6fe028
// 006fe024  3bc1                 cmp eax, ecx
// 006fe026  7406                 je 0x6fe02e
// 006fe028  ffd3                 call ebx
// 006fe02a  8b442428             mov eax, dword ptr [esp + 0x28]
// 006fe02e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006fe032  55                   push ebp
// 006fe033  3bd7                 cmp edx, edi
// 006fe035  753a                 jne 0x6fe071
// 006fe037  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006fe03b  83c20c               add edx, 0xc
// 006fe03e  52                   push edx
// 006fe03f  57                   push edi
// 006fe040  ff15e0e48900         call dword ptr [0x89e4e0]
// 006fe046  83c408               add esp, 8
// 006fe049  84c0                 test al, al
// 006fe04b  0f849a010000         je 0x6fe1eb
// 006fe051  8b442430             mov eax, dword ptr [esp + 0x30]
// 006fe055  57                   push edi
// 006fe056  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fe05a  50                   push eax
// 006fe05b  6a01                 push 1
// 006fe05d  57                   push edi
// 006fe05e  8bce                 mov ecx, esi
// 006fe060  e8ebf4ffff           call 0x6fd550
// 006fe065  5d                   pop ebp
// 006fe066  5b                   pop ebx
// 006fe067  8bc7                 mov eax, edi
// 006fe069  5f                   pop edi
// 006fe06a  5e                   pop esi
// 006fe06b  83c414               add esp, 0x14
// 006fe06e  c21000               ret 0x10
// 006fe071  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006fe074  8b0e                 mov ecx, dword ptr [esi]
// 006fe076  85c0                 test eax, eax
// 006fe078  7404                 je 0x6fe07e
// 006fe07a  3bc1                 cmp eax, ecx
// 006fe07c  7406                 je 0x6fe084
// 006fe07e  ffd3                 call ebx
// 006fe080  8b542430             mov edx, dword ptr [esp + 0x30]
// 006fe084  3bd7                 cmp edx, edi
// 006fe086  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006fe08a  753e                 jne 0x6fe0ca
// 006fe08c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006fe08f  8b4108               mov eax, dword ptr [ecx + 8]
// 006fe092  83c00c               add eax, 0xc
// 006fe095  57                   push edi
// 006fe096  50                   push eax
// 006fe097  ff15e0e48900         call dword ptr [0x89e4e0]
// 006fe09d  83c408               add esp, 8
// 006fe0a0  84c0                 test al, al
// 006fe0a2  0f8443010000         je 0x6fe1eb
// 006fe0a8  8b5618               mov edx, dword ptr [esi + 0x18]
// 006fe0ab  8b4208               mov eax, dword ptr [edx + 8]
// 006fe0ae  57                   push edi
// 006fe0af  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fe0b3  50                   push eax
// 006fe0b4  6a00                 push 0
// 006fe0b6  57                   push edi
// 006fe0b7  8bce                 mov ecx, esi
// 006fe0b9  e892f4ffff           call 0x6fd550
// 006fe0be  5d                   pop ebp
// 006fe0bf  5b                   pop ebx
// 006fe0c0  8bc7                 mov eax, edi
// 006fe0c2  5f                   pop edi
// 006fe0c3  5e                   pop esi
// 006fe0c4  83c414               add esp, 0x14
// 006fe0c7  c21000               ret 0x10
// 006fe0ca  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 006fe0d0  83c20c               add edx, 0xc
// 006fe0d3  52                   push edx
// 006fe0d4  57                   push edi
// 006fe0d5  ffd5                 call ebp
// 006fe0d7  83c408               add esp, 8
// 006fe0da  84c0                 test al, al
// 006fe0dc  746c                 je 0x6fe14a
// 006fe0de  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006fe0e2  8b542430             mov edx, dword ptr [esp + 0x30]
// 006fe0e6  894c2410             mov dword ptr [esp + 0x10], ecx
// 006fe0ea  8d4c2410             lea ecx, [esp + 0x10]
// 006fe0ee  89542414             mov dword ptr [esp + 0x14], edx
// 006fe0f2  e899eaffff           call 0x6fcb90
// 006fe0f7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006fe0fb  57                   push edi
// 006fe0fc  8d430c               lea eax, [ebx + 0xc]
// 006fe0ff  50                   push eax
// 006fe100  8d4e08               lea ecx, [esi + 8]
// 006fe103  e808afedff           call 0x5d9010
// 006fe108  84c0                 test al, al
// 006fe10a  743e                 je 0x6fe14a
// 006fe10c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006fe10f  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fe113  57                   push edi
// 006fe114  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fe118  8bce                 mov ecx, esi
// 006fe11a  7415                 je 0x6fe131
// 006fe11c  53                   push ebx
// 006fe11d  6a00                 push 0
// 006fe11f  57                   push edi
// 006fe120  e82bf4ffff           call 0x6fd550
// 006fe125  5d                   pop ebp
// 006fe126  5b                   pop ebx
// 006fe127  8bc7                 mov eax, edi
// 006fe129  5f                   pop edi
// 006fe12a  5e                   pop esi
// 006fe12b  83c414               add esp, 0x14
// 006fe12e  c21000               ret 0x10
// 006fe131  8b542434             mov edx, dword ptr [esp + 0x34]
// 006fe135  52                   push edx
// 006fe136  6a01                 push 1
// 006fe138  57                   push edi
// 006fe139  e812f4ffff           call 0x6fd550
// 006fe13e  5d                   pop ebp
// 006fe13f  5b                   pop ebx
// 006fe140  8bc7                 mov eax, edi
// 006fe142  5f                   pop edi
// 006fe143  5e                   pop esi
// 006fe144  83c414               add esp, 0x14
// 006fe147  c21000               ret 0x10
// 006fe14a  8b442430             mov eax, dword ptr [esp + 0x30]
// 006fe14e  83c00c               add eax, 0xc
// 006fe151  57                   push edi
// 006fe152  50                   push eax
// 006fe153  ffd5                 call ebp
// 006fe155  83c408               add esp, 8
// 006fe158  84c0                 test al, al
// 006fe15a  0f848b000000         je 0x6fe1eb
// 006fe160  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006fe164  8b542430             mov edx, dword ptr [esp + 0x30]
// 006fe168  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe16b  894c2410             mov dword ptr [esp + 0x10], ecx
// 006fe16f  8b0e                 mov ecx, dword ptr [esi]
// 006fe171  894c2418             mov dword ptr [esp + 0x18], ecx
// 006fe175  8d4c2410             lea ecx, [esp + 0x10]
// 006fe179  89542414             mov dword ptr [esp + 0x14], edx
// 006fe17d  8944241c             mov dword ptr [esp + 0x1c], eax
// 006fe181  e89aeaffff           call 0x6fcc20
// 006fe186  8d542418             lea edx, [esp + 0x18]
// 006fe18a  52                   push edx
// 006fe18b  8d4c2414             lea ecx, [esp + 0x14]
// 006fe18f  e80c53f4ff           call 0x6434a0
// 006fe194  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006fe198  84c0                 test al, al
// 006fe19a  7511                 jne 0x6fe1ad
// 006fe19c  8d430c               lea eax, [ebx + 0xc]
// 006fe19f  50                   push eax
// 006fe1a0  57                   push edi
// 006fe1a1  8d4e08               lea ecx, [esi + 8]
// 006fe1a4  e867aeedff           call 0x5d9010
// 006fe1a9  84c0                 test al, al
// 006fe1ab  743e                 je 0x6fe1eb
// 006fe1ad  8b442430             mov eax, dword ptr [esp + 0x30]
// 006fe1b1  8b4808               mov ecx, dword ptr [eax + 8]
// 006fe1b4  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fe1b8  57                   push edi
// 006fe1b9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fe1bd  8bce                 mov ecx, esi
// 006fe1bf  7415                 je 0x6fe1d6
// 006fe1c1  50                   push eax
// 006fe1c2  6a00                 push 0
// 006fe1c4  57                   push edi
// 006fe1c5  e886f3ffff           call 0x6fd550
// 006fe1ca  5d                   pop ebp
// 006fe1cb  5b                   pop ebx
// 006fe1cc  8bc7                 mov eax, edi
// 006fe1ce  5f                   pop edi
// 006fe1cf  5e                   pop esi
// 006fe1d0  83c414               add esp, 0x14
// 006fe1d3  c21000               ret 0x10
// 006fe1d6  53                   push ebx
// 006fe1d7  6a01                 push 1
// 006fe1d9  57                   push edi
// 006fe1da  e871f3ffff           call 0x6fd550
// 006fe1df  5d                   pop ebp
// 006fe1e0  5b                   pop ebx
// 006fe1e1  8bc7                 mov eax, edi
// 006fe1e3  5f                   pop edi
// 006fe1e4  5e                   pop esi
// 006fe1e5  83c414               add esp, 0x14
// 006fe1e8  c21000               ret 0x10
// 006fe1eb  57                   push edi
// 006fe1ec  8d54241c             lea edx, [esp + 0x1c]
// 006fe1f0  52                   push edx
// 006fe1f1  8bce                 mov ecx, esi
// 006fe1f3  e8f8fcffff           call 0x6fdef0
// 006fe1f8  8b10                 mov edx, dword ptr [eax]
// 006fe1fa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006fe1fe  5d                   pop ebp
// 006fe1ff  5b                   pop ebx
// 006fe200  8911                 mov dword ptr [ecx], edx
// 006fe202  8b4004               mov eax, dword ptr [eax + 4]
// 006fe205  5f                   pop edi
// 006fe206  894104               mov dword ptr [ecx + 4], eax
// 006fe209  8bc1                 mov eax, ecx
// 006fe20b  5e                   pop esi
// 006fe20c  83c414               add esp, 0x14
// 006fe20f  c21000               ret 0x10
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
