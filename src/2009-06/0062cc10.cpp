// from server: 100% by auto
// roc 2009-06 0062cc10  unit: RBX::ArrowTool  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062cc10
//
// 0062cc10  64a100000000         mov eax, dword ptr fs:[0]
// 0062cc16  6aff                 push -1
// 0062cc18  68b2db8500           push 0x85dbb2
// 0062cc1d  50                   push eax
// 0062cc1e  64892500000000       mov dword ptr fs:[0], esp
// 0062cc25  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062cc29  83ec48               sub esp, 0x48
// 0062cc2c  80781100             cmp byte ptr [eax + 0x11], 0
// 0062cc30  55                   push ebp
// 0062cc31  8be9                 mov ebp, ecx
// 0062cc33  7459                 je 0x62cc8e
// 0062cc35  68a4c98a00           push 0x8ac9a4
// 0062cc3a  8d4c240c             lea ecx, [esp + 0xc]
// 0062cc3e  ff15b4e48900         call dword ptr [0x89e4b4]
// 0062cc44  8d4c2424             lea ecx, [esp + 0x24]
// 0062cc48  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0062cc50  ff15b8e98900         call dword ptr [0x89e9b8]
// 0062cc56  8d442408             lea eax, [esp + 8]
// 0062cc5a  50                   push eax
// 0062cc5b  8d4c2434             lea ecx, [esp + 0x34]
// 0062cc5f  c644245801           mov byte ptr [esp + 0x58], 1
// 0062cc64  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 0062cc6c  ff15b8e48900         call dword ptr [0x89e4b8]
// 0062cc72  68dc919700           push 0x9791dc
// 0062cc77  8d4c2428             lea ecx, [esp + 0x28]
// 0062cc7b  51                   push ecx
// 0062cc7c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0062cc81  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 0062cc89  e8bccd0e00           call 0x719a4a
// 0062cc8e  53                   push ebx
// 0062cc8f  56                   push esi
// 0062cc90  8bd8                 mov ebx, eax
// 0062cc92  57                   push edi
// 0062cc93  8d4c246c             lea ecx, [esp + 0x6c]
// 0062cc97  895c2410             mov dword ptr [esp + 0x10], ebx
// 0062cc9b  e8b09b0800           call 0x6b6850
// 0062cca0  8b0b                 mov ecx, dword ptr [ebx]
// 0062cca2  80791100             cmp byte ptr [ecx + 0x11], 0
// 0062cca6  7405                 je 0x62ccad
// 0062cca8  8b7b08               mov edi, dword ptr [ebx + 8]
// 0062ccab  eb1b                 jmp 0x62ccc8
// 0062ccad  8b5308               mov edx, dword ptr [ebx + 8]
// 0062ccb0  807a1100             cmp byte ptr [edx + 0x11], 0
// 0062ccb4  7404                 je 0x62ccba
// 0062ccb6  8bf9                 mov edi, ecx
// 0062ccb8  eb0e                 jmp 0x62ccc8
// 0062ccba  8b442470             mov eax, dword ptr [esp + 0x70]
// 0062ccbe  8b7808               mov edi, dword ptr [eax + 8]
// 0062ccc1  8d5008               lea edx, [eax + 8]
// 0062ccc4  3bc3                 cmp eax, ebx
// 0062ccc6  756b                 jne 0x62cd33
// 0062ccc8  807f1100             cmp byte ptr [edi + 0x11], 0
// 0062cccc  8b7304               mov esi, dword ptr [ebx + 4]
// 0062cccf  7503                 jne 0x62ccd4
// 0062ccd1  897704               mov dword ptr [edi + 4], esi
// 0062ccd4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0062ccd7  395804               cmp dword ptr [eax + 4], ebx
// 0062ccda  7505                 jne 0x62cce1
// 0062ccdc  897804               mov dword ptr [eax + 4], edi
// 0062ccdf  eb0b                 jmp 0x62ccec
// 0062cce1  391e                 cmp dword ptr [esi], ebx
// 0062cce3  7504                 jne 0x62cce9
// 0062cce5  893e                 mov dword ptr [esi], edi
// 0062cce7  eb03                 jmp 0x62ccec
// 0062cce9  897e08               mov dword ptr [esi + 8], edi
// 0062ccec  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0062ccef  8b03                 mov eax, dword ptr [ebx]
// 0062ccf1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0062ccf5  7515                 jne 0x62cd0c
// 0062ccf7  807f1100             cmp byte ptr [edi + 0x11], 0
// 0062ccfb  7404                 je 0x62cd01
// 0062ccfd  8bc6                 mov eax, esi
// 0062ccff  eb09                 jmp 0x62cd0a
// 0062cd01  57                   push edi
// 0062cd02  e8991a0500           call 0x67e7a0
// 0062cd07  83c404               add esp, 4
// 0062cd0a  8903                 mov dword ptr [ebx], eax
// 0062cd0c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0062cd0f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062cd13  394b08               cmp dword ptr [ebx + 8], ecx
// 0062cd16  7577                 jne 0x62cd8f
// 0062cd18  807f1100             cmp byte ptr [edi + 0x11], 0
// 0062cd1c  7407                 je 0x62cd25
// 0062cd1e  8bc6                 mov eax, esi
// 0062cd20  894308               mov dword ptr [ebx + 8], eax
// 0062cd23  eb6a                 jmp 0x62cd8f
// 0062cd25  57                   push edi
// 0062cd26  e875e2ffff           call 0x62afa0
// 0062cd2b  83c404               add esp, 4
// 0062cd2e  894308               mov dword ptr [ebx + 8], eax
// 0062cd31  eb5c                 jmp 0x62cd8f
// 0062cd33  894104               mov dword ptr [ecx + 4], eax
// 0062cd36  8b0b                 mov ecx, dword ptr [ebx]
// 0062cd38  8908                 mov dword ptr [eax], ecx
// 0062cd3a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0062cd3d  7504                 jne 0x62cd43
// 0062cd3f  8bf0                 mov esi, eax
// 0062cd41  eb19                 jmp 0x62cd5c
// 0062cd43  807f1100             cmp byte ptr [edi + 0x11], 0
// 0062cd47  8b7004               mov esi, dword ptr [eax + 4]
// 0062cd4a  7503                 jne 0x62cd4f
// 0062cd4c  897704               mov dword ptr [edi + 4], esi
// 0062cd4f  893e                 mov dword ptr [esi], edi
// 0062cd51  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0062cd54  890a                 mov dword ptr [edx], ecx
// 0062cd56  8b5308               mov edx, dword ptr [ebx + 8]
// 0062cd59  894204               mov dword ptr [edx + 4], eax
// 0062cd5c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0062cd5f  395904               cmp dword ptr [ecx + 4], ebx
// 0062cd62  7505                 jne 0x62cd69
// 0062cd64  894104               mov dword ptr [ecx + 4], eax
// 0062cd67  eb0e                 jmp 0x62cd77
// 0062cd69  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0062cd6c  3919                 cmp dword ptr [ecx], ebx
// 0062cd6e  7504                 jne 0x62cd74
// 0062cd70  8901                 mov dword ptr [ecx], eax
// 0062cd72  eb03                 jmp 0x62cd77
// 0062cd74  894108               mov dword ptr [ecx + 8], eax
// 0062cd77  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0062cd7a  894804               mov dword ptr [eax + 4], ecx
// 0062cd7d  8d4b10               lea ecx, [ebx + 0x10]
// 0062cd80  83c010               add eax, 0x10
// 0062cd83  3bc1                 cmp eax, ecx
// 0062cd85  7408                 je 0x62cd8f
// 0062cd87  8a19                 mov bl, byte ptr [ecx]
// 0062cd89  8a10                 mov dl, byte ptr [eax]
// 0062cd8b  8818                 mov byte ptr [eax], bl
// 0062cd8d  8811                 mov byte ptr [ecx], dl
// 0062cd8f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0062cd93  b301                 mov bl, 1
// 0062cd95  385a10               cmp byte ptr [edx + 0x10], bl
// 0062cd98  0f85fd000000         jne 0x62ce9b
// 0062cd9e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0062cda1  3b7804               cmp edi, dword ptr [eax + 4]
// 0062cda4  0f84ee000000         je 0x62ce98
// 0062cdaa  8d9b00000000         lea ebx, [ebx]
// 0062cdb0  385f10               cmp byte ptr [edi + 0x10], bl
// 0062cdb3  0f85df000000         jne 0x62ce98
// 0062cdb9  8b06                 mov eax, dword ptr [esi]
// 0062cdbb  3bf8                 cmp edi, eax
// 0062cdbd  7565                 jne 0x62ce24
// 0062cdbf  8b4608               mov eax, dword ptr [esi + 8]
// 0062cdc2  80781000             cmp byte ptr [eax + 0x10], 0
// 0062cdc6  7512                 jne 0x62cdda
// 0062cdc8  885810               mov byte ptr [eax + 0x10], bl
// 0062cdcb  56                   push esi
// 0062cdcc  8bcd                 mov ecx, ebp
// 0062cdce  c6461000             mov byte ptr [esi + 0x10], 0
// 0062cdd2  e8090adfff           call 0x41d7e0
// 0062cdd7  8b4608               mov eax, dword ptr [esi + 8]
// 0062cdda  80781100             cmp byte ptr [eax + 0x11], 0
// 0062cdde  7574                 jne 0x62ce54
// 0062cde0  8b08                 mov ecx, dword ptr [eax]
// 0062cde2  385910               cmp byte ptr [ecx + 0x10], bl
// 0062cde5  7508                 jne 0x62cdef
// 0062cde7  8b5008               mov edx, dword ptr [eax + 8]
// 0062cdea  385a10               cmp byte ptr [edx + 0x10], bl
// 0062cded  7461                 je 0x62ce50
// 0062cdef  8b4808               mov ecx, dword ptr [eax + 8]
// 0062cdf2  385910               cmp byte ptr [ecx + 0x10], bl
// 0062cdf5  7514                 jne 0x62ce0b
// 0062cdf7  8b10                 mov edx, dword ptr [eax]
// 0062cdf9  885a10               mov byte ptr [edx + 0x10], bl
// 0062cdfc  50                   push eax
// 0062cdfd  8bcd                 mov ecx, ebp
// 0062cdff  c6401000             mov byte ptr [eax + 0x10], 0
// 0062ce03  e81853e0ff           call 0x432120
// 0062ce08  8b4608               mov eax, dword ptr [esi + 8]
// 0062ce0b  8a4e10               mov cl, byte ptr [esi + 0x10]
// 0062ce0e  884810               mov byte ptr [eax + 0x10], cl
// 0062ce11  885e10               mov byte ptr [esi + 0x10], bl
// 0062ce14  8b5008               mov edx, dword ptr [eax + 8]
// 0062ce17  56                   push esi
// 0062ce18  8bcd                 mov ecx, ebp
// 0062ce1a  885a10               mov byte ptr [edx + 0x10], bl
// 0062ce1d  e8be09dfff           call 0x41d7e0
// 0062ce22  eb74                 jmp 0x62ce98
// 0062ce24  80781000             cmp byte ptr [eax + 0x10], 0
// 0062ce28  7511                 jne 0x62ce3b
// 0062ce2a  885810               mov byte ptr [eax + 0x10], bl
// 0062ce2d  56                   push esi
// 0062ce2e  8bcd                 mov ecx, ebp
// 0062ce30  c6461000             mov byte ptr [esi + 0x10], 0
// 0062ce34  e8e752e0ff           call 0x432120
// 0062ce39  8b06                 mov eax, dword ptr [esi]
// 0062ce3b  80781100             cmp byte ptr [eax + 0x11], 0
// 0062ce3f  7513                 jne 0x62ce54
// 0062ce41  8b4808               mov ecx, dword ptr [eax + 8]
// 0062ce44  385910               cmp byte ptr [ecx + 0x10], bl
// 0062ce47  751e                 jne 0x62ce67
// 0062ce49  8b10                 mov edx, dword ptr [eax]
// 0062ce4b  385a10               cmp byte ptr [edx + 0x10], bl
// 0062ce4e  7517                 jne 0x62ce67
// 0062ce50  c6401000             mov byte ptr [eax + 0x10], 0
// 0062ce54  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0062ce57  8bfe                 mov edi, esi
// 0062ce59  8b7604               mov esi, dword ptr [esi + 4]
// 0062ce5c  3b7804               cmp edi, dword ptr [eax + 4]
// 0062ce5f  0f854bffffff         jne 0x62cdb0
// 0062ce65  eb31                 jmp 0x62ce98
// 0062ce67  8b08                 mov ecx, dword ptr [eax]
// 0062ce69  385910               cmp byte ptr [ecx + 0x10], bl
// 0062ce6c  7514                 jne 0x62ce82
// 0062ce6e  8b5008               mov edx, dword ptr [eax + 8]
// 0062ce71  885a10               mov byte ptr [edx + 0x10], bl
// 0062ce74  50                   push eax
// 0062ce75  8bcd                 mov ecx, ebp
// 0062ce77  c6401000             mov byte ptr [eax + 0x10], 0
// 0062ce7b  e86009dfff           call 0x41d7e0
// 0062ce80  8b06                 mov eax, dword ptr [esi]
// 0062ce82  8a4e10               mov cl, byte ptr [esi + 0x10]
// 0062ce85  884810               mov byte ptr [eax + 0x10], cl
// 0062ce88  885e10               mov byte ptr [esi + 0x10], bl
// 0062ce8b  8b10                 mov edx, dword ptr [eax]
// 0062ce8d  56                   push esi
// 0062ce8e  8bcd                 mov ecx, ebp
// 0062ce90  885a10               mov byte ptr [edx + 0x10], bl
// 0062ce93  e88852e0ff           call 0x432120
// 0062ce98  885f10               mov byte ptr [edi + 0x10], bl
// 0062ce9b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0062ce9f  50                   push eax
// 0062cea0  e88dbb0e00           call 0x718a32
// 0062cea5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0062cea8  83c404               add esp, 4
// 0062ceab  5f                   pop edi
// 0062ceac  5e                   pop esi
// 0062cead  5b                   pop ebx
// 0062ceae  85c0                 test eax, eax
// 0062ceb0  7604                 jbe 0x62ceb6
// 0062ceb2  48                   dec eax
// 0062ceb3  89451c               mov dword ptr [ebp + 0x1c], eax
// 0062ceb6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0062ceba  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0062cebe  8b5500               mov edx, dword ptr [ebp]
// 0062cec1  894804               mov dword ptr [eax + 4], ecx
// 0062cec4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0062cec8  8910                 mov dword ptr [eax], edx
// 0062ceca  5d                   pop ebp
// 0062cecb  64890d00000000       mov dword ptr fs:[0], ecx
// 0062ced2  83c454               add esp, 0x54
// 0062ced5  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
