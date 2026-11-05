// from server: 100% by auto
// roc 2010-06 007385c0  unit: seg_00730000  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007385c0
//
// 007385c0  64a100000000         mov eax, dword ptr fs:[0]
// 007385c6  6aff                 push -1
// 007385c8  68e22f9a00           push 0x9a2fe2
// 007385cd  50                   push eax
// 007385ce  64892500000000       mov dword ptr fs:[0], esp
// 007385d5  83ec44               sub esp, 0x44
// 007385d8  57                   push edi
// 007385d9  8bf9                 mov edi, ecx
// 007385db  817f1c5c74d105       cmp dword ptr [edi + 0x1c], 0x5d1745c
// 007385e2  7259                 jb 0x73863d
// 007385e4  68a800a000           push 0xa000a8
// 007385e9  8d4c2408             lea ecx, [esp + 8]
// 007385ed  ff1510a49e00         call dword ptr [0x9ea410]
// 007385f3  8d4c2420             lea ecx, [esp + 0x20]
// 007385f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007385ff  ff1518a99e00         call dword ptr [0x9ea918]
// 00738605  8d442404             lea eax, [esp + 4]
// 00738609  50                   push eax
// 0073860a  8d4c2430             lea ecx, [esp + 0x30]
// 0073860e  c644245401           mov byte ptr [esp + 0x54], 1
// 00738613  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0073861b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00738621  68601bb000           push 0xb01b60
// 00738626  8d4c2424             lea ecx, [esp + 0x24]
// 0073862a  51                   push ecx
// 0073862b  c644245800           mov byte ptr [esp + 0x58], 0
// 00738630  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00738638  e875030700           call 0x7a89b2
// 0073863d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00738641  8b4718               mov eax, dword ptr [edi + 0x18]
// 00738644  53                   push ebx
// 00738645  55                   push ebp
// 00738646  56                   push esi
// 00738647  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0073864b  6a00                 push 0
// 0073864d  52                   push edx
// 0073864e  50                   push eax
// 0073864f  56                   push esi
// 00738650  50                   push eax
// 00738651  e8dafeffff           call 0x738530
// 00738656  8be8                 mov ebp, eax
// 00738658  8b4718               mov eax, dword ptr [edi + 0x18]
// 0073865b  bb01000000           mov ebx, 1
// 00738660  015f1c               add dword ptr [edi + 0x1c], ebx
// 00738663  3bf0                 cmp esi, eax
// 00738665  7510                 jne 0x738677
// 00738667  896804               mov dword ptr [eax + 4], ebp
// 0073866a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0073866d  8928                 mov dword ptr [eax], ebp
// 0073866f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00738672  896908               mov dword ptr [ecx + 8], ebp
// 00738675  eb22                 jmp 0x738699
// 00738677  807c246800           cmp byte ptr [esp + 0x68], 0
// 0073867c  740d                 je 0x73868b
// 0073867e  892e                 mov dword ptr [esi], ebp
// 00738680  8b4718               mov eax, dword ptr [edi + 0x18]
// 00738683  3b30                 cmp esi, dword ptr [eax]
// 00738685  7512                 jne 0x738699
// 00738687  8928                 mov dword ptr [eax], ebp
// 00738689  eb0e                 jmp 0x738699
// 0073868b  896e08               mov dword ptr [esi + 8], ebp
// 0073868e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00738691  3b7008               cmp esi, dword ptr [eax + 8]
// 00738694  7503                 jne 0x738699
// 00738696  896808               mov dword ptr [eax + 8], ebp
// 00738699  8b5504               mov edx, dword ptr [ebp + 4]
// 0073869c  807a3800             cmp byte ptr [edx + 0x38], 0
// 007386a0  8d4504               lea eax, [ebp + 4]
// 007386a3  8bf5                 mov esi, ebp
// 007386a5  0f85ea000000         jne 0x738795
// 007386ab  eb03                 jmp 0x7386b0
// 007386ad  8d4900               lea ecx, [ecx]
// 007386b0  8b08                 mov ecx, dword ptr [eax]
// 007386b2  8b5104               mov edx, dword ptr [ecx + 4]
// 007386b5  3b0a                 cmp ecx, dword ptr [edx]
// 007386b7  7551                 jne 0x73870a
// 007386b9  8b5208               mov edx, dword ptr [edx + 8]
// 007386bc  807a3800             cmp byte ptr [edx + 0x38], 0
// 007386c0  7519                 jne 0x7386db
// 007386c2  885938               mov byte ptr [ecx + 0x38], bl
// 007386c5  885a38               mov byte ptr [edx + 0x38], bl
// 007386c8  8b10                 mov edx, dword ptr [eax]
// 007386ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 007386cd  c6413800             mov byte ptr [ecx + 0x38], 0
// 007386d1  8b10                 mov edx, dword ptr [eax]
// 007386d3  8b7204               mov esi, dword ptr [edx + 4]
// 007386d6  e9aa000000           jmp 0x738785
// 007386db  3b7108               cmp esi, dword ptr [ecx + 8]
// 007386de  750a                 jne 0x7386ea
// 007386e0  8bf1                 mov esi, ecx
// 007386e2  56                   push esi
// 007386e3  8bcf                 mov ecx, edi
// 007386e5  e8f650edff           call 0x60d7e0
// 007386ea  8b4604               mov eax, dword ptr [esi + 4]
// 007386ed  885838               mov byte ptr [eax + 0x38], bl
// 007386f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007386f3  8b5104               mov edx, dword ptr [ecx + 4]
// 007386f6  c6423800             mov byte ptr [edx + 0x38], 0
// 007386fa  8b4604               mov eax, dword ptr [esi + 4]
// 007386fd  8b4804               mov ecx, dword ptr [eax + 4]
// 00738700  51                   push ecx
// 00738701  8bcf                 mov ecx, edi
// 00738703  e8f8e51800           call 0x8c6d00
// 00738708  eb7b                 jmp 0x738785
// 0073870a  8b12                 mov edx, dword ptr [edx]
// 0073870c  807a3800             cmp byte ptr [edx + 0x38], 0
// 00738710  7516                 jne 0x738728
// 00738712  885938               mov byte ptr [ecx + 0x38], bl
// 00738715  885a38               mov byte ptr [edx + 0x38], bl
// 00738718  8b10                 mov edx, dword ptr [eax]
// 0073871a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0073871d  c6413800             mov byte ptr [ecx + 0x38], 0
// 00738721  8b10                 mov edx, dword ptr [eax]
// 00738723  8b7204               mov esi, dword ptr [edx + 4]
// 00738726  eb5d                 jmp 0x738785
// 00738728  3b31                 cmp esi, dword ptr [ecx]
// 0073872a  750a                 jne 0x738736
// 0073872c  8bf1                 mov esi, ecx
// 0073872e  56                   push esi
// 0073872f  8bcf                 mov ecx, edi
// 00738731  e8cae51800           call 0x8c6d00
// 00738736  8b4604               mov eax, dword ptr [esi + 4]
// 00738739  885838               mov byte ptr [eax + 0x38], bl
// 0073873c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0073873f  8b5104               mov edx, dword ptr [ecx + 4]
// 00738742  c6423800             mov byte ptr [edx + 0x38], 0
// 00738746  8b4604               mov eax, dword ptr [esi + 4]
// 00738749  8b4004               mov eax, dword ptr [eax + 4]
// 0073874c  8b4808               mov ecx, dword ptr [eax + 8]
// 0073874f  8b11                 mov edx, dword ptr [ecx]
// 00738751  895008               mov dword ptr [eax + 8], edx
// 00738754  8b11                 mov edx, dword ptr [ecx]
// 00738756  807a3900             cmp byte ptr [edx + 0x39], 0
// 0073875a  7503                 jne 0x73875f
// 0073875c  894204               mov dword ptr [edx + 4], eax
// 0073875f  8b5004               mov edx, dword ptr [eax + 4]
// 00738762  895104               mov dword ptr [ecx + 4], edx
// 00738765  8b5718               mov edx, dword ptr [edi + 0x18]
// 00738768  3b4204               cmp eax, dword ptr [edx + 4]
// 0073876b  7505                 jne 0x738772
// 0073876d  894a04               mov dword ptr [edx + 4], ecx
// 00738770  eb0e                 jmp 0x738780
// 00738772  8b5004               mov edx, dword ptr [eax + 4]
// 00738775  3b02                 cmp eax, dword ptr [edx]
// 00738777  7504                 jne 0x73877d
// 00738779  890a                 mov dword ptr [edx], ecx
// 0073877b  eb03                 jmp 0x738780
// 0073877d  894a08               mov dword ptr [edx + 8], ecx
// 00738780  8901                 mov dword ptr [ecx], eax
// 00738782  894804               mov dword ptr [eax + 4], ecx
// 00738785  8b4e04               mov ecx, dword ptr [esi + 4]
// 00738788  80793800             cmp byte ptr [ecx + 0x38], 0
// 0073878c  8d4604               lea eax, [esi + 4]
// 0073878f  0f841bffffff         je 0x7386b0
// 00738795  8b5718               mov edx, dword ptr [edi + 0x18]
// 00738798  8b4204               mov eax, dword ptr [edx + 4]
// 0073879b  885838               mov byte ptr [eax + 0x38], bl
// 0073879e  8b442464             mov eax, dword ptr [esp + 0x64]
// 007387a2  8b0f                 mov ecx, dword ptr [edi]
// 007387a4  5e                   pop esi
// 007387a5  896804               mov dword ptr [eax + 4], ebp
// 007387a8  5d                   pop ebp
// 007387a9  8908                 mov dword ptr [eax], ecx
// 007387ab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007387af  5b                   pop ebx
// 007387b0  5f                   pop edi
// 007387b1  64890d00000000       mov dword ptr fs:[0], ecx
// 007387b8  83c450               add esp, 0x50
// 007387bb  c21000               ret 0x10
// standard library map_int<pod40> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
