// from server: 100% by auto
// roc 2009-12 0055b1c0  unit: RBX::Network::ServerReplicator  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055b1c0
//
// 0055b1c0  64a100000000         mov eax, dword ptr fs:[0]
// 0055b1c6  6aff                 push -1
// 0055b1c8  6812699500           push 0x956912
// 0055b1cd  50                   push eax
// 0055b1ce  64892500000000       mov dword ptr fs:[0], esp
// 0055b1d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0055b1d9  83ec48               sub esp, 0x48
// 0055b1dc  80782500             cmp byte ptr [eax + 0x25], 0
// 0055b1e0  55                   push ebp
// 0055b1e1  8be9                 mov ebp, ecx
// 0055b1e3  7459                 je 0x55b23e
// 0055b1e5  68e4f49900           push 0x99f4e4
// 0055b1ea  8d4c240c             lea ecx, [esp + 0xc]
// 0055b1ee  ff15f4b69800         call dword ptr [0x98b6f4]
// 0055b1f4  8d4c2424             lea ecx, [esp + 0x24]
// 0055b1f8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0055b200  ff1554b79800         call dword ptr [0x98b754]
// 0055b206  8d442408             lea eax, [esp + 8]
// 0055b20a  50                   push eax
// 0055b20b  8d4c2434             lea ecx, [esp + 0x34]
// 0055b20f  c644245801           mov byte ptr [esp + 0x58], 1
// 0055b214  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 0055b21c  ff15f0b69800         call dword ptr [0x98b6f0]
// 0055b222  688cefa800           push 0xa8ef8c
// 0055b227  8d4c2428             lea ecx, [esp + 0x28]
// 0055b22b  51                   push ecx
// 0055b22c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0055b231  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 0055b239  e83a962900           call 0x7f4878
// 0055b23e  53                   push ebx
// 0055b23f  56                   push esi
// 0055b240  8bd8                 mov ebx, eax
// 0055b242  57                   push edi
// 0055b243  8d4c246c             lea ecx, [esp + 0x6c]
// 0055b247  895c2410             mov dword ptr [esp + 0x10], ebx
// 0055b24b  e8e0fbffff           call 0x55ae30
// 0055b250  8b0b                 mov ecx, dword ptr [ebx]
// 0055b252  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055b256  7405                 je 0x55b25d
// 0055b258  8b7b08               mov edi, dword ptr [ebx + 8]
// 0055b25b  eb1b                 jmp 0x55b278
// 0055b25d  8b5308               mov edx, dword ptr [ebx + 8]
// 0055b260  807a2500             cmp byte ptr [edx + 0x25], 0
// 0055b264  7404                 je 0x55b26a
// 0055b266  8bf9                 mov edi, ecx
// 0055b268  eb0e                 jmp 0x55b278
// 0055b26a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0055b26e  8b7808               mov edi, dword ptr [eax + 8]
// 0055b271  8d5008               lea edx, [eax + 8]
// 0055b274  3bc3                 cmp eax, ebx
// 0055b276  756b                 jne 0x55b2e3
// 0055b278  807f2500             cmp byte ptr [edi + 0x25], 0
// 0055b27c  8b7304               mov esi, dword ptr [ebx + 4]
// 0055b27f  7503                 jne 0x55b284
// 0055b281  897704               mov dword ptr [edi + 4], esi
// 0055b284  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0055b287  395804               cmp dword ptr [eax + 4], ebx
// 0055b28a  7505                 jne 0x55b291
// 0055b28c  897804               mov dword ptr [eax + 4], edi
// 0055b28f  eb0b                 jmp 0x55b29c
// 0055b291  391e                 cmp dword ptr [esi], ebx
// 0055b293  7504                 jne 0x55b299
// 0055b295  893e                 mov dword ptr [esi], edi
// 0055b297  eb03                 jmp 0x55b29c
// 0055b299  897e08               mov dword ptr [esi + 8], edi
// 0055b29c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0055b29f  8b03                 mov eax, dword ptr [ebx]
// 0055b2a1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0055b2a5  7515                 jne 0x55b2bc
// 0055b2a7  807f2500             cmp byte ptr [edi + 0x25], 0
// 0055b2ab  7404                 je 0x55b2b1
// 0055b2ad  8bc6                 mov eax, esi
// 0055b2af  eb09                 jmp 0x55b2ba
// 0055b2b1  57                   push edi
// 0055b2b2  e85909efff           call 0x44bc10
// 0055b2b7  83c404               add esp, 4
// 0055b2ba  8903                 mov dword ptr [ebx], eax
// 0055b2bc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0055b2bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055b2c3  394b08               cmp dword ptr [ebx + 8], ecx
// 0055b2c6  7577                 jne 0x55b33f
// 0055b2c8  807f2500             cmp byte ptr [edi + 0x25], 0
// 0055b2cc  7407                 je 0x55b2d5
// 0055b2ce  8bc6                 mov eax, esi
// 0055b2d0  894308               mov dword ptr [ebx + 8], eax
// 0055b2d3  eb6a                 jmp 0x55b33f
// 0055b2d5  57                   push edi
// 0055b2d6  e825fbffff           call 0x55ae00
// 0055b2db  83c404               add esp, 4
// 0055b2de  894308               mov dword ptr [ebx + 8], eax
// 0055b2e1  eb5c                 jmp 0x55b33f
// 0055b2e3  894104               mov dword ptr [ecx + 4], eax
// 0055b2e6  8b0b                 mov ecx, dword ptr [ebx]
// 0055b2e8  8908                 mov dword ptr [eax], ecx
// 0055b2ea  3b4308               cmp eax, dword ptr [ebx + 8]
// 0055b2ed  7504                 jne 0x55b2f3
// 0055b2ef  8bf0                 mov esi, eax
// 0055b2f1  eb19                 jmp 0x55b30c
// 0055b2f3  807f2500             cmp byte ptr [edi + 0x25], 0
// 0055b2f7  8b7004               mov esi, dword ptr [eax + 4]
// 0055b2fa  7503                 jne 0x55b2ff
// 0055b2fc  897704               mov dword ptr [edi + 4], esi
// 0055b2ff  893e                 mov dword ptr [esi], edi
// 0055b301  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0055b304  890a                 mov dword ptr [edx], ecx
// 0055b306  8b5308               mov edx, dword ptr [ebx + 8]
// 0055b309  894204               mov dword ptr [edx + 4], eax
// 0055b30c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0055b30f  395904               cmp dword ptr [ecx + 4], ebx
// 0055b312  7505                 jne 0x55b319
// 0055b314  894104               mov dword ptr [ecx + 4], eax
// 0055b317  eb0e                 jmp 0x55b327
// 0055b319  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0055b31c  3919                 cmp dword ptr [ecx], ebx
// 0055b31e  7504                 jne 0x55b324
// 0055b320  8901                 mov dword ptr [ecx], eax
// 0055b322  eb03                 jmp 0x55b327
// 0055b324  894108               mov dword ptr [ecx + 8], eax
// 0055b327  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0055b32a  894804               mov dword ptr [eax + 4], ecx
// 0055b32d  8d4b24               lea ecx, [ebx + 0x24]
// 0055b330  83c024               add eax, 0x24
// 0055b333  3bc1                 cmp eax, ecx
// 0055b335  7408                 je 0x55b33f
// 0055b337  8a19                 mov bl, byte ptr [ecx]
// 0055b339  8a10                 mov dl, byte ptr [eax]
// 0055b33b  8818                 mov byte ptr [eax], bl
// 0055b33d  8811                 mov byte ptr [ecx], dl
// 0055b33f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055b343  b301                 mov bl, 1
// 0055b345  385a24               cmp byte ptr [edx + 0x24], bl
// 0055b348  0f85fd000000         jne 0x55b44b
// 0055b34e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0055b351  3b7804               cmp edi, dword ptr [eax + 4]
// 0055b354  0f84ee000000         je 0x55b448
// 0055b35a  8d9b00000000         lea ebx, [ebx]
// 0055b360  385f24               cmp byte ptr [edi + 0x24], bl
// 0055b363  0f85df000000         jne 0x55b448
// 0055b369  8b06                 mov eax, dword ptr [esi]
// 0055b36b  3bf8                 cmp edi, eax
// 0055b36d  7565                 jne 0x55b3d4
// 0055b36f  8b4608               mov eax, dword ptr [esi + 8]
// 0055b372  80782400             cmp byte ptr [eax + 0x24], 0
// 0055b376  7512                 jne 0x55b38a
// 0055b378  885824               mov byte ptr [eax + 0x24], bl
// 0055b37b  56                   push esi
// 0055b37c  8bcd                 mov ecx, ebp
// 0055b37e  c6462400             mov byte ptr [esi + 0x24], 0
// 0055b382  e83908efff           call 0x44bbc0
// 0055b387  8b4608               mov eax, dword ptr [esi + 8]
// 0055b38a  80782500             cmp byte ptr [eax + 0x25], 0
// 0055b38e  7574                 jne 0x55b404
// 0055b390  8b08                 mov ecx, dword ptr [eax]
// 0055b392  385924               cmp byte ptr [ecx + 0x24], bl
// 0055b395  7508                 jne 0x55b39f
// 0055b397  8b5008               mov edx, dword ptr [eax + 8]
// 0055b39a  385a24               cmp byte ptr [edx + 0x24], bl
// 0055b39d  7461                 je 0x55b400
// 0055b39f  8b4808               mov ecx, dword ptr [eax + 8]
// 0055b3a2  385924               cmp byte ptr [ecx + 0x24], bl
// 0055b3a5  7514                 jne 0x55b3bb
// 0055b3a7  8b10                 mov edx, dword ptr [eax]
// 0055b3a9  885a24               mov byte ptr [edx + 0x24], bl
// 0055b3ac  50                   push eax
// 0055b3ad  8bcd                 mov ecx, ebp
// 0055b3af  c6402400             mov byte ptr [eax + 0x24], 0
// 0055b3b3  e828fbffff           call 0x55aee0
// 0055b3b8  8b4608               mov eax, dword ptr [esi + 8]
// 0055b3bb  8a4e24               mov cl, byte ptr [esi + 0x24]
// 0055b3be  884824               mov byte ptr [eax + 0x24], cl
// 0055b3c1  885e24               mov byte ptr [esi + 0x24], bl
// 0055b3c4  8b5008               mov edx, dword ptr [eax + 8]
// 0055b3c7  56                   push esi
// 0055b3c8  8bcd                 mov ecx, ebp
// 0055b3ca  885a24               mov byte ptr [edx + 0x24], bl
// 0055b3cd  e8ee07efff           call 0x44bbc0
// 0055b3d2  eb74                 jmp 0x55b448
// 0055b3d4  80782400             cmp byte ptr [eax + 0x24], 0
// 0055b3d8  7511                 jne 0x55b3eb
// 0055b3da  885824               mov byte ptr [eax + 0x24], bl
// 0055b3dd  56                   push esi
// 0055b3de  8bcd                 mov ecx, ebp
// 0055b3e0  c6462400             mov byte ptr [esi + 0x24], 0
// 0055b3e4  e8f7faffff           call 0x55aee0
// 0055b3e9  8b06                 mov eax, dword ptr [esi]
// 0055b3eb  80782500             cmp byte ptr [eax + 0x25], 0
// 0055b3ef  7513                 jne 0x55b404
// 0055b3f1  8b4808               mov ecx, dword ptr [eax + 8]
// 0055b3f4  385924               cmp byte ptr [ecx + 0x24], bl
// 0055b3f7  751e                 jne 0x55b417
// 0055b3f9  8b10                 mov edx, dword ptr [eax]
// 0055b3fb  385a24               cmp byte ptr [edx + 0x24], bl
// 0055b3fe  7517                 jne 0x55b417
// 0055b400  c6402400             mov byte ptr [eax + 0x24], 0
// 0055b404  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0055b407  8bfe                 mov edi, esi
// 0055b409  8b7604               mov esi, dword ptr [esi + 4]
// 0055b40c  3b7804               cmp edi, dword ptr [eax + 4]
// 0055b40f  0f854bffffff         jne 0x55b360
// 0055b415  eb31                 jmp 0x55b448
// 0055b417  8b08                 mov ecx, dword ptr [eax]
// 0055b419  385924               cmp byte ptr [ecx + 0x24], bl
// 0055b41c  7514                 jne 0x55b432
// 0055b41e  8b5008               mov edx, dword ptr [eax + 8]
// 0055b421  885a24               mov byte ptr [edx + 0x24], bl
// 0055b424  50                   push eax
// 0055b425  8bcd                 mov ecx, ebp
// 0055b427  c6402400             mov byte ptr [eax + 0x24], 0
// 0055b42b  e89007efff           call 0x44bbc0
// 0055b430  8b06                 mov eax, dword ptr [esi]
// 0055b432  8a4e24               mov cl, byte ptr [esi + 0x24]
// 0055b435  884824               mov byte ptr [eax + 0x24], cl
// 0055b438  885e24               mov byte ptr [esi + 0x24], bl
// 0055b43b  8b10                 mov edx, dword ptr [eax]
// 0055b43d  56                   push esi
// 0055b43e  8bcd                 mov ecx, ebp
// 0055b440  885a24               mov byte ptr [edx + 0x24], bl
// 0055b443  e898faffff           call 0x55aee0
// 0055b448  885f24               mov byte ptr [edi + 0x24], bl
// 0055b44b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0055b44f  50                   push eax
// 0055b450  e805842900           call 0x7f385a
// 0055b455  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0055b458  83c404               add esp, 4
// 0055b45b  5f                   pop edi
// 0055b45c  5e                   pop esi
// 0055b45d  5b                   pop ebx
// 0055b45e  85c0                 test eax, eax
// 0055b460  7604                 jbe 0x55b466
// 0055b462  48                   dec eax
// 0055b463  89451c               mov dword ptr [ebp + 0x1c], eax
// 0055b466  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0055b46a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0055b46e  8b5500               mov edx, dword ptr [ebp]
// 0055b471  894804               mov dword ptr [eax + 4], ecx
// 0055b474  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0055b478  8910                 mov dword ptr [eax], edx
// 0055b47a  5d                   pop ebp
// 0055b47b  64890d00000000       mov dword ptr fs:[0], ecx
// 0055b482  83c454               add esp, 0x54
// 0055b485  c20c00               ret 0xc
// standard library set<pod24> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
