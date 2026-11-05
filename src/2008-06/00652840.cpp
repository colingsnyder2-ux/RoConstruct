// from server: 100% by auto
// roc 2008-06 00652840  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652840
//
// 00652840  64a100000000         mov eax, dword ptr fs:[0]
// 00652846  6aff                 push -1
// 00652848  6842e87d00           push 0x7de842
// 0065284d  50                   push eax
// 0065284e  64892500000000       mov dword ptr fs:[0], esp
// 00652855  83ec44               sub esp, 0x44
// 00652858  57                   push edi
// 00652859  8bf9                 mov edi, ecx
// 0065285b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 00652862  7259                 jb 0x6528bd
// 00652864  688cb28000           push 0x80b28c
// 00652869  8d4c2408             lea ecx, [esp + 8]
// 0065286d  ff1558248000         call dword ptr [0x802458]
// 00652873  8d4c2420             lea ecx, [esp + 0x20]
// 00652877  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0065287f  ff1598288000         call dword ptr [0x802898]
// 00652885  8d442404             lea eax, [esp + 4]
// 00652889  50                   push eax
// 0065288a  8d4c2430             lea ecx, [esp + 0x30]
// 0065288e  c644245401           mov byte ptr [esp + 0x54], 1
// 00652893  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0065289b  ff155c248000         call dword ptr [0x80245c]
// 006528a1  68c00c8d00           push 0x8d0cc0
// 006528a6  8d4c2424             lea ecx, [esp + 0x24]
// 006528aa  51                   push ecx
// 006528ab  c644245800           mov byte ptr [esp + 0x58], 0
// 006528b0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 006528b8  e8cfec0400           call 0x6a158c
// 006528bd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006528c1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006528c4  53                   push ebx
// 006528c5  55                   push ebp
// 006528c6  56                   push esi
// 006528c7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006528cb  6a00                 push 0
// 006528cd  52                   push edx
// 006528ce  50                   push eax
// 006528cf  56                   push esi
// 006528d0  50                   push eax
// 006528d1  e89af9ffff           call 0x652270
// 006528d6  8be8                 mov ebp, eax
// 006528d8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006528db  bb01000000           mov ebx, 1
// 006528e0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006528e3  3bf0                 cmp esi, eax
// 006528e5  7510                 jne 0x6528f7
// 006528e7  896804               mov dword ptr [eax + 4], ebp
// 006528ea  8b4718               mov eax, dword ptr [edi + 0x18]
// 006528ed  8928                 mov dword ptr [eax], ebp
// 006528ef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006528f2  896908               mov dword ptr [ecx + 8], ebp
// 006528f5  eb22                 jmp 0x652919
// 006528f7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006528fc  740d                 je 0x65290b
// 006528fe  892e                 mov dword ptr [esi], ebp
// 00652900  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652903  3b30                 cmp esi, dword ptr [eax]
// 00652905  7512                 jne 0x652919
// 00652907  8928                 mov dword ptr [eax], ebp
// 00652909  eb0e                 jmp 0x652919
// 0065290b  896e08               mov dword ptr [esi + 8], ebp
// 0065290e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652911  3b7008               cmp esi, dword ptr [eax + 8]
// 00652914  7503                 jne 0x652919
// 00652916  896808               mov dword ptr [eax + 8], ebp
// 00652919  8b5504               mov edx, dword ptr [ebp + 4]
// 0065291c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00652920  8d4504               lea eax, [ebp + 4]
// 00652923  8bf5                 mov esi, ebp
// 00652925  0f85ea000000         jne 0x652a15
// 0065292b  eb03                 jmp 0x652930
// 0065292d  8d4900               lea ecx, [ecx]
// 00652930  8b08                 mov ecx, dword ptr [eax]
// 00652932  8b5104               mov edx, dword ptr [ecx + 4]
// 00652935  3b0a                 cmp ecx, dword ptr [edx]
// 00652937  7551                 jne 0x65298a
// 00652939  8b5208               mov edx, dword ptr [edx + 8]
// 0065293c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00652940  7519                 jne 0x65295b
// 00652942  885948               mov byte ptr [ecx + 0x48], bl
// 00652945  885a48               mov byte ptr [edx + 0x48], bl
// 00652948  8b10                 mov edx, dword ptr [eax]
// 0065294a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0065294d  c6414800             mov byte ptr [ecx + 0x48], 0
// 00652951  8b10                 mov edx, dword ptr [eax]
// 00652953  8b7204               mov esi, dword ptr [edx + 4]
// 00652956  e9aa000000           jmp 0x652a05
// 0065295b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0065295e  750a                 jne 0x65296a
// 00652960  8bf1                 mov esi, ecx
// 00652962  56                   push esi
// 00652963  8bcf                 mov ecx, edi
// 00652965  e8a649f3ff           call 0x587310
// 0065296a  8b4604               mov eax, dword ptr [esi + 4]
// 0065296d  885848               mov byte ptr [eax + 0x48], bl
// 00652970  8b4e04               mov ecx, dword ptr [esi + 4]
// 00652973  8b5104               mov edx, dword ptr [ecx + 4]
// 00652976  c6424800             mov byte ptr [edx + 0x48], 0
// 0065297a  8b4604               mov eax, dword ptr [esi + 4]
// 0065297d  8b4804               mov ecx, dword ptr [eax + 4]
// 00652980  51                   push ecx
// 00652981  8bcf                 mov ecx, edi
// 00652983  e85847f3ff           call 0x5870e0
// 00652988  eb7b                 jmp 0x652a05
// 0065298a  8b12                 mov edx, dword ptr [edx]
// 0065298c  807a4800             cmp byte ptr [edx + 0x48], 0
// 00652990  7516                 jne 0x6529a8
// 00652992  885948               mov byte ptr [ecx + 0x48], bl
// 00652995  885a48               mov byte ptr [edx + 0x48], bl
// 00652998  8b10                 mov edx, dword ptr [eax]
// 0065299a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0065299d  c6414800             mov byte ptr [ecx + 0x48], 0
// 006529a1  8b10                 mov edx, dword ptr [eax]
// 006529a3  8b7204               mov esi, dword ptr [edx + 4]
// 006529a6  eb5d                 jmp 0x652a05
// 006529a8  3b31                 cmp esi, dword ptr [ecx]
// 006529aa  750a                 jne 0x6529b6
// 006529ac  8bf1                 mov esi, ecx
// 006529ae  56                   push esi
// 006529af  8bcf                 mov ecx, edi
// 006529b1  e82a47f3ff           call 0x5870e0
// 006529b6  8b4604               mov eax, dword ptr [esi + 4]
// 006529b9  885848               mov byte ptr [eax + 0x48], bl
// 006529bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006529bf  8b5104               mov edx, dword ptr [ecx + 4]
// 006529c2  c6424800             mov byte ptr [edx + 0x48], 0
// 006529c6  8b4604               mov eax, dword ptr [esi + 4]
// 006529c9  8b4004               mov eax, dword ptr [eax + 4]
// 006529cc  8b4808               mov ecx, dword ptr [eax + 8]
// 006529cf  8b11                 mov edx, dword ptr [ecx]
// 006529d1  895008               mov dword ptr [eax + 8], edx
// 006529d4  8b11                 mov edx, dword ptr [ecx]
// 006529d6  807a4900             cmp byte ptr [edx + 0x49], 0
// 006529da  7503                 jne 0x6529df
// 006529dc  894204               mov dword ptr [edx + 4], eax
// 006529df  8b5004               mov edx, dword ptr [eax + 4]
// 006529e2  895104               mov dword ptr [ecx + 4], edx
// 006529e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006529e8  3b4204               cmp eax, dword ptr [edx + 4]
// 006529eb  7505                 jne 0x6529f2
// 006529ed  894a04               mov dword ptr [edx + 4], ecx
// 006529f0  eb0e                 jmp 0x652a00
// 006529f2  8b5004               mov edx, dword ptr [eax + 4]
// 006529f5  3b02                 cmp eax, dword ptr [edx]
// 006529f7  7504                 jne 0x6529fd
// 006529f9  890a                 mov dword ptr [edx], ecx
// 006529fb  eb03                 jmp 0x652a00
// 006529fd  894a08               mov dword ptr [edx + 8], ecx
// 00652a00  8901                 mov dword ptr [ecx], eax
// 00652a02  894804               mov dword ptr [eax + 4], ecx
// 00652a05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00652a08  80794800             cmp byte ptr [ecx + 0x48], 0
// 00652a0c  8d4604               lea eax, [esi + 4]
// 00652a0f  0f841bffffff         je 0x652930
// 00652a15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00652a18  8b4204               mov eax, dword ptr [edx + 4]
// 00652a1b  885848               mov byte ptr [eax + 0x48], bl
// 00652a1e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00652a22  8b0f                 mov ecx, dword ptr [edi]
// 00652a24  5e                   pop esi
// 00652a25  896804               mov dword ptr [eax + 4], ebp
// 00652a28  5d                   pop ebp
// 00652a29  8908                 mov dword ptr [eax], ecx
// 00652a2b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00652a2f  5b                   pop ebx
// 00652a30  5f                   pop edi
// 00652a31  64890d00000000       mov dword ptr fs:[0], ecx
// 00652a38  83c450               add esp, 0x50
// 00652a3b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
