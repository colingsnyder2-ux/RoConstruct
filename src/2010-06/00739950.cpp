// from server: 100% by auto
// roc 2010-06 00739950  unit: seg_00730000  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00739950
//
// 00739950  64a100000000         mov eax, dword ptr fs:[0]
// 00739956  6aff                 push -1
// 00739958  68e22f9a00           push 0x9a2fe2
// 0073995d  50                   push eax
// 0073995e  64892500000000       mov dword ptr fs:[0], esp
// 00739965  83ec44               sub esp, 0x44
// 00739968  57                   push edi
// 00739969  8bf9                 mov edi, ecx
// 0073996b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00739972  7259                 jb 0x7399cd
// 00739974  68a800a000           push 0xa000a8
// 00739979  8d4c2408             lea ecx, [esp + 8]
// 0073997d  ff1510a49e00         call dword ptr [0x9ea410]
// 00739983  8d4c2420             lea ecx, [esp + 0x20]
// 00739987  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0073998f  ff1518a99e00         call dword ptr [0x9ea918]
// 00739995  8d442404             lea eax, [esp + 4]
// 00739999  50                   push eax
// 0073999a  8d4c2430             lea ecx, [esp + 0x30]
// 0073999e  c644245401           mov byte ptr [esp + 0x54], 1
// 007399a3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 007399ab  ff150ca49e00         call dword ptr [0x9ea40c]
// 007399b1  68601bb000           push 0xb01b60
// 007399b6  8d4c2424             lea ecx, [esp + 0x24]
// 007399ba  51                   push ecx
// 007399bb  c644245800           mov byte ptr [esp + 0x58], 0
// 007399c0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 007399c8  e8e5ef0600           call 0x7a89b2
// 007399cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 007399d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 007399d4  53                   push ebx
// 007399d5  55                   push ebp
// 007399d6  56                   push esi
// 007399d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007399db  6a00                 push 0
// 007399dd  52                   push edx
// 007399de  50                   push eax
// 007399df  56                   push esi
// 007399e0  50                   push eax
// 007399e1  e8cafeffff           call 0x7398b0
// 007399e6  8be8                 mov ebp, eax
// 007399e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 007399eb  bb01000000           mov ebx, 1
// 007399f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 007399f3  3bf0                 cmp esi, eax
// 007399f5  7510                 jne 0x739a07
// 007399f7  896804               mov dword ptr [eax + 4], ebp
// 007399fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 007399fd  8928                 mov dword ptr [eax], ebp
// 007399ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00739a02  896908               mov dword ptr [ecx + 8], ebp
// 00739a05  eb22                 jmp 0x739a29
// 00739a07  807c246800           cmp byte ptr [esp + 0x68], 0
// 00739a0c  740d                 je 0x739a1b
// 00739a0e  892e                 mov dword ptr [esi], ebp
// 00739a10  8b4718               mov eax, dword ptr [edi + 0x18]
// 00739a13  3b30                 cmp esi, dword ptr [eax]
// 00739a15  7512                 jne 0x739a29
// 00739a17  8928                 mov dword ptr [eax], ebp
// 00739a19  eb0e                 jmp 0x739a29
// 00739a1b  896e08               mov dword ptr [esi + 8], ebp
// 00739a1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00739a21  3b7008               cmp esi, dword ptr [eax + 8]
// 00739a24  7503                 jne 0x739a29
// 00739a26  896808               mov dword ptr [eax + 8], ebp
// 00739a29  8b5504               mov edx, dword ptr [ebp + 4]
// 00739a2c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00739a30  8d4504               lea eax, [ebp + 4]
// 00739a33  8bf5                 mov esi, ebp
// 00739a35  0f85ea000000         jne 0x739b25
// 00739a3b  eb03                 jmp 0x739a40
// 00739a3d  8d4900               lea ecx, [ecx]
// 00739a40  8b08                 mov ecx, dword ptr [eax]
// 00739a42  8b5104               mov edx, dword ptr [ecx + 4]
// 00739a45  3b0a                 cmp ecx, dword ptr [edx]
// 00739a47  7551                 jne 0x739a9a
// 00739a49  8b5208               mov edx, dword ptr [edx + 8]
// 00739a4c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00739a50  7519                 jne 0x739a6b
// 00739a52  88592c               mov byte ptr [ecx + 0x2c], bl
// 00739a55  885a2c               mov byte ptr [edx + 0x2c], bl
// 00739a58  8b10                 mov edx, dword ptr [eax]
// 00739a5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00739a5d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00739a61  8b10                 mov edx, dword ptr [eax]
// 00739a63  8b7204               mov esi, dword ptr [edx + 4]
// 00739a66  e9aa000000           jmp 0x739b15
// 00739a6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00739a6e  750a                 jne 0x739a7a
// 00739a70  8bf1                 mov esi, ecx
// 00739a72  56                   push esi
// 00739a73  8bcf                 mov ecx, edi
// 00739a75  e856fdffff           call 0x7397d0
// 00739a7a  8b4604               mov eax, dword ptr [esi + 4]
// 00739a7d  88582c               mov byte ptr [eax + 0x2c], bl
// 00739a80  8b4e04               mov ecx, dword ptr [esi + 4]
// 00739a83  8b5104               mov edx, dword ptr [ecx + 4]
// 00739a86  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00739a8a  8b4604               mov eax, dword ptr [esi + 4]
// 00739a8d  8b4804               mov ecx, dword ptr [eax + 4]
// 00739a90  51                   push ecx
// 00739a91  8bcf                 mov ecx, edi
// 00739a93  e828702200           call 0x960ac0
// 00739a98  eb7b                 jmp 0x739b15
// 00739a9a  8b12                 mov edx, dword ptr [edx]
// 00739a9c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00739aa0  7516                 jne 0x739ab8
// 00739aa2  88592c               mov byte ptr [ecx + 0x2c], bl
// 00739aa5  885a2c               mov byte ptr [edx + 0x2c], bl
// 00739aa8  8b10                 mov edx, dword ptr [eax]
// 00739aaa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00739aad  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00739ab1  8b10                 mov edx, dword ptr [eax]
// 00739ab3  8b7204               mov esi, dword ptr [edx + 4]
// 00739ab6  eb5d                 jmp 0x739b15
// 00739ab8  3b31                 cmp esi, dword ptr [ecx]
// 00739aba  750a                 jne 0x739ac6
// 00739abc  8bf1                 mov esi, ecx
// 00739abe  56                   push esi
// 00739abf  8bcf                 mov ecx, edi
// 00739ac1  e8fa6f2200           call 0x960ac0
// 00739ac6  8b4604               mov eax, dword ptr [esi + 4]
// 00739ac9  88582c               mov byte ptr [eax + 0x2c], bl
// 00739acc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00739acf  8b5104               mov edx, dword ptr [ecx + 4]
// 00739ad2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00739ad6  8b4604               mov eax, dword ptr [esi + 4]
// 00739ad9  8b4004               mov eax, dword ptr [eax + 4]
// 00739adc  8b4808               mov ecx, dword ptr [eax + 8]
// 00739adf  8b11                 mov edx, dword ptr [ecx]
// 00739ae1  895008               mov dword ptr [eax + 8], edx
// 00739ae4  8b11                 mov edx, dword ptr [ecx]
// 00739ae6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00739aea  7503                 jne 0x739aef
// 00739aec  894204               mov dword ptr [edx + 4], eax
// 00739aef  8b5004               mov edx, dword ptr [eax + 4]
// 00739af2  895104               mov dword ptr [ecx + 4], edx
// 00739af5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00739af8  3b4204               cmp eax, dword ptr [edx + 4]
// 00739afb  7505                 jne 0x739b02
// 00739afd  894a04               mov dword ptr [edx + 4], ecx
// 00739b00  eb0e                 jmp 0x739b10
// 00739b02  8b5004               mov edx, dword ptr [eax + 4]
// 00739b05  3b02                 cmp eax, dword ptr [edx]
// 00739b07  7504                 jne 0x739b0d
// 00739b09  890a                 mov dword ptr [edx], ecx
// 00739b0b  eb03                 jmp 0x739b10
// 00739b0d  894a08               mov dword ptr [edx + 8], ecx
// 00739b10  8901                 mov dword ptr [ecx], eax
// 00739b12  894804               mov dword ptr [eax + 4], ecx
// 00739b15  8b4e04               mov ecx, dword ptr [esi + 4]
// 00739b18  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 00739b1c  8d4604               lea eax, [esi + 4]
// 00739b1f  0f841bffffff         je 0x739a40
// 00739b25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00739b28  8b4204               mov eax, dword ptr [edx + 4]
// 00739b2b  88582c               mov byte ptr [eax + 0x2c], bl
// 00739b2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00739b32  8b0f                 mov ecx, dword ptr [edi]
// 00739b34  5e                   pop esi
// 00739b35  896804               mov dword ptr [eax + 4], ebp
// 00739b38  5d                   pop ebp
// 00739b39  8908                 mov dword ptr [eax], ecx
// 00739b3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00739b3f  5b                   pop ebx
// 00739b40  5f                   pop edi
// 00739b41  64890d00000000       mov dword ptr fs:[0], ecx
// 00739b48  83c450               add esp, 0x50
// 00739b4b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
