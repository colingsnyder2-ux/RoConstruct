// from server: 100% by auto
// roc 2009-12 0053aad0  unit: G3D::VRay::?$holder  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053aad0
//
// 0053aad0  64a100000000         mov eax, dword ptr fs:[0]
// 0053aad6  6aff                 push -1
// 0053aad8  6812699500           push 0x956912
// 0053aadd  50                   push eax
// 0053aade  64892500000000       mov dword ptr fs:[0], esp
// 0053aae5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0053aae9  83ec48               sub esp, 0x48
// 0053aaec  80781900             cmp byte ptr [eax + 0x19], 0
// 0053aaf0  55                   push ebp
// 0053aaf1  8be9                 mov ebp, ecx
// 0053aaf3  7459                 je 0x53ab4e
// 0053aaf5  68e4f49900           push 0x99f4e4
// 0053aafa  8d4c240c             lea ecx, [esp + 0xc]
// 0053aafe  ff15f4b69800         call dword ptr [0x98b6f4]
// 0053ab04  8d4c2424             lea ecx, [esp + 0x24]
// 0053ab08  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0053ab10  ff1554b79800         call dword ptr [0x98b754]
// 0053ab16  8d442408             lea eax, [esp + 8]
// 0053ab1a  50                   push eax
// 0053ab1b  8d4c2434             lea ecx, [esp + 0x34]
// 0053ab1f  c644245801           mov byte ptr [esp + 0x58], 1
// 0053ab24  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 0053ab2c  ff15f0b69800         call dword ptr [0x98b6f0]
// 0053ab32  688cefa800           push 0xa8ef8c
// 0053ab37  8d4c2428             lea ecx, [esp + 0x28]
// 0053ab3b  51                   push ecx
// 0053ab3c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0053ab41  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 0053ab49  e82a9d2b00           call 0x7f4878
// 0053ab4e  53                   push ebx
// 0053ab4f  56                   push esi
// 0053ab50  8bd8                 mov ebx, eax
// 0053ab52  57                   push edi
// 0053ab53  8d4c246c             lea ecx, [esp + 0x6c]
// 0053ab57  895c2410             mov dword ptr [esp + 0x10], ebx
// 0053ab5b  e820daffff           call 0x538580
// 0053ab60  8b0b                 mov ecx, dword ptr [ebx]
// 0053ab62  80791900             cmp byte ptr [ecx + 0x19], 0
// 0053ab66  7405                 je 0x53ab6d
// 0053ab68  8b7b08               mov edi, dword ptr [ebx + 8]
// 0053ab6b  eb1b                 jmp 0x53ab88
// 0053ab6d  8b5308               mov edx, dword ptr [ebx + 8]
// 0053ab70  807a1900             cmp byte ptr [edx + 0x19], 0
// 0053ab74  7404                 je 0x53ab7a
// 0053ab76  8bf9                 mov edi, ecx
// 0053ab78  eb0e                 jmp 0x53ab88
// 0053ab7a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0053ab7e  8b7808               mov edi, dword ptr [eax + 8]
// 0053ab81  8d5008               lea edx, [eax + 8]
// 0053ab84  3bc3                 cmp eax, ebx
// 0053ab86  756b                 jne 0x53abf3
// 0053ab88  807f1900             cmp byte ptr [edi + 0x19], 0
// 0053ab8c  8b7304               mov esi, dword ptr [ebx + 4]
// 0053ab8f  7503                 jne 0x53ab94
// 0053ab91  897704               mov dword ptr [edi + 4], esi
// 0053ab94  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0053ab97  395804               cmp dword ptr [eax + 4], ebx
// 0053ab9a  7505                 jne 0x53aba1
// 0053ab9c  897804               mov dword ptr [eax + 4], edi
// 0053ab9f  eb0b                 jmp 0x53abac
// 0053aba1  391e                 cmp dword ptr [esi], ebx
// 0053aba3  7504                 jne 0x53aba9
// 0053aba5  893e                 mov dword ptr [esi], edi
// 0053aba7  eb03                 jmp 0x53abac
// 0053aba9  897e08               mov dword ptr [esi + 8], edi
// 0053abac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0053abaf  8b03                 mov eax, dword ptr [ebx]
// 0053abb1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0053abb5  7515                 jne 0x53abcc
// 0053abb7  807f1900             cmp byte ptr [edi + 0x19], 0
// 0053abbb  7404                 je 0x53abc1
// 0053abbd  8bc6                 mov eax, esi
// 0053abbf  eb09                 jmp 0x53abca
// 0053abc1  57                   push edi
// 0053abc2  e849cbffff           call 0x537710
// 0053abc7  83c404               add esp, 4
// 0053abca  8903                 mov dword ptr [ebx], eax
// 0053abcc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0053abcf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053abd3  394b08               cmp dword ptr [ebx + 8], ecx
// 0053abd6  7577                 jne 0x53ac4f
// 0053abd8  807f1900             cmp byte ptr [edi + 0x19], 0
// 0053abdc  7407                 je 0x53abe5
// 0053abde  8bc6                 mov eax, esi
// 0053abe0  894308               mov dword ptr [ebx + 8], eax
// 0053abe3  eb6a                 jmp 0x53ac4f
// 0053abe5  57                   push edi
// 0053abe6  e805cbffff           call 0x5376f0
// 0053abeb  83c404               add esp, 4
// 0053abee  894308               mov dword ptr [ebx + 8], eax
// 0053abf1  eb5c                 jmp 0x53ac4f
// 0053abf3  894104               mov dword ptr [ecx + 4], eax
// 0053abf6  8b0b                 mov ecx, dword ptr [ebx]
// 0053abf8  8908                 mov dword ptr [eax], ecx
// 0053abfa  3b4308               cmp eax, dword ptr [ebx + 8]
// 0053abfd  7504                 jne 0x53ac03
// 0053abff  8bf0                 mov esi, eax
// 0053ac01  eb19                 jmp 0x53ac1c
// 0053ac03  807f1900             cmp byte ptr [edi + 0x19], 0
// 0053ac07  8b7004               mov esi, dword ptr [eax + 4]
// 0053ac0a  7503                 jne 0x53ac0f
// 0053ac0c  897704               mov dword ptr [edi + 4], esi
// 0053ac0f  893e                 mov dword ptr [esi], edi
// 0053ac11  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0053ac14  890a                 mov dword ptr [edx], ecx
// 0053ac16  8b5308               mov edx, dword ptr [ebx + 8]
// 0053ac19  894204               mov dword ptr [edx + 4], eax
// 0053ac1c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0053ac1f  395904               cmp dword ptr [ecx + 4], ebx
// 0053ac22  7505                 jne 0x53ac29
// 0053ac24  894104               mov dword ptr [ecx + 4], eax
// 0053ac27  eb0e                 jmp 0x53ac37
// 0053ac29  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0053ac2c  3919                 cmp dword ptr [ecx], ebx
// 0053ac2e  7504                 jne 0x53ac34
// 0053ac30  8901                 mov dword ptr [ecx], eax
// 0053ac32  eb03                 jmp 0x53ac37
// 0053ac34  894108               mov dword ptr [ecx + 8], eax
// 0053ac37  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0053ac3a  894804               mov dword ptr [eax + 4], ecx
// 0053ac3d  8d4b18               lea ecx, [ebx + 0x18]
// 0053ac40  83c018               add eax, 0x18
// 0053ac43  3bc1                 cmp eax, ecx
// 0053ac45  7408                 je 0x53ac4f
// 0053ac47  8a19                 mov bl, byte ptr [ecx]
// 0053ac49  8a10                 mov dl, byte ptr [eax]
// 0053ac4b  8818                 mov byte ptr [eax], bl
// 0053ac4d  8811                 mov byte ptr [ecx], dl
// 0053ac4f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053ac53  b301                 mov bl, 1
// 0053ac55  385a18               cmp byte ptr [edx + 0x18], bl
// 0053ac58  0f85fd000000         jne 0x53ad5b
// 0053ac5e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0053ac61  3b7804               cmp edi, dword ptr [eax + 4]
// 0053ac64  0f84ee000000         je 0x53ad58
// 0053ac6a  8d9b00000000         lea ebx, [ebx]
// 0053ac70  385f18               cmp byte ptr [edi + 0x18], bl
// 0053ac73  0f85df000000         jne 0x53ad58
// 0053ac79  8b06                 mov eax, dword ptr [esi]
// 0053ac7b  3bf8                 cmp edi, eax
// 0053ac7d  7565                 jne 0x53ace4
// 0053ac7f  8b4608               mov eax, dword ptr [esi + 8]
// 0053ac82  80781800             cmp byte ptr [eax + 0x18], 0
// 0053ac86  7512                 jne 0x53ac9a
// 0053ac88  885818               mov byte ptr [eax + 0x18], bl
// 0053ac8b  56                   push esi
// 0053ac8c  8bcd                 mov ecx, ebp
// 0053ac8e  c6461800             mov byte ptr [esi + 0x18], 0
// 0053ac92  e879b71200           call 0x666410
// 0053ac97  8b4608               mov eax, dword ptr [esi + 8]
// 0053ac9a  80781900             cmp byte ptr [eax + 0x19], 0
// 0053ac9e  7574                 jne 0x53ad14
// 0053aca0  8b08                 mov ecx, dword ptr [eax]
// 0053aca2  385918               cmp byte ptr [ecx + 0x18], bl
// 0053aca5  7508                 jne 0x53acaf
// 0053aca7  8b5008               mov edx, dword ptr [eax + 8]
// 0053acaa  385a18               cmp byte ptr [edx + 0x18], bl
// 0053acad  7461                 je 0x53ad10
// 0053acaf  8b4808               mov ecx, dword ptr [eax + 8]
// 0053acb2  385918               cmp byte ptr [ecx + 0x18], bl
// 0053acb5  7514                 jne 0x53accb
// 0053acb7  8b10                 mov edx, dword ptr [eax]
// 0053acb9  885a18               mov byte ptr [edx + 0x18], bl
// 0053acbc  50                   push eax
// 0053acbd  8bcd                 mov ecx, ebp
// 0053acbf  c6401800             mov byte ptr [eax + 0x18], 0
// 0053acc3  e87881efff           call 0x432e40
// 0053acc8  8b4608               mov eax, dword ptr [esi + 8]
// 0053accb  8a4e18               mov cl, byte ptr [esi + 0x18]
// 0053acce  884818               mov byte ptr [eax + 0x18], cl
// 0053acd1  885e18               mov byte ptr [esi + 0x18], bl
// 0053acd4  8b5008               mov edx, dword ptr [eax + 8]
// 0053acd7  56                   push esi
// 0053acd8  8bcd                 mov ecx, ebp
// 0053acda  885a18               mov byte ptr [edx + 0x18], bl
// 0053acdd  e82eb71200           call 0x666410
// 0053ace2  eb74                 jmp 0x53ad58
// 0053ace4  80781800             cmp byte ptr [eax + 0x18], 0
// 0053ace8  7511                 jne 0x53acfb
// 0053acea  885818               mov byte ptr [eax + 0x18], bl
// 0053aced  56                   push esi
// 0053acee  8bcd                 mov ecx, ebp
// 0053acf0  c6461800             mov byte ptr [esi + 0x18], 0
// 0053acf4  e84781efff           call 0x432e40
// 0053acf9  8b06                 mov eax, dword ptr [esi]
// 0053acfb  80781900             cmp byte ptr [eax + 0x19], 0
// 0053acff  7513                 jne 0x53ad14
// 0053ad01  8b4808               mov ecx, dword ptr [eax + 8]
// 0053ad04  385918               cmp byte ptr [ecx + 0x18], bl
// 0053ad07  751e                 jne 0x53ad27
// 0053ad09  8b10                 mov edx, dword ptr [eax]
// 0053ad0b  385a18               cmp byte ptr [edx + 0x18], bl
// 0053ad0e  7517                 jne 0x53ad27
// 0053ad10  c6401800             mov byte ptr [eax + 0x18], 0
// 0053ad14  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0053ad17  8bfe                 mov edi, esi
// 0053ad19  8b7604               mov esi, dword ptr [esi + 4]
// 0053ad1c  3b7804               cmp edi, dword ptr [eax + 4]
// 0053ad1f  0f854bffffff         jne 0x53ac70
// 0053ad25  eb31                 jmp 0x53ad58
// 0053ad27  8b08                 mov ecx, dword ptr [eax]
// 0053ad29  385918               cmp byte ptr [ecx + 0x18], bl
// 0053ad2c  7514                 jne 0x53ad42
// 0053ad2e  8b5008               mov edx, dword ptr [eax + 8]
// 0053ad31  885a18               mov byte ptr [edx + 0x18], bl
// 0053ad34  50                   push eax
// 0053ad35  8bcd                 mov ecx, ebp
// 0053ad37  c6401800             mov byte ptr [eax + 0x18], 0
// 0053ad3b  e8d0b61200           call 0x666410
// 0053ad40  8b06                 mov eax, dword ptr [esi]
// 0053ad42  8a4e18               mov cl, byte ptr [esi + 0x18]
// 0053ad45  884818               mov byte ptr [eax + 0x18], cl
// 0053ad48  885e18               mov byte ptr [esi + 0x18], bl
// 0053ad4b  8b10                 mov edx, dword ptr [eax]
// 0053ad4d  56                   push esi
// 0053ad4e  8bcd                 mov ecx, ebp
// 0053ad50  885a18               mov byte ptr [edx + 0x18], bl
// 0053ad53  e8e880efff           call 0x432e40
// 0053ad58  885f18               mov byte ptr [edi + 0x18], bl
// 0053ad5b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0053ad5f  50                   push eax
// 0053ad60  e8f58a2b00           call 0x7f385a
// 0053ad65  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0053ad68  83c404               add esp, 4
// 0053ad6b  5f                   pop edi
// 0053ad6c  5e                   pop esi
// 0053ad6d  5b                   pop ebx
// 0053ad6e  85c0                 test eax, eax
// 0053ad70  7604                 jbe 0x53ad76
// 0053ad72  48                   dec eax
// 0053ad73  89451c               mov dword ptr [ebp + 0x1c], eax
// 0053ad76  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0053ad7a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0053ad7e  8b5500               mov edx, dword ptr [ebp]
// 0053ad81  894804               mov dword ptr [eax + 4], ecx
// 0053ad84  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0053ad88  8910                 mov dword ptr [eax], edx
// 0053ad8a  5d                   pop ebp
// 0053ad8b  64890d00000000       mov dword ptr fs:[0], ecx
// 0053ad92  83c454               add esp, 0x54
// 0053ad95  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
