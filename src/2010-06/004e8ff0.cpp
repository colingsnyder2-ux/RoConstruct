// from server: 100% by auto
// roc 2010-06 004e8ff0  unit: G3D::VRay::?$holder  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e8ff0
//
// 004e8ff0  64a100000000         mov eax, dword ptr fs:[0]
// 004e8ff6  6aff                 push -1
// 004e8ff8  68e22f9a00           push 0x9a2fe2
// 004e8ffd  50                   push eax
// 004e8ffe  64892500000000       mov dword ptr fs:[0], esp
// 004e9005  8b442418             mov eax, dword ptr [esp + 0x18]
// 004e9009  83ec48               sub esp, 0x48
// 004e900c  80781900             cmp byte ptr [eax + 0x19], 0
// 004e9010  55                   push ebp
// 004e9011  8be9                 mov ebp, ecx
// 004e9013  7459                 je 0x4e906e
// 004e9015  688c00a000           push 0xa0008c
// 004e901a  8d4c240c             lea ecx, [esp + 0xc]
// 004e901e  ff1510a49e00         call dword ptr [0x9ea410]
// 004e9024  8d4c2424             lea ecx, [esp + 0x24]
// 004e9028  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004e9030  ff1518a99e00         call dword ptr [0x9ea918]
// 004e9036  8d442408             lea eax, [esp + 8]
// 004e903a  50                   push eax
// 004e903b  8d4c2434             lea ecx, [esp + 0x34]
// 004e903f  c644245801           mov byte ptr [esp + 0x58], 1
// 004e9044  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 004e904c  ff150ca49e00         call dword ptr [0x9ea40c]
// 004e9052  68081bb000           push 0xb01b08
// 004e9057  8d4c2428             lea ecx, [esp + 0x28]
// 004e905b  51                   push ecx
// 004e905c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004e9061  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 004e9069  e844f92b00           call 0x7a89b2
// 004e906e  53                   push ebx
// 004e906f  56                   push esi
// 004e9070  8bd8                 mov ebx, eax
// 004e9072  57                   push edi
// 004e9073  8d4c246c             lea ecx, [esp + 0x6c]
// 004e9077  895c2410             mov dword ptr [esp + 0x10], ebx
// 004e907b  e8b0d9ffff           call 0x4e6a30
// 004e9080  8b0b                 mov ecx, dword ptr [ebx]
// 004e9082  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e9086  7405                 je 0x4e908d
// 004e9088  8b7b08               mov edi, dword ptr [ebx + 8]
// 004e908b  eb1b                 jmp 0x4e90a8
// 004e908d  8b5308               mov edx, dword ptr [ebx + 8]
// 004e9090  807a1900             cmp byte ptr [edx + 0x19], 0
// 004e9094  7404                 je 0x4e909a
// 004e9096  8bf9                 mov edi, ecx
// 004e9098  eb0e                 jmp 0x4e90a8
// 004e909a  8b442470             mov eax, dword ptr [esp + 0x70]
// 004e909e  8b7808               mov edi, dword ptr [eax + 8]
// 004e90a1  8d5008               lea edx, [eax + 8]
// 004e90a4  3bc3                 cmp eax, ebx
// 004e90a6  756b                 jne 0x4e9113
// 004e90a8  807f1900             cmp byte ptr [edi + 0x19], 0
// 004e90ac  8b7304               mov esi, dword ptr [ebx + 4]
// 004e90af  7503                 jne 0x4e90b4
// 004e90b1  897704               mov dword ptr [edi + 4], esi
// 004e90b4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004e90b7  395804               cmp dword ptr [eax + 4], ebx
// 004e90ba  7505                 jne 0x4e90c1
// 004e90bc  897804               mov dword ptr [eax + 4], edi
// 004e90bf  eb0b                 jmp 0x4e90cc
// 004e90c1  391e                 cmp dword ptr [esi], ebx
// 004e90c3  7504                 jne 0x4e90c9
// 004e90c5  893e                 mov dword ptr [esi], edi
// 004e90c7  eb03                 jmp 0x4e90cc
// 004e90c9  897e08               mov dword ptr [esi + 8], edi
// 004e90cc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004e90cf  8b03                 mov eax, dword ptr [ebx]
// 004e90d1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 004e90d5  7515                 jne 0x4e90ec
// 004e90d7  807f1900             cmp byte ptr [edi + 0x19], 0
// 004e90db  7404                 je 0x4e90e1
// 004e90dd  8bc6                 mov eax, esi
// 004e90df  eb09                 jmp 0x4e90ea
// 004e90e1  57                   push edi
// 004e90e2  e8a9c9ffff           call 0x4e5a90
// 004e90e7  83c404               add esp, 4
// 004e90ea  8903                 mov dword ptr [ebx], eax
// 004e90ec  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004e90ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e90f3  394b08               cmp dword ptr [ebx + 8], ecx
// 004e90f6  7577                 jne 0x4e916f
// 004e90f8  807f1900             cmp byte ptr [edi + 0x19], 0
// 004e90fc  7407                 je 0x4e9105
// 004e90fe  8bc6                 mov eax, esi
// 004e9100  894308               mov dword ptr [ebx + 8], eax
// 004e9103  eb6a                 jmp 0x4e916f
// 004e9105  57                   push edi
// 004e9106  e805951000           call 0x5f2610
// 004e910b  83c404               add esp, 4
// 004e910e  894308               mov dword ptr [ebx + 8], eax
// 004e9111  eb5c                 jmp 0x4e916f
// 004e9113  894104               mov dword ptr [ecx + 4], eax
// 004e9116  8b0b                 mov ecx, dword ptr [ebx]
// 004e9118  8908                 mov dword ptr [eax], ecx
// 004e911a  3b4308               cmp eax, dword ptr [ebx + 8]
// 004e911d  7504                 jne 0x4e9123
// 004e911f  8bf0                 mov esi, eax
// 004e9121  eb19                 jmp 0x4e913c
// 004e9123  807f1900             cmp byte ptr [edi + 0x19], 0
// 004e9127  8b7004               mov esi, dword ptr [eax + 4]
// 004e912a  7503                 jne 0x4e912f
// 004e912c  897704               mov dword ptr [edi + 4], esi
// 004e912f  893e                 mov dword ptr [esi], edi
// 004e9131  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004e9134  890a                 mov dword ptr [edx], ecx
// 004e9136  8b5308               mov edx, dword ptr [ebx + 8]
// 004e9139  894204               mov dword ptr [edx + 4], eax
// 004e913c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004e913f  395904               cmp dword ptr [ecx + 4], ebx
// 004e9142  7505                 jne 0x4e9149
// 004e9144  894104               mov dword ptr [ecx + 4], eax
// 004e9147  eb0e                 jmp 0x4e9157
// 004e9149  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004e914c  3919                 cmp dword ptr [ecx], ebx
// 004e914e  7504                 jne 0x4e9154
// 004e9150  8901                 mov dword ptr [ecx], eax
// 004e9152  eb03                 jmp 0x4e9157
// 004e9154  894108               mov dword ptr [ecx + 8], eax
// 004e9157  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004e915a  894804               mov dword ptr [eax + 4], ecx
// 004e915d  8d4b18               lea ecx, [ebx + 0x18]
// 004e9160  83c018               add eax, 0x18
// 004e9163  3bc1                 cmp eax, ecx
// 004e9165  7408                 je 0x4e916f
// 004e9167  8a19                 mov bl, byte ptr [ecx]
// 004e9169  8a10                 mov dl, byte ptr [eax]
// 004e916b  8818                 mov byte ptr [eax], bl
// 004e916d  8811                 mov byte ptr [ecx], dl
// 004e916f  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e9173  b301                 mov bl, 1
// 004e9175  385a18               cmp byte ptr [edx + 0x18], bl
// 004e9178  0f85fd000000         jne 0x4e927b
// 004e917e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004e9181  3b7804               cmp edi, dword ptr [eax + 4]
// 004e9184  0f84ee000000         je 0x4e9278
// 004e918a  8d9b00000000         lea ebx, [ebx]
// 004e9190  385f18               cmp byte ptr [edi + 0x18], bl
// 004e9193  0f85df000000         jne 0x4e9278
// 004e9199  8b06                 mov eax, dword ptr [esi]
// 004e919b  3bf8                 cmp edi, eax
// 004e919d  7565                 jne 0x4e9204
// 004e919f  8b4608               mov eax, dword ptr [esi + 8]
// 004e91a2  80781800             cmp byte ptr [eax + 0x18], 0
// 004e91a6  7512                 jne 0x4e91ba
// 004e91a8  885818               mov byte ptr [eax + 0x18], bl
// 004e91ab  56                   push esi
// 004e91ac  8bcd                 mov ecx, ebp
// 004e91ae  c6461800             mov byte ptr [esi + 0x18], 0
// 004e91b2  e829d7ffff           call 0x4e68e0
// 004e91b7  8b4608               mov eax, dword ptr [esi + 8]
// 004e91ba  80781900             cmp byte ptr [eax + 0x19], 0
// 004e91be  7574                 jne 0x4e9234
// 004e91c0  8b08                 mov ecx, dword ptr [eax]
// 004e91c2  385918               cmp byte ptr [ecx + 0x18], bl
// 004e91c5  7508                 jne 0x4e91cf
// 004e91c7  8b5008               mov edx, dword ptr [eax + 8]
// 004e91ca  385a18               cmp byte ptr [edx + 0x18], bl
// 004e91cd  7461                 je 0x4e9230
// 004e91cf  8b4808               mov ecx, dword ptr [eax + 8]
// 004e91d2  385918               cmp byte ptr [ecx + 0x18], bl
// 004e91d5  7514                 jne 0x4e91eb
// 004e91d7  8b10                 mov edx, dword ptr [eax]
// 004e91d9  885a18               mov byte ptr [edx + 0x18], bl
// 004e91dc  50                   push eax
// 004e91dd  8bcd                 mov ecx, ebp
// 004e91df  c6401800             mov byte ptr [eax + 0x18], 0
// 004e91e3  e8c8931000           call 0x5f25b0
// 004e91e8  8b4608               mov eax, dword ptr [esi + 8]
// 004e91eb  8a4e18               mov cl, byte ptr [esi + 0x18]
// 004e91ee  884818               mov byte ptr [eax + 0x18], cl
// 004e91f1  885e18               mov byte ptr [esi + 0x18], bl
// 004e91f4  8b5008               mov edx, dword ptr [eax + 8]
// 004e91f7  56                   push esi
// 004e91f8  8bcd                 mov ecx, ebp
// 004e91fa  885a18               mov byte ptr [edx + 0x18], bl
// 004e91fd  e8ded6ffff           call 0x4e68e0
// 004e9202  eb74                 jmp 0x4e9278
// 004e9204  80781800             cmp byte ptr [eax + 0x18], 0
// 004e9208  7511                 jne 0x4e921b
// 004e920a  885818               mov byte ptr [eax + 0x18], bl
// 004e920d  56                   push esi
// 004e920e  8bcd                 mov ecx, ebp
// 004e9210  c6461800             mov byte ptr [esi + 0x18], 0
// 004e9214  e897931000           call 0x5f25b0
// 004e9219  8b06                 mov eax, dword ptr [esi]
// 004e921b  80781900             cmp byte ptr [eax + 0x19], 0
// 004e921f  7513                 jne 0x4e9234
// 004e9221  8b4808               mov ecx, dword ptr [eax + 8]
// 004e9224  385918               cmp byte ptr [ecx + 0x18], bl
// 004e9227  751e                 jne 0x4e9247
// 004e9229  8b10                 mov edx, dword ptr [eax]
// 004e922b  385a18               cmp byte ptr [edx + 0x18], bl
// 004e922e  7517                 jne 0x4e9247
// 004e9230  c6401800             mov byte ptr [eax + 0x18], 0
// 004e9234  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004e9237  8bfe                 mov edi, esi
// 004e9239  8b7604               mov esi, dword ptr [esi + 4]
// 004e923c  3b7804               cmp edi, dword ptr [eax + 4]
// 004e923f  0f854bffffff         jne 0x4e9190
// 004e9245  eb31                 jmp 0x4e9278
// 004e9247  8b08                 mov ecx, dword ptr [eax]
// 004e9249  385918               cmp byte ptr [ecx + 0x18], bl
// 004e924c  7514                 jne 0x4e9262
// 004e924e  8b5008               mov edx, dword ptr [eax + 8]
// 004e9251  885a18               mov byte ptr [edx + 0x18], bl
// 004e9254  50                   push eax
// 004e9255  8bcd                 mov ecx, ebp
// 004e9257  c6401800             mov byte ptr [eax + 0x18], 0
// 004e925b  e880d6ffff           call 0x4e68e0
// 004e9260  8b06                 mov eax, dword ptr [esi]
// 004e9262  8a4e18               mov cl, byte ptr [esi + 0x18]
// 004e9265  884818               mov byte ptr [eax + 0x18], cl
// 004e9268  885e18               mov byte ptr [esi + 0x18], bl
// 004e926b  8b10                 mov edx, dword ptr [eax]
// 004e926d  56                   push esi
// 004e926e  8bcd                 mov ecx, ebp
// 004e9270  885a18               mov byte ptr [edx + 0x18], bl
// 004e9273  e838931000           call 0x5f25b0
// 004e9278  885f18               mov byte ptr [edi + 0x18], bl
// 004e927b  8b442410             mov eax, dword ptr [esp + 0x10]
// 004e927f  50                   push eax
// 004e9280  e815e72b00           call 0x7a799a
// 004e9285  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004e9288  83c404               add esp, 4
// 004e928b  5f                   pop edi
// 004e928c  5e                   pop esi
// 004e928d  5b                   pop ebx
// 004e928e  85c0                 test eax, eax
// 004e9290  7604                 jbe 0x4e9296
// 004e9292  48                   dec eax
// 004e9293  89451c               mov dword ptr [ebp + 0x1c], eax
// 004e9296  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004e929a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004e929e  8b5500               mov edx, dword ptr [ebp]
// 004e92a1  894804               mov dword ptr [eax + 4], ecx
// 004e92a4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e92a8  8910                 mov dword ptr [eax], edx
// 004e92aa  5d                   pop ebp
// 004e92ab  64890d00000000       mov dword ptr fs:[0], ecx
// 004e92b2  83c454               add esp, 0x54
// 004e92b5  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
