// from server: 100% by auto
// roc 2009-12 006adf50  unit: RBX::Accoutrement  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006adf50
//
// 006adf50  83ec14               sub esp, 0x14
// 006adf53  56                   push esi
// 006adf54  8bf1                 mov esi, ecx
// 006adf56  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006adf5a  57                   push edi
// 006adf5b  7521                 jne 0x6adf7e
// 006adf5d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006adf61  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006adf64  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006adf68  50                   push eax
// 006adf69  51                   push ecx
// 006adf6a  6a01                 push 1
// 006adf6c  57                   push edi
// 006adf6d  8bce                 mov ecx, esi
// 006adf6f  e8acf5ffff           call 0x6ad520
// 006adf74  8bc7                 mov eax, edi
// 006adf76  5f                   pop edi
// 006adf77  5e                   pop esi
// 006adf78  83c414               add esp, 0x14
// 006adf7b  c21000               ret 0x10
// 006adf7e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006adf82  8b5618               mov edx, dword ptr [esi + 0x18]
// 006adf85  8b3a                 mov edi, dword ptr [edx]
// 006adf87  8b06                 mov eax, dword ptr [esi]
// 006adf89  53                   push ebx
// 006adf8a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006adf90  85c9                 test ecx, ecx
// 006adf92  7404                 je 0x6adf98
// 006adf94  3bc8                 cmp ecx, eax
// 006adf96  7406                 je 0x6adf9e
// 006adf98  ffd3                 call ebx
// 006adf9a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006adf9e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006adfa2  3bc7                 cmp eax, edi
// 006adfa4  752a                 jne 0x6adfd0
// 006adfa6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006adfaa  8b0f                 mov ecx, dword ptr [edi]
// 006adfac  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006adfaf  0f8d4b010000         jge 0x6ae100
// 006adfb5  57                   push edi
// 006adfb6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006adfba  50                   push eax
// 006adfbb  6a01                 push 1
// 006adfbd  57                   push edi
// 006adfbe  8bce                 mov ecx, esi
// 006adfc0  e85bf5ffff           call 0x6ad520
// 006adfc5  5b                   pop ebx
// 006adfc6  8bc7                 mov eax, edi
// 006adfc8  5f                   pop edi
// 006adfc9  5e                   pop esi
// 006adfca  83c414               add esp, 0x14
// 006adfcd  c21000               ret 0x10
// 006adfd0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006adfd3  8b16                 mov edx, dword ptr [esi]
// 006adfd5  85c9                 test ecx, ecx
// 006adfd7  7404                 je 0x6adfdd
// 006adfd9  3bca                 cmp ecx, edx
// 006adfdb  740a                 je 0x6adfe7
// 006adfdd  ffd3                 call ebx
// 006adfdf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006adfe3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006adfe7  3bc7                 cmp eax, edi
// 006adfe9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006adfed  752c                 jne 0x6ae01b
// 006adfef  8b5618               mov edx, dword ptr [esi + 0x18]
// 006adff2  8b4208               mov eax, dword ptr [edx + 8]
// 006adff5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006adff8  3b0f                 cmp ecx, dword ptr [edi]
// 006adffa  0f8d00010000         jge 0x6ae100
// 006ae000  57                   push edi
// 006ae001  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006ae005  50                   push eax
// 006ae006  6a00                 push 0
// 006ae008  57                   push edi
// 006ae009  8bce                 mov ecx, esi
// 006ae00b  e810f5ffff           call 0x6ad520
// 006ae010  5b                   pop ebx
// 006ae011  8bc7                 mov eax, edi
// 006ae013  5f                   pop edi
// 006ae014  5e                   pop esi
// 006ae015  83c414               add esp, 0x14
// 006ae018  c21000               ret 0x10
// 006ae01b  8b17                 mov edx, dword ptr [edi]
// 006ae01d  39500c               cmp dword ptr [eax + 0xc], edx
// 006ae020  7e63                 jle 0x6ae085
// 006ae022  894c240c             mov dword ptr [esp + 0xc], ecx
// 006ae026  8d4c240c             lea ecx, [esp + 0xc]
// 006ae02a  89442410             mov dword ptr [esp + 0x10], eax
// 006ae02e  e89df2f1ff           call 0x5cd2d0
// 006ae033  8b17                 mov edx, dword ptr [edi]
// 006ae035  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ae039  39500c               cmp dword ptr [eax + 0xc], edx
// 006ae03c  7d3c                 jge 0x6ae07a
// 006ae03e  8b5008               mov edx, dword ptr [eax + 8]
// 006ae041  807a2100             cmp byte ptr [edx + 0x21], 0
// 006ae045  57                   push edi
// 006ae046  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006ae04a  8bce                 mov ecx, esi
// 006ae04c  7414                 je 0x6ae062
// 006ae04e  50                   push eax
// 006ae04f  6a00                 push 0
// 006ae051  57                   push edi
// 006ae052  e8c9f4ffff           call 0x6ad520
// 006ae057  5b                   pop ebx
// 006ae058  8bc7                 mov eax, edi
// 006ae05a  5f                   pop edi
// 006ae05b  5e                   pop esi
// 006ae05c  83c414               add esp, 0x14
// 006ae05f  c21000               ret 0x10
// 006ae062  8b442430             mov eax, dword ptr [esp + 0x30]
// 006ae066  50                   push eax
// 006ae067  6a01                 push 1
// 006ae069  57                   push edi
// 006ae06a  e8b1f4ffff           call 0x6ad520
// 006ae06f  5b                   pop ebx
// 006ae070  8bc7                 mov eax, edi
// 006ae072  5f                   pop edi
// 006ae073  5e                   pop esi
// 006ae074  83c414               add esp, 0x14
// 006ae077  c21000               ret 0x10
// 006ae07a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006ae07e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006ae082  39500c               cmp dword ptr [eax + 0xc], edx
// 006ae085  7d79                 jge 0x6ae100
// 006ae087  8b16                 mov edx, dword ptr [esi]
// 006ae089  894c240c             mov dword ptr [esp + 0xc], ecx
// 006ae08d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006ae090  894c2418             mov dword ptr [esp + 0x18], ecx
// 006ae094  8d4c240c             lea ecx, [esp + 0xc]
// 006ae098  89442410             mov dword ptr [esp + 0x10], eax
// 006ae09c  89542414             mov dword ptr [esp + 0x14], edx
// 006ae0a0  e85b10deff           call 0x48f100
// 006ae0a5  8d442414             lea eax, [esp + 0x14]
// 006ae0a9  50                   push eax
// 006ae0aa  8d4c2410             lea ecx, [esp + 0x10]
// 006ae0ae  e8ade2f1ff           call 0x5cc360
// 006ae0b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ae0b7  84c0                 test al, al
// 006ae0b9  7507                 jne 0x6ae0c2
// 006ae0bb  8b17                 mov edx, dword ptr [edi]
// 006ae0bd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006ae0c0  7d3e                 jge 0x6ae100
// 006ae0c2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006ae0c6  8b5008               mov edx, dword ptr [eax + 8]
// 006ae0c9  807a2100             cmp byte ptr [edx + 0x21], 0
// 006ae0cd  57                   push edi
// 006ae0ce  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006ae0d2  7416                 je 0x6ae0ea
// 006ae0d4  50                   push eax
// 006ae0d5  6a00                 push 0
// 006ae0d7  57                   push edi
// 006ae0d8  8bce                 mov ecx, esi
// 006ae0da  e841f4ffff           call 0x6ad520
// 006ae0df  5b                   pop ebx
// 006ae0e0  8bc7                 mov eax, edi
// 006ae0e2  5f                   pop edi
// 006ae0e3  5e                   pop esi
// 006ae0e4  83c414               add esp, 0x14
// 006ae0e7  c21000               ret 0x10
// 006ae0ea  51                   push ecx
// 006ae0eb  6a01                 push 1
// 006ae0ed  57                   push edi
// 006ae0ee  8bce                 mov ecx, esi
// 006ae0f0  e82bf4ffff           call 0x6ad520
// 006ae0f5  5b                   pop ebx
// 006ae0f6  8bc7                 mov eax, edi
// 006ae0f8  5f                   pop edi
// 006ae0f9  5e                   pop esi
// 006ae0fa  83c414               add esp, 0x14
// 006ae0fd  c21000               ret 0x10
// 006ae100  57                   push edi
// 006ae101  8d442418             lea eax, [esp + 0x18]
// 006ae105  50                   push eax
// 006ae106  8bce                 mov ecx, esi
// 006ae108  e8b3faffff           call 0x6adbc0
// 006ae10d  8b10                 mov edx, dword ptr [eax]
// 006ae10f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006ae113  5b                   pop ebx
// 006ae114  8911                 mov dword ptr [ecx], edx
// 006ae116  8b4004               mov eax, dword ptr [eax + 4]
// 006ae119  5f                   pop edi
// 006ae11a  894104               mov dword ptr [ecx + 4], eax
// 006ae11d  8bc1                 mov eax, ecx
// 006ae11f  5e                   pop esi
// 006ae120  83c414               add esp, 0x14
// 006ae123  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
