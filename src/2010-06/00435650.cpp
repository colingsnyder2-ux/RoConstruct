// from server: 100% by auto
// roc 2010-06 00435650  unit: CPropGrid::UpdateItemsJob  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00435650
//
// 00435650  64a100000000         mov eax, dword ptr fs:[0]
// 00435656  6aff                 push -1
// 00435658  68e22f9a00           push 0x9a2fe2
// 0043565d  50                   push eax
// 0043565e  64892500000000       mov dword ptr fs:[0], esp
// 00435665  8b442418             mov eax, dword ptr [esp + 0x18]
// 00435669  83ec48               sub esp, 0x48
// 0043566c  80781100             cmp byte ptr [eax + 0x11], 0
// 00435670  55                   push ebp
// 00435671  8be9                 mov ebp, ecx
// 00435673  7459                 je 0x4356ce
// 00435675  688c00a000           push 0xa0008c
// 0043567a  8d4c240c             lea ecx, [esp + 0xc]
// 0043567e  ff1510a49e00         call dword ptr [0x9ea410]
// 00435684  8d4c2424             lea ecx, [esp + 0x24]
// 00435688  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00435690  ff1518a99e00         call dword ptr [0x9ea918]
// 00435696  8d442408             lea eax, [esp + 8]
// 0043569a  50                   push eax
// 0043569b  8d4c2434             lea ecx, [esp + 0x34]
// 0043569f  c644245801           mov byte ptr [esp + 0x58], 1
// 004356a4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 004356ac  ff150ca49e00         call dword ptr [0x9ea40c]
// 004356b2  68081bb000           push 0xb01b08
// 004356b7  8d4c2428             lea ecx, [esp + 0x28]
// 004356bb  51                   push ecx
// 004356bc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004356c1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 004356c9  e8e4323700           call 0x7a89b2
// 004356ce  53                   push ebx
// 004356cf  56                   push esi
// 004356d0  8bd8                 mov ebx, eax
// 004356d2  57                   push edi
// 004356d3  8d4c246c             lea ecx, [esp + 0x6c]
// 004356d7  895c2410             mov dword ptr [esp + 0x10], ebx
// 004356db  e8e0c03200           call 0x7617c0
// 004356e0  8b0b                 mov ecx, dword ptr [ebx]
// 004356e2  80791100             cmp byte ptr [ecx + 0x11], 0
// 004356e6  7405                 je 0x4356ed
// 004356e8  8b7b08               mov edi, dword ptr [ebx + 8]
// 004356eb  eb1b                 jmp 0x435708
// 004356ed  8b5308               mov edx, dword ptr [ebx + 8]
// 004356f0  807a1100             cmp byte ptr [edx + 0x11], 0
// 004356f4  7404                 je 0x4356fa
// 004356f6  8bf9                 mov edi, ecx
// 004356f8  eb0e                 jmp 0x435708
// 004356fa  8b442470             mov eax, dword ptr [esp + 0x70]
// 004356fe  8b7808               mov edi, dword ptr [eax + 8]
// 00435701  8d5008               lea edx, [eax + 8]
// 00435704  3bc3                 cmp eax, ebx
// 00435706  756b                 jne 0x435773
// 00435708  807f1100             cmp byte ptr [edi + 0x11], 0
// 0043570c  8b7304               mov esi, dword ptr [ebx + 4]
// 0043570f  7503                 jne 0x435714
// 00435711  897704               mov dword ptr [edi + 4], esi
// 00435714  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00435717  395804               cmp dword ptr [eax + 4], ebx
// 0043571a  7505                 jne 0x435721
// 0043571c  897804               mov dword ptr [eax + 4], edi
// 0043571f  eb0b                 jmp 0x43572c
// 00435721  391e                 cmp dword ptr [esi], ebx
// 00435723  7504                 jne 0x435729
// 00435725  893e                 mov dword ptr [esi], edi
// 00435727  eb03                 jmp 0x43572c
// 00435729  897e08               mov dword ptr [esi + 8], edi
// 0043572c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0043572f  8b03                 mov eax, dword ptr [ebx]
// 00435731  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00435735  7515                 jne 0x43574c
// 00435737  807f1100             cmp byte ptr [edi + 0x11], 0
// 0043573b  7404                 je 0x435741
// 0043573d  8bc6                 mov eax, esi
// 0043573f  eb09                 jmp 0x43574a
// 00435741  57                   push edi
// 00435742  e839c8fcff           call 0x401f80
// 00435747  83c404               add esp, 4
// 0043574a  8903                 mov dword ptr [ebx], eax
// 0043574c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0043574f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00435753  394b08               cmp dword ptr [ebx + 8], ecx
// 00435756  7577                 jne 0x4357cf
// 00435758  807f1100             cmp byte ptr [edi + 0x11], 0
// 0043575c  7407                 je 0x435765
// 0043575e  8bc6                 mov eax, esi
// 00435760  894308               mov dword ptr [ebx + 8], eax
// 00435763  eb6a                 jmp 0x4357cf
// 00435765  57                   push edi
// 00435766  e805030b00           call 0x4e5a70
// 0043576b  83c404               add esp, 4
// 0043576e  894308               mov dword ptr [ebx + 8], eax
// 00435771  eb5c                 jmp 0x4357cf
// 00435773  894104               mov dword ptr [ecx + 4], eax
// 00435776  8b0b                 mov ecx, dword ptr [ebx]
// 00435778  8908                 mov dword ptr [eax], ecx
// 0043577a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0043577d  7504                 jne 0x435783
// 0043577f  8bf0                 mov esi, eax
// 00435781  eb19                 jmp 0x43579c
// 00435783  807f1100             cmp byte ptr [edi + 0x11], 0
// 00435787  8b7004               mov esi, dword ptr [eax + 4]
// 0043578a  7503                 jne 0x43578f
// 0043578c  897704               mov dword ptr [edi + 4], esi
// 0043578f  893e                 mov dword ptr [esi], edi
// 00435791  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00435794  890a                 mov dword ptr [edx], ecx
// 00435796  8b5308               mov edx, dword ptr [ebx + 8]
// 00435799  894204               mov dword ptr [edx + 4], eax
// 0043579c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0043579f  395904               cmp dword ptr [ecx + 4], ebx
// 004357a2  7505                 jne 0x4357a9
// 004357a4  894104               mov dword ptr [ecx + 4], eax
// 004357a7  eb0e                 jmp 0x4357b7
// 004357a9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004357ac  3919                 cmp dword ptr [ecx], ebx
// 004357ae  7504                 jne 0x4357b4
// 004357b0  8901                 mov dword ptr [ecx], eax
// 004357b2  eb03                 jmp 0x4357b7
// 004357b4  894108               mov dword ptr [ecx + 8], eax
// 004357b7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004357ba  894804               mov dword ptr [eax + 4], ecx
// 004357bd  8d4b10               lea ecx, [ebx + 0x10]
// 004357c0  83c010               add eax, 0x10
// 004357c3  3bc1                 cmp eax, ecx
// 004357c5  7408                 je 0x4357cf
// 004357c7  8a19                 mov bl, byte ptr [ecx]
// 004357c9  8a10                 mov dl, byte ptr [eax]
// 004357cb  8818                 mov byte ptr [eax], bl
// 004357cd  8811                 mov byte ptr [ecx], dl
// 004357cf  8b542410             mov edx, dword ptr [esp + 0x10]
// 004357d3  b301                 mov bl, 1
// 004357d5  385a10               cmp byte ptr [edx + 0x10], bl
// 004357d8  0f85fd000000         jne 0x4358db
// 004357de  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004357e1  3b7804               cmp edi, dword ptr [eax + 4]
// 004357e4  0f84ee000000         je 0x4358d8
// 004357ea  8d9b00000000         lea ebx, [ebx]
// 004357f0  385f10               cmp byte ptr [edi + 0x10], bl
// 004357f3  0f85df000000         jne 0x4358d8
// 004357f9  8b06                 mov eax, dword ptr [esi]
// 004357fb  3bf8                 cmp edi, eax
// 004357fd  7565                 jne 0x435864
// 004357ff  8b4608               mov eax, dword ptr [esi + 8]
// 00435802  80781000             cmp byte ptr [eax + 0x10], 0
// 00435806  7512                 jne 0x43581a
// 00435808  885810               mov byte ptr [eax + 0x10], bl
// 0043580b  56                   push esi
// 0043580c  8bcd                 mov ecx, ebp
// 0043580e  c6461000             mov byte ptr [esi + 0x10], 0
// 00435812  e8b9963200           call 0x75eed0
// 00435817  8b4608               mov eax, dword ptr [esi + 8]
// 0043581a  80781100             cmp byte ptr [eax + 0x11], 0
// 0043581e  7574                 jne 0x435894
// 00435820  8b08                 mov ecx, dword ptr [eax]
// 00435822  385910               cmp byte ptr [ecx + 0x10], bl
// 00435825  7508                 jne 0x43582f
// 00435827  8b5008               mov edx, dword ptr [eax + 8]
// 0043582a  385a10               cmp byte ptr [edx + 0x10], bl
// 0043582d  7461                 je 0x435890
// 0043582f  8b4808               mov ecx, dword ptr [eax + 8]
// 00435832  385910               cmp byte ptr [ecx + 0x10], bl
// 00435835  7514                 jne 0x43584b
// 00435837  8b10                 mov edx, dword ptr [eax]
// 00435839  885a10               mov byte ptr [edx + 0x10], bl
// 0043583c  50                   push eax
// 0043583d  8bcd                 mov ecx, ebp
// 0043583f  c6401000             mov byte ptr [eax + 0x10], 0
// 00435843  e898be1c00           call 0x6016e0
// 00435848  8b4608               mov eax, dword ptr [esi + 8]
// 0043584b  8a4e10               mov cl, byte ptr [esi + 0x10]
// 0043584e  884810               mov byte ptr [eax + 0x10], cl
// 00435851  885e10               mov byte ptr [esi + 0x10], bl
// 00435854  8b5008               mov edx, dword ptr [eax + 8]
// 00435857  56                   push esi
// 00435858  8bcd                 mov ecx, ebp
// 0043585a  885a10               mov byte ptr [edx + 0x10], bl
// 0043585d  e86e963200           call 0x75eed0
// 00435862  eb74                 jmp 0x4358d8
// 00435864  80781000             cmp byte ptr [eax + 0x10], 0
// 00435868  7511                 jne 0x43587b
// 0043586a  885810               mov byte ptr [eax + 0x10], bl
// 0043586d  56                   push esi
// 0043586e  8bcd                 mov ecx, ebp
// 00435870  c6461000             mov byte ptr [esi + 0x10], 0
// 00435874  e867be1c00           call 0x6016e0
// 00435879  8b06                 mov eax, dword ptr [esi]
// 0043587b  80781100             cmp byte ptr [eax + 0x11], 0
// 0043587f  7513                 jne 0x435894
// 00435881  8b4808               mov ecx, dword ptr [eax + 8]
// 00435884  385910               cmp byte ptr [ecx + 0x10], bl
// 00435887  751e                 jne 0x4358a7
// 00435889  8b10                 mov edx, dword ptr [eax]
// 0043588b  385a10               cmp byte ptr [edx + 0x10], bl
// 0043588e  7517                 jne 0x4358a7
// 00435890  c6401000             mov byte ptr [eax + 0x10], 0
// 00435894  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00435897  8bfe                 mov edi, esi
// 00435899  8b7604               mov esi, dword ptr [esi + 4]
// 0043589c  3b7804               cmp edi, dword ptr [eax + 4]
// 0043589f  0f854bffffff         jne 0x4357f0
// 004358a5  eb31                 jmp 0x4358d8
// 004358a7  8b08                 mov ecx, dword ptr [eax]
// 004358a9  385910               cmp byte ptr [ecx + 0x10], bl
// 004358ac  7514                 jne 0x4358c2
// 004358ae  8b5008               mov edx, dword ptr [eax + 8]
// 004358b1  885a10               mov byte ptr [edx + 0x10], bl
// 004358b4  50                   push eax
// 004358b5  8bcd                 mov ecx, ebp
// 004358b7  c6401000             mov byte ptr [eax + 0x10], 0
// 004358bb  e810963200           call 0x75eed0
// 004358c0  8b06                 mov eax, dword ptr [esi]
// 004358c2  8a4e10               mov cl, byte ptr [esi + 0x10]
// 004358c5  884810               mov byte ptr [eax + 0x10], cl
// 004358c8  885e10               mov byte ptr [esi + 0x10], bl
// 004358cb  8b10                 mov edx, dword ptr [eax]
// 004358cd  56                   push esi
// 004358ce  8bcd                 mov ecx, ebp
// 004358d0  885a10               mov byte ptr [edx + 0x10], bl
// 004358d3  e808be1c00           call 0x6016e0
// 004358d8  885f10               mov byte ptr [edi + 0x10], bl
// 004358db  8b442410             mov eax, dword ptr [esp + 0x10]
// 004358df  50                   push eax
// 004358e0  e8b5203700           call 0x7a799a
// 004358e5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004358e8  83c404               add esp, 4
// 004358eb  5f                   pop edi
// 004358ec  5e                   pop esi
// 004358ed  5b                   pop ebx
// 004358ee  85c0                 test eax, eax
// 004358f0  7604                 jbe 0x4358f6
// 004358f2  48                   dec eax
// 004358f3  89451c               mov dword ptr [ebp + 0x1c], eax
// 004358f6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004358fa  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004358fe  8b5500               mov edx, dword ptr [ebp]
// 00435901  894804               mov dword ptr [eax + 4], ecx
// 00435904  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00435908  8910                 mov dword ptr [eax], edx
// 0043590a  5d                   pop ebp
// 0043590b  64890d00000000       mov dword ptr fs:[0], ecx
// 00435912  83c454               add esp, 0x54
// 00435915  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
