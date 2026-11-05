// from server: 100% by auto
// roc 2008-06 005539d0  unit: RBX::RenderBase::AggregateChunk  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005539d0
//
// 005539d0  64a100000000         mov eax, dword ptr fs:[0]
// 005539d6  6aff                 push -1
// 005539d8  6842e87d00           push 0x7de842
// 005539dd  50                   push eax
// 005539de  64892500000000       mov dword ptr fs:[0], esp
// 005539e5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005539e9  83ec48               sub esp, 0x48
// 005539ec  80781500             cmp byte ptr [eax + 0x15], 0
// 005539f0  55                   push ebp
// 005539f1  8be9                 mov ebp, ecx
// 005539f3  7459                 je 0x553a4e
// 005539f5  6870b28000           push 0x80b270
// 005539fa  8d4c240c             lea ecx, [esp + 0xc]
// 005539fe  ff1558248000         call dword ptr [0x802458]
// 00553a04  8d4c2424             lea ecx, [esp + 0x24]
// 00553a08  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00553a10  ff1598288000         call dword ptr [0x802898]
// 00553a16  8d442408             lea eax, [esp + 8]
// 00553a1a  50                   push eax
// 00553a1b  8d4c2434             lea ecx, [esp + 0x34]
// 00553a1f  c644245801           mov byte ptr [esp + 0x58], 1
// 00553a24  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 00553a2c  ff155c248000         call dword ptr [0x80245c]
// 00553a32  683c0c8d00           push 0x8d0c3c
// 00553a37  8d4c2428             lea ecx, [esp + 0x28]
// 00553a3b  51                   push ecx
// 00553a3c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00553a41  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00553a49  e83edb1400           call 0x6a158c
// 00553a4e  53                   push ebx
// 00553a4f  56                   push esi
// 00553a50  8bd8                 mov ebx, eax
// 00553a52  57                   push edi
// 00553a53  8d4c246c             lea ecx, [esp + 0x6c]
// 00553a57  895c2410             mov dword ptr [esp + 0x10], ebx
// 00553a5b  e840a51300           call 0x68dfa0
// 00553a60  8b0b                 mov ecx, dword ptr [ebx]
// 00553a62  80791500             cmp byte ptr [ecx + 0x15], 0
// 00553a66  7405                 je 0x553a6d
// 00553a68  8b7b08               mov edi, dword ptr [ebx + 8]
// 00553a6b  eb1b                 jmp 0x553a88
// 00553a6d  8b5308               mov edx, dword ptr [ebx + 8]
// 00553a70  807a1500             cmp byte ptr [edx + 0x15], 0
// 00553a74  7404                 je 0x553a7a
// 00553a76  8bf9                 mov edi, ecx
// 00553a78  eb0e                 jmp 0x553a88
// 00553a7a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00553a7e  8b7808               mov edi, dword ptr [eax + 8]
// 00553a81  8d5008               lea edx, [eax + 8]
// 00553a84  3bc3                 cmp eax, ebx
// 00553a86  756b                 jne 0x553af3
// 00553a88  807f1500             cmp byte ptr [edi + 0x15], 0
// 00553a8c  8b7304               mov esi, dword ptr [ebx + 4]
// 00553a8f  7503                 jne 0x553a94
// 00553a91  897704               mov dword ptr [edi + 4], esi
// 00553a94  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00553a97  395804               cmp dword ptr [eax + 4], ebx
// 00553a9a  7505                 jne 0x553aa1
// 00553a9c  897804               mov dword ptr [eax + 4], edi
// 00553a9f  eb0b                 jmp 0x553aac
// 00553aa1  391e                 cmp dword ptr [esi], ebx
// 00553aa3  7504                 jne 0x553aa9
// 00553aa5  893e                 mov dword ptr [esi], edi
// 00553aa7  eb03                 jmp 0x553aac
// 00553aa9  897e08               mov dword ptr [esi + 8], edi
// 00553aac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00553aaf  8b03                 mov eax, dword ptr [ebx]
// 00553ab1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00553ab5  7515                 jne 0x553acc
// 00553ab7  807f1500             cmp byte ptr [edi + 0x15], 0
// 00553abb  7404                 je 0x553ac1
// 00553abd  8bc6                 mov eax, esi
// 00553abf  eb09                 jmp 0x553aca
// 00553ac1  57                   push edi
// 00553ac2  e81994f1ff           call 0x46cee0
// 00553ac7  83c404               add esp, 4
// 00553aca  8903                 mov dword ptr [ebx], eax
// 00553acc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00553acf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00553ad3  394b08               cmp dword ptr [ebx + 8], ecx
// 00553ad6  7577                 jne 0x553b4f
// 00553ad8  807f1500             cmp byte ptr [edi + 0x15], 0
// 00553adc  7407                 je 0x553ae5
// 00553ade  8bc6                 mov eax, esi
// 00553ae0  894308               mov dword ptr [ebx + 8], eax
// 00553ae3  eb6a                 jmp 0x553b4f
// 00553ae5  57                   push edi
// 00553ae6  e8c5600b00           call 0x609bb0
// 00553aeb  83c404               add esp, 4
// 00553aee  894308               mov dword ptr [ebx + 8], eax
// 00553af1  eb5c                 jmp 0x553b4f
// 00553af3  894104               mov dword ptr [ecx + 4], eax
// 00553af6  8b0b                 mov ecx, dword ptr [ebx]
// 00553af8  8908                 mov dword ptr [eax], ecx
// 00553afa  3b4308               cmp eax, dword ptr [ebx + 8]
// 00553afd  7504                 jne 0x553b03
// 00553aff  8bf0                 mov esi, eax
// 00553b01  eb19                 jmp 0x553b1c
// 00553b03  807f1500             cmp byte ptr [edi + 0x15], 0
// 00553b07  8b7004               mov esi, dword ptr [eax + 4]
// 00553b0a  7503                 jne 0x553b0f
// 00553b0c  897704               mov dword ptr [edi + 4], esi
// 00553b0f  893e                 mov dword ptr [esi], edi
// 00553b11  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00553b14  890a                 mov dword ptr [edx], ecx
// 00553b16  8b5308               mov edx, dword ptr [ebx + 8]
// 00553b19  894204               mov dword ptr [edx + 4], eax
// 00553b1c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00553b1f  395904               cmp dword ptr [ecx + 4], ebx
// 00553b22  7505                 jne 0x553b29
// 00553b24  894104               mov dword ptr [ecx + 4], eax
// 00553b27  eb0e                 jmp 0x553b37
// 00553b29  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00553b2c  3919                 cmp dword ptr [ecx], ebx
// 00553b2e  7504                 jne 0x553b34
// 00553b30  8901                 mov dword ptr [ecx], eax
// 00553b32  eb03                 jmp 0x553b37
// 00553b34  894108               mov dword ptr [ecx + 8], eax
// 00553b37  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00553b3a  894804               mov dword ptr [eax + 4], ecx
// 00553b3d  8d4b14               lea ecx, [ebx + 0x14]
// 00553b40  83c014               add eax, 0x14
// 00553b43  3bc1                 cmp eax, ecx
// 00553b45  7408                 je 0x553b4f
// 00553b47  8a19                 mov bl, byte ptr [ecx]
// 00553b49  8a10                 mov dl, byte ptr [eax]
// 00553b4b  8818                 mov byte ptr [eax], bl
// 00553b4d  8811                 mov byte ptr [ecx], dl
// 00553b4f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00553b53  b301                 mov bl, 1
// 00553b55  385a14               cmp byte ptr [edx + 0x14], bl
// 00553b58  0f85fd000000         jne 0x553c5b
// 00553b5e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00553b61  3b7804               cmp edi, dword ptr [eax + 4]
// 00553b64  0f84ee000000         je 0x553c58
// 00553b6a  8d9b00000000         lea ebx, [ebx]
// 00553b70  385f14               cmp byte ptr [edi + 0x14], bl
// 00553b73  0f85df000000         jne 0x553c58
// 00553b79  8b06                 mov eax, dword ptr [esi]
// 00553b7b  3bf8                 cmp edi, eax
// 00553b7d  7565                 jne 0x553be4
// 00553b7f  8b4608               mov eax, dword ptr [esi + 8]
// 00553b82  80781400             cmp byte ptr [eax + 0x14], 0
// 00553b86  7512                 jne 0x553b9a
// 00553b88  885814               mov byte ptr [eax + 0x14], bl
// 00553b8b  56                   push esi
// 00553b8c  8bcd                 mov ecx, ebp
// 00553b8e  c6461400             mov byte ptr [esi + 0x14], 0
// 00553b92  e80917efff           call 0x4452a0
// 00553b97  8b4608               mov eax, dword ptr [esi + 8]
// 00553b9a  80781500             cmp byte ptr [eax + 0x15], 0
// 00553b9e  7574                 jne 0x553c14
// 00553ba0  8b08                 mov ecx, dword ptr [eax]
// 00553ba2  385914               cmp byte ptr [ecx + 0x14], bl
// 00553ba5  7508                 jne 0x553baf
// 00553ba7  8b5008               mov edx, dword ptr [eax + 8]
// 00553baa  385a14               cmp byte ptr [edx + 0x14], bl
// 00553bad  7461                 je 0x553c10
// 00553baf  8b4808               mov ecx, dword ptr [eax + 8]
// 00553bb2  385914               cmp byte ptr [ecx + 0x14], bl
// 00553bb5  7514                 jne 0x553bcb
// 00553bb7  8b10                 mov edx, dword ptr [eax]
// 00553bb9  885a14               mov byte ptr [edx + 0x14], bl
// 00553bbc  50                   push eax
// 00553bbd  8bcd                 mov ecx, ebp
// 00553bbf  c6401400             mov byte ptr [eax + 0x14], 0
// 00553bc3  e878300600           call 0x5b6c40
// 00553bc8  8b4608               mov eax, dword ptr [esi + 8]
// 00553bcb  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00553bce  884814               mov byte ptr [eax + 0x14], cl
// 00553bd1  885e14               mov byte ptr [esi + 0x14], bl
// 00553bd4  8b5008               mov edx, dword ptr [eax + 8]
// 00553bd7  56                   push esi
// 00553bd8  8bcd                 mov ecx, ebp
// 00553bda  885a14               mov byte ptr [edx + 0x14], bl
// 00553bdd  e8be16efff           call 0x4452a0
// 00553be2  eb74                 jmp 0x553c58
// 00553be4  80781400             cmp byte ptr [eax + 0x14], 0
// 00553be8  7511                 jne 0x553bfb
// 00553bea  885814               mov byte ptr [eax + 0x14], bl
// 00553bed  56                   push esi
// 00553bee  8bcd                 mov ecx, ebp
// 00553bf0  c6461400             mov byte ptr [esi + 0x14], 0
// 00553bf4  e847300600           call 0x5b6c40
// 00553bf9  8b06                 mov eax, dword ptr [esi]
// 00553bfb  80781500             cmp byte ptr [eax + 0x15], 0
// 00553bff  7513                 jne 0x553c14
// 00553c01  8b4808               mov ecx, dword ptr [eax + 8]
// 00553c04  385914               cmp byte ptr [ecx + 0x14], bl
// 00553c07  751e                 jne 0x553c27
// 00553c09  8b10                 mov edx, dword ptr [eax]
// 00553c0b  385a14               cmp byte ptr [edx + 0x14], bl
// 00553c0e  7517                 jne 0x553c27
// 00553c10  c6401400             mov byte ptr [eax + 0x14], 0
// 00553c14  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00553c17  8bfe                 mov edi, esi
// 00553c19  8b7604               mov esi, dword ptr [esi + 4]
// 00553c1c  3b7804               cmp edi, dword ptr [eax + 4]
// 00553c1f  0f854bffffff         jne 0x553b70
// 00553c25  eb31                 jmp 0x553c58
// 00553c27  8b08                 mov ecx, dword ptr [eax]
// 00553c29  385914               cmp byte ptr [ecx + 0x14], bl
// 00553c2c  7514                 jne 0x553c42
// 00553c2e  8b5008               mov edx, dword ptr [eax + 8]
// 00553c31  885a14               mov byte ptr [edx + 0x14], bl
// 00553c34  50                   push eax
// 00553c35  8bcd                 mov ecx, ebp
// 00553c37  c6401400             mov byte ptr [eax + 0x14], 0
// 00553c3b  e86016efff           call 0x4452a0
// 00553c40  8b06                 mov eax, dword ptr [esi]
// 00553c42  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00553c45  884814               mov byte ptr [eax + 0x14], cl
// 00553c48  885e14               mov byte ptr [esi + 0x14], bl
// 00553c4b  8b10                 mov edx, dword ptr [eax]
// 00553c4d  56                   push esi
// 00553c4e  8bcd                 mov ecx, ebp
// 00553c50  885a14               mov byte ptr [edx + 0x14], bl
// 00553c53  e8e82f0600           call 0x5b6c40
// 00553c58  885f14               mov byte ptr [edi + 0x14], bl
// 00553c5b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00553c5f  50                   push eax
// 00553c60  e815ca1400           call 0x6a067a
// 00553c65  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00553c68  83c404               add esp, 4
// 00553c6b  5f                   pop edi
// 00553c6c  5e                   pop esi
// 00553c6d  5b                   pop ebx
// 00553c6e  85c0                 test eax, eax
// 00553c70  7604                 jbe 0x553c76
// 00553c72  48                   dec eax
// 00553c73  89451c               mov dword ptr [ebp + 0x1c], eax
// 00553c76  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00553c7a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00553c7e  8b5500               mov edx, dword ptr [ebp]
// 00553c81  894804               mov dword ptr [eax + 4], ecx
// 00553c84  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00553c88  8910                 mov dword ptr [eax], edx
// 00553c8a  5d                   pop ebp
// 00553c8b  64890d00000000       mov dword ptr fs:[0], ecx
// 00553c92  83c454               add esp, 0x54
// 00553c95  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
