// from server: 100% by auto
// roc 2007-08 004d2830  unit: G3D::VVector3::?$Table  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d2830
//
// 004d2830  64a100000000         mov eax, dword ptr fs:[0]
// 004d2836  6aff                 push -1
// 004d2838  68b2417500           push 0x7541b2
// 004d283d  50                   push eax
// 004d283e  64892500000000       mov dword ptr fs:[0], esp
// 004d2845  83ec44               sub esp, 0x44
// 004d2848  57                   push edi
// 004d2849  8bf9                 mov edi, ecx
// 004d284b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 004d2852  7259                 jb 0x4d28ad
// 004d2854  68904f7800           push 0x784f90
// 004d2859  8d4c2408             lea ecx, [esp + 8]
// 004d285d  ff1598e67700         call dword ptr [0x77e698]
// 004d2863  8d4c2420             lea ecx, [esp + 0x20]
// 004d2867  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004d286f  ff15f8e67700         call dword ptr [0x77e6f8]
// 004d2875  8d442404             lea eax, [esp + 4]
// 004d2879  50                   push eax
// 004d287a  8d4c2430             lea ecx, [esp + 0x30]
// 004d287e  c644245401           mov byte ptr [esp + 0x54], 1
// 004d2883  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 004d288b  ff159ce67700         call dword ptr [0x77e69c]
// 004d2891  6878f78300           push 0x83f778
// 004d2896  8d4c2424             lea ecx, [esp + 0x24]
// 004d289a  51                   push ecx
// 004d289b  c644245800           mov byte ptr [esp + 0x58], 0
// 004d28a0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 004d28a8  e8f1e21500           call 0x630b9e
// 004d28ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 004d28b1  8b4704               mov eax, dword ptr [edi + 4]
// 004d28b4  53                   push ebx
// 004d28b5  55                   push ebp
// 004d28b6  56                   push esi
// 004d28b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004d28bb  6a00                 push 0
// 004d28bd  52                   push edx
// 004d28be  50                   push eax
// 004d28bf  56                   push esi
// 004d28c0  50                   push eax
// 004d28c1  e8faf9ffff           call 0x4d22c0
// 004d28c6  8be8                 mov ebp, eax
// 004d28c8  8b4704               mov eax, dword ptr [edi + 4]
// 004d28cb  bb01000000           mov ebx, 1
// 004d28d0  015f08               add dword ptr [edi + 8], ebx
// 004d28d3  3bf0                 cmp esi, eax
// 004d28d5  7510                 jne 0x4d28e7
// 004d28d7  896804               mov dword ptr [eax + 4], ebp
// 004d28da  8b4704               mov eax, dword ptr [edi + 4]
// 004d28dd  8928                 mov dword ptr [eax], ebp
// 004d28df  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d28e2  896908               mov dword ptr [ecx + 8], ebp
// 004d28e5  eb22                 jmp 0x4d2909
// 004d28e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004d28ec  740d                 je 0x4d28fb
// 004d28ee  892e                 mov dword ptr [esi], ebp
// 004d28f0  8b4704               mov eax, dword ptr [edi + 4]
// 004d28f3  3b30                 cmp esi, dword ptr [eax]
// 004d28f5  7512                 jne 0x4d2909
// 004d28f7  8928                 mov dword ptr [eax], ebp
// 004d28f9  eb0e                 jmp 0x4d2909
// 004d28fb  896e08               mov dword ptr [esi + 8], ebp
// 004d28fe  8b4704               mov eax, dword ptr [edi + 4]
// 004d2901  3b7008               cmp esi, dword ptr [eax + 8]
// 004d2904  7503                 jne 0x4d2909
// 004d2906  896808               mov dword ptr [eax + 8], ebp
// 004d2909  8b5504               mov edx, dword ptr [ebp + 4]
// 004d290c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d2910  8d4504               lea eax, [ebp + 4]
// 004d2913  8bf5                 mov esi, ebp
// 004d2915  0f85ea000000         jne 0x4d2a05
// 004d291b  eb03                 jmp 0x4d2920
// 004d291d  8d4900               lea ecx, [ecx]
// 004d2920  8b08                 mov ecx, dword ptr [eax]
// 004d2922  8b5104               mov edx, dword ptr [ecx + 4]
// 004d2925  3b0a                 cmp ecx, dword ptr [edx]
// 004d2927  7551                 jne 0x4d297a
// 004d2929  8b5208               mov edx, dword ptr [edx + 8]
// 004d292c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d2930  7519                 jne 0x4d294b
// 004d2932  885920               mov byte ptr [ecx + 0x20], bl
// 004d2935  885a20               mov byte ptr [edx + 0x20], bl
// 004d2938  8b10                 mov edx, dword ptr [eax]
// 004d293a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d293d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004d2941  8b10                 mov edx, dword ptr [eax]
// 004d2943  8b7204               mov esi, dword ptr [edx + 4]
// 004d2946  e9aa000000           jmp 0x4d29f5
// 004d294b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004d294e  750a                 jne 0x4d295a
// 004d2950  8bf1                 mov esi, ecx
// 004d2952  56                   push esi
// 004d2953  8bcf                 mov ecx, edi
// 004d2955  e8b6adffff           call 0x4cd710
// 004d295a  8b4604               mov eax, dword ptr [esi + 4]
// 004d295d  885820               mov byte ptr [eax + 0x20], bl
// 004d2960  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d2963  8b5104               mov edx, dword ptr [ecx + 4]
// 004d2966  c6422000             mov byte ptr [edx + 0x20], 0
// 004d296a  8b4604               mov eax, dword ptr [esi + 4]
// 004d296d  8b4804               mov ecx, dword ptr [eax + 4]
// 004d2970  51                   push ecx
// 004d2971  8bcf                 mov ecx, edi
// 004d2973  e878d9ffff           call 0x4d02f0
// 004d2978  eb7b                 jmp 0x4d29f5
// 004d297a  8b12                 mov edx, dword ptr [edx]
// 004d297c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d2980  7516                 jne 0x4d2998
// 004d2982  885920               mov byte ptr [ecx + 0x20], bl
// 004d2985  885a20               mov byte ptr [edx + 0x20], bl
// 004d2988  8b10                 mov edx, dword ptr [eax]
// 004d298a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d298d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004d2991  8b10                 mov edx, dword ptr [eax]
// 004d2993  8b7204               mov esi, dword ptr [edx + 4]
// 004d2996  eb5d                 jmp 0x4d29f5
// 004d2998  3b31                 cmp esi, dword ptr [ecx]
// 004d299a  750a                 jne 0x4d29a6
// 004d299c  8bf1                 mov esi, ecx
// 004d299e  56                   push esi
// 004d299f  8bcf                 mov ecx, edi
// 004d29a1  e84ad9ffff           call 0x4d02f0
// 004d29a6  8b4604               mov eax, dword ptr [esi + 4]
// 004d29a9  885820               mov byte ptr [eax + 0x20], bl
// 004d29ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d29af  8b5104               mov edx, dword ptr [ecx + 4]
// 004d29b2  c6422000             mov byte ptr [edx + 0x20], 0
// 004d29b6  8b4604               mov eax, dword ptr [esi + 4]
// 004d29b9  8b4004               mov eax, dword ptr [eax + 4]
// 004d29bc  8b4808               mov ecx, dword ptr [eax + 8]
// 004d29bf  8b11                 mov edx, dword ptr [ecx]
// 004d29c1  895008               mov dword ptr [eax + 8], edx
// 004d29c4  8b11                 mov edx, dword ptr [ecx]
// 004d29c6  807a2100             cmp byte ptr [edx + 0x21], 0
// 004d29ca  7503                 jne 0x4d29cf
// 004d29cc  894204               mov dword ptr [edx + 4], eax
// 004d29cf  8b5004               mov edx, dword ptr [eax + 4]
// 004d29d2  895104               mov dword ptr [ecx + 4], edx
// 004d29d5  8b5704               mov edx, dword ptr [edi + 4]
// 004d29d8  3b4204               cmp eax, dword ptr [edx + 4]
// 004d29db  7505                 jne 0x4d29e2
// 004d29dd  894a04               mov dword ptr [edx + 4], ecx
// 004d29e0  eb0e                 jmp 0x4d29f0
// 004d29e2  8b5004               mov edx, dword ptr [eax + 4]
// 004d29e5  3b02                 cmp eax, dword ptr [edx]
// 004d29e7  7504                 jne 0x4d29ed
// 004d29e9  890a                 mov dword ptr [edx], ecx
// 004d29eb  eb03                 jmp 0x4d29f0
// 004d29ed  894a08               mov dword ptr [edx + 8], ecx
// 004d29f0  8901                 mov dword ptr [ecx], eax
// 004d29f2  894804               mov dword ptr [eax + 4], ecx
// 004d29f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d29f8  80792000             cmp byte ptr [ecx + 0x20], 0
// 004d29fc  8d4604               lea eax, [esi + 4]
// 004d29ff  0f841bffffff         je 0x4d2920
// 004d2a05  8b5704               mov edx, dword ptr [edi + 4]
// 004d2a08  8b4204               mov eax, dword ptr [edx + 4]
// 004d2a0b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d2a0f  885820               mov byte ptr [eax + 0x20], bl
// 004d2a12  8b442464             mov eax, dword ptr [esp + 0x64]
// 004d2a16  5e                   pop esi
// 004d2a17  896804               mov dword ptr [eax + 4], ebp
// 004d2a1a  5d                   pop ebp
// 004d2a1b  8938                 mov dword ptr [eax], edi
// 004d2a1d  5b                   pop ebx
// 004d2a1e  5f                   pop edi
// 004d2a1f  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2a26  83c450               add esp, 0x50
// 004d2a29  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
