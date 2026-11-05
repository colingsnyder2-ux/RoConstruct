// from server: 100% by auto
// roc 2007-08 0056b0b0  unit: ArchiveBinder  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056b0b0
//
// 0056b0b0  83ec0c               sub esp, 0xc
// 0056b0b3  56                   push esi
// 0056b0b4  8bf1                 mov esi, ecx
// 0056b0b6  837e0800             cmp dword ptr [esi + 8], 0
// 0056b0ba  57                   push edi
// 0056b0bb  7521                 jne 0x56b0de
// 0056b0bd  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056b0c1  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056b0c4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056b0c8  50                   push eax
// 0056b0c9  51                   push ecx
// 0056b0ca  6a01                 push 1
// 0056b0cc  57                   push edi
// 0056b0cd  8bce                 mov ecx, esi
// 0056b0cf  e8dcfcffff           call 0x56adb0
// 0056b0d4  8bc7                 mov eax, edi
// 0056b0d6  5f                   pop edi
// 0056b0d7  5e                   pop esi
// 0056b0d8  83c40c               add esp, 0xc
// 0056b0db  c21000               ret 0x10
// 0056b0de  8b5604               mov edx, dword ptr [esi + 4]
// 0056b0e1  8b3a                 mov edi, dword ptr [edx]
// 0056b0e3  55                   push ebp
// 0056b0e4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056b0e8  85ed                 test ebp, ebp
// 0056b0ea  7404                 je 0x56b0f0
// 0056b0ec  3bee                 cmp ebp, esi
// 0056b0ee  7406                 je 0x56b0f6
// 0056b0f0  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056b0f6  53                   push ebx
// 0056b0f7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056b0fb  3bdf                 cmp ebx, edi
// 0056b0fd  7536                 jne 0x56b135
// 0056b0ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056b103  8d430c               lea eax, [ebx + 0xc]
// 0056b106  50                   push eax
// 0056b107  57                   push edi
// 0056b108  ff1520e67700         call dword ptr [0x77e620]
// 0056b10e  83c408               add esp, 8
// 0056b111  84c0                 test al, al
// 0056b113  0f8476010000         je 0x56b28f
// 0056b119  57                   push edi
// 0056b11a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056b11e  53                   push ebx
// 0056b11f  6a01                 push 1
// 0056b121  57                   push edi
// 0056b122  8bce                 mov ecx, esi
// 0056b124  e887fcffff           call 0x56adb0
// 0056b129  5b                   pop ebx
// 0056b12a  5d                   pop ebp
// 0056b12b  8bc7                 mov eax, edi
// 0056b12d  5f                   pop edi
// 0056b12e  5e                   pop esi
// 0056b12f  83c40c               add esp, 0xc
// 0056b132  c21000               ret 0x10
// 0056b135  85ed                 test ebp, ebp
// 0056b137  8b7e04               mov edi, dword ptr [esi + 4]
// 0056b13a  7404                 je 0x56b140
// 0056b13c  3bee                 cmp ebp, esi
// 0056b13e  7406                 je 0x56b146
// 0056b140  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056b146  3bdf                 cmp ebx, edi
// 0056b148  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056b14c  753e                 jne 0x56b18c
// 0056b14e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056b151  8b4108               mov eax, dword ptr [ecx + 8]
// 0056b154  83c00c               add eax, 0xc
// 0056b157  57                   push edi
// 0056b158  50                   push eax
// 0056b159  ff1520e67700         call dword ptr [0x77e620]
// 0056b15f  83c408               add esp, 8
// 0056b162  84c0                 test al, al
// 0056b164  0f8425010000         je 0x56b28f
// 0056b16a  8b5604               mov edx, dword ptr [esi + 4]
// 0056b16d  8b4208               mov eax, dword ptr [edx + 8]
// 0056b170  57                   push edi
// 0056b171  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056b175  50                   push eax
// 0056b176  6a00                 push 0
// 0056b178  57                   push edi
// 0056b179  8bce                 mov ecx, esi
// 0056b17b  e830fcffff           call 0x56adb0
// 0056b180  5b                   pop ebx
// 0056b181  5d                   pop ebp
// 0056b182  8bc7                 mov eax, edi
// 0056b184  5f                   pop edi
// 0056b185  5e                   pop esi
// 0056b186  83c40c               add esp, 0xc
// 0056b189  c21000               ret 0x10
// 0056b18c  8d430c               lea eax, [ebx + 0xc]
// 0056b18f  50                   push eax
// 0056b190  57                   push edi
// 0056b191  ff1520e67700         call dword ptr [0x77e620]
// 0056b197  83c408               add esp, 8
// 0056b19a  84c0                 test al, al
// 0056b19c  7463                 je 0x56b201
// 0056b19e  8d4c2424             lea ecx, [esp + 0x24]
// 0056b1a2  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056b1a6  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056b1aa  e8e1f9ffff           call 0x56ab90
// 0056b1af  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056b1b3  83c10c               add ecx, 0xc
// 0056b1b6  57                   push edi
// 0056b1b7  51                   push ecx
// 0056b1b8  8bce                 mov ecx, esi
// 0056b1ba  e8419cedff           call 0x444e00
// 0056b1bf  84c0                 test al, al
// 0056b1c1  743e                 je 0x56b201
// 0056b1c3  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056b1c7  8b5008               mov edx, dword ptr [eax + 8]
// 0056b1ca  807a3100             cmp byte ptr [edx + 0x31], 0
// 0056b1ce  57                   push edi
// 0056b1cf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056b1d3  8bce                 mov ecx, esi
// 0056b1d5  7415                 je 0x56b1ec
// 0056b1d7  50                   push eax
// 0056b1d8  6a00                 push 0
// 0056b1da  57                   push edi
// 0056b1db  e8d0fbffff           call 0x56adb0
// 0056b1e0  5b                   pop ebx
// 0056b1e1  5d                   pop ebp
// 0056b1e2  8bc7                 mov eax, edi
// 0056b1e4  5f                   pop edi
// 0056b1e5  5e                   pop esi
// 0056b1e6  83c40c               add esp, 0xc
// 0056b1e9  c21000               ret 0x10
// 0056b1ec  53                   push ebx
// 0056b1ed  6a01                 push 1
// 0056b1ef  57                   push edi
// 0056b1f0  e8bbfbffff           call 0x56adb0
// 0056b1f5  5b                   pop ebx
// 0056b1f6  5d                   pop ebp
// 0056b1f7  8bc7                 mov eax, edi
// 0056b1f9  5f                   pop edi
// 0056b1fa  5e                   pop esi
// 0056b1fb  83c40c               add esp, 0xc
// 0056b1fe  c21000               ret 0x10
// 0056b201  8d430c               lea eax, [ebx + 0xc]
// 0056b204  57                   push edi
// 0056b205  50                   push eax
// 0056b206  ff1520e67700         call dword ptr [0x77e620]
// 0056b20c  83c408               add esp, 8
// 0056b20f  84c0                 test al, al
// 0056b211  747c                 je 0x56b28f
// 0056b213  8b4604               mov eax, dword ptr [esi + 4]
// 0056b216  8d4c2424             lea ecx, [esp + 0x24]
// 0056b21a  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056b21e  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056b222  89442414             mov dword ptr [esp + 0x14], eax
// 0056b226  89742410             mov dword ptr [esp + 0x10], esi
// 0056b22a  e801e3ffff           call 0x569530
// 0056b22f  8d4c2410             lea ecx, [esp + 0x10]
// 0056b233  51                   push ecx
// 0056b234  8d4c2428             lea ecx, [esp + 0x28]
// 0056b238  e873b8efff           call 0x466ab0
// 0056b23d  84c0                 test al, al
// 0056b23f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056b243  7510                 jne 0x56b255
// 0056b245  8d550c               lea edx, [ebp + 0xc]
// 0056b248  52                   push edx
// 0056b249  57                   push edi
// 0056b24a  8bce                 mov ecx, esi
// 0056b24c  e8af9bedff           call 0x444e00
// 0056b251  84c0                 test al, al
// 0056b253  743a                 je 0x56b28f
// 0056b255  8b4308               mov eax, dword ptr [ebx + 8]
// 0056b258  80783100             cmp byte ptr [eax + 0x31], 0
// 0056b25c  57                   push edi
// 0056b25d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056b261  8bce                 mov ecx, esi
// 0056b263  7415                 je 0x56b27a
// 0056b265  53                   push ebx
// 0056b266  6a00                 push 0
// 0056b268  57                   push edi
// 0056b269  e842fbffff           call 0x56adb0
// 0056b26e  5b                   pop ebx
// 0056b26f  5d                   pop ebp
// 0056b270  8bc7                 mov eax, edi
// 0056b272  5f                   pop edi
// 0056b273  5e                   pop esi
// 0056b274  83c40c               add esp, 0xc
// 0056b277  c21000               ret 0x10
// 0056b27a  55                   push ebp
// 0056b27b  6a01                 push 1
// 0056b27d  57                   push edi
// 0056b27e  e82dfbffff           call 0x56adb0
// 0056b283  5b                   pop ebx
// 0056b284  5d                   pop ebp
// 0056b285  8bc7                 mov eax, edi
// 0056b287  5f                   pop edi
// 0056b288  5e                   pop esi
// 0056b289  83c40c               add esp, 0xc
// 0056b28c  c21000               ret 0x10
// 0056b28f  57                   push edi
// 0056b290  8d4c2414             lea ecx, [esp + 0x14]
// 0056b294  51                   push ecx
// 0056b295  8bce                 mov ecx, esi
// 0056b297  e814fdffff           call 0x56afb0
// 0056b29c  8b10                 mov edx, dword ptr [eax]
// 0056b29e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0056b2a2  5b                   pop ebx
// 0056b2a3  5d                   pop ebp
// 0056b2a4  8911                 mov dword ptr [ecx], edx
// 0056b2a6  8b4004               mov eax, dword ptr [eax + 4]
// 0056b2a9  5f                   pop edi
// 0056b2aa  894104               mov dword ptr [ecx + 4], eax
// 0056b2ad  8bc1                 mov eax, ecx
// 0056b2af  5e                   pop esi
// 0056b2b0  83c40c               add esp, 0xc
// 0056b2b3  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
