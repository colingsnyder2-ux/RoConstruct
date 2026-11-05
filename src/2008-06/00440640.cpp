// from server: 100% by auto
// roc 2008-06 00440640  unit: RBX::Soundscape::VSoundId::?$ContentItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00440640
//
// 00440640  64a100000000         mov eax, dword ptr fs:[0]
// 00440646  6aff                 push -1
// 00440648  6842e87d00           push 0x7de842
// 0044064d  50                   push eax
// 0044064e  64892500000000       mov dword ptr fs:[0], esp
// 00440655  83ec44               sub esp, 0x44
// 00440658  57                   push edi
// 00440659  8bf9                 mov edi, ecx
// 0044065b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00440662  7259                 jb 0x4406bd
// 00440664  688cb28000           push 0x80b28c
// 00440669  8d4c2408             lea ecx, [esp + 8]
// 0044066d  ff1558248000         call dword ptr [0x802458]
// 00440673  8d4c2420             lea ecx, [esp + 0x20]
// 00440677  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0044067f  ff1598288000         call dword ptr [0x802898]
// 00440685  8d442404             lea eax, [esp + 4]
// 00440689  50                   push eax
// 0044068a  8d4c2430             lea ecx, [esp + 0x30]
// 0044068e  c644245401           mov byte ptr [esp + 0x54], 1
// 00440693  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0044069b  ff155c248000         call dword ptr [0x80245c]
// 004406a1  68c00c8d00           push 0x8d0cc0
// 004406a6  8d4c2424             lea ecx, [esp + 0x24]
// 004406aa  51                   push ecx
// 004406ab  c644245800           mov byte ptr [esp + 0x58], 0
// 004406b0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004406b8  e8cf0e2600           call 0x6a158c
// 004406bd  8b542464             mov edx, dword ptr [esp + 0x64]
// 004406c1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406c4  53                   push ebx
// 004406c5  55                   push ebp
// 004406c6  56                   push esi
// 004406c7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004406cb  6a00                 push 0
// 004406cd  52                   push edx
// 004406ce  50                   push eax
// 004406cf  56                   push esi
// 004406d0  50                   push eax
// 004406d1  e8bacbffff           call 0x43d290
// 004406d6  8be8                 mov ebp, eax
// 004406d8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406db  bb01000000           mov ebx, 1
// 004406e0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004406e3  3bf0                 cmp esi, eax
// 004406e5  7510                 jne 0x4406f7
// 004406e7  896804               mov dword ptr [eax + 4], ebp
// 004406ea  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406ed  8928                 mov dword ptr [eax], ebp
// 004406ef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004406f2  896908               mov dword ptr [ecx + 8], ebp
// 004406f5  eb22                 jmp 0x440719
// 004406f7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004406fc  740d                 je 0x44070b
// 004406fe  892e                 mov dword ptr [esi], ebp
// 00440700  8b4718               mov eax, dword ptr [edi + 0x18]
// 00440703  3b30                 cmp esi, dword ptr [eax]
// 00440705  7512                 jne 0x440719
// 00440707  8928                 mov dword ptr [eax], ebp
// 00440709  eb0e                 jmp 0x440719
// 0044070b  896e08               mov dword ptr [esi + 8], ebp
// 0044070e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00440711  3b7008               cmp esi, dword ptr [eax + 8]
// 00440714  7503                 jne 0x440719
// 00440716  896808               mov dword ptr [eax + 8], ebp
// 00440719  8b5504               mov edx, dword ptr [ebp + 4]
// 0044071c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00440720  8d4504               lea eax, [ebp + 4]
// 00440723  8bf5                 mov esi, ebp
// 00440725  0f85ea000000         jne 0x440815
// 0044072b  eb03                 jmp 0x440730
// 0044072d  8d4900               lea ecx, [ecx]
// 00440730  8b08                 mov ecx, dword ptr [eax]
// 00440732  8b5104               mov edx, dword ptr [ecx + 4]
// 00440735  3b0a                 cmp ecx, dword ptr [edx]
// 00440737  7551                 jne 0x44078a
// 00440739  8b5208               mov edx, dword ptr [edx + 8]
// 0044073c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00440740  7519                 jne 0x44075b
// 00440742  885928               mov byte ptr [ecx + 0x28], bl
// 00440745  885a28               mov byte ptr [edx + 0x28], bl
// 00440748  8b10                 mov edx, dword ptr [eax]
// 0044074a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044074d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00440751  8b10                 mov edx, dword ptr [eax]
// 00440753  8b7204               mov esi, dword ptr [edx + 4]
// 00440756  e9aa000000           jmp 0x440805
// 0044075b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0044075e  750a                 jne 0x44076a
// 00440760  8bf1                 mov esi, ecx
// 00440762  56                   push esi
// 00440763  8bcf                 mov ecx, edi
// 00440765  e8366e0900           call 0x4d75a0
// 0044076a  8b4604               mov eax, dword ptr [esi + 4]
// 0044076d  885828               mov byte ptr [eax + 0x28], bl
// 00440770  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440773  8b5104               mov edx, dword ptr [ecx + 4]
// 00440776  c6422800             mov byte ptr [edx + 0x28], 0
// 0044077a  8b4604               mov eax, dword ptr [esi + 4]
// 0044077d  8b4804               mov ecx, dword ptr [eax + 4]
// 00440780  51                   push ecx
// 00440781  8bcf                 mov ecx, edi
// 00440783  e808130600           call 0x4a1a90
// 00440788  eb7b                 jmp 0x440805
// 0044078a  8b12                 mov edx, dword ptr [edx]
// 0044078c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00440790  7516                 jne 0x4407a8
// 00440792  885928               mov byte ptr [ecx + 0x28], bl
// 00440795  885a28               mov byte ptr [edx + 0x28], bl
// 00440798  8b10                 mov edx, dword ptr [eax]
// 0044079a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044079d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004407a1  8b10                 mov edx, dword ptr [eax]
// 004407a3  8b7204               mov esi, dword ptr [edx + 4]
// 004407a6  eb5d                 jmp 0x440805
// 004407a8  3b31                 cmp esi, dword ptr [ecx]
// 004407aa  750a                 jne 0x4407b6
// 004407ac  8bf1                 mov esi, ecx
// 004407ae  56                   push esi
// 004407af  8bcf                 mov ecx, edi
// 004407b1  e8da120600           call 0x4a1a90
// 004407b6  8b4604               mov eax, dword ptr [esi + 4]
// 004407b9  885828               mov byte ptr [eax + 0x28], bl
// 004407bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004407bf  8b5104               mov edx, dword ptr [ecx + 4]
// 004407c2  c6422800             mov byte ptr [edx + 0x28], 0
// 004407c6  8b4604               mov eax, dword ptr [esi + 4]
// 004407c9  8b4004               mov eax, dword ptr [eax + 4]
// 004407cc  8b4808               mov ecx, dword ptr [eax + 8]
// 004407cf  8b11                 mov edx, dword ptr [ecx]
// 004407d1  895008               mov dword ptr [eax + 8], edx
// 004407d4  8b11                 mov edx, dword ptr [ecx]
// 004407d6  807a2900             cmp byte ptr [edx + 0x29], 0
// 004407da  7503                 jne 0x4407df
// 004407dc  894204               mov dword ptr [edx + 4], eax
// 004407df  8b5004               mov edx, dword ptr [eax + 4]
// 004407e2  895104               mov dword ptr [ecx + 4], edx
// 004407e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004407e8  3b4204               cmp eax, dword ptr [edx + 4]
// 004407eb  7505                 jne 0x4407f2
// 004407ed  894a04               mov dword ptr [edx + 4], ecx
// 004407f0  eb0e                 jmp 0x440800
// 004407f2  8b5004               mov edx, dword ptr [eax + 4]
// 004407f5  3b02                 cmp eax, dword ptr [edx]
// 004407f7  7504                 jne 0x4407fd
// 004407f9  890a                 mov dword ptr [edx], ecx
// 004407fb  eb03                 jmp 0x440800
// 004407fd  894a08               mov dword ptr [edx + 8], ecx
// 00440800  8901                 mov dword ptr [ecx], eax
// 00440802  894804               mov dword ptr [eax + 4], ecx
// 00440805  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440808  80792800             cmp byte ptr [ecx + 0x28], 0
// 0044080c  8d4604               lea eax, [esi + 4]
// 0044080f  0f841bffffff         je 0x440730
// 00440815  8b5718               mov edx, dword ptr [edi + 0x18]
// 00440818  8b4204               mov eax, dword ptr [edx + 4]
// 0044081b  885828               mov byte ptr [eax + 0x28], bl
// 0044081e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00440822  8b0f                 mov ecx, dword ptr [edi]
// 00440824  5e                   pop esi
// 00440825  896804               mov dword ptr [eax + 4], ebp
// 00440828  5d                   pop ebp
// 00440829  8908                 mov dword ptr [eax], ecx
// 0044082b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0044082f  5b                   pop ebx
// 00440830  5f                   pop edi
// 00440831  64890d00000000       mov dword ptr fs:[0], ecx
// 00440838  83c450               add esp, 0x50
// 0044083b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
