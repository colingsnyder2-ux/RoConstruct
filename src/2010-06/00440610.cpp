// from server: 100% by auto
// roc 2010-06 00440610  unit: ScriptItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00440610
//
// 00440610  64a100000000         mov eax, dword ptr fs:[0]
// 00440616  6aff                 push -1
// 00440618  68e22f9a00           push 0x9a2fe2
// 0044061d  50                   push eax
// 0044061e  64892500000000       mov dword ptr fs:[0], esp
// 00440625  83ec44               sub esp, 0x44
// 00440628  57                   push edi
// 00440629  8bf9                 mov edi, ecx
// 0044062b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00440632  7259                 jb 0x44068d
// 00440634  68a800a000           push 0xa000a8
// 00440639  8d4c2408             lea ecx, [esp + 8]
// 0044063d  ff1510a49e00         call dword ptr [0x9ea410]
// 00440643  8d4c2420             lea ecx, [esp + 0x20]
// 00440647  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0044064f  ff1518a99e00         call dword ptr [0x9ea918]
// 00440655  8d442404             lea eax, [esp + 4]
// 00440659  50                   push eax
// 0044065a  8d4c2430             lea ecx, [esp + 0x30]
// 0044065e  c644245401           mov byte ptr [esp + 0x54], 1
// 00440663  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0044066b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00440671  68601bb000           push 0xb01b60
// 00440676  8d4c2424             lea ecx, [esp + 0x24]
// 0044067a  51                   push ecx
// 0044067b  c644245800           mov byte ptr [esp + 0x58], 0
// 00440680  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00440688  e825833600           call 0x7a89b2
// 0044068d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00440691  8b4718               mov eax, dword ptr [edi + 0x18]
// 00440694  53                   push ebx
// 00440695  55                   push ebp
// 00440696  56                   push esi
// 00440697  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0044069b  6a00                 push 0
// 0044069d  52                   push edx
// 0044069e  50                   push eax
// 0044069f  56                   push esi
// 004406a0  50                   push eax
// 004406a1  e83aa2ffff           call 0x43a8e0
// 004406a6  8be8                 mov ebp, eax
// 004406a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406ab  bb01000000           mov ebx, 1
// 004406b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004406b3  3bf0                 cmp esi, eax
// 004406b5  7510                 jne 0x4406c7
// 004406b7  896804               mov dword ptr [eax + 4], ebp
// 004406ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406bd  8928                 mov dword ptr [eax], ebp
// 004406bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004406c2  896908               mov dword ptr [ecx + 8], ebp
// 004406c5  eb22                 jmp 0x4406e9
// 004406c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004406cc  740d                 je 0x4406db
// 004406ce  892e                 mov dword ptr [esi], ebp
// 004406d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406d3  3b30                 cmp esi, dword ptr [eax]
// 004406d5  7512                 jne 0x4406e9
// 004406d7  8928                 mov dword ptr [eax], ebp
// 004406d9  eb0e                 jmp 0x4406e9
// 004406db  896e08               mov dword ptr [esi + 8], ebp
// 004406de  8b4718               mov eax, dword ptr [edi + 0x18]
// 004406e1  3b7008               cmp esi, dword ptr [eax + 8]
// 004406e4  7503                 jne 0x4406e9
// 004406e6  896808               mov dword ptr [eax + 8], ebp
// 004406e9  8b5504               mov edx, dword ptr [ebp + 4]
// 004406ec  807a2800             cmp byte ptr [edx + 0x28], 0
// 004406f0  8d4504               lea eax, [ebp + 4]
// 004406f3  8bf5                 mov esi, ebp
// 004406f5  0f85ea000000         jne 0x4407e5
// 004406fb  eb03                 jmp 0x440700
// 004406fd  8d4900               lea ecx, [ecx]
// 00440700  8b08                 mov ecx, dword ptr [eax]
// 00440702  8b5104               mov edx, dword ptr [ecx + 4]
// 00440705  3b0a                 cmp ecx, dword ptr [edx]
// 00440707  7551                 jne 0x44075a
// 00440709  8b5208               mov edx, dword ptr [edx + 8]
// 0044070c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00440710  7519                 jne 0x44072b
// 00440712  885928               mov byte ptr [ecx + 0x28], bl
// 00440715  885a28               mov byte ptr [edx + 0x28], bl
// 00440718  8b10                 mov edx, dword ptr [eax]
// 0044071a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044071d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00440721  8b10                 mov edx, dword ptr [eax]
// 00440723  8b7204               mov esi, dword ptr [edx + 4]
// 00440726  e9aa000000           jmp 0x4407d5
// 0044072b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0044072e  750a                 jne 0x44073a
// 00440730  8bf1                 mov esi, ecx
// 00440732  56                   push esi
// 00440733  8bcf                 mov ecx, edi
// 00440735  e896680e00           call 0x526fd0
// 0044073a  8b4604               mov eax, dword ptr [esi + 4]
// 0044073d  885828               mov byte ptr [eax + 0x28], bl
// 00440740  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440743  8b5104               mov edx, dword ptr [ecx + 4]
// 00440746  c6422800             mov byte ptr [edx + 0x28], 0
// 0044074a  8b4604               mov eax, dword ptr [esi + 4]
// 0044074d  8b4804               mov ecx, dword ptr [eax + 4]
// 00440750  51                   push ecx
// 00440751  8bcf                 mov ecx, edi
// 00440753  e818680e00           call 0x526f70
// 00440758  eb7b                 jmp 0x4407d5
// 0044075a  8b12                 mov edx, dword ptr [edx]
// 0044075c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00440760  7516                 jne 0x440778
// 00440762  885928               mov byte ptr [ecx + 0x28], bl
// 00440765  885a28               mov byte ptr [edx + 0x28], bl
// 00440768  8b10                 mov edx, dword ptr [eax]
// 0044076a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044076d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00440771  8b10                 mov edx, dword ptr [eax]
// 00440773  8b7204               mov esi, dword ptr [edx + 4]
// 00440776  eb5d                 jmp 0x4407d5
// 00440778  3b31                 cmp esi, dword ptr [ecx]
// 0044077a  750a                 jne 0x440786
// 0044077c  8bf1                 mov esi, ecx
// 0044077e  56                   push esi
// 0044077f  8bcf                 mov ecx, edi
// 00440781  e8ea670e00           call 0x526f70
// 00440786  8b4604               mov eax, dword ptr [esi + 4]
// 00440789  885828               mov byte ptr [eax + 0x28], bl
// 0044078c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044078f  8b5104               mov edx, dword ptr [ecx + 4]
// 00440792  c6422800             mov byte ptr [edx + 0x28], 0
// 00440796  8b4604               mov eax, dword ptr [esi + 4]
// 00440799  8b4004               mov eax, dword ptr [eax + 4]
// 0044079c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044079f  8b11                 mov edx, dword ptr [ecx]
// 004407a1  895008               mov dword ptr [eax + 8], edx
// 004407a4  8b11                 mov edx, dword ptr [ecx]
// 004407a6  807a2900             cmp byte ptr [edx + 0x29], 0
// 004407aa  7503                 jne 0x4407af
// 004407ac  894204               mov dword ptr [edx + 4], eax
// 004407af  8b5004               mov edx, dword ptr [eax + 4]
// 004407b2  895104               mov dword ptr [ecx + 4], edx
// 004407b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004407b8  3b4204               cmp eax, dword ptr [edx + 4]
// 004407bb  7505                 jne 0x4407c2
// 004407bd  894a04               mov dword ptr [edx + 4], ecx
// 004407c0  eb0e                 jmp 0x4407d0
// 004407c2  8b5004               mov edx, dword ptr [eax + 4]
// 004407c5  3b02                 cmp eax, dword ptr [edx]
// 004407c7  7504                 jne 0x4407cd
// 004407c9  890a                 mov dword ptr [edx], ecx
// 004407cb  eb03                 jmp 0x4407d0
// 004407cd  894a08               mov dword ptr [edx + 8], ecx
// 004407d0  8901                 mov dword ptr [ecx], eax
// 004407d2  894804               mov dword ptr [eax + 4], ecx
// 004407d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004407d8  80792800             cmp byte ptr [ecx + 0x28], 0
// 004407dc  8d4604               lea eax, [esi + 4]
// 004407df  0f841bffffff         je 0x440700
// 004407e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004407e8  8b4204               mov eax, dword ptr [edx + 4]
// 004407eb  885828               mov byte ptr [eax + 0x28], bl
// 004407ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 004407f2  8b0f                 mov ecx, dword ptr [edi]
// 004407f4  5e                   pop esi
// 004407f5  896804               mov dword ptr [eax + 4], ebp
// 004407f8  5d                   pop ebp
// 004407f9  8908                 mov dword ptr [eax], ecx
// 004407fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004407ff  5b                   pop ebx
// 00440800  5f                   pop edi
// 00440801  64890d00000000       mov dword ptr fs:[0], ecx
// 00440808  83c450               add esp, 0x50
// 0044080b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
