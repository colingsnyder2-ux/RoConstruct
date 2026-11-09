// from server: 100% by auto
// roc 2010-06 004cdb00  unit: RBX::Network::Players  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cdb00
//
// 004cdb00  83ec14               sub esp, 0x14
// 004cdb03  56                   push esi
// 004cdb04  8bf1                 mov esi, ecx
// 004cdb06  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 004cdb0a  57                   push edi
// 004cdb0b  7521                 jne 0x4cdb2e
// 004cdb0d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004cdb11  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004cdb14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cdb18  50                   push eax
// 004cdb19  51                   push ecx
// 004cdb1a  6a01                 push 1
// 004cdb1c  57                   push edi
// 004cdb1d  8bce                 mov ecx, esi
// 004cdb1f  e8fcebffff           call 0x4cc720
// 004cdb24  8bc7                 mov eax, edi
// 004cdb26  5f                   pop edi
// 004cdb27  5e                   pop esi
// 004cdb28  83c414               add esp, 0x14
// 004cdb2b  c21000               ret 0x10
// 004cdb2e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004cdb32  8b5618               mov edx, dword ptr [esi + 0x18]
// 004cdb35  8b3a                 mov edi, dword ptr [edx]
// 004cdb37  8b06                 mov eax, dword ptr [esi]
// 004cdb39  53                   push ebx
// 004cdb3a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 004cdb40  85c9                 test ecx, ecx
// 004cdb42  7404                 je 0x4cdb48
// 004cdb44  3bc8                 cmp ecx, eax
// 004cdb46  7406                 je 0x4cdb4e
// 004cdb48  ffd3                 call ebx
// 004cdb4a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004cdb4e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004cdb52  3bc7                 cmp eax, edi
// 004cdb54  752a                 jne 0x4cdb80
// 004cdb56  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004cdb5a  8b0f                 mov ecx, dword ptr [edi]
// 004cdb5c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004cdb5f  0f8d4b010000         jge 0x4cdcb0
// 004cdb65  57                   push edi
// 004cdb66  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004cdb6a  50                   push eax
// 004cdb6b  6a01                 push 1
// 004cdb6d  57                   push edi
// 004cdb6e  8bce                 mov ecx, esi
// 004cdb70  e8abebffff           call 0x4cc720
// 004cdb75  5b                   pop ebx
// 004cdb76  8bc7                 mov eax, edi
// 004cdb78  5f                   pop edi
// 004cdb79  5e                   pop esi
// 004cdb7a  83c414               add esp, 0x14
// 004cdb7d  c21000               ret 0x10
// 004cdb80  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004cdb83  8b16                 mov edx, dword ptr [esi]
// 004cdb85  85c9                 test ecx, ecx
// 004cdb87  7404                 je 0x4cdb8d
// 004cdb89  3bca                 cmp ecx, edx
// 004cdb8b  740a                 je 0x4cdb97
// 004cdb8d  ffd3                 call ebx
// 004cdb8f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004cdb93  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004cdb97  3bc7                 cmp eax, edi
// 004cdb99  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004cdb9d  752c                 jne 0x4cdbcb
// 004cdb9f  8b5618               mov edx, dword ptr [esi + 0x18]
// 004cdba2  8b4208               mov eax, dword ptr [edx + 8]
// 004cdba5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004cdba8  3b0f                 cmp ecx, dword ptr [edi]
// 004cdbaa  0f8d00010000         jge 0x4cdcb0
// 004cdbb0  57                   push edi
// 004cdbb1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004cdbb5  50                   push eax
// 004cdbb6  6a00                 push 0
// 004cdbb8  57                   push edi
// 004cdbb9  8bce                 mov ecx, esi
// 004cdbbb  e860ebffff           call 0x4cc720
// 004cdbc0  5b                   pop ebx
// 004cdbc1  8bc7                 mov eax, edi
// 004cdbc3  5f                   pop edi
// 004cdbc4  5e                   pop esi
// 004cdbc5  83c414               add esp, 0x14
// 004cdbc8  c21000               ret 0x10
// 004cdbcb  8b17                 mov edx, dword ptr [edi]
// 004cdbcd  39500c               cmp dword ptr [eax + 0xc], edx
// 004cdbd0  7e63                 jle 0x4cdc35
// 004cdbd2  894c240c             mov dword ptr [esp + 0xc], ecx
// 004cdbd6  8d4c240c             lea ecx, [esp + 0xc]
// 004cdbda  89442410             mov dword ptr [esp + 0x10], eax
// 004cdbde  e8fd58faff           call 0x4734e0
// 004cdbe3  8b17                 mov edx, dword ptr [edi]
// 004cdbe5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004cdbe9  39500c               cmp dword ptr [eax + 0xc], edx
// 004cdbec  7d3c                 jge 0x4cdc2a
// 004cdbee  8b5008               mov edx, dword ptr [eax + 8]
// 004cdbf1  807a3100             cmp byte ptr [edx + 0x31], 0
// 004cdbf5  57                   push edi
// 004cdbf6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004cdbfa  8bce                 mov ecx, esi
// 004cdbfc  7414                 je 0x4cdc12
// 004cdbfe  50                   push eax
// 004cdbff  6a00                 push 0
// 004cdc01  57                   push edi
// 004cdc02  e819ebffff           call 0x4cc720
// 004cdc07  5b                   pop ebx
// 004cdc08  8bc7                 mov eax, edi
// 004cdc0a  5f                   pop edi
// 004cdc0b  5e                   pop esi
// 004cdc0c  83c414               add esp, 0x14
// 004cdc0f  c21000               ret 0x10
// 004cdc12  8b442430             mov eax, dword ptr [esp + 0x30]
// 004cdc16  50                   push eax
// 004cdc17  6a01                 push 1
// 004cdc19  57                   push edi
// 004cdc1a  e801ebffff           call 0x4cc720
// 004cdc1f  5b                   pop ebx
// 004cdc20  8bc7                 mov eax, edi
// 004cdc22  5f                   pop edi
// 004cdc23  5e                   pop esi
// 004cdc24  83c414               add esp, 0x14
// 004cdc27  c21000               ret 0x10
// 004cdc2a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004cdc2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004cdc32  39500c               cmp dword ptr [eax + 0xc], edx
// 004cdc35  7d79                 jge 0x4cdcb0
// 004cdc37  8b16                 mov edx, dword ptr [esi]
// 004cdc39  894c240c             mov dword ptr [esp + 0xc], ecx
// 004cdc3d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004cdc40  894c2418             mov dword ptr [esp + 0x18], ecx
// 004cdc44  8d4c240c             lea ecx, [esp + 0xc]
// 004cdc48  89442410             mov dword ptr [esp + 0x10], eax
// 004cdc4c  89542414             mov dword ptr [esp + 0x14], edx
// 004cdc50  e85b181900           call 0x65f4b0
// 004cdc55  8d442414             lea eax, [esp + 0x14]
// 004cdc59  50                   push eax
// 004cdc5a  8d4c2410             lea ecx, [esp + 0x10]
// 004cdc5e  e81d93f9ff           call 0x466f80
// 004cdc63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004cdc67  84c0                 test al, al
// 004cdc69  7507                 jne 0x4cdc72
// 004cdc6b  8b17                 mov edx, dword ptr [edi]
// 004cdc6d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 004cdc70  7d3e                 jge 0x4cdcb0
// 004cdc72  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004cdc76  8b5008               mov edx, dword ptr [eax + 8]
// 004cdc79  807a3100             cmp byte ptr [edx + 0x31], 0
// 004cdc7d  57                   push edi
// 004cdc7e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004cdc82  7416                 je 0x4cdc9a
// 004cdc84  50                   push eax
// 004cdc85  6a00                 push 0
// 004cdc87  57                   push edi
// 004cdc88  8bce                 mov ecx, esi
// 004cdc8a  e891eaffff           call 0x4cc720
// 004cdc8f  5b                   pop ebx
// 004cdc90  8bc7                 mov eax, edi
// 004cdc92  5f                   pop edi
// 004cdc93  5e                   pop esi
// 004cdc94  83c414               add esp, 0x14
// 004cdc97  c21000               ret 0x10
// 004cdc9a  51                   push ecx
// 004cdc9b  6a01                 push 1
// 004cdc9d  57                   push edi
// 004cdc9e  8bce                 mov ecx, esi
// 004cdca0  e87beaffff           call 0x4cc720
// 004cdca5  5b                   pop ebx
// 004cdca6  8bc7                 mov eax, edi
// 004cdca8  5f                   pop edi
// 004cdca9  5e                   pop esi
// 004cdcaa  83c414               add esp, 0x14
// 004cdcad  c21000               ret 0x10
// 004cdcb0  57                   push edi
// 004cdcb1  8d442418             lea eax, [esp + 0x18]
// 004cdcb5  50                   push eax
// 004cdcb6  8bce                 mov ecx, esi
// 004cdcb8  e893f7ffff           call 0x4cd450
// 004cdcbd  8b10                 mov edx, dword ptr [eax]
// 004cdcbf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004cdcc3  5b                   pop ebx
// 004cdcc4  8911                 mov dword ptr [ecx], edx
// 004cdcc6  8b4004               mov eax, dword ptr [eax + 4]
// 004cdcc9  5f                   pop edi
// 004cdcca  894104               mov dword ptr [ecx + 4], eax
// 004cdccd  8bc1                 mov eax, ecx
// 004cdccf  5e                   pop esi
// 004cdcd0  83c414               add esp, 0x14
// 004cdcd3  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
