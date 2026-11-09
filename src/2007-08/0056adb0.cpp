// from server: 100% by auto
// roc 2007-08 0056adb0  unit: ArchiveBinder  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056adb0
//
// 0056adb0  64a100000000         mov eax, dword ptr fs:[0]
// 0056adb6  6aff                 push -1
// 0056adb8  68b2417500           push 0x7541b2
// 0056adbd  50                   push eax
// 0056adbe  64892500000000       mov dword ptr fs:[0], esp
// 0056adc5  83ec44               sub esp, 0x44
// 0056adc8  57                   push edi
// 0056adc9  8bf9                 mov edi, ecx
// 0056adcb  817f08c6711c07       cmp dword ptr [edi + 8], 0x71c71c6
// 0056add2  7259                 jb 0x56ae2d
// 0056add4  68904f7800           push 0x784f90
// 0056add9  8d4c2408             lea ecx, [esp + 8]
// 0056addd  ff1598e67700         call dword ptr [0x77e698]
// 0056ade3  8d4c2420             lea ecx, [esp + 0x20]
// 0056ade7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0056adef  ff15f8e67700         call dword ptr [0x77e6f8]
// 0056adf5  8d442404             lea eax, [esp + 4]
// 0056adf9  50                   push eax
// 0056adfa  8d4c2430             lea ecx, [esp + 0x30]
// 0056adfe  c644245401           mov byte ptr [esp + 0x54], 1
// 0056ae03  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0056ae0b  ff159ce67700         call dword ptr [0x77e69c]
// 0056ae11  6878f78300           push 0x83f778
// 0056ae16  8d4c2424             lea ecx, [esp + 0x24]
// 0056ae1a  51                   push ecx
// 0056ae1b  c644245800           mov byte ptr [esp + 0x58], 0
// 0056ae20  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0056ae28  e8715d0c00           call 0x630b9e
// 0056ae2d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0056ae31  8b4704               mov eax, dword ptr [edi + 4]
// 0056ae34  53                   push ebx
// 0056ae35  55                   push ebp
// 0056ae36  56                   push esi
// 0056ae37  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0056ae3b  6a00                 push 0
// 0056ae3d  52                   push edx
// 0056ae3e  50                   push eax
// 0056ae3f  56                   push esi
// 0056ae40  50                   push eax
// 0056ae41  e8dafeffff           call 0x56ad20
// 0056ae46  8be8                 mov ebp, eax
// 0056ae48  8b4704               mov eax, dword ptr [edi + 4]
// 0056ae4b  bb01000000           mov ebx, 1
// 0056ae50  015f08               add dword ptr [edi + 8], ebx
// 0056ae53  3bf0                 cmp esi, eax
// 0056ae55  7510                 jne 0x56ae67
// 0056ae57  896804               mov dword ptr [eax + 4], ebp
// 0056ae5a  8b4704               mov eax, dword ptr [edi + 4]
// 0056ae5d  8928                 mov dword ptr [eax], ebp
// 0056ae5f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0056ae62  896908               mov dword ptr [ecx + 8], ebp
// 0056ae65  eb22                 jmp 0x56ae89
// 0056ae67  807c246800           cmp byte ptr [esp + 0x68], 0
// 0056ae6c  740d                 je 0x56ae7b
// 0056ae6e  892e                 mov dword ptr [esi], ebp
// 0056ae70  8b4704               mov eax, dword ptr [edi + 4]
// 0056ae73  3b30                 cmp esi, dword ptr [eax]
// 0056ae75  7512                 jne 0x56ae89
// 0056ae77  8928                 mov dword ptr [eax], ebp
// 0056ae79  eb0e                 jmp 0x56ae89
// 0056ae7b  896e08               mov dword ptr [esi + 8], ebp
// 0056ae7e  8b4704               mov eax, dword ptr [edi + 4]
// 0056ae81  3b7008               cmp esi, dword ptr [eax + 8]
// 0056ae84  7503                 jne 0x56ae89
// 0056ae86  896808               mov dword ptr [eax + 8], ebp
// 0056ae89  8b5504               mov edx, dword ptr [ebp + 4]
// 0056ae8c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0056ae90  8d4504               lea eax, [ebp + 4]
// 0056ae93  8bf5                 mov esi, ebp
// 0056ae95  0f85ea000000         jne 0x56af85
// 0056ae9b  eb03                 jmp 0x56aea0
// 0056ae9d  8d4900               lea ecx, [ecx]
// 0056aea0  8b08                 mov ecx, dword ptr [eax]
// 0056aea2  8b5104               mov edx, dword ptr [ecx + 4]
// 0056aea5  3b0a                 cmp ecx, dword ptr [edx]
// 0056aea7  7551                 jne 0x56aefa
// 0056aea9  8b5208               mov edx, dword ptr [edx + 8]
// 0056aeac  807a3000             cmp byte ptr [edx + 0x30], 0
// 0056aeb0  7519                 jne 0x56aecb
// 0056aeb2  885930               mov byte ptr [ecx + 0x30], bl
// 0056aeb5  885a30               mov byte ptr [edx + 0x30], bl
// 0056aeb8  8b10                 mov edx, dword ptr [eax]
// 0056aeba  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056aebd  c6413000             mov byte ptr [ecx + 0x30], 0
// 0056aec1  8b10                 mov edx, dword ptr [eax]
// 0056aec3  8b7204               mov esi, dword ptr [edx + 4]
// 0056aec6  e9aa000000           jmp 0x56af75
// 0056aecb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0056aece  750a                 jne 0x56aeda
// 0056aed0  8bf1                 mov esi, ecx
// 0056aed2  56                   push esi
// 0056aed3  8bcf                 mov ecx, edi
// 0056aed5  e896e7ffff           call 0x569670
// 0056aeda  8b4604               mov eax, dword ptr [esi + 4]
// 0056aedd  885830               mov byte ptr [eax + 0x30], bl
// 0056aee0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056aee3  8b5104               mov edx, dword ptr [ecx + 4]
// 0056aee6  c6423000             mov byte ptr [edx + 0x30], 0
// 0056aeea  8b4604               mov eax, dword ptr [esi + 4]
// 0056aeed  8b4804               mov ecx, dword ptr [eax + 4]
// 0056aef0  51                   push ecx
// 0056aef1  8bcf                 mov ecx, edi
// 0056aef3  e898e5ffff           call 0x569490
// 0056aef8  eb7b                 jmp 0x56af75
// 0056aefa  8b12                 mov edx, dword ptr [edx]
// 0056aefc  807a3000             cmp byte ptr [edx + 0x30], 0
// 0056af00  7516                 jne 0x56af18
// 0056af02  885930               mov byte ptr [ecx + 0x30], bl
// 0056af05  885a30               mov byte ptr [edx + 0x30], bl
// 0056af08  8b10                 mov edx, dword ptr [eax]
// 0056af0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056af0d  c6413000             mov byte ptr [ecx + 0x30], 0
// 0056af11  8b10                 mov edx, dword ptr [eax]
// 0056af13  8b7204               mov esi, dword ptr [edx + 4]
// 0056af16  eb5d                 jmp 0x56af75
// 0056af18  3b31                 cmp esi, dword ptr [ecx]
// 0056af1a  750a                 jne 0x56af26
// 0056af1c  8bf1                 mov esi, ecx
// 0056af1e  56                   push esi
// 0056af1f  8bcf                 mov ecx, edi
// 0056af21  e86ae5ffff           call 0x569490
// 0056af26  8b4604               mov eax, dword ptr [esi + 4]
// 0056af29  885830               mov byte ptr [eax + 0x30], bl
// 0056af2c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056af2f  8b5104               mov edx, dword ptr [ecx + 4]
// 0056af32  c6423000             mov byte ptr [edx + 0x30], 0
// 0056af36  8b4604               mov eax, dword ptr [esi + 4]
// 0056af39  8b4004               mov eax, dword ptr [eax + 4]
// 0056af3c  8b4808               mov ecx, dword ptr [eax + 8]
// 0056af3f  8b11                 mov edx, dword ptr [ecx]
// 0056af41  895008               mov dword ptr [eax + 8], edx
// 0056af44  8b11                 mov edx, dword ptr [ecx]
// 0056af46  807a3100             cmp byte ptr [edx + 0x31], 0
// 0056af4a  7503                 jne 0x56af4f
// 0056af4c  894204               mov dword ptr [edx + 4], eax
// 0056af4f  8b5004               mov edx, dword ptr [eax + 4]
// 0056af52  895104               mov dword ptr [ecx + 4], edx
// 0056af55  8b5704               mov edx, dword ptr [edi + 4]
// 0056af58  3b4204               cmp eax, dword ptr [edx + 4]
// 0056af5b  7505                 jne 0x56af62
// 0056af5d  894a04               mov dword ptr [edx + 4], ecx
// 0056af60  eb0e                 jmp 0x56af70
// 0056af62  8b5004               mov edx, dword ptr [eax + 4]
// 0056af65  3b02                 cmp eax, dword ptr [edx]
// 0056af67  7504                 jne 0x56af6d
// 0056af69  890a                 mov dword ptr [edx], ecx
// 0056af6b  eb03                 jmp 0x56af70
// 0056af6d  894a08               mov dword ptr [edx + 8], ecx
// 0056af70  8901                 mov dword ptr [ecx], eax
// 0056af72  894804               mov dword ptr [eax + 4], ecx
// 0056af75  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056af78  80793000             cmp byte ptr [ecx + 0x30], 0
// 0056af7c  8d4604               lea eax, [esi + 4]
// 0056af7f  0f841bffffff         je 0x56aea0
// 0056af85  8b5704               mov edx, dword ptr [edi + 4]
// 0056af88  8b4204               mov eax, dword ptr [edx + 4]
// 0056af8b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0056af8f  885830               mov byte ptr [eax + 0x30], bl
// 0056af92  8b442464             mov eax, dword ptr [esp + 0x64]
// 0056af96  5e                   pop esi
// 0056af97  896804               mov dword ptr [eax + 4], ebp
// 0056af9a  5d                   pop ebp
// 0056af9b  8938                 mov dword ptr [eax], edi
// 0056af9d  5b                   pop ebx
// 0056af9e  5f                   pop edi
// 0056af9f  64890d00000000       mov dword ptr fs:[0], ecx
// 0056afa6  83c450               add esp, 0x50
// 0056afa9  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
