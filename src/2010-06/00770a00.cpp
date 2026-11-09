// from server: 100% by auto
// roc 2010-06 00770a00  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00770a00
//
// 00770a00  83ec14               sub esp, 0x14
// 00770a03  56                   push esi
// 00770a04  8bf1                 mov esi, ecx
// 00770a06  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00770a0a  57                   push edi
// 00770a0b  7521                 jne 0x770a2e
// 00770a0d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00770a11  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00770a14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00770a18  50                   push eax
// 00770a19  51                   push ecx
// 00770a1a  6a01                 push 1
// 00770a1c  57                   push edi
// 00770a1d  8bce                 mov ecx, esi
// 00770a1f  e86cf4ffff           call 0x76fe90
// 00770a24  8bc7                 mov eax, edi
// 00770a26  5f                   pop edi
// 00770a27  5e                   pop esi
// 00770a28  83c414               add esp, 0x14
// 00770a2b  c21000               ret 0x10
// 00770a2e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00770a32  8b5618               mov edx, dword ptr [esi + 0x18]
// 00770a35  8b3a                 mov edi, dword ptr [edx]
// 00770a37  8b06                 mov eax, dword ptr [esi]
// 00770a39  53                   push ebx
// 00770a3a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00770a40  85c9                 test ecx, ecx
// 00770a42  7404                 je 0x770a48
// 00770a44  3bc8                 cmp ecx, eax
// 00770a46  7406                 je 0x770a4e
// 00770a48  ffd3                 call ebx
// 00770a4a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00770a4e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00770a52  3bc7                 cmp eax, edi
// 00770a54  752a                 jne 0x770a80
// 00770a56  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00770a5a  8b0f                 mov ecx, dword ptr [edi]
// 00770a5c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00770a5f  0f834b010000         jae 0x770bb0
// 00770a65  57                   push edi
// 00770a66  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00770a6a  50                   push eax
// 00770a6b  6a01                 push 1
// 00770a6d  57                   push edi
// 00770a6e  8bce                 mov ecx, esi
// 00770a70  e81bf4ffff           call 0x76fe90
// 00770a75  5b                   pop ebx
// 00770a76  8bc7                 mov eax, edi
// 00770a78  5f                   pop edi
// 00770a79  5e                   pop esi
// 00770a7a  83c414               add esp, 0x14
// 00770a7d  c21000               ret 0x10
// 00770a80  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00770a83  8b16                 mov edx, dword ptr [esi]
// 00770a85  85c9                 test ecx, ecx
// 00770a87  7404                 je 0x770a8d
// 00770a89  3bca                 cmp ecx, edx
// 00770a8b  740a                 je 0x770a97
// 00770a8d  ffd3                 call ebx
// 00770a8f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00770a93  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00770a97  3bc7                 cmp eax, edi
// 00770a99  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00770a9d  752c                 jne 0x770acb
// 00770a9f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00770aa2  8b4208               mov eax, dword ptr [edx + 8]
// 00770aa5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00770aa8  3b0f                 cmp ecx, dword ptr [edi]
// 00770aaa  0f8300010000         jae 0x770bb0
// 00770ab0  57                   push edi
// 00770ab1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00770ab5  50                   push eax
// 00770ab6  6a00                 push 0
// 00770ab8  57                   push edi
// 00770ab9  8bce                 mov ecx, esi
// 00770abb  e8d0f3ffff           call 0x76fe90
// 00770ac0  5b                   pop ebx
// 00770ac1  8bc7                 mov eax, edi
// 00770ac3  5f                   pop edi
// 00770ac4  5e                   pop esi
// 00770ac5  83c414               add esp, 0x14
// 00770ac8  c21000               ret 0x10
// 00770acb  8b17                 mov edx, dword ptr [edi]
// 00770acd  39500c               cmp dword ptr [eax + 0xc], edx
// 00770ad0  7663                 jbe 0x770b35
// 00770ad2  894c240c             mov dword ptr [esp + 0xc], ecx
// 00770ad6  8d4c240c             lea ecx, [esp + 0xc]
// 00770ada  89442410             mov dword ptr [esp + 0x10], eax
// 00770ade  e8ddcdf1ff           call 0x68d8c0
// 00770ae3  8b17                 mov edx, dword ptr [edi]
// 00770ae5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00770ae9  39500c               cmp dword ptr [eax + 0xc], edx
// 00770aec  733c                 jae 0x770b2a
// 00770aee  8b5008               mov edx, dword ptr [eax + 8]
// 00770af1  807a2900             cmp byte ptr [edx + 0x29], 0
// 00770af5  57                   push edi
// 00770af6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00770afa  8bce                 mov ecx, esi
// 00770afc  7414                 je 0x770b12
// 00770afe  50                   push eax
// 00770aff  6a00                 push 0
// 00770b01  57                   push edi
// 00770b02  e889f3ffff           call 0x76fe90
// 00770b07  5b                   pop ebx
// 00770b08  8bc7                 mov eax, edi
// 00770b0a  5f                   pop edi
// 00770b0b  5e                   pop esi
// 00770b0c  83c414               add esp, 0x14
// 00770b0f  c21000               ret 0x10
// 00770b12  8b442430             mov eax, dword ptr [esp + 0x30]
// 00770b16  50                   push eax
// 00770b17  6a01                 push 1
// 00770b19  57                   push edi
// 00770b1a  e871f3ffff           call 0x76fe90
// 00770b1f  5b                   pop ebx
// 00770b20  8bc7                 mov eax, edi
// 00770b22  5f                   pop edi
// 00770b23  5e                   pop esi
// 00770b24  83c414               add esp, 0x14
// 00770b27  c21000               ret 0x10
// 00770b2a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00770b2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00770b32  39500c               cmp dword ptr [eax + 0xc], edx
// 00770b35  7379                 jae 0x770bb0
// 00770b37  8b16                 mov edx, dword ptr [esi]
// 00770b39  894c240c             mov dword ptr [esp + 0xc], ecx
// 00770b3d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00770b40  894c2418             mov dword ptr [esp + 0x18], ecx
// 00770b44  8d4c240c             lea ecx, [esp + 0xc]
// 00770b48  89442410             mov dword ptr [esp + 0x10], eax
// 00770b4c  89542414             mov dword ptr [esp + 0x14], edx
// 00770b50  e85beaffff           call 0x76f5b0
// 00770b55  8d442414             lea eax, [esp + 0x14]
// 00770b59  50                   push eax
// 00770b5a  8d4c2410             lea ecx, [esp + 0x10]
// 00770b5e  e81d64cfff           call 0x466f80
// 00770b63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00770b67  84c0                 test al, al
// 00770b69  7507                 jne 0x770b72
// 00770b6b  8b17                 mov edx, dword ptr [edi]
// 00770b6d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00770b70  733e                 jae 0x770bb0
// 00770b72  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00770b76  8b5008               mov edx, dword ptr [eax + 8]
// 00770b79  807a2900             cmp byte ptr [edx + 0x29], 0
// 00770b7d  57                   push edi
// 00770b7e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00770b82  7416                 je 0x770b9a
// 00770b84  50                   push eax
// 00770b85  6a00                 push 0
// 00770b87  57                   push edi
// 00770b88  8bce                 mov ecx, esi
// 00770b8a  e801f3ffff           call 0x76fe90
// 00770b8f  5b                   pop ebx
// 00770b90  8bc7                 mov eax, edi
// 00770b92  5f                   pop edi
// 00770b93  5e                   pop esi
// 00770b94  83c414               add esp, 0x14
// 00770b97  c21000               ret 0x10
// 00770b9a  51                   push ecx
// 00770b9b  6a01                 push 1
// 00770b9d  57                   push edi
// 00770b9e  8bce                 mov ecx, esi
// 00770ba0  e8ebf2ffff           call 0x76fe90
// 00770ba5  5b                   pop ebx
// 00770ba6  8bc7                 mov eax, edi
// 00770ba8  5f                   pop edi
// 00770ba9  5e                   pop esi
// 00770baa  83c414               add esp, 0x14
// 00770bad  c21000               ret 0x10
// 00770bb0  57                   push edi
// 00770bb1  8d442418             lea eax, [esp + 0x18]
// 00770bb5  50                   push eax
// 00770bb6  8bce                 mov ecx, esi
// 00770bb8  e823f8ffff           call 0x7703e0
// 00770bbd  8b10                 mov edx, dword ptr [eax]
// 00770bbf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00770bc3  5b                   pop ebx
// 00770bc4  8911                 mov dword ptr [ecx], edx
// 00770bc6  8b4004               mov eax, dword ptr [eax + 4]
// 00770bc9  5f                   pop edi
// 00770bca  894104               mov dword ptr [ecx + 4], eax
// 00770bcd  8bc1                 mov eax, ecx
// 00770bcf  5e                   pop esi
// 00770bd0  83c414               add esp, 0x14
// 00770bd3  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
