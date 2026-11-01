// from server: 100% by auto
// roc 2009-12 00661ca0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00661ca0
//
// 00661ca0  64a100000000         mov eax, dword ptr fs:[0]
// 00661ca6  6aff                 push -1
// 00661ca8  6812699500           push 0x956912
// 00661cad  50                   push eax
// 00661cae  64892500000000       mov dword ptr fs:[0], esp
// 00661cb5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00661cb9  83ec48               sub esp, 0x48
// 00661cbc  80781500             cmp byte ptr [eax + 0x15], 0
// 00661cc0  55                   push ebp
// 00661cc1  8be9                 mov ebp, ecx
// 00661cc3  7459                 je 0x661d1e
// 00661cc5  68e4f49900           push 0x99f4e4
// 00661cca  8d4c240c             lea ecx, [esp + 0xc]
// 00661cce  ff15f4b69800         call dword ptr [0x98b6f4]
// 00661cd4  8d4c2424             lea ecx, [esp + 0x24]
// 00661cd8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00661ce0  ff1554b79800         call dword ptr [0x98b754]
// 00661ce6  8d442408             lea eax, [esp + 8]
// 00661cea  50                   push eax
// 00661ceb  8d4c2434             lea ecx, [esp + 0x34]
// 00661cef  c644245801           mov byte ptr [esp + 0x58], 1
// 00661cf4  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 00661cfc  ff15f0b69800         call dword ptr [0x98b6f0]
// 00661d02  688cefa800           push 0xa8ef8c
// 00661d07  8d4c2428             lea ecx, [esp + 0x28]
// 00661d0b  51                   push ecx
// 00661d0c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00661d11  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 00661d19  e85a2b1900           call 0x7f4878
// 00661d1e  53                   push ebx
// 00661d1f  56                   push esi
// 00661d20  8bd8                 mov ebx, eax
// 00661d22  57                   push edi
// 00661d23  8d4c246c             lea ecx, [esp + 0x6c]
// 00661d27  895c2410             mov dword ptr [esp + 0x10], ebx
// 00661d2b  e8c0b30400           call 0x6ad0f0
// 00661d30  8b0b                 mov ecx, dword ptr [ebx]
// 00661d32  80791500             cmp byte ptr [ecx + 0x15], 0
// 00661d36  7405                 je 0x661d3d
// 00661d38  8b7b08               mov edi, dword ptr [ebx + 8]
// 00661d3b  eb1b                 jmp 0x661d58
// 00661d3d  8b5308               mov edx, dword ptr [ebx + 8]
// 00661d40  807a1500             cmp byte ptr [edx + 0x15], 0
// 00661d44  7404                 je 0x661d4a
// 00661d46  8bf9                 mov edi, ecx
// 00661d48  eb0e                 jmp 0x661d58
// 00661d4a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00661d4e  8b7808               mov edi, dword ptr [eax + 8]
// 00661d51  8d5008               lea edx, [eax + 8]
// 00661d54  3bc3                 cmp eax, ebx
// 00661d56  756b                 jne 0x661dc3
// 00661d58  807f1500             cmp byte ptr [edi + 0x15], 0
// 00661d5c  8b7304               mov esi, dword ptr [ebx + 4]
// 00661d5f  7503                 jne 0x661d64
// 00661d61  897704               mov dword ptr [edi + 4], esi
// 00661d64  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00661d67  395804               cmp dword ptr [eax + 4], ebx
// 00661d6a  7505                 jne 0x661d71
// 00661d6c  897804               mov dword ptr [eax + 4], edi
// 00661d6f  eb0b                 jmp 0x661d7c
// 00661d71  391e                 cmp dword ptr [esi], ebx
// 00661d73  7504                 jne 0x661d79
// 00661d75  893e                 mov dword ptr [esi], edi
// 00661d77  eb03                 jmp 0x661d7c
// 00661d79  897e08               mov dword ptr [esi + 8], edi
// 00661d7c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00661d7f  8b03                 mov eax, dword ptr [ebx]
// 00661d81  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00661d85  7515                 jne 0x661d9c
// 00661d87  807f1500             cmp byte ptr [edi + 0x15], 0
// 00661d8b  7404                 je 0x661d91
// 00661d8d  8bc6                 mov eax, esi
// 00661d8f  eb09                 jmp 0x661d9a
// 00661d91  57                   push edi
// 00661d92  e86963feff           call 0x648100
// 00661d97  83c404               add esp, 4
// 00661d9a  8903                 mov dword ptr [ebx], eax
// 00661d9c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00661d9f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00661da3  394b08               cmp dword ptr [ebx + 8], ecx
// 00661da6  7577                 jne 0x661e1f
// 00661da8  807f1500             cmp byte ptr [edi + 0x15], 0
// 00661dac  7407                 je 0x661db5
// 00661dae  8bc6                 mov eax, esi
// 00661db0  894308               mov dword ptr [ebx + 8], eax
// 00661db3  eb6a                 jmp 0x661e1f
// 00661db5  57                   push edi
// 00661db6  e8e507edff           call 0x5325a0
// 00661dbb  83c404               add esp, 4
// 00661dbe  894308               mov dword ptr [ebx + 8], eax
// 00661dc1  eb5c                 jmp 0x661e1f
// 00661dc3  894104               mov dword ptr [ecx + 4], eax
// 00661dc6  8b0b                 mov ecx, dword ptr [ebx]
// 00661dc8  8908                 mov dword ptr [eax], ecx
// 00661dca  3b4308               cmp eax, dword ptr [ebx + 8]
// 00661dcd  7504                 jne 0x661dd3
// 00661dcf  8bf0                 mov esi, eax
// 00661dd1  eb19                 jmp 0x661dec
// 00661dd3  807f1500             cmp byte ptr [edi + 0x15], 0
// 00661dd7  8b7004               mov esi, dword ptr [eax + 4]
// 00661dda  7503                 jne 0x661ddf
// 00661ddc  897704               mov dword ptr [edi + 4], esi
// 00661ddf  893e                 mov dword ptr [esi], edi
// 00661de1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00661de4  890a                 mov dword ptr [edx], ecx
// 00661de6  8b5308               mov edx, dword ptr [ebx + 8]
// 00661de9  894204               mov dword ptr [edx + 4], eax
// 00661dec  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00661def  395904               cmp dword ptr [ecx + 4], ebx
// 00661df2  7505                 jne 0x661df9
// 00661df4  894104               mov dword ptr [ecx + 4], eax
// 00661df7  eb0e                 jmp 0x661e07
// 00661df9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00661dfc  3919                 cmp dword ptr [ecx], ebx
// 00661dfe  7504                 jne 0x661e04
// 00661e00  8901                 mov dword ptr [ecx], eax
// 00661e02  eb03                 jmp 0x661e07
// 00661e04  894108               mov dword ptr [ecx + 8], eax
// 00661e07  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00661e0a  894804               mov dword ptr [eax + 4], ecx
// 00661e0d  8d4b14               lea ecx, [ebx + 0x14]
// 00661e10  83c014               add eax, 0x14
// 00661e13  3bc1                 cmp eax, ecx
// 00661e15  7408                 je 0x661e1f
// 00661e17  8a19                 mov bl, byte ptr [ecx]
// 00661e19  8a10                 mov dl, byte ptr [eax]
// 00661e1b  8818                 mov byte ptr [eax], bl
// 00661e1d  8811                 mov byte ptr [ecx], dl
// 00661e1f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00661e23  b301                 mov bl, 1
// 00661e25  385a14               cmp byte ptr [edx + 0x14], bl
// 00661e28  0f85fd000000         jne 0x661f2b
// 00661e2e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00661e31  3b7804               cmp edi, dword ptr [eax + 4]
// 00661e34  0f84ee000000         je 0x661f28
// 00661e3a  8d9b00000000         lea ebx, [ebx]
// 00661e40  385f14               cmp byte ptr [edi + 0x14], bl
// 00661e43  0f85df000000         jne 0x661f28
// 00661e49  8b06                 mov eax, dword ptr [esi]
// 00661e4b  3bf8                 cmp edi, eax
// 00661e4d  7565                 jne 0x661eb4
// 00661e4f  8b4608               mov eax, dword ptr [esi + 8]
// 00661e52  80781400             cmp byte ptr [eax + 0x14], 0
// 00661e56  7512                 jne 0x661e6a
// 00661e58  885814               mov byte ptr [eax + 0x14], bl
// 00661e5b  56                   push esi
// 00661e5c  8bcd                 mov ecx, ebp
// 00661e5e  c6461400             mov byte ptr [esi + 0x14], 0
// 00661e62  e869431800           call 0x7e61d0
// 00661e67  8b4608               mov eax, dword ptr [esi + 8]
// 00661e6a  80781500             cmp byte ptr [eax + 0x15], 0
// 00661e6e  7574                 jne 0x661ee4
// 00661e70  8b08                 mov ecx, dword ptr [eax]
// 00661e72  385914               cmp byte ptr [ecx + 0x14], bl
// 00661e75  7508                 jne 0x661e7f
// 00661e77  8b5008               mov edx, dword ptr [eax + 8]
// 00661e7a  385a14               cmp byte ptr [edx + 0x14], bl
// 00661e7d  7461                 je 0x661ee0
// 00661e7f  8b4808               mov ecx, dword ptr [eax + 8]
// 00661e82  385914               cmp byte ptr [ecx + 0x14], bl
// 00661e85  7514                 jne 0x661e9b
// 00661e87  8b10                 mov edx, dword ptr [eax]
// 00661e89  885a14               mov byte ptr [edx + 0x14], bl
// 00661e8c  50                   push eax
// 00661e8d  8bcd                 mov ecx, ebp
// 00661e8f  c6401400             mov byte ptr [eax + 0x14], 0
// 00661e93  e8d82edfff           call 0x454d70
// 00661e98  8b4608               mov eax, dword ptr [esi + 8]
// 00661e9b  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00661e9e  884814               mov byte ptr [eax + 0x14], cl
// 00661ea1  885e14               mov byte ptr [esi + 0x14], bl
// 00661ea4  8b5008               mov edx, dword ptr [eax + 8]
// 00661ea7  56                   push esi
// 00661ea8  8bcd                 mov ecx, ebp
// 00661eaa  885a14               mov byte ptr [edx + 0x14], bl
// 00661ead  e81e431800           call 0x7e61d0
// 00661eb2  eb74                 jmp 0x661f28
// 00661eb4  80781400             cmp byte ptr [eax + 0x14], 0
// 00661eb8  7511                 jne 0x661ecb
// 00661eba  885814               mov byte ptr [eax + 0x14], bl
// 00661ebd  56                   push esi
// 00661ebe  8bcd                 mov ecx, ebp
// 00661ec0  c6461400             mov byte ptr [esi + 0x14], 0
// 00661ec4  e8a72edfff           call 0x454d70
// 00661ec9  8b06                 mov eax, dword ptr [esi]
// 00661ecb  80781500             cmp byte ptr [eax + 0x15], 0
// 00661ecf  7513                 jne 0x661ee4
// 00661ed1  8b4808               mov ecx, dword ptr [eax + 8]
// 00661ed4  385914               cmp byte ptr [ecx + 0x14], bl
// 00661ed7  751e                 jne 0x661ef7
// 00661ed9  8b10                 mov edx, dword ptr [eax]
// 00661edb  385a14               cmp byte ptr [edx + 0x14], bl
// 00661ede  7517                 jne 0x661ef7
// 00661ee0  c6401400             mov byte ptr [eax + 0x14], 0
// 00661ee4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00661ee7  8bfe                 mov edi, esi
// 00661ee9  8b7604               mov esi, dword ptr [esi + 4]
// 00661eec  3b7804               cmp edi, dword ptr [eax + 4]
// 00661eef  0f854bffffff         jne 0x661e40
// 00661ef5  eb31                 jmp 0x661f28
// 00661ef7  8b08                 mov ecx, dword ptr [eax]
// 00661ef9  385914               cmp byte ptr [ecx + 0x14], bl
// 00661efc  7514                 jne 0x661f12
// 00661efe  8b5008               mov edx, dword ptr [eax + 8]
// 00661f01  885a14               mov byte ptr [edx + 0x14], bl
// 00661f04  50                   push eax
// 00661f05  8bcd                 mov ecx, ebp
// 00661f07  c6401400             mov byte ptr [eax + 0x14], 0
// 00661f0b  e8c0421800           call 0x7e61d0
// 00661f10  8b06                 mov eax, dword ptr [esi]
// 00661f12  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00661f15  884814               mov byte ptr [eax + 0x14], cl
// 00661f18  885e14               mov byte ptr [esi + 0x14], bl
// 00661f1b  8b10                 mov edx, dword ptr [eax]
// 00661f1d  56                   push esi
// 00661f1e  8bcd                 mov ecx, ebp
// 00661f20  885a14               mov byte ptr [edx + 0x14], bl
// 00661f23  e8482edfff           call 0x454d70
// 00661f28  885f14               mov byte ptr [edi + 0x14], bl
// 00661f2b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00661f2f  50                   push eax
// 00661f30  e825191900           call 0x7f385a
// 00661f35  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00661f38  83c404               add esp, 4
// 00661f3b  5f                   pop edi
// 00661f3c  5e                   pop esi
// 00661f3d  5b                   pop ebx
// 00661f3e  85c0                 test eax, eax
// 00661f40  7604                 jbe 0x661f46
// 00661f42  48                   dec eax
// 00661f43  89451c               mov dword ptr [ebp + 0x1c], eax
// 00661f46  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00661f4a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00661f4e  8b5500               mov edx, dword ptr [ebp]
// 00661f51  894804               mov dword ptr [eax + 4], ecx
// 00661f54  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00661f58  8910                 mov dword ptr [eax], edx
// 00661f5a  5d                   pop ebp
// 00661f5b  64890d00000000       mov dword ptr fs:[0], ecx
// 00661f62  83c454               add esp, 0x54
// 00661f65  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
