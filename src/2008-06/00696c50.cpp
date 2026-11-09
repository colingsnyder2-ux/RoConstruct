// from server: 100% by auto
// roc 2008-06 00696c50  unit: Ogre::RbxSceneManager  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00696c50
//
// 00696c50  64a100000000         mov eax, dword ptr fs:[0]
// 00696c56  6aff                 push -1
// 00696c58  6842e87d00           push 0x7de842
// 00696c5d  50                   push eax
// 00696c5e  64892500000000       mov dword ptr fs:[0], esp
// 00696c65  8b442418             mov eax, dword ptr [esp + 0x18]
// 00696c69  83ec48               sub esp, 0x48
// 00696c6c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00696c70  55                   push ebp
// 00696c71  8be9                 mov ebp, ecx
// 00696c73  7459                 je 0x696cce
// 00696c75  6870b28000           push 0x80b270
// 00696c7a  8d4c240c             lea ecx, [esp + 0xc]
// 00696c7e  ff1558248000         call dword ptr [0x802458]
// 00696c84  8d4c2424             lea ecx, [esp + 0x24]
// 00696c88  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00696c90  ff1598288000         call dword ptr [0x802898]
// 00696c96  8d442408             lea eax, [esp + 8]
// 00696c9a  50                   push eax
// 00696c9b  8d4c2434             lea ecx, [esp + 0x34]
// 00696c9f  c644245801           mov byte ptr [esp + 0x58], 1
// 00696ca4  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 00696cac  ff155c248000         call dword ptr [0x80245c]
// 00696cb2  683c0c8d00           push 0x8d0c3c
// 00696cb7  8d4c2428             lea ecx, [esp + 0x28]
// 00696cbb  51                   push ecx
// 00696cbc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00696cc1  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00696cc9  e8bea80000           call 0x6a158c
// 00696cce  53                   push ebx
// 00696ccf  56                   push esi
// 00696cd0  8bd8                 mov ebx, eax
// 00696cd2  57                   push edi
// 00696cd3  8d4c246c             lea ecx, [esp + 0x6c]
// 00696cd7  895c2410             mov dword ptr [esp + 0x10], ebx
// 00696cdb  e8c064ffff           call 0x68d1a0
// 00696ce0  8b0b                 mov ecx, dword ptr [ebx]
// 00696ce2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00696ce6  7405                 je 0x696ced
// 00696ce8  8b7b08               mov edi, dword ptr [ebx + 8]
// 00696ceb  eb1b                 jmp 0x696d08
// 00696ced  8b5308               mov edx, dword ptr [ebx + 8]
// 00696cf0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00696cf4  7404                 je 0x696cfa
// 00696cf6  8bf9                 mov edi, ecx
// 00696cf8  eb0e                 jmp 0x696d08
// 00696cfa  8b442470             mov eax, dword ptr [esp + 0x70]
// 00696cfe  8b7808               mov edi, dword ptr [eax + 8]
// 00696d01  8d5008               lea edx, [eax + 8]
// 00696d04  3bc3                 cmp eax, ebx
// 00696d06  756b                 jne 0x696d73
// 00696d08  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00696d0c  8b7304               mov esi, dword ptr [ebx + 4]
// 00696d0f  7503                 jne 0x696d14
// 00696d11  897704               mov dword ptr [edi + 4], esi
// 00696d14  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00696d17  395804               cmp dword ptr [eax + 4], ebx
// 00696d1a  7505                 jne 0x696d21
// 00696d1c  897804               mov dword ptr [eax + 4], edi
// 00696d1f  eb0b                 jmp 0x696d2c
// 00696d21  391e                 cmp dword ptr [esi], ebx
// 00696d23  7504                 jne 0x696d29
// 00696d25  893e                 mov dword ptr [esi], edi
// 00696d27  eb03                 jmp 0x696d2c
// 00696d29  897e08               mov dword ptr [esi + 8], edi
// 00696d2c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00696d2f  8b03                 mov eax, dword ptr [ebx]
// 00696d31  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00696d35  7515                 jne 0x696d4c
// 00696d37  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00696d3b  7404                 je 0x696d41
// 00696d3d  8bc6                 mov eax, esi
// 00696d3f  eb09                 jmp 0x696d4a
// 00696d41  57                   push edi
// 00696d42  e83963ffff           call 0x68d080
// 00696d47  83c404               add esp, 4
// 00696d4a  8903                 mov dword ptr [ebx], eax
// 00696d4c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00696d4f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00696d53  394b08               cmp dword ptr [ebx + 8], ecx
// 00696d56  7577                 jne 0x696dcf
// 00696d58  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00696d5c  7407                 je 0x696d65
// 00696d5e  8bc6                 mov eax, esi
// 00696d60  894308               mov dword ptr [ebx + 8], eax
// 00696d63  eb6a                 jmp 0x696dcf
// 00696d65  57                   push edi
// 00696d66  e8f562ffff           call 0x68d060
// 00696d6b  83c404               add esp, 4
// 00696d6e  894308               mov dword ptr [ebx + 8], eax
// 00696d71  eb5c                 jmp 0x696dcf
// 00696d73  894104               mov dword ptr [ecx + 4], eax
// 00696d76  8b0b                 mov ecx, dword ptr [ebx]
// 00696d78  8908                 mov dword ptr [eax], ecx
// 00696d7a  3b4308               cmp eax, dword ptr [ebx + 8]
// 00696d7d  7504                 jne 0x696d83
// 00696d7f  8bf0                 mov esi, eax
// 00696d81  eb19                 jmp 0x696d9c
// 00696d83  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00696d87  8b7004               mov esi, dword ptr [eax + 4]
// 00696d8a  7503                 jne 0x696d8f
// 00696d8c  897704               mov dword ptr [edi + 4], esi
// 00696d8f  893e                 mov dword ptr [esi], edi
// 00696d91  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00696d94  890a                 mov dword ptr [edx], ecx
// 00696d96  8b5308               mov edx, dword ptr [ebx + 8]
// 00696d99  894204               mov dword ptr [edx + 4], eax
// 00696d9c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00696d9f  395904               cmp dword ptr [ecx + 4], ebx
// 00696da2  7505                 jne 0x696da9
// 00696da4  894104               mov dword ptr [ecx + 4], eax
// 00696da7  eb0e                 jmp 0x696db7
// 00696da9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00696dac  3919                 cmp dword ptr [ecx], ebx
// 00696dae  7504                 jne 0x696db4
// 00696db0  8901                 mov dword ptr [ecx], eax
// 00696db2  eb03                 jmp 0x696db7
// 00696db4  894108               mov dword ptr [ecx + 8], eax
// 00696db7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00696dba  894804               mov dword ptr [eax + 4], ecx
// 00696dbd  8d4b2c               lea ecx, [ebx + 0x2c]
// 00696dc0  83c02c               add eax, 0x2c
// 00696dc3  3bc1                 cmp eax, ecx
// 00696dc5  7408                 je 0x696dcf
// 00696dc7  8a19                 mov bl, byte ptr [ecx]
// 00696dc9  8a10                 mov dl, byte ptr [eax]
// 00696dcb  8818                 mov byte ptr [eax], bl
// 00696dcd  8811                 mov byte ptr [ecx], dl
// 00696dcf  8b542410             mov edx, dword ptr [esp + 0x10]
// 00696dd3  b301                 mov bl, 1
// 00696dd5  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00696dd8  0f85fd000000         jne 0x696edb
// 00696dde  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00696de1  3b7804               cmp edi, dword ptr [eax + 4]
// 00696de4  0f84ee000000         je 0x696ed8
// 00696dea  8d9b00000000         lea ebx, [ebx]
// 00696df0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 00696df3  0f85df000000         jne 0x696ed8
// 00696df9  8b06                 mov eax, dword ptr [esi]
// 00696dfb  3bf8                 cmp edi, eax
// 00696dfd  7565                 jne 0x696e64
// 00696dff  8b4608               mov eax, dword ptr [esi + 8]
// 00696e02  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00696e06  7512                 jne 0x696e1a
// 00696e08  88582c               mov byte ptr [eax + 0x2c], bl
// 00696e0b  56                   push esi
// 00696e0c  8bcd                 mov ecx, ebp
// 00696e0e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00696e12  e8e970ffff           call 0x68df00
// 00696e17  8b4608               mov eax, dword ptr [esi + 8]
// 00696e1a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00696e1e  7574                 jne 0x696e94
// 00696e20  8b08                 mov ecx, dword ptr [eax]
// 00696e22  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00696e25  7508                 jne 0x696e2f
// 00696e27  8b5008               mov edx, dword ptr [eax + 8]
// 00696e2a  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00696e2d  7461                 je 0x696e90
// 00696e2f  8b4808               mov ecx, dword ptr [eax + 8]
// 00696e32  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00696e35  7514                 jne 0x696e4b
// 00696e37  8b10                 mov edx, dword ptr [eax]
// 00696e39  885a2c               mov byte ptr [edx + 0x2c], bl
// 00696e3c  50                   push eax
// 00696e3d  8bcd                 mov ecx, ebp
// 00696e3f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00696e43  e88861ffff           call 0x68cfd0
// 00696e48  8b4608               mov eax, dword ptr [esi + 8]
// 00696e4b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 00696e4e  88482c               mov byte ptr [eax + 0x2c], cl
// 00696e51  885e2c               mov byte ptr [esi + 0x2c], bl
// 00696e54  8b5008               mov edx, dword ptr [eax + 8]
// 00696e57  56                   push esi
// 00696e58  8bcd                 mov ecx, ebp
// 00696e5a  885a2c               mov byte ptr [edx + 0x2c], bl
// 00696e5d  e89e70ffff           call 0x68df00
// 00696e62  eb74                 jmp 0x696ed8
// 00696e64  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00696e68  7511                 jne 0x696e7b
// 00696e6a  88582c               mov byte ptr [eax + 0x2c], bl
// 00696e6d  56                   push esi
// 00696e6e  8bcd                 mov ecx, ebp
// 00696e70  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00696e74  e85761ffff           call 0x68cfd0
// 00696e79  8b06                 mov eax, dword ptr [esi]
// 00696e7b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00696e7f  7513                 jne 0x696e94
// 00696e81  8b4808               mov ecx, dword ptr [eax + 8]
// 00696e84  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00696e87  751e                 jne 0x696ea7
// 00696e89  8b10                 mov edx, dword ptr [eax]
// 00696e8b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00696e8e  7517                 jne 0x696ea7
// 00696e90  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00696e94  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00696e97  8bfe                 mov edi, esi
// 00696e99  8b7604               mov esi, dword ptr [esi + 4]
// 00696e9c  3b7804               cmp edi, dword ptr [eax + 4]
// 00696e9f  0f854bffffff         jne 0x696df0
// 00696ea5  eb31                 jmp 0x696ed8
// 00696ea7  8b08                 mov ecx, dword ptr [eax]
// 00696ea9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00696eac  7514                 jne 0x696ec2
// 00696eae  8b5008               mov edx, dword ptr [eax + 8]
// 00696eb1  885a2c               mov byte ptr [edx + 0x2c], bl
// 00696eb4  50                   push eax
// 00696eb5  8bcd                 mov ecx, ebp
// 00696eb7  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00696ebb  e84070ffff           call 0x68df00
// 00696ec0  8b06                 mov eax, dword ptr [esi]
// 00696ec2  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 00696ec5  88482c               mov byte ptr [eax + 0x2c], cl
// 00696ec8  885e2c               mov byte ptr [esi + 0x2c], bl
// 00696ecb  8b10                 mov edx, dword ptr [eax]
// 00696ecd  56                   push esi
// 00696ece  8bcd                 mov ecx, ebp
// 00696ed0  885a2c               mov byte ptr [edx + 0x2c], bl
// 00696ed3  e8f860ffff           call 0x68cfd0
// 00696ed8  885f2c               mov byte ptr [edi + 0x2c], bl
// 00696edb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00696edf  83c10c               add ecx, 0xc
// 00696ee2  ff1568248000         call dword ptr [0x802468]
// 00696ee8  8b442410             mov eax, dword ptr [esp + 0x10]
// 00696eec  50                   push eax
// 00696eed  e888970000           call 0x6a067a
// 00696ef2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00696ef5  83c404               add esp, 4
// 00696ef8  5f                   pop edi
// 00696ef9  5e                   pop esi
// 00696efa  5b                   pop ebx
// 00696efb  85c0                 test eax, eax
// 00696efd  7604                 jbe 0x696f03
// 00696eff  48                   dec eax
// 00696f00  89451c               mov dword ptr [ebp + 0x1c], eax
// 00696f03  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00696f07  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00696f0b  8b5500               mov edx, dword ptr [ebp]
// 00696f0e  894804               mov dword ptr [eax + 4], ecx
// 00696f11  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00696f15  8910                 mov dword ptr [eax], edx
// 00696f17  5d                   pop ebp
// 00696f18  64890d00000000       mov dword ptr fs:[0], ecx
// 00696f1f  83c454               add esp, 0x54
// 00696f22  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
