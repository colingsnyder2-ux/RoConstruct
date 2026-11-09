// from server: 100% by auto
// roc 2009-06 0063ec10  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ec10
//
// 0063ec10  64a100000000         mov eax, dword ptr fs:[0]
// 0063ec16  6aff                 push -1
// 0063ec18  68b2db8500           push 0x85dbb2
// 0063ec1d  50                   push eax
// 0063ec1e  64892500000000       mov dword ptr fs:[0], esp
// 0063ec25  83ec44               sub esp, 0x44
// 0063ec28  57                   push edi
// 0063ec29  8bf9                 mov edi, ecx
// 0063ec2b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 0063ec32  7259                 jb 0x63ec8d
// 0063ec34  68c0c98a00           push 0x8ac9c0
// 0063ec39  8d4c2408             lea ecx, [esp + 8]
// 0063ec3d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0063ec43  8d4c2420             lea ecx, [esp + 0x20]
// 0063ec47  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0063ec4f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0063ec55  8d442404             lea eax, [esp + 4]
// 0063ec59  50                   push eax
// 0063ec5a  8d4c2430             lea ecx, [esp + 0x30]
// 0063ec5e  c644245401           mov byte ptr [esp + 0x54], 1
// 0063ec63  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0063ec6b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0063ec71  6834929700           push 0x979234
// 0063ec76  8d4c2424             lea ecx, [esp + 0x24]
// 0063ec7a  51                   push ecx
// 0063ec7b  c644245800           mov byte ptr [esp + 0x58], 0
// 0063ec80  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0063ec88  e8bdad0d00           call 0x719a4a
// 0063ec8d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0063ec91  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ec94  53                   push ebx
// 0063ec95  55                   push ebp
// 0063ec96  56                   push esi
// 0063ec97  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0063ec9b  6a00                 push 0
// 0063ec9d  52                   push edx
// 0063ec9e  50                   push eax
// 0063ec9f  56                   push esi
// 0063eca0  50                   push eax
// 0063eca1  e82afeffff           call 0x63ead0
// 0063eca6  8be8                 mov ebp, eax
// 0063eca8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ecab  bb01000000           mov ebx, 1
// 0063ecb0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0063ecb3  3bf0                 cmp esi, eax
// 0063ecb5  7510                 jne 0x63ecc7
// 0063ecb7  896804               mov dword ptr [eax + 4], ebp
// 0063ecba  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ecbd  8928                 mov dword ptr [eax], ebp
// 0063ecbf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0063ecc2  896908               mov dword ptr [ecx + 8], ebp
// 0063ecc5  eb22                 jmp 0x63ece9
// 0063ecc7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0063eccc  740d                 je 0x63ecdb
// 0063ecce  892e                 mov dword ptr [esi], ebp
// 0063ecd0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ecd3  3b30                 cmp esi, dword ptr [eax]
// 0063ecd5  7512                 jne 0x63ece9
// 0063ecd7  8928                 mov dword ptr [eax], ebp
// 0063ecd9  eb0e                 jmp 0x63ece9
// 0063ecdb  896e08               mov dword ptr [esi + 8], ebp
// 0063ecde  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063ece1  3b7008               cmp esi, dword ptr [eax + 8]
// 0063ece4  7503                 jne 0x63ece9
// 0063ece6  896808               mov dword ptr [eax + 8], ebp
// 0063ece9  8b5504               mov edx, dword ptr [ebp + 4]
// 0063ecec  807a2000             cmp byte ptr [edx + 0x20], 0
// 0063ecf0  8d4504               lea eax, [ebp + 4]
// 0063ecf3  8bf5                 mov esi, ebp
// 0063ecf5  0f85ea000000         jne 0x63ede5
// 0063ecfb  eb03                 jmp 0x63ed00
// 0063ecfd  8d4900               lea ecx, [ecx]
// 0063ed00  8b08                 mov ecx, dword ptr [eax]
// 0063ed02  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ed05  3b0a                 cmp ecx, dword ptr [edx]
// 0063ed07  7551                 jne 0x63ed5a
// 0063ed09  8b5208               mov edx, dword ptr [edx + 8]
// 0063ed0c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0063ed10  7519                 jne 0x63ed2b
// 0063ed12  885920               mov byte ptr [ecx + 0x20], bl
// 0063ed15  885a20               mov byte ptr [edx + 0x20], bl
// 0063ed18  8b10                 mov edx, dword ptr [eax]
// 0063ed1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063ed1d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0063ed21  8b10                 mov edx, dword ptr [eax]
// 0063ed23  8b7204               mov esi, dword ptr [edx + 4]
// 0063ed26  e9aa000000           jmp 0x63edd5
// 0063ed2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0063ed2e  750a                 jne 0x63ed3a
// 0063ed30  8bf1                 mov esi, ecx
// 0063ed32  56                   push esi
// 0063ed33  8bcf                 mov ecx, edi
// 0063ed35  e8e68aedff           call 0x517820
// 0063ed3a  8b4604               mov eax, dword ptr [esi + 4]
// 0063ed3d  885820               mov byte ptr [eax + 0x20], bl
// 0063ed40  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063ed43  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ed46  c6422000             mov byte ptr [edx + 0x20], 0
// 0063ed4a  8b4604               mov eax, dword ptr [esi + 4]
// 0063ed4d  8b4804               mov ecx, dword ptr [eax + 4]
// 0063ed50  51                   push ecx
// 0063ed51  8bcf                 mov ecx, edi
// 0063ed53  e8f87cedff           call 0x516a50
// 0063ed58  eb7b                 jmp 0x63edd5
// 0063ed5a  8b12                 mov edx, dword ptr [edx]
// 0063ed5c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0063ed60  7516                 jne 0x63ed78
// 0063ed62  885920               mov byte ptr [ecx + 0x20], bl
// 0063ed65  885a20               mov byte ptr [edx + 0x20], bl
// 0063ed68  8b10                 mov edx, dword ptr [eax]
// 0063ed6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063ed6d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0063ed71  8b10                 mov edx, dword ptr [eax]
// 0063ed73  8b7204               mov esi, dword ptr [edx + 4]
// 0063ed76  eb5d                 jmp 0x63edd5
// 0063ed78  3b31                 cmp esi, dword ptr [ecx]
// 0063ed7a  750a                 jne 0x63ed86
// 0063ed7c  8bf1                 mov esi, ecx
// 0063ed7e  56                   push esi
// 0063ed7f  8bcf                 mov ecx, edi
// 0063ed81  e8ca7cedff           call 0x516a50
// 0063ed86  8b4604               mov eax, dword ptr [esi + 4]
// 0063ed89  885820               mov byte ptr [eax + 0x20], bl
// 0063ed8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063ed8f  8b5104               mov edx, dword ptr [ecx + 4]
// 0063ed92  c6422000             mov byte ptr [edx + 0x20], 0
// 0063ed96  8b4604               mov eax, dword ptr [esi + 4]
// 0063ed99  8b4004               mov eax, dword ptr [eax + 4]
// 0063ed9c  8b4808               mov ecx, dword ptr [eax + 8]
// 0063ed9f  8b11                 mov edx, dword ptr [ecx]
// 0063eda1  895008               mov dword ptr [eax + 8], edx
// 0063eda4  8b11                 mov edx, dword ptr [ecx]
// 0063eda6  807a2100             cmp byte ptr [edx + 0x21], 0
// 0063edaa  7503                 jne 0x63edaf
// 0063edac  894204               mov dword ptr [edx + 4], eax
// 0063edaf  8b5004               mov edx, dword ptr [eax + 4]
// 0063edb2  895104               mov dword ptr [ecx + 4], edx
// 0063edb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063edb8  3b4204               cmp eax, dword ptr [edx + 4]
// 0063edbb  7505                 jne 0x63edc2
// 0063edbd  894a04               mov dword ptr [edx + 4], ecx
// 0063edc0  eb0e                 jmp 0x63edd0
// 0063edc2  8b5004               mov edx, dword ptr [eax + 4]
// 0063edc5  3b02                 cmp eax, dword ptr [edx]
// 0063edc7  7504                 jne 0x63edcd
// 0063edc9  890a                 mov dword ptr [edx], ecx
// 0063edcb  eb03                 jmp 0x63edd0
// 0063edcd  894a08               mov dword ptr [edx + 8], ecx
// 0063edd0  8901                 mov dword ptr [ecx], eax
// 0063edd2  894804               mov dword ptr [eax + 4], ecx
// 0063edd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063edd8  80792000             cmp byte ptr [ecx + 0x20], 0
// 0063eddc  8d4604               lea eax, [esi + 4]
// 0063eddf  0f841bffffff         je 0x63ed00
// 0063ede5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063ede8  8b4204               mov eax, dword ptr [edx + 4]
// 0063edeb  885820               mov byte ptr [eax + 0x20], bl
// 0063edee  8b442464             mov eax, dword ptr [esp + 0x64]
// 0063edf2  8b0f                 mov ecx, dword ptr [edi]
// 0063edf4  5e                   pop esi
// 0063edf5  896804               mov dword ptr [eax + 4], ebp
// 0063edf8  5d                   pop ebp
// 0063edf9  8908                 mov dword ptr [eax], ecx
// 0063edfb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0063edff  5b                   pop ebx
// 0063ee00  5f                   pop edi
// 0063ee01  64890d00000000       mov dword ptr fs:[0], ecx
// 0063ee08  83c450               add esp, 0x50
// 0063ee0b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
