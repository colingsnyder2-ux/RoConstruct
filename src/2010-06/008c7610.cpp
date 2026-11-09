// from server: 100% by auto
// roc 2010-06 008c7610  unit: Ogre::VRbxFont::?$SharedPtr  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c7610
//
// 008c7610  64a100000000         mov eax, dword ptr fs:[0]
// 008c7616  6aff                 push -1
// 008c7618  68e22f9a00           push 0x9a2fe2
// 008c761d  50                   push eax
// 008c761e  64892500000000       mov dword ptr fs:[0], esp
// 008c7625  83ec44               sub esp, 0x44
// 008c7628  57                   push edi
// 008c7629  8bf9                 mov edi, ecx
// 008c762b  817f1c5c74d105       cmp dword ptr [edi + 0x1c], 0x5d1745c
// 008c7632  7259                 jb 0x8c768d
// 008c7634  68a800a000           push 0xa000a8
// 008c7639  8d4c2408             lea ecx, [esp + 8]
// 008c763d  ff1510a49e00         call dword ptr [0x9ea410]
// 008c7643  8d4c2420             lea ecx, [esp + 0x20]
// 008c7647  c744245000000000     mov dword ptr [esp + 0x50], 0
// 008c764f  ff1518a99e00         call dword ptr [0x9ea918]
// 008c7655  8d442404             lea eax, [esp + 4]
// 008c7659  50                   push eax
// 008c765a  8d4c2430             lea ecx, [esp + 0x30]
// 008c765e  c644245401           mov byte ptr [esp + 0x54], 1
// 008c7663  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 008c766b  ff150ca49e00         call dword ptr [0x9ea40c]
// 008c7671  68601bb000           push 0xb01b60
// 008c7676  8d4c2424             lea ecx, [esp + 0x24]
// 008c767a  51                   push ecx
// 008c767b  c644245800           mov byte ptr [esp + 0x58], 0
// 008c7680  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 008c7688  e82513eeff           call 0x7a89b2
// 008c768d  8b542464             mov edx, dword ptr [esp + 0x64]
// 008c7691  8b4718               mov eax, dword ptr [edi + 0x18]
// 008c7694  53                   push ebx
// 008c7695  55                   push ebp
// 008c7696  56                   push esi
// 008c7697  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 008c769b  6a00                 push 0
// 008c769d  52                   push edx
// 008c769e  50                   push eax
// 008c769f  56                   push esi
// 008c76a0  50                   push eax
// 008c76a1  e8aafaffff           call 0x8c7150
// 008c76a6  8be8                 mov ebp, eax
// 008c76a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 008c76ab  bb01000000           mov ebx, 1
// 008c76b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 008c76b3  3bf0                 cmp esi, eax
// 008c76b5  7510                 jne 0x8c76c7
// 008c76b7  896804               mov dword ptr [eax + 4], ebp
// 008c76ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 008c76bd  8928                 mov dword ptr [eax], ebp
// 008c76bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 008c76c2  896908               mov dword ptr [ecx + 8], ebp
// 008c76c5  eb22                 jmp 0x8c76e9
// 008c76c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 008c76cc  740d                 je 0x8c76db
// 008c76ce  892e                 mov dword ptr [esi], ebp
// 008c76d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 008c76d3  3b30                 cmp esi, dword ptr [eax]
// 008c76d5  7512                 jne 0x8c76e9
// 008c76d7  8928                 mov dword ptr [eax], ebp
// 008c76d9  eb0e                 jmp 0x8c76e9
// 008c76db  896e08               mov dword ptr [esi + 8], ebp
// 008c76de  8b4718               mov eax, dword ptr [edi + 0x18]
// 008c76e1  3b7008               cmp esi, dword ptr [eax + 8]
// 008c76e4  7503                 jne 0x8c76e9
// 008c76e6  896808               mov dword ptr [eax + 8], ebp
// 008c76e9  8b5504               mov edx, dword ptr [ebp + 4]
// 008c76ec  807a3800             cmp byte ptr [edx + 0x38], 0
// 008c76f0  8d4504               lea eax, [ebp + 4]
// 008c76f3  8bf5                 mov esi, ebp
// 008c76f5  0f85ea000000         jne 0x8c77e5
// 008c76fb  eb03                 jmp 0x8c7700
// 008c76fd  8d4900               lea ecx, [ecx]
// 008c7700  8b08                 mov ecx, dword ptr [eax]
// 008c7702  8b5104               mov edx, dword ptr [ecx + 4]
// 008c7705  3b0a                 cmp ecx, dword ptr [edx]
// 008c7707  7551                 jne 0x8c775a
// 008c7709  8b5208               mov edx, dword ptr [edx + 8]
// 008c770c  807a3800             cmp byte ptr [edx + 0x38], 0
// 008c7710  7519                 jne 0x8c772b
// 008c7712  885938               mov byte ptr [ecx + 0x38], bl
// 008c7715  885a38               mov byte ptr [edx + 0x38], bl
// 008c7718  8b10                 mov edx, dword ptr [eax]
// 008c771a  8b4a04               mov ecx, dword ptr [edx + 4]
// 008c771d  c6413800             mov byte ptr [ecx + 0x38], 0
// 008c7721  8b10                 mov edx, dword ptr [eax]
// 008c7723  8b7204               mov esi, dword ptr [edx + 4]
// 008c7726  e9aa000000           jmp 0x8c77d5
// 008c772b  3b7108               cmp esi, dword ptr [ecx + 8]
// 008c772e  750a                 jne 0x8c773a
// 008c7730  8bf1                 mov esi, ecx
// 008c7732  56                   push esi
// 008c7733  8bcf                 mov ecx, edi
// 008c7735  e8a660d4ff           call 0x60d7e0
// 008c773a  8b4604               mov eax, dword ptr [esi + 4]
// 008c773d  885838               mov byte ptr [eax + 0x38], bl
// 008c7740  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c7743  8b5104               mov edx, dword ptr [ecx + 4]
// 008c7746  c6423800             mov byte ptr [edx + 0x38], 0
// 008c774a  8b4604               mov eax, dword ptr [esi + 4]
// 008c774d  8b4804               mov ecx, dword ptr [eax + 4]
// 008c7750  51                   push ecx
// 008c7751  8bcf                 mov ecx, edi
// 008c7753  e8a8f5ffff           call 0x8c6d00
// 008c7758  eb7b                 jmp 0x8c77d5
// 008c775a  8b12                 mov edx, dword ptr [edx]
// 008c775c  807a3800             cmp byte ptr [edx + 0x38], 0
// 008c7760  7516                 jne 0x8c7778
// 008c7762  885938               mov byte ptr [ecx + 0x38], bl
// 008c7765  885a38               mov byte ptr [edx + 0x38], bl
// 008c7768  8b10                 mov edx, dword ptr [eax]
// 008c776a  8b4a04               mov ecx, dword ptr [edx + 4]
// 008c776d  c6413800             mov byte ptr [ecx + 0x38], 0
// 008c7771  8b10                 mov edx, dword ptr [eax]
// 008c7773  8b7204               mov esi, dword ptr [edx + 4]
// 008c7776  eb5d                 jmp 0x8c77d5
// 008c7778  3b31                 cmp esi, dword ptr [ecx]
// 008c777a  750a                 jne 0x8c7786
// 008c777c  8bf1                 mov esi, ecx
// 008c777e  56                   push esi
// 008c777f  8bcf                 mov ecx, edi
// 008c7781  e87af5ffff           call 0x8c6d00
// 008c7786  8b4604               mov eax, dword ptr [esi + 4]
// 008c7789  885838               mov byte ptr [eax + 0x38], bl
// 008c778c  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c778f  8b5104               mov edx, dword ptr [ecx + 4]
// 008c7792  c6423800             mov byte ptr [edx + 0x38], 0
// 008c7796  8b4604               mov eax, dword ptr [esi + 4]
// 008c7799  8b4004               mov eax, dword ptr [eax + 4]
// 008c779c  8b4808               mov ecx, dword ptr [eax + 8]
// 008c779f  8b11                 mov edx, dword ptr [ecx]
// 008c77a1  895008               mov dword ptr [eax + 8], edx
// 008c77a4  8b11                 mov edx, dword ptr [ecx]
// 008c77a6  807a3900             cmp byte ptr [edx + 0x39], 0
// 008c77aa  7503                 jne 0x8c77af
// 008c77ac  894204               mov dword ptr [edx + 4], eax
// 008c77af  8b5004               mov edx, dword ptr [eax + 4]
// 008c77b2  895104               mov dword ptr [ecx + 4], edx
// 008c77b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 008c77b8  3b4204               cmp eax, dword ptr [edx + 4]
// 008c77bb  7505                 jne 0x8c77c2
// 008c77bd  894a04               mov dword ptr [edx + 4], ecx
// 008c77c0  eb0e                 jmp 0x8c77d0
// 008c77c2  8b5004               mov edx, dword ptr [eax + 4]
// 008c77c5  3b02                 cmp eax, dword ptr [edx]
// 008c77c7  7504                 jne 0x8c77cd
// 008c77c9  890a                 mov dword ptr [edx], ecx
// 008c77cb  eb03                 jmp 0x8c77d0
// 008c77cd  894a08               mov dword ptr [edx + 8], ecx
// 008c77d0  8901                 mov dword ptr [ecx], eax
// 008c77d2  894804               mov dword ptr [eax + 4], ecx
// 008c77d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c77d8  80793800             cmp byte ptr [ecx + 0x38], 0
// 008c77dc  8d4604               lea eax, [esi + 4]
// 008c77df  0f841bffffff         je 0x8c7700
// 008c77e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 008c77e8  8b4204               mov eax, dword ptr [edx + 4]
// 008c77eb  885838               mov byte ptr [eax + 0x38], bl
// 008c77ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 008c77f2  8b0f                 mov ecx, dword ptr [edi]
// 008c77f4  5e                   pop esi
// 008c77f5  896804               mov dword ptr [eax + 4], ebp
// 008c77f8  5d                   pop ebp
// 008c77f9  8908                 mov dword ptr [eax], ecx
// 008c77fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008c77ff  5b                   pop ebx
// 008c7800  5f                   pop edi
// 008c7801  64890d00000000       mov dword ptr fs:[0], ecx
// 008c7808  83c450               add esp, 0x50
// 008c780b  c21000               ret 0x10
// standard library map_int<pod40> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
