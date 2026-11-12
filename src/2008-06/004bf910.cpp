// from server: 100% by auto
// roc 2008-06 004bf910  unit: ProfiledRakPeer  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bf910
//
// 004bf910  55                   push ebp
// 004bf911  8b6c2408             mov ebp, dword ptr [esp + 8]
// 004bf915  56                   push esi
// 004bf916  57                   push edi
// 004bf917  8bf1                 mov esi, ecx
// 004bf919  85ed                 test ebp, ebp
// 004bf91b  0f84d2000000         je 0x4bf9f3
// 004bf921  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004bf925  85ff                 test edi, edi
// 004bf927  0f8cc6000000         jl 0x4bf9f3
// 004bf92d  83be2c02000000       cmp dword ptr [esi + 0x22c], 0
// 004bf934  0f84b9000000         je 0x4bf9f3
// 004bf93a  8a4604               mov al, byte ptr [esi + 4]
// 004bf93d  3c01                 cmp al, 1
// 004bf93f  0f84ae000000         je 0x4bf9f3
// 004bf945  53                   push ebx
// 004bf946  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 004bf94a  84db                 test bl, bl
// 004bf94c  7570                 jne 0x4bf9be
// 004bf94e  6870cb9300           push 0x93cb70
// 004bf953  8d4c242c             lea ecx, [esp + 0x2c]
// 004bf957  e8c49efeff           call 0x4a9820
// 004bf95c  84c0                 test al, al
// 004bf95e  7409                 je 0x4bf969
// 004bf960  5b                   pop ebx
// 004bf961  5f                   pop edi
// 004bf962  5e                   pop esi
// 004bf963  32c0                 xor al, al
// 004bf965  5d                   pop ebp
// 004bf966  c22000               ret 0x20
// 004bf969  83be2c07000000       cmp dword ptr [esi + 0x72c], 0
// 004bf970  744c                 je 0x4bf9be
// 004bf972  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004bf976  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004bf97a  8b16                 mov edx, dword ptr [esi]
// 004bf97c  8b5268               mov edx, dword ptr [edx + 0x68]
// 004bf97f  50                   push eax
// 004bf980  51                   push ecx
// 004bf981  8bce                 mov ecx, esi
// 004bf983  ffd2                 call edx
// 004bf985  84c0                 test al, al
// 004bf987  7535                 jne 0x4bf9be
// 004bf989  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf98d  8b8e2c070000         mov ecx, dword ptr [esi + 0x72c]
// 004bf993  8b01                 mov eax, dword ptr [ecx]
// 004bf995  8b00                 mov eax, dword ptr [eax]
// 004bf997  52                   push edx
// 004bf998  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf99c  52                   push edx
// 004bf99d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf9a1  52                   push edx
// 004bf9a2  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf9a6  52                   push edx
// 004bf9a7  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf9ab  52                   push edx
// 004bf9ac  8d14fd00000000       lea edx, [edi*8]
// 004bf9b3  52                   push edx
// 004bf9b4  55                   push ebp
// 004bf9b5  ffd0                 call eax
// 004bf9b7  5b                   pop ebx
// 004bf9b8  5f                   pop edi
// 004bf9b9  5e                   pop esi
// 004bf9ba  5d                   pop ebp
// 004bf9bb  c22000               ret 0x20
// 004bf9be  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004bf9c2  8b542428             mov edx, dword ptr [esp + 0x28]
// 004bf9c6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004bf9ca  6a00                 push 0
// 004bf9cc  53                   push ebx
// 004bf9cd  51                   push ecx
// 004bf9ce  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004bf9d2  52                   push edx
// 004bf9d3  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bf9d7  50                   push eax
// 004bf9d8  51                   push ecx
// 004bf9d9  52                   push edx
// 004bf9da  8d04fd00000000       lea eax, [edi*8]
// 004bf9e1  50                   push eax
// 004bf9e2  55                   push ebp
// 004bf9e3  8bce                 mov ecx, esi
// 004bf9e5  e846dcffff           call 0x4bd630
// 004bf9ea  5b                   pop ebx
// 004bf9eb  5f                   pop edi
// 004bf9ec  5e                   pop esi
// 004bf9ed  b001                 mov al, 1
// 004bf9ef  5d                   pop ebp
// 004bf9f0  c22000               ret 0x20
// 004bf9f3  5f                   pop edi
// 004bf9f4  5e                   pop esi
// 004bf9f5  32c0                 xor al, al
// 004bf9f7  5d                   pop ebp
// 004bf9f8  c22000               ret 0x20
// library openrbx-raknet/RakPeer.cpp (function ?Send@RakPeer@@UAE_NPBDHW4PacketPriority@@W4PacketReliability@@DUSystemAddress@@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
