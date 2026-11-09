// from server: 100% by auto
// roc 2007-08 005b7170  unit: RBX::$01MP8Surface::?$SurfaceGetSet  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b7170
//
// 005b7170  64a100000000         mov eax, dword ptr fs:[0]
// 005b7176  6aff                 push -1
// 005b7178  68b2417500           push 0x7541b2
// 005b717d  50                   push eax
// 005b717e  64892500000000       mov dword ptr fs:[0], esp
// 005b7185  8b442418             mov eax, dword ptr [esp + 0x18]
// 005b7189  83ec48               sub esp, 0x48
// 005b718c  80781500             cmp byte ptr [eax + 0x15], 0
// 005b7190  55                   push ebp
// 005b7191  8be9                 mov ebp, ecx
// 005b7193  7459                 je 0x5b71ee
// 005b7195  68dc4e7800           push 0x784edc
// 005b719a  8d4c240c             lea ecx, [esp + 0xc]
// 005b719e  ff1598e67700         call dword ptr [0x77e698]
// 005b71a4  8d4c2424             lea ecx, [esp + 0x24]
// 005b71a8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005b71b0  ff15f8e67700         call dword ptr [0x77e6f8]
// 005b71b6  8d442408             lea eax, [esp + 8]
// 005b71ba  50                   push eax
// 005b71bb  8d4c2434             lea ecx, [esp + 0x34]
// 005b71bf  c644245801           mov byte ptr [esp + 0x58], 1
// 005b71c4  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 005b71cc  ff159ce67700         call dword ptr [0x77e69c]
// 005b71d2  6864f38300           push 0x83f364
// 005b71d7  8d4c2428             lea ecx, [esp + 0x28]
// 005b71db  51                   push ecx
// 005b71dc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005b71e1  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 005b71e9  e8b0990700           call 0x630b9e
// 005b71ee  53                   push ebx
// 005b71ef  56                   push esi
// 005b71f0  8bd8                 mov ebx, eax
// 005b71f2  57                   push edi
// 005b71f3  8d4c246c             lea ecx, [esp + 0x6c]
// 005b71f7  895c2410             mov dword ptr [esp + 0x10], ebx
// 005b71fb  e8b01ce8ff           call 0x438eb0
// 005b7200  8b03                 mov eax, dword ptr [ebx]
// 005b7202  80781500             cmp byte ptr [eax + 0x15], 0
// 005b7206  7405                 je 0x5b720d
// 005b7208  8b7b08               mov edi, dword ptr [ebx + 8]
// 005b720b  eb18                 jmp 0x5b7225
// 005b720d  8b5308               mov edx, dword ptr [ebx + 8]
// 005b7210  807a1500             cmp byte ptr [edx + 0x15], 0
// 005b7214  7404                 je 0x5b721a
// 005b7216  8bf8                 mov edi, eax
// 005b7218  eb0b                 jmp 0x5b7225
// 005b721a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005b721e  3bcb                 cmp ecx, ebx
// 005b7220  8b7908               mov edi, dword ptr [ecx + 8]
// 005b7223  756b                 jne 0x5b7290
// 005b7225  807f1500             cmp byte ptr [edi + 0x15], 0
// 005b7229  8b7304               mov esi, dword ptr [ebx + 4]
// 005b722c  7503                 jne 0x5b7231
// 005b722e  897704               mov dword ptr [edi + 4], esi
// 005b7231  8b4504               mov eax, dword ptr [ebp + 4]
// 005b7234  395804               cmp dword ptr [eax + 4], ebx
// 005b7237  7505                 jne 0x5b723e
// 005b7239  897804               mov dword ptr [eax + 4], edi
// 005b723c  eb0b                 jmp 0x5b7249
// 005b723e  391e                 cmp dword ptr [esi], ebx
// 005b7240  7504                 jne 0x5b7246
// 005b7242  893e                 mov dword ptr [esi], edi
// 005b7244  eb03                 jmp 0x5b7249
// 005b7246  897e08               mov dword ptr [esi + 8], edi
// 005b7249  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005b724c  8b03                 mov eax, dword ptr [ebx]
// 005b724e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005b7252  7515                 jne 0x5b7269
// 005b7254  807f1500             cmp byte ptr [edi + 0x15], 0
// 005b7258  7404                 je 0x5b725e
// 005b725a  8bc6                 mov eax, esi
// 005b725c  eb09                 jmp 0x5b7267
// 005b725e  57                   push edi
// 005b725f  e8ac7ff3ff           call 0x4ef210
// 005b7264  83c404               add esp, 4
// 005b7267  8903                 mov dword ptr [ebx], eax
// 005b7269  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005b726c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b7270  394b08               cmp dword ptr [ebx + 8], ecx
// 005b7273  7572                 jne 0x5b72e7
// 005b7275  807f1500             cmp byte ptr [edi + 0x15], 0
// 005b7279  7407                 je 0x5b7282
// 005b727b  8bc6                 mov eax, esi
// 005b727d  894308               mov dword ptr [ebx + 8], eax
// 005b7280  eb65                 jmp 0x5b72e7
// 005b7282  57                   push edi
// 005b7283  e888b9f8ff           call 0x542c10
// 005b7288  83c404               add esp, 4
// 005b728b  894308               mov dword ptr [ebx + 8], eax
// 005b728e  eb57                 jmp 0x5b72e7
// 005b7290  894804               mov dword ptr [eax + 4], ecx
// 005b7293  8b13                 mov edx, dword ptr [ebx]
// 005b7295  8911                 mov dword ptr [ecx], edx
// 005b7297  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005b729a  7504                 jne 0x5b72a0
// 005b729c  8bf1                 mov esi, ecx
// 005b729e  eb1a                 jmp 0x5b72ba
// 005b72a0  807f1500             cmp byte ptr [edi + 0x15], 0
// 005b72a4  8b7104               mov esi, dword ptr [ecx + 4]
// 005b72a7  7503                 jne 0x5b72ac
// 005b72a9  897704               mov dword ptr [edi + 4], esi
// 005b72ac  893e                 mov dword ptr [esi], edi
// 005b72ae  8b4308               mov eax, dword ptr [ebx + 8]
// 005b72b1  894108               mov dword ptr [ecx + 8], eax
// 005b72b4  8b5308               mov edx, dword ptr [ebx + 8]
// 005b72b7  894a04               mov dword ptr [edx + 4], ecx
// 005b72ba  8b4504               mov eax, dword ptr [ebp + 4]
// 005b72bd  395804               cmp dword ptr [eax + 4], ebx
// 005b72c0  7505                 jne 0x5b72c7
// 005b72c2  894804               mov dword ptr [eax + 4], ecx
// 005b72c5  eb0e                 jmp 0x5b72d5
// 005b72c7  8b4304               mov eax, dword ptr [ebx + 4]
// 005b72ca  3918                 cmp dword ptr [eax], ebx
// 005b72cc  7504                 jne 0x5b72d2
// 005b72ce  8908                 mov dword ptr [eax], ecx
// 005b72d0  eb03                 jmp 0x5b72d5
// 005b72d2  894808               mov dword ptr [eax + 8], ecx
// 005b72d5  8b4304               mov eax, dword ptr [ebx + 4]
// 005b72d8  894104               mov dword ptr [ecx + 4], eax
// 005b72db  8a5314               mov dl, byte ptr [ebx + 0x14]
// 005b72de  8a4114               mov al, byte ptr [ecx + 0x14]
// 005b72e1  885114               mov byte ptr [ecx + 0x14], dl
// 005b72e4  884314               mov byte ptr [ebx + 0x14], al
// 005b72e7  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b72eb  b301                 mov bl, 1
// 005b72ed  385814               cmp byte ptr [eax + 0x14], bl
// 005b72f0  0f85f2000000         jne 0x5b73e8
// 005b72f6  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005b72f9  3b7904               cmp edi, dword ptr [ecx + 4]
// 005b72fc  0f84e3000000         je 0x5b73e5
// 005b7302  385f14               cmp byte ptr [edi + 0x14], bl
// 005b7305  0f85da000000         jne 0x5b73e5
// 005b730b  8b06                 mov eax, dword ptr [esi]
// 005b730d  3bf8                 cmp edi, eax
// 005b730f  7563                 jne 0x5b7374
// 005b7311  8b4608               mov eax, dword ptr [esi + 8]
// 005b7314  80781400             cmp byte ptr [eax + 0x14], 0
// 005b7318  7512                 jne 0x5b732c
// 005b731a  885814               mov byte ptr [eax + 0x14], bl
// 005b731d  56                   push esi
// 005b731e  8bcd                 mov ecx, ebp
// 005b7320  c6461400             mov byte ptr [esi + 0x14], 0
// 005b7324  e8b761fbff           call 0x56d4e0
// 005b7329  8b4608               mov eax, dword ptr [esi + 8]
// 005b732c  80781500             cmp byte ptr [eax + 0x15], 0
// 005b7330  7572                 jne 0x5b73a4
// 005b7332  8b10                 mov edx, dword ptr [eax]
// 005b7334  385a14               cmp byte ptr [edx + 0x14], bl
// 005b7337  7508                 jne 0x5b7341
// 005b7339  8b4808               mov ecx, dword ptr [eax + 8]
// 005b733c  385914               cmp byte ptr [ecx + 0x14], bl
// 005b733f  745f                 je 0x5b73a0
// 005b7341  8b4808               mov ecx, dword ptr [eax + 8]
// 005b7344  385914               cmp byte ptr [ecx + 0x14], bl
// 005b7347  7512                 jne 0x5b735b
// 005b7349  885a14               mov byte ptr [edx + 0x14], bl
// 005b734c  50                   push eax
// 005b734d  8bcd                 mov ecx, ebp
// 005b734f  c6401400             mov byte ptr [eax + 0x14], 0
// 005b7353  e8c8d70400           call 0x604b20
// 005b7358  8b4608               mov eax, dword ptr [esi + 8]
// 005b735b  8a4e14               mov cl, byte ptr [esi + 0x14]
// 005b735e  884814               mov byte ptr [eax + 0x14], cl
// 005b7361  885e14               mov byte ptr [esi + 0x14], bl
// 005b7364  8b5008               mov edx, dword ptr [eax + 8]
// 005b7367  56                   push esi
// 005b7368  8bcd                 mov ecx, ebp
// 005b736a  885a14               mov byte ptr [edx + 0x14], bl
// 005b736d  e86e61fbff           call 0x56d4e0
// 005b7372  eb71                 jmp 0x5b73e5
// 005b7374  80781400             cmp byte ptr [eax + 0x14], 0
// 005b7378  7511                 jne 0x5b738b
// 005b737a  885814               mov byte ptr [eax + 0x14], bl
// 005b737d  56                   push esi
// 005b737e  8bcd                 mov ecx, ebp
// 005b7380  c6461400             mov byte ptr [esi + 0x14], 0
// 005b7384  e897d70400           call 0x604b20
// 005b7389  8b06                 mov eax, dword ptr [esi]
// 005b738b  80781500             cmp byte ptr [eax + 0x15], 0
// 005b738f  7513                 jne 0x5b73a4
// 005b7391  8b5008               mov edx, dword ptr [eax + 8]
// 005b7394  385a14               cmp byte ptr [edx + 0x14], bl
// 005b7397  751e                 jne 0x5b73b7
// 005b7399  8b08                 mov ecx, dword ptr [eax]
// 005b739b  385914               cmp byte ptr [ecx + 0x14], bl
// 005b739e  7517                 jne 0x5b73b7
// 005b73a0  c6401400             mov byte ptr [eax + 0x14], 0
// 005b73a4  8b5504               mov edx, dword ptr [ebp + 4]
// 005b73a7  8bfe                 mov edi, esi
// 005b73a9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005b73ac  8b7604               mov esi, dword ptr [esi + 4]
// 005b73af  0f854dffffff         jne 0x5b7302
// 005b73b5  eb2e                 jmp 0x5b73e5
// 005b73b7  8b08                 mov ecx, dword ptr [eax]
// 005b73b9  385914               cmp byte ptr [ecx + 0x14], bl
// 005b73bc  7511                 jne 0x5b73cf
// 005b73be  885a14               mov byte ptr [edx + 0x14], bl
// 005b73c1  50                   push eax
// 005b73c2  8bcd                 mov ecx, ebp
// 005b73c4  c6401400             mov byte ptr [eax + 0x14], 0
// 005b73c8  e81361fbff           call 0x56d4e0
// 005b73cd  8b06                 mov eax, dword ptr [esi]
// 005b73cf  8a4e14               mov cl, byte ptr [esi + 0x14]
// 005b73d2  884814               mov byte ptr [eax + 0x14], cl
// 005b73d5  885e14               mov byte ptr [esi + 0x14], bl
// 005b73d8  8b10                 mov edx, dword ptr [eax]
// 005b73da  56                   push esi
// 005b73db  8bcd                 mov ecx, ebp
// 005b73dd  885a14               mov byte ptr [edx + 0x14], bl
// 005b73e0  e83bd70400           call 0x604b20
// 005b73e5  885f14               mov byte ptr [edi + 0x14], bl
// 005b73e8  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b73ec  50                   push eax
// 005b73ed  e870880700           call 0x62fc62
// 005b73f2  8b4508               mov eax, dword ptr [ebp + 8]
// 005b73f5  83c404               add esp, 4
// 005b73f8  85c0                 test eax, eax
// 005b73fa  5f                   pop edi
// 005b73fb  5e                   pop esi
// 005b73fc  5b                   pop ebx
// 005b73fd  7606                 jbe 0x5b7405
// 005b73ff  83c0ff               add eax, -1
// 005b7402  894508               mov dword ptr [ebp + 8], eax
// 005b7405  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005b7409  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005b740d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005b7411  8908                 mov dword ptr [eax], ecx
// 005b7413  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b7417  895004               mov dword ptr [eax + 4], edx
// 005b741a  5d                   pop ebp
// 005b741b  64890d00000000       mov dword ptr fs:[0], ecx
// 005b7422  83c454               add esp, 0x54
// 005b7425  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
