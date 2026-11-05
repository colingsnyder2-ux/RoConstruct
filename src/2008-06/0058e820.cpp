// from server: 100% by auto
// roc 2008-06 0058e820  unit: TextXmlWriter  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058e820
//
// 0058e820  64a100000000         mov eax, dword ptr fs:[0]
// 0058e826  6aff                 push -1
// 0058e828  6842e87d00           push 0x7de842
// 0058e82d  50                   push eax
// 0058e82e  64892500000000       mov dword ptr fs:[0], esp
// 0058e835  83ec44               sub esp, 0x44
// 0058e838  57                   push edi
// 0058e839  8bf9                 mov edi, ecx
// 0058e83b  817f1c23499204       cmp dword ptr [edi + 0x1c], 0x4924923
// 0058e842  7259                 jb 0x58e89d
// 0058e844  688cb28000           push 0x80b28c
// 0058e849  8d4c2408             lea ecx, [esp + 8]
// 0058e84d  ff1558248000         call dword ptr [0x802458]
// 0058e853  8d4c2420             lea ecx, [esp + 0x20]
// 0058e857  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058e85f  ff1598288000         call dword ptr [0x802898]
// 0058e865  8d442404             lea eax, [esp + 4]
// 0058e869  50                   push eax
// 0058e86a  8d4c2430             lea ecx, [esp + 0x30]
// 0058e86e  c644245401           mov byte ptr [esp + 0x54], 1
// 0058e873  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0058e87b  ff155c248000         call dword ptr [0x80245c]
// 0058e881  68c00c8d00           push 0x8d0cc0
// 0058e886  8d4c2424             lea ecx, [esp + 0x24]
// 0058e88a  51                   push ecx
// 0058e88b  c644245800           mov byte ptr [esp + 0x58], 0
// 0058e890  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 0058e898  e8ef2c1100           call 0x6a158c
// 0058e89d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0058e8a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058e8a4  53                   push ebx
// 0058e8a5  55                   push ebp
// 0058e8a6  56                   push esi
// 0058e8a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0058e8ab  6a00                 push 0
// 0058e8ad  52                   push edx
// 0058e8ae  50                   push eax
// 0058e8af  56                   push esi
// 0058e8b0  50                   push eax
// 0058e8b1  e8aaefffff           call 0x58d860
// 0058e8b6  8be8                 mov ebp, eax
// 0058e8b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058e8bb  bb01000000           mov ebx, 1
// 0058e8c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0058e8c3  3bf0                 cmp esi, eax
// 0058e8c5  7510                 jne 0x58e8d7
// 0058e8c7  896804               mov dword ptr [eax + 4], ebp
// 0058e8ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058e8cd  8928                 mov dword ptr [eax], ebp
// 0058e8cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0058e8d2  896908               mov dword ptr [ecx + 8], ebp
// 0058e8d5  eb22                 jmp 0x58e8f9
// 0058e8d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0058e8dc  740d                 je 0x58e8eb
// 0058e8de  892e                 mov dword ptr [esi], ebp
// 0058e8e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058e8e3  3b30                 cmp esi, dword ptr [eax]
// 0058e8e5  7512                 jne 0x58e8f9
// 0058e8e7  8928                 mov dword ptr [eax], ebp
// 0058e8e9  eb0e                 jmp 0x58e8f9
// 0058e8eb  896e08               mov dword ptr [esi + 8], ebp
// 0058e8ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058e8f1  3b7008               cmp esi, dword ptr [eax + 8]
// 0058e8f4  7503                 jne 0x58e8f9
// 0058e8f6  896808               mov dword ptr [eax + 8], ebp
// 0058e8f9  8b5504               mov edx, dword ptr [ebp + 4]
// 0058e8fc  807a4400             cmp byte ptr [edx + 0x44], 0
// 0058e900  8d4504               lea eax, [ebp + 4]
// 0058e903  8bf5                 mov esi, ebp
// 0058e905  0f85ea000000         jne 0x58e9f5
// 0058e90b  eb03                 jmp 0x58e910
// 0058e90d  8d4900               lea ecx, [ecx]
// 0058e910  8b08                 mov ecx, dword ptr [eax]
// 0058e912  8b5104               mov edx, dword ptr [ecx + 4]
// 0058e915  3b0a                 cmp ecx, dword ptr [edx]
// 0058e917  7551                 jne 0x58e96a
// 0058e919  8b5208               mov edx, dword ptr [edx + 8]
// 0058e91c  807a4400             cmp byte ptr [edx + 0x44], 0
// 0058e920  7519                 jne 0x58e93b
// 0058e922  885944               mov byte ptr [ecx + 0x44], bl
// 0058e925  885a44               mov byte ptr [edx + 0x44], bl
// 0058e928  8b10                 mov edx, dword ptr [eax]
// 0058e92a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058e92d  c6414400             mov byte ptr [ecx + 0x44], 0
// 0058e931  8b10                 mov edx, dword ptr [eax]
// 0058e933  8b7204               mov esi, dword ptr [edx + 4]
// 0058e936  e9aa000000           jmp 0x58e9e5
// 0058e93b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0058e93e  750a                 jne 0x58e94a
// 0058e940  8bf1                 mov esi, ecx
// 0058e942  56                   push esi
// 0058e943  8bcf                 mov ecx, edi
// 0058e945  e8164ce8ff           call 0x413560
// 0058e94a  8b4604               mov eax, dword ptr [esi + 4]
// 0058e94d  885844               mov byte ptr [eax + 0x44], bl
// 0058e950  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058e953  8b5104               mov edx, dword ptr [ecx + 4]
// 0058e956  c6424400             mov byte ptr [edx + 0x44], 0
// 0058e95a  8b4604               mov eax, dword ptr [esi + 4]
// 0058e95d  8b4804               mov ecx, dword ptr [eax + 4]
// 0058e960  51                   push ecx
// 0058e961  8bcf                 mov ecx, edi
// 0058e963  e8884ce8ff           call 0x4135f0
// 0058e968  eb7b                 jmp 0x58e9e5
// 0058e96a  8b12                 mov edx, dword ptr [edx]
// 0058e96c  807a4400             cmp byte ptr [edx + 0x44], 0
// 0058e970  7516                 jne 0x58e988
// 0058e972  885944               mov byte ptr [ecx + 0x44], bl
// 0058e975  885a44               mov byte ptr [edx + 0x44], bl
// 0058e978  8b10                 mov edx, dword ptr [eax]
// 0058e97a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058e97d  c6414400             mov byte ptr [ecx + 0x44], 0
// 0058e981  8b10                 mov edx, dword ptr [eax]
// 0058e983  8b7204               mov esi, dword ptr [edx + 4]
// 0058e986  eb5d                 jmp 0x58e9e5
// 0058e988  3b31                 cmp esi, dword ptr [ecx]
// 0058e98a  750a                 jne 0x58e996
// 0058e98c  8bf1                 mov esi, ecx
// 0058e98e  56                   push esi
// 0058e98f  8bcf                 mov ecx, edi
// 0058e991  e85a4ce8ff           call 0x4135f0
// 0058e996  8b4604               mov eax, dword ptr [esi + 4]
// 0058e999  885844               mov byte ptr [eax + 0x44], bl
// 0058e99c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058e99f  8b5104               mov edx, dword ptr [ecx + 4]
// 0058e9a2  c6424400             mov byte ptr [edx + 0x44], 0
// 0058e9a6  8b4604               mov eax, dword ptr [esi + 4]
// 0058e9a9  8b4004               mov eax, dword ptr [eax + 4]
// 0058e9ac  8b4808               mov ecx, dword ptr [eax + 8]
// 0058e9af  8b11                 mov edx, dword ptr [ecx]
// 0058e9b1  895008               mov dword ptr [eax + 8], edx
// 0058e9b4  8b11                 mov edx, dword ptr [ecx]
// 0058e9b6  807a4500             cmp byte ptr [edx + 0x45], 0
// 0058e9ba  7503                 jne 0x58e9bf
// 0058e9bc  894204               mov dword ptr [edx + 4], eax
// 0058e9bf  8b5004               mov edx, dword ptr [eax + 4]
// 0058e9c2  895104               mov dword ptr [ecx + 4], edx
// 0058e9c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0058e9c8  3b4204               cmp eax, dword ptr [edx + 4]
// 0058e9cb  7505                 jne 0x58e9d2
// 0058e9cd  894a04               mov dword ptr [edx + 4], ecx
// 0058e9d0  eb0e                 jmp 0x58e9e0
// 0058e9d2  8b5004               mov edx, dword ptr [eax + 4]
// 0058e9d5  3b02                 cmp eax, dword ptr [edx]
// 0058e9d7  7504                 jne 0x58e9dd
// 0058e9d9  890a                 mov dword ptr [edx], ecx
// 0058e9db  eb03                 jmp 0x58e9e0
// 0058e9dd  894a08               mov dword ptr [edx + 8], ecx
// 0058e9e0  8901                 mov dword ptr [ecx], eax
// 0058e9e2  894804               mov dword ptr [eax + 4], ecx
// 0058e9e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058e9e8  80794400             cmp byte ptr [ecx + 0x44], 0
// 0058e9ec  8d4604               lea eax, [esi + 4]
// 0058e9ef  0f841bffffff         je 0x58e910
// 0058e9f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0058e9f8  8b4204               mov eax, dword ptr [edx + 4]
// 0058e9fb  885844               mov byte ptr [eax + 0x44], bl
// 0058e9fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 0058ea02  8b0f                 mov ecx, dword ptr [edi]
// 0058ea04  5e                   pop esi
// 0058ea05  896804               mov dword ptr [eax + 4], ebp
// 0058ea08  5d                   pop ebp
// 0058ea09  8908                 mov dword ptr [eax], ecx
// 0058ea0b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0058ea0f  5b                   pop ebx
// 0058ea10  5f                   pop edi
// 0058ea11  64890d00000000       mov dword ptr fs:[0], ecx
// 0058ea18  83c450               add esp, 0x50
// 0058ea1b  c21000               ret 0x10
// standard library map_str<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
