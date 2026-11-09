// from server: 100% by auto
// roc 2007-08 0060d1d0  unit: RBX::Block  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060d1d0
//
// 0060d1d0  64a100000000         mov eax, dword ptr fs:[0]
// 0060d1d6  6aff                 push -1
// 0060d1d8  68b2417500           push 0x7541b2
// 0060d1dd  50                   push eax
// 0060d1de  64892500000000       mov dword ptr fs:[0], esp
// 0060d1e5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0060d1e9  83ec48               sub esp, 0x48
// 0060d1ec  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060d1f0  55                   push ebp
// 0060d1f1  8be9                 mov ebp, ecx
// 0060d1f3  7459                 je 0x60d24e
// 0060d1f5  68dc4e7800           push 0x784edc
// 0060d1fa  8d4c240c             lea ecx, [esp + 0xc]
// 0060d1fe  ff1598e67700         call dword ptr [0x77e698]
// 0060d204  8d4c2424             lea ecx, [esp + 0x24]
// 0060d208  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0060d210  ff15f8e67700         call dword ptr [0x77e6f8]
// 0060d216  8d442408             lea eax, [esp + 8]
// 0060d21a  50                   push eax
// 0060d21b  8d4c2434             lea ecx, [esp + 0x34]
// 0060d21f  c644245801           mov byte ptr [esp + 0x58], 1
// 0060d224  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 0060d22c  ff159ce67700         call dword ptr [0x77e69c]
// 0060d232  6864f38300           push 0x83f364
// 0060d237  8d4c2428             lea ecx, [esp + 0x28]
// 0060d23b  51                   push ecx
// 0060d23c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0060d241  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 0060d249  e850390200           call 0x630b9e
// 0060d24e  53                   push ebx
// 0060d24f  56                   push esi
// 0060d250  8bd8                 mov ebx, eax
// 0060d252  57                   push edi
// 0060d253  8d4c246c             lea ecx, [esp + 0x6c]
// 0060d257  895c2410             mov dword ptr [esp + 0x10], ebx
// 0060d25b  e820fbffff           call 0x60cd80
// 0060d260  8b03                 mov eax, dword ptr [ebx]
// 0060d262  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060d266  7405                 je 0x60d26d
// 0060d268  8b7b08               mov edi, dword ptr [ebx + 8]
// 0060d26b  eb18                 jmp 0x60d285
// 0060d26d  8b5308               mov edx, dword ptr [ebx + 8]
// 0060d270  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0060d274  7404                 je 0x60d27a
// 0060d276  8bf8                 mov edi, eax
// 0060d278  eb0b                 jmp 0x60d285
// 0060d27a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0060d27e  3bcb                 cmp ecx, ebx
// 0060d280  8b7908               mov edi, dword ptr [ecx + 8]
// 0060d283  756b                 jne 0x60d2f0
// 0060d285  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0060d289  8b7304               mov esi, dword ptr [ebx + 4]
// 0060d28c  7503                 jne 0x60d291
// 0060d28e  897704               mov dword ptr [edi + 4], esi
// 0060d291  8b4504               mov eax, dword ptr [ebp + 4]
// 0060d294  395804               cmp dword ptr [eax + 4], ebx
// 0060d297  7505                 jne 0x60d29e
// 0060d299  897804               mov dword ptr [eax + 4], edi
// 0060d29c  eb0b                 jmp 0x60d2a9
// 0060d29e  391e                 cmp dword ptr [esi], ebx
// 0060d2a0  7504                 jne 0x60d2a6
// 0060d2a2  893e                 mov dword ptr [esi], edi
// 0060d2a4  eb03                 jmp 0x60d2a9
// 0060d2a6  897e08               mov dword ptr [esi + 8], edi
// 0060d2a9  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0060d2ac  8b03                 mov eax, dword ptr [ebx]
// 0060d2ae  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0060d2b2  7515                 jne 0x60d2c9
// 0060d2b4  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0060d2b8  7404                 je 0x60d2be
// 0060d2ba  8bc6                 mov eax, esi
// 0060d2bc  eb09                 jmp 0x60d2c7
// 0060d2be  57                   push edi
// 0060d2bf  e86c070100           call 0x61da30
// 0060d2c4  83c404               add esp, 4
// 0060d2c7  8903                 mov dword ptr [ebx], eax
// 0060d2c9  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0060d2cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060d2d0  394b08               cmp dword ptr [ebx + 8], ecx
// 0060d2d3  7572                 jne 0x60d347
// 0060d2d5  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0060d2d9  7407                 je 0x60d2e2
// 0060d2db  8bc6                 mov eax, esi
// 0060d2dd  894308               mov dword ptr [ebx + 8], eax
// 0060d2e0  eb65                 jmp 0x60d347
// 0060d2e2  57                   push edi
// 0060d2e3  e8d81feeff           call 0x4ef2c0
// 0060d2e8  83c404               add esp, 4
// 0060d2eb  894308               mov dword ptr [ebx + 8], eax
// 0060d2ee  eb57                 jmp 0x60d347
// 0060d2f0  894804               mov dword ptr [eax + 4], ecx
// 0060d2f3  8b13                 mov edx, dword ptr [ebx]
// 0060d2f5  8911                 mov dword ptr [ecx], edx
// 0060d2f7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0060d2fa  7504                 jne 0x60d300
// 0060d2fc  8bf1                 mov esi, ecx
// 0060d2fe  eb1a                 jmp 0x60d31a
// 0060d300  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0060d304  8b7104               mov esi, dword ptr [ecx + 4]
// 0060d307  7503                 jne 0x60d30c
// 0060d309  897704               mov dword ptr [edi + 4], esi
// 0060d30c  893e                 mov dword ptr [esi], edi
// 0060d30e  8b4308               mov eax, dword ptr [ebx + 8]
// 0060d311  894108               mov dword ptr [ecx + 8], eax
// 0060d314  8b5308               mov edx, dword ptr [ebx + 8]
// 0060d317  894a04               mov dword ptr [edx + 4], ecx
// 0060d31a  8b4504               mov eax, dword ptr [ebp + 4]
// 0060d31d  395804               cmp dword ptr [eax + 4], ebx
// 0060d320  7505                 jne 0x60d327
// 0060d322  894804               mov dword ptr [eax + 4], ecx
// 0060d325  eb0e                 jmp 0x60d335
// 0060d327  8b4304               mov eax, dword ptr [ebx + 4]
// 0060d32a  3918                 cmp dword ptr [eax], ebx
// 0060d32c  7504                 jne 0x60d332
// 0060d32e  8908                 mov dword ptr [eax], ecx
// 0060d330  eb03                 jmp 0x60d335
// 0060d332  894808               mov dword ptr [eax + 8], ecx
// 0060d335  8b4304               mov eax, dword ptr [ebx + 4]
// 0060d338  894104               mov dword ptr [ecx + 4], eax
// 0060d33b  8a531c               mov dl, byte ptr [ebx + 0x1c]
// 0060d33e  8a411c               mov al, byte ptr [ecx + 0x1c]
// 0060d341  88511c               mov byte ptr [ecx + 0x1c], dl
// 0060d344  88431c               mov byte ptr [ebx + 0x1c], al
// 0060d347  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060d34b  b301                 mov bl, 1
// 0060d34d  38581c               cmp byte ptr [eax + 0x1c], bl
// 0060d350  0f85f2000000         jne 0x60d448
// 0060d356  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0060d359  3b7904               cmp edi, dword ptr [ecx + 4]
// 0060d35c  0f84e3000000         je 0x60d445
// 0060d362  385f1c               cmp byte ptr [edi + 0x1c], bl
// 0060d365  0f85da000000         jne 0x60d445
// 0060d36b  8b06                 mov eax, dword ptr [esi]
// 0060d36d  3bf8                 cmp edi, eax
// 0060d36f  7563                 jne 0x60d3d4
// 0060d371  8b4608               mov eax, dword ptr [esi + 8]
// 0060d374  80781c00             cmp byte ptr [eax + 0x1c], 0
// 0060d378  7512                 jne 0x60d38c
// 0060d37a  88581c               mov byte ptr [eax + 0x1c], bl
// 0060d37d  56                   push esi
// 0060d37e  8bcd                 mov ecx, ebp
// 0060d380  c6461c00             mov byte ptr [esi + 0x1c], 0
// 0060d384  e80723eeff           call 0x4ef690
// 0060d389  8b4608               mov eax, dword ptr [esi + 8]
// 0060d38c  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060d390  7572                 jne 0x60d404
// 0060d392  8b10                 mov edx, dword ptr [eax]
// 0060d394  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0060d397  7508                 jne 0x60d3a1
// 0060d399  8b4808               mov ecx, dword ptr [eax + 8]
// 0060d39c  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0060d39f  745f                 je 0x60d400
// 0060d3a1  8b4808               mov ecx, dword ptr [eax + 8]
// 0060d3a4  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0060d3a7  7512                 jne 0x60d3bb
// 0060d3a9  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d3ac  50                   push eax
// 0060d3ad  8bcd                 mov ecx, ebp
// 0060d3af  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0060d3b3  e818060100           call 0x61d9d0
// 0060d3b8  8b4608               mov eax, dword ptr [esi + 8]
// 0060d3bb  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 0060d3be  88481c               mov byte ptr [eax + 0x1c], cl
// 0060d3c1  885e1c               mov byte ptr [esi + 0x1c], bl
// 0060d3c4  8b5008               mov edx, dword ptr [eax + 8]
// 0060d3c7  56                   push esi
// 0060d3c8  8bcd                 mov ecx, ebp
// 0060d3ca  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d3cd  e8be22eeff           call 0x4ef690
// 0060d3d2  eb71                 jmp 0x60d445
// 0060d3d4  80781c00             cmp byte ptr [eax + 0x1c], 0
// 0060d3d8  7511                 jne 0x60d3eb
// 0060d3da  88581c               mov byte ptr [eax + 0x1c], bl
// 0060d3dd  56                   push esi
// 0060d3de  8bcd                 mov ecx, ebp
// 0060d3e0  c6461c00             mov byte ptr [esi + 0x1c], 0
// 0060d3e4  e8e7050100           call 0x61d9d0
// 0060d3e9  8b06                 mov eax, dword ptr [esi]
// 0060d3eb  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060d3ef  7513                 jne 0x60d404
// 0060d3f1  8b5008               mov edx, dword ptr [eax + 8]
// 0060d3f4  385a1c               cmp byte ptr [edx + 0x1c], bl
// 0060d3f7  751e                 jne 0x60d417
// 0060d3f9  8b08                 mov ecx, dword ptr [eax]
// 0060d3fb  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0060d3fe  7517                 jne 0x60d417
// 0060d400  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0060d404  8b5504               mov edx, dword ptr [ebp + 4]
// 0060d407  8bfe                 mov edi, esi
// 0060d409  3b7a04               cmp edi, dword ptr [edx + 4]
// 0060d40c  8b7604               mov esi, dword ptr [esi + 4]
// 0060d40f  0f854dffffff         jne 0x60d362
// 0060d415  eb2e                 jmp 0x60d445
// 0060d417  8b08                 mov ecx, dword ptr [eax]
// 0060d419  38591c               cmp byte ptr [ecx + 0x1c], bl
// 0060d41c  7511                 jne 0x60d42f
// 0060d41e  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d421  50                   push eax
// 0060d422  8bcd                 mov ecx, ebp
// 0060d424  c6401c00             mov byte ptr [eax + 0x1c], 0
// 0060d428  e86322eeff           call 0x4ef690
// 0060d42d  8b06                 mov eax, dword ptr [esi]
// 0060d42f  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 0060d432  88481c               mov byte ptr [eax + 0x1c], cl
// 0060d435  885e1c               mov byte ptr [esi + 0x1c], bl
// 0060d438  8b10                 mov edx, dword ptr [eax]
// 0060d43a  56                   push esi
// 0060d43b  8bcd                 mov ecx, ebp
// 0060d43d  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d440  e88b050100           call 0x61d9d0
// 0060d445  885f1c               mov byte ptr [edi + 0x1c], bl
// 0060d448  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060d44c  50                   push eax
// 0060d44d  e810280200           call 0x62fc62
// 0060d452  8b4508               mov eax, dword ptr [ebp + 8]
// 0060d455  83c404               add esp, 4
// 0060d458  85c0                 test eax, eax
// 0060d45a  5f                   pop edi
// 0060d45b  5e                   pop esi
// 0060d45c  5b                   pop ebx
// 0060d45d  7606                 jbe 0x60d465
// 0060d45f  83c0ff               add eax, -1
// 0060d462  894508               mov dword ptr [ebp + 8], eax
// 0060d465  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0060d469  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0060d46d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0060d471  8908                 mov dword ptr [eax], ecx
// 0060d473  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0060d477  895004               mov dword ptr [eax + 4], edx
// 0060d47a  5d                   pop ebp
// 0060d47b  64890d00000000       mov dword ptr fs:[0], ecx
// 0060d482  83c454               add esp, 0x54
// 0060d485  c20c00               ret 0xc
// standard library set<pod16> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
