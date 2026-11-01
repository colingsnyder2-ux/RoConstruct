// from server: 100% by auto
// roc 2007-08 004670e0  unit: VCWorkspace::?$CComObject  size: 692 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004670e0
//
// 004670e0  6aff                 push -1
// 004670e2  68e9a07400           push 0x74a0e9
// 004670e7  64a100000000         mov eax, dword ptr fs:[0]
// 004670ed  50                   push eax
// 004670ee  83ec48               sub esp, 0x48
// 004670f1  53                   push ebx
// 004670f2  55                   push ebp
// 004670f3  56                   push esi
// 004670f4  57                   push edi
// 004670f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004670fa  33c4                 xor eax, esp
// 004670fc  50                   push eax
// 004670fd  8d44245c             lea eax, [esp + 0x5c]
// 00467101  64a300000000         mov dword ptr fs:[0], eax
// 00467107  8be9                 mov ebp, ecx
// 00467109  8b442474             mov eax, dword ptr [esp + 0x74]
// 0046710d  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00467111  743c                 je 0x46714f
// 00467113  68dc4e7800           push 0x784edc
// 00467118  8d4c241c             lea ecx, [esp + 0x1c]
// 0046711c  ff1598e67700         call dword ptr [0x77e698]
// 00467122  8d442418             lea eax, [esp + 0x18]
// 00467126  50                   push eax
// 00467127  8d4c2438             lea ecx, [esp + 0x38]
// 0046712b  c744246800000000     mov dword ptr [esp + 0x68], 0
// 00467133  e888b3f9ff           call 0x4024c0
// 00467138  6864f38300           push 0x83f364
// 0046713d  8d4c2438             lea ecx, [esp + 0x38]
// 00467141  51                   push ecx
// 00467142  c744243c784e7800     mov dword ptr [esp + 0x3c], 0x784e78
// 0046714a  e84f9a1c00           call 0x630b9e
// 0046714f  8bd8                 mov ebx, eax
// 00467151  8d4c2470             lea ecx, [esp + 0x70]
// 00467155  895c2414             mov dword ptr [esp + 0x14], ebx
// 00467159  e8c22d1700           call 0x5d9f20
// 0046715e  8b03                 mov eax, dword ptr [ebx]
// 00467160  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00467164  7405                 je 0x46716b
// 00467166  8b7b08               mov edi, dword ptr [ebx + 8]
// 00467169  eb18                 jmp 0x467183
// 0046716b  8b5308               mov edx, dword ptr [ebx + 8]
// 0046716e  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00467172  7404                 je 0x467178
// 00467174  8bf8                 mov edi, eax
// 00467176  eb0b                 jmp 0x467183
// 00467178  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0046717c  3bcb                 cmp ecx, ebx
// 0046717e  8b7908               mov edi, dword ptr [ecx + 8]
// 00467181  756b                 jne 0x4671ee
// 00467183  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00467187  8b7304               mov esi, dword ptr [ebx + 4]
// 0046718a  7503                 jne 0x46718f
// 0046718c  897704               mov dword ptr [edi + 4], esi
// 0046718f  8b4504               mov eax, dword ptr [ebp + 4]
// 00467192  395804               cmp dword ptr [eax + 4], ebx
// 00467195  7505                 jne 0x46719c
// 00467197  897804               mov dword ptr [eax + 4], edi
// 0046719a  eb0b                 jmp 0x4671a7
// 0046719c  391e                 cmp dword ptr [esi], ebx
// 0046719e  7504                 jne 0x4671a4
// 004671a0  893e                 mov dword ptr [esi], edi
// 004671a2  eb03                 jmp 0x4671a7
// 004671a4  897e08               mov dword ptr [esi + 8], edi
// 004671a7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 004671aa  8b03                 mov eax, dword ptr [ebx]
// 004671ac  3b442414             cmp eax, dword ptr [esp + 0x14]
// 004671b0  7515                 jne 0x4671c7
// 004671b2  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004671b6  7404                 je 0x4671bc
// 004671b8  8bc6                 mov eax, esi
// 004671ba  eb09                 jmp 0x4671c5
// 004671bc  57                   push edi
// 004671bd  e8ce910300           call 0x4a0390
// 004671c2  83c404               add esp, 4
// 004671c5  8903                 mov dword ptr [ebx], eax
// 004671c7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 004671ca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004671ce  394b08               cmp dword ptr [ebx + 8], ecx
// 004671d1  7572                 jne 0x467245
// 004671d3  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004671d7  7407                 je 0x4671e0
// 004671d9  8bc6                 mov eax, esi
// 004671db  894308               mov dword ptr [ebx + 8], eax
// 004671de  eb65                 jmp 0x467245
// 004671e0  57                   push edi
// 004671e1  e86a251300           call 0x599750
// 004671e6  83c404               add esp, 4
// 004671e9  894308               mov dword ptr [ebx + 8], eax
// 004671ec  eb57                 jmp 0x467245
// 004671ee  894804               mov dword ptr [eax + 4], ecx
// 004671f1  8b13                 mov edx, dword ptr [ebx]
// 004671f3  8911                 mov dword ptr [ecx], edx
// 004671f5  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 004671f8  7504                 jne 0x4671fe
// 004671fa  8bf1                 mov esi, ecx
// 004671fc  eb1a                 jmp 0x467218
// 004671fe  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00467202  8b7104               mov esi, dword ptr [ecx + 4]
// 00467205  7503                 jne 0x46720a
// 00467207  897704               mov dword ptr [edi + 4], esi
// 0046720a  893e                 mov dword ptr [esi], edi
// 0046720c  8b4308               mov eax, dword ptr [ebx + 8]
// 0046720f  894108               mov dword ptr [ecx + 8], eax
// 00467212  8b5308               mov edx, dword ptr [ebx + 8]
// 00467215  894a04               mov dword ptr [edx + 4], ecx
// 00467218  8b4504               mov eax, dword ptr [ebp + 4]
// 0046721b  395804               cmp dword ptr [eax + 4], ebx
// 0046721e  7505                 jne 0x467225
// 00467220  894804               mov dword ptr [eax + 4], ecx
// 00467223  eb0e                 jmp 0x467233
// 00467225  8b4304               mov eax, dword ptr [ebx + 4]
// 00467228  3918                 cmp dword ptr [eax], ebx
// 0046722a  7504                 jne 0x467230
// 0046722c  8908                 mov dword ptr [eax], ecx
// 0046722e  eb03                 jmp 0x467233
// 00467230  894808               mov dword ptr [eax + 8], ecx
// 00467233  8b4304               mov eax, dword ptr [ebx + 4]
// 00467236  894104               mov dword ptr [ecx + 4], eax
// 00467239  8a532c               mov dl, byte ptr [ebx + 0x2c]
// 0046723c  8a412c               mov al, byte ptr [ecx + 0x2c]
// 0046723f  88512c               mov byte ptr [ecx + 0x2c], dl
// 00467242  88432c               mov byte ptr [ebx + 0x2c], al
// 00467245  8b442414             mov eax, dword ptr [esp + 0x14]
// 00467249  b301                 mov bl, 1
// 0046724b  38582c               cmp byte ptr [eax + 0x2c], bl
// 0046724e  0f85f2000000         jne 0x467346
// 00467254  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00467257  3b7904               cmp edi, dword ptr [ecx + 4]
// 0046725a  0f84e3000000         je 0x467343
// 00467260  385f2c               cmp byte ptr [edi + 0x2c], bl
// 00467263  0f85da000000         jne 0x467343
// 00467269  8b06                 mov eax, dword ptr [esi]
// 0046726b  3bf8                 cmp edi, eax
// 0046726d  7563                 jne 0x4672d2
// 0046726f  8b4608               mov eax, dword ptr [esi + 8]
// 00467272  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00467276  7512                 jne 0x46728a
// 00467278  88582c               mov byte ptr [eax + 0x2c], bl
// 0046727b  56                   push esi
// 0046727c  8bcd                 mov ecx, ebp
// 0046727e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00467282  e8099d0300           call 0x4a0f90
// 00467287  8b4608               mov eax, dword ptr [esi + 8]
// 0046728a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0046728e  7572                 jne 0x467302
// 00467290  8b10                 mov edx, dword ptr [eax]
// 00467292  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00467295  7508                 jne 0x46729f
// 00467297  8b4808               mov ecx, dword ptr [eax + 8]
// 0046729a  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0046729d  745f                 je 0x4672fe
// 0046729f  8b4808               mov ecx, dword ptr [eax + 8]
// 004672a2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004672a5  7512                 jne 0x4672b9
// 004672a7  885a2c               mov byte ptr [edx + 0x2c], bl
// 004672aa  50                   push eax
// 004672ab  8bcd                 mov ecx, ebp
// 004672ad  c6402c00             mov byte ptr [eax + 0x2c], 0
// 004672b1  e82a9c0300           call 0x4a0ee0
// 004672b6  8b4608               mov eax, dword ptr [esi + 8]
// 004672b9  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 004672bc  88482c               mov byte ptr [eax + 0x2c], cl
// 004672bf  885e2c               mov byte ptr [esi + 0x2c], bl
// 004672c2  8b5008               mov edx, dword ptr [eax + 8]
// 004672c5  56                   push esi
// 004672c6  8bcd                 mov ecx, ebp
// 004672c8  885a2c               mov byte ptr [edx + 0x2c], bl
// 004672cb  e8c09c0300           call 0x4a0f90
// 004672d0  eb71                 jmp 0x467343
// 004672d2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 004672d6  7511                 jne 0x4672e9
// 004672d8  88582c               mov byte ptr [eax + 0x2c], bl
// 004672db  56                   push esi
// 004672dc  8bcd                 mov ecx, ebp
// 004672de  c6462c00             mov byte ptr [esi + 0x2c], 0
// 004672e2  e8f99b0300           call 0x4a0ee0
// 004672e7  8b06                 mov eax, dword ptr [esi]
// 004672e9  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004672ed  7513                 jne 0x467302
// 004672ef  8b5008               mov edx, dword ptr [eax + 8]
// 004672f2  385a2c               cmp byte ptr [edx + 0x2c], bl
// 004672f5  751e                 jne 0x467315
// 004672f7  8b08                 mov ecx, dword ptr [eax]
// 004672f9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004672fc  7517                 jne 0x467315
// 004672fe  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00467302  8b5504               mov edx, dword ptr [ebp + 4]
// 00467305  8bfe                 mov edi, esi
// 00467307  3b7a04               cmp edi, dword ptr [edx + 4]
// 0046730a  8b7604               mov esi, dword ptr [esi + 4]
// 0046730d  0f854dffffff         jne 0x467260
// 00467313  eb2e                 jmp 0x467343
// 00467315  8b08                 mov ecx, dword ptr [eax]
// 00467317  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0046731a  7511                 jne 0x46732d
// 0046731c  885a2c               mov byte ptr [edx + 0x2c], bl
// 0046731f  50                   push eax
// 00467320  8bcd                 mov ecx, ebp
// 00467322  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00467326  e8659c0300           call 0x4a0f90
// 0046732b  8b06                 mov eax, dword ptr [esi]
// 0046732d  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 00467330  88482c               mov byte ptr [eax + 0x2c], cl
// 00467333  885e2c               mov byte ptr [esi + 0x2c], bl
// 00467336  8b10                 mov edx, dword ptr [eax]
// 00467338  56                   push esi
// 00467339  8bcd                 mov ecx, ebp
// 0046733b  885a2c               mov byte ptr [edx + 0x2c], bl
// 0046733e  e89d9b0300           call 0x4a0ee0
// 00467343  885f2c               mov byte ptr [edi + 0x2c], bl
// 00467346  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046734a  83c10c               add ecx, 0xc
// 0046734d  ff15ace67700         call dword ptr [0x77e6ac]
// 00467353  8b442414             mov eax, dword ptr [esp + 0x14]
// 00467357  50                   push eax
// 00467358  e805891c00           call 0x62fc62
// 0046735d  8b4508               mov eax, dword ptr [ebp + 8]
// 00467360  83c404               add esp, 4
// 00467363  85c0                 test eax, eax
// 00467365  7606                 jbe 0x46736d
// 00467367  83c0ff               add eax, -1
// 0046736a  894508               mov dword ptr [ebp + 8], eax
// 0046736d  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00467371  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 00467375  8b542474             mov edx, dword ptr [esp + 0x74]
// 00467379  8908                 mov dword ptr [eax], ecx
// 0046737b  895004               mov dword ptr [eax + 4], edx
// 0046737e  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00467382  64890d00000000       mov dword ptr fs:[0], ecx
// 00467389  59                   pop ecx
// 0046738a  5f                   pop edi
// 0046738b  5e                   pop esi
// 0046738c  5d                   pop ebp
// 0046738d  5b                   pop ebx
// 0046738e  83c454               add esp, 0x54
// 00467391  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
