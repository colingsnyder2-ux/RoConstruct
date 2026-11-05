// from server: 100% by auto
// roc 2008-06 00681360  unit: Ogre::RbxSceneNode  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00681360
//
// 00681360  64a100000000         mov eax, dword ptr fs:[0]
// 00681366  6aff                 push -1
// 00681368  6842e87d00           push 0x7de842
// 0068136d  50                   push eax
// 0068136e  64892500000000       mov dword ptr fs:[0], esp
// 00681375  83ec44               sub esp, 0x44
// 00681378  57                   push edi
// 00681379  8bf9                 mov edi, ecx
// 0068137b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 00681382  7259                 jb 0x6813dd
// 00681384  688cb28000           push 0x80b28c
// 00681389  8d4c2408             lea ecx, [esp + 8]
// 0068138d  ff1558248000         call dword ptr [0x802458]
// 00681393  8d4c2420             lea ecx, [esp + 0x20]
// 00681397  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0068139f  ff1598288000         call dword ptr [0x802898]
// 006813a5  8d442404             lea eax, [esp + 4]
// 006813a9  50                   push eax
// 006813aa  8d4c2430             lea ecx, [esp + 0x30]
// 006813ae  c644245401           mov byte ptr [esp + 0x54], 1
// 006813b3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 006813bb  ff155c248000         call dword ptr [0x80245c]
// 006813c1  68c00c8d00           push 0x8d0cc0
// 006813c6  8d4c2424             lea ecx, [esp + 0x24]
// 006813ca  51                   push ecx
// 006813cb  c644245800           mov byte ptr [esp + 0x58], 0
// 006813d0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 006813d8  e8af010200           call 0x6a158c
// 006813dd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006813e1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006813e4  53                   push ebx
// 006813e5  55                   push ebp
// 006813e6  56                   push esi
// 006813e7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006813eb  6a00                 push 0
// 006813ed  52                   push edx
// 006813ee  50                   push eax
// 006813ef  56                   push esi
// 006813f0  50                   push eax
// 006813f1  e80affffff           call 0x681300
// 006813f6  8be8                 mov ebp, eax
// 006813f8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006813fb  bb01000000           mov ebx, 1
// 00681400  015f1c               add dword ptr [edi + 0x1c], ebx
// 00681403  3bf0                 cmp esi, eax
// 00681405  7510                 jne 0x681417
// 00681407  896804               mov dword ptr [eax + 4], ebp
// 0068140a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068140d  8928                 mov dword ptr [eax], ebp
// 0068140f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00681412  896908               mov dword ptr [ecx + 8], ebp
// 00681415  eb22                 jmp 0x681439
// 00681417  807c246800           cmp byte ptr [esp + 0x68], 0
// 0068141c  740d                 je 0x68142b
// 0068141e  892e                 mov dword ptr [esi], ebp
// 00681420  8b4718               mov eax, dword ptr [edi + 0x18]
// 00681423  3b30                 cmp esi, dword ptr [eax]
// 00681425  7512                 jne 0x681439
// 00681427  8928                 mov dword ptr [eax], ebp
// 00681429  eb0e                 jmp 0x681439
// 0068142b  896e08               mov dword ptr [esi + 8], ebp
// 0068142e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00681431  3b7008               cmp esi, dword ptr [eax + 8]
// 00681434  7503                 jne 0x681439
// 00681436  896808               mov dword ptr [eax + 8], ebp
// 00681439  8b5504               mov edx, dword ptr [ebp + 4]
// 0068143c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00681440  8d4504               lea eax, [ebp + 4]
// 00681443  8bf5                 mov esi, ebp
// 00681445  0f85ea000000         jne 0x681535
// 0068144b  eb03                 jmp 0x681450
// 0068144d  8d4900               lea ecx, [ecx]
// 00681450  8b08                 mov ecx, dword ptr [eax]
// 00681452  8b5104               mov edx, dword ptr [ecx + 4]
// 00681455  3b0a                 cmp ecx, dword ptr [edx]
// 00681457  7551                 jne 0x6814aa
// 00681459  8b5208               mov edx, dword ptr [edx + 8]
// 0068145c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00681460  7519                 jne 0x68147b
// 00681462  885920               mov byte ptr [ecx + 0x20], bl
// 00681465  885a20               mov byte ptr [edx + 0x20], bl
// 00681468  8b10                 mov edx, dword ptr [eax]
// 0068146a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068146d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00681471  8b10                 mov edx, dword ptr [eax]
// 00681473  8b7204               mov esi, dword ptr [edx + 4]
// 00681476  e9aa000000           jmp 0x681525
// 0068147b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0068147e  750a                 jne 0x68148a
// 00681480  8bf1                 mov esi, ecx
// 00681482  56                   push esi
// 00681483  8bcf                 mov ecx, edi
// 00681485  e86661e5ff           call 0x4d75f0
// 0068148a  8b4604               mov eax, dword ptr [esi + 4]
// 0068148d  885820               mov byte ptr [eax + 0x20], bl
// 00681490  8b4e04               mov ecx, dword ptr [esi + 4]
// 00681493  8b5104               mov edx, dword ptr [ecx + 4]
// 00681496  c6422000             mov byte ptr [edx + 0x20], 0
// 0068149a  8b4604               mov eax, dword ptr [esi + 4]
// 0068149d  8b4804               mov ecx, dword ptr [eax + 4]
// 006814a0  51                   push ecx
// 006814a1  8bcf                 mov ecx, edi
// 006814a3  e8181af3ff           call 0x5b2ec0
// 006814a8  eb7b                 jmp 0x681525
// 006814aa  8b12                 mov edx, dword ptr [edx]
// 006814ac  807a2000             cmp byte ptr [edx + 0x20], 0
// 006814b0  7516                 jne 0x6814c8
// 006814b2  885920               mov byte ptr [ecx + 0x20], bl
// 006814b5  885a20               mov byte ptr [edx + 0x20], bl
// 006814b8  8b10                 mov edx, dword ptr [eax]
// 006814ba  8b4a04               mov ecx, dword ptr [edx + 4]
// 006814bd  c6412000             mov byte ptr [ecx + 0x20], 0
// 006814c1  8b10                 mov edx, dword ptr [eax]
// 006814c3  8b7204               mov esi, dword ptr [edx + 4]
// 006814c6  eb5d                 jmp 0x681525
// 006814c8  3b31                 cmp esi, dword ptr [ecx]
// 006814ca  750a                 jne 0x6814d6
// 006814cc  8bf1                 mov esi, ecx
// 006814ce  56                   push esi
// 006814cf  8bcf                 mov ecx, edi
// 006814d1  e8ea19f3ff           call 0x5b2ec0
// 006814d6  8b4604               mov eax, dword ptr [esi + 4]
// 006814d9  885820               mov byte ptr [eax + 0x20], bl
// 006814dc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006814df  8b5104               mov edx, dword ptr [ecx + 4]
// 006814e2  c6422000             mov byte ptr [edx + 0x20], 0
// 006814e6  8b4604               mov eax, dword ptr [esi + 4]
// 006814e9  8b4004               mov eax, dword ptr [eax + 4]
// 006814ec  8b4808               mov ecx, dword ptr [eax + 8]
// 006814ef  8b11                 mov edx, dword ptr [ecx]
// 006814f1  895008               mov dword ptr [eax + 8], edx
// 006814f4  8b11                 mov edx, dword ptr [ecx]
// 006814f6  807a2100             cmp byte ptr [edx + 0x21], 0
// 006814fa  7503                 jne 0x6814ff
// 006814fc  894204               mov dword ptr [edx + 4], eax
// 006814ff  8b5004               mov edx, dword ptr [eax + 4]
// 00681502  895104               mov dword ptr [ecx + 4], edx
// 00681505  8b5718               mov edx, dword ptr [edi + 0x18]
// 00681508  3b4204               cmp eax, dword ptr [edx + 4]
// 0068150b  7505                 jne 0x681512
// 0068150d  894a04               mov dword ptr [edx + 4], ecx
// 00681510  eb0e                 jmp 0x681520
// 00681512  8b5004               mov edx, dword ptr [eax + 4]
// 00681515  3b02                 cmp eax, dword ptr [edx]
// 00681517  7504                 jne 0x68151d
// 00681519  890a                 mov dword ptr [edx], ecx
// 0068151b  eb03                 jmp 0x681520
// 0068151d  894a08               mov dword ptr [edx + 8], ecx
// 00681520  8901                 mov dword ptr [ecx], eax
// 00681522  894804               mov dword ptr [eax + 4], ecx
// 00681525  8b4e04               mov ecx, dword ptr [esi + 4]
// 00681528  80792000             cmp byte ptr [ecx + 0x20], 0
// 0068152c  8d4604               lea eax, [esi + 4]
// 0068152f  0f841bffffff         je 0x681450
// 00681535  8b5718               mov edx, dword ptr [edi + 0x18]
// 00681538  8b4204               mov eax, dword ptr [edx + 4]
// 0068153b  885820               mov byte ptr [eax + 0x20], bl
// 0068153e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00681542  8b0f                 mov ecx, dword ptr [edi]
// 00681544  5e                   pop esi
// 00681545  896804               mov dword ptr [eax + 4], ebp
// 00681548  5d                   pop ebp
// 00681549  8908                 mov dword ptr [eax], ecx
// 0068154b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0068154f  5b                   pop ebx
// 00681550  5f                   pop edi
// 00681551  64890d00000000       mov dword ptr fs:[0], ecx
// 00681558  83c450               add esp, 0x50
// 0068155b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
