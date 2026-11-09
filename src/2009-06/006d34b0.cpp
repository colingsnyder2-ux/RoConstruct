// from server: 100% by auto
// roc 2009-06 006d34b0  unit: RBX::Block  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d34b0
//
// 006d34b0  64a100000000         mov eax, dword ptr fs:[0]
// 006d34b6  6aff                 push -1
// 006d34b8  68b2db8500           push 0x85dbb2
// 006d34bd  50                   push eax
// 006d34be  64892500000000       mov dword ptr fs:[0], esp
// 006d34c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006d34c9  83ec48               sub esp, 0x48
// 006d34cc  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d34d0  55                   push ebp
// 006d34d1  8be9                 mov ebp, ecx
// 006d34d3  7459                 je 0x6d352e
// 006d34d5  68a4c98a00           push 0x8ac9a4
// 006d34da  8d4c240c             lea ecx, [esp + 0xc]
// 006d34de  ff15b4e48900         call dword ptr [0x89e4b4]
// 006d34e4  8d4c2424             lea ecx, [esp + 0x24]
// 006d34e8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006d34f0  ff15b8e98900         call dword ptr [0x89e9b8]
// 006d34f6  8d442408             lea eax, [esp + 8]
// 006d34fa  50                   push eax
// 006d34fb  8d4c2434             lea ecx, [esp + 0x34]
// 006d34ff  c644245801           mov byte ptr [esp + 0x58], 1
// 006d3504  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 006d350c  ff15b8e48900         call dword ptr [0x89e4b8]
// 006d3512  68dc919700           push 0x9791dc
// 006d3517  8d4c2428             lea ecx, [esp + 0x28]
// 006d351b  51                   push ecx
// 006d351c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 006d3521  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 006d3529  e81c650400           call 0x719a4a
// 006d352e  53                   push ebx
// 006d352f  56                   push esi
// 006d3530  8bd8                 mov ebx, eax
// 006d3532  57                   push edi
// 006d3533  8d4c246c             lea ecx, [esp + 0x6c]
// 006d3537  895c2410             mov dword ptr [esp + 0x10], ebx
// 006d353b  e800faffff           call 0x6d2f40
// 006d3540  8b0b                 mov ecx, dword ptr [ebx]
// 006d3542  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d3546  7405                 je 0x6d354d
// 006d3548  8b7b08               mov edi, dword ptr [ebx + 8]
// 006d354b  eb1b                 jmp 0x6d3568
// 006d354d  8b5308               mov edx, dword ptr [ebx + 8]
// 006d3550  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 006d3554  7404                 je 0x6d355a
// 006d3556  8bf9                 mov edi, ecx
// 006d3558  eb0e                 jmp 0x6d3568
// 006d355a  8b442470             mov eax, dword ptr [esp + 0x70]
// 006d355e  8b7808               mov edi, dword ptr [eax + 8]
// 006d3561  8d5008               lea edx, [eax + 8]
// 006d3564  3bc3                 cmp eax, ebx
// 006d3566  756b                 jne 0x6d35d3
// 006d3568  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006d356c  8b7304               mov esi, dword ptr [ebx + 4]
// 006d356f  7503                 jne 0x6d3574
// 006d3571  897704               mov dword ptr [edi + 4], esi
// 006d3574  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006d3577  395804               cmp dword ptr [eax + 4], ebx
// 006d357a  7505                 jne 0x6d3581
// 006d357c  897804               mov dword ptr [eax + 4], edi
// 006d357f  eb0b                 jmp 0x6d358c
// 006d3581  391e                 cmp dword ptr [esi], ebx
// 006d3583  7504                 jne 0x6d3589
// 006d3585  893e                 mov dword ptr [esi], edi
// 006d3587  eb03                 jmp 0x6d358c
// 006d3589  897e08               mov dword ptr [esi + 8], edi
// 006d358c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006d358f  8b03                 mov eax, dword ptr [ebx]
// 006d3591  3b442410             cmp eax, dword ptr [esp + 0x10]
// 006d3595  7515                 jne 0x6d35ac
// 006d3597  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006d359b  7404                 je 0x6d35a1
// 006d359d  8bc6                 mov eax, esi
// 006d359f  eb09                 jmp 0x6d35aa
// 006d35a1  57                   push edi
// 006d35a2  e849f6ffff           call 0x6d2bf0
// 006d35a7  83c404               add esp, 4
// 006d35aa  8903                 mov dword ptr [ebx], eax
// 006d35ac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006d35af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006d35b3  394b08               cmp dword ptr [ebx + 8], ecx
// 006d35b6  7577                 jne 0x6d362f
// 006d35b8  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006d35bc  7407                 je 0x6d35c5
// 006d35be  8bc6                 mov eax, esi
// 006d35c0  894308               mov dword ptr [ebx + 8], eax
// 006d35c3  eb6a                 jmp 0x6d362f
// 006d35c5  57                   push edi
// 006d35c6  e8a5f6ffff           call 0x6d2c70
// 006d35cb  83c404               add esp, 4
// 006d35ce  894308               mov dword ptr [ebx + 8], eax
// 006d35d1  eb5c                 jmp 0x6d362f
// 006d35d3  894104               mov dword ptr [ecx + 4], eax
// 006d35d6  8b0b                 mov ecx, dword ptr [ebx]
// 006d35d8  8908                 mov dword ptr [eax], ecx
// 006d35da  3b4308               cmp eax, dword ptr [ebx + 8]
// 006d35dd  7504                 jne 0x6d35e3
// 006d35df  8bf0                 mov esi, eax
// 006d35e1  eb19                 jmp 0x6d35fc
// 006d35e3  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006d35e7  8b7004               mov esi, dword ptr [eax + 4]
// 006d35ea  7503                 jne 0x6d35ef
// 006d35ec  897704               mov dword ptr [edi + 4], esi
// 006d35ef  893e                 mov dword ptr [esi], edi
// 006d35f1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006d35f4  890a                 mov dword ptr [edx], ecx
// 006d35f6  8b5308               mov edx, dword ptr [ebx + 8]
// 006d35f9  894204               mov dword ptr [edx + 4], eax
// 006d35fc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006d35ff  395904               cmp dword ptr [ecx + 4], ebx
// 006d3602  7505                 jne 0x6d3609
// 006d3604  894104               mov dword ptr [ecx + 4], eax
// 006d3607  eb0e                 jmp 0x6d3617
// 006d3609  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006d360c  3919                 cmp dword ptr [ecx], ebx
// 006d360e  7504                 jne 0x6d3614
// 006d3610  8901                 mov dword ptr [ecx], eax
// 006d3612  eb03                 jmp 0x6d3617
// 006d3614  894108               mov dword ptr [ecx + 8], eax
// 006d3617  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006d361a  894804               mov dword ptr [eax + 4], ecx
// 006d361d  8d4b1c               lea ecx, [ebx + 0x1c]
// 006d3620  83c01c               add eax, 0x1c
// 006d3623  3bc1                 cmp eax, ecx
// 006d3625  7408                 je 0x6d362f
// 006d3627  8a19                 mov bl, byte ptr [ecx]
// 006d3629  8a10                 mov dl, byte ptr [eax]
// 006d362b  8818                 mov byte ptr [eax], bl
// 006d362d  8811                 mov byte ptr [ecx], dl
// 006d362f  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d3633  b301                 mov bl, 1
// 006d3635  385a1c               cmp byte ptr [edx + 0x1c], bl
// 006d3638  0f85fd000000         jne 0x6d373b
// 006d363e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006d3641  3b7804               cmp edi, dword ptr [eax + 4]
// 006d3644  0f84ee000000         je 0x6d3738
// 006d364a  8d9b00000000         lea ebx, [ebx]
// 006d3650  385f1c               cmp byte ptr [edi + 0x1c], bl
// 006d3653  0f85df000000         jne 0x6d3738
// 006d3659  8b06                 mov eax, dword ptr [esi]
// 006d365b  3bf8                 cmp edi, eax
// 006d365d  7565                 jne 0x6d36c4
// 006d365f  8b4608               mov eax, dword ptr [esi + 8]
// 006d3662  80781c00             cmp byte ptr [eax + 0x1c], 0
// 006d3666  7512                 jne 0x6d367a
// 006d3668  88581c               mov byte ptr [eax + 0x1c], bl
// 006d366b  56                   push esi
// 006d366c  8bcd                 mov ecx, ebp
// 006d366e  c6461c00             mov byte ptr [esi + 0x1c], 0
// 006d3672  e839f9ffff           call 0x6d2fb0
// 006d3677  8b4608               mov eax, dword ptr [esi + 8]
// 006d367a  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d367e  7574                 jne 0x6d36f4
// 006d3680  8b08                 mov ecx, dword ptr [eax]
// 006d3682  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006d3685  7508                 jne 0x6d368f
// 006d3687  8b5008               mov edx, dword ptr [eax + 8]
// 006d368a  385a1c               cmp byte ptr [edx + 0x1c], bl
// 006d368d  7461                 je 0x6d36f0
// 006d368f  8b4808               mov ecx, dword ptr [eax + 8]
// 006d3692  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006d3695  7514                 jne 0x6d36ab
// 006d3697  8b10                 mov edx, dword ptr [eax]
// 006d3699  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d369c  50                   push eax
// 006d369d  8bcd                 mov ecx, ebp
// 006d369f  c6401c00             mov byte ptr [eax + 0x1c], 0
// 006d36a3  e868f5ffff           call 0x6d2c10
// 006d36a8  8b4608               mov eax, dword ptr [esi + 8]
// 006d36ab  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 006d36ae  88481c               mov byte ptr [eax + 0x1c], cl
// 006d36b1  885e1c               mov byte ptr [esi + 0x1c], bl
// 006d36b4  8b5008               mov edx, dword ptr [eax + 8]
// 006d36b7  56                   push esi
// 006d36b8  8bcd                 mov ecx, ebp
// 006d36ba  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d36bd  e8eef8ffff           call 0x6d2fb0
// 006d36c2  eb74                 jmp 0x6d3738
// 006d36c4  80781c00             cmp byte ptr [eax + 0x1c], 0
// 006d36c8  7511                 jne 0x6d36db
// 006d36ca  88581c               mov byte ptr [eax + 0x1c], bl
// 006d36cd  56                   push esi
// 006d36ce  8bcd                 mov ecx, ebp
// 006d36d0  c6461c00             mov byte ptr [esi + 0x1c], 0
// 006d36d4  e837f5ffff           call 0x6d2c10
// 006d36d9  8b06                 mov eax, dword ptr [esi]
// 006d36db  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d36df  7513                 jne 0x6d36f4
// 006d36e1  8b4808               mov ecx, dword ptr [eax + 8]
// 006d36e4  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006d36e7  751e                 jne 0x6d3707
// 006d36e9  8b10                 mov edx, dword ptr [eax]
// 006d36eb  385a1c               cmp byte ptr [edx + 0x1c], bl
// 006d36ee  7517                 jne 0x6d3707
// 006d36f0  c6401c00             mov byte ptr [eax + 0x1c], 0
// 006d36f4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006d36f7  8bfe                 mov edi, esi
// 006d36f9  8b7604               mov esi, dword ptr [esi + 4]
// 006d36fc  3b7804               cmp edi, dword ptr [eax + 4]
// 006d36ff  0f854bffffff         jne 0x6d3650
// 006d3705  eb31                 jmp 0x6d3738
// 006d3707  8b08                 mov ecx, dword ptr [eax]
// 006d3709  38591c               cmp byte ptr [ecx + 0x1c], bl
// 006d370c  7514                 jne 0x6d3722
// 006d370e  8b5008               mov edx, dword ptr [eax + 8]
// 006d3711  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d3714  50                   push eax
// 006d3715  8bcd                 mov ecx, ebp
// 006d3717  c6401c00             mov byte ptr [eax + 0x1c], 0
// 006d371b  e890f8ffff           call 0x6d2fb0
// 006d3720  8b06                 mov eax, dword ptr [esi]
// 006d3722  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 006d3725  88481c               mov byte ptr [eax + 0x1c], cl
// 006d3728  885e1c               mov byte ptr [esi + 0x1c], bl
// 006d372b  8b10                 mov edx, dword ptr [eax]
// 006d372d  56                   push esi
// 006d372e  8bcd                 mov ecx, ebp
// 006d3730  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d3733  e8d8f4ffff           call 0x6d2c10
// 006d3738  885f1c               mov byte ptr [edi + 0x1c], bl
// 006d373b  8b442410             mov eax, dword ptr [esp + 0x10]
// 006d373f  50                   push eax
// 006d3740  e8ed520400           call 0x718a32
// 006d3745  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 006d3748  83c404               add esp, 4
// 006d374b  5f                   pop edi
// 006d374c  5e                   pop esi
// 006d374d  5b                   pop ebx
// 006d374e  85c0                 test eax, eax
// 006d3750  7604                 jbe 0x6d3756
// 006d3752  48                   dec eax
// 006d3753  89451c               mov dword ptr [ebp + 0x1c], eax
// 006d3756  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006d375a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 006d375e  8b5500               mov edx, dword ptr [ebp]
// 006d3761  894804               mov dword ptr [eax + 4], ecx
// 006d3764  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006d3768  8910                 mov dword ptr [eax], edx
// 006d376a  5d                   pop ebp
// 006d376b  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3772  83c454               add esp, 0x54
// 006d3775  c20c00               ret 0xc
// standard library set<pod16> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
