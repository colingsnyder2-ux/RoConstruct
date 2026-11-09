// from server: 100% by auto
// roc 2010-06 007576b0  unit: RBX::PrismPoly  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007576b0
//
// 007576b0  64a100000000         mov eax, dword ptr fs:[0]
// 007576b6  6aff                 push -1
// 007576b8  68e22f9a00           push 0x9a2fe2
// 007576bd  50                   push eax
// 007576be  64892500000000       mov dword ptr fs:[0], esp
// 007576c5  83ec44               sub esp, 0x44
// 007576c8  57                   push edi
// 007576c9  8bf9                 mov edi, ecx
// 007576cb  817f1ca9aaaa0a       cmp dword ptr [edi + 0x1c], 0xaaaaaa9
// 007576d2  7259                 jb 0x75772d
// 007576d4  68a800a000           push 0xa000a8
// 007576d9  8d4c2408             lea ecx, [esp + 8]
// 007576dd  ff1510a49e00         call dword ptr [0x9ea410]
// 007576e3  8d4c2420             lea ecx, [esp + 0x20]
// 007576e7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007576ef  ff1518a99e00         call dword ptr [0x9ea918]
// 007576f5  8d442404             lea eax, [esp + 4]
// 007576f9  50                   push eax
// 007576fa  8d4c2430             lea ecx, [esp + 0x30]
// 007576fe  c644245401           mov byte ptr [esp + 0x54], 1
// 00757703  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0075770b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00757711  68601bb000           push 0xb01b60
// 00757716  8d4c2424             lea ecx, [esp + 0x24]
// 0075771a  51                   push ecx
// 0075771b  c644245800           mov byte ptr [esp + 0x58], 0
// 00757720  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00757728  e885120500           call 0x7a89b2
// 0075772d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00757731  8b4718               mov eax, dword ptr [edi + 0x18]
// 00757734  53                   push ebx
// 00757735  55                   push ebp
// 00757736  56                   push esi
// 00757737  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0075773b  6a00                 push 0
// 0075773d  52                   push edx
// 0075773e  50                   push eax
// 0075773f  56                   push esi
// 00757740  50                   push eax
// 00757741  e80affffff           call 0x757650
// 00757746  8be8                 mov ebp, eax
// 00757748  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075774b  bb01000000           mov ebx, 1
// 00757750  015f1c               add dword ptr [edi + 0x1c], ebx
// 00757753  3bf0                 cmp esi, eax
// 00757755  7510                 jne 0x757767
// 00757757  896804               mov dword ptr [eax + 4], ebp
// 0075775a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075775d  8928                 mov dword ptr [eax], ebp
// 0075775f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00757762  896908               mov dword ptr [ecx + 8], ebp
// 00757765  eb22                 jmp 0x757789
// 00757767  807c246800           cmp byte ptr [esp + 0x68], 0
// 0075776c  740d                 je 0x75777b
// 0075776e  892e                 mov dword ptr [esi], ebp
// 00757770  8b4718               mov eax, dword ptr [edi + 0x18]
// 00757773  3b30                 cmp esi, dword ptr [eax]
// 00757775  7512                 jne 0x757789
// 00757777  8928                 mov dword ptr [eax], ebp
// 00757779  eb0e                 jmp 0x757789
// 0075777b  896e08               mov dword ptr [esi + 8], ebp
// 0075777e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00757781  3b7008               cmp esi, dword ptr [eax + 8]
// 00757784  7503                 jne 0x757789
// 00757786  896808               mov dword ptr [eax + 8], ebp
// 00757789  8b5504               mov edx, dword ptr [ebp + 4]
// 0075778c  807a2400             cmp byte ptr [edx + 0x24], 0
// 00757790  8d4504               lea eax, [ebp + 4]
// 00757793  8bf5                 mov esi, ebp
// 00757795  0f85ea000000         jne 0x757885
// 0075779b  eb03                 jmp 0x7577a0
// 0075779d  8d4900               lea ecx, [ecx]
// 007577a0  8b08                 mov ecx, dword ptr [eax]
// 007577a2  8b5104               mov edx, dword ptr [ecx + 4]
// 007577a5  3b0a                 cmp ecx, dword ptr [edx]
// 007577a7  7551                 jne 0x7577fa
// 007577a9  8b5208               mov edx, dword ptr [edx + 8]
// 007577ac  807a2400             cmp byte ptr [edx + 0x24], 0
// 007577b0  7519                 jne 0x7577cb
// 007577b2  885924               mov byte ptr [ecx + 0x24], bl
// 007577b5  885a24               mov byte ptr [edx + 0x24], bl
// 007577b8  8b10                 mov edx, dword ptr [eax]
// 007577ba  8b4a04               mov ecx, dword ptr [edx + 4]
// 007577bd  c6412400             mov byte ptr [ecx + 0x24], 0
// 007577c1  8b10                 mov edx, dword ptr [eax]
// 007577c3  8b7204               mov esi, dword ptr [edx + 4]
// 007577c6  e9aa000000           jmp 0x757875
// 007577cb  3b7108               cmp esi, dword ptr [ecx + 8]
// 007577ce  750a                 jne 0x7577da
// 007577d0  8bf1                 mov esi, ecx
// 007577d2  56                   push esi
// 007577d3  8bcf                 mov ecx, edi
// 007577d5  e826feffff           call 0x757600
// 007577da  8b4604               mov eax, dword ptr [esi + 4]
// 007577dd  885824               mov byte ptr [eax + 0x24], bl
// 007577e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007577e3  8b5104               mov edx, dword ptr [ecx + 4]
// 007577e6  c6422400             mov byte ptr [edx + 0x24], 0
// 007577ea  8b4604               mov eax, dword ptr [esi + 4]
// 007577ed  8b4804               mov ecx, dword ptr [eax + 4]
// 007577f0  51                   push ecx
// 007577f1  8bcf                 mov ecx, edi
// 007577f3  e8c8f2dcff           call 0x526ac0
// 007577f8  eb7b                 jmp 0x757875
// 007577fa  8b12                 mov edx, dword ptr [edx]
// 007577fc  807a2400             cmp byte ptr [edx + 0x24], 0
// 00757800  7516                 jne 0x757818
// 00757802  885924               mov byte ptr [ecx + 0x24], bl
// 00757805  885a24               mov byte ptr [edx + 0x24], bl
// 00757808  8b10                 mov edx, dword ptr [eax]
// 0075780a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0075780d  c6412400             mov byte ptr [ecx + 0x24], 0
// 00757811  8b10                 mov edx, dword ptr [eax]
// 00757813  8b7204               mov esi, dword ptr [edx + 4]
// 00757816  eb5d                 jmp 0x757875
// 00757818  3b31                 cmp esi, dword ptr [ecx]
// 0075781a  750a                 jne 0x757826
// 0075781c  8bf1                 mov esi, ecx
// 0075781e  56                   push esi
// 0075781f  8bcf                 mov ecx, edi
// 00757821  e89af2dcff           call 0x526ac0
// 00757826  8b4604               mov eax, dword ptr [esi + 4]
// 00757829  885824               mov byte ptr [eax + 0x24], bl
// 0075782c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075782f  8b5104               mov edx, dword ptr [ecx + 4]
// 00757832  c6422400             mov byte ptr [edx + 0x24], 0
// 00757836  8b4604               mov eax, dword ptr [esi + 4]
// 00757839  8b4004               mov eax, dword ptr [eax + 4]
// 0075783c  8b4808               mov ecx, dword ptr [eax + 8]
// 0075783f  8b11                 mov edx, dword ptr [ecx]
// 00757841  895008               mov dword ptr [eax + 8], edx
// 00757844  8b11                 mov edx, dword ptr [ecx]
// 00757846  807a2500             cmp byte ptr [edx + 0x25], 0
// 0075784a  7503                 jne 0x75784f
// 0075784c  894204               mov dword ptr [edx + 4], eax
// 0075784f  8b5004               mov edx, dword ptr [eax + 4]
// 00757852  895104               mov dword ptr [ecx + 4], edx
// 00757855  8b5718               mov edx, dword ptr [edi + 0x18]
// 00757858  3b4204               cmp eax, dword ptr [edx + 4]
// 0075785b  7505                 jne 0x757862
// 0075785d  894a04               mov dword ptr [edx + 4], ecx
// 00757860  eb0e                 jmp 0x757870
// 00757862  8b5004               mov edx, dword ptr [eax + 4]
// 00757865  3b02                 cmp eax, dword ptr [edx]
// 00757867  7504                 jne 0x75786d
// 00757869  890a                 mov dword ptr [edx], ecx
// 0075786b  eb03                 jmp 0x757870
// 0075786d  894a08               mov dword ptr [edx + 8], ecx
// 00757870  8901                 mov dword ptr [ecx], eax
// 00757872  894804               mov dword ptr [eax + 4], ecx
// 00757875  8b4e04               mov ecx, dword ptr [esi + 4]
// 00757878  80792400             cmp byte ptr [ecx + 0x24], 0
// 0075787c  8d4604               lea eax, [esi + 4]
// 0075787f  0f841bffffff         je 0x7577a0
// 00757885  8b5718               mov edx, dword ptr [edi + 0x18]
// 00757888  8b4204               mov eax, dword ptr [edx + 4]
// 0075788b  885824               mov byte ptr [eax + 0x24], bl
// 0075788e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00757892  8b0f                 mov ecx, dword ptr [edi]
// 00757894  5e                   pop esi
// 00757895  896804               mov dword ptr [eax + 4], ebp
// 00757898  5d                   pop ebp
// 00757899  8908                 mov dword ptr [eax], ecx
// 0075789b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0075789f  5b                   pop ebx
// 007578a0  5f                   pop edi
// 007578a1  64890d00000000       mov dword ptr fs:[0], ecx
// 007578a8  83c450               add esp, 0x50
// 007578ab  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
