// from server: 100% by auto
// roc 2007-08 004399f0  unit: RBX::VSoundId::?$XItem  size: 679 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004399f0
//
// 004399f0  6aff                 push -1
// 004399f2  68e9a07400           push 0x74a0e9
// 004399f7  64a100000000         mov eax, dword ptr fs:[0]
// 004399fd  50                   push eax
// 004399fe  83ec48               sub esp, 0x48
// 00439a01  53                   push ebx
// 00439a02  55                   push ebp
// 00439a03  56                   push esi
// 00439a04  57                   push edi
// 00439a05  a188518b00           mov eax, dword ptr [0x8b5188]
// 00439a0a  33c4                 xor eax, esp
// 00439a0c  50                   push eax
// 00439a0d  8d44245c             lea eax, [esp + 0x5c]
// 00439a11  64a300000000         mov dword ptr fs:[0], eax
// 00439a17  8be9                 mov ebp, ecx
// 00439a19  8b442474             mov eax, dword ptr [esp + 0x74]
// 00439a1d  80781100             cmp byte ptr [eax + 0x11], 0
// 00439a21  743c                 je 0x439a5f
// 00439a23  68dc4e7800           push 0x784edc
// 00439a28  8d4c241c             lea ecx, [esp + 0x1c]
// 00439a2c  ff1598e67700         call dword ptr [0x77e698]
// 00439a32  8d442418             lea eax, [esp + 0x18]
// 00439a36  50                   push eax
// 00439a37  8d4c2438             lea ecx, [esp + 0x38]
// 00439a3b  c744246800000000     mov dword ptr [esp + 0x68], 0
// 00439a43  e8788afcff           call 0x4024c0
// 00439a48  6864f38300           push 0x83f364
// 00439a4d  8d4c2438             lea ecx, [esp + 0x38]
// 00439a51  51                   push ecx
// 00439a52  c744243c784e7800     mov dword ptr [esp + 0x3c], 0x784e78
// 00439a5a  e83f711f00           call 0x630b9e
// 00439a5f  8bd8                 mov ebx, eax
// 00439a61  8d4c2470             lea ecx, [esp + 0x70]
// 00439a65  895c2414             mov dword ptr [esp + 0x14], ebx
// 00439a69  e8d2d71e00           call 0x627240
// 00439a6e  8b03                 mov eax, dword ptr [ebx]
// 00439a70  80781100             cmp byte ptr [eax + 0x11], 0
// 00439a74  7405                 je 0x439a7b
// 00439a76  8b7b08               mov edi, dword ptr [ebx + 8]
// 00439a79  eb18                 jmp 0x439a93
// 00439a7b  8b5308               mov edx, dword ptr [ebx + 8]
// 00439a7e  807a1100             cmp byte ptr [edx + 0x11], 0
// 00439a82  7404                 je 0x439a88
// 00439a84  8bf8                 mov edi, eax
// 00439a86  eb0b                 jmp 0x439a93
// 00439a88  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00439a8c  3bcb                 cmp ecx, ebx
// 00439a8e  8b7908               mov edi, dword ptr [ecx + 8]
// 00439a91  756b                 jne 0x439afe
// 00439a93  807f1100             cmp byte ptr [edi + 0x11], 0
// 00439a97  8b7304               mov esi, dword ptr [ebx + 4]
// 00439a9a  7503                 jne 0x439a9f
// 00439a9c  897704               mov dword ptr [edi + 4], esi
// 00439a9f  8b4504               mov eax, dword ptr [ebp + 4]
// 00439aa2  395804               cmp dword ptr [eax + 4], ebx
// 00439aa5  7505                 jne 0x439aac
// 00439aa7  897804               mov dword ptr [eax + 4], edi
// 00439aaa  eb0b                 jmp 0x439ab7
// 00439aac  391e                 cmp dword ptr [esi], ebx
// 00439aae  7504                 jne 0x439ab4
// 00439ab0  893e                 mov dword ptr [esi], edi
// 00439ab2  eb03                 jmp 0x439ab7
// 00439ab4  897e08               mov dword ptr [esi + 8], edi
// 00439ab7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00439aba  8b03                 mov eax, dword ptr [ebx]
// 00439abc  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00439ac0  7515                 jne 0x439ad7
// 00439ac2  807f1100             cmp byte ptr [edi + 0x11], 0
// 00439ac6  7404                 je 0x439acc
// 00439ac8  8bc6                 mov eax, esi
// 00439aca  eb09                 jmp 0x439ad5
// 00439acc  57                   push edi
// 00439acd  e83ef61600           call 0x5a9110
// 00439ad2  83c404               add esp, 4
// 00439ad5  8903                 mov dword ptr [ebx], eax
// 00439ad7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00439ada  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00439ade  394b08               cmp dword ptr [ebx + 8], ecx
// 00439ae1  7572                 jne 0x439b55
// 00439ae3  807f1100             cmp byte ptr [edi + 0x11], 0
// 00439ae7  7407                 je 0x439af0
// 00439ae9  8bc6                 mov eax, esi
// 00439aeb  894308               mov dword ptr [ebx + 8], eax
// 00439aee  eb65                 jmp 0x439b55
// 00439af0  57                   push edi
// 00439af1  e81a461a00           call 0x5de110
// 00439af6  83c404               add esp, 4
// 00439af9  894308               mov dword ptr [ebx + 8], eax
// 00439afc  eb57                 jmp 0x439b55
// 00439afe  894804               mov dword ptr [eax + 4], ecx
// 00439b01  8b13                 mov edx, dword ptr [ebx]
// 00439b03  8911                 mov dword ptr [ecx], edx
// 00439b05  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 00439b08  7504                 jne 0x439b0e
// 00439b0a  8bf1                 mov esi, ecx
// 00439b0c  eb1a                 jmp 0x439b28
// 00439b0e  807f1100             cmp byte ptr [edi + 0x11], 0
// 00439b12  8b7104               mov esi, dword ptr [ecx + 4]
// 00439b15  7503                 jne 0x439b1a
// 00439b17  897704               mov dword ptr [edi + 4], esi
// 00439b1a  893e                 mov dword ptr [esi], edi
// 00439b1c  8b4308               mov eax, dword ptr [ebx + 8]
// 00439b1f  894108               mov dword ptr [ecx + 8], eax
// 00439b22  8b5308               mov edx, dword ptr [ebx + 8]
// 00439b25  894a04               mov dword ptr [edx + 4], ecx
// 00439b28  8b4504               mov eax, dword ptr [ebp + 4]
// 00439b2b  395804               cmp dword ptr [eax + 4], ebx
// 00439b2e  7505                 jne 0x439b35
// 00439b30  894804               mov dword ptr [eax + 4], ecx
// 00439b33  eb0e                 jmp 0x439b43
// 00439b35  8b4304               mov eax, dword ptr [ebx + 4]
// 00439b38  3918                 cmp dword ptr [eax], ebx
// 00439b3a  7504                 jne 0x439b40
// 00439b3c  8908                 mov dword ptr [eax], ecx
// 00439b3e  eb03                 jmp 0x439b43
// 00439b40  894808               mov dword ptr [eax + 8], ecx
// 00439b43  8b4304               mov eax, dword ptr [ebx + 4]
// 00439b46  894104               mov dword ptr [ecx + 4], eax
// 00439b49  8a5310               mov dl, byte ptr [ebx + 0x10]
// 00439b4c  8a4110               mov al, byte ptr [ecx + 0x10]
// 00439b4f  885110               mov byte ptr [ecx + 0x10], dl
// 00439b52  884310               mov byte ptr [ebx + 0x10], al
// 00439b55  8b442414             mov eax, dword ptr [esp + 0x14]
// 00439b59  b301                 mov bl, 1
// 00439b5b  385810               cmp byte ptr [eax + 0x10], bl
// 00439b5e  0f85f2000000         jne 0x439c56
// 00439b64  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00439b67  3b7904               cmp edi, dword ptr [ecx + 4]
// 00439b6a  0f84e3000000         je 0x439c53
// 00439b70  385f10               cmp byte ptr [edi + 0x10], bl
// 00439b73  0f85da000000         jne 0x439c53
// 00439b79  8b06                 mov eax, dword ptr [esi]
// 00439b7b  3bf8                 cmp edi, eax
// 00439b7d  7563                 jne 0x439be2
// 00439b7f  8b4608               mov eax, dword ptr [esi + 8]
// 00439b82  80781000             cmp byte ptr [eax + 0x10], 0
// 00439b86  7512                 jne 0x439b9a
// 00439b88  885810               mov byte ptr [eax + 0x10], bl
// 00439b8b  56                   push esi
// 00439b8c  8bcd                 mov ecx, ebp
// 00439b8e  c6461000             mov byte ptr [esi + 0x10], 0
// 00439b92  e8492a1700           call 0x5ac5e0
// 00439b97  8b4608               mov eax, dword ptr [esi + 8]
// 00439b9a  80781100             cmp byte ptr [eax + 0x11], 0
// 00439b9e  7572                 jne 0x439c12
// 00439ba0  8b10                 mov edx, dword ptr [eax]
// 00439ba2  385a10               cmp byte ptr [edx + 0x10], bl
// 00439ba5  7508                 jne 0x439baf
// 00439ba7  8b4808               mov ecx, dword ptr [eax + 8]
// 00439baa  385910               cmp byte ptr [ecx + 0x10], bl
// 00439bad  745f                 je 0x439c0e
// 00439baf  8b4808               mov ecx, dword ptr [eax + 8]
// 00439bb2  385910               cmp byte ptr [ecx + 0x10], bl
// 00439bb5  7512                 jne 0x439bc9
// 00439bb7  885a10               mov byte ptr [edx + 0x10], bl
// 00439bba  50                   push eax
// 00439bbb  8bcd                 mov ecx, ebp
// 00439bbd  c6401000             mov byte ptr [eax + 0x10], 0
// 00439bc1  e88aa51a00           call 0x5e4150
// 00439bc6  8b4608               mov eax, dword ptr [esi + 8]
// 00439bc9  8a4e10               mov cl, byte ptr [esi + 0x10]
// 00439bcc  884810               mov byte ptr [eax + 0x10], cl
// 00439bcf  885e10               mov byte ptr [esi + 0x10], bl
// 00439bd2  8b5008               mov edx, dword ptr [eax + 8]
// 00439bd5  56                   push esi
// 00439bd6  8bcd                 mov ecx, ebp
// 00439bd8  885a10               mov byte ptr [edx + 0x10], bl
// 00439bdb  e8002a1700           call 0x5ac5e0
// 00439be0  eb71                 jmp 0x439c53
// 00439be2  80781000             cmp byte ptr [eax + 0x10], 0
// 00439be6  7511                 jne 0x439bf9
// 00439be8  885810               mov byte ptr [eax + 0x10], bl
// 00439beb  56                   push esi
// 00439bec  8bcd                 mov ecx, ebp
// 00439bee  c6461000             mov byte ptr [esi + 0x10], 0
// 00439bf2  e859a51a00           call 0x5e4150
// 00439bf7  8b06                 mov eax, dword ptr [esi]
// 00439bf9  80781100             cmp byte ptr [eax + 0x11], 0
// 00439bfd  7513                 jne 0x439c12
// 00439bff  8b5008               mov edx, dword ptr [eax + 8]
// 00439c02  385a10               cmp byte ptr [edx + 0x10], bl
// 00439c05  751e                 jne 0x439c25
// 00439c07  8b08                 mov ecx, dword ptr [eax]
// 00439c09  385910               cmp byte ptr [ecx + 0x10], bl
// 00439c0c  7517                 jne 0x439c25
// 00439c0e  c6401000             mov byte ptr [eax + 0x10], 0
// 00439c12  8b5504               mov edx, dword ptr [ebp + 4]
// 00439c15  8bfe                 mov edi, esi
// 00439c17  3b7a04               cmp edi, dword ptr [edx + 4]
// 00439c1a  8b7604               mov esi, dword ptr [esi + 4]
// 00439c1d  0f854dffffff         jne 0x439b70
// 00439c23  eb2e                 jmp 0x439c53
// 00439c25  8b08                 mov ecx, dword ptr [eax]
// 00439c27  385910               cmp byte ptr [ecx + 0x10], bl
// 00439c2a  7511                 jne 0x439c3d
// 00439c2c  885a10               mov byte ptr [edx + 0x10], bl
// 00439c2f  50                   push eax
// 00439c30  8bcd                 mov ecx, ebp
// 00439c32  c6401000             mov byte ptr [eax + 0x10], 0
// 00439c36  e8a5291700           call 0x5ac5e0
// 00439c3b  8b06                 mov eax, dword ptr [esi]
// 00439c3d  8a4e10               mov cl, byte ptr [esi + 0x10]
// 00439c40  884810               mov byte ptr [eax + 0x10], cl
// 00439c43  885e10               mov byte ptr [esi + 0x10], bl
// 00439c46  8b10                 mov edx, dword ptr [eax]
// 00439c48  56                   push esi
// 00439c49  8bcd                 mov ecx, ebp
// 00439c4b  885a10               mov byte ptr [edx + 0x10], bl
// 00439c4e  e8fda41a00           call 0x5e4150
// 00439c53  885f10               mov byte ptr [edi + 0x10], bl
// 00439c56  8b442414             mov eax, dword ptr [esp + 0x14]
// 00439c5a  50                   push eax
// 00439c5b  e802601f00           call 0x62fc62
// 00439c60  8b4508               mov eax, dword ptr [ebp + 8]
// 00439c63  83c404               add esp, 4
// 00439c66  85c0                 test eax, eax
// 00439c68  7606                 jbe 0x439c70
// 00439c6a  83c0ff               add eax, -1
// 00439c6d  894508               mov dword ptr [ebp + 8], eax
// 00439c70  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00439c74  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 00439c78  8b542474             mov edx, dword ptr [esp + 0x74]
// 00439c7c  8908                 mov dword ptr [eax], ecx
// 00439c7e  895004               mov dword ptr [eax + 4], edx
// 00439c81  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00439c85  64890d00000000       mov dword ptr fs:[0], ecx
// 00439c8c  59                   pop ecx
// 00439c8d  5f                   pop edi
// 00439c8e  5e                   pop esi
// 00439c8f  5d                   pop ebp
// 00439c90  5b                   pop ebx
// 00439c91  83c454               add esp, 0x54
// 00439c94  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
