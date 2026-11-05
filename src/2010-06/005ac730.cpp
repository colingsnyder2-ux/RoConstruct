// from server: 100% by auto
// roc 2010-06 005ac730  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ac730
//
// 005ac730  64a100000000         mov eax, dword ptr fs:[0]
// 005ac736  6aff                 push -1
// 005ac738  68e22f9a00           push 0x9a2fe2
// 005ac73d  50                   push eax
// 005ac73e  64892500000000       mov dword ptr fs:[0], esp
// 005ac745  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ac749  83ec48               sub esp, 0x48
// 005ac74c  80781500             cmp byte ptr [eax + 0x15], 0
// 005ac750  55                   push ebp
// 005ac751  8be9                 mov ebp, ecx
// 005ac753  7459                 je 0x5ac7ae
// 005ac755  688c00a000           push 0xa0008c
// 005ac75a  8d4c240c             lea ecx, [esp + 0xc]
// 005ac75e  ff1510a49e00         call dword ptr [0x9ea410]
// 005ac764  8d4c2424             lea ecx, [esp + 0x24]
// 005ac768  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005ac770  ff1518a99e00         call dword ptr [0x9ea918]
// 005ac776  8d442408             lea eax, [esp + 8]
// 005ac77a  50                   push eax
// 005ac77b  8d4c2434             lea ecx, [esp + 0x34]
// 005ac77f  c644245801           mov byte ptr [esp + 0x58], 1
// 005ac784  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 005ac78c  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ac792  68081bb000           push 0xb01b08
// 005ac797  8d4c2428             lea ecx, [esp + 0x28]
// 005ac79b  51                   push ecx
// 005ac79c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005ac7a1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 005ac7a9  e804c21f00           call 0x7a89b2
// 005ac7ae  53                   push ebx
// 005ac7af  56                   push esi
// 005ac7b0  8bd8                 mov ebx, eax
// 005ac7b2  57                   push edi
// 005ac7b3  8d4c246c             lea ecx, [esp + 0x6c]
// 005ac7b7  895c2410             mov dword ptr [esp + 0x10], ebx
// 005ac7bb  e820b21300           call 0x6e79e0
// 005ac7c0  8b0b                 mov ecx, dword ptr [ebx]
// 005ac7c2  80791500             cmp byte ptr [ecx + 0x15], 0
// 005ac7c6  7405                 je 0x5ac7cd
// 005ac7c8  8b7b08               mov edi, dword ptr [ebx + 8]
// 005ac7cb  eb1b                 jmp 0x5ac7e8
// 005ac7cd  8b5308               mov edx, dword ptr [ebx + 8]
// 005ac7d0  807a1500             cmp byte ptr [edx + 0x15], 0
// 005ac7d4  7404                 je 0x5ac7da
// 005ac7d6  8bf9                 mov edi, ecx
// 005ac7d8  eb0e                 jmp 0x5ac7e8
// 005ac7da  8b442470             mov eax, dword ptr [esp + 0x70]
// 005ac7de  8b7808               mov edi, dword ptr [eax + 8]
// 005ac7e1  8d5008               lea edx, [eax + 8]
// 005ac7e4  3bc3                 cmp eax, ebx
// 005ac7e6  756b                 jne 0x5ac853
// 005ac7e8  807f1500             cmp byte ptr [edi + 0x15], 0
// 005ac7ec  8b7304               mov esi, dword ptr [ebx + 4]
// 005ac7ef  7503                 jne 0x5ac7f4
// 005ac7f1  897704               mov dword ptr [edi + 4], esi
// 005ac7f4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005ac7f7  395804               cmp dword ptr [eax + 4], ebx
// 005ac7fa  7505                 jne 0x5ac801
// 005ac7fc  897804               mov dword ptr [eax + 4], edi
// 005ac7ff  eb0b                 jmp 0x5ac80c
// 005ac801  391e                 cmp dword ptr [esi], ebx
// 005ac803  7504                 jne 0x5ac809
// 005ac805  893e                 mov dword ptr [esi], edi
// 005ac807  eb03                 jmp 0x5ac80c
// 005ac809  897e08               mov dword ptr [esi + 8], edi
// 005ac80c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005ac80f  8b03                 mov eax, dword ptr [ebx]
// 005ac811  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005ac815  7515                 jne 0x5ac82c
// 005ac817  807f1500             cmp byte ptr [edi + 0x15], 0
// 005ac81b  7404                 je 0x5ac821
// 005ac81d  8bc6                 mov eax, esi
// 005ac81f  eb09                 jmp 0x5ac82a
// 005ac821  57                   push edi
// 005ac822  e81941f3ff           call 0x4e0940
// 005ac827  83c404               add esp, 4
// 005ac82a  8903                 mov dword ptr [ebx], eax
// 005ac82c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005ac82f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ac833  394b08               cmp dword ptr [ebx + 8], ecx
// 005ac836  7577                 jne 0x5ac8af
// 005ac838  807f1500             cmp byte ptr [edi + 0x15], 0
// 005ac83c  7407                 je 0x5ac845
// 005ac83e  8bc6                 mov eax, esi
// 005ac840  894308               mov dword ptr [ebx + 8], eax
// 005ac843  eb6a                 jmp 0x5ac8af
// 005ac845  57                   push edi
// 005ac846  e875e0ffff           call 0x5aa8c0
// 005ac84b  83c404               add esp, 4
// 005ac84e  894308               mov dword ptr [ebx + 8], eax
// 005ac851  eb5c                 jmp 0x5ac8af
// 005ac853  894104               mov dword ptr [ecx + 4], eax
// 005ac856  8b0b                 mov ecx, dword ptr [ebx]
// 005ac858  8908                 mov dword ptr [eax], ecx
// 005ac85a  3b4308               cmp eax, dword ptr [ebx + 8]
// 005ac85d  7504                 jne 0x5ac863
// 005ac85f  8bf0                 mov esi, eax
// 005ac861  eb19                 jmp 0x5ac87c
// 005ac863  807f1500             cmp byte ptr [edi + 0x15], 0
// 005ac867  8b7004               mov esi, dword ptr [eax + 4]
// 005ac86a  7503                 jne 0x5ac86f
// 005ac86c  897704               mov dword ptr [edi + 4], esi
// 005ac86f  893e                 mov dword ptr [esi], edi
// 005ac871  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005ac874  890a                 mov dword ptr [edx], ecx
// 005ac876  8b5308               mov edx, dword ptr [ebx + 8]
// 005ac879  894204               mov dword ptr [edx + 4], eax
// 005ac87c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005ac87f  395904               cmp dword ptr [ecx + 4], ebx
// 005ac882  7505                 jne 0x5ac889
// 005ac884  894104               mov dword ptr [ecx + 4], eax
// 005ac887  eb0e                 jmp 0x5ac897
// 005ac889  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005ac88c  3919                 cmp dword ptr [ecx], ebx
// 005ac88e  7504                 jne 0x5ac894
// 005ac890  8901                 mov dword ptr [ecx], eax
// 005ac892  eb03                 jmp 0x5ac897
// 005ac894  894108               mov dword ptr [ecx + 8], eax
// 005ac897  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005ac89a  894804               mov dword ptr [eax + 4], ecx
// 005ac89d  8d4b14               lea ecx, [ebx + 0x14]
// 005ac8a0  83c014               add eax, 0x14
// 005ac8a3  3bc1                 cmp eax, ecx
// 005ac8a5  7408                 je 0x5ac8af
// 005ac8a7  8a19                 mov bl, byte ptr [ecx]
// 005ac8a9  8a10                 mov dl, byte ptr [eax]
// 005ac8ab  8818                 mov byte ptr [eax], bl
// 005ac8ad  8811                 mov byte ptr [ecx], dl
// 005ac8af  8b542410             mov edx, dword ptr [esp + 0x10]
// 005ac8b3  b301                 mov bl, 1
// 005ac8b5  385a14               cmp byte ptr [edx + 0x14], bl
// 005ac8b8  0f85fd000000         jne 0x5ac9bb
// 005ac8be  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005ac8c1  3b7804               cmp edi, dword ptr [eax + 4]
// 005ac8c4  0f84ee000000         je 0x5ac9b8
// 005ac8ca  8d9b00000000         lea ebx, [ebx]
// 005ac8d0  385f14               cmp byte ptr [edi + 0x14], bl
// 005ac8d3  0f85df000000         jne 0x5ac9b8
// 005ac8d9  8b06                 mov eax, dword ptr [esi]
// 005ac8db  3bf8                 cmp edi, eax
// 005ac8dd  7565                 jne 0x5ac944
// 005ac8df  8b4608               mov eax, dword ptr [esi + 8]
// 005ac8e2  80781400             cmp byte ptr [eax + 0x14], 0
// 005ac8e6  7512                 jne 0x5ac8fa
// 005ac8e8  885814               mov byte ptr [eax + 0x14], bl
// 005ac8eb  56                   push esi
// 005ac8ec  8bcd                 mov ecx, ebp
// 005ac8ee  c6461400             mov byte ptr [esi + 0x14], 0
// 005ac8f2  e829faffff           call 0x5ac320
// 005ac8f7  8b4608               mov eax, dword ptr [esi + 8]
// 005ac8fa  80781500             cmp byte ptr [eax + 0x15], 0
// 005ac8fe  7574                 jne 0x5ac974
// 005ac900  8b08                 mov ecx, dword ptr [eax]
// 005ac902  385914               cmp byte ptr [ecx + 0x14], bl
// 005ac905  7508                 jne 0x5ac90f
// 005ac907  8b5008               mov edx, dword ptr [eax + 8]
// 005ac90a  385a14               cmp byte ptr [edx + 0x14], bl
// 005ac90d  7461                 je 0x5ac970
// 005ac90f  8b4808               mov ecx, dword ptr [eax + 8]
// 005ac912  385914               cmp byte ptr [ecx + 0x14], bl
// 005ac915  7514                 jne 0x5ac92b
// 005ac917  8b10                 mov edx, dword ptr [eax]
// 005ac919  885a14               mov byte ptr [edx + 0x14], bl
// 005ac91c  50                   push eax
// 005ac91d  8bcd                 mov ecx, ebp
// 005ac91f  c6401400             mov byte ptr [eax + 0x14], 0
// 005ac923  e8d8c20100           call 0x5c8c00
// 005ac928  8b4608               mov eax, dword ptr [esi + 8]
// 005ac92b  8a4e14               mov cl, byte ptr [esi + 0x14]
// 005ac92e  884814               mov byte ptr [eax + 0x14], cl
// 005ac931  885e14               mov byte ptr [esi + 0x14], bl
// 005ac934  8b5008               mov edx, dword ptr [eax + 8]
// 005ac937  56                   push esi
// 005ac938  8bcd                 mov ecx, ebp
// 005ac93a  885a14               mov byte ptr [edx + 0x14], bl
// 005ac93d  e8def9ffff           call 0x5ac320
// 005ac942  eb74                 jmp 0x5ac9b8
// 005ac944  80781400             cmp byte ptr [eax + 0x14], 0
// 005ac948  7511                 jne 0x5ac95b
// 005ac94a  885814               mov byte ptr [eax + 0x14], bl
// 005ac94d  56                   push esi
// 005ac94e  8bcd                 mov ecx, ebp
// 005ac950  c6461400             mov byte ptr [esi + 0x14], 0
// 005ac954  e8a7c20100           call 0x5c8c00
// 005ac959  8b06                 mov eax, dword ptr [esi]
// 005ac95b  80781500             cmp byte ptr [eax + 0x15], 0
// 005ac95f  7513                 jne 0x5ac974
// 005ac961  8b4808               mov ecx, dword ptr [eax + 8]
// 005ac964  385914               cmp byte ptr [ecx + 0x14], bl
// 005ac967  751e                 jne 0x5ac987
// 005ac969  8b10                 mov edx, dword ptr [eax]
// 005ac96b  385a14               cmp byte ptr [edx + 0x14], bl
// 005ac96e  7517                 jne 0x5ac987
// 005ac970  c6401400             mov byte ptr [eax + 0x14], 0
// 005ac974  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005ac977  8bfe                 mov edi, esi
// 005ac979  8b7604               mov esi, dword ptr [esi + 4]
// 005ac97c  3b7804               cmp edi, dword ptr [eax + 4]
// 005ac97f  0f854bffffff         jne 0x5ac8d0
// 005ac985  eb31                 jmp 0x5ac9b8
// 005ac987  8b08                 mov ecx, dword ptr [eax]
// 005ac989  385914               cmp byte ptr [ecx + 0x14], bl
// 005ac98c  7514                 jne 0x5ac9a2
// 005ac98e  8b5008               mov edx, dword ptr [eax + 8]
// 005ac991  885a14               mov byte ptr [edx + 0x14], bl
// 005ac994  50                   push eax
// 005ac995  8bcd                 mov ecx, ebp
// 005ac997  c6401400             mov byte ptr [eax + 0x14], 0
// 005ac99b  e880f9ffff           call 0x5ac320
// 005ac9a0  8b06                 mov eax, dword ptr [esi]
// 005ac9a2  8a4e14               mov cl, byte ptr [esi + 0x14]
// 005ac9a5  884814               mov byte ptr [eax + 0x14], cl
// 005ac9a8  885e14               mov byte ptr [esi + 0x14], bl
// 005ac9ab  8b10                 mov edx, dword ptr [eax]
// 005ac9ad  56                   push esi
// 005ac9ae  8bcd                 mov ecx, ebp
// 005ac9b0  885a14               mov byte ptr [edx + 0x14], bl
// 005ac9b3  e848c20100           call 0x5c8c00
// 005ac9b8  885f14               mov byte ptr [edi + 0x14], bl
// 005ac9bb  8b442410             mov eax, dword ptr [esp + 0x10]
// 005ac9bf  50                   push eax
// 005ac9c0  e8d5af1f00           call 0x7a799a
// 005ac9c5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005ac9c8  83c404               add esp, 4
// 005ac9cb  5f                   pop edi
// 005ac9cc  5e                   pop esi
// 005ac9cd  5b                   pop ebx
// 005ac9ce  85c0                 test eax, eax
// 005ac9d0  7604                 jbe 0x5ac9d6
// 005ac9d2  48                   dec eax
// 005ac9d3  89451c               mov dword ptr [ebp + 0x1c], eax
// 005ac9d6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005ac9da  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005ac9de  8b5500               mov edx, dword ptr [ebp]
// 005ac9e1  894804               mov dword ptr [eax + 4], ecx
// 005ac9e4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005ac9e8  8910                 mov dword ptr [eax], edx
// 005ac9ea  5d                   pop ebp
// 005ac9eb  64890d00000000       mov dword ptr fs:[0], ecx
// 005ac9f2  83c454               add esp, 0x54
// 005ac9f5  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
