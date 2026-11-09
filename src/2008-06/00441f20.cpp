// from server: 100% by auto
// roc 2008-06 00441f20  unit: TextureItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00441f20
//
// 00441f20  83ec14               sub esp, 0x14
// 00441f23  56                   push esi
// 00441f24  8bf1                 mov esi, ecx
// 00441f26  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00441f2a  57                   push edi
// 00441f2b  7521                 jne 0x441f4e
// 00441f2d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441f31  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00441f34  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00441f38  50                   push eax
// 00441f39  51                   push ecx
// 00441f3a  6a01                 push 1
// 00441f3c  57                   push edi
// 00441f3d  8bce                 mov ecx, esi
// 00441f3f  e8fce6ffff           call 0x440640
// 00441f44  8bc7                 mov eax, edi
// 00441f46  5f                   pop edi
// 00441f47  5e                   pop esi
// 00441f48  83c414               add esp, 0x14
// 00441f4b  c21000               ret 0x10
// 00441f4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00441f52  8b5618               mov edx, dword ptr [esi + 0x18]
// 00441f55  8b3a                 mov edi, dword ptr [edx]
// 00441f57  8b06                 mov eax, dword ptr [esi]
// 00441f59  53                   push ebx
// 00441f5a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00441f60  85c9                 test ecx, ecx
// 00441f62  7404                 je 0x441f68
// 00441f64  3bc8                 cmp ecx, eax
// 00441f66  7406                 je 0x441f6e
// 00441f68  ffd3                 call ebx
// 00441f6a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441f6e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441f72  3bc7                 cmp eax, edi
// 00441f74  752a                 jne 0x441fa0
// 00441f76  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00441f7a  8b0f                 mov ecx, dword ptr [edi]
// 00441f7c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00441f7f  0f834b010000         jae 0x4420d0
// 00441f85  57                   push edi
// 00441f86  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00441f8a  50                   push eax
// 00441f8b  6a01                 push 1
// 00441f8d  57                   push edi
// 00441f8e  8bce                 mov ecx, esi
// 00441f90  e8abe6ffff           call 0x440640
// 00441f95  5b                   pop ebx
// 00441f96  8bc7                 mov eax, edi
// 00441f98  5f                   pop edi
// 00441f99  5e                   pop esi
// 00441f9a  83c414               add esp, 0x14
// 00441f9d  c21000               ret 0x10
// 00441fa0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00441fa3  8b16                 mov edx, dword ptr [esi]
// 00441fa5  85c9                 test ecx, ecx
// 00441fa7  7404                 je 0x441fad
// 00441fa9  3bca                 cmp ecx, edx
// 00441fab  740a                 je 0x441fb7
// 00441fad  ffd3                 call ebx
// 00441faf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441fb3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441fb7  3bc7                 cmp eax, edi
// 00441fb9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00441fbd  752c                 jne 0x441feb
// 00441fbf  8b5618               mov edx, dword ptr [esi + 0x18]
// 00441fc2  8b4208               mov eax, dword ptr [edx + 8]
// 00441fc5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00441fc8  3b0f                 cmp ecx, dword ptr [edi]
// 00441fca  0f8300010000         jae 0x4420d0
// 00441fd0  57                   push edi
// 00441fd1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00441fd5  50                   push eax
// 00441fd6  6a00                 push 0
// 00441fd8  57                   push edi
// 00441fd9  8bce                 mov ecx, esi
// 00441fdb  e860e6ffff           call 0x440640
// 00441fe0  5b                   pop ebx
// 00441fe1  8bc7                 mov eax, edi
// 00441fe3  5f                   pop edi
// 00441fe4  5e                   pop esi
// 00441fe5  83c414               add esp, 0x14
// 00441fe8  c21000               ret 0x10
// 00441feb  8b17                 mov edx, dword ptr [edi]
// 00441fed  39500c               cmp dword ptr [eax + 0xc], edx
// 00441ff0  7663                 jbe 0x442055
// 00441ff2  894c240c             mov dword ptr [esp + 0xc], ecx
// 00441ff6  8d4c240c             lea ecx, [esp + 0xc]
// 00441ffa  89442410             mov dword ptr [esp + 0x10], eax
// 00441ffe  e8dd66ffff           call 0x4386e0
// 00442003  8b17                 mov edx, dword ptr [edi]
// 00442005  8b442410             mov eax, dword ptr [esp + 0x10]
// 00442009  39500c               cmp dword ptr [eax + 0xc], edx
// 0044200c  733c                 jae 0x44204a
// 0044200e  8b5008               mov edx, dword ptr [eax + 8]
// 00442011  807a2900             cmp byte ptr [edx + 0x29], 0
// 00442015  57                   push edi
// 00442016  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044201a  8bce                 mov ecx, esi
// 0044201c  7414                 je 0x442032
// 0044201e  50                   push eax
// 0044201f  6a00                 push 0
// 00442021  57                   push edi
// 00442022  e819e6ffff           call 0x440640
// 00442027  5b                   pop ebx
// 00442028  8bc7                 mov eax, edi
// 0044202a  5f                   pop edi
// 0044202b  5e                   pop esi
// 0044202c  83c414               add esp, 0x14
// 0044202f  c21000               ret 0x10
// 00442032  8b442430             mov eax, dword ptr [esp + 0x30]
// 00442036  50                   push eax
// 00442037  6a01                 push 1
// 00442039  57                   push edi
// 0044203a  e801e6ffff           call 0x440640
// 0044203f  5b                   pop ebx
// 00442040  8bc7                 mov eax, edi
// 00442042  5f                   pop edi
// 00442043  5e                   pop esi
// 00442044  83c414               add esp, 0x14
// 00442047  c21000               ret 0x10
// 0044204a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0044204e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00442052  39500c               cmp dword ptr [eax + 0xc], edx
// 00442055  7379                 jae 0x4420d0
// 00442057  8b16                 mov edx, dword ptr [esi]
// 00442059  894c240c             mov dword ptr [esp + 0xc], ecx
// 0044205d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00442060  894c2418             mov dword ptr [esp + 0x18], ecx
// 00442064  8d4c240c             lea ecx, [esp + 0xc]
// 00442068  89442410             mov dword ptr [esp + 0x10], eax
// 0044206c  89542414             mov dword ptr [esp + 0x14], edx
// 00442070  e8fb66ffff           call 0x438770
// 00442075  8d442414             lea eax, [esp + 0x14]
// 00442079  50                   push eax
// 0044207a  8d4c2410             lea ecx, [esp + 0x10]
// 0044207e  e81dac1a00           call 0x5ecca0
// 00442083  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00442087  84c0                 test al, al
// 00442089  7507                 jne 0x442092
// 0044208b  8b17                 mov edx, dword ptr [edi]
// 0044208d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00442090  733e                 jae 0x4420d0
// 00442092  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00442096  8b5008               mov edx, dword ptr [eax + 8]
// 00442099  807a2900             cmp byte ptr [edx + 0x29], 0
// 0044209d  57                   push edi
// 0044209e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004420a2  7416                 je 0x4420ba
// 004420a4  50                   push eax
// 004420a5  6a00                 push 0
// 004420a7  57                   push edi
// 004420a8  8bce                 mov ecx, esi
// 004420aa  e891e5ffff           call 0x440640
// 004420af  5b                   pop ebx
// 004420b0  8bc7                 mov eax, edi
// 004420b2  5f                   pop edi
// 004420b3  5e                   pop esi
// 004420b4  83c414               add esp, 0x14
// 004420b7  c21000               ret 0x10
// 004420ba  51                   push ecx
// 004420bb  6a01                 push 1
// 004420bd  57                   push edi
// 004420be  8bce                 mov ecx, esi
// 004420c0  e87be5ffff           call 0x440640
// 004420c5  5b                   pop ebx
// 004420c6  8bc7                 mov eax, edi
// 004420c8  5f                   pop edi
// 004420c9  5e                   pop esi
// 004420ca  83c414               add esp, 0x14
// 004420cd  c21000               ret 0x10
// 004420d0  57                   push edi
// 004420d1  8d442418             lea eax, [esp + 0x18]
// 004420d5  50                   push eax
// 004420d6  8bce                 mov ecx, esi
// 004420d8  e813f7ffff           call 0x4417f0
// 004420dd  8b10                 mov edx, dword ptr [eax]
// 004420df  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004420e3  5b                   pop ebx
// 004420e4  8911                 mov dword ptr [ecx], edx
// 004420e6  8b4004               mov eax, dword ptr [eax + 4]
// 004420e9  5f                   pop edi
// 004420ea  894104               mov dword ptr [ecx + 4], eax
// 004420ed  8bc1                 mov eax, ecx
// 004420ef  5e                   pop esi
// 004420f0  83c414               add esp, 0x14
// 004420f3  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
