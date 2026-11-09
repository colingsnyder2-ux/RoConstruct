// from server: 100% by auto
// roc 2007-08 00584430  unit: RBX::VHat::?$FactoryProduct  size: 709 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584430
//
// 00584430  64a100000000         mov eax, dword ptr fs:[0]
// 00584436  6aff                 push -1
// 00584438  68b2417500           push 0x7541b2
// 0058443d  50                   push eax
// 0058443e  64892500000000       mov dword ptr fs:[0], esp
// 00584445  8b442418             mov eax, dword ptr [esp + 0x18]
// 00584449  83ec48               sub esp, 0x48
// 0058444c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00584450  55                   push ebp
// 00584451  8be9                 mov ebp, ecx
// 00584453  7459                 je 0x5844ae
// 00584455  68dc4e7800           push 0x784edc
// 0058445a  8d4c240c             lea ecx, [esp + 0xc]
// 0058445e  ff1598e67700         call dword ptr [0x77e698]
// 00584464  8d4c2424             lea ecx, [esp + 0x24]
// 00584468  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00584470  ff15f8e67700         call dword ptr [0x77e6f8]
// 00584476  8d442408             lea eax, [esp + 8]
// 0058447a  50                   push eax
// 0058447b  8d4c2434             lea ecx, [esp + 0x34]
// 0058447f  c644245801           mov byte ptr [esp + 0x58], 1
// 00584484  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 0058448c  ff159ce67700         call dword ptr [0x77e69c]
// 00584492  6864f38300           push 0x83f364
// 00584497  8d4c2428             lea ecx, [esp + 0x28]
// 0058449b  51                   push ecx
// 0058449c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005844a1  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 005844a9  e8f0c60a00           call 0x630b9e
// 005844ae  53                   push ebx
// 005844af  56                   push esi
// 005844b0  8bd8                 mov ebx, eax
// 005844b2  57                   push edi
// 005844b3  8d4c246c             lea ecx, [esp + 0x6c]
// 005844b7  895c2410             mov dword ptr [esp + 0x10], ebx
// 005844bb  e8605a0500           call 0x5d9f20
// 005844c0  8b03                 mov eax, dword ptr [ebx]
// 005844c2  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005844c6  7405                 je 0x5844cd
// 005844c8  8b7b08               mov edi, dword ptr [ebx + 8]
// 005844cb  eb18                 jmp 0x5844e5
// 005844cd  8b5308               mov edx, dword ptr [ebx + 8]
// 005844d0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005844d4  7404                 je 0x5844da
// 005844d6  8bf8                 mov edi, eax
// 005844d8  eb0b                 jmp 0x5844e5
// 005844da  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005844de  3bcb                 cmp ecx, ebx
// 005844e0  8b7908               mov edi, dword ptr [ecx + 8]
// 005844e3  756b                 jne 0x584550
// 005844e5  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005844e9  8b7304               mov esi, dword ptr [ebx + 4]
// 005844ec  7503                 jne 0x5844f1
// 005844ee  897704               mov dword ptr [edi + 4], esi
// 005844f1  8b4504               mov eax, dword ptr [ebp + 4]
// 005844f4  395804               cmp dword ptr [eax + 4], ebx
// 005844f7  7505                 jne 0x5844fe
// 005844f9  897804               mov dword ptr [eax + 4], edi
// 005844fc  eb0b                 jmp 0x584509
// 005844fe  391e                 cmp dword ptr [esi], ebx
// 00584500  7504                 jne 0x584506
// 00584502  893e                 mov dword ptr [esi], edi
// 00584504  eb03                 jmp 0x584509
// 00584506  897e08               mov dword ptr [esi + 8], edi
// 00584509  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0058450c  8b03                 mov eax, dword ptr [ebx]
// 0058450e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00584512  7515                 jne 0x584529
// 00584514  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00584518  7404                 je 0x58451e
// 0058451a  8bc6                 mov eax, esi
// 0058451c  eb09                 jmp 0x584527
// 0058451e  57                   push edi
// 0058451f  e86cbef1ff           call 0x4a0390
// 00584524  83c404               add esp, 4
// 00584527  8903                 mov dword ptr [ebx], eax
// 00584529  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0058452c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00584530  394b08               cmp dword ptr [ebx + 8], ecx
// 00584533  7572                 jne 0x5845a7
// 00584535  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00584539  7407                 je 0x584542
// 0058453b  8bc6                 mov eax, esi
// 0058453d  894308               mov dword ptr [ebx + 8], eax
// 00584540  eb65                 jmp 0x5845a7
// 00584542  57                   push edi
// 00584543  e808520100           call 0x599750
// 00584548  83c404               add esp, 4
// 0058454b  894308               mov dword ptr [ebx + 8], eax
// 0058454e  eb57                 jmp 0x5845a7
// 00584550  894804               mov dword ptr [eax + 4], ecx
// 00584553  8b13                 mov edx, dword ptr [ebx]
// 00584555  8911                 mov dword ptr [ecx], edx
// 00584557  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0058455a  7504                 jne 0x584560
// 0058455c  8bf1                 mov esi, ecx
// 0058455e  eb1a                 jmp 0x58457a
// 00584560  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00584564  8b7104               mov esi, dword ptr [ecx + 4]
// 00584567  7503                 jne 0x58456c
// 00584569  897704               mov dword ptr [edi + 4], esi
// 0058456c  893e                 mov dword ptr [esi], edi
// 0058456e  8b4308               mov eax, dword ptr [ebx + 8]
// 00584571  894108               mov dword ptr [ecx + 8], eax
// 00584574  8b5308               mov edx, dword ptr [ebx + 8]
// 00584577  894a04               mov dword ptr [edx + 4], ecx
// 0058457a  8b4504               mov eax, dword ptr [ebp + 4]
// 0058457d  395804               cmp dword ptr [eax + 4], ebx
// 00584580  7505                 jne 0x584587
// 00584582  894804               mov dword ptr [eax + 4], ecx
// 00584585  eb0e                 jmp 0x584595
// 00584587  8b4304               mov eax, dword ptr [ebx + 4]
// 0058458a  3918                 cmp dword ptr [eax], ebx
// 0058458c  7504                 jne 0x584592
// 0058458e  8908                 mov dword ptr [eax], ecx
// 00584590  eb03                 jmp 0x584595
// 00584592  894808               mov dword ptr [eax + 8], ecx
// 00584595  8b4304               mov eax, dword ptr [ebx + 4]
// 00584598  894104               mov dword ptr [ecx + 4], eax
// 0058459b  8a532c               mov dl, byte ptr [ebx + 0x2c]
// 0058459e  8a412c               mov al, byte ptr [ecx + 0x2c]
// 005845a1  88512c               mov byte ptr [ecx + 0x2c], dl
// 005845a4  88432c               mov byte ptr [ebx + 0x2c], al
// 005845a7  8b442410             mov eax, dword ptr [esp + 0x10]
// 005845ab  b301                 mov bl, 1
// 005845ad  38582c               cmp byte ptr [eax + 0x2c], bl
// 005845b0  0f85f2000000         jne 0x5846a8
// 005845b6  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005845b9  3b7904               cmp edi, dword ptr [ecx + 4]
// 005845bc  0f84e3000000         je 0x5846a5
// 005845c2  385f2c               cmp byte ptr [edi + 0x2c], bl
// 005845c5  0f85da000000         jne 0x5846a5
// 005845cb  8b06                 mov eax, dword ptr [esi]
// 005845cd  3bf8                 cmp edi, eax
// 005845cf  7563                 jne 0x584634
// 005845d1  8b4608               mov eax, dword ptr [esi + 8]
// 005845d4  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005845d8  7512                 jne 0x5845ec
// 005845da  88582c               mov byte ptr [eax + 0x2c], bl
// 005845dd  56                   push esi
// 005845de  8bcd                 mov ecx, ebp
// 005845e0  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005845e4  e8a7c9f1ff           call 0x4a0f90
// 005845e9  8b4608               mov eax, dword ptr [esi + 8]
// 005845ec  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005845f0  7572                 jne 0x584664
// 005845f2  8b10                 mov edx, dword ptr [eax]
// 005845f4  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005845f7  7508                 jne 0x584601
// 005845f9  8b4808               mov ecx, dword ptr [eax + 8]
// 005845fc  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005845ff  745f                 je 0x584660
// 00584601  8b4808               mov ecx, dword ptr [eax + 8]
// 00584604  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00584607  7512                 jne 0x58461b
// 00584609  885a2c               mov byte ptr [edx + 0x2c], bl
// 0058460c  50                   push eax
// 0058460d  8bcd                 mov ecx, ebp
// 0058460f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00584613  e8c8c8f1ff           call 0x4a0ee0
// 00584618  8b4608               mov eax, dword ptr [esi + 8]
// 0058461b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0058461e  88482c               mov byte ptr [eax + 0x2c], cl
// 00584621  885e2c               mov byte ptr [esi + 0x2c], bl
// 00584624  8b5008               mov edx, dword ptr [eax + 8]
// 00584627  56                   push esi
// 00584628  8bcd                 mov ecx, ebp
// 0058462a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0058462d  e85ec9f1ff           call 0x4a0f90
// 00584632  eb71                 jmp 0x5846a5
// 00584634  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00584638  7511                 jne 0x58464b
// 0058463a  88582c               mov byte ptr [eax + 0x2c], bl
// 0058463d  56                   push esi
// 0058463e  8bcd                 mov ecx, ebp
// 00584640  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00584644  e897c8f1ff           call 0x4a0ee0
// 00584649  8b06                 mov eax, dword ptr [esi]
// 0058464b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0058464f  7513                 jne 0x584664
// 00584651  8b5008               mov edx, dword ptr [eax + 8]
// 00584654  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00584657  751e                 jne 0x584677
// 00584659  8b08                 mov ecx, dword ptr [eax]
// 0058465b  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0058465e  7517                 jne 0x584677
// 00584660  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00584664  8b5504               mov edx, dword ptr [ebp + 4]
// 00584667  8bfe                 mov edi, esi
// 00584669  3b7a04               cmp edi, dword ptr [edx + 4]
// 0058466c  8b7604               mov esi, dword ptr [esi + 4]
// 0058466f  0f854dffffff         jne 0x5845c2
// 00584675  eb2e                 jmp 0x5846a5
// 00584677  8b08                 mov ecx, dword ptr [eax]
// 00584679  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0058467c  7511                 jne 0x58468f
// 0058467e  885a2c               mov byte ptr [edx + 0x2c], bl
// 00584681  50                   push eax
// 00584682  8bcd                 mov ecx, ebp
// 00584684  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00584688  e803c9f1ff           call 0x4a0f90
// 0058468d  8b06                 mov eax, dword ptr [esi]
// 0058468f  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 00584692  88482c               mov byte ptr [eax + 0x2c], cl
// 00584695  885e2c               mov byte ptr [esi + 0x2c], bl
// 00584698  8b10                 mov edx, dword ptr [eax]
// 0058469a  56                   push esi
// 0058469b  8bcd                 mov ecx, ebp
// 0058469d  885a2c               mov byte ptr [edx + 0x2c], bl
// 005846a0  e83bc8f1ff           call 0x4a0ee0
// 005846a5  885f2c               mov byte ptr [edi + 0x2c], bl
// 005846a8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005846ac  83c110               add ecx, 0x10
// 005846af  ff15ace67700         call dword ptr [0x77e6ac]
// 005846b5  8b442410             mov eax, dword ptr [esp + 0x10]
// 005846b9  50                   push eax
// 005846ba  e8a3b50a00           call 0x62fc62
// 005846bf  8b4508               mov eax, dword ptr [ebp + 8]
// 005846c2  83c404               add esp, 4
// 005846c5  85c0                 test eax, eax
// 005846c7  5f                   pop edi
// 005846c8  5e                   pop esi
// 005846c9  5b                   pop ebx
// 005846ca  7606                 jbe 0x5846d2
// 005846cc  83c0ff               add eax, -1
// 005846cf  894508               mov dword ptr [ebp + 8], eax
// 005846d2  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005846d6  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005846da  8b542464             mov edx, dword ptr [esp + 0x64]
// 005846de  8908                 mov dword ptr [eax], ecx
// 005846e0  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005846e4  895004               mov dword ptr [eax + 4], edx
// 005846e7  5d                   pop ebp
// 005846e8  64890d00000000       mov dword ptr fs:[0], ecx
// 005846ef  83c454               add esp, 0x54
// 005846f2  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
