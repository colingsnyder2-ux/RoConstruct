// from server: 100% by auto
// roc 2009-06 004018b0  unit: CAboutRobloxDialog  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004018b0
//
// 004018b0  64a100000000         mov eax, dword ptr fs:[0]
// 004018b6  6aff                 push -1
// 004018b8  68b2db8500           push 0x85dbb2
// 004018bd  50                   push eax
// 004018be  64892500000000       mov dword ptr fs:[0], esp
// 004018c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 004018c9  83ec48               sub esp, 0x48
// 004018cc  80781500             cmp byte ptr [eax + 0x15], 0
// 004018d0  55                   push ebp
// 004018d1  8be9                 mov ebp, ecx
// 004018d3  7459                 je 0x40192e
// 004018d5  68a4c98a00           push 0x8ac9a4
// 004018da  8d4c240c             lea ecx, [esp + 0xc]
// 004018de  ff15b4e48900         call dword ptr [0x89e4b4]
// 004018e4  8d4c2424             lea ecx, [esp + 0x24]
// 004018e8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004018f0  ff15b8e98900         call dword ptr [0x89e9b8]
// 004018f6  8d442408             lea eax, [esp + 8]
// 004018fa  50                   push eax
// 004018fb  8d4c2434             lea ecx, [esp + 0x34]
// 004018ff  c644245801           mov byte ptr [esp + 0x58], 1
// 00401904  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 0040190c  ff15b8e48900         call dword ptr [0x89e4b8]
// 00401912  68dc919700           push 0x9791dc
// 00401917  8d4c2428             lea ecx, [esp + 0x28]
// 0040191b  51                   push ecx
// 0040191c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00401921  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 00401929  e81c813100           call 0x719a4a
// 0040192e  53                   push ebx
// 0040192f  56                   push esi
// 00401930  8bd8                 mov ebx, eax
// 00401932  57                   push edi
// 00401933  8d4c246c             lea ecx, [esp + 0x6c]
// 00401937  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040193b  e830781e00           call 0x5e9170
// 00401940  8b0b                 mov ecx, dword ptr [ebx]
// 00401942  80791500             cmp byte ptr [ecx + 0x15], 0
// 00401946  7405                 je 0x40194d
// 00401948  8b7b08               mov edi, dword ptr [ebx + 8]
// 0040194b  eb1b                 jmp 0x401968
// 0040194d  8b5308               mov edx, dword ptr [ebx + 8]
// 00401950  807a1500             cmp byte ptr [edx + 0x15], 0
// 00401954  7404                 je 0x40195a
// 00401956  8bf9                 mov edi, ecx
// 00401958  eb0e                 jmp 0x401968
// 0040195a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0040195e  8b7808               mov edi, dword ptr [eax + 8]
// 00401961  8d5008               lea edx, [eax + 8]
// 00401964  3bc3                 cmp eax, ebx
// 00401966  756b                 jne 0x4019d3
// 00401968  807f1500             cmp byte ptr [edi + 0x15], 0
// 0040196c  8b7304               mov esi, dword ptr [ebx + 4]
// 0040196f  7503                 jne 0x401974
// 00401971  897704               mov dword ptr [edi + 4], esi
// 00401974  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00401977  395804               cmp dword ptr [eax + 4], ebx
// 0040197a  7505                 jne 0x401981
// 0040197c  897804               mov dword ptr [eax + 4], edi
// 0040197f  eb0b                 jmp 0x40198c
// 00401981  391e                 cmp dword ptr [esi], ebx
// 00401983  7504                 jne 0x401989
// 00401985  893e                 mov dword ptr [esi], edi
// 00401987  eb03                 jmp 0x40198c
// 00401989  897e08               mov dword ptr [esi + 8], edi
// 0040198c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0040198f  8b03                 mov eax, dword ptr [ebx]
// 00401991  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00401995  7515                 jne 0x4019ac
// 00401997  807f1500             cmp byte ptr [edi + 0x15], 0
// 0040199b  7404                 je 0x4019a1
// 0040199d  8bc6                 mov eax, esi
// 0040199f  eb09                 jmp 0x4019aa
// 004019a1  57                   push edi
// 004019a2  e899ba0400           call 0x44d440
// 004019a7  83c404               add esp, 4
// 004019aa  8903                 mov dword ptr [ebx], eax
// 004019ac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004019af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004019b3  394b08               cmp dword ptr [ebx + 8], ecx
// 004019b6  7577                 jne 0x401a2f
// 004019b8  807f1500             cmp byte ptr [edi + 0x15], 0
// 004019bc  7407                 je 0x4019c5
// 004019be  8bc6                 mov eax, esi
// 004019c0  894308               mov dword ptr [ebx + 8], eax
// 004019c3  eb6a                 jmp 0x401a2f
// 004019c5  57                   push edi
// 004019c6  e825db0c00           call 0x4cf4f0
// 004019cb  83c404               add esp, 4
// 004019ce  894308               mov dword ptr [ebx + 8], eax
// 004019d1  eb5c                 jmp 0x401a2f
// 004019d3  894104               mov dword ptr [ecx + 4], eax
// 004019d6  8b0b                 mov ecx, dword ptr [ebx]
// 004019d8  8908                 mov dword ptr [eax], ecx
// 004019da  3b4308               cmp eax, dword ptr [ebx + 8]
// 004019dd  7504                 jne 0x4019e3
// 004019df  8bf0                 mov esi, eax
// 004019e1  eb19                 jmp 0x4019fc
// 004019e3  807f1500             cmp byte ptr [edi + 0x15], 0
// 004019e7  8b7004               mov esi, dword ptr [eax + 4]
// 004019ea  7503                 jne 0x4019ef
// 004019ec  897704               mov dword ptr [edi + 4], esi
// 004019ef  893e                 mov dword ptr [esi], edi
// 004019f1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004019f4  890a                 mov dword ptr [edx], ecx
// 004019f6  8b5308               mov edx, dword ptr [ebx + 8]
// 004019f9  894204               mov dword ptr [edx + 4], eax
// 004019fc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004019ff  395904               cmp dword ptr [ecx + 4], ebx
// 00401a02  7505                 jne 0x401a09
// 00401a04  894104               mov dword ptr [ecx + 4], eax
// 00401a07  eb0e                 jmp 0x401a17
// 00401a09  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00401a0c  3919                 cmp dword ptr [ecx], ebx
// 00401a0e  7504                 jne 0x401a14
// 00401a10  8901                 mov dword ptr [ecx], eax
// 00401a12  eb03                 jmp 0x401a17
// 00401a14  894108               mov dword ptr [ecx + 8], eax
// 00401a17  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00401a1a  894804               mov dword ptr [eax + 4], ecx
// 00401a1d  8d4b14               lea ecx, [ebx + 0x14]
// 00401a20  83c014               add eax, 0x14
// 00401a23  3bc1                 cmp eax, ecx
// 00401a25  7408                 je 0x401a2f
// 00401a27  8a19                 mov bl, byte ptr [ecx]
// 00401a29  8a10                 mov dl, byte ptr [eax]
// 00401a2b  8818                 mov byte ptr [eax], bl
// 00401a2d  8811                 mov byte ptr [ecx], dl
// 00401a2f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00401a33  b301                 mov bl, 1
// 00401a35  385a14               cmp byte ptr [edx + 0x14], bl
// 00401a38  0f85fd000000         jne 0x401b3b
// 00401a3e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00401a41  3b7804               cmp edi, dword ptr [eax + 4]
// 00401a44  0f84ee000000         je 0x401b38
// 00401a4a  8d9b00000000         lea ebx, [ebx]
// 00401a50  385f14               cmp byte ptr [edi + 0x14], bl
// 00401a53  0f85df000000         jne 0x401b38
// 00401a59  8b06                 mov eax, dword ptr [esi]
// 00401a5b  3bf8                 cmp edi, eax
// 00401a5d  7565                 jne 0x401ac4
// 00401a5f  8b4608               mov eax, dword ptr [esi + 8]
// 00401a62  80781400             cmp byte ptr [eax + 0x14], 0
// 00401a66  7512                 jne 0x401a7a
// 00401a68  885814               mov byte ptr [eax + 0x14], bl
// 00401a6b  56                   push esi
// 00401a6c  8bcd                 mov ecx, ebp
// 00401a6e  c6461400             mov byte ptr [esi + 0x14], 0
// 00401a72  e819ae2f00           call 0x6fc890
// 00401a77  8b4608               mov eax, dword ptr [esi + 8]
// 00401a7a  80781500             cmp byte ptr [eax + 0x15], 0
// 00401a7e  7574                 jne 0x401af4
// 00401a80  8b08                 mov ecx, dword ptr [eax]
// 00401a82  385914               cmp byte ptr [ecx + 0x14], bl
// 00401a85  7508                 jne 0x401a8f
// 00401a87  8b5008               mov edx, dword ptr [eax + 8]
// 00401a8a  385a14               cmp byte ptr [edx + 0x14], bl
// 00401a8d  7461                 je 0x401af0
// 00401a8f  8b4808               mov ecx, dword ptr [eax + 8]
// 00401a92  385914               cmp byte ptr [ecx + 0x14], bl
// 00401a95  7514                 jne 0x401aab
// 00401a97  8b10                 mov edx, dword ptr [eax]
// 00401a99  885a14               mov byte ptr [edx + 0x14], bl
// 00401a9c  50                   push eax
// 00401a9d  8bcd                 mov ecx, ebp
// 00401a9f  c6401400             mov byte ptr [eax + 0x14], 0
// 00401aa3  e868761e00           call 0x5e9110
// 00401aa8  8b4608               mov eax, dword ptr [esi + 8]
// 00401aab  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00401aae  884814               mov byte ptr [eax + 0x14], cl
// 00401ab1  885e14               mov byte ptr [esi + 0x14], bl
// 00401ab4  8b5008               mov edx, dword ptr [eax + 8]
// 00401ab7  56                   push esi
// 00401ab8  8bcd                 mov ecx, ebp
// 00401aba  885a14               mov byte ptr [edx + 0x14], bl
// 00401abd  e8cead2f00           call 0x6fc890
// 00401ac2  eb74                 jmp 0x401b38
// 00401ac4  80781400             cmp byte ptr [eax + 0x14], 0
// 00401ac8  7511                 jne 0x401adb
// 00401aca  885814               mov byte ptr [eax + 0x14], bl
// 00401acd  56                   push esi
// 00401ace  8bcd                 mov ecx, ebp
// 00401ad0  c6461400             mov byte ptr [esi + 0x14], 0
// 00401ad4  e837761e00           call 0x5e9110
// 00401ad9  8b06                 mov eax, dword ptr [esi]
// 00401adb  80781500             cmp byte ptr [eax + 0x15], 0
// 00401adf  7513                 jne 0x401af4
// 00401ae1  8b4808               mov ecx, dword ptr [eax + 8]
// 00401ae4  385914               cmp byte ptr [ecx + 0x14], bl
// 00401ae7  751e                 jne 0x401b07
// 00401ae9  8b10                 mov edx, dword ptr [eax]
// 00401aeb  385a14               cmp byte ptr [edx + 0x14], bl
// 00401aee  7517                 jne 0x401b07
// 00401af0  c6401400             mov byte ptr [eax + 0x14], 0
// 00401af4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00401af7  8bfe                 mov edi, esi
// 00401af9  8b7604               mov esi, dword ptr [esi + 4]
// 00401afc  3b7804               cmp edi, dword ptr [eax + 4]
// 00401aff  0f854bffffff         jne 0x401a50
// 00401b05  eb31                 jmp 0x401b38
// 00401b07  8b08                 mov ecx, dword ptr [eax]
// 00401b09  385914               cmp byte ptr [ecx + 0x14], bl
// 00401b0c  7514                 jne 0x401b22
// 00401b0e  8b5008               mov edx, dword ptr [eax + 8]
// 00401b11  885a14               mov byte ptr [edx + 0x14], bl
// 00401b14  50                   push eax
// 00401b15  8bcd                 mov ecx, ebp
// 00401b17  c6401400             mov byte ptr [eax + 0x14], 0
// 00401b1b  e870ad2f00           call 0x6fc890
// 00401b20  8b06                 mov eax, dword ptr [esi]
// 00401b22  8a4e14               mov cl, byte ptr [esi + 0x14]
// 00401b25  884814               mov byte ptr [eax + 0x14], cl
// 00401b28  885e14               mov byte ptr [esi + 0x14], bl
// 00401b2b  8b10                 mov edx, dword ptr [eax]
// 00401b2d  56                   push esi
// 00401b2e  8bcd                 mov ecx, ebp
// 00401b30  885a14               mov byte ptr [edx + 0x14], bl
// 00401b33  e8d8751e00           call 0x5e9110
// 00401b38  885f14               mov byte ptr [edi + 0x14], bl
// 00401b3b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00401b3f  50                   push eax
// 00401b40  e8ed6e3100           call 0x718a32
// 00401b45  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00401b48  83c404               add esp, 4
// 00401b4b  5f                   pop edi
// 00401b4c  5e                   pop esi
// 00401b4d  5b                   pop ebx
// 00401b4e  85c0                 test eax, eax
// 00401b50  7604                 jbe 0x401b56
// 00401b52  48                   dec eax
// 00401b53  89451c               mov dword ptr [ebp + 0x1c], eax
// 00401b56  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00401b5a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00401b5e  8b5500               mov edx, dword ptr [ebp]
// 00401b61  894804               mov dword ptr [eax + 4], ecx
// 00401b64  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00401b68  8910                 mov dword ptr [eax], edx
// 00401b6a  5d                   pop ebp
// 00401b6b  64890d00000000       mov dword ptr fs:[0], ecx
// 00401b72  83c454               add esp, 0x54
// 00401b75  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
