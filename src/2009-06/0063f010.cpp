// from server: 100% by auto
// roc 2009-06 0063f010  unit: RBX::Accoutrement  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f010
//
// 0063f010  64a100000000         mov eax, dword ptr fs:[0]
// 0063f016  6aff                 push -1
// 0063f018  68b2db8500           push 0x85dbb2
// 0063f01d  50                   push eax
// 0063f01e  64892500000000       mov dword ptr fs:[0], esp
// 0063f025  8b442418             mov eax, dword ptr [esp + 0x18]
// 0063f029  83ec48               sub esp, 0x48
// 0063f02c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063f030  55                   push ebp
// 0063f031  8be9                 mov ebp, ecx
// 0063f033  7459                 je 0x63f08e
// 0063f035  68a4c98a00           push 0x8ac9a4
// 0063f03a  8d4c240c             lea ecx, [esp + 0xc]
// 0063f03e  ff15b4e48900         call dword ptr [0x89e4b4]
// 0063f044  8d4c2424             lea ecx, [esp + 0x24]
// 0063f048  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0063f050  ff15b8e98900         call dword ptr [0x89e9b8]
// 0063f056  8d442408             lea eax, [esp + 8]
// 0063f05a  50                   push eax
// 0063f05b  8d4c2434             lea ecx, [esp + 0x34]
// 0063f05f  c644245801           mov byte ptr [esp + 0x58], 1
// 0063f064  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 0063f06c  ff15b8e48900         call dword ptr [0x89e4b8]
// 0063f072  68dc919700           push 0x9791dc
// 0063f077  8d4c2428             lea ecx, [esp + 0x28]
// 0063f07b  51                   push ecx
// 0063f07c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0063f081  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 0063f089  e8bca90d00           call 0x719a4a
// 0063f08e  53                   push ebx
// 0063f08f  56                   push esi
// 0063f090  8bd8                 mov ebx, eax
// 0063f092  57                   push edi
// 0063f093  8d4c246c             lea ecx, [esp + 0x6c]
// 0063f097  895c2410             mov dword ptr [esp + 0x10], ebx
// 0063f09b  e870f9ffff           call 0x63ea10
// 0063f0a0  8b0b                 mov ecx, dword ptr [ebx]
// 0063f0a2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0063f0a6  7405                 je 0x63f0ad
// 0063f0a8  8b7b08               mov edi, dword ptr [ebx + 8]
// 0063f0ab  eb1b                 jmp 0x63f0c8
// 0063f0ad  8b5308               mov edx, dword ptr [ebx + 8]
// 0063f0b0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0063f0b4  7404                 je 0x63f0ba
// 0063f0b6  8bf9                 mov edi, ecx
// 0063f0b8  eb0e                 jmp 0x63f0c8
// 0063f0ba  8b442470             mov eax, dword ptr [esp + 0x70]
// 0063f0be  8b7808               mov edi, dword ptr [eax + 8]
// 0063f0c1  8d5008               lea edx, [eax + 8]
// 0063f0c4  3bc3                 cmp eax, ebx
// 0063f0c6  756b                 jne 0x63f133
// 0063f0c8  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0063f0cc  8b7304               mov esi, dword ptr [ebx + 4]
// 0063f0cf  7503                 jne 0x63f0d4
// 0063f0d1  897704               mov dword ptr [edi + 4], esi
// 0063f0d4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0063f0d7  395804               cmp dword ptr [eax + 4], ebx
// 0063f0da  7505                 jne 0x63f0e1
// 0063f0dc  897804               mov dword ptr [eax + 4], edi
// 0063f0df  eb0b                 jmp 0x63f0ec
// 0063f0e1  391e                 cmp dword ptr [esi], ebx
// 0063f0e3  7504                 jne 0x63f0e9
// 0063f0e5  893e                 mov dword ptr [esi], edi
// 0063f0e7  eb03                 jmp 0x63f0ec
// 0063f0e9  897e08               mov dword ptr [esi + 8], edi
// 0063f0ec  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0063f0ef  8b03                 mov eax, dword ptr [ebx]
// 0063f0f1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0063f0f5  7515                 jne 0x63f10c
// 0063f0f7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0063f0fb  7404                 je 0x63f101
// 0063f0fd  8bc6                 mov eax, esi
// 0063f0ff  eb09                 jmp 0x63f10a
// 0063f101  57                   push edi
// 0063f102  e8a941eaff           call 0x4e32b0
// 0063f107  83c404               add esp, 4
// 0063f10a  8903                 mov dword ptr [ebx], eax
// 0063f10c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0063f10f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f113  394b08               cmp dword ptr [ebx + 8], ecx
// 0063f116  7577                 jne 0x63f18f
// 0063f118  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0063f11c  7407                 je 0x63f125
// 0063f11e  8bc6                 mov eax, esi
// 0063f120  894308               mov dword ptr [ebx + 8], eax
// 0063f123  eb6a                 jmp 0x63f18f
// 0063f125  57                   push edi
// 0063f126  e8d5e8e2ff           call 0x46da00
// 0063f12b  83c404               add esp, 4
// 0063f12e  894308               mov dword ptr [ebx + 8], eax
// 0063f131  eb5c                 jmp 0x63f18f
// 0063f133  894104               mov dword ptr [ecx + 4], eax
// 0063f136  8b0b                 mov ecx, dword ptr [ebx]
// 0063f138  8908                 mov dword ptr [eax], ecx
// 0063f13a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0063f13d  7504                 jne 0x63f143
// 0063f13f  8bf0                 mov esi, eax
// 0063f141  eb19                 jmp 0x63f15c
// 0063f143  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0063f147  8b7004               mov esi, dword ptr [eax + 4]
// 0063f14a  7503                 jne 0x63f14f
// 0063f14c  897704               mov dword ptr [edi + 4], esi
// 0063f14f  893e                 mov dword ptr [esi], edi
// 0063f151  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0063f154  890a                 mov dword ptr [edx], ecx
// 0063f156  8b5308               mov edx, dword ptr [ebx + 8]
// 0063f159  894204               mov dword ptr [edx + 4], eax
// 0063f15c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0063f15f  395904               cmp dword ptr [ecx + 4], ebx
// 0063f162  7505                 jne 0x63f169
// 0063f164  894104               mov dword ptr [ecx + 4], eax
// 0063f167  eb0e                 jmp 0x63f177
// 0063f169  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0063f16c  3919                 cmp dword ptr [ecx], ebx
// 0063f16e  7504                 jne 0x63f174
// 0063f170  8901                 mov dword ptr [ecx], eax
// 0063f172  eb03                 jmp 0x63f177
// 0063f174  894108               mov dword ptr [ecx + 8], eax
// 0063f177  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0063f17a  894804               mov dword ptr [eax + 4], ecx
// 0063f17d  8d4b2c               lea ecx, [ebx + 0x2c]
// 0063f180  83c02c               add eax, 0x2c
// 0063f183  3bc1                 cmp eax, ecx
// 0063f185  7408                 je 0x63f18f
// 0063f187  8a19                 mov bl, byte ptr [ecx]
// 0063f189  8a10                 mov dl, byte ptr [eax]
// 0063f18b  8818                 mov byte ptr [eax], bl
// 0063f18d  8811                 mov byte ptr [ecx], dl
// 0063f18f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0063f193  b301                 mov bl, 1
// 0063f195  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0063f198  0f85fd000000         jne 0x63f29b
// 0063f19e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0063f1a1  3b7804               cmp edi, dword ptr [eax + 4]
// 0063f1a4  0f84ee000000         je 0x63f298
// 0063f1aa  8d9b00000000         lea ebx, [ebx]
// 0063f1b0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 0063f1b3  0f85df000000         jne 0x63f298
// 0063f1b9  8b06                 mov eax, dword ptr [esi]
// 0063f1bb  3bf8                 cmp edi, eax
// 0063f1bd  7565                 jne 0x63f224
// 0063f1bf  8b4608               mov eax, dword ptr [esi + 8]
// 0063f1c2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0063f1c6  7512                 jne 0x63f1da
// 0063f1c8  88582c               mov byte ptr [eax + 0x2c], bl
// 0063f1cb  56                   push esi
// 0063f1cc  8bcd                 mov ecx, ebp
// 0063f1ce  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0063f1d2  e8a9f8ffff           call 0x63ea80
// 0063f1d7  8b4608               mov eax, dword ptr [esi + 8]
// 0063f1da  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063f1de  7574                 jne 0x63f254
// 0063f1e0  8b08                 mov ecx, dword ptr [eax]
// 0063f1e2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0063f1e5  7508                 jne 0x63f1ef
// 0063f1e7  8b5008               mov edx, dword ptr [eax + 8]
// 0063f1ea  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0063f1ed  7461                 je 0x63f250
// 0063f1ef  8b4808               mov ecx, dword ptr [eax + 8]
// 0063f1f2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0063f1f5  7514                 jne 0x63f20b
// 0063f1f7  8b10                 mov edx, dword ptr [eax]
// 0063f1f9  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063f1fc  50                   push eax
// 0063f1fd  8bcd                 mov ecx, ebp
// 0063f1ff  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0063f203  e8f8d7e9ff           call 0x4dca00
// 0063f208  8b4608               mov eax, dword ptr [esi + 8]
// 0063f20b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0063f20e  88482c               mov byte ptr [eax + 0x2c], cl
// 0063f211  885e2c               mov byte ptr [esi + 0x2c], bl
// 0063f214  8b5008               mov edx, dword ptr [eax + 8]
// 0063f217  56                   push esi
// 0063f218  8bcd                 mov ecx, ebp
// 0063f21a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063f21d  e85ef8ffff           call 0x63ea80
// 0063f222  eb74                 jmp 0x63f298
// 0063f224  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0063f228  7511                 jne 0x63f23b
// 0063f22a  88582c               mov byte ptr [eax + 0x2c], bl
// 0063f22d  56                   push esi
// 0063f22e  8bcd                 mov ecx, ebp
// 0063f230  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0063f234  e8c7d7e9ff           call 0x4dca00
// 0063f239  8b06                 mov eax, dword ptr [esi]
// 0063f23b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063f23f  7513                 jne 0x63f254
// 0063f241  8b4808               mov ecx, dword ptr [eax + 8]
// 0063f244  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0063f247  751e                 jne 0x63f267
// 0063f249  8b10                 mov edx, dword ptr [eax]
// 0063f24b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0063f24e  7517                 jne 0x63f267
// 0063f250  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0063f254  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0063f257  8bfe                 mov edi, esi
// 0063f259  8b7604               mov esi, dword ptr [esi + 4]
// 0063f25c  3b7804               cmp edi, dword ptr [eax + 4]
// 0063f25f  0f854bffffff         jne 0x63f1b0
// 0063f265  eb31                 jmp 0x63f298
// 0063f267  8b08                 mov ecx, dword ptr [eax]
// 0063f269  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0063f26c  7514                 jne 0x63f282
// 0063f26e  8b5008               mov edx, dword ptr [eax + 8]
// 0063f271  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063f274  50                   push eax
// 0063f275  8bcd                 mov ecx, ebp
// 0063f277  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0063f27b  e800f8ffff           call 0x63ea80
// 0063f280  8b06                 mov eax, dword ptr [esi]
// 0063f282  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0063f285  88482c               mov byte ptr [eax + 0x2c], cl
// 0063f288  885e2c               mov byte ptr [esi + 0x2c], bl
// 0063f28b  8b10                 mov edx, dword ptr [eax]
// 0063f28d  56                   push esi
// 0063f28e  8bcd                 mov ecx, ebp
// 0063f290  885a2c               mov byte ptr [edx + 0x2c], bl
// 0063f293  e868d7e9ff           call 0x4dca00
// 0063f298  885f2c               mov byte ptr [edi + 0x2c], bl
// 0063f29b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f29f  83c110               add ecx, 0x10
// 0063f2a2  ff15c4e48900         call dword ptr [0x89e4c4]
// 0063f2a8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0063f2ac  50                   push eax
// 0063f2ad  e880970d00           call 0x718a32
// 0063f2b2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0063f2b5  83c404               add esp, 4
// 0063f2b8  5f                   pop edi
// 0063f2b9  5e                   pop esi
// 0063f2ba  5b                   pop ebx
// 0063f2bb  85c0                 test eax, eax
// 0063f2bd  7604                 jbe 0x63f2c3
// 0063f2bf  48                   dec eax
// 0063f2c0  89451c               mov dword ptr [ebp + 0x1c], eax
// 0063f2c3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0063f2c7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0063f2cb  8b5500               mov edx, dword ptr [ebp]
// 0063f2ce  894804               mov dword ptr [eax + 4], ecx
// 0063f2d1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0063f2d5  8910                 mov dword ptr [eax], edx
// 0063f2d7  5d                   pop ebp
// 0063f2d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0063f2df  83c454               add esp, 0x54
// 0063f2e2  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
