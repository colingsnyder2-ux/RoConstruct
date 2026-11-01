// from server: 100% by auto
// roc 2009-12 0051e930  unit: RBX::Network::Players  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0051e930
//
// 0051e930  64a100000000         mov eax, dword ptr fs:[0]
// 0051e936  6aff                 push -1
// 0051e938  6812699500           push 0x956912
// 0051e93d  50                   push eax
// 0051e93e  64892500000000       mov dword ptr fs:[0], esp
// 0051e945  83ec44               sub esp, 0x44
// 0051e948  57                   push edi
// 0051e949  8bf9                 mov edi, ecx
// 0051e94b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 0051e952  7259                 jb 0x51e9ad
// 0051e954  6800f59900           push 0x99f500
// 0051e959  8d4c2408             lea ecx, [esp + 8]
// 0051e95d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0051e963  8d4c2420             lea ecx, [esp + 0x20]
// 0051e967  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0051e96f  ff1554b79800         call dword ptr [0x98b754]
// 0051e975  8d442404             lea eax, [esp + 4]
// 0051e979  50                   push eax
// 0051e97a  8d4c2430             lea ecx, [esp + 0x30]
// 0051e97e  c644245401           mov byte ptr [esp + 0x54], 1
// 0051e983  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0051e98b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0051e991  68e4efa800           push 0xa8efe4
// 0051e996  8d4c2424             lea ecx, [esp + 0x24]
// 0051e99a  51                   push ecx
// 0051e99b  c644245800           mov byte ptr [esp + 0x58], 0
// 0051e9a0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0051e9a8  e8cb5e2d00           call 0x7f4878
// 0051e9ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0051e9b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051e9b4  53                   push ebx
// 0051e9b5  55                   push ebp
// 0051e9b6  56                   push esi
// 0051e9b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0051e9bb  6a00                 push 0
// 0051e9bd  52                   push edx
// 0051e9be  50                   push eax
// 0051e9bf  56                   push esi
// 0051e9c0  50                   push eax
// 0051e9c1  e89aefffff           call 0x51d960
// 0051e9c6  8be8                 mov ebp, eax
// 0051e9c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051e9cb  bb01000000           mov ebx, 1
// 0051e9d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0051e9d3  3bf0                 cmp esi, eax
// 0051e9d5  7510                 jne 0x51e9e7
// 0051e9d7  896804               mov dword ptr [eax + 4], ebp
// 0051e9da  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051e9dd  8928                 mov dword ptr [eax], ebp
// 0051e9df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0051e9e2  896908               mov dword ptr [ecx + 8], ebp
// 0051e9e5  eb22                 jmp 0x51ea09
// 0051e9e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0051e9ec  740d                 je 0x51e9fb
// 0051e9ee  892e                 mov dword ptr [esi], ebp
// 0051e9f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051e9f3  3b30                 cmp esi, dword ptr [eax]
// 0051e9f5  7512                 jne 0x51ea09
// 0051e9f7  8928                 mov dword ptr [eax], ebp
// 0051e9f9  eb0e                 jmp 0x51ea09
// 0051e9fb  896e08               mov dword ptr [esi + 8], ebp
// 0051e9fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0051ea01  3b7008               cmp esi, dword ptr [eax + 8]
// 0051ea04  7503                 jne 0x51ea09
// 0051ea06  896808               mov dword ptr [eax + 8], ebp
// 0051ea09  8b5504               mov edx, dword ptr [ebp + 4]
// 0051ea0c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0051ea10  8d4504               lea eax, [ebp + 4]
// 0051ea13  8bf5                 mov esi, ebp
// 0051ea15  0f85ea000000         jne 0x51eb05
// 0051ea1b  eb03                 jmp 0x51ea20
// 0051ea1d  8d4900               lea ecx, [ecx]
// 0051ea20  8b08                 mov ecx, dword ptr [eax]
// 0051ea22  8b5104               mov edx, dword ptr [ecx + 4]
// 0051ea25  3b0a                 cmp ecx, dword ptr [edx]
// 0051ea27  7551                 jne 0x51ea7a
// 0051ea29  8b5208               mov edx, dword ptr [edx + 8]
// 0051ea2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0051ea30  7519                 jne 0x51ea4b
// 0051ea32  885930               mov byte ptr [ecx + 0x30], bl
// 0051ea35  885a30               mov byte ptr [edx + 0x30], bl
// 0051ea38  8b10                 mov edx, dword ptr [eax]
// 0051ea3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0051ea3d  c6413000             mov byte ptr [ecx + 0x30], 0
// 0051ea41  8b10                 mov edx, dword ptr [eax]
// 0051ea43  8b7204               mov esi, dword ptr [edx + 4]
// 0051ea46  e9aa000000           jmp 0x51eaf5
// 0051ea4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0051ea4e  750a                 jne 0x51ea5a
// 0051ea50  8bf1                 mov esi, ecx
// 0051ea52  56                   push esi
// 0051ea53  8bcf                 mov ecx, edi
// 0051ea55  e8b64dffff           call 0x513810
// 0051ea5a  8b4604               mov eax, dword ptr [esi + 4]
// 0051ea5d  885830               mov byte ptr [eax + 0x30], bl
// 0051ea60  8b4e04               mov ecx, dword ptr [esi + 4]
// 0051ea63  8b5104               mov edx, dword ptr [ecx + 4]
// 0051ea66  c6423000             mov byte ptr [edx + 0x30], 0
// 0051ea6a  8b4604               mov eax, dword ptr [esi + 4]
// 0051ea6d  8b4804               mov ecx, dword ptr [eax + 4]
// 0051ea70  51                   push ecx
// 0051ea71  8bcf                 mov ecx, edi
// 0051ea73  e828421e00           call 0x702ca0
// 0051ea78  eb7b                 jmp 0x51eaf5
// 0051ea7a  8b12                 mov edx, dword ptr [edx]
// 0051ea7c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0051ea80  7516                 jne 0x51ea98
// 0051ea82  885930               mov byte ptr [ecx + 0x30], bl
// 0051ea85  885a30               mov byte ptr [edx + 0x30], bl
// 0051ea88  8b10                 mov edx, dword ptr [eax]
// 0051ea8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0051ea8d  c6413000             mov byte ptr [ecx + 0x30], 0
// 0051ea91  8b10                 mov edx, dword ptr [eax]
// 0051ea93  8b7204               mov esi, dword ptr [edx + 4]
// 0051ea96  eb5d                 jmp 0x51eaf5
// 0051ea98  3b31                 cmp esi, dword ptr [ecx]
// 0051ea9a  750a                 jne 0x51eaa6
// 0051ea9c  8bf1                 mov esi, ecx
// 0051ea9e  56                   push esi
// 0051ea9f  8bcf                 mov ecx, edi
// 0051eaa1  e8fa411e00           call 0x702ca0
// 0051eaa6  8b4604               mov eax, dword ptr [esi + 4]
// 0051eaa9  885830               mov byte ptr [eax + 0x30], bl
// 0051eaac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0051eaaf  8b5104               mov edx, dword ptr [ecx + 4]
// 0051eab2  c6423000             mov byte ptr [edx + 0x30], 0
// 0051eab6  8b4604               mov eax, dword ptr [esi + 4]
// 0051eab9  8b4004               mov eax, dword ptr [eax + 4]
// 0051eabc  8b4808               mov ecx, dword ptr [eax + 8]
// 0051eabf  8b11                 mov edx, dword ptr [ecx]
// 0051eac1  895008               mov dword ptr [eax + 8], edx
// 0051eac4  8b11                 mov edx, dword ptr [ecx]
// 0051eac6  807a3100             cmp byte ptr [edx + 0x31], 0
// 0051eaca  7503                 jne 0x51eacf
// 0051eacc  894204               mov dword ptr [edx + 4], eax
// 0051eacf  8b5004               mov edx, dword ptr [eax + 4]
// 0051ead2  895104               mov dword ptr [ecx + 4], edx
// 0051ead5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0051ead8  3b4204               cmp eax, dword ptr [edx + 4]
// 0051eadb  7505                 jne 0x51eae2
// 0051eadd  894a04               mov dword ptr [edx + 4], ecx
// 0051eae0  eb0e                 jmp 0x51eaf0
// 0051eae2  8b5004               mov edx, dword ptr [eax + 4]
// 0051eae5  3b02                 cmp eax, dword ptr [edx]
// 0051eae7  7504                 jne 0x51eaed
// 0051eae9  890a                 mov dword ptr [edx], ecx
// 0051eaeb  eb03                 jmp 0x51eaf0
// 0051eaed  894a08               mov dword ptr [edx + 8], ecx
// 0051eaf0  8901                 mov dword ptr [ecx], eax
// 0051eaf2  894804               mov dword ptr [eax + 4], ecx
// 0051eaf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0051eaf8  80793000             cmp byte ptr [ecx + 0x30], 0
// 0051eafc  8d4604               lea eax, [esi + 4]
// 0051eaff  0f841bffffff         je 0x51ea20
// 0051eb05  8b5718               mov edx, dword ptr [edi + 0x18]
// 0051eb08  8b4204               mov eax, dword ptr [edx + 4]
// 0051eb0b  885830               mov byte ptr [eax + 0x30], bl
// 0051eb0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0051eb12  8b0f                 mov ecx, dword ptr [edi]
// 0051eb14  5e                   pop esi
// 0051eb15  896804               mov dword ptr [eax + 4], ebp
// 0051eb18  5d                   pop ebp
// 0051eb19  8908                 mov dword ptr [eax], ecx
// 0051eb1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0051eb1f  5b                   pop ebx
// 0051eb20  5f                   pop edi
// 0051eb21  64890d00000000       mov dword ptr fs:[0], ecx
// 0051eb28  83c450               add esp, 0x50
// 0051eb2b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
