// from server: 100% by auto
// roc 2008-06 00497b00  unit: RBX::Network::Players  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00497b00
//
// 00497b00  64a100000000         mov eax, dword ptr fs:[0]
// 00497b06  6aff                 push -1
// 00497b08  6842e87d00           push 0x7de842
// 00497b0d  50                   push eax
// 00497b0e  64892500000000       mov dword ptr fs:[0], esp
// 00497b15  8b442418             mov eax, dword ptr [esp + 0x18]
// 00497b19  83ec48               sub esp, 0x48
// 00497b1c  80781900             cmp byte ptr [eax + 0x19], 0
// 00497b20  55                   push ebp
// 00497b21  8be9                 mov ebp, ecx
// 00497b23  7459                 je 0x497b7e
// 00497b25  6870b28000           push 0x80b270
// 00497b2a  8d4c240c             lea ecx, [esp + 0xc]
// 00497b2e  ff1558248000         call dword ptr [0x802458]
// 00497b34  8d4c2424             lea ecx, [esp + 0x24]
// 00497b38  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00497b40  ff1598288000         call dword ptr [0x802898]
// 00497b46  8d442408             lea eax, [esp + 8]
// 00497b4a  50                   push eax
// 00497b4b  8d4c2434             lea ecx, [esp + 0x34]
// 00497b4f  c644245801           mov byte ptr [esp + 0x58], 1
// 00497b54  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 00497b5c  ff155c248000         call dword ptr [0x80245c]
// 00497b62  683c0c8d00           push 0x8d0c3c
// 00497b67  8d4c2428             lea ecx, [esp + 0x28]
// 00497b6b  51                   push ecx
// 00497b6c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00497b71  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00497b79  e80e9a2000           call 0x6a158c
// 00497b7e  53                   push ebx
// 00497b7f  56                   push esi
// 00497b80  8bd8                 mov ebx, eax
// 00497b82  57                   push edi
// 00497b83  8d4c246c             lea ecx, [esp + 0x6c]
// 00497b87  895c2410             mov dword ptr [esp + 0x10], ebx
// 00497b8b  e8c0f61100           call 0x5b7250
// 00497b90  8b0b                 mov ecx, dword ptr [ebx]
// 00497b92  80791900             cmp byte ptr [ecx + 0x19], 0
// 00497b96  7405                 je 0x497b9d
// 00497b98  8b7b08               mov edi, dword ptr [ebx + 8]
// 00497b9b  eb1b                 jmp 0x497bb8
// 00497b9d  8b5308               mov edx, dword ptr [ebx + 8]
// 00497ba0  807a1900             cmp byte ptr [edx + 0x19], 0
// 00497ba4  7404                 je 0x497baa
// 00497ba6  8bf9                 mov edi, ecx
// 00497ba8  eb0e                 jmp 0x497bb8
// 00497baa  8b442470             mov eax, dword ptr [esp + 0x70]
// 00497bae  8b7808               mov edi, dword ptr [eax + 8]
// 00497bb1  8d5008               lea edx, [eax + 8]
// 00497bb4  3bc3                 cmp eax, ebx
// 00497bb6  756b                 jne 0x497c23
// 00497bb8  807f1900             cmp byte ptr [edi + 0x19], 0
// 00497bbc  8b7304               mov esi, dword ptr [ebx + 4]
// 00497bbf  7503                 jne 0x497bc4
// 00497bc1  897704               mov dword ptr [edi + 4], esi
// 00497bc4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00497bc7  395804               cmp dword ptr [eax + 4], ebx
// 00497bca  7505                 jne 0x497bd1
// 00497bcc  897804               mov dword ptr [eax + 4], edi
// 00497bcf  eb0b                 jmp 0x497bdc
// 00497bd1  391e                 cmp dword ptr [esi], ebx
// 00497bd3  7504                 jne 0x497bd9
// 00497bd5  893e                 mov dword ptr [esi], edi
// 00497bd7  eb03                 jmp 0x497bdc
// 00497bd9  897e08               mov dword ptr [esi + 8], edi
// 00497bdc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00497bdf  8b03                 mov eax, dword ptr [ebx]
// 00497be1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00497be5  7515                 jne 0x497bfc
// 00497be7  807f1900             cmp byte ptr [edi + 0x19], 0
// 00497beb  7404                 je 0x497bf1
// 00497bed  8bc6                 mov eax, esi
// 00497bef  eb09                 jmp 0x497bfa
// 00497bf1  57                   push edi
// 00497bf2  e829f01100           call 0x5b6c20
// 00497bf7  83c404               add esp, 4
// 00497bfa  8903                 mov dword ptr [ebx], eax
// 00497bfc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00497bff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00497c03  394b08               cmp dword ptr [ebx + 8], ecx
// 00497c06  7577                 jne 0x497c7f
// 00497c08  807f1900             cmp byte ptr [edi + 0x19], 0
// 00497c0c  7407                 je 0x497c15
// 00497c0e  8bc6                 mov eax, esi
// 00497c10  894308               mov dword ptr [ebx + 8], eax
// 00497c13  eb6a                 jmp 0x497c7f
// 00497c15  57                   push edi
// 00497c16  e855340100           call 0x4ab070
// 00497c1b  83c404               add esp, 4
// 00497c1e  894308               mov dword ptr [ebx + 8], eax
// 00497c21  eb5c                 jmp 0x497c7f
// 00497c23  894104               mov dword ptr [ecx + 4], eax
// 00497c26  8b0b                 mov ecx, dword ptr [ebx]
// 00497c28  8908                 mov dword ptr [eax], ecx
// 00497c2a  3b4308               cmp eax, dword ptr [ebx + 8]
// 00497c2d  7504                 jne 0x497c33
// 00497c2f  8bf0                 mov esi, eax
// 00497c31  eb19                 jmp 0x497c4c
// 00497c33  807f1900             cmp byte ptr [edi + 0x19], 0
// 00497c37  8b7004               mov esi, dword ptr [eax + 4]
// 00497c3a  7503                 jne 0x497c3f
// 00497c3c  897704               mov dword ptr [edi + 4], esi
// 00497c3f  893e                 mov dword ptr [esi], edi
// 00497c41  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00497c44  890a                 mov dword ptr [edx], ecx
// 00497c46  8b5308               mov edx, dword ptr [ebx + 8]
// 00497c49  894204               mov dword ptr [edx + 4], eax
// 00497c4c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00497c4f  395904               cmp dword ptr [ecx + 4], ebx
// 00497c52  7505                 jne 0x497c59
// 00497c54  894104               mov dword ptr [ecx + 4], eax
// 00497c57  eb0e                 jmp 0x497c67
// 00497c59  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00497c5c  3919                 cmp dword ptr [ecx], ebx
// 00497c5e  7504                 jne 0x497c64
// 00497c60  8901                 mov dword ptr [ecx], eax
// 00497c62  eb03                 jmp 0x497c67
// 00497c64  894108               mov dword ptr [ecx + 8], eax
// 00497c67  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00497c6a  894804               mov dword ptr [eax + 4], ecx
// 00497c6d  8d4b18               lea ecx, [ebx + 0x18]
// 00497c70  83c018               add eax, 0x18
// 00497c73  3bc1                 cmp eax, ecx
// 00497c75  7408                 je 0x497c7f
// 00497c77  8a19                 mov bl, byte ptr [ecx]
// 00497c79  8a10                 mov dl, byte ptr [eax]
// 00497c7b  8818                 mov byte ptr [eax], bl
// 00497c7d  8811                 mov byte ptr [ecx], dl
// 00497c7f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00497c83  b301                 mov bl, 1
// 00497c85  385a18               cmp byte ptr [edx + 0x18], bl
// 00497c88  0f85fd000000         jne 0x497d8b
// 00497c8e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00497c91  3b7804               cmp edi, dword ptr [eax + 4]
// 00497c94  0f84ee000000         je 0x497d88
// 00497c9a  8d9b00000000         lea ebx, [ebx]
// 00497ca0  385f18               cmp byte ptr [edi + 0x18], bl
// 00497ca3  0f85df000000         jne 0x497d88
// 00497ca9  8b06                 mov eax, dword ptr [esi]
// 00497cab  3bf8                 cmp edi, eax
// 00497cad  7565                 jne 0x497d14
// 00497caf  8b4608               mov eax, dword ptr [esi + 8]
// 00497cb2  80781800             cmp byte ptr [eax + 0x18], 0
// 00497cb6  7512                 jne 0x497cca
// 00497cb8  885818               mov byte ptr [eax + 0x18], bl
// 00497cbb  56                   push esi
// 00497cbc  8bcd                 mov ecx, ebp
// 00497cbe  c6461800             mov byte ptr [esi + 0x18], 0
// 00497cc2  e829410100           call 0x4abdf0
// 00497cc7  8b4608               mov eax, dword ptr [esi + 8]
// 00497cca  80781900             cmp byte ptr [eax + 0x19], 0
// 00497cce  7574                 jne 0x497d44
// 00497cd0  8b08                 mov ecx, dword ptr [eax]
// 00497cd2  385918               cmp byte ptr [ecx + 0x18], bl
// 00497cd5  7508                 jne 0x497cdf
// 00497cd7  8b5008               mov edx, dword ptr [eax + 8]
// 00497cda  385a18               cmp byte ptr [edx + 0x18], bl
// 00497cdd  7461                 je 0x497d40
// 00497cdf  8b4808               mov ecx, dword ptr [eax + 8]
// 00497ce2  385918               cmp byte ptr [ecx + 0x18], bl
// 00497ce5  7514                 jne 0x497cfb
// 00497ce7  8b10                 mov edx, dword ptr [eax]
// 00497ce9  885a18               mov byte ptr [edx + 0x18], bl
// 00497cec  50                   push eax
// 00497ced  8bcd                 mov ecx, ebp
// 00497cef  c6401800             mov byte ptr [eax + 0x18], 0
// 00497cf3  e868f60e00           call 0x587360
// 00497cf8  8b4608               mov eax, dword ptr [esi + 8]
// 00497cfb  8a4e18               mov cl, byte ptr [esi + 0x18]
// 00497cfe  884818               mov byte ptr [eax + 0x18], cl
// 00497d01  885e18               mov byte ptr [esi + 0x18], bl
// 00497d04  8b5008               mov edx, dword ptr [eax + 8]
// 00497d07  56                   push esi
// 00497d08  8bcd                 mov ecx, ebp
// 00497d0a  885a18               mov byte ptr [edx + 0x18], bl
// 00497d0d  e8de400100           call 0x4abdf0
// 00497d12  eb74                 jmp 0x497d88
// 00497d14  80781800             cmp byte ptr [eax + 0x18], 0
// 00497d18  7511                 jne 0x497d2b
// 00497d1a  885818               mov byte ptr [eax + 0x18], bl
// 00497d1d  56                   push esi
// 00497d1e  8bcd                 mov ecx, ebp
// 00497d20  c6461800             mov byte ptr [esi + 0x18], 0
// 00497d24  e837f60e00           call 0x587360
// 00497d29  8b06                 mov eax, dword ptr [esi]
// 00497d2b  80781900             cmp byte ptr [eax + 0x19], 0
// 00497d2f  7513                 jne 0x497d44
// 00497d31  8b4808               mov ecx, dword ptr [eax + 8]
// 00497d34  385918               cmp byte ptr [ecx + 0x18], bl
// 00497d37  751e                 jne 0x497d57
// 00497d39  8b10                 mov edx, dword ptr [eax]
// 00497d3b  385a18               cmp byte ptr [edx + 0x18], bl
// 00497d3e  7517                 jne 0x497d57
// 00497d40  c6401800             mov byte ptr [eax + 0x18], 0
// 00497d44  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00497d47  8bfe                 mov edi, esi
// 00497d49  8b7604               mov esi, dword ptr [esi + 4]
// 00497d4c  3b7804               cmp edi, dword ptr [eax + 4]
// 00497d4f  0f854bffffff         jne 0x497ca0
// 00497d55  eb31                 jmp 0x497d88
// 00497d57  8b08                 mov ecx, dword ptr [eax]
// 00497d59  385918               cmp byte ptr [ecx + 0x18], bl
// 00497d5c  7514                 jne 0x497d72
// 00497d5e  8b5008               mov edx, dword ptr [eax + 8]
// 00497d61  885a18               mov byte ptr [edx + 0x18], bl
// 00497d64  50                   push eax
// 00497d65  8bcd                 mov ecx, ebp
// 00497d67  c6401800             mov byte ptr [eax + 0x18], 0
// 00497d6b  e880400100           call 0x4abdf0
// 00497d70  8b06                 mov eax, dword ptr [esi]
// 00497d72  8a4e18               mov cl, byte ptr [esi + 0x18]
// 00497d75  884818               mov byte ptr [eax + 0x18], cl
// 00497d78  885e18               mov byte ptr [esi + 0x18], bl
// 00497d7b  8b10                 mov edx, dword ptr [eax]
// 00497d7d  56                   push esi
// 00497d7e  8bcd                 mov ecx, ebp
// 00497d80  885a18               mov byte ptr [edx + 0x18], bl
// 00497d83  e8d8f50e00           call 0x587360
// 00497d88  885f18               mov byte ptr [edi + 0x18], bl
// 00497d8b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00497d8f  50                   push eax
// 00497d90  e8e5882000           call 0x6a067a
// 00497d95  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00497d98  83c404               add esp, 4
// 00497d9b  5f                   pop edi
// 00497d9c  5e                   pop esi
// 00497d9d  5b                   pop ebx
// 00497d9e  85c0                 test eax, eax
// 00497da0  7604                 jbe 0x497da6
// 00497da2  48                   dec eax
// 00497da3  89451c               mov dword ptr [ebp + 0x1c], eax
// 00497da6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00497daa  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00497dae  8b5500               mov edx, dword ptr [ebp]
// 00497db1  894804               mov dword ptr [eax + 4], ecx
// 00497db4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00497db8  8910                 mov dword ptr [eax], edx
// 00497dba  5d                   pop ebp
// 00497dbb  64890d00000000       mov dword ptr fs:[0], ecx
// 00497dc2  83c454               add esp, 0x54
// 00497dc5  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
