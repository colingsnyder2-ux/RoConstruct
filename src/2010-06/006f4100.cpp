// from server: 100% by auto
// roc 2010-06 006f4100  unit: RBX::VStudioTool::?$EventDesc  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f4100
//
// 006f4100  64a100000000         mov eax, dword ptr fs:[0]
// 006f4106  6aff                 push -1
// 006f4108  68e22f9a00           push 0x9a2fe2
// 006f410d  50                   push eax
// 006f410e  64892500000000       mov dword ptr fs:[0], esp
// 006f4115  8b442418             mov eax, dword ptr [esp + 0x18]
// 006f4119  83ec48               sub esp, 0x48
// 006f411c  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f4120  55                   push ebp
// 006f4121  8be9                 mov ebp, ecx
// 006f4123  7459                 je 0x6f417e
// 006f4125  688c00a000           push 0xa0008c
// 006f412a  8d4c240c             lea ecx, [esp + 0xc]
// 006f412e  ff1510a49e00         call dword ptr [0x9ea410]
// 006f4134  8d4c2424             lea ecx, [esp + 0x24]
// 006f4138  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006f4140  ff1518a99e00         call dword ptr [0x9ea918]
// 006f4146  8d442408             lea eax, [esp + 8]
// 006f414a  50                   push eax
// 006f414b  8d4c2434             lea ecx, [esp + 0x34]
// 006f414f  c644245801           mov byte ptr [esp + 0x58], 1
// 006f4154  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 006f415c  ff150ca49e00         call dword ptr [0x9ea40c]
// 006f4162  68081bb000           push 0xb01b08
// 006f4167  8d4c2428             lea ecx, [esp + 0x28]
// 006f416b  51                   push ecx
// 006f416c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 006f4171  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 006f4179  e834480b00           call 0x7a89b2
// 006f417e  53                   push ebx
// 006f417f  56                   push esi
// 006f4180  8bd8                 mov ebx, eax
// 006f4182  57                   push edi
// 006f4183  8d4c246c             lea ecx, [esp + 0x6c]
// 006f4187  895c2410             mov dword ptr [esp + 0x10], ebx
// 006f418b  e860fbffff           call 0x6f3cf0
// 006f4190  8b0b                 mov ecx, dword ptr [ebx]
// 006f4192  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f4196  7405                 je 0x6f419d
// 006f4198  8b7b08               mov edi, dword ptr [ebx + 8]
// 006f419b  eb1b                 jmp 0x6f41b8
// 006f419d  8b5308               mov edx, dword ptr [ebx + 8]
// 006f41a0  807a0e00             cmp byte ptr [edx + 0xe], 0
// 006f41a4  7404                 je 0x6f41aa
// 006f41a6  8bf9                 mov edi, ecx
// 006f41a8  eb0e                 jmp 0x6f41b8
// 006f41aa  8b442470             mov eax, dword ptr [esp + 0x70]
// 006f41ae  8b7808               mov edi, dword ptr [eax + 8]
// 006f41b1  8d5008               lea edx, [eax + 8]
// 006f41b4  3bc3                 cmp eax, ebx
// 006f41b6  756b                 jne 0x6f4223
// 006f41b8  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006f41bc  8b7304               mov esi, dword ptr [ebx + 4]
// 006f41bf  7503                 jne 0x6f41c4
// 006f41c1  897704               mov dword ptr [edi + 4], esi
// 006f41c4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006f41c7  395804               cmp dword ptr [eax + 4], ebx
// 006f41ca  7505                 jne 0x6f41d1
// 006f41cc  897804               mov dword ptr [eax + 4], edi
// 006f41cf  eb0b                 jmp 0x6f41dc
// 006f41d1  391e                 cmp dword ptr [esi], ebx
// 006f41d3  7504                 jne 0x6f41d9
// 006f41d5  893e                 mov dword ptr [esi], edi
// 006f41d7  eb03                 jmp 0x6f41dc
// 006f41d9  897e08               mov dword ptr [esi + 8], edi
// 006f41dc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006f41df  8b03                 mov eax, dword ptr [ebx]
// 006f41e1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 006f41e5  7515                 jne 0x6f41fc
// 006f41e7  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006f41eb  7404                 je 0x6f41f1
// 006f41ed  8bc6                 mov eax, esi
// 006f41ef  eb09                 jmp 0x6f41fa
// 006f41f1  57                   push edi
// 006f41f2  e8d9faffff           call 0x6f3cd0
// 006f41f7  83c404               add esp, 4
// 006f41fa  8903                 mov dword ptr [ebx], eax
// 006f41fc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006f41ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f4203  394b08               cmp dword ptr [ebx + 8], ecx
// 006f4206  7577                 jne 0x6f427f
// 006f4208  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006f420c  7407                 je 0x6f4215
// 006f420e  8bc6                 mov eax, esi
// 006f4210  894308               mov dword ptr [ebx + 8], eax
// 006f4213  eb6a                 jmp 0x6f427f
// 006f4215  57                   push edi
// 006f4216  e895faffff           call 0x6f3cb0
// 006f421b  83c404               add esp, 4
// 006f421e  894308               mov dword ptr [ebx + 8], eax
// 006f4221  eb5c                 jmp 0x6f427f
// 006f4223  894104               mov dword ptr [ecx + 4], eax
// 006f4226  8b0b                 mov ecx, dword ptr [ebx]
// 006f4228  8908                 mov dword ptr [eax], ecx
// 006f422a  3b4308               cmp eax, dword ptr [ebx + 8]
// 006f422d  7504                 jne 0x6f4233
// 006f422f  8bf0                 mov esi, eax
// 006f4231  eb19                 jmp 0x6f424c
// 006f4233  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006f4237  8b7004               mov esi, dword ptr [eax + 4]
// 006f423a  7503                 jne 0x6f423f
// 006f423c  897704               mov dword ptr [edi + 4], esi
// 006f423f  893e                 mov dword ptr [esi], edi
// 006f4241  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006f4244  890a                 mov dword ptr [edx], ecx
// 006f4246  8b5308               mov edx, dword ptr [ebx + 8]
// 006f4249  894204               mov dword ptr [edx + 4], eax
// 006f424c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006f424f  395904               cmp dword ptr [ecx + 4], ebx
// 006f4252  7505                 jne 0x6f4259
// 006f4254  894104               mov dword ptr [ecx + 4], eax
// 006f4257  eb0e                 jmp 0x6f4267
// 006f4259  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006f425c  3919                 cmp dword ptr [ecx], ebx
// 006f425e  7504                 jne 0x6f4264
// 006f4260  8901                 mov dword ptr [ecx], eax
// 006f4262  eb03                 jmp 0x6f4267
// 006f4264  894108               mov dword ptr [ecx + 8], eax
// 006f4267  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006f426a  894804               mov dword ptr [eax + 4], ecx
// 006f426d  8d4b0d               lea ecx, [ebx + 0xd]
// 006f4270  83c00d               add eax, 0xd
// 006f4273  3bc1                 cmp eax, ecx
// 006f4275  7408                 je 0x6f427f
// 006f4277  8a19                 mov bl, byte ptr [ecx]
// 006f4279  8a10                 mov dl, byte ptr [eax]
// 006f427b  8818                 mov byte ptr [eax], bl
// 006f427d  8811                 mov byte ptr [ecx], dl
// 006f427f  8b542410             mov edx, dword ptr [esp + 0x10]
// 006f4283  b301                 mov bl, 1
// 006f4285  385a0d               cmp byte ptr [edx + 0xd], bl
// 006f4288  0f85fd000000         jne 0x6f438b
// 006f428e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006f4291  3b7804               cmp edi, dword ptr [eax + 4]
// 006f4294  0f84ee000000         je 0x6f4388
// 006f429a  8d9b00000000         lea ebx, [ebx]
// 006f42a0  385f0d               cmp byte ptr [edi + 0xd], bl
// 006f42a3  0f85df000000         jne 0x6f4388
// 006f42a9  8b06                 mov eax, dword ptr [esi]
// 006f42ab  3bf8                 cmp edi, eax
// 006f42ad  7565                 jne 0x6f4314
// 006f42af  8b4608               mov eax, dword ptr [esi + 8]
// 006f42b2  80780d00             cmp byte ptr [eax + 0xd], 0
// 006f42b6  7512                 jne 0x6f42ca
// 006f42b8  88580d               mov byte ptr [eax + 0xd], bl
// 006f42bb  56                   push esi
// 006f42bc  8bcd                 mov ecx, ebp
// 006f42be  c6460d00             mov byte ptr [esi + 0xd], 0
// 006f42c2  e869fbffff           call 0x6f3e30
// 006f42c7  8b4608               mov eax, dword ptr [esi + 8]
// 006f42ca  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f42ce  7574                 jne 0x6f4344
// 006f42d0  8b08                 mov ecx, dword ptr [eax]
// 006f42d2  38590d               cmp byte ptr [ecx + 0xd], bl
// 006f42d5  7508                 jne 0x6f42df
// 006f42d7  8b5008               mov edx, dword ptr [eax + 8]
// 006f42da  385a0d               cmp byte ptr [edx + 0xd], bl
// 006f42dd  7461                 je 0x6f4340
// 006f42df  8b4808               mov ecx, dword ptr [eax + 8]
// 006f42e2  38590d               cmp byte ptr [ecx + 0xd], bl
// 006f42e5  7514                 jne 0x6f42fb
// 006f42e7  8b10                 mov edx, dword ptr [eax]
// 006f42e9  885a0d               mov byte ptr [edx + 0xd], bl
// 006f42ec  50                   push eax
// 006f42ed  8bcd                 mov ecx, ebp
// 006f42ef  c6400d00             mov byte ptr [eax + 0xd], 0
// 006f42f3  e888fbffff           call 0x6f3e80
// 006f42f8  8b4608               mov eax, dword ptr [esi + 8]
// 006f42fb  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 006f42fe  88480d               mov byte ptr [eax + 0xd], cl
// 006f4301  885e0d               mov byte ptr [esi + 0xd], bl
// 006f4304  8b5008               mov edx, dword ptr [eax + 8]
// 006f4307  56                   push esi
// 006f4308  8bcd                 mov ecx, ebp
// 006f430a  885a0d               mov byte ptr [edx + 0xd], bl
// 006f430d  e81efbffff           call 0x6f3e30
// 006f4312  eb74                 jmp 0x6f4388
// 006f4314  80780d00             cmp byte ptr [eax + 0xd], 0
// 006f4318  7511                 jne 0x6f432b
// 006f431a  88580d               mov byte ptr [eax + 0xd], bl
// 006f431d  56                   push esi
// 006f431e  8bcd                 mov ecx, ebp
// 006f4320  c6460d00             mov byte ptr [esi + 0xd], 0
// 006f4324  e857fbffff           call 0x6f3e80
// 006f4329  8b06                 mov eax, dword ptr [esi]
// 006f432b  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f432f  7513                 jne 0x6f4344
// 006f4331  8b4808               mov ecx, dword ptr [eax + 8]
// 006f4334  38590d               cmp byte ptr [ecx + 0xd], bl
// 006f4337  751e                 jne 0x6f4357
// 006f4339  8b10                 mov edx, dword ptr [eax]
// 006f433b  385a0d               cmp byte ptr [edx + 0xd], bl
// 006f433e  7517                 jne 0x6f4357
// 006f4340  c6400d00             mov byte ptr [eax + 0xd], 0
// 006f4344  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006f4347  8bfe                 mov edi, esi
// 006f4349  8b7604               mov esi, dword ptr [esi + 4]
// 006f434c  3b7804               cmp edi, dword ptr [eax + 4]
// 006f434f  0f854bffffff         jne 0x6f42a0
// 006f4355  eb31                 jmp 0x6f4388
// 006f4357  8b08                 mov ecx, dword ptr [eax]
// 006f4359  38590d               cmp byte ptr [ecx + 0xd], bl
// 006f435c  7514                 jne 0x6f4372
// 006f435e  8b5008               mov edx, dword ptr [eax + 8]
// 006f4361  885a0d               mov byte ptr [edx + 0xd], bl
// 006f4364  50                   push eax
// 006f4365  8bcd                 mov ecx, ebp
// 006f4367  c6400d00             mov byte ptr [eax + 0xd], 0
// 006f436b  e8c0faffff           call 0x6f3e30
// 006f4370  8b06                 mov eax, dword ptr [esi]
// 006f4372  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 006f4375  88480d               mov byte ptr [eax + 0xd], cl
// 006f4378  885e0d               mov byte ptr [esi + 0xd], bl
// 006f437b  8b10                 mov edx, dword ptr [eax]
// 006f437d  56                   push esi
// 006f437e  8bcd                 mov ecx, ebp
// 006f4380  885a0d               mov byte ptr [edx + 0xd], bl
// 006f4383  e8f8faffff           call 0x6f3e80
// 006f4388  885f0d               mov byte ptr [edi + 0xd], bl
// 006f438b  8b442410             mov eax, dword ptr [esp + 0x10]
// 006f438f  50                   push eax
// 006f4390  e805360b00           call 0x7a799a
// 006f4395  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 006f4398  83c404               add esp, 4
// 006f439b  5f                   pop edi
// 006f439c  5e                   pop esi
// 006f439d  5b                   pop ebx
// 006f439e  85c0                 test eax, eax
// 006f43a0  7604                 jbe 0x6f43a6
// 006f43a2  48                   dec eax
// 006f43a3  89451c               mov dword ptr [ebp + 0x1c], eax
// 006f43a6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006f43aa  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 006f43ae  8b5500               mov edx, dword ptr [ebp]
// 006f43b1  894804               mov dword ptr [eax + 4], ecx
// 006f43b4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006f43b8  8910                 mov dword ptr [eax], edx
// 006f43ba  5d                   pop ebp
// 006f43bb  64890d00000000       mov dword ptr fs:[0], ecx
// 006f43c2  83c454               add esp, 0x54
// 006f43c5  c20c00               ret 0xc
// standard library set<char> (function ?erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
