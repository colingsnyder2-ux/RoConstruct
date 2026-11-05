// from server: 100% by auto
// roc 2010-06 008e36c0  unit: RBX::RbxTextureProxy  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e36c0
//
// 008e36c0  64a100000000         mov eax, dword ptr fs:[0]
// 008e36c6  6aff                 push -1
// 008e36c8  68e22f9a00           push 0x9a2fe2
// 008e36cd  50                   push eax
// 008e36ce  64892500000000       mov dword ptr fs:[0], esp
// 008e36d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e36d9  83ec48               sub esp, 0x48
// 008e36dc  80782100             cmp byte ptr [eax + 0x21], 0
// 008e36e0  55                   push ebp
// 008e36e1  8be9                 mov ebp, ecx
// 008e36e3  7459                 je 0x8e373e
// 008e36e5  688c00a000           push 0xa0008c
// 008e36ea  8d4c240c             lea ecx, [esp + 0xc]
// 008e36ee  ff1510a49e00         call dword ptr [0x9ea410]
// 008e36f4  8d4c2424             lea ecx, [esp + 0x24]
// 008e36f8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 008e3700  ff1518a99e00         call dword ptr [0x9ea918]
// 008e3706  8d442408             lea eax, [esp + 8]
// 008e370a  50                   push eax
// 008e370b  8d4c2434             lea ecx, [esp + 0x34]
// 008e370f  c644245801           mov byte ptr [esp + 0x58], 1
// 008e3714  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 008e371c  ff150ca49e00         call dword ptr [0x9ea40c]
// 008e3722  68081bb000           push 0xb01b08
// 008e3727  8d4c2428             lea ecx, [esp + 0x28]
// 008e372b  51                   push ecx
// 008e372c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 008e3731  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 008e3739  e87452ecff           call 0x7a89b2
// 008e373e  53                   push ebx
// 008e373f  56                   push esi
// 008e3740  8bd8                 mov ebx, eax
// 008e3742  57                   push edi
// 008e3743  8d4c246c             lea ecx, [esp + 0x6c]
// 008e3747  895c2410             mov dword ptr [esp + 0x10], ebx
// 008e374b  e8b079d3ff           call 0x61b100
// 008e3750  8b0b                 mov ecx, dword ptr [ebx]
// 008e3752  80792100             cmp byte ptr [ecx + 0x21], 0
// 008e3756  7405                 je 0x8e375d
// 008e3758  8b7b08               mov edi, dword ptr [ebx + 8]
// 008e375b  eb1b                 jmp 0x8e3778
// 008e375d  8b5308               mov edx, dword ptr [ebx + 8]
// 008e3760  807a2100             cmp byte ptr [edx + 0x21], 0
// 008e3764  7404                 je 0x8e376a
// 008e3766  8bf9                 mov edi, ecx
// 008e3768  eb0e                 jmp 0x8e3778
// 008e376a  8b442470             mov eax, dword ptr [esp + 0x70]
// 008e376e  8b7808               mov edi, dword ptr [eax + 8]
// 008e3771  8d5008               lea edx, [eax + 8]
// 008e3774  3bc3                 cmp eax, ebx
// 008e3776  756b                 jne 0x8e37e3
// 008e3778  807f2100             cmp byte ptr [edi + 0x21], 0
// 008e377c  8b7304               mov esi, dword ptr [ebx + 4]
// 008e377f  7503                 jne 0x8e3784
// 008e3781  897704               mov dword ptr [edi + 4], esi
// 008e3784  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008e3787  395804               cmp dword ptr [eax + 4], ebx
// 008e378a  7505                 jne 0x8e3791
// 008e378c  897804               mov dword ptr [eax + 4], edi
// 008e378f  eb0b                 jmp 0x8e379c
// 008e3791  391e                 cmp dword ptr [esi], ebx
// 008e3793  7504                 jne 0x8e3799
// 008e3795  893e                 mov dword ptr [esi], edi
// 008e3797  eb03                 jmp 0x8e379c
// 008e3799  897e08               mov dword ptr [esi + 8], edi
// 008e379c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 008e379f  8b03                 mov eax, dword ptr [ebx]
// 008e37a1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 008e37a5  7515                 jne 0x8e37bc
// 008e37a7  807f2100             cmp byte ptr [edi + 0x21], 0
// 008e37ab  7404                 je 0x8e37b1
// 008e37ad  8bc6                 mov eax, esi
// 008e37af  eb09                 jmp 0x8e37ba
// 008e37b1  57                   push edi
// 008e37b2  e89933c4ff           call 0x526b50
// 008e37b7  83c404               add esp, 4
// 008e37ba  8903                 mov dword ptr [ebx], eax
// 008e37bc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 008e37bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e37c3  394b08               cmp dword ptr [ebx + 8], ecx
// 008e37c6  7577                 jne 0x8e383f
// 008e37c8  807f2100             cmp byte ptr [edi + 0x21], 0
// 008e37cc  7407                 je 0x8e37d5
// 008e37ce  8bc6                 mov eax, esi
// 008e37d0  894308               mov dword ptr [ebx + 8], eax
// 008e37d3  eb6a                 jmp 0x8e383f
// 008e37d5  57                   push edi
// 008e37d6  e8a578d3ff           call 0x61b080
// 008e37db  83c404               add esp, 4
// 008e37de  894308               mov dword ptr [ebx + 8], eax
// 008e37e1  eb5c                 jmp 0x8e383f
// 008e37e3  894104               mov dword ptr [ecx + 4], eax
// 008e37e6  8b0b                 mov ecx, dword ptr [ebx]
// 008e37e8  8908                 mov dword ptr [eax], ecx
// 008e37ea  3b4308               cmp eax, dword ptr [ebx + 8]
// 008e37ed  7504                 jne 0x8e37f3
// 008e37ef  8bf0                 mov esi, eax
// 008e37f1  eb19                 jmp 0x8e380c
// 008e37f3  807f2100             cmp byte ptr [edi + 0x21], 0
// 008e37f7  8b7004               mov esi, dword ptr [eax + 4]
// 008e37fa  7503                 jne 0x8e37ff
// 008e37fc  897704               mov dword ptr [edi + 4], esi
// 008e37ff  893e                 mov dword ptr [esi], edi
// 008e3801  8b4b08               mov ecx, dword ptr [ebx + 8]
// 008e3804  890a                 mov dword ptr [edx], ecx
// 008e3806  8b5308               mov edx, dword ptr [ebx + 8]
// 008e3809  894204               mov dword ptr [edx + 4], eax
// 008e380c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 008e380f  395904               cmp dword ptr [ecx + 4], ebx
// 008e3812  7505                 jne 0x8e3819
// 008e3814  894104               mov dword ptr [ecx + 4], eax
// 008e3817  eb0e                 jmp 0x8e3827
// 008e3819  8b4b04               mov ecx, dword ptr [ebx + 4]
// 008e381c  3919                 cmp dword ptr [ecx], ebx
// 008e381e  7504                 jne 0x8e3824
// 008e3820  8901                 mov dword ptr [ecx], eax
// 008e3822  eb03                 jmp 0x8e3827
// 008e3824  894108               mov dword ptr [ecx + 8], eax
// 008e3827  8b4b04               mov ecx, dword ptr [ebx + 4]
// 008e382a  894804               mov dword ptr [eax + 4], ecx
// 008e382d  8d4b20               lea ecx, [ebx + 0x20]
// 008e3830  83c020               add eax, 0x20
// 008e3833  3bc1                 cmp eax, ecx
// 008e3835  7408                 je 0x8e383f
// 008e3837  8a19                 mov bl, byte ptr [ecx]
// 008e3839  8a10                 mov dl, byte ptr [eax]
// 008e383b  8818                 mov byte ptr [eax], bl
// 008e383d  8811                 mov byte ptr [ecx], dl
// 008e383f  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e3843  b301                 mov bl, 1
// 008e3845  385a20               cmp byte ptr [edx + 0x20], bl
// 008e3848  0f85fd000000         jne 0x8e394b
// 008e384e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008e3851  3b7804               cmp edi, dword ptr [eax + 4]
// 008e3854  0f84ee000000         je 0x8e3948
// 008e385a  8d9b00000000         lea ebx, [ebx]
// 008e3860  385f20               cmp byte ptr [edi + 0x20], bl
// 008e3863  0f85df000000         jne 0x8e3948
// 008e3869  8b06                 mov eax, dword ptr [esi]
// 008e386b  3bf8                 cmp edi, eax
// 008e386d  7565                 jne 0x8e38d4
// 008e386f  8b4608               mov eax, dword ptr [esi + 8]
// 008e3872  80782000             cmp byte ptr [eax + 0x20], 0
// 008e3876  7512                 jne 0x8e388a
// 008e3878  885820               mov byte ptr [eax + 0x20], bl
// 008e387b  56                   push esi
// 008e387c  8bcd                 mov ecx, ebp
// 008e387e  c6462000             mov byte ptr [esi + 0x20], 0
// 008e3882  e82998c4ff           call 0x52d0b0
// 008e3887  8b4608               mov eax, dword ptr [esi + 8]
// 008e388a  80782100             cmp byte ptr [eax + 0x21], 0
// 008e388e  7574                 jne 0x8e3904
// 008e3890  8b08                 mov ecx, dword ptr [eax]
// 008e3892  385920               cmp byte ptr [ecx + 0x20], bl
// 008e3895  7508                 jne 0x8e389f
// 008e3897  8b5008               mov edx, dword ptr [eax + 8]
// 008e389a  385a20               cmp byte ptr [edx + 0x20], bl
// 008e389d  7461                 je 0x8e3900
// 008e389f  8b4808               mov ecx, dword ptr [eax + 8]
// 008e38a2  385920               cmp byte ptr [ecx + 0x20], bl
// 008e38a5  7514                 jne 0x8e38bb
// 008e38a7  8b10                 mov edx, dword ptr [eax]
// 008e38a9  885a20               mov byte ptr [edx + 0x20], bl
// 008e38ac  50                   push eax
// 008e38ad  8bcd                 mov ecx, ebp
// 008e38af  c6402000             mov byte ptr [eax + 0x20], 0
// 008e38b3  e8e877d3ff           call 0x61b0a0
// 008e38b8  8b4608               mov eax, dword ptr [esi + 8]
// 008e38bb  8a4e20               mov cl, byte ptr [esi + 0x20]
// 008e38be  884820               mov byte ptr [eax + 0x20], cl
// 008e38c1  885e20               mov byte ptr [esi + 0x20], bl
// 008e38c4  8b5008               mov edx, dword ptr [eax + 8]
// 008e38c7  56                   push esi
// 008e38c8  8bcd                 mov ecx, ebp
// 008e38ca  885a20               mov byte ptr [edx + 0x20], bl
// 008e38cd  e8de97c4ff           call 0x52d0b0
// 008e38d2  eb74                 jmp 0x8e3948
// 008e38d4  80782000             cmp byte ptr [eax + 0x20], 0
// 008e38d8  7511                 jne 0x8e38eb
// 008e38da  885820               mov byte ptr [eax + 0x20], bl
// 008e38dd  56                   push esi
// 008e38de  8bcd                 mov ecx, ebp
// 008e38e0  c6462000             mov byte ptr [esi + 0x20], 0
// 008e38e4  e8b777d3ff           call 0x61b0a0
// 008e38e9  8b06                 mov eax, dword ptr [esi]
// 008e38eb  80782100             cmp byte ptr [eax + 0x21], 0
// 008e38ef  7513                 jne 0x8e3904
// 008e38f1  8b4808               mov ecx, dword ptr [eax + 8]
// 008e38f4  385920               cmp byte ptr [ecx + 0x20], bl
// 008e38f7  751e                 jne 0x8e3917
// 008e38f9  8b10                 mov edx, dword ptr [eax]
// 008e38fb  385a20               cmp byte ptr [edx + 0x20], bl
// 008e38fe  7517                 jne 0x8e3917
// 008e3900  c6402000             mov byte ptr [eax + 0x20], 0
// 008e3904  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008e3907  8bfe                 mov edi, esi
// 008e3909  8b7604               mov esi, dword ptr [esi + 4]
// 008e390c  3b7804               cmp edi, dword ptr [eax + 4]
// 008e390f  0f854bffffff         jne 0x8e3860
// 008e3915  eb31                 jmp 0x8e3948
// 008e3917  8b08                 mov ecx, dword ptr [eax]
// 008e3919  385920               cmp byte ptr [ecx + 0x20], bl
// 008e391c  7514                 jne 0x8e3932
// 008e391e  8b5008               mov edx, dword ptr [eax + 8]
// 008e3921  885a20               mov byte ptr [edx + 0x20], bl
// 008e3924  50                   push eax
// 008e3925  8bcd                 mov ecx, ebp
// 008e3927  c6402000             mov byte ptr [eax + 0x20], 0
// 008e392b  e88097c4ff           call 0x52d0b0
// 008e3930  8b06                 mov eax, dword ptr [esi]
// 008e3932  8a4e20               mov cl, byte ptr [esi + 0x20]
// 008e3935  884820               mov byte ptr [eax + 0x20], cl
// 008e3938  885e20               mov byte ptr [esi + 0x20], bl
// 008e393b  8b10                 mov edx, dword ptr [eax]
// 008e393d  56                   push esi
// 008e393e  8bcd                 mov ecx, ebp
// 008e3940  885a20               mov byte ptr [edx + 0x20], bl
// 008e3943  e85877d3ff           call 0x61b0a0
// 008e3948  885f20               mov byte ptr [edi + 0x20], bl
// 008e394b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e394f  50                   push eax
// 008e3950  e84540ecff           call 0x7a799a
// 008e3955  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 008e3958  83c404               add esp, 4
// 008e395b  5f                   pop edi
// 008e395c  5e                   pop esi
// 008e395d  5b                   pop ebx
// 008e395e  85c0                 test eax, eax
// 008e3960  7604                 jbe 0x8e3966
// 008e3962  48                   dec eax
// 008e3963  89451c               mov dword ptr [ebp + 0x1c], eax
// 008e3966  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 008e396a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 008e396e  8b5500               mov edx, dword ptr [ebp]
// 008e3971  894804               mov dword ptr [eax + 4], ecx
// 008e3974  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008e3978  8910                 mov dword ptr [eax], edx
// 008e397a  5d                   pop ebp
// 008e397b  64890d00000000       mov dword ptr fs:[0], ecx
// 008e3982  83c454               add esp, 0x54
// 008e3985  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
