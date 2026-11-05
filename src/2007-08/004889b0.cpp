// from server: 100% by auto
// roc 2007-08 004889b0  unit: P8CRenderSettings::?$GetSetImpl  size: 679 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004889b0
//
// 004889b0  6aff                 push -1
// 004889b2  68e9a07400           push 0x74a0e9
// 004889b7  64a100000000         mov eax, dword ptr fs:[0]
// 004889bd  50                   push eax
// 004889be  83ec48               sub esp, 0x48
// 004889c1  53                   push ebx
// 004889c2  55                   push ebp
// 004889c3  56                   push esi
// 004889c4  57                   push edi
// 004889c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004889ca  33c4                 xor eax, esp
// 004889cc  50                   push eax
// 004889cd  8d44245c             lea eax, [esp + 0x5c]
// 004889d1  64a300000000         mov dword ptr fs:[0], eax
// 004889d7  8be9                 mov ebp, ecx
// 004889d9  8b442474             mov eax, dword ptr [esp + 0x74]
// 004889dd  80780e00             cmp byte ptr [eax + 0xe], 0
// 004889e1  743c                 je 0x488a1f
// 004889e3  68dc4e7800           push 0x784edc
// 004889e8  8d4c241c             lea ecx, [esp + 0x1c]
// 004889ec  ff1598e67700         call dword ptr [0x77e698]
// 004889f2  8d442418             lea eax, [esp + 0x18]
// 004889f6  50                   push eax
// 004889f7  8d4c2438             lea ecx, [esp + 0x38]
// 004889fb  c744246800000000     mov dword ptr [esp + 0x68], 0
// 00488a03  e8b89af7ff           call 0x4024c0
// 00488a08  6864f38300           push 0x83f364
// 00488a0d  8d4c2438             lea ecx, [esp + 0x38]
// 00488a11  51                   push ecx
// 00488a12  c744243c784e7800     mov dword ptr [esp + 0x3c], 0x784e78
// 00488a1a  e87f811a00           call 0x630b9e
// 00488a1f  8bd8                 mov ebx, eax
// 00488a21  8d4c2470             lea ecx, [esp + 0x70]
// 00488a25  895c2414             mov dword ptr [esp + 0x14], ebx
// 00488a29  e8d2e0ffff           call 0x486b00
// 00488a2e  8b03                 mov eax, dword ptr [ebx]
// 00488a30  80780e00             cmp byte ptr [eax + 0xe], 0
// 00488a34  7405                 je 0x488a3b
// 00488a36  8b7b08               mov edi, dword ptr [ebx + 8]
// 00488a39  eb18                 jmp 0x488a53
// 00488a3b  8b5308               mov edx, dword ptr [ebx + 8]
// 00488a3e  807a0e00             cmp byte ptr [edx + 0xe], 0
// 00488a42  7404                 je 0x488a48
// 00488a44  8bf8                 mov edi, eax
// 00488a46  eb0b                 jmp 0x488a53
// 00488a48  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00488a4c  3bcb                 cmp ecx, ebx
// 00488a4e  8b7908               mov edi, dword ptr [ecx + 8]
// 00488a51  756b                 jne 0x488abe
// 00488a53  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00488a57  8b7304               mov esi, dword ptr [ebx + 4]
// 00488a5a  7503                 jne 0x488a5f
// 00488a5c  897704               mov dword ptr [edi + 4], esi
// 00488a5f  8b4504               mov eax, dword ptr [ebp + 4]
// 00488a62  395804               cmp dword ptr [eax + 4], ebx
// 00488a65  7505                 jne 0x488a6c
// 00488a67  897804               mov dword ptr [eax + 4], edi
// 00488a6a  eb0b                 jmp 0x488a77
// 00488a6c  391e                 cmp dword ptr [esi], ebx
// 00488a6e  7504                 jne 0x488a74
// 00488a70  893e                 mov dword ptr [esi], edi
// 00488a72  eb03                 jmp 0x488a77
// 00488a74  897e08               mov dword ptr [esi + 8], edi
// 00488a77  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00488a7a  8b03                 mov eax, dword ptr [ebx]
// 00488a7c  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00488a80  7515                 jne 0x488a97
// 00488a82  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00488a86  7404                 je 0x488a8c
// 00488a88  8bc6                 mov eax, esi
// 00488a8a  eb09                 jmp 0x488a95
// 00488a8c  57                   push edi
// 00488a8d  e8eedfffff           call 0x486a80
// 00488a92  83c404               add esp, 4
// 00488a95  8903                 mov dword ptr [ebx], eax
// 00488a97  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00488a9a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00488a9e  394b08               cmp dword ptr [ebx + 8], ecx
// 00488aa1  7572                 jne 0x488b15
// 00488aa3  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00488aa7  7407                 je 0x488ab0
// 00488aa9  8bc6                 mov eax, esi
// 00488aab  894308               mov dword ptr [ebx + 8], eax
// 00488aae  eb65                 jmp 0x488b15
// 00488ab0  57                   push edi
// 00488ab1  e8aadfffff           call 0x486a60
// 00488ab6  83c404               add esp, 4
// 00488ab9  894308               mov dword ptr [ebx + 8], eax
// 00488abc  eb57                 jmp 0x488b15
// 00488abe  894804               mov dword ptr [eax + 4], ecx
// 00488ac1  8b13                 mov edx, dword ptr [ebx]
// 00488ac3  8911                 mov dword ptr [ecx], edx
// 00488ac5  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 00488ac8  7504                 jne 0x488ace
// 00488aca  8bf1                 mov esi, ecx
// 00488acc  eb1a                 jmp 0x488ae8
// 00488ace  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00488ad2  8b7104               mov esi, dword ptr [ecx + 4]
// 00488ad5  7503                 jne 0x488ada
// 00488ad7  897704               mov dword ptr [edi + 4], esi
// 00488ada  893e                 mov dword ptr [esi], edi
// 00488adc  8b4308               mov eax, dword ptr [ebx + 8]
// 00488adf  894108               mov dword ptr [ecx + 8], eax
// 00488ae2  8b5308               mov edx, dword ptr [ebx + 8]
// 00488ae5  894a04               mov dword ptr [edx + 4], ecx
// 00488ae8  8b4504               mov eax, dword ptr [ebp + 4]
// 00488aeb  395804               cmp dword ptr [eax + 4], ebx
// 00488aee  7505                 jne 0x488af5
// 00488af0  894804               mov dword ptr [eax + 4], ecx
// 00488af3  eb0e                 jmp 0x488b03
// 00488af5  8b4304               mov eax, dword ptr [ebx + 4]
// 00488af8  3918                 cmp dword ptr [eax], ebx
// 00488afa  7504                 jne 0x488b00
// 00488afc  8908                 mov dword ptr [eax], ecx
// 00488afe  eb03                 jmp 0x488b03
// 00488b00  894808               mov dword ptr [eax + 8], ecx
// 00488b03  8b4304               mov eax, dword ptr [ebx + 4]
// 00488b06  894104               mov dword ptr [ecx + 4], eax
// 00488b09  8a530d               mov dl, byte ptr [ebx + 0xd]
// 00488b0c  8a410d               mov al, byte ptr [ecx + 0xd]
// 00488b0f  88510d               mov byte ptr [ecx + 0xd], dl
// 00488b12  88430d               mov byte ptr [ebx + 0xd], al
// 00488b15  8b442414             mov eax, dword ptr [esp + 0x14]
// 00488b19  b301                 mov bl, 1
// 00488b1b  38580d               cmp byte ptr [eax + 0xd], bl
// 00488b1e  0f85f2000000         jne 0x488c16
// 00488b24  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00488b27  3b7904               cmp edi, dword ptr [ecx + 4]
// 00488b2a  0f84e3000000         je 0x488c13
// 00488b30  385f0d               cmp byte ptr [edi + 0xd], bl
// 00488b33  0f85da000000         jne 0x488c13
// 00488b39  8b06                 mov eax, dword ptr [esi]
// 00488b3b  3bf8                 cmp edi, eax
// 00488b3d  7563                 jne 0x488ba2
// 00488b3f  8b4608               mov eax, dword ptr [esi + 8]
// 00488b42  80780d00             cmp byte ptr [eax + 0xd], 0
// 00488b46  7512                 jne 0x488b5a
// 00488b48  88580d               mov byte ptr [eax + 0xd], bl
// 00488b4b  56                   push esi
// 00488b4c  8bcd                 mov ecx, ebp
// 00488b4e  c6460d00             mov byte ptr [esi + 0xd], 0
// 00488b52  e8b9ebffff           call 0x487710
// 00488b57  8b4608               mov eax, dword ptr [esi + 8]
// 00488b5a  80780e00             cmp byte ptr [eax + 0xe], 0
// 00488b5e  7572                 jne 0x488bd2
// 00488b60  8b10                 mov edx, dword ptr [eax]
// 00488b62  385a0d               cmp byte ptr [edx + 0xd], bl
// 00488b65  7508                 jne 0x488b6f
// 00488b67  8b4808               mov ecx, dword ptr [eax + 8]
// 00488b6a  38590d               cmp byte ptr [ecx + 0xd], bl
// 00488b6d  745f                 je 0x488bce
// 00488b6f  8b4808               mov ecx, dword ptr [eax + 8]
// 00488b72  38590d               cmp byte ptr [ecx + 0xd], bl
// 00488b75  7512                 jne 0x488b89
// 00488b77  885a0d               mov byte ptr [edx + 0xd], bl
// 00488b7a  50                   push eax
// 00488b7b  8bcd                 mov ecx, ebp
// 00488b7d  c6400d00             mov byte ptr [eax + 0xd], 0
// 00488b81  e81adfffff           call 0x486aa0
// 00488b86  8b4608               mov eax, dword ptr [esi + 8]
// 00488b89  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00488b8c  88480d               mov byte ptr [eax + 0xd], cl
// 00488b8f  885e0d               mov byte ptr [esi + 0xd], bl
// 00488b92  8b5008               mov edx, dword ptr [eax + 8]
// 00488b95  56                   push esi
// 00488b96  8bcd                 mov ecx, ebp
// 00488b98  885a0d               mov byte ptr [edx + 0xd], bl
// 00488b9b  e870ebffff           call 0x487710
// 00488ba0  eb71                 jmp 0x488c13
// 00488ba2  80780d00             cmp byte ptr [eax + 0xd], 0
// 00488ba6  7511                 jne 0x488bb9
// 00488ba8  88580d               mov byte ptr [eax + 0xd], bl
// 00488bab  56                   push esi
// 00488bac  8bcd                 mov ecx, ebp
// 00488bae  c6460d00             mov byte ptr [esi + 0xd], 0
// 00488bb2  e8e9deffff           call 0x486aa0
// 00488bb7  8b06                 mov eax, dword ptr [esi]
// 00488bb9  80780e00             cmp byte ptr [eax + 0xe], 0
// 00488bbd  7513                 jne 0x488bd2
// 00488bbf  8b5008               mov edx, dword ptr [eax + 8]
// 00488bc2  385a0d               cmp byte ptr [edx + 0xd], bl
// 00488bc5  751e                 jne 0x488be5
// 00488bc7  8b08                 mov ecx, dword ptr [eax]
// 00488bc9  38590d               cmp byte ptr [ecx + 0xd], bl
// 00488bcc  7517                 jne 0x488be5
// 00488bce  c6400d00             mov byte ptr [eax + 0xd], 0
// 00488bd2  8b5504               mov edx, dword ptr [ebp + 4]
// 00488bd5  8bfe                 mov edi, esi
// 00488bd7  3b7a04               cmp edi, dword ptr [edx + 4]
// 00488bda  8b7604               mov esi, dword ptr [esi + 4]
// 00488bdd  0f854dffffff         jne 0x488b30
// 00488be3  eb2e                 jmp 0x488c13
// 00488be5  8b08                 mov ecx, dword ptr [eax]
// 00488be7  38590d               cmp byte ptr [ecx + 0xd], bl
// 00488bea  7511                 jne 0x488bfd
// 00488bec  885a0d               mov byte ptr [edx + 0xd], bl
// 00488bef  50                   push eax
// 00488bf0  8bcd                 mov ecx, ebp
// 00488bf2  c6400d00             mov byte ptr [eax + 0xd], 0
// 00488bf6  e815ebffff           call 0x487710
// 00488bfb  8b06                 mov eax, dword ptr [esi]
// 00488bfd  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00488c00  88480d               mov byte ptr [eax + 0xd], cl
// 00488c03  885e0d               mov byte ptr [esi + 0xd], bl
// 00488c06  8b10                 mov edx, dword ptr [eax]
// 00488c08  56                   push esi
// 00488c09  8bcd                 mov ecx, ebp
// 00488c0b  885a0d               mov byte ptr [edx + 0xd], bl
// 00488c0e  e88ddeffff           call 0x486aa0
// 00488c13  885f0d               mov byte ptr [edi + 0xd], bl
// 00488c16  8b442414             mov eax, dword ptr [esp + 0x14]
// 00488c1a  50                   push eax
// 00488c1b  e842701a00           call 0x62fc62
// 00488c20  8b4508               mov eax, dword ptr [ebp + 8]
// 00488c23  83c404               add esp, 4
// 00488c26  85c0                 test eax, eax
// 00488c28  7606                 jbe 0x488c30
// 00488c2a  83c0ff               add eax, -1
// 00488c2d  894508               mov dword ptr [ebp + 8], eax
// 00488c30  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00488c34  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 00488c38  8b542474             mov edx, dword ptr [esp + 0x74]
// 00488c3c  8908                 mov dword ptr [eax], ecx
// 00488c3e  895004               mov dword ptr [eax + 4], edx
// 00488c41  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00488c45  64890d00000000       mov dword ptr fs:[0], ecx
// 00488c4c  59                   pop ecx
// 00488c4d  5f                   pop edi
// 00488c4e  5e                   pop esi
// 00488c4f  5d                   pop ebp
// 00488c50  5b                   pop ebx
// 00488c51  83c454               add esp, 0x54
// 00488c54  c20c00               ret 0xc
// standard library set<char> (function ?erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
