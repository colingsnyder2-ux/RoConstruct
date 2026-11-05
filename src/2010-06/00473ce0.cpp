// from server: 100% by auto
// roc 2010-06 00473ce0  unit: CRobloxScriptReviewPaneView  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00473ce0
//
// 00473ce0  64a100000000         mov eax, dword ptr fs:[0]
// 00473ce6  6aff                 push -1
// 00473ce8  68e22f9a00           push 0x9a2fe2
// 00473ced  50                   push eax
// 00473cee  64892500000000       mov dword ptr fs:[0], esp
// 00473cf5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00473cf9  83ec48               sub esp, 0x48
// 00473cfc  80783100             cmp byte ptr [eax + 0x31], 0
// 00473d00  55                   push ebp
// 00473d01  8be9                 mov ebp, ecx
// 00473d03  7459                 je 0x473d5e
// 00473d05  688c00a000           push 0xa0008c
// 00473d0a  8d4c240c             lea ecx, [esp + 0xc]
// 00473d0e  ff1510a49e00         call dword ptr [0x9ea410]
// 00473d14  8d4c2424             lea ecx, [esp + 0x24]
// 00473d18  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00473d20  ff1518a99e00         call dword ptr [0x9ea918]
// 00473d26  8d442408             lea eax, [esp + 8]
// 00473d2a  50                   push eax
// 00473d2b  8d4c2434             lea ecx, [esp + 0x34]
// 00473d2f  c644245801           mov byte ptr [esp + 0x58], 1
// 00473d34  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 00473d3c  ff150ca49e00         call dword ptr [0x9ea40c]
// 00473d42  68081bb000           push 0xb01b08
// 00473d47  8d4c2428             lea ecx, [esp + 0x28]
// 00473d4b  51                   push ecx
// 00473d4c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00473d51  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 00473d59  e8544c3300           call 0x7a89b2
// 00473d5e  53                   push ebx
// 00473d5f  56                   push esi
// 00473d60  8bd8                 mov ebx, eax
// 00473d62  57                   push edi
// 00473d63  8d4c246c             lea ecx, [esp + 0x6c]
// 00473d67  895c2410             mov dword ptr [esp + 0x10], ebx
// 00473d6b  e840b71e00           call 0x65f4b0
// 00473d70  8b0b                 mov ecx, dword ptr [ebx]
// 00473d72  80793100             cmp byte ptr [ecx + 0x31], 0
// 00473d76  7405                 je 0x473d7d
// 00473d78  8b7b08               mov edi, dword ptr [ebx + 8]
// 00473d7b  eb1b                 jmp 0x473d98
// 00473d7d  8b5308               mov edx, dword ptr [ebx + 8]
// 00473d80  807a3100             cmp byte ptr [edx + 0x31], 0
// 00473d84  7404                 je 0x473d8a
// 00473d86  8bf9                 mov edi, ecx
// 00473d88  eb0e                 jmp 0x473d98
// 00473d8a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00473d8e  8b7808               mov edi, dword ptr [eax + 8]
// 00473d91  8d5008               lea edx, [eax + 8]
// 00473d94  3bc3                 cmp eax, ebx
// 00473d96  756b                 jne 0x473e03
// 00473d98  807f3100             cmp byte ptr [edi + 0x31], 0
// 00473d9c  8b7304               mov esi, dword ptr [ebx + 4]
// 00473d9f  7503                 jne 0x473da4
// 00473da1  897704               mov dword ptr [edi + 4], esi
// 00473da4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00473da7  395804               cmp dword ptr [eax + 4], ebx
// 00473daa  7505                 jne 0x473db1
// 00473dac  897804               mov dword ptr [eax + 4], edi
// 00473daf  eb0b                 jmp 0x473dbc
// 00473db1  391e                 cmp dword ptr [esi], ebx
// 00473db3  7504                 jne 0x473db9
// 00473db5  893e                 mov dword ptr [esi], edi
// 00473db7  eb03                 jmp 0x473dbc
// 00473db9  897e08               mov dword ptr [esi + 8], edi
// 00473dbc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00473dbf  8b03                 mov eax, dword ptr [ebx]
// 00473dc1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00473dc5  7515                 jne 0x473ddc
// 00473dc7  807f3100             cmp byte ptr [edi + 0x31], 0
// 00473dcb  7404                 je 0x473dd1
// 00473dcd  8bc6                 mov eax, esi
// 00473dcf  eb09                 jmp 0x473dda
// 00473dd1  57                   push edi
// 00473dd2  e879741e00           call 0x65b250
// 00473dd7  83c404               add esp, 4
// 00473dda  8903                 mov dword ptr [ebx], eax
// 00473ddc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00473ddf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00473de3  394b08               cmp dword ptr [ebx + 8], ecx
// 00473de6  7577                 jne 0x473e5f
// 00473de8  807f3100             cmp byte ptr [edi + 0x31], 0
// 00473dec  7407                 je 0x473df5
// 00473dee  8bc6                 mov eax, esi
// 00473df0  894308               mov dword ptr [ebx + 8], eax
// 00473df3  eb6a                 jmp 0x473e5f
// 00473df5  57                   push edi
// 00473df6  e8156e2000           call 0x67ac10
// 00473dfb  83c404               add esp, 4
// 00473dfe  894308               mov dword ptr [ebx + 8], eax
// 00473e01  eb5c                 jmp 0x473e5f
// 00473e03  894104               mov dword ptr [ecx + 4], eax
// 00473e06  8b0b                 mov ecx, dword ptr [ebx]
// 00473e08  8908                 mov dword ptr [eax], ecx
// 00473e0a  3b4308               cmp eax, dword ptr [ebx + 8]
// 00473e0d  7504                 jne 0x473e13
// 00473e0f  8bf0                 mov esi, eax
// 00473e11  eb19                 jmp 0x473e2c
// 00473e13  807f3100             cmp byte ptr [edi + 0x31], 0
// 00473e17  8b7004               mov esi, dword ptr [eax + 4]
// 00473e1a  7503                 jne 0x473e1f
// 00473e1c  897704               mov dword ptr [edi + 4], esi
// 00473e1f  893e                 mov dword ptr [esi], edi
// 00473e21  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00473e24  890a                 mov dword ptr [edx], ecx
// 00473e26  8b5308               mov edx, dword ptr [ebx + 8]
// 00473e29  894204               mov dword ptr [edx + 4], eax
// 00473e2c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00473e2f  395904               cmp dword ptr [ecx + 4], ebx
// 00473e32  7505                 jne 0x473e39
// 00473e34  894104               mov dword ptr [ecx + 4], eax
// 00473e37  eb0e                 jmp 0x473e47
// 00473e39  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00473e3c  3919                 cmp dword ptr [ecx], ebx
// 00473e3e  7504                 jne 0x473e44
// 00473e40  8901                 mov dword ptr [ecx], eax
// 00473e42  eb03                 jmp 0x473e47
// 00473e44  894108               mov dword ptr [ecx + 8], eax
// 00473e47  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00473e4a  894804               mov dword ptr [eax + 4], ecx
// 00473e4d  8d4b30               lea ecx, [ebx + 0x30]
// 00473e50  83c030               add eax, 0x30
// 00473e53  3bc1                 cmp eax, ecx
// 00473e55  7408                 je 0x473e5f
// 00473e57  8a19                 mov bl, byte ptr [ecx]
// 00473e59  8a10                 mov dl, byte ptr [eax]
// 00473e5b  8818                 mov byte ptr [eax], bl
// 00473e5d  8811                 mov byte ptr [ecx], dl
// 00473e5f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00473e63  b301                 mov bl, 1
// 00473e65  385a30               cmp byte ptr [edx + 0x30], bl
// 00473e68  0f85fd000000         jne 0x473f6b
// 00473e6e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00473e71  3b7804               cmp edi, dword ptr [eax + 4]
// 00473e74  0f84ee000000         je 0x473f68
// 00473e7a  8d9b00000000         lea ebx, [ebx]
// 00473e80  385f30               cmp byte ptr [edi + 0x30], bl
// 00473e83  0f85df000000         jne 0x473f68
// 00473e89  8b06                 mov eax, dword ptr [esi]
// 00473e8b  3bf8                 cmp edi, eax
// 00473e8d  7565                 jne 0x473ef4
// 00473e8f  8b4608               mov eax, dword ptr [esi + 8]
// 00473e92  80783000             cmp byte ptr [eax + 0x30], 0
// 00473e96  7512                 jne 0x473eaa
// 00473e98  885830               mov byte ptr [eax + 0x30], bl
// 00473e9b  56                   push esi
// 00473e9c  8bcd                 mov ecx, ebp
// 00473e9e  c6463000             mov byte ptr [esi + 0x30], 0
// 00473ea2  e879b61e00           call 0x65f520
// 00473ea7  8b4608               mov eax, dword ptr [esi + 8]
// 00473eaa  80783100             cmp byte ptr [eax + 0x31], 0
// 00473eae  7574                 jne 0x473f24
// 00473eb0  8b08                 mov ecx, dword ptr [eax]
// 00473eb2  385930               cmp byte ptr [ecx + 0x30], bl
// 00473eb5  7508                 jne 0x473ebf
// 00473eb7  8b5008               mov edx, dword ptr [eax + 8]
// 00473eba  385a30               cmp byte ptr [edx + 0x30], bl
// 00473ebd  7461                 je 0x473f20
// 00473ebf  8b4808               mov ecx, dword ptr [eax + 8]
// 00473ec2  385930               cmp byte ptr [ecx + 0x30], bl
// 00473ec5  7514                 jne 0x473edb
// 00473ec7  8b10                 mov edx, dword ptr [eax]
// 00473ec9  885a30               mov byte ptr [edx + 0x30], bl
// 00473ecc  50                   push eax
// 00473ecd  8bcd                 mov ecx, ebp
// 00473ecf  c6403000             mov byte ptr [eax + 0x30], 0
// 00473ed3  e878bf0400           call 0x4bfe50
// 00473ed8  8b4608               mov eax, dword ptr [esi + 8]
// 00473edb  8a4e30               mov cl, byte ptr [esi + 0x30]
// 00473ede  884830               mov byte ptr [eax + 0x30], cl
// 00473ee1  885e30               mov byte ptr [esi + 0x30], bl
// 00473ee4  8b5008               mov edx, dword ptr [eax + 8]
// 00473ee7  56                   push esi
// 00473ee8  8bcd                 mov ecx, ebp
// 00473eea  885a30               mov byte ptr [edx + 0x30], bl
// 00473eed  e82eb61e00           call 0x65f520
// 00473ef2  eb74                 jmp 0x473f68
// 00473ef4  80783000             cmp byte ptr [eax + 0x30], 0
// 00473ef8  7511                 jne 0x473f0b
// 00473efa  885830               mov byte ptr [eax + 0x30], bl
// 00473efd  56                   push esi
// 00473efe  8bcd                 mov ecx, ebp
// 00473f00  c6463000             mov byte ptr [esi + 0x30], 0
// 00473f04  e847bf0400           call 0x4bfe50
// 00473f09  8b06                 mov eax, dword ptr [esi]
// 00473f0b  80783100             cmp byte ptr [eax + 0x31], 0
// 00473f0f  7513                 jne 0x473f24
// 00473f11  8b4808               mov ecx, dword ptr [eax + 8]
// 00473f14  385930               cmp byte ptr [ecx + 0x30], bl
// 00473f17  751e                 jne 0x473f37
// 00473f19  8b10                 mov edx, dword ptr [eax]
// 00473f1b  385a30               cmp byte ptr [edx + 0x30], bl
// 00473f1e  7517                 jne 0x473f37
// 00473f20  c6403000             mov byte ptr [eax + 0x30], 0
// 00473f24  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00473f27  8bfe                 mov edi, esi
// 00473f29  8b7604               mov esi, dword ptr [esi + 4]
// 00473f2c  3b7804               cmp edi, dword ptr [eax + 4]
// 00473f2f  0f854bffffff         jne 0x473e80
// 00473f35  eb31                 jmp 0x473f68
// 00473f37  8b08                 mov ecx, dword ptr [eax]
// 00473f39  385930               cmp byte ptr [ecx + 0x30], bl
// 00473f3c  7514                 jne 0x473f52
// 00473f3e  8b5008               mov edx, dword ptr [eax + 8]
// 00473f41  885a30               mov byte ptr [edx + 0x30], bl
// 00473f44  50                   push eax
// 00473f45  8bcd                 mov ecx, ebp
// 00473f47  c6403000             mov byte ptr [eax + 0x30], 0
// 00473f4b  e8d0b51e00           call 0x65f520
// 00473f50  8b06                 mov eax, dword ptr [esi]
// 00473f52  8a4e30               mov cl, byte ptr [esi + 0x30]
// 00473f55  884830               mov byte ptr [eax + 0x30], cl
// 00473f58  885e30               mov byte ptr [esi + 0x30], bl
// 00473f5b  8b10                 mov edx, dword ptr [eax]
// 00473f5d  56                   push esi
// 00473f5e  8bcd                 mov ecx, ebp
// 00473f60  885a30               mov byte ptr [edx + 0x30], bl
// 00473f63  e8e8be0400           call 0x4bfe50
// 00473f68  885f30               mov byte ptr [edi + 0x30], bl
// 00473f6b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00473f6f  83c10c               add ecx, 0xc
// 00473f72  ff1500a49e00         call dword ptr [0x9ea400]
// 00473f78  8b442410             mov eax, dword ptr [esp + 0x10]
// 00473f7c  50                   push eax
// 00473f7d  e8183a3300           call 0x7a799a
// 00473f82  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00473f85  83c404               add esp, 4
// 00473f88  5f                   pop edi
// 00473f89  5e                   pop esi
// 00473f8a  5b                   pop ebx
// 00473f8b  85c0                 test eax, eax
// 00473f8d  7604                 jbe 0x473f93
// 00473f8f  48                   dec eax
// 00473f90  89451c               mov dword ptr [ebp + 0x1c], eax
// 00473f93  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00473f97  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00473f9b  8b5500               mov edx, dword ptr [ebp]
// 00473f9e  894804               mov dword ptr [eax + 4], ecx
// 00473fa1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00473fa5  8910                 mov dword ptr [eax], edx
// 00473fa7  5d                   pop ebp
// 00473fa8  64890d00000000       mov dword ptr fs:[0], ecx
// 00473faf  83c454               add esp, 0x54
// 00473fb2  c20c00               ret 0xc
// standard library map_str<pod8> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
