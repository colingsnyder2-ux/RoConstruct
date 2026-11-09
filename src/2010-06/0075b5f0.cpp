// from server: 100% by auto
// roc 2010-06 0075b5f0  unit: RBX::ParallelRampPoly  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075b5f0
//
// 0075b5f0  64a100000000         mov eax, dword ptr fs:[0]
// 0075b5f6  6aff                 push -1
// 0075b5f8  68e22f9a00           push 0x9a2fe2
// 0075b5fd  50                   push eax
// 0075b5fe  64892500000000       mov dword ptr fs:[0], esp
// 0075b605  8b442418             mov eax, dword ptr [esp + 0x18]
// 0075b609  83ec48               sub esp, 0x48
// 0075b60c  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b610  55                   push ebp
// 0075b611  8be9                 mov ebp, ecx
// 0075b613  7459                 je 0x75b66e
// 0075b615  688c00a000           push 0xa0008c
// 0075b61a  8d4c240c             lea ecx, [esp + 0xc]
// 0075b61e  ff1510a49e00         call dword ptr [0x9ea410]
// 0075b624  8d4c2424             lea ecx, [esp + 0x24]
// 0075b628  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0075b630  ff1518a99e00         call dword ptr [0x9ea918]
// 0075b636  8d442408             lea eax, [esp + 8]
// 0075b63a  50                   push eax
// 0075b63b  8d4c2434             lea ecx, [esp + 0x34]
// 0075b63f  c644245801           mov byte ptr [esp + 0x58], 1
// 0075b644  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 0075b64c  ff150ca49e00         call dword ptr [0x9ea40c]
// 0075b652  68081bb000           push 0xb01b08
// 0075b657  8d4c2428             lea ecx, [esp + 0x28]
// 0075b65b  51                   push ecx
// 0075b65c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0075b661  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 0075b669  e844d30400           call 0x7a89b2
// 0075b66e  53                   push ebx
// 0075b66f  56                   push esi
// 0075b670  8bd8                 mov ebx, eax
// 0075b672  57                   push edi
// 0075b673  8d4c246c             lea ecx, [esp + 0x6c]
// 0075b677  895c2410             mov dword ptr [esp + 0x10], ebx
// 0075b67b  e8502ce3ff           call 0x58e2d0
// 0075b680  8b0b                 mov ecx, dword ptr [ebx]
// 0075b682  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0075b686  7405                 je 0x75b68d
// 0075b688  8b7b08               mov edi, dword ptr [ebx + 8]
// 0075b68b  eb1b                 jmp 0x75b6a8
// 0075b68d  8b5308               mov edx, dword ptr [ebx + 8]
// 0075b690  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0075b694  7404                 je 0x75b69a
// 0075b696  8bf9                 mov edi, ecx
// 0075b698  eb0e                 jmp 0x75b6a8
// 0075b69a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0075b69e  8b7808               mov edi, dword ptr [eax + 8]
// 0075b6a1  8d5008               lea edx, [eax + 8]
// 0075b6a4  3bc3                 cmp eax, ebx
// 0075b6a6  756b                 jne 0x75b713
// 0075b6a8  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0075b6ac  8b7304               mov esi, dword ptr [ebx + 4]
// 0075b6af  7503                 jne 0x75b6b4
// 0075b6b1  897704               mov dword ptr [edi + 4], esi
// 0075b6b4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0075b6b7  395804               cmp dword ptr [eax + 4], ebx
// 0075b6ba  7505                 jne 0x75b6c1
// 0075b6bc  897804               mov dword ptr [eax + 4], edi
// 0075b6bf  eb0b                 jmp 0x75b6cc
// 0075b6c1  391e                 cmp dword ptr [esi], ebx
// 0075b6c3  7504                 jne 0x75b6c9
// 0075b6c5  893e                 mov dword ptr [esi], edi
// 0075b6c7  eb03                 jmp 0x75b6cc
// 0075b6c9  897e08               mov dword ptr [esi + 8], edi
// 0075b6cc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0075b6cf  8b03                 mov eax, dword ptr [ebx]
// 0075b6d1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0075b6d5  7515                 jne 0x75b6ec
// 0075b6d7  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0075b6db  7404                 je 0x75b6e1
// 0075b6dd  8bc6                 mov eax, esi
// 0075b6df  eb09                 jmp 0x75b6ea
// 0075b6e1  57                   push edi
// 0075b6e2  e8c92be3ff           call 0x58e2b0
// 0075b6e7  83c404               add esp, 4
// 0075b6ea  8903                 mov dword ptr [ebx], eax
// 0075b6ec  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0075b6ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0075b6f3  394b08               cmp dword ptr [ebx + 8], ecx
// 0075b6f6  7577                 jne 0x75b76f
// 0075b6f8  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0075b6fc  7407                 je 0x75b705
// 0075b6fe  8bc6                 mov eax, esi
// 0075b700  894308               mov dword ptr [ebx + 8], eax
// 0075b703  eb6a                 jmp 0x75b76f
// 0075b705  57                   push edi
// 0075b706  e835f3ffff           call 0x75aa40
// 0075b70b  83c404               add esp, 4
// 0075b70e  894308               mov dword ptr [ebx + 8], eax
// 0075b711  eb5c                 jmp 0x75b76f
// 0075b713  894104               mov dword ptr [ecx + 4], eax
// 0075b716  8b0b                 mov ecx, dword ptr [ebx]
// 0075b718  8908                 mov dword ptr [eax], ecx
// 0075b71a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0075b71d  7504                 jne 0x75b723
// 0075b71f  8bf0                 mov esi, eax
// 0075b721  eb19                 jmp 0x75b73c
// 0075b723  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0075b727  8b7004               mov esi, dword ptr [eax + 4]
// 0075b72a  7503                 jne 0x75b72f
// 0075b72c  897704               mov dword ptr [edi + 4], esi
// 0075b72f  893e                 mov dword ptr [esi], edi
// 0075b731  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0075b734  890a                 mov dword ptr [edx], ecx
// 0075b736  8b5308               mov edx, dword ptr [ebx + 8]
// 0075b739  894204               mov dword ptr [edx + 4], eax
// 0075b73c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0075b73f  395904               cmp dword ptr [ecx + 4], ebx
// 0075b742  7505                 jne 0x75b749
// 0075b744  894104               mov dword ptr [ecx + 4], eax
// 0075b747  eb0e                 jmp 0x75b757
// 0075b749  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0075b74c  3919                 cmp dword ptr [ecx], ebx
// 0075b74e  7504                 jne 0x75b754
// 0075b750  8901                 mov dword ptr [ecx], eax
// 0075b752  eb03                 jmp 0x75b757
// 0075b754  894108               mov dword ptr [ecx + 8], eax
// 0075b757  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0075b75a  894804               mov dword ptr [eax + 4], ecx
// 0075b75d  8d4b1c               lea ecx, [ebx + 0x1c]
// 0075b760  83c01c               add eax, 0x1c
// 0075b763  3bc1                 cmp eax, ecx
// 0075b765  7408                 je 0x75b76f
// 0075b767  8a19                 mov bl, byte ptr [ecx]
// 0075b769  8a10                 mov dl, byte ptr [eax]
// 0075b76b  8818                 mov byte ptr [eax], bl
// 0075b76d  8811                 mov byte ptr [ecx], dl
// 0075b76f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0075b773  b301                 mov bl, 1
// 0075b775  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0075b778  0f85fd000000         jne 0x75b87b
// 0075b77e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0075b781  3b7804               cmp edi, dword ptr [eax + 4]
// 0075b784  0f84ee000000         je 0x75b878
// 0075b78a  8d9b00000000         lea ebx, [ebx]
// 0075b790  385f1c               cmp byte ptr [edi + 0x1c], bl
// 0075b793  0f85df000000         jne 0x75b878
// 0075b799  8b06                 mov eax, dword ptr [esi]
// 0075b79b  3bf8                 cmp edi, eax
// 0075b79d  7565                 jne 0x75b804
// 0075b79f  8b4608               mov eax, dword ptr [esi + 8]
// 0075b7a2  80781c00             cmp byte ptr [eax + 0x1c], 0
// 0075b7a6  7512                 jne 0x75b7ba
// 0075b7a8  88581c               mov byte ptr [eax + 0x1c], bl
// 0075b7ab  56                   push esi
// 0075b7ac  8bcd                 mov ecx, ebp
// 0075b7ae  c6461c00             mov byte ptr [esi + 0x1c], 0
// 0075b7b2  e859fdffff           call 0x75b510
// 0075b7b7  8b4608               mov eax, dword ptr [esi + 8]
// 0075b7ba  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b7be  7574                 jne 0x75b834
// 0075b7c0  8b08                 mov ecx, dword ptr [eax]
// 0075b7c2  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0075b7c5  7508                 jne 0x75b7cf
// 0075b7c7  8b5008               mov edx, dword ptr [eax + 8]
// 0075b7ca  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0075b7cd  7461                 je 0x75b830
// 0075b7cf  8b4808               mov ecx, dword ptr [eax + 8]
// 0075b7d2  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0075b7d5  7514                 jne 0x75b7eb
// 0075b7d7  8b10                 mov edx, dword ptr [eax]
// 0075b7d9  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075b7dc  50                   push eax
// 0075b7dd  8bcd                 mov ecx, ebp
// 0075b7df  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0075b7e3  e8289fffff           call 0x755710
// 0075b7e8  8b4608               mov eax, dword ptr [esi + 8]
// 0075b7eb  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 0075b7ee  88481c               mov byte ptr [eax + 0x1c], cl
// 0075b7f1  885e1c               mov byte ptr [esi + 0x1c], bl
// 0075b7f4  8b5008               mov edx, dword ptr [eax + 8]
// 0075b7f7  56                   push esi
// 0075b7f8  8bcd                 mov ecx, ebp
// 0075b7fa  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075b7fd  e80efdffff           call 0x75b510
// 0075b802  eb74                 jmp 0x75b878
// 0075b804  80781c00             cmp byte ptr [eax + 0x1c], 0
// 0075b808  7511                 jne 0x75b81b
// 0075b80a  88581c               mov byte ptr [eax + 0x1c], bl
// 0075b80d  56                   push esi
// 0075b80e  8bcd                 mov ecx, ebp
// 0075b810  c6461c00             mov byte ptr [esi + 0x1c], 0
// 0075b814  e8f79effff           call 0x755710
// 0075b819  8b06                 mov eax, dword ptr [esi]
// 0075b81b  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b81f  7513                 jne 0x75b834
// 0075b821  8b4808               mov ecx, dword ptr [eax + 8]
// 0075b824  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0075b827  751e                 jne 0x75b847
// 0075b829  8b10                 mov edx, dword ptr [eax]
// 0075b82b  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0075b82e  7517                 jne 0x75b847
// 0075b830  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0075b834  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0075b837  8bfe                 mov edi, esi
// 0075b839  8b7604               mov esi, dword ptr [esi + 4]
// 0075b83c  3b7804               cmp edi, dword ptr [eax + 4]
// 0075b83f  0f854bffffff         jne 0x75b790
// 0075b845  eb31                 jmp 0x75b878
// 0075b847  8b08                 mov ecx, dword ptr [eax]
// 0075b849  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0075b84c  7514                 jne 0x75b862
// 0075b84e  8b5008               mov edx, dword ptr [eax + 8]
// 0075b851  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075b854  50                   push eax
// 0075b855  8bcd                 mov ecx, ebp
// 0075b857  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0075b85b  e8b0fcffff           call 0x75b510
// 0075b860  8b06                 mov eax, dword ptr [esi]
// 0075b862  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 0075b865  88481c               mov byte ptr [eax + 0x1c], cl
// 0075b868  885e1c               mov byte ptr [esi + 0x1c], bl
// 0075b86b  8b10                 mov edx, dword ptr [eax]
// 0075b86d  56                   push esi
// 0075b86e  8bcd                 mov ecx, ebp
// 0075b870  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075b873  e8989effff           call 0x755710
// 0075b878  885f1c               mov byte ptr [edi + 0x1c], bl
// 0075b87b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0075b87f  50                   push eax
// 0075b880  e815c10400           call 0x7a799a
// 0075b885  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0075b888  83c404               add esp, 4
// 0075b88b  5f                   pop edi
// 0075b88c  5e                   pop esi
// 0075b88d  5b                   pop ebx
// 0075b88e  85c0                 test eax, eax
// 0075b890  7604                 jbe 0x75b896
// 0075b892  48                   dec eax
// 0075b893  89451c               mov dword ptr [ebp + 0x1c], eax
// 0075b896  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0075b89a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0075b89e  8b5500               mov edx, dword ptr [ebp]
// 0075b8a1  894804               mov dword ptr [eax + 4], ecx
// 0075b8a4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0075b8a8  8910                 mov dword ptr [eax], edx
// 0075b8aa  5d                   pop ebp
// 0075b8ab  64890d00000000       mov dword ptr fs:[0], ecx
// 0075b8b2  83c454               add esp, 0x54
// 0075b8b5  c20c00               ret 0xc
// standard library set<pod16> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
