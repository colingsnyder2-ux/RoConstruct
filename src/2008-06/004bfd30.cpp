// from server: 100% by auto
// roc 2008-06 004bfd30  unit: ProfiledRakPeer  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfd30
//
// 004bfd30  56                   push esi
// 004bfd31  8bf1                 mov esi, ecx
// 004bfd33  6870cb9300           push 0x93cb70
// 004bfd38  8d4c240c             lea ecx, [esp + 0xc]
// 004bfd3c  e8df9afeff           call 0x4a9820
// 004bfd41  84c0                 test al, al
// 004bfd43  7407                 je 0x4bfd4c
// 004bfd45  83c8ff               or eax, 0xffffffff
// 004bfd48  5e                   pop esi
// 004bfd49  c20c00               ret 0xc
// 004bfd4c  807c241000           cmp byte ptr [esp + 0x10], 0
// 004bfd51  7430                 je 0x4bfd83
// 004bfd53  6850b54b00           push 0x4bb550
// 004bfd58  8d442414             lea eax, [esp + 0x14]
// 004bfd5c  50                   push eax
// 004bfd5d  8d4c2410             lea ecx, [esp + 0x10]
// 004bfd61  81c630020000         add esi, 0x230
// 004bfd67  51                   push ecx
// 004bfd68  8bce                 mov ecx, esi
// 004bfd6a  e881dbffff           call 0x4bd8f0
// 004bfd6f  807c241000           cmp byte ptr [esp + 0x10], 0
// 004bfd74  74cf                 je 0x4bfd45
// 004bfd76  8d1440               lea edx, [eax + eax*2]
// 004bfd79  8b06                 mov eax, dword ptr [esi]
// 004bfd7b  8b449008             mov eax, dword ptr [eax + edx*4 + 8]
// 004bfd7f  5e                   pop esi
// 004bfd80  c20c00               ret 0xc
// 004bfd83  53                   push ebx
// 004bfd84  33c9                 xor ecx, ecx
// 004bfd86  33db                 xor ebx, ebx
// 004bfd88  57                   push edi
// 004bfd89  663b4e08             cmp cx, word ptr [esi + 8]
// 004bfd8d  7331                 jae 0x4bfdc0
// 004bfd8f  33ff                 xor edi, edi
// 004bfd91  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 004bfd97  803c3a00             cmp byte ptr [edx + edi], 0
// 004bfd9b  8d043a               lea eax, [edx + edi]
// 004bfd9e  7411                 je 0x4bfdb1
// 004bfda0  8d4c2410             lea ecx, [esp + 0x10]
// 004bfda4  51                   push ecx
// 004bfda5  8d4804               lea ecx, [eax + 4]
// 004bfda8  e8739afeff           call 0x4a9820
// 004bfdad  84c0                 test al, al
// 004bfdaf  7518                 jne 0x4bfdc9
// 004bfdb1  0fb75608             movzx edx, word ptr [esi + 8]
// 004bfdb5  43                   inc ebx
// 004bfdb6  81c750080000         add edi, 0x850
// 004bfdbc  3bda                 cmp ebx, edx
// 004bfdbe  72d1                 jb 0x4bfd91
// 004bfdc0  5f                   pop edi
// 004bfdc1  5b                   pop ebx
// 004bfdc2  83c8ff               or eax, 0xffffffff
// 004bfdc5  5e                   pop esi
// 004bfdc6  c20c00               ret 0xc
// 004bfdc9  5f                   pop edi
// 004bfdca  8bc3                 mov eax, ebx
// 004bfdcc  5b                   pop ebx
// 004bfdcd  5e                   pop esi
// 004bfdce  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?GetIndexFromSystemAddress@RakPeer@@IAEHUSystemAddress@@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
