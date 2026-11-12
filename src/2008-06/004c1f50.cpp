// from server: 100% by auto
// roc 2008-06 004c1f50  unit: ProfiledRakPeer  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1f50
//
// 004c1f50  81eccc000000         sub esp, 0xcc
// 004c1f56  56                   push esi
// 004c1f57  8bf1                 mov esi, ecx
// 004c1f59  6870cb9300           push 0x93cb70
// 004c1f5e  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 004c1f65  89742408             mov dword ptr [esp + 8], esi
// 004c1f69  e8b278feff           call 0x4a9820
// 004c1f6e  84c0                 test al, al
// 004c1f70  7472                 je 0x4c1fe4
// 004c1f72  53                   push ebx
// 004c1f73  55                   push ebp
// 004c1f74  33c0                 xor eax, eax
// 004c1f76  32db                 xor bl, bl
// 004c1f78  33ed                 xor ebp, ebp
// 004c1f7a  663b4608             cmp ax, word ptr [esi + 8]
// 004c1f7e  7353                 jae 0x4c1fd3
// 004c1f80  57                   push edi
// 004c1f81  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 004c1f87  0fb7cd               movzx ecx, bp
// 004c1f8a  69c950080000         imul ecx, ecx, 0x850
// 004c1f90  803c1100             cmp byte ptr [ecx + edx], 0
// 004c1f94  8d0411               lea eax, [ecx + edx]
// 004c1f97  7432                 je 0x4c1fcb
// 004c1f99  8d4818               lea ecx, [eax + 0x18]
// 004c1f9c  e8dff30000           call 0x4d1380
// 004c1fa1  84db                 test bl, bl
// 004c1fa3  7516                 jne 0x4c1fbb
// 004c1fa5  b932000000           mov ecx, 0x32
// 004c1faa  8bf0                 mov esi, eax
// 004c1fac  bfb8199700           mov edi, 0x9719b8
// 004c1fb1  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c1fb3  8b742410             mov esi, dword ptr [esp + 0x10]
// 004c1fb7  b301                 mov bl, 1
// 004c1fb9  eb10                 jmp 0x4c1fcb
// 004c1fbb  50                   push eax
// 004c1fbc  8d442418             lea eax, [esp + 0x18]
// 004c1fc0  50                   push eax
// 004c1fc1  b9b8199700           mov ecx, 0x9719b8
// 004c1fc6  e8d593ffff           call 0x4bb3a0
// 004c1fcb  45                   inc ebp
// 004c1fcc  663b6e08             cmp bp, word ptr [esi + 8]
// 004c1fd0  72af                 jb 0x4c1f81
// 004c1fd2  5f                   pop edi
// 004c1fd3  5d                   pop ebp
// 004c1fd4  5b                   pop ebx
// 004c1fd5  b8b8199700           mov eax, 0x9719b8
// 004c1fda  5e                   pop esi
// 004c1fdb  81c4cc000000         add esp, 0xcc
// 004c1fe1  c20800               ret 8
// 004c1fe4  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 004c1feb  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 004c1ff2  6a00                 push 0
// 004c1ff4  6a00                 push 0
// 004c1ff6  51                   push ecx
// 004c1ff7  52                   push edx
// 004c1ff8  8bce                 mov ecx, esi
// 004c1ffa  e8e1ddffff           call 0x4bfde0
// 004c1fff  85c0                 test eax, eax
// 004c2001  7419                 je 0x4c201c
// 004c2003  8a4e04               mov cl, byte ptr [esi + 4]
// 004c2006  84c9                 test cl, cl
// 004c2008  7512                 jne 0x4c201c
// 004c200a  8d4818               lea ecx, [eax + 0x18]
// 004c200d  e86ef30000           call 0x4d1380
// 004c2012  5e                   pop esi
// 004c2013  81c4cc000000         add esp, 0xcc
// 004c2019  c20800               ret 8
// 004c201c  33c0                 xor eax, eax
// 004c201e  5e                   pop esi
// 004c201f  81c4cc000000         add esp, 0xcc
// 004c2025  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetStatistics@RakPeer@@UAEQAURakNetStatistics@@USystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
