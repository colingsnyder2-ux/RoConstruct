// from server: 100% by auto
// roc 2007-08 00543190  unit: RBX::VDebugSettings::?$FactoryProduct  size: 709 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00543190
//
// 00543190  64a100000000         mov eax, dword ptr fs:[0]
// 00543196  6aff                 push -1
// 00543198  68b2417500           push 0x7541b2
// 0054319d  50                   push eax
// 0054319e  64892500000000       mov dword ptr fs:[0], esp
// 005431a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005431a9  83ec48               sub esp, 0x48
// 005431ac  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005431b0  55                   push ebp
// 005431b1  8be9                 mov ebp, ecx
// 005431b3  7459                 je 0x54320e
// 005431b5  68dc4e7800           push 0x784edc
// 005431ba  8d4c240c             lea ecx, [esp + 0xc]
// 005431be  ff1598e67700         call dword ptr [0x77e698]
// 005431c4  8d4c2424             lea ecx, [esp + 0x24]
// 005431c8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005431d0  ff15f8e67700         call dword ptr [0x77e6f8]
// 005431d6  8d442408             lea eax, [esp + 8]
// 005431da  50                   push eax
// 005431db  8d4c2434             lea ecx, [esp + 0x34]
// 005431df  c644245801           mov byte ptr [esp + 0x58], 1
// 005431e4  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 005431ec  ff159ce67700         call dword ptr [0x77e69c]
// 005431f2  6864f38300           push 0x83f364
// 005431f7  8d4c2428             lea ecx, [esp + 0x28]
// 005431fb  51                   push ecx
// 005431fc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00543201  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 00543209  e890d90e00           call 0x630b9e
// 0054320e  53                   push ebx
// 0054320f  56                   push esi
// 00543210  8bd8                 mov ebx, eax
// 00543212  57                   push edi
// 00543213  8d4c246c             lea ecx, [esp + 0x6c]
// 00543217  895c2410             mov dword ptr [esp + 0x10], ebx
// 0054321b  e8006d0900           call 0x5d9f20
// 00543220  8b03                 mov eax, dword ptr [ebx]
// 00543222  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00543226  7405                 je 0x54322d
// 00543228  8b7b08               mov edi, dword ptr [ebx + 8]
// 0054322b  eb18                 jmp 0x543245
// 0054322d  8b5308               mov edx, dword ptr [ebx + 8]
// 00543230  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00543234  7404                 je 0x54323a
// 00543236  8bf8                 mov edi, eax
// 00543238  eb0b                 jmp 0x543245
// 0054323a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0054323e  3bcb                 cmp ecx, ebx
// 00543240  8b7908               mov edi, dword ptr [ecx + 8]
// 00543243  756b                 jne 0x5432b0
// 00543245  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00543249  8b7304               mov esi, dword ptr [ebx + 4]
// 0054324c  7503                 jne 0x543251
// 0054324e  897704               mov dword ptr [edi + 4], esi
// 00543251  8b4504               mov eax, dword ptr [ebp + 4]
// 00543254  395804               cmp dword ptr [eax + 4], ebx
// 00543257  7505                 jne 0x54325e
// 00543259  897804               mov dword ptr [eax + 4], edi
// 0054325c  eb0b                 jmp 0x543269
// 0054325e  391e                 cmp dword ptr [esi], ebx
// 00543260  7504                 jne 0x543266
// 00543262  893e                 mov dword ptr [esi], edi
// 00543264  eb03                 jmp 0x543269
// 00543266  897e08               mov dword ptr [esi + 8], edi
// 00543269  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0054326c  8b03                 mov eax, dword ptr [ebx]
// 0054326e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00543272  7515                 jne 0x543289
// 00543274  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00543278  7404                 je 0x54327e
// 0054327a  8bc6                 mov eax, esi
// 0054327c  eb09                 jmp 0x543287
// 0054327e  57                   push edi
// 0054327f  e80cd1f5ff           call 0x4a0390
// 00543284  83c404               add esp, 4
// 00543287  8903                 mov dword ptr [ebx], eax
// 00543289  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0054328c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00543290  394b08               cmp dword ptr [ebx + 8], ecx
// 00543293  7572                 jne 0x543307
// 00543295  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00543299  7407                 je 0x5432a2
// 0054329b  8bc6                 mov eax, esi
// 0054329d  894308               mov dword ptr [ebx + 8], eax
// 005432a0  eb65                 jmp 0x543307
// 005432a2  57                   push edi
// 005432a3  e8a8640500           call 0x599750
// 005432a8  83c404               add esp, 4
// 005432ab  894308               mov dword ptr [ebx + 8], eax
// 005432ae  eb57                 jmp 0x543307
// 005432b0  894804               mov dword ptr [eax + 4], ecx
// 005432b3  8b13                 mov edx, dword ptr [ebx]
// 005432b5  8911                 mov dword ptr [ecx], edx
// 005432b7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005432ba  7504                 jne 0x5432c0
// 005432bc  8bf1                 mov esi, ecx
// 005432be  eb1a                 jmp 0x5432da
// 005432c0  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005432c4  8b7104               mov esi, dword ptr [ecx + 4]
// 005432c7  7503                 jne 0x5432cc
// 005432c9  897704               mov dword ptr [edi + 4], esi
// 005432cc  893e                 mov dword ptr [esi], edi
// 005432ce  8b4308               mov eax, dword ptr [ebx + 8]
// 005432d1  894108               mov dword ptr [ecx + 8], eax
// 005432d4  8b5308               mov edx, dword ptr [ebx + 8]
// 005432d7  894a04               mov dword ptr [edx + 4], ecx
// 005432da  8b4504               mov eax, dword ptr [ebp + 4]
// 005432dd  395804               cmp dword ptr [eax + 4], ebx
// 005432e0  7505                 jne 0x5432e7
// 005432e2  894804               mov dword ptr [eax + 4], ecx
// 005432e5  eb0e                 jmp 0x5432f5
// 005432e7  8b4304               mov eax, dword ptr [ebx + 4]
// 005432ea  3918                 cmp dword ptr [eax], ebx
// 005432ec  7504                 jne 0x5432f2
// 005432ee  8908                 mov dword ptr [eax], ecx
// 005432f0  eb03                 jmp 0x5432f5
// 005432f2  894808               mov dword ptr [eax + 8], ecx
// 005432f5  8b4304               mov eax, dword ptr [ebx + 4]
// 005432f8  894104               mov dword ptr [ecx + 4], eax
// 005432fb  8a532c               mov dl, byte ptr [ebx + 0x2c]
// 005432fe  8a412c               mov al, byte ptr [ecx + 0x2c]
// 00543301  88512c               mov byte ptr [ecx + 0x2c], dl
// 00543304  88432c               mov byte ptr [ebx + 0x2c], al
// 00543307  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054330b  b301                 mov bl, 1
// 0054330d  38582c               cmp byte ptr [eax + 0x2c], bl
// 00543310  0f85f2000000         jne 0x543408
// 00543316  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00543319  3b7904               cmp edi, dword ptr [ecx + 4]
// 0054331c  0f84e3000000         je 0x543405
// 00543322  385f2c               cmp byte ptr [edi + 0x2c], bl
// 00543325  0f85da000000         jne 0x543405
// 0054332b  8b06                 mov eax, dword ptr [esi]
// 0054332d  3bf8                 cmp edi, eax
// 0054332f  7563                 jne 0x543394
// 00543331  8b4608               mov eax, dword ptr [esi + 8]
// 00543334  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00543338  7512                 jne 0x54334c
// 0054333a  88582c               mov byte ptr [eax + 0x2c], bl
// 0054333d  56                   push esi
// 0054333e  8bcd                 mov ecx, ebp
// 00543340  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00543344  e847dcf5ff           call 0x4a0f90
// 00543349  8b4608               mov eax, dword ptr [esi + 8]
// 0054334c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00543350  7572                 jne 0x5433c4
// 00543352  8b10                 mov edx, dword ptr [eax]
// 00543354  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00543357  7508                 jne 0x543361
// 00543359  8b4808               mov ecx, dword ptr [eax + 8]
// 0054335c  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0054335f  745f                 je 0x5433c0
// 00543361  8b4808               mov ecx, dword ptr [eax + 8]
// 00543364  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00543367  7512                 jne 0x54337b
// 00543369  885a2c               mov byte ptr [edx + 0x2c], bl
// 0054336c  50                   push eax
// 0054336d  8bcd                 mov ecx, ebp
// 0054336f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00543373  e868dbf5ff           call 0x4a0ee0
// 00543378  8b4608               mov eax, dword ptr [esi + 8]
// 0054337b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0054337e  88482c               mov byte ptr [eax + 0x2c], cl
// 00543381  885e2c               mov byte ptr [esi + 0x2c], bl
// 00543384  8b5008               mov edx, dword ptr [eax + 8]
// 00543387  56                   push esi
// 00543388  8bcd                 mov ecx, ebp
// 0054338a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0054338d  e8fedbf5ff           call 0x4a0f90
// 00543392  eb71                 jmp 0x543405
// 00543394  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00543398  7511                 jne 0x5433ab
// 0054339a  88582c               mov byte ptr [eax + 0x2c], bl
// 0054339d  56                   push esi
// 0054339e  8bcd                 mov ecx, ebp
// 005433a0  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005433a4  e837dbf5ff           call 0x4a0ee0
// 005433a9  8b06                 mov eax, dword ptr [esi]
// 005433ab  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005433af  7513                 jne 0x5433c4
// 005433b1  8b5008               mov edx, dword ptr [eax + 8]
// 005433b4  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005433b7  751e                 jne 0x5433d7
// 005433b9  8b08                 mov ecx, dword ptr [eax]
// 005433bb  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005433be  7517                 jne 0x5433d7
// 005433c0  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005433c4  8b5504               mov edx, dword ptr [ebp + 4]
// 005433c7  8bfe                 mov edi, esi
// 005433c9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005433cc  8b7604               mov esi, dword ptr [esi + 4]
// 005433cf  0f854dffffff         jne 0x543322
// 005433d5  eb2e                 jmp 0x543405
// 005433d7  8b08                 mov ecx, dword ptr [eax]
// 005433d9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005433dc  7511                 jne 0x5433ef
// 005433de  885a2c               mov byte ptr [edx + 0x2c], bl
// 005433e1  50                   push eax
// 005433e2  8bcd                 mov ecx, ebp
// 005433e4  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005433e8  e8a3dbf5ff           call 0x4a0f90
// 005433ed  8b06                 mov eax, dword ptr [esi]
// 005433ef  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 005433f2  88482c               mov byte ptr [eax + 0x2c], cl
// 005433f5  885e2c               mov byte ptr [esi + 0x2c], bl
// 005433f8  8b10                 mov edx, dword ptr [eax]
// 005433fa  56                   push esi
// 005433fb  8bcd                 mov ecx, ebp
// 005433fd  885a2c               mov byte ptr [edx + 0x2c], bl
// 00543400  e8dbdaf5ff           call 0x4a0ee0
// 00543405  885f2c               mov byte ptr [edi + 0x2c], bl
// 00543408  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054340c  83c10c               add ecx, 0xc
// 0054340f  ff15ace67700         call dword ptr [0x77e6ac]
// 00543415  8b442410             mov eax, dword ptr [esp + 0x10]
// 00543419  50                   push eax
// 0054341a  e843c80e00           call 0x62fc62
// 0054341f  8b4508               mov eax, dword ptr [ebp + 8]
// 00543422  83c404               add esp, 4
// 00543425  85c0                 test eax, eax
// 00543427  5f                   pop edi
// 00543428  5e                   pop esi
// 00543429  5b                   pop ebx
// 0054342a  7606                 jbe 0x543432
// 0054342c  83c0ff               add eax, -1
// 0054342f  894508               mov dword ptr [ebp + 8], eax
// 00543432  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00543436  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0054343a  8b542464             mov edx, dword ptr [esp + 0x64]
// 0054343e  8908                 mov dword ptr [eax], ecx
// 00543440  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00543444  895004               mov dword ptr [eax + 4], edx
// 00543447  5d                   pop ebp
// 00543448  64890d00000000       mov dword ptr fs:[0], ecx
// 0054344f  83c454               add esp, 0x54
// 00543452  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
