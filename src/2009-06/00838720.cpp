// from server: 100% by auto
// roc 2009-06 00838720  unit: RBX::RenderNew::TextureProxy  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00838720
//
// 00838720  64a100000000         mov eax, dword ptr fs:[0]
// 00838726  6aff                 push -1
// 00838728  68b2db8500           push 0x85dbb2
// 0083872d  50                   push eax
// 0083872e  64892500000000       mov dword ptr fs:[0], esp
// 00838735  8b442418             mov eax, dword ptr [esp + 0x18]
// 00838739  83ec48               sub esp, 0x48
// 0083873c  80782100             cmp byte ptr [eax + 0x21], 0
// 00838740  55                   push ebp
// 00838741  8be9                 mov ebp, ecx
// 00838743  7459                 je 0x83879e
// 00838745  68a4c98a00           push 0x8ac9a4
// 0083874a  8d4c240c             lea ecx, [esp + 0xc]
// 0083874e  ff15b4e48900         call dword ptr [0x89e4b4]
// 00838754  8d4c2424             lea ecx, [esp + 0x24]
// 00838758  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00838760  ff15b8e98900         call dword ptr [0x89e9b8]
// 00838766  8d442408             lea eax, [esp + 8]
// 0083876a  50                   push eax
// 0083876b  8d4c2434             lea ecx, [esp + 0x34]
// 0083876f  c644245801           mov byte ptr [esp + 0x58], 1
// 00838774  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 0083877c  ff15b8e48900         call dword ptr [0x89e4b8]
// 00838782  68dc919700           push 0x9791dc
// 00838787  8d4c2428             lea ecx, [esp + 0x28]
// 0083878b  51                   push ecx
// 0083878c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00838791  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 00838799  e8ac12eeff           call 0x719a4a
// 0083879e  53                   push ebx
// 0083879f  56                   push esi
// 008387a0  8bd8                 mov ebx, eax
// 008387a2  57                   push edi
// 008387a3  8d4c246c             lea ecx, [esp + 0x6c]
// 008387a7  895c2410             mov dword ptr [esp + 0x10], ebx
// 008387ab  e860e3cdff           call 0x516b10
// 008387b0  8b0b                 mov ecx, dword ptr [ebx]
// 008387b2  80792100             cmp byte ptr [ecx + 0x21], 0
// 008387b6  7405                 je 0x8387bd
// 008387b8  8b7b08               mov edi, dword ptr [ebx + 8]
// 008387bb  eb1b                 jmp 0x8387d8
// 008387bd  8b5308               mov edx, dword ptr [ebx + 8]
// 008387c0  807a2100             cmp byte ptr [edx + 0x21], 0
// 008387c4  7404                 je 0x8387ca
// 008387c6  8bf9                 mov edi, ecx
// 008387c8  eb0e                 jmp 0x8387d8
// 008387ca  8b442470             mov eax, dword ptr [esp + 0x70]
// 008387ce  8b7808               mov edi, dword ptr [eax + 8]
// 008387d1  8d5008               lea edx, [eax + 8]
// 008387d4  3bc3                 cmp eax, ebx
// 008387d6  756b                 jne 0x838843
// 008387d8  807f2100             cmp byte ptr [edi + 0x21], 0
// 008387dc  8b7304               mov esi, dword ptr [ebx + 4]
// 008387df  7503                 jne 0x8387e4
// 008387e1  897704               mov dword ptr [edi + 4], esi
// 008387e4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008387e7  395804               cmp dword ptr [eax + 4], ebx
// 008387ea  7505                 jne 0x8387f1
// 008387ec  897804               mov dword ptr [eax + 4], edi
// 008387ef  eb0b                 jmp 0x8387fc
// 008387f1  391e                 cmp dword ptr [esi], ebx
// 008387f3  7504                 jne 0x8387f9
// 008387f5  893e                 mov dword ptr [esi], edi
// 008387f7  eb03                 jmp 0x8387fc
// 008387f9  897e08               mov dword ptr [esi + 8], edi
// 008387fc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 008387ff  8b03                 mov eax, dword ptr [ebx]
// 00838801  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00838805  7515                 jne 0x83881c
// 00838807  807f2100             cmp byte ptr [edi + 0x21], 0
// 0083880b  7404                 je 0x838811
// 0083880d  8bc6                 mov eax, esi
// 0083880f  eb09                 jmp 0x83881a
// 00838811  57                   push edi
// 00838812  e899e2cdff           call 0x516ab0
// 00838817  83c404               add esp, 4
// 0083881a  8903                 mov dword ptr [ebx], eax
// 0083881c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0083881f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00838823  394b08               cmp dword ptr [ebx + 8], ecx
// 00838826  7577                 jne 0x83889f
// 00838828  807f2100             cmp byte ptr [edi + 0x21], 0
// 0083882c  7407                 je 0x838835
// 0083882e  8bc6                 mov eax, esi
// 00838830  894308               mov dword ptr [ebx + 8], eax
// 00838833  eb6a                 jmp 0x83889f
// 00838835  57                   push edi
// 00838836  e8b5e2cdff           call 0x516af0
// 0083883b  83c404               add esp, 4
// 0083883e  894308               mov dword ptr [ebx + 8], eax
// 00838841  eb5c                 jmp 0x83889f
// 00838843  894104               mov dword ptr [ecx + 4], eax
// 00838846  8b0b                 mov ecx, dword ptr [ebx]
// 00838848  8908                 mov dword ptr [eax], ecx
// 0083884a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0083884d  7504                 jne 0x838853
// 0083884f  8bf0                 mov esi, eax
// 00838851  eb19                 jmp 0x83886c
// 00838853  807f2100             cmp byte ptr [edi + 0x21], 0
// 00838857  8b7004               mov esi, dword ptr [eax + 4]
// 0083885a  7503                 jne 0x83885f
// 0083885c  897704               mov dword ptr [edi + 4], esi
// 0083885f  893e                 mov dword ptr [esi], edi
// 00838861  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00838864  890a                 mov dword ptr [edx], ecx
// 00838866  8b5308               mov edx, dword ptr [ebx + 8]
// 00838869  894204               mov dword ptr [edx + 4], eax
// 0083886c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0083886f  395904               cmp dword ptr [ecx + 4], ebx
// 00838872  7505                 jne 0x838879
// 00838874  894104               mov dword ptr [ecx + 4], eax
// 00838877  eb0e                 jmp 0x838887
// 00838879  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0083887c  3919                 cmp dword ptr [ecx], ebx
// 0083887e  7504                 jne 0x838884
// 00838880  8901                 mov dword ptr [ecx], eax
// 00838882  eb03                 jmp 0x838887
// 00838884  894108               mov dword ptr [ecx + 8], eax
// 00838887  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0083888a  894804               mov dword ptr [eax + 4], ecx
// 0083888d  8d4b20               lea ecx, [ebx + 0x20]
// 00838890  83c020               add eax, 0x20
// 00838893  3bc1                 cmp eax, ecx
// 00838895  7408                 je 0x83889f
// 00838897  8a19                 mov bl, byte ptr [ecx]
// 00838899  8a10                 mov dl, byte ptr [eax]
// 0083889b  8818                 mov byte ptr [eax], bl
// 0083889d  8811                 mov byte ptr [ecx], dl
// 0083889f  8b542410             mov edx, dword ptr [esp + 0x10]
// 008388a3  b301                 mov bl, 1
// 008388a5  385a20               cmp byte ptr [edx + 0x20], bl
// 008388a8  0f85fd000000         jne 0x8389ab
// 008388ae  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008388b1  3b7804               cmp edi, dword ptr [eax + 4]
// 008388b4  0f84ee000000         je 0x8389a8
// 008388ba  8d9b00000000         lea ebx, [ebx]
// 008388c0  385f20               cmp byte ptr [edi + 0x20], bl
// 008388c3  0f85df000000         jne 0x8389a8
// 008388c9  8b06                 mov eax, dword ptr [esi]
// 008388cb  3bf8                 cmp edi, eax
// 008388cd  7565                 jne 0x838934
// 008388cf  8b4608               mov eax, dword ptr [esi + 8]
// 008388d2  80782000             cmp byte ptr [eax + 0x20], 0
// 008388d6  7512                 jne 0x8388ea
// 008388d8  885820               mov byte ptr [eax + 0x20], bl
// 008388db  56                   push esi
// 008388dc  8bcd                 mov ecx, ebp
// 008388de  c6462000             mov byte ptr [esi + 0x20], 0
// 008388e2  e839efcdff           call 0x517820
// 008388e7  8b4608               mov eax, dword ptr [esi + 8]
// 008388ea  80782100             cmp byte ptr [eax + 0x21], 0
// 008388ee  7574                 jne 0x838964
// 008388f0  8b08                 mov ecx, dword ptr [eax]
// 008388f2  385920               cmp byte ptr [ecx + 0x20], bl
// 008388f5  7508                 jne 0x8388ff
// 008388f7  8b5008               mov edx, dword ptr [eax + 8]
// 008388fa  385a20               cmp byte ptr [edx + 0x20], bl
// 008388fd  7461                 je 0x838960
// 008388ff  8b4808               mov ecx, dword ptr [eax + 8]
// 00838902  385920               cmp byte ptr [ecx + 0x20], bl
// 00838905  7514                 jne 0x83891b
// 00838907  8b10                 mov edx, dword ptr [eax]
// 00838909  885a20               mov byte ptr [edx + 0x20], bl
// 0083890c  50                   push eax
// 0083890d  8bcd                 mov ecx, ebp
// 0083890f  c6402000             mov byte ptr [eax + 0x20], 0
// 00838913  e838e1cdff           call 0x516a50
// 00838918  8b4608               mov eax, dword ptr [esi + 8]
// 0083891b  8a4e20               mov cl, byte ptr [esi + 0x20]
// 0083891e  884820               mov byte ptr [eax + 0x20], cl
// 00838921  885e20               mov byte ptr [esi + 0x20], bl
// 00838924  8b5008               mov edx, dword ptr [eax + 8]
// 00838927  56                   push esi
// 00838928  8bcd                 mov ecx, ebp
// 0083892a  885a20               mov byte ptr [edx + 0x20], bl
// 0083892d  e8eeeecdff           call 0x517820
// 00838932  eb74                 jmp 0x8389a8
// 00838934  80782000             cmp byte ptr [eax + 0x20], 0
// 00838938  7511                 jne 0x83894b
// 0083893a  885820               mov byte ptr [eax + 0x20], bl
// 0083893d  56                   push esi
// 0083893e  8bcd                 mov ecx, ebp
// 00838940  c6462000             mov byte ptr [esi + 0x20], 0
// 00838944  e807e1cdff           call 0x516a50
// 00838949  8b06                 mov eax, dword ptr [esi]
// 0083894b  80782100             cmp byte ptr [eax + 0x21], 0
// 0083894f  7513                 jne 0x838964
// 00838951  8b4808               mov ecx, dword ptr [eax + 8]
// 00838954  385920               cmp byte ptr [ecx + 0x20], bl
// 00838957  751e                 jne 0x838977
// 00838959  8b10                 mov edx, dword ptr [eax]
// 0083895b  385a20               cmp byte ptr [edx + 0x20], bl
// 0083895e  7517                 jne 0x838977
// 00838960  c6402000             mov byte ptr [eax + 0x20], 0
// 00838964  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00838967  8bfe                 mov edi, esi
// 00838969  8b7604               mov esi, dword ptr [esi + 4]
// 0083896c  3b7804               cmp edi, dword ptr [eax + 4]
// 0083896f  0f854bffffff         jne 0x8388c0
// 00838975  eb31                 jmp 0x8389a8
// 00838977  8b08                 mov ecx, dword ptr [eax]
// 00838979  385920               cmp byte ptr [ecx + 0x20], bl
// 0083897c  7514                 jne 0x838992
// 0083897e  8b5008               mov edx, dword ptr [eax + 8]
// 00838981  885a20               mov byte ptr [edx + 0x20], bl
// 00838984  50                   push eax
// 00838985  8bcd                 mov ecx, ebp
// 00838987  c6402000             mov byte ptr [eax + 0x20], 0
// 0083898b  e890eecdff           call 0x517820
// 00838990  8b06                 mov eax, dword ptr [esi]
// 00838992  8a4e20               mov cl, byte ptr [esi + 0x20]
// 00838995  884820               mov byte ptr [eax + 0x20], cl
// 00838998  885e20               mov byte ptr [esi + 0x20], bl
// 0083899b  8b10                 mov edx, dword ptr [eax]
// 0083899d  56                   push esi
// 0083899e  8bcd                 mov ecx, ebp
// 008389a0  885a20               mov byte ptr [edx + 0x20], bl
// 008389a3  e8a8e0cdff           call 0x516a50
// 008389a8  885f20               mov byte ptr [edi + 0x20], bl
// 008389ab  8b442410             mov eax, dword ptr [esp + 0x10]
// 008389af  50                   push eax
// 008389b0  e87d00eeff           call 0x718a32
// 008389b5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 008389b8  83c404               add esp, 4
// 008389bb  5f                   pop edi
// 008389bc  5e                   pop esi
// 008389bd  5b                   pop ebx
// 008389be  85c0                 test eax, eax
// 008389c0  7604                 jbe 0x8389c6
// 008389c2  48                   dec eax
// 008389c3  89451c               mov dword ptr [ebp + 0x1c], eax
// 008389c6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 008389ca  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 008389ce  8b5500               mov edx, dword ptr [ebp]
// 008389d1  894804               mov dword ptr [eax + 4], ecx
// 008389d4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008389d8  8910                 mov dword ptr [eax], edx
// 008389da  5d                   pop ebp
// 008389db  64890d00000000       mov dword ptr fs:[0], ecx
// 008389e2  83c454               add esp, 0x54
// 008389e5  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
