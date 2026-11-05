// from server: 100% by auto
// roc 2009-06 00470940  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470940
//
// 00470940  83ec14               sub esp, 0x14
// 00470943  56                   push esi
// 00470944  8bf1                 mov esi, ecx
// 00470946  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0047094a  57                   push edi
// 0047094b  7521                 jne 0x47096e
// 0047094d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00470951  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00470954  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00470958  50                   push eax
// 00470959  51                   push ecx
// 0047095a  6a01                 push 1
// 0047095c  57                   push edi
// 0047095d  8bce                 mov ecx, esi
// 0047095f  e8bc432800           call 0x6f4d20
// 00470964  8bc7                 mov eax, edi
// 00470966  5f                   pop edi
// 00470967  5e                   pop esi
// 00470968  83c414               add esp, 0x14
// 0047096b  c21000               ret 0x10
// 0047096e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00470972  8b5618               mov edx, dword ptr [esi + 0x18]
// 00470975  8b3a                 mov edi, dword ptr [edx]
// 00470977  8b06                 mov eax, dword ptr [esi]
// 00470979  53                   push ebx
// 0047097a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00470980  85c9                 test ecx, ecx
// 00470982  7404                 je 0x470988
// 00470984  3bc8                 cmp ecx, eax
// 00470986  7406                 je 0x47098e
// 00470988  ffd3                 call ebx
// 0047098a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0047098e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00470992  3bc7                 cmp eax, edi
// 00470994  752a                 jne 0x4709c0
// 00470996  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0047099a  8b0f                 mov ecx, dword ptr [edi]
// 0047099c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0047099f  0f8d4b010000         jge 0x470af0
// 004709a5  57                   push edi
// 004709a6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004709aa  50                   push eax
// 004709ab  6a01                 push 1
// 004709ad  57                   push edi
// 004709ae  8bce                 mov ecx, esi
// 004709b0  e86b432800           call 0x6f4d20
// 004709b5  5b                   pop ebx
// 004709b6  8bc7                 mov eax, edi
// 004709b8  5f                   pop edi
// 004709b9  5e                   pop esi
// 004709ba  83c414               add esp, 0x14
// 004709bd  c21000               ret 0x10
// 004709c0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004709c3  8b16                 mov edx, dword ptr [esi]
// 004709c5  85c9                 test ecx, ecx
// 004709c7  7404                 je 0x4709cd
// 004709c9  3bca                 cmp ecx, edx
// 004709cb  740a                 je 0x4709d7
// 004709cd  ffd3                 call ebx
// 004709cf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004709d3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004709d7  3bc7                 cmp eax, edi
// 004709d9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004709dd  752c                 jne 0x470a0b
// 004709df  8b5618               mov edx, dword ptr [esi + 0x18]
// 004709e2  8b4208               mov eax, dword ptr [edx + 8]
// 004709e5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004709e8  3b0f                 cmp ecx, dword ptr [edi]
// 004709ea  0f8d00010000         jge 0x470af0
// 004709f0  57                   push edi
// 004709f1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004709f5  50                   push eax
// 004709f6  6a00                 push 0
// 004709f8  57                   push edi
// 004709f9  8bce                 mov ecx, esi
// 004709fb  e820432800           call 0x6f4d20
// 00470a00  5b                   pop ebx
// 00470a01  8bc7                 mov eax, edi
// 00470a03  5f                   pop edi
// 00470a04  5e                   pop esi
// 00470a05  83c414               add esp, 0x14
// 00470a08  c21000               ret 0x10
// 00470a0b  8b17                 mov edx, dword ptr [edi]
// 00470a0d  39500c               cmp dword ptr [eax + 0xc], edx
// 00470a10  7e63                 jle 0x470a75
// 00470a12  894c240c             mov dword ptr [esp + 0xc], ecx
// 00470a16  8d4c240c             lea ecx, [esp + 0xc]
// 00470a1a  89442410             mov dword ptr [esp + 0x10], eax
// 00470a1e  e8cd502300           call 0x6a5af0
// 00470a23  8b17                 mov edx, dword ptr [edi]
// 00470a25  8b442410             mov eax, dword ptr [esp + 0x10]
// 00470a29  39500c               cmp dword ptr [eax + 0xc], edx
// 00470a2c  7d3c                 jge 0x470a6a
// 00470a2e  8b5008               mov edx, dword ptr [eax + 8]
// 00470a31  807a1500             cmp byte ptr [edx + 0x15], 0
// 00470a35  57                   push edi
// 00470a36  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00470a3a  8bce                 mov ecx, esi
// 00470a3c  7414                 je 0x470a52
// 00470a3e  50                   push eax
// 00470a3f  6a00                 push 0
// 00470a41  57                   push edi
// 00470a42  e8d9422800           call 0x6f4d20
// 00470a47  5b                   pop ebx
// 00470a48  8bc7                 mov eax, edi
// 00470a4a  5f                   pop edi
// 00470a4b  5e                   pop esi
// 00470a4c  83c414               add esp, 0x14
// 00470a4f  c21000               ret 0x10
// 00470a52  8b442430             mov eax, dword ptr [esp + 0x30]
// 00470a56  50                   push eax
// 00470a57  6a01                 push 1
// 00470a59  57                   push edi
// 00470a5a  e8c1422800           call 0x6f4d20
// 00470a5f  5b                   pop ebx
// 00470a60  8bc7                 mov eax, edi
// 00470a62  5f                   pop edi
// 00470a63  5e                   pop esi
// 00470a64  83c414               add esp, 0x14
// 00470a67  c21000               ret 0x10
// 00470a6a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00470a6e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00470a72  39500c               cmp dword ptr [eax + 0xc], edx
// 00470a75  7d79                 jge 0x470af0
// 00470a77  8b16                 mov edx, dword ptr [esi]
// 00470a79  894c240c             mov dword ptr [esp + 0xc], ecx
// 00470a7d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00470a80  894c2418             mov dword ptr [esp + 0x18], ecx
// 00470a84  8d4c240c             lea ecx, [esp + 0xc]
// 00470a88  89442410             mov dword ptr [esp + 0x10], eax
// 00470a8c  89542414             mov dword ptr [esp + 0x14], edx
// 00470a90  e8db861700           call 0x5e9170
// 00470a95  8d442414             lea eax, [esp + 0x14]
// 00470a99  50                   push eax
// 00470a9a  8d4c2410             lea ecx, [esp + 0x10]
// 00470a9e  e8fd291d00           call 0x6434a0
// 00470aa3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00470aa7  84c0                 test al, al
// 00470aa9  7507                 jne 0x470ab2
// 00470aab  8b17                 mov edx, dword ptr [edi]
// 00470aad  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00470ab0  7d3e                 jge 0x470af0
// 00470ab2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00470ab6  8b5008               mov edx, dword ptr [eax + 8]
// 00470ab9  807a1500             cmp byte ptr [edx + 0x15], 0
// 00470abd  57                   push edi
// 00470abe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00470ac2  7416                 je 0x470ada
// 00470ac4  50                   push eax
// 00470ac5  6a00                 push 0
// 00470ac7  57                   push edi
// 00470ac8  8bce                 mov ecx, esi
// 00470aca  e851422800           call 0x6f4d20
// 00470acf  5b                   pop ebx
// 00470ad0  8bc7                 mov eax, edi
// 00470ad2  5f                   pop edi
// 00470ad3  5e                   pop esi
// 00470ad4  83c414               add esp, 0x14
// 00470ad7  c21000               ret 0x10
// 00470ada  51                   push ecx
// 00470adb  6a01                 push 1
// 00470add  57                   push edi
// 00470ade  8bce                 mov ecx, esi
// 00470ae0  e83b422800           call 0x6f4d20
// 00470ae5  5b                   pop ebx
// 00470ae6  8bc7                 mov eax, edi
// 00470ae8  5f                   pop edi
// 00470ae9  5e                   pop esi
// 00470aea  83c414               add esp, 0x14
// 00470aed  c21000               ret 0x10
// 00470af0  57                   push edi
// 00470af1  8d442418             lea eax, [esp + 0x18]
// 00470af5  50                   push eax
// 00470af6  8bce                 mov ecx, esi
// 00470af8  e833e81c00           call 0x63f330
// 00470afd  8b10                 mov edx, dword ptr [eax]
// 00470aff  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00470b03  5b                   pop ebx
// 00470b04  8911                 mov dword ptr [ecx], edx
// 00470b06  8b4004               mov eax, dword ptr [eax + 4]
// 00470b09  5f                   pop edi
// 00470b0a  894104               mov dword ptr [ecx + 4], eax
// 00470b0d  8bc1                 mov eax, ecx
// 00470b0f  5e                   pop esi
// 00470b10  83c414               add esp, 0x14
// 00470b13  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
