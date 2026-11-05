// from server: 100% by auto
// roc 2008-06 00648690  unit: RBX::Block  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648690
//
// 00648690  64a100000000         mov eax, dword ptr fs:[0]
// 00648696  6aff                 push -1
// 00648698  6842e87d00           push 0x7de842
// 0064869d  50                   push eax
// 0064869e  64892500000000       mov dword ptr fs:[0], esp
// 006486a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006486a9  83ec48               sub esp, 0x48
// 006486ac  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006486b0  55                   push ebp
// 006486b1  8be9                 mov ebp, ecx
// 006486b3  7459                 je 0x64870e
// 006486b5  6870b28000           push 0x80b270
// 006486ba  8d4c240c             lea ecx, [esp + 0xc]
// 006486be  ff1558248000         call dword ptr [0x802458]
// 006486c4  8d4c2424             lea ecx, [esp + 0x24]
// 006486c8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006486d0  ff1598288000         call dword ptr [0x802898]
// 006486d6  8d442408             lea eax, [esp + 8]
// 006486da  50                   push eax
// 006486db  8d4c2434             lea ecx, [esp + 0x34]
// 006486df  c644245801           mov byte ptr [esp + 0x58], 1
// 006486e4  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 006486ec  ff155c248000         call dword ptr [0x80245c]
// 006486f2  683c0c8d00           push 0x8d0c3c
// 006486f7  8d4c2428             lea ecx, [esp + 0x28]
// 006486fb  51                   push ecx
// 006486fc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00648701  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00648709  e87e8e0500           call 0x6a158c
// 0064870e  53                   push ebx
// 0064870f  56                   push esi
// 00648710  8bd8                 mov ebx, eax
// 00648712  57                   push edi
// 00648713  8d4c246c             lea ecx, [esp + 0x6c]
// 00648717  895c2410             mov dword ptr [esp + 0x10], ebx
// 0064871b  e800faffff           call 0x648120
// 00648720  8b0b                 mov ecx, dword ptr [ebx]
// 00648722  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00648726  7405                 je 0x64872d
// 00648728  8b7b08               mov edi, dword ptr [ebx + 8]
// 0064872b  eb1b                 jmp 0x648748
// 0064872d  8b5308               mov edx, dword ptr [ebx + 8]
// 00648730  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 00648734  7404                 je 0x64873a
// 00648736  8bf9                 mov edi, ecx
// 00648738  eb0e                 jmp 0x648748
// 0064873a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0064873e  8b7808               mov edi, dword ptr [eax + 8]
// 00648741  8d5008               lea edx, [eax + 8]
// 00648744  3bc3                 cmp eax, ebx
// 00648746  756b                 jne 0x6487b3
// 00648748  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0064874c  8b7304               mov esi, dword ptr [ebx + 4]
// 0064874f  7503                 jne 0x648754
// 00648751  897704               mov dword ptr [edi + 4], esi
// 00648754  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00648757  395804               cmp dword ptr [eax + 4], ebx
// 0064875a  7505                 jne 0x648761
// 0064875c  897804               mov dword ptr [eax + 4], edi
// 0064875f  eb0b                 jmp 0x64876c
// 00648761  391e                 cmp dword ptr [esi], ebx
// 00648763  7504                 jne 0x648769
// 00648765  893e                 mov dword ptr [esi], edi
// 00648767  eb03                 jmp 0x64876c
// 00648769  897e08               mov dword ptr [esi + 8], edi
// 0064876c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064876f  8b03                 mov eax, dword ptr [ebx]
// 00648771  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00648775  7515                 jne 0x64878c
// 00648777  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0064877b  7404                 je 0x648781
// 0064877d  8bc6                 mov eax, esi
// 0064877f  eb09                 jmp 0x64878a
// 00648781  57                   push edi
// 00648782  e849f6ffff           call 0x647dd0
// 00648787  83c404               add esp, 4
// 0064878a  8903                 mov dword ptr [ebx], eax
// 0064878c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064878f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00648793  394b08               cmp dword ptr [ebx + 8], ecx
// 00648796  7577                 jne 0x64880f
// 00648798  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0064879c  7407                 je 0x6487a5
// 0064879e  8bc6                 mov eax, esi
// 006487a0  894308               mov dword ptr [ebx + 8], eax
// 006487a3  eb6a                 jmp 0x64880f
// 006487a5  57                   push edi
// 006487a6  e8a5f6ffff           call 0x647e50
// 006487ab  83c404               add esp, 4
// 006487ae  894308               mov dword ptr [ebx + 8], eax
// 006487b1  eb5c                 jmp 0x64880f
// 006487b3  894104               mov dword ptr [ecx + 4], eax
// 006487b6  8b0b                 mov ecx, dword ptr [ebx]
// 006487b8  8908                 mov dword ptr [eax], ecx
// 006487ba  3b4308               cmp eax, dword ptr [ebx + 8]
// 006487bd  7504                 jne 0x6487c3
// 006487bf  8bf0                 mov esi, eax
// 006487c1  eb19                 jmp 0x6487dc
// 006487c3  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006487c7  8b7004               mov esi, dword ptr [eax + 4]
// 006487ca  7503                 jne 0x6487cf
// 006487cc  897704               mov dword ptr [edi + 4], esi
// 006487cf  893e                 mov dword ptr [esi], edi
// 006487d1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006487d4  890a                 mov dword ptr [edx], ecx
// 006487d6  8b5308               mov edx, dword ptr [ebx + 8]
// 006487d9  894204               mov dword ptr [edx + 4], eax
// 006487dc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006487df  395904               cmp dword ptr [ecx + 4], ebx
// 006487e2  7505                 jne 0x6487e9
// 006487e4  894104               mov dword ptr [ecx + 4], eax
// 006487e7  eb0e                 jmp 0x6487f7
// 006487e9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006487ec  3919                 cmp dword ptr [ecx], ebx
// 006487ee  7504                 jne 0x6487f4
// 006487f0  8901                 mov dword ptr [ecx], eax
// 006487f2  eb03                 jmp 0x6487f7
// 006487f4  894108               mov dword ptr [ecx + 8], eax
// 006487f7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006487fa  894804               mov dword ptr [eax + 4], ecx
// 006487fd  8d4b1c               lea ecx, [ebx + 0x1c]
// 00648800  83c01c               add eax, 0x1c
// 00648803  3bc1                 cmp eax, ecx
// 00648805  7408                 je 0x64880f
// 00648807  8a19                 mov bl, byte ptr [ecx]
// 00648809  8a10                 mov dl, byte ptr [eax]
// 0064880b  8818                 mov byte ptr [eax], bl
// 0064880d  8811                 mov byte ptr [ecx], dl
// 0064880f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00648813  b301                 mov bl, 1
// 00648815  385a1c               cmp byte ptr [edx + 0x1c], bl
// 00648818  0f85fd000000         jne 0x64891b
// 0064881e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00648821  3b7804               cmp edi, dword ptr [eax + 4]
// 00648824  0f84ee000000         je 0x648918
// 0064882a  8d9b00000000         lea ebx, [ebx]
// 00648830  385f1c               cmp byte ptr [edi + 0x1c], bl
// 00648833  0f85df000000         jne 0x648918
// 00648839  8b06                 mov eax, dword ptr [esi]
// 0064883b  3bf8                 cmp edi, eax
// 0064883d  7565                 jne 0x6488a4
// 0064883f  8b4608               mov eax, dword ptr [esi + 8]
// 00648842  80781c00             cmp byte ptr [eax + 0x1c], 0
// 00648846  7512                 jne 0x64885a
// 00648848  88581c               mov byte ptr [eax + 0x1c], bl
// 0064884b  56                   push esi
// 0064884c  8bcd                 mov ecx, ebp
// 0064884e  c6461c00             mov byte ptr [esi + 0x1c], 0
// 00648852  e839f9ffff           call 0x648190
// 00648857  8b4608               mov eax, dword ptr [esi + 8]
// 0064885a  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0064885e  7574                 jne 0x6488d4
// 00648860  8b08                 mov ecx, dword ptr [eax]
// 00648862  38591c               cmp byte ptr [ecx + 0x1c], bl
// 00648865  7508                 jne 0x64886f
// 00648867  8b5008               mov edx, dword ptr [eax + 8]
// 0064886a  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0064886d  7461                 je 0x6488d0
// 0064886f  8b4808               mov ecx, dword ptr [eax + 8]
// 00648872  38591c               cmp byte ptr [ecx + 0x1c], bl
// 00648875  7514                 jne 0x64888b
// 00648877  8b10                 mov edx, dword ptr [eax]
// 00648879  885a1c               mov byte ptr [edx + 0x1c], bl
// 0064887c  50                   push eax
// 0064887d  8bcd                 mov ecx, ebp
// 0064887f  c6401c00             mov byte ptr [eax + 0x1c], 0
// 00648883  e868f5ffff           call 0x647df0
// 00648888  8b4608               mov eax, dword ptr [esi + 8]
// 0064888b  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 0064888e  88481c               mov byte ptr [eax + 0x1c], cl
// 00648891  885e1c               mov byte ptr [esi + 0x1c], bl
// 00648894  8b5008               mov edx, dword ptr [eax + 8]
// 00648897  56                   push esi
// 00648898  8bcd                 mov ecx, ebp
// 0064889a  885a1c               mov byte ptr [edx + 0x1c], bl
// 0064889d  e8eef8ffff           call 0x648190
// 006488a2  eb74                 jmp 0x648918
// 006488a4  80781c00             cmp byte ptr [eax + 0x1c], 0
// 006488a8  7511                 jne 0x6488bb
// 006488aa  88581c               mov byte ptr [eax + 0x1c], bl
// 006488ad  56                   push esi
// 006488ae  8bcd                 mov ecx, ebp
// 006488b0  c6461c00             mov byte ptr [esi + 0x1c], 0
// 006488b4  e837f5ffff           call 0x647df0
// 006488b9  8b06                 mov eax, dword ptr [esi]
// 006488bb  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006488bf  7513                 jne 0x6488d4
// 006488c1  8b4808               mov ecx, dword ptr [eax + 8]
// 006488c4  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006488c7  751e                 jne 0x6488e7
// 006488c9  8b10                 mov edx, dword ptr [eax]
// 006488cb  385a1c               cmp byte ptr [edx + 0x1c], bl
// 006488ce  7517                 jne 0x6488e7
// 006488d0  c6401c00             mov byte ptr [eax + 0x1c], 0
// 006488d4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006488d7  8bfe                 mov edi, esi
// 006488d9  8b7604               mov esi, dword ptr [esi + 4]
// 006488dc  3b7804               cmp edi, dword ptr [eax + 4]
// 006488df  0f854bffffff         jne 0x648830
// 006488e5  eb31                 jmp 0x648918
// 006488e7  8b08                 mov ecx, dword ptr [eax]
// 006488e9  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006488ec  7514                 jne 0x648902
// 006488ee  8b5008               mov edx, dword ptr [eax + 8]
// 006488f1  885a1c               mov byte ptr [edx + 0x1c], bl
// 006488f4  50                   push eax
// 006488f5  8bcd                 mov ecx, ebp
// 006488f7  c6401c00             mov byte ptr [eax + 0x1c], 0
// 006488fb  e890f8ffff           call 0x648190
// 00648900  8b06                 mov eax, dword ptr [esi]
// 00648902  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 00648905  88481c               mov byte ptr [eax + 0x1c], cl
// 00648908  885e1c               mov byte ptr [esi + 0x1c], bl
// 0064890b  8b10                 mov edx, dword ptr [eax]
// 0064890d  56                   push esi
// 0064890e  8bcd                 mov ecx, ebp
// 00648910  885a1c               mov byte ptr [edx + 0x1c], bl
// 00648913  e8d8f4ffff           call 0x647df0
// 00648918  885f1c               mov byte ptr [edi + 0x1c], bl
// 0064891b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0064891f  50                   push eax
// 00648920  e8557d0500           call 0x6a067a
// 00648925  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00648928  83c404               add esp, 4
// 0064892b  5f                   pop edi
// 0064892c  5e                   pop esi
// 0064892d  5b                   pop ebx
// 0064892e  85c0                 test eax, eax
// 00648930  7604                 jbe 0x648936
// 00648932  48                   dec eax
// 00648933  89451c               mov dword ptr [ebp + 0x1c], eax
// 00648936  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0064893a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0064893e  8b5500               mov edx, dword ptr [ebp]
// 00648941  894804               mov dword ptr [eax + 4], ecx
// 00648944  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00648948  8910                 mov dword ptr [eax], edx
// 0064894a  5d                   pop ebp
// 0064894b  64890d00000000       mov dword ptr fs:[0], ecx
// 00648952  83c454               add esp, 0x54
// 00648955  c20c00               ret 0xc
// standard library set<pod16> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
