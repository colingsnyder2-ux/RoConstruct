// from server: 100% by auto
// roc 2009-12 0047f960  unit: Ogre::VRbxFont::?$SharedPtr  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f960
//
// 0047f960  64a100000000         mov eax, dword ptr fs:[0]
// 0047f966  6aff                 push -1
// 0047f968  6812699500           push 0x956912
// 0047f96d  50                   push eax
// 0047f96e  64892500000000       mov dword ptr fs:[0], esp
// 0047f975  83ec44               sub esp, 0x44
// 0047f978  57                   push edi
// 0047f979  8bf9                 mov edi, ecx
// 0047f97b  817f1c5c74d105       cmp dword ptr [edi + 0x1c], 0x5d1745c
// 0047f982  7259                 jb 0x47f9dd
// 0047f984  6800f59900           push 0x99f500
// 0047f989  8d4c2408             lea ecx, [esp + 8]
// 0047f98d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0047f993  8d4c2420             lea ecx, [esp + 0x20]
// 0047f997  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0047f99f  ff1554b79800         call dword ptr [0x98b754]
// 0047f9a5  8d442404             lea eax, [esp + 4]
// 0047f9a9  50                   push eax
// 0047f9aa  8d4c2430             lea ecx, [esp + 0x30]
// 0047f9ae  c644245401           mov byte ptr [esp + 0x54], 1
// 0047f9b3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0047f9bb  ff15f0b69800         call dword ptr [0x98b6f0]
// 0047f9c1  68e4efa800           push 0xa8efe4
// 0047f9c6  8d4c2424             lea ecx, [esp + 0x24]
// 0047f9ca  51                   push ecx
// 0047f9cb  c644245800           mov byte ptr [esp + 0x58], 0
// 0047f9d0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0047f9d8  e89b4e3700           call 0x7f4878
// 0047f9dd  8b542464             mov edx, dword ptr [esp + 0x64]
// 0047f9e1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047f9e4  53                   push ebx
// 0047f9e5  55                   push ebp
// 0047f9e6  56                   push esi
// 0047f9e7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0047f9eb  6a00                 push 0
// 0047f9ed  52                   push edx
// 0047f9ee  50                   push eax
// 0047f9ef  56                   push esi
// 0047f9f0  50                   push eax
// 0047f9f1  e8bafaffff           call 0x47f4b0
// 0047f9f6  8be8                 mov ebp, eax
// 0047f9f8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047f9fb  bb01000000           mov ebx, 1
// 0047fa00  015f1c               add dword ptr [edi + 0x1c], ebx
// 0047fa03  3bf0                 cmp esi, eax
// 0047fa05  7510                 jne 0x47fa17
// 0047fa07  896804               mov dword ptr [eax + 4], ebp
// 0047fa0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047fa0d  8928                 mov dword ptr [eax], ebp
// 0047fa0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0047fa12  896908               mov dword ptr [ecx + 8], ebp
// 0047fa15  eb22                 jmp 0x47fa39
// 0047fa17  807c246800           cmp byte ptr [esp + 0x68], 0
// 0047fa1c  740d                 je 0x47fa2b
// 0047fa1e  892e                 mov dword ptr [esi], ebp
// 0047fa20  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047fa23  3b30                 cmp esi, dword ptr [eax]
// 0047fa25  7512                 jne 0x47fa39
// 0047fa27  8928                 mov dword ptr [eax], ebp
// 0047fa29  eb0e                 jmp 0x47fa39
// 0047fa2b  896e08               mov dword ptr [esi + 8], ebp
// 0047fa2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047fa31  3b7008               cmp esi, dword ptr [eax + 8]
// 0047fa34  7503                 jne 0x47fa39
// 0047fa36  896808               mov dword ptr [eax + 8], ebp
// 0047fa39  8b5504               mov edx, dword ptr [ebp + 4]
// 0047fa3c  807a3800             cmp byte ptr [edx + 0x38], 0
// 0047fa40  8d4504               lea eax, [ebp + 4]
// 0047fa43  8bf5                 mov esi, ebp
// 0047fa45  0f85ea000000         jne 0x47fb35
// 0047fa4b  eb03                 jmp 0x47fa50
// 0047fa4d  8d4900               lea ecx, [ecx]
// 0047fa50  8b08                 mov ecx, dword ptr [eax]
// 0047fa52  8b5104               mov edx, dword ptr [ecx + 4]
// 0047fa55  3b0a                 cmp ecx, dword ptr [edx]
// 0047fa57  7551                 jne 0x47faaa
// 0047fa59  8b5208               mov edx, dword ptr [edx + 8]
// 0047fa5c  807a3800             cmp byte ptr [edx + 0x38], 0
// 0047fa60  7519                 jne 0x47fa7b
// 0047fa62  885938               mov byte ptr [ecx + 0x38], bl
// 0047fa65  885a38               mov byte ptr [edx + 0x38], bl
// 0047fa68  8b10                 mov edx, dword ptr [eax]
// 0047fa6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047fa6d  c6413800             mov byte ptr [ecx + 0x38], 0
// 0047fa71  8b10                 mov edx, dword ptr [eax]
// 0047fa73  8b7204               mov esi, dword ptr [edx + 4]
// 0047fa76  e9aa000000           jmp 0x47fb25
// 0047fa7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0047fa7e  750a                 jne 0x47fa8a
// 0047fa80  8bf1                 mov esi, ecx
// 0047fa82  56                   push esi
// 0047fa83  8bcf                 mov ecx, edi
// 0047fa85  e8b6f4ffff           call 0x47ef40
// 0047fa8a  8b4604               mov eax, dword ptr [esi + 4]
// 0047fa8d  885838               mov byte ptr [eax + 0x38], bl
// 0047fa90  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047fa93  8b5104               mov edx, dword ptr [ecx + 4]
// 0047fa96  c6423800             mov byte ptr [edx + 0x38], 0
// 0047fa9a  8b4604               mov eax, dword ptr [esi + 4]
// 0047fa9d  8b4804               mov ecx, dword ptr [eax + 4]
// 0047faa0  51                   push ecx
// 0047faa1  8bcf                 mov ecx, edi
// 0047faa3  e8e8f4ffff           call 0x47ef90
// 0047faa8  eb7b                 jmp 0x47fb25
// 0047faaa  8b12                 mov edx, dword ptr [edx]
// 0047faac  807a3800             cmp byte ptr [edx + 0x38], 0
// 0047fab0  7516                 jne 0x47fac8
// 0047fab2  885938               mov byte ptr [ecx + 0x38], bl
// 0047fab5  885a38               mov byte ptr [edx + 0x38], bl
// 0047fab8  8b10                 mov edx, dword ptr [eax]
// 0047faba  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047fabd  c6413800             mov byte ptr [ecx + 0x38], 0
// 0047fac1  8b10                 mov edx, dword ptr [eax]
// 0047fac3  8b7204               mov esi, dword ptr [edx + 4]
// 0047fac6  eb5d                 jmp 0x47fb25
// 0047fac8  3b31                 cmp esi, dword ptr [ecx]
// 0047faca  750a                 jne 0x47fad6
// 0047facc  8bf1                 mov esi, ecx
// 0047face  56                   push esi
// 0047facf  8bcf                 mov ecx, edi
// 0047fad1  e8baf4ffff           call 0x47ef90
// 0047fad6  8b4604               mov eax, dword ptr [esi + 4]
// 0047fad9  885838               mov byte ptr [eax + 0x38], bl
// 0047fadc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047fadf  8b5104               mov edx, dword ptr [ecx + 4]
// 0047fae2  c6423800             mov byte ptr [edx + 0x38], 0
// 0047fae6  8b4604               mov eax, dword ptr [esi + 4]
// 0047fae9  8b4004               mov eax, dword ptr [eax + 4]
// 0047faec  8b4808               mov ecx, dword ptr [eax + 8]
// 0047faef  8b11                 mov edx, dword ptr [ecx]
// 0047faf1  895008               mov dword ptr [eax + 8], edx
// 0047faf4  8b11                 mov edx, dword ptr [ecx]
// 0047faf6  807a3900             cmp byte ptr [edx + 0x39], 0
// 0047fafa  7503                 jne 0x47faff
// 0047fafc  894204               mov dword ptr [edx + 4], eax
// 0047faff  8b5004               mov edx, dword ptr [eax + 4]
// 0047fb02  895104               mov dword ptr [ecx + 4], edx
// 0047fb05  8b5718               mov edx, dword ptr [edi + 0x18]
// 0047fb08  3b4204               cmp eax, dword ptr [edx + 4]
// 0047fb0b  7505                 jne 0x47fb12
// 0047fb0d  894a04               mov dword ptr [edx + 4], ecx
// 0047fb10  eb0e                 jmp 0x47fb20
// 0047fb12  8b5004               mov edx, dword ptr [eax + 4]
// 0047fb15  3b02                 cmp eax, dword ptr [edx]
// 0047fb17  7504                 jne 0x47fb1d
// 0047fb19  890a                 mov dword ptr [edx], ecx
// 0047fb1b  eb03                 jmp 0x47fb20
// 0047fb1d  894a08               mov dword ptr [edx + 8], ecx
// 0047fb20  8901                 mov dword ptr [ecx], eax
// 0047fb22  894804               mov dword ptr [eax + 4], ecx
// 0047fb25  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047fb28  80793800             cmp byte ptr [ecx + 0x38], 0
// 0047fb2c  8d4604               lea eax, [esi + 4]
// 0047fb2f  0f841bffffff         je 0x47fa50
// 0047fb35  8b5718               mov edx, dword ptr [edi + 0x18]
// 0047fb38  8b4204               mov eax, dword ptr [edx + 4]
// 0047fb3b  885838               mov byte ptr [eax + 0x38], bl
// 0047fb3e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0047fb42  8b0f                 mov ecx, dword ptr [edi]
// 0047fb44  5e                   pop esi
// 0047fb45  896804               mov dword ptr [eax + 4], ebp
// 0047fb48  5d                   pop ebp
// 0047fb49  8908                 mov dword ptr [eax], ecx
// 0047fb4b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0047fb4f  5b                   pop ebx
// 0047fb50  5f                   pop edi
// 0047fb51  64890d00000000       mov dword ptr fs:[0], ecx
// 0047fb58  83c450               add esp, 0x50
// 0047fb5b  c21000               ret 0x10
// standard library map_int<pod40> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
