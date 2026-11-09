// from server: 100% by auto
// roc 2009-06 004766f0  unit: Ogre::RbxMeshLoader  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004766f0
//
// 004766f0  64a100000000         mov eax, dword ptr fs:[0]
// 004766f6  6aff                 push -1
// 004766f8  68b2db8500           push 0x85dbb2
// 004766fd  50                   push eax
// 004766fe  64892500000000       mov dword ptr fs:[0], esp
// 00476705  83ec44               sub esp, 0x44
// 00476708  57                   push edi
// 00476709  8bf9                 mov edi, ecx
// 0047670b  817f1c23499204       cmp dword ptr [edi + 0x1c], 0x4924923
// 00476712  7259                 jb 0x47676d
// 00476714  68c0c98a00           push 0x8ac9c0
// 00476719  8d4c2408             lea ecx, [esp + 8]
// 0047671d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00476723  8d4c2420             lea ecx, [esp + 0x20]
// 00476727  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0047672f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00476735  8d442404             lea eax, [esp + 4]
// 00476739  50                   push eax
// 0047673a  8d4c2430             lea ecx, [esp + 0x30]
// 0047673e  c644245401           mov byte ptr [esp + 0x54], 1
// 00476743  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0047674b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00476751  6834929700           push 0x979234
// 00476756  8d4c2424             lea ecx, [esp + 0x24]
// 0047675a  51                   push ecx
// 0047675b  c644245800           mov byte ptr [esp + 0x58], 0
// 00476760  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 00476768  e8dd322a00           call 0x719a4a
// 0047676d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00476771  8b4718               mov eax, dword ptr [edi + 0x18]
// 00476774  53                   push ebx
// 00476775  55                   push ebp
// 00476776  56                   push esi
// 00476777  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0047677b  6a00                 push 0
// 0047677d  52                   push edx
// 0047677e  50                   push eax
// 0047677f  56                   push esi
// 00476780  50                   push eax
// 00476781  e81afeffff           call 0x4765a0
// 00476786  8be8                 mov ebp, eax
// 00476788  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047678b  bb01000000           mov ebx, 1
// 00476790  015f1c               add dword ptr [edi + 0x1c], ebx
// 00476793  3bf0                 cmp esi, eax
// 00476795  7510                 jne 0x4767a7
// 00476797  896804               mov dword ptr [eax + 4], ebp
// 0047679a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047679d  8928                 mov dword ptr [eax], ebp
// 0047679f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004767a2  896908               mov dword ptr [ecx + 8], ebp
// 004767a5  eb22                 jmp 0x4767c9
// 004767a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004767ac  740d                 je 0x4767bb
// 004767ae  892e                 mov dword ptr [esi], ebp
// 004767b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004767b3  3b30                 cmp esi, dword ptr [eax]
// 004767b5  7512                 jne 0x4767c9
// 004767b7  8928                 mov dword ptr [eax], ebp
// 004767b9  eb0e                 jmp 0x4767c9
// 004767bb  896e08               mov dword ptr [esi + 8], ebp
// 004767be  8b4718               mov eax, dword ptr [edi + 0x18]
// 004767c1  3b7008               cmp esi, dword ptr [eax + 8]
// 004767c4  7503                 jne 0x4767c9
// 004767c6  896808               mov dword ptr [eax + 8], ebp
// 004767c9  8b5504               mov edx, dword ptr [ebp + 4]
// 004767cc  807a4400             cmp byte ptr [edx + 0x44], 0
// 004767d0  8d4504               lea eax, [ebp + 4]
// 004767d3  8bf5                 mov esi, ebp
// 004767d5  0f85ea000000         jne 0x4768c5
// 004767db  eb03                 jmp 0x4767e0
// 004767dd  8d4900               lea ecx, [ecx]
// 004767e0  8b08                 mov ecx, dword ptr [eax]
// 004767e2  8b5104               mov edx, dword ptr [ecx + 4]
// 004767e5  3b0a                 cmp ecx, dword ptr [edx]
// 004767e7  7551                 jne 0x47683a
// 004767e9  8b5208               mov edx, dword ptr [edx + 8]
// 004767ec  807a4400             cmp byte ptr [edx + 0x44], 0
// 004767f0  7519                 jne 0x47680b
// 004767f2  885944               mov byte ptr [ecx + 0x44], bl
// 004767f5  885a44               mov byte ptr [edx + 0x44], bl
// 004767f8  8b10                 mov edx, dword ptr [eax]
// 004767fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004767fd  c6414400             mov byte ptr [ecx + 0x44], 0
// 00476801  8b10                 mov edx, dword ptr [eax]
// 00476803  8b7204               mov esi, dword ptr [edx + 4]
// 00476806  e9aa000000           jmp 0x4768b5
// 0047680b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0047680e  750a                 jne 0x47681a
// 00476810  8bf1                 mov esi, ecx
// 00476812  56                   push esi
// 00476813  8bcf                 mov ecx, edi
// 00476815  e8f6d2f9ff           call 0x413b10
// 0047681a  8b4604               mov eax, dword ptr [esi + 4]
// 0047681d  885844               mov byte ptr [eax + 0x44], bl
// 00476820  8b4e04               mov ecx, dword ptr [esi + 4]
// 00476823  8b5104               mov edx, dword ptr [ecx + 4]
// 00476826  c6424400             mov byte ptr [edx + 0x44], 0
// 0047682a  8b4604               mov eax, dword ptr [esi + 4]
// 0047682d  8b4804               mov ecx, dword ptr [eax + 4]
// 00476830  51                   push ecx
// 00476831  8bcf                 mov ecx, edi
// 00476833  e868d3f9ff           call 0x413ba0
// 00476838  eb7b                 jmp 0x4768b5
// 0047683a  8b12                 mov edx, dword ptr [edx]
// 0047683c  807a4400             cmp byte ptr [edx + 0x44], 0
// 00476840  7516                 jne 0x476858
// 00476842  885944               mov byte ptr [ecx + 0x44], bl
// 00476845  885a44               mov byte ptr [edx + 0x44], bl
// 00476848  8b10                 mov edx, dword ptr [eax]
// 0047684a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047684d  c6414400             mov byte ptr [ecx + 0x44], 0
// 00476851  8b10                 mov edx, dword ptr [eax]
// 00476853  8b7204               mov esi, dword ptr [edx + 4]
// 00476856  eb5d                 jmp 0x4768b5
// 00476858  3b31                 cmp esi, dword ptr [ecx]
// 0047685a  750a                 jne 0x476866
// 0047685c  8bf1                 mov esi, ecx
// 0047685e  56                   push esi
// 0047685f  8bcf                 mov ecx, edi
// 00476861  e83ad3f9ff           call 0x413ba0
// 00476866  8b4604               mov eax, dword ptr [esi + 4]
// 00476869  885844               mov byte ptr [eax + 0x44], bl
// 0047686c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047686f  8b5104               mov edx, dword ptr [ecx + 4]
// 00476872  c6424400             mov byte ptr [edx + 0x44], 0
// 00476876  8b4604               mov eax, dword ptr [esi + 4]
// 00476879  8b4004               mov eax, dword ptr [eax + 4]
// 0047687c  8b4808               mov ecx, dword ptr [eax + 8]
// 0047687f  8b11                 mov edx, dword ptr [ecx]
// 00476881  895008               mov dword ptr [eax + 8], edx
// 00476884  8b11                 mov edx, dword ptr [ecx]
// 00476886  807a4500             cmp byte ptr [edx + 0x45], 0
// 0047688a  7503                 jne 0x47688f
// 0047688c  894204               mov dword ptr [edx + 4], eax
// 0047688f  8b5004               mov edx, dword ptr [eax + 4]
// 00476892  895104               mov dword ptr [ecx + 4], edx
// 00476895  8b5718               mov edx, dword ptr [edi + 0x18]
// 00476898  3b4204               cmp eax, dword ptr [edx + 4]
// 0047689b  7505                 jne 0x4768a2
// 0047689d  894a04               mov dword ptr [edx + 4], ecx
// 004768a0  eb0e                 jmp 0x4768b0
// 004768a2  8b5004               mov edx, dword ptr [eax + 4]
// 004768a5  3b02                 cmp eax, dword ptr [edx]
// 004768a7  7504                 jne 0x4768ad
// 004768a9  890a                 mov dword ptr [edx], ecx
// 004768ab  eb03                 jmp 0x4768b0
// 004768ad  894a08               mov dword ptr [edx + 8], ecx
// 004768b0  8901                 mov dword ptr [ecx], eax
// 004768b2  894804               mov dword ptr [eax + 4], ecx
// 004768b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004768b8  80794400             cmp byte ptr [ecx + 0x44], 0
// 004768bc  8d4604               lea eax, [esi + 4]
// 004768bf  0f841bffffff         je 0x4767e0
// 004768c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004768c8  8b4204               mov eax, dword ptr [edx + 4]
// 004768cb  885844               mov byte ptr [eax + 0x44], bl
// 004768ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 004768d2  8b0f                 mov ecx, dword ptr [edi]
// 004768d4  5e                   pop esi
// 004768d5  896804               mov dword ptr [eax + 4], ebp
// 004768d8  5d                   pop ebp
// 004768d9  8908                 mov dword ptr [eax], ecx
// 004768db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004768df  5b                   pop ebx
// 004768e0  5f                   pop edi
// 004768e1  64890d00000000       mov dword ptr fs:[0], ecx
// 004768e8  83c450               add esp, 0x50
// 004768eb  c21000               ret 0x10
// standard library map_str<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
