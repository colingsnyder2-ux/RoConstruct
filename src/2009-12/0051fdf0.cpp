// from server: 100% by auto
// roc 2009-12 0051fdf0  unit: RBX::Network::Players  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0051fdf0
//
// 0051fdf0  83ec14               sub esp, 0x14
// 0051fdf3  56                   push esi
// 0051fdf4  8bf1                 mov esi, ecx
// 0051fdf6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0051fdfa  57                   push edi
// 0051fdfb  7521                 jne 0x51fe1e
// 0051fdfd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051fe01  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051fe04  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051fe08  50                   push eax
// 0051fe09  51                   push ecx
// 0051fe0a  6a01                 push 1
// 0051fe0c  57                   push edi
// 0051fe0d  8bce                 mov ecx, esi
// 0051fe0f  e81cebffff           call 0x51e930
// 0051fe14  8bc7                 mov eax, edi
// 0051fe16  5f                   pop edi
// 0051fe17  5e                   pop esi
// 0051fe18  83c414               add esp, 0x14
// 0051fe1b  c21000               ret 0x10
// 0051fe1e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0051fe22  8b5618               mov edx, dword ptr [esi + 0x18]
// 0051fe25  8b3a                 mov edi, dword ptr [edx]
// 0051fe27  8b06                 mov eax, dword ptr [esi]
// 0051fe29  53                   push ebx
// 0051fe2a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0051fe30  85c9                 test ecx, ecx
// 0051fe32  7404                 je 0x51fe38
// 0051fe34  3bc8                 cmp ecx, eax
// 0051fe36  7406                 je 0x51fe3e
// 0051fe38  ffd3                 call ebx
// 0051fe3a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051fe3e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051fe42  3bc7                 cmp eax, edi
// 0051fe44  752a                 jne 0x51fe70
// 0051fe46  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051fe4a  8b0f                 mov ecx, dword ptr [edi]
// 0051fe4c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0051fe4f  0f8d4b010000         jge 0x51ffa0
// 0051fe55  57                   push edi
// 0051fe56  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051fe5a  50                   push eax
// 0051fe5b  6a01                 push 1
// 0051fe5d  57                   push edi
// 0051fe5e  8bce                 mov ecx, esi
// 0051fe60  e8cbeaffff           call 0x51e930
// 0051fe65  5b                   pop ebx
// 0051fe66  8bc7                 mov eax, edi
// 0051fe68  5f                   pop edi
// 0051fe69  5e                   pop esi
// 0051fe6a  83c414               add esp, 0x14
// 0051fe6d  c21000               ret 0x10
// 0051fe70  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0051fe73  8b16                 mov edx, dword ptr [esi]
// 0051fe75  85c9                 test ecx, ecx
// 0051fe77  7404                 je 0x51fe7d
// 0051fe79  3bca                 cmp ecx, edx
// 0051fe7b  740a                 je 0x51fe87
// 0051fe7d  ffd3                 call ebx
// 0051fe7f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051fe83  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051fe87  3bc7                 cmp eax, edi
// 0051fe89  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051fe8d  752c                 jne 0x51febb
// 0051fe8f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0051fe92  8b4208               mov eax, dword ptr [edx + 8]
// 0051fe95  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0051fe98  3b0f                 cmp ecx, dword ptr [edi]
// 0051fe9a  0f8d00010000         jge 0x51ffa0
// 0051fea0  57                   push edi
// 0051fea1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051fea5  50                   push eax
// 0051fea6  6a00                 push 0
// 0051fea8  57                   push edi
// 0051fea9  8bce                 mov ecx, esi
// 0051feab  e880eaffff           call 0x51e930
// 0051feb0  5b                   pop ebx
// 0051feb1  8bc7                 mov eax, edi
// 0051feb3  5f                   pop edi
// 0051feb4  5e                   pop esi
// 0051feb5  83c414               add esp, 0x14
// 0051feb8  c21000               ret 0x10
// 0051febb  8b17                 mov edx, dword ptr [edi]
// 0051febd  39500c               cmp dword ptr [eax + 0xc], edx
// 0051fec0  7e63                 jle 0x51ff25
// 0051fec2  894c240c             mov dword ptr [esp + 0xc], ecx
// 0051fec6  8d4c240c             lea ecx, [esp + 0xc]
// 0051feca  89442410             mov dword ptr [esp + 0x10], eax
// 0051fece  e88d39ffff           call 0x513860
// 0051fed3  8b17                 mov edx, dword ptr [edi]
// 0051fed5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0051fed9  39500c               cmp dword ptr [eax + 0xc], edx
// 0051fedc  7d3c                 jge 0x51ff1a
// 0051fede  8b5008               mov edx, dword ptr [eax + 8]
// 0051fee1  807a3100             cmp byte ptr [edx + 0x31], 0
// 0051fee5  57                   push edi
// 0051fee6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051feea  8bce                 mov ecx, esi
// 0051feec  7414                 je 0x51ff02
// 0051feee  50                   push eax
// 0051feef  6a00                 push 0
// 0051fef1  57                   push edi
// 0051fef2  e839eaffff           call 0x51e930
// 0051fef7  5b                   pop ebx
// 0051fef8  8bc7                 mov eax, edi
// 0051fefa  5f                   pop edi
// 0051fefb  5e                   pop esi
// 0051fefc  83c414               add esp, 0x14
// 0051feff  c21000               ret 0x10
// 0051ff02  8b442430             mov eax, dword ptr [esp + 0x30]
// 0051ff06  50                   push eax
// 0051ff07  6a01                 push 1
// 0051ff09  57                   push edi
// 0051ff0a  e821eaffff           call 0x51e930
// 0051ff0f  5b                   pop ebx
// 0051ff10  8bc7                 mov eax, edi
// 0051ff12  5f                   pop edi
// 0051ff13  5e                   pop esi
// 0051ff14  83c414               add esp, 0x14
// 0051ff17  c21000               ret 0x10
// 0051ff1a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051ff1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051ff22  39500c               cmp dword ptr [eax + 0xc], edx
// 0051ff25  7d79                 jge 0x51ffa0
// 0051ff27  8b16                 mov edx, dword ptr [esi]
// 0051ff29  894c240c             mov dword ptr [esp + 0xc], ecx
// 0051ff2d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051ff30  894c2418             mov dword ptr [esp + 0x18], ecx
// 0051ff34  8d4c240c             lea ecx, [esp + 0xc]
// 0051ff38  89442410             mov dword ptr [esp + 0x10], eax
// 0051ff3c  89542414             mov dword ptr [esp + 0x14], edx
// 0051ff40  e8ab39ffff           call 0x5138f0
// 0051ff45  8d442414             lea eax, [esp + 0x14]
// 0051ff49  50                   push eax
// 0051ff4a  8d4c2410             lea ecx, [esp + 0x10]
// 0051ff4e  e80dc40a00           call 0x5cc360
// 0051ff53  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051ff57  84c0                 test al, al
// 0051ff59  7507                 jne 0x51ff62
// 0051ff5b  8b17                 mov edx, dword ptr [edi]
// 0051ff5d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0051ff60  7d3e                 jge 0x51ffa0
// 0051ff62  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051ff66  8b5008               mov edx, dword ptr [eax + 8]
// 0051ff69  807a3100             cmp byte ptr [edx + 0x31], 0
// 0051ff6d  57                   push edi
// 0051ff6e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051ff72  7416                 je 0x51ff8a
// 0051ff74  50                   push eax
// 0051ff75  6a00                 push 0
// 0051ff77  57                   push edi
// 0051ff78  8bce                 mov ecx, esi
// 0051ff7a  e8b1e9ffff           call 0x51e930
// 0051ff7f  5b                   pop ebx
// 0051ff80  8bc7                 mov eax, edi
// 0051ff82  5f                   pop edi
// 0051ff83  5e                   pop esi
// 0051ff84  83c414               add esp, 0x14
// 0051ff87  c21000               ret 0x10
// 0051ff8a  51                   push ecx
// 0051ff8b  6a01                 push 1
// 0051ff8d  57                   push edi
// 0051ff8e  8bce                 mov ecx, esi
// 0051ff90  e89be9ffff           call 0x51e930
// 0051ff95  5b                   pop ebx
// 0051ff96  8bc7                 mov eax, edi
// 0051ff98  5f                   pop edi
// 0051ff99  5e                   pop esi
// 0051ff9a  83c414               add esp, 0x14
// 0051ff9d  c21000               ret 0x10
// 0051ffa0  57                   push edi
// 0051ffa1  8d442418             lea eax, [esp + 0x18]
// 0051ffa5  50                   push eax
// 0051ffa6  8bce                 mov ecx, esi
// 0051ffa8  e873f5ffff           call 0x51f520
// 0051ffad  8b10                 mov edx, dword ptr [eax]
// 0051ffaf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0051ffb3  5b                   pop ebx
// 0051ffb4  8911                 mov dword ptr [ecx], edx
// 0051ffb6  8b4004               mov eax, dword ptr [eax + 4]
// 0051ffb9  5f                   pop edi
// 0051ffba  894104               mov dword ptr [ecx + 4], eax
// 0051ffbd  8bc1                 mov eax, ecx
// 0051ffbf  5e                   pop esi
// 0051ffc0  83c414               add esp, 0x14
// 0051ffc3  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
