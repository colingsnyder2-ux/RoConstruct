// from server: 100% by auto
// roc 2009-06 005cd080  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005cd080
//
// 005cd080  64a100000000         mov eax, dword ptr fs:[0]
// 005cd086  6aff                 push -1
// 005cd088  68b2db8500           push 0x85dbb2
// 005cd08d  50                   push eax
// 005cd08e  64892500000000       mov dword ptr fs:[0], esp
// 005cd095  8b442418             mov eax, dword ptr [esp + 0x18]
// 005cd099  83ec48               sub esp, 0x48
// 005cd09c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005cd0a0  55                   push ebp
// 005cd0a1  8be9                 mov ebp, ecx
// 005cd0a3  7459                 je 0x5cd0fe
// 005cd0a5  68a4c98a00           push 0x8ac9a4
// 005cd0aa  8d4c240c             lea ecx, [esp + 0xc]
// 005cd0ae  ff15b4e48900         call dword ptr [0x89e4b4]
// 005cd0b4  8d4c2424             lea ecx, [esp + 0x24]
// 005cd0b8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005cd0c0  ff15b8e98900         call dword ptr [0x89e9b8]
// 005cd0c6  8d442408             lea eax, [esp + 8]
// 005cd0ca  50                   push eax
// 005cd0cb  8d4c2434             lea ecx, [esp + 0x34]
// 005cd0cf  c644245801           mov byte ptr [esp + 0x58], 1
// 005cd0d4  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 005cd0dc  ff15b8e48900         call dword ptr [0x89e4b8]
// 005cd0e2  68dc919700           push 0x9791dc
// 005cd0e7  8d4c2428             lea ecx, [esp + 0x28]
// 005cd0eb  51                   push ecx
// 005cd0ec  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005cd0f1  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 005cd0f9  e84cc91400           call 0x719a4a
// 005cd0fe  53                   push ebx
// 005cd0ff  56                   push esi
// 005cd100  8bd8                 mov ebx, eax
// 005cd102  57                   push edi
// 005cd103  8d4c246c             lea ecx, [esp + 0x6c]
// 005cd107  895c2410             mov dword ptr [esp + 0x10], ebx
// 005cd10b  e800190700           call 0x63ea10
// 005cd110  8b0b                 mov ecx, dword ptr [ebx]
// 005cd112  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005cd116  7405                 je 0x5cd11d
// 005cd118  8b7b08               mov edi, dword ptr [ebx + 8]
// 005cd11b  eb1b                 jmp 0x5cd138
// 005cd11d  8b5308               mov edx, dword ptr [ebx + 8]
// 005cd120  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005cd124  7404                 je 0x5cd12a
// 005cd126  8bf9                 mov edi, ecx
// 005cd128  eb0e                 jmp 0x5cd138
// 005cd12a  8b442470             mov eax, dword ptr [esp + 0x70]
// 005cd12e  8b7808               mov edi, dword ptr [eax + 8]
// 005cd131  8d5008               lea edx, [eax + 8]
// 005cd134  3bc3                 cmp eax, ebx
// 005cd136  756b                 jne 0x5cd1a3
// 005cd138  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cd13c  8b7304               mov esi, dword ptr [ebx + 4]
// 005cd13f  7503                 jne 0x5cd144
// 005cd141  897704               mov dword ptr [edi + 4], esi
// 005cd144  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005cd147  395804               cmp dword ptr [eax + 4], ebx
// 005cd14a  7505                 jne 0x5cd151
// 005cd14c  897804               mov dword ptr [eax + 4], edi
// 005cd14f  eb0b                 jmp 0x5cd15c
// 005cd151  391e                 cmp dword ptr [esi], ebx
// 005cd153  7504                 jne 0x5cd159
// 005cd155  893e                 mov dword ptr [esi], edi
// 005cd157  eb03                 jmp 0x5cd15c
// 005cd159  897e08               mov dword ptr [esi + 8], edi
// 005cd15c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005cd15f  8b03                 mov eax, dword ptr [ebx]
// 005cd161  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005cd165  7515                 jne 0x5cd17c
// 005cd167  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cd16b  7404                 je 0x5cd171
// 005cd16d  8bc6                 mov eax, esi
// 005cd16f  eb09                 jmp 0x5cd17a
// 005cd171  57                   push edi
// 005cd172  e83961f1ff           call 0x4e32b0
// 005cd177  83c404               add esp, 4
// 005cd17a  8903                 mov dword ptr [ebx], eax
// 005cd17c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005cd17f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005cd183  394b08               cmp dword ptr [ebx + 8], ecx
// 005cd186  7577                 jne 0x5cd1ff
// 005cd188  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cd18c  7407                 je 0x5cd195
// 005cd18e  8bc6                 mov eax, esi
// 005cd190  894308               mov dword ptr [ebx + 8], eax
// 005cd193  eb6a                 jmp 0x5cd1ff
// 005cd195  57                   push edi
// 005cd196  e86508eaff           call 0x46da00
// 005cd19b  83c404               add esp, 4
// 005cd19e  894308               mov dword ptr [ebx + 8], eax
// 005cd1a1  eb5c                 jmp 0x5cd1ff
// 005cd1a3  894104               mov dword ptr [ecx + 4], eax
// 005cd1a6  8b0b                 mov ecx, dword ptr [ebx]
// 005cd1a8  8908                 mov dword ptr [eax], ecx
// 005cd1aa  3b4308               cmp eax, dword ptr [ebx + 8]
// 005cd1ad  7504                 jne 0x5cd1b3
// 005cd1af  8bf0                 mov esi, eax
// 005cd1b1  eb19                 jmp 0x5cd1cc
// 005cd1b3  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cd1b7  8b7004               mov esi, dword ptr [eax + 4]
// 005cd1ba  7503                 jne 0x5cd1bf
// 005cd1bc  897704               mov dword ptr [edi + 4], esi
// 005cd1bf  893e                 mov dword ptr [esi], edi
// 005cd1c1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005cd1c4  890a                 mov dword ptr [edx], ecx
// 005cd1c6  8b5308               mov edx, dword ptr [ebx + 8]
// 005cd1c9  894204               mov dword ptr [edx + 4], eax
// 005cd1cc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005cd1cf  395904               cmp dword ptr [ecx + 4], ebx
// 005cd1d2  7505                 jne 0x5cd1d9
// 005cd1d4  894104               mov dword ptr [ecx + 4], eax
// 005cd1d7  eb0e                 jmp 0x5cd1e7
// 005cd1d9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005cd1dc  3919                 cmp dword ptr [ecx], ebx
// 005cd1de  7504                 jne 0x5cd1e4
// 005cd1e0  8901                 mov dword ptr [ecx], eax
// 005cd1e2  eb03                 jmp 0x5cd1e7
// 005cd1e4  894108               mov dword ptr [ecx + 8], eax
// 005cd1e7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005cd1ea  894804               mov dword ptr [eax + 4], ecx
// 005cd1ed  8d4b2c               lea ecx, [ebx + 0x2c]
// 005cd1f0  83c02c               add eax, 0x2c
// 005cd1f3  3bc1                 cmp eax, ecx
// 005cd1f5  7408                 je 0x5cd1ff
// 005cd1f7  8a19                 mov bl, byte ptr [ecx]
// 005cd1f9  8a10                 mov dl, byte ptr [eax]
// 005cd1fb  8818                 mov byte ptr [eax], bl
// 005cd1fd  8811                 mov byte ptr [ecx], dl
// 005cd1ff  8b542410             mov edx, dword ptr [esp + 0x10]
// 005cd203  b301                 mov bl, 1
// 005cd205  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005cd208  0f85fd000000         jne 0x5cd30b
// 005cd20e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005cd211  3b7804               cmp edi, dword ptr [eax + 4]
// 005cd214  0f84ee000000         je 0x5cd308
// 005cd21a  8d9b00000000         lea ebx, [ebx]
// 005cd220  385f2c               cmp byte ptr [edi + 0x2c], bl
// 005cd223  0f85df000000         jne 0x5cd308
// 005cd229  8b06                 mov eax, dword ptr [esi]
// 005cd22b  3bf8                 cmp edi, eax
// 005cd22d  7565                 jne 0x5cd294
// 005cd22f  8b4608               mov eax, dword ptr [esi + 8]
// 005cd232  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005cd236  7512                 jne 0x5cd24a
// 005cd238  88582c               mov byte ptr [eax + 0x2c], bl
// 005cd23b  56                   push esi
// 005cd23c  8bcd                 mov ecx, ebp
// 005cd23e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005cd242  e839180700           call 0x63ea80
// 005cd247  8b4608               mov eax, dword ptr [esi + 8]
// 005cd24a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005cd24e  7574                 jne 0x5cd2c4
// 005cd250  8b08                 mov ecx, dword ptr [eax]
// 005cd252  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005cd255  7508                 jne 0x5cd25f
// 005cd257  8b5008               mov edx, dword ptr [eax + 8]
// 005cd25a  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005cd25d  7461                 je 0x5cd2c0
// 005cd25f  8b4808               mov ecx, dword ptr [eax + 8]
// 005cd262  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005cd265  7514                 jne 0x5cd27b
// 005cd267  8b10                 mov edx, dword ptr [eax]
// 005cd269  885a2c               mov byte ptr [edx + 0x2c], bl
// 005cd26c  50                   push eax
// 005cd26d  8bcd                 mov ecx, ebp
// 005cd26f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005cd273  e888f7f0ff           call 0x4dca00
// 005cd278  8b4608               mov eax, dword ptr [esi + 8]
// 005cd27b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 005cd27e  88482c               mov byte ptr [eax + 0x2c], cl
// 005cd281  885e2c               mov byte ptr [esi + 0x2c], bl
// 005cd284  8b5008               mov edx, dword ptr [eax + 8]
// 005cd287  56                   push esi
// 005cd288  8bcd                 mov ecx, ebp
// 005cd28a  885a2c               mov byte ptr [edx + 0x2c], bl
// 005cd28d  e8ee170700           call 0x63ea80
// 005cd292  eb74                 jmp 0x5cd308
// 005cd294  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005cd298  7511                 jne 0x5cd2ab
// 005cd29a  88582c               mov byte ptr [eax + 0x2c], bl
// 005cd29d  56                   push esi
// 005cd29e  8bcd                 mov ecx, ebp
// 005cd2a0  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005cd2a4  e857f7f0ff           call 0x4dca00
// 005cd2a9  8b06                 mov eax, dword ptr [esi]
// 005cd2ab  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005cd2af  7513                 jne 0x5cd2c4
// 005cd2b1  8b4808               mov ecx, dword ptr [eax + 8]
// 005cd2b4  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005cd2b7  751e                 jne 0x5cd2d7
// 005cd2b9  8b10                 mov edx, dword ptr [eax]
// 005cd2bb  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005cd2be  7517                 jne 0x5cd2d7
// 005cd2c0  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005cd2c4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005cd2c7  8bfe                 mov edi, esi
// 005cd2c9  8b7604               mov esi, dword ptr [esi + 4]
// 005cd2cc  3b7804               cmp edi, dword ptr [eax + 4]
// 005cd2cf  0f854bffffff         jne 0x5cd220
// 005cd2d5  eb31                 jmp 0x5cd308
// 005cd2d7  8b08                 mov ecx, dword ptr [eax]
// 005cd2d9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005cd2dc  7514                 jne 0x5cd2f2
// 005cd2de  8b5008               mov edx, dword ptr [eax + 8]
// 005cd2e1  885a2c               mov byte ptr [edx + 0x2c], bl
// 005cd2e4  50                   push eax
// 005cd2e5  8bcd                 mov ecx, ebp
// 005cd2e7  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005cd2eb  e890170700           call 0x63ea80
// 005cd2f0  8b06                 mov eax, dword ptr [esi]
// 005cd2f2  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 005cd2f5  88482c               mov byte ptr [eax + 0x2c], cl
// 005cd2f8  885e2c               mov byte ptr [esi + 0x2c], bl
// 005cd2fb  8b10                 mov edx, dword ptr [eax]
// 005cd2fd  56                   push esi
// 005cd2fe  8bcd                 mov ecx, ebp
// 005cd300  885a2c               mov byte ptr [edx + 0x2c], bl
// 005cd303  e8f8f6f0ff           call 0x4dca00
// 005cd308  885f2c               mov byte ptr [edi + 0x2c], bl
// 005cd30b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005cd30f  83c10c               add ecx, 0xc
// 005cd312  ff15c4e48900         call dword ptr [0x89e4c4]
// 005cd318  8b442410             mov eax, dword ptr [esp + 0x10]
// 005cd31c  50                   push eax
// 005cd31d  e810b71400           call 0x718a32
// 005cd322  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005cd325  83c404               add esp, 4
// 005cd328  5f                   pop edi
// 005cd329  5e                   pop esi
// 005cd32a  5b                   pop ebx
// 005cd32b  85c0                 test eax, eax
// 005cd32d  7604                 jbe 0x5cd333
// 005cd32f  48                   dec eax
// 005cd330  89451c               mov dword ptr [ebp + 0x1c], eax
// 005cd333  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005cd337  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005cd33b  8b5500               mov edx, dword ptr [ebp]
// 005cd33e  894804               mov dword ptr [eax + 4], ecx
// 005cd341  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005cd345  8910                 mov dword ptr [eax], edx
// 005cd347  5d                   pop ebp
// 005cd348  64890d00000000       mov dword ptr fs:[0], ecx
// 005cd34f  83c454               add esp, 0x54
// 005cd352  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
