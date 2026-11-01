// from server: 100% by auto
// roc 2007-03 00608fe0  unit: seg_00600000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00608fe0
//
// 00608fe0  64a100000000         mov eax, dword ptr fs:[0]
// 00608fe6  6aff                 push -1
// 00608fe8  68926f7500           push 0x756f92
// 00608fed  50                   push eax
// 00608fee  64892500000000       mov dword ptr fs:[0], esp
// 00608ff5  83ec44               sub esp, 0x44
// 00608ff8  57                   push edi
// 00608ff9  8bf9                 mov edi, ecx
// 00608ffb  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 00609002  7259                 jb 0x60905d
// 00609004  68903f7800           push 0x783f90
// 00609009  8d4c2408             lea ecx, [esp + 8]
// 0060900d  ff1578e77700         call dword ptr [0x77e778]
// 00609013  8d4c2420             lea ecx, [esp + 0x20]
// 00609017  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0060901f  ff1560e97700         call dword ptr [0x77e960]
// 00609025  8d442404             lea eax, [esp + 4]
// 00609029  50                   push eax
// 0060902a  8d4c2430             lea ecx, [esp + 0x30]
// 0060902e  c644245401           mov byte ptr [esp + 0x54], 1
// 00609033  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 0060903b  ff157ce77700         call dword ptr [0x77e77c]
// 00609041  6870f78300           push 0x83f770
// 00609046  8d4c2424             lea ecx, [esp + 0x24]
// 0060904a  51                   push ecx
// 0060904b  c644245800           mov byte ptr [esp + 0x58], 0
// 00609050  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 00609058  e8d15f0100           call 0x61f02e
// 0060905d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00609061  8b4704               mov eax, dword ptr [edi + 4]
// 00609064  53                   push ebx
// 00609065  55                   push ebp
// 00609066  56                   push esi
// 00609067  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0060906b  6a00                 push 0
// 0060906d  52                   push edx
// 0060906e  50                   push eax
// 0060906f  56                   push esi
// 00609070  50                   push eax
// 00609071  e84afcffff           call 0x608cc0
// 00609076  8be8                 mov ebp, eax
// 00609078  8b4704               mov eax, dword ptr [edi + 4]
// 0060907b  bb01000000           mov ebx, 1
// 00609080  015f08               add dword ptr [edi + 8], ebx
// 00609083  3bf0                 cmp esi, eax
// 00609085  7510                 jne 0x609097
// 00609087  896804               mov dword ptr [eax + 4], ebp
// 0060908a  8b4704               mov eax, dword ptr [edi + 4]
// 0060908d  8928                 mov dword ptr [eax], ebp
// 0060908f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00609092  896908               mov dword ptr [ecx + 8], ebp
// 00609095  eb22                 jmp 0x6090b9
// 00609097  807c246800           cmp byte ptr [esp + 0x68], 0
// 0060909c  740d                 je 0x6090ab
// 0060909e  892e                 mov dword ptr [esi], ebp
// 006090a0  8b4704               mov eax, dword ptr [edi + 4]
// 006090a3  3b30                 cmp esi, dword ptr [eax]
// 006090a5  7512                 jne 0x6090b9
// 006090a7  8928                 mov dword ptr [eax], ebp
// 006090a9  eb0e                 jmp 0x6090b9
// 006090ab  896e08               mov dword ptr [esi + 8], ebp
// 006090ae  8b4704               mov eax, dword ptr [edi + 4]
// 006090b1  3b7008               cmp esi, dword ptr [eax + 8]
// 006090b4  7503                 jne 0x6090b9
// 006090b6  896808               mov dword ptr [eax + 8], ebp
// 006090b9  8b5504               mov edx, dword ptr [ebp + 4]
// 006090bc  807a2000             cmp byte ptr [edx + 0x20], 0
// 006090c0  8d4504               lea eax, [ebp + 4]
// 006090c3  8bf5                 mov esi, ebp
// 006090c5  0f85ea000000         jne 0x6091b5
// 006090cb  eb03                 jmp 0x6090d0
// 006090cd  8d4900               lea ecx, [ecx]
// 006090d0  8b08                 mov ecx, dword ptr [eax]
// 006090d2  8b5104               mov edx, dword ptr [ecx + 4]
// 006090d5  3b0a                 cmp ecx, dword ptr [edx]
// 006090d7  7551                 jne 0x60912a
// 006090d9  8b5208               mov edx, dword ptr [edx + 8]
// 006090dc  807a2000             cmp byte ptr [edx + 0x20], 0
// 006090e0  7519                 jne 0x6090fb
// 006090e2  885920               mov byte ptr [ecx + 0x20], bl
// 006090e5  885a20               mov byte ptr [edx + 0x20], bl
// 006090e8  8b10                 mov edx, dword ptr [eax]
// 006090ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 006090ed  c6412000             mov byte ptr [ecx + 0x20], 0
// 006090f1  8b10                 mov edx, dword ptr [eax]
// 006090f3  8b7204               mov esi, dword ptr [edx + 4]
// 006090f6  e9aa000000           jmp 0x6091a5
// 006090fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006090fe  750a                 jne 0x60910a
// 00609100  8bf1                 mov esi, ecx
// 00609102  56                   push esi
// 00609103  8bcf                 mov ecx, edi
// 00609105  e8d692ebff           call 0x4c23e0
// 0060910a  8b4604               mov eax, dword ptr [esi + 4]
// 0060910d  885820               mov byte ptr [eax + 0x20], bl
// 00609110  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609113  8b5104               mov edx, dword ptr [ecx + 4]
// 00609116  c6422000             mov byte ptr [edx + 0x20], 0
// 0060911a  8b4604               mov eax, dword ptr [esi + 4]
// 0060911d  8b4804               mov ecx, dword ptr [eax + 4]
// 00609120  51                   push ecx
// 00609121  8bcf                 mov ecx, edi
// 00609123  e85805e3ff           call 0x439680
// 00609128  eb7b                 jmp 0x6091a5
// 0060912a  8b12                 mov edx, dword ptr [edx]
// 0060912c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00609130  7516                 jne 0x609148
// 00609132  885920               mov byte ptr [ecx + 0x20], bl
// 00609135  885a20               mov byte ptr [edx + 0x20], bl
// 00609138  8b10                 mov edx, dword ptr [eax]
// 0060913a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060913d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00609141  8b10                 mov edx, dword ptr [eax]
// 00609143  8b7204               mov esi, dword ptr [edx + 4]
// 00609146  eb5d                 jmp 0x6091a5
// 00609148  3b31                 cmp esi, dword ptr [ecx]
// 0060914a  750a                 jne 0x609156
// 0060914c  8bf1                 mov esi, ecx
// 0060914e  56                   push esi
// 0060914f  8bcf                 mov ecx, edi
// 00609151  e82a05e3ff           call 0x439680
// 00609156  8b4604               mov eax, dword ptr [esi + 4]
// 00609159  885820               mov byte ptr [eax + 0x20], bl
// 0060915c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060915f  8b5104               mov edx, dword ptr [ecx + 4]
// 00609162  c6422000             mov byte ptr [edx + 0x20], 0
// 00609166  8b4604               mov eax, dword ptr [esi + 4]
// 00609169  8b4004               mov eax, dword ptr [eax + 4]
// 0060916c  8b4808               mov ecx, dword ptr [eax + 8]
// 0060916f  8b11                 mov edx, dword ptr [ecx]
// 00609171  895008               mov dword ptr [eax + 8], edx
// 00609174  8b11                 mov edx, dword ptr [ecx]
// 00609176  807a2100             cmp byte ptr [edx + 0x21], 0
// 0060917a  7503                 jne 0x60917f
// 0060917c  894204               mov dword ptr [edx + 4], eax
// 0060917f  8b5004               mov edx, dword ptr [eax + 4]
// 00609182  895104               mov dword ptr [ecx + 4], edx
// 00609185  8b5704               mov edx, dword ptr [edi + 4]
// 00609188  3b4204               cmp eax, dword ptr [edx + 4]
// 0060918b  7505                 jne 0x609192
// 0060918d  894a04               mov dword ptr [edx + 4], ecx
// 00609190  eb0e                 jmp 0x6091a0
// 00609192  8b5004               mov edx, dword ptr [eax + 4]
// 00609195  3b02                 cmp eax, dword ptr [edx]
// 00609197  7504                 jne 0x60919d
// 00609199  890a                 mov dword ptr [edx], ecx
// 0060919b  eb03                 jmp 0x6091a0
// 0060919d  894a08               mov dword ptr [edx + 8], ecx
// 006091a0  8901                 mov dword ptr [ecx], eax
// 006091a2  894804               mov dword ptr [eax + 4], ecx
// 006091a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006091a8  80792000             cmp byte ptr [ecx + 0x20], 0
// 006091ac  8d4604               lea eax, [esi + 4]
// 006091af  0f841bffffff         je 0x6090d0
// 006091b5  8b5704               mov edx, dword ptr [edi + 4]
// 006091b8  8b4204               mov eax, dword ptr [edx + 4]
// 006091bb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 006091bf  885820               mov byte ptr [eax + 0x20], bl
// 006091c2  8b442464             mov eax, dword ptr [esp + 0x64]
// 006091c6  5e                   pop esi
// 006091c7  896804               mov dword ptr [eax + 4], ebp
// 006091ca  5d                   pop ebp
// 006091cb  8938                 mov dword ptr [eax], edi
// 006091cd  5b                   pop ebx
// 006091ce  5f                   pop edi
// 006091cf  64890d00000000       mov dword ptr fs:[0], ecx
// 006091d6  83c450               add esp, 0x50
// 006091d9  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
