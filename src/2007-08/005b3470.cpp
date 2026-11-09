// from server: 100% by auto
// roc 2007-08 005b3470  unit: RBX::Assembly  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b3470
//
// 005b3470  64a100000000         mov eax, dword ptr fs:[0]
// 005b3476  6aff                 push -1
// 005b3478  68b2417500           push 0x7541b2
// 005b347d  50                   push eax
// 005b347e  64892500000000       mov dword ptr fs:[0], esp
// 005b3485  8b442418             mov eax, dword ptr [esp + 0x18]
// 005b3489  83ec48               sub esp, 0x48
// 005b348c  80781100             cmp byte ptr [eax + 0x11], 0
// 005b3490  55                   push ebp
// 005b3491  8be9                 mov ebp, ecx
// 005b3493  7459                 je 0x5b34ee
// 005b3495  68dc4e7800           push 0x784edc
// 005b349a  8d4c240c             lea ecx, [esp + 0xc]
// 005b349e  ff1598e67700         call dword ptr [0x77e698]
// 005b34a4  8d4c2424             lea ecx, [esp + 0x24]
// 005b34a8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005b34b0  ff15f8e67700         call dword ptr [0x77e6f8]
// 005b34b6  8d442408             lea eax, [esp + 8]
// 005b34ba  50                   push eax
// 005b34bb  8d4c2434             lea ecx, [esp + 0x34]
// 005b34bf  c644245801           mov byte ptr [esp + 0x58], 1
// 005b34c4  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 005b34cc  ff159ce67700         call dword ptr [0x77e69c]
// 005b34d2  6864f38300           push 0x83f364
// 005b34d7  8d4c2428             lea ecx, [esp + 0x28]
// 005b34db  51                   push ecx
// 005b34dc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005b34e1  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 005b34e9  e8b0d60700           call 0x630b9e
// 005b34ee  53                   push ebx
// 005b34ef  56                   push esi
// 005b34f0  8bd8                 mov ebx, eax
// 005b34f2  57                   push edi
// 005b34f3  8d4c246c             lea ecx, [esp + 0x6c]
// 005b34f7  895c2410             mov dword ptr [esp + 0x10], ebx
// 005b34fb  e8403d0700           call 0x627240
// 005b3500  8b03                 mov eax, dword ptr [ebx]
// 005b3502  80781100             cmp byte ptr [eax + 0x11], 0
// 005b3506  7405                 je 0x5b350d
// 005b3508  8b7b08               mov edi, dword ptr [ebx + 8]
// 005b350b  eb18                 jmp 0x5b3525
// 005b350d  8b5308               mov edx, dword ptr [ebx + 8]
// 005b3510  807a1100             cmp byte ptr [edx + 0x11], 0
// 005b3514  7404                 je 0x5b351a
// 005b3516  8bf8                 mov edi, eax
// 005b3518  eb0b                 jmp 0x5b3525
// 005b351a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005b351e  3bcb                 cmp ecx, ebx
// 005b3520  8b7908               mov edi, dword ptr [ecx + 8]
// 005b3523  756b                 jne 0x5b3590
// 005b3525  807f1100             cmp byte ptr [edi + 0x11], 0
// 005b3529  8b7304               mov esi, dword ptr [ebx + 4]
// 005b352c  7503                 jne 0x5b3531
// 005b352e  897704               mov dword ptr [edi + 4], esi
// 005b3531  8b4504               mov eax, dword ptr [ebp + 4]
// 005b3534  395804               cmp dword ptr [eax + 4], ebx
// 005b3537  7505                 jne 0x5b353e
// 005b3539  897804               mov dword ptr [eax + 4], edi
// 005b353c  eb0b                 jmp 0x5b3549
// 005b353e  391e                 cmp dword ptr [esi], ebx
// 005b3540  7504                 jne 0x5b3546
// 005b3542  893e                 mov dword ptr [esi], edi
// 005b3544  eb03                 jmp 0x5b3549
// 005b3546  897e08               mov dword ptr [esi + 8], edi
// 005b3549  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005b354c  8b03                 mov eax, dword ptr [ebx]
// 005b354e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005b3552  7515                 jne 0x5b3569
// 005b3554  807f1100             cmp byte ptr [edi + 0x11], 0
// 005b3558  7404                 je 0x5b355e
// 005b355a  8bc6                 mov eax, esi
// 005b355c  eb09                 jmp 0x5b3567
// 005b355e  57                   push edi
// 005b355f  e8ac5bffff           call 0x5a9110
// 005b3564  83c404               add esp, 4
// 005b3567  8903                 mov dword ptr [ebx], eax
// 005b3569  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005b356c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3570  394b08               cmp dword ptr [ebx + 8], ecx
// 005b3573  7572                 jne 0x5b35e7
// 005b3575  807f1100             cmp byte ptr [edi + 0x11], 0
// 005b3579  7407                 je 0x5b3582
// 005b357b  8bc6                 mov eax, esi
// 005b357d  894308               mov dword ptr [ebx + 8], eax
// 005b3580  eb65                 jmp 0x5b35e7
// 005b3582  57                   push edi
// 005b3583  e888ab0200           call 0x5de110
// 005b3588  83c404               add esp, 4
// 005b358b  894308               mov dword ptr [ebx + 8], eax
// 005b358e  eb57                 jmp 0x5b35e7
// 005b3590  894804               mov dword ptr [eax + 4], ecx
// 005b3593  8b13                 mov edx, dword ptr [ebx]
// 005b3595  8911                 mov dword ptr [ecx], edx
// 005b3597  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005b359a  7504                 jne 0x5b35a0
// 005b359c  8bf1                 mov esi, ecx
// 005b359e  eb1a                 jmp 0x5b35ba
// 005b35a0  807f1100             cmp byte ptr [edi + 0x11], 0
// 005b35a4  8b7104               mov esi, dword ptr [ecx + 4]
// 005b35a7  7503                 jne 0x5b35ac
// 005b35a9  897704               mov dword ptr [edi + 4], esi
// 005b35ac  893e                 mov dword ptr [esi], edi
// 005b35ae  8b4308               mov eax, dword ptr [ebx + 8]
// 005b35b1  894108               mov dword ptr [ecx + 8], eax
// 005b35b4  8b5308               mov edx, dword ptr [ebx + 8]
// 005b35b7  894a04               mov dword ptr [edx + 4], ecx
// 005b35ba  8b4504               mov eax, dword ptr [ebp + 4]
// 005b35bd  395804               cmp dword ptr [eax + 4], ebx
// 005b35c0  7505                 jne 0x5b35c7
// 005b35c2  894804               mov dword ptr [eax + 4], ecx
// 005b35c5  eb0e                 jmp 0x5b35d5
// 005b35c7  8b4304               mov eax, dword ptr [ebx + 4]
// 005b35ca  3918                 cmp dword ptr [eax], ebx
// 005b35cc  7504                 jne 0x5b35d2
// 005b35ce  8908                 mov dword ptr [eax], ecx
// 005b35d0  eb03                 jmp 0x5b35d5
// 005b35d2  894808               mov dword ptr [eax + 8], ecx
// 005b35d5  8b4304               mov eax, dword ptr [ebx + 4]
// 005b35d8  894104               mov dword ptr [ecx + 4], eax
// 005b35db  8a5310               mov dl, byte ptr [ebx + 0x10]
// 005b35de  8a4110               mov al, byte ptr [ecx + 0x10]
// 005b35e1  885110               mov byte ptr [ecx + 0x10], dl
// 005b35e4  884310               mov byte ptr [ebx + 0x10], al
// 005b35e7  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b35eb  b301                 mov bl, 1
// 005b35ed  385810               cmp byte ptr [eax + 0x10], bl
// 005b35f0  0f85f2000000         jne 0x5b36e8
// 005b35f6  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005b35f9  3b7904               cmp edi, dword ptr [ecx + 4]
// 005b35fc  0f84e3000000         je 0x5b36e5
// 005b3602  385f10               cmp byte ptr [edi + 0x10], bl
// 005b3605  0f85da000000         jne 0x5b36e5
// 005b360b  8b06                 mov eax, dword ptr [esi]
// 005b360d  3bf8                 cmp edi, eax
// 005b360f  7563                 jne 0x5b3674
// 005b3611  8b4608               mov eax, dword ptr [esi + 8]
// 005b3614  80781000             cmp byte ptr [eax + 0x10], 0
// 005b3618  7512                 jne 0x5b362c
// 005b361a  885810               mov byte ptr [eax + 0x10], bl
// 005b361d  56                   push esi
// 005b361e  8bcd                 mov ecx, ebp
// 005b3620  c6461000             mov byte ptr [esi + 0x10], 0
// 005b3624  e8b78fffff           call 0x5ac5e0
// 005b3629  8b4608               mov eax, dword ptr [esi + 8]
// 005b362c  80781100             cmp byte ptr [eax + 0x11], 0
// 005b3630  7572                 jne 0x5b36a4
// 005b3632  8b10                 mov edx, dword ptr [eax]
// 005b3634  385a10               cmp byte ptr [edx + 0x10], bl
// 005b3637  7508                 jne 0x5b3641
// 005b3639  8b4808               mov ecx, dword ptr [eax + 8]
// 005b363c  385910               cmp byte ptr [ecx + 0x10], bl
// 005b363f  745f                 je 0x5b36a0
// 005b3641  8b4808               mov ecx, dword ptr [eax + 8]
// 005b3644  385910               cmp byte ptr [ecx + 0x10], bl
// 005b3647  7512                 jne 0x5b365b
// 005b3649  885a10               mov byte ptr [edx + 0x10], bl
// 005b364c  50                   push eax
// 005b364d  8bcd                 mov ecx, ebp
// 005b364f  c6401000             mov byte ptr [eax + 0x10], 0
// 005b3653  e8f80a0300           call 0x5e4150
// 005b3658  8b4608               mov eax, dword ptr [esi + 8]
// 005b365b  8a4e10               mov cl, byte ptr [esi + 0x10]
// 005b365e  884810               mov byte ptr [eax + 0x10], cl
// 005b3661  885e10               mov byte ptr [esi + 0x10], bl
// 005b3664  8b5008               mov edx, dword ptr [eax + 8]
// 005b3667  56                   push esi
// 005b3668  8bcd                 mov ecx, ebp
// 005b366a  885a10               mov byte ptr [edx + 0x10], bl
// 005b366d  e86e8fffff           call 0x5ac5e0
// 005b3672  eb71                 jmp 0x5b36e5
// 005b3674  80781000             cmp byte ptr [eax + 0x10], 0
// 005b3678  7511                 jne 0x5b368b
// 005b367a  885810               mov byte ptr [eax + 0x10], bl
// 005b367d  56                   push esi
// 005b367e  8bcd                 mov ecx, ebp
// 005b3680  c6461000             mov byte ptr [esi + 0x10], 0
// 005b3684  e8c70a0300           call 0x5e4150
// 005b3689  8b06                 mov eax, dword ptr [esi]
// 005b368b  80781100             cmp byte ptr [eax + 0x11], 0
// 005b368f  7513                 jne 0x5b36a4
// 005b3691  8b5008               mov edx, dword ptr [eax + 8]
// 005b3694  385a10               cmp byte ptr [edx + 0x10], bl
// 005b3697  751e                 jne 0x5b36b7
// 005b3699  8b08                 mov ecx, dword ptr [eax]
// 005b369b  385910               cmp byte ptr [ecx + 0x10], bl
// 005b369e  7517                 jne 0x5b36b7
// 005b36a0  c6401000             mov byte ptr [eax + 0x10], 0
// 005b36a4  8b5504               mov edx, dword ptr [ebp + 4]
// 005b36a7  8bfe                 mov edi, esi
// 005b36a9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005b36ac  8b7604               mov esi, dword ptr [esi + 4]
// 005b36af  0f854dffffff         jne 0x5b3602
// 005b36b5  eb2e                 jmp 0x5b36e5
// 005b36b7  8b08                 mov ecx, dword ptr [eax]
// 005b36b9  385910               cmp byte ptr [ecx + 0x10], bl
// 005b36bc  7511                 jne 0x5b36cf
// 005b36be  885a10               mov byte ptr [edx + 0x10], bl
// 005b36c1  50                   push eax
// 005b36c2  8bcd                 mov ecx, ebp
// 005b36c4  c6401000             mov byte ptr [eax + 0x10], 0
// 005b36c8  e8138fffff           call 0x5ac5e0
// 005b36cd  8b06                 mov eax, dword ptr [esi]
// 005b36cf  8a4e10               mov cl, byte ptr [esi + 0x10]
// 005b36d2  884810               mov byte ptr [eax + 0x10], cl
// 005b36d5  885e10               mov byte ptr [esi + 0x10], bl
// 005b36d8  8b10                 mov edx, dword ptr [eax]
// 005b36da  56                   push esi
// 005b36db  8bcd                 mov ecx, ebp
// 005b36dd  885a10               mov byte ptr [edx + 0x10], bl
// 005b36e0  e86b0a0300           call 0x5e4150
// 005b36e5  885f10               mov byte ptr [edi + 0x10], bl
// 005b36e8  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b36ec  50                   push eax
// 005b36ed  e870c50700           call 0x62fc62
// 005b36f2  8b4508               mov eax, dword ptr [ebp + 8]
// 005b36f5  83c404               add esp, 4
// 005b36f8  85c0                 test eax, eax
// 005b36fa  5f                   pop edi
// 005b36fb  5e                   pop esi
// 005b36fc  5b                   pop ebx
// 005b36fd  7606                 jbe 0x5b3705
// 005b36ff  83c0ff               add eax, -1
// 005b3702  894508               mov dword ptr [ebp + 8], eax
// 005b3705  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005b3709  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005b370d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005b3711  8908                 mov dword ptr [eax], ecx
// 005b3713  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b3717  895004               mov dword ptr [eax + 4], edx
// 005b371a  5d                   pop ebp
// 005b371b  64890d00000000       mov dword ptr fs:[0], ecx
// 005b3722  83c454               add esp, 0x54
// 005b3725  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
