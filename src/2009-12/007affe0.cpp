// from server: 100% by auto
// roc 2009-12 007affe0  unit: RBX::Block  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007affe0
//
// 007affe0  64a100000000         mov eax, dword ptr fs:[0]
// 007affe6  6aff                 push -1
// 007affe8  6812699500           push 0x956912
// 007affed  50                   push eax
// 007affee  64892500000000       mov dword ptr fs:[0], esp
// 007afff5  8b442418             mov eax, dword ptr [esp + 0x18]
// 007afff9  83ec48               sub esp, 0x48
// 007afffc  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007b0000  55                   push ebp
// 007b0001  8be9                 mov ebp, ecx
// 007b0003  7459                 je 0x7b005e
// 007b0005  68e4f49900           push 0x99f4e4
// 007b000a  8d4c240c             lea ecx, [esp + 0xc]
// 007b000e  ff15f4b69800         call dword ptr [0x98b6f4]
// 007b0014  8d4c2424             lea ecx, [esp + 0x24]
// 007b0018  c744245400000000     mov dword ptr [esp + 0x54], 0
// 007b0020  ff1554b79800         call dword ptr [0x98b754]
// 007b0026  8d442408             lea eax, [esp + 8]
// 007b002a  50                   push eax
// 007b002b  8d4c2434             lea ecx, [esp + 0x34]
// 007b002f  c644245801           mov byte ptr [esp + 0x58], 1
// 007b0034  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 007b003c  ff15f0b69800         call dword ptr [0x98b6f0]
// 007b0042  688cefa800           push 0xa8ef8c
// 007b0047  8d4c2428             lea ecx, [esp + 0x28]
// 007b004b  51                   push ecx
// 007b004c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 007b0051  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 007b0059  e81a480400           call 0x7f4878
// 007b005e  53                   push ebx
// 007b005f  56                   push esi
// 007b0060  8bd8                 mov ebx, eax
// 007b0062  57                   push edi
// 007b0063  8d4c246c             lea ecx, [esp + 0x6c]
// 007b0067  895c2410             mov dword ptr [esp + 0x10], ebx
// 007b006b  e800f9ffff           call 0x7af970
// 007b0070  8b0b                 mov ecx, dword ptr [ebx]
// 007b0072  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007b0076  7405                 je 0x7b007d
// 007b0078  8b7b08               mov edi, dword ptr [ebx + 8]
// 007b007b  eb1b                 jmp 0x7b0098
// 007b007d  8b5308               mov edx, dword ptr [ebx + 8]
// 007b0080  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 007b0084  7404                 je 0x7b008a
// 007b0086  8bf9                 mov edi, ecx
// 007b0088  eb0e                 jmp 0x7b0098
// 007b008a  8b442470             mov eax, dword ptr [esp + 0x70]
// 007b008e  8b7808               mov edi, dword ptr [eax + 8]
// 007b0091  8d5008               lea edx, [eax + 8]
// 007b0094  3bc3                 cmp eax, ebx
// 007b0096  756b                 jne 0x7b0103
// 007b0098  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007b009c  8b7304               mov esi, dword ptr [ebx + 4]
// 007b009f  7503                 jne 0x7b00a4
// 007b00a1  897704               mov dword ptr [edi + 4], esi
// 007b00a4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007b00a7  395804               cmp dword ptr [eax + 4], ebx
// 007b00aa  7505                 jne 0x7b00b1
// 007b00ac  897804               mov dword ptr [eax + 4], edi
// 007b00af  eb0b                 jmp 0x7b00bc
// 007b00b1  391e                 cmp dword ptr [esi], ebx
// 007b00b3  7504                 jne 0x7b00b9
// 007b00b5  893e                 mov dword ptr [esi], edi
// 007b00b7  eb03                 jmp 0x7b00bc
// 007b00b9  897e08               mov dword ptr [esi + 8], edi
// 007b00bc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 007b00bf  8b03                 mov eax, dword ptr [ebx]
// 007b00c1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 007b00c5  7515                 jne 0x7b00dc
// 007b00c7  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007b00cb  7404                 je 0x7b00d1
// 007b00cd  8bc6                 mov eax, esi
// 007b00cf  eb09                 jmp 0x7b00da
// 007b00d1  57                   push edi
// 007b00d2  e809f5ffff           call 0x7af5e0
// 007b00d7  83c404               add esp, 4
// 007b00da  8903                 mov dword ptr [ebx], eax
// 007b00dc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 007b00df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007b00e3  394b08               cmp dword ptr [ebx + 8], ecx
// 007b00e6  7577                 jne 0x7b015f
// 007b00e8  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007b00ec  7407                 je 0x7b00f5
// 007b00ee  8bc6                 mov eax, esi
// 007b00f0  894308               mov dword ptr [ebx + 8], eax
// 007b00f3  eb6a                 jmp 0x7b015f
// 007b00f5  57                   push edi
// 007b00f6  e865f5ffff           call 0x7af660
// 007b00fb  83c404               add esp, 4
// 007b00fe  894308               mov dword ptr [ebx + 8], eax
// 007b0101  eb5c                 jmp 0x7b015f
// 007b0103  894104               mov dword ptr [ecx + 4], eax
// 007b0106  8b0b                 mov ecx, dword ptr [ebx]
// 007b0108  8908                 mov dword ptr [eax], ecx
// 007b010a  3b4308               cmp eax, dword ptr [ebx + 8]
// 007b010d  7504                 jne 0x7b0113
// 007b010f  8bf0                 mov esi, eax
// 007b0111  eb19                 jmp 0x7b012c
// 007b0113  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007b0117  8b7004               mov esi, dword ptr [eax + 4]
// 007b011a  7503                 jne 0x7b011f
// 007b011c  897704               mov dword ptr [edi + 4], esi
// 007b011f  893e                 mov dword ptr [esi], edi
// 007b0121  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007b0124  890a                 mov dword ptr [edx], ecx
// 007b0126  8b5308               mov edx, dword ptr [ebx + 8]
// 007b0129  894204               mov dword ptr [edx + 4], eax
// 007b012c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007b012f  395904               cmp dword ptr [ecx + 4], ebx
// 007b0132  7505                 jne 0x7b0139
// 007b0134  894104               mov dword ptr [ecx + 4], eax
// 007b0137  eb0e                 jmp 0x7b0147
// 007b0139  8b4b04               mov ecx, dword ptr [ebx + 4]
// 007b013c  3919                 cmp dword ptr [ecx], ebx
// 007b013e  7504                 jne 0x7b0144
// 007b0140  8901                 mov dword ptr [ecx], eax
// 007b0142  eb03                 jmp 0x7b0147
// 007b0144  894108               mov dword ptr [ecx + 8], eax
// 007b0147  8b4b04               mov ecx, dword ptr [ebx + 4]
// 007b014a  894804               mov dword ptr [eax + 4], ecx
// 007b014d  8d4b1c               lea ecx, [ebx + 0x1c]
// 007b0150  83c01c               add eax, 0x1c
// 007b0153  3bc1                 cmp eax, ecx
// 007b0155  7408                 je 0x7b015f
// 007b0157  8a19                 mov bl, byte ptr [ecx]
// 007b0159  8a10                 mov dl, byte ptr [eax]
// 007b015b  8818                 mov byte ptr [eax], bl
// 007b015d  8811                 mov byte ptr [ecx], dl
// 007b015f  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b0163  b301                 mov bl, 1
// 007b0165  385a1c               cmp byte ptr [edx + 0x1c], bl
// 007b0168  0f85fd000000         jne 0x7b026b
// 007b016e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007b0171  3b7804               cmp edi, dword ptr [eax + 4]
// 007b0174  0f84ee000000         je 0x7b0268
// 007b017a  8d9b00000000         lea ebx, [ebx]
// 007b0180  385f1c               cmp byte ptr [edi + 0x1c], bl
// 007b0183  0f85df000000         jne 0x7b0268
// 007b0189  8b06                 mov eax, dword ptr [esi]
// 007b018b  3bf8                 cmp edi, eax
// 007b018d  7565                 jne 0x7b01f4
// 007b018f  8b4608               mov eax, dword ptr [esi + 8]
// 007b0192  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007b0196  7512                 jne 0x7b01aa
// 007b0198  88581c               mov byte ptr [eax + 0x1c], bl
// 007b019b  56                   push esi
// 007b019c  8bcd                 mov ecx, ebp
// 007b019e  c6461c00             mov byte ptr [esi + 0x1c], 0
// 007b01a2  e839f8ffff           call 0x7af9e0
// 007b01a7  8b4608               mov eax, dword ptr [esi + 8]
// 007b01aa  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007b01ae  7574                 jne 0x7b0224
// 007b01b0  8b08                 mov ecx, dword ptr [eax]
// 007b01b2  38591c               cmp byte ptr [ecx + 0x1c], bl
// 007b01b5  7508                 jne 0x7b01bf
// 007b01b7  8b5008               mov edx, dword ptr [eax + 8]
// 007b01ba  385a1c               cmp byte ptr [edx + 0x1c], bl
// 007b01bd  7461                 je 0x7b0220
// 007b01bf  8b4808               mov ecx, dword ptr [eax + 8]
// 007b01c2  38591c               cmp byte ptr [ecx + 0x1c], bl
// 007b01c5  7514                 jne 0x7b01db
// 007b01c7  8b10                 mov edx, dword ptr [eax]
// 007b01c9  885a1c               mov byte ptr [edx + 0x1c], bl
// 007b01cc  50                   push eax
// 007b01cd  8bcd                 mov ecx, ebp
// 007b01cf  c6401c00             mov byte ptr [eax + 0x1c], 0
// 007b01d3  e828f4ffff           call 0x7af600
// 007b01d8  8b4608               mov eax, dword ptr [esi + 8]
// 007b01db  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 007b01de  88481c               mov byte ptr [eax + 0x1c], cl
// 007b01e1  885e1c               mov byte ptr [esi + 0x1c], bl
// 007b01e4  8b5008               mov edx, dword ptr [eax + 8]
// 007b01e7  56                   push esi
// 007b01e8  8bcd                 mov ecx, ebp
// 007b01ea  885a1c               mov byte ptr [edx + 0x1c], bl
// 007b01ed  e8eef7ffff           call 0x7af9e0
// 007b01f2  eb74                 jmp 0x7b0268
// 007b01f4  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007b01f8  7511                 jne 0x7b020b
// 007b01fa  88581c               mov byte ptr [eax + 0x1c], bl
// 007b01fd  56                   push esi
// 007b01fe  8bcd                 mov ecx, ebp
// 007b0200  c6461c00             mov byte ptr [esi + 0x1c], 0
// 007b0204  e8f7f3ffff           call 0x7af600
// 007b0209  8b06                 mov eax, dword ptr [esi]
// 007b020b  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007b020f  7513                 jne 0x7b0224
// 007b0211  8b4808               mov ecx, dword ptr [eax + 8]
// 007b0214  38591c               cmp byte ptr [ecx + 0x1c], bl
// 007b0217  751e                 jne 0x7b0237
// 007b0219  8b10                 mov edx, dword ptr [eax]
// 007b021b  385a1c               cmp byte ptr [edx + 0x1c], bl
// 007b021e  7517                 jne 0x7b0237
// 007b0220  c6401c00             mov byte ptr [eax + 0x1c], 0
// 007b0224  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007b0227  8bfe                 mov edi, esi
// 007b0229  8b7604               mov esi, dword ptr [esi + 4]
// 007b022c  3b7804               cmp edi, dword ptr [eax + 4]
// 007b022f  0f854bffffff         jne 0x7b0180
// 007b0235  eb31                 jmp 0x7b0268
// 007b0237  8b08                 mov ecx, dword ptr [eax]
// 007b0239  38591c               cmp byte ptr [ecx + 0x1c], bl
// 007b023c  7514                 jne 0x7b0252
// 007b023e  8b5008               mov edx, dword ptr [eax + 8]
// 007b0241  885a1c               mov byte ptr [edx + 0x1c], bl
// 007b0244  50                   push eax
// 007b0245  8bcd                 mov ecx, ebp
// 007b0247  c6401c00             mov byte ptr [eax + 0x1c], 0
// 007b024b  e890f7ffff           call 0x7af9e0
// 007b0250  8b06                 mov eax, dword ptr [esi]
// 007b0252  8a4e1c               mov cl, byte ptr [esi + 0x1c]
// 007b0255  88481c               mov byte ptr [eax + 0x1c], cl
// 007b0258  885e1c               mov byte ptr [esi + 0x1c], bl
// 007b025b  8b10                 mov edx, dword ptr [eax]
// 007b025d  56                   push esi
// 007b025e  8bcd                 mov ecx, ebp
// 007b0260  885a1c               mov byte ptr [edx + 0x1c], bl
// 007b0263  e898f3ffff           call 0x7af600
// 007b0268  885f1c               mov byte ptr [edi + 0x1c], bl
// 007b026b  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b026f  50                   push eax
// 007b0270  e8e5350400           call 0x7f385a
// 007b0275  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 007b0278  83c404               add esp, 4
// 007b027b  5f                   pop edi
// 007b027c  5e                   pop esi
// 007b027d  5b                   pop ebx
// 007b027e  85c0                 test eax, eax
// 007b0280  7604                 jbe 0x7b0286
// 007b0282  48                   dec eax
// 007b0283  89451c               mov dword ptr [ebp + 0x1c], eax
// 007b0286  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 007b028a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 007b028e  8b5500               mov edx, dword ptr [ebp]
// 007b0291  894804               mov dword ptr [eax + 4], ecx
// 007b0294  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007b0298  8910                 mov dword ptr [eax], edx
// 007b029a  5d                   pop ebp
// 007b029b  64890d00000000       mov dword ptr fs:[0], ecx
// 007b02a2  83c454               add esp, 0x54
// 007b02a5  c20c00               ret 0xc
// standard library set<pod16> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
