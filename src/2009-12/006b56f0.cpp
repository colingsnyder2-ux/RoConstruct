// from server: 100% by auto
// roc 2009-12 006b56f0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b56f0
//
// 006b56f0  83ec14               sub esp, 0x14
// 006b56f3  56                   push esi
// 006b56f4  8bf1                 mov esi, ecx
// 006b56f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006b56fa  57                   push edi
// 006b56fb  7521                 jne 0x6b571e
// 006b56fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b5701  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006b5704  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5708  50                   push eax
// 006b5709  51                   push ecx
// 006b570a  6a01                 push 1
// 006b570c  57                   push edi
// 006b570d  8bce                 mov ecx, esi
// 006b570f  e8dc70e8ff           call 0x53c7f0
// 006b5714  8bc7                 mov eax, edi
// 006b5716  5f                   pop edi
// 006b5717  5e                   pop esi
// 006b5718  83c414               add esp, 0x14
// 006b571b  c21000               ret 0x10
// 006b571e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006b5722  8b5618               mov edx, dword ptr [esi + 0x18]
// 006b5725  8b3a                 mov edi, dword ptr [edx]
// 006b5727  8b06                 mov eax, dword ptr [esi]
// 006b5729  53                   push ebx
// 006b572a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006b5730  85c9                 test ecx, ecx
// 006b5732  7404                 je 0x6b5738
// 006b5734  3bc8                 cmp ecx, eax
// 006b5736  7406                 je 0x6b573e
// 006b5738  ffd3                 call ebx
// 006b573a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006b573e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b5742  3bc7                 cmp eax, edi
// 006b5744  752a                 jne 0x6b5770
// 006b5746  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006b574a  8b0f                 mov ecx, dword ptr [edi]
// 006b574c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006b574f  0f8d4b010000         jge 0x6b58a0
// 006b5755  57                   push edi
// 006b5756  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006b575a  50                   push eax
// 006b575b  6a01                 push 1
// 006b575d  57                   push edi
// 006b575e  8bce                 mov ecx, esi
// 006b5760  e88b70e8ff           call 0x53c7f0
// 006b5765  5b                   pop ebx
// 006b5766  8bc7                 mov eax, edi
// 006b5768  5f                   pop edi
// 006b5769  5e                   pop esi
// 006b576a  83c414               add esp, 0x14
// 006b576d  c21000               ret 0x10
// 006b5770  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006b5773  8b16                 mov edx, dword ptr [esi]
// 006b5775  85c9                 test ecx, ecx
// 006b5777  7404                 je 0x6b577d
// 006b5779  3bca                 cmp ecx, edx
// 006b577b  740a                 je 0x6b5787
// 006b577d  ffd3                 call ebx
// 006b577f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b5783  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006b5787  3bc7                 cmp eax, edi
// 006b5789  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006b578d  752c                 jne 0x6b57bb
// 006b578f  8b5618               mov edx, dword ptr [esi + 0x18]
// 006b5792  8b4208               mov eax, dword ptr [edx + 8]
// 006b5795  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006b5798  3b0f                 cmp ecx, dword ptr [edi]
// 006b579a  0f8d00010000         jge 0x6b58a0
// 006b57a0  57                   push edi
// 006b57a1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006b57a5  50                   push eax
// 006b57a6  6a00                 push 0
// 006b57a8  57                   push edi
// 006b57a9  8bce                 mov ecx, esi
// 006b57ab  e84070e8ff           call 0x53c7f0
// 006b57b0  5b                   pop ebx
// 006b57b1  8bc7                 mov eax, edi
// 006b57b3  5f                   pop edi
// 006b57b4  5e                   pop esi
// 006b57b5  83c414               add esp, 0x14
// 006b57b8  c21000               ret 0x10
// 006b57bb  8b17                 mov edx, dword ptr [edi]
// 006b57bd  39500c               cmp dword ptr [eax + 0xc], edx
// 006b57c0  7e63                 jle 0x6b5825
// 006b57c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006b57c6  8d4c240c             lea ecx, [esp + 0xc]
// 006b57ca  89442410             mov dword ptr [esp + 0x10], eax
// 006b57ce  e8dd16fcff           call 0x676eb0
// 006b57d3  8b17                 mov edx, dword ptr [edi]
// 006b57d5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b57d9  39500c               cmp dword ptr [eax + 0xc], edx
// 006b57dc  7d3c                 jge 0x6b581a
// 006b57de  8b5008               mov edx, dword ptr [eax + 8]
// 006b57e1  807a1900             cmp byte ptr [edx + 0x19], 0
// 006b57e5  57                   push edi
// 006b57e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006b57ea  8bce                 mov ecx, esi
// 006b57ec  7414                 je 0x6b5802
// 006b57ee  50                   push eax
// 006b57ef  6a00                 push 0
// 006b57f1  57                   push edi
// 006b57f2  e8f96fe8ff           call 0x53c7f0
// 006b57f7  5b                   pop ebx
// 006b57f8  8bc7                 mov eax, edi
// 006b57fa  5f                   pop edi
// 006b57fb  5e                   pop esi
// 006b57fc  83c414               add esp, 0x14
// 006b57ff  c21000               ret 0x10
// 006b5802  8b442430             mov eax, dword ptr [esp + 0x30]
// 006b5806  50                   push eax
// 006b5807  6a01                 push 1
// 006b5809  57                   push edi
// 006b580a  e8e16fe8ff           call 0x53c7f0
// 006b580f  5b                   pop ebx
// 006b5810  8bc7                 mov eax, edi
// 006b5812  5f                   pop edi
// 006b5813  5e                   pop esi
// 006b5814  83c414               add esp, 0x14
// 006b5817  c21000               ret 0x10
// 006b581a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b581e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006b5822  39500c               cmp dword ptr [eax + 0xc], edx
// 006b5825  7d79                 jge 0x6b58a0
// 006b5827  8b16                 mov edx, dword ptr [esi]
// 006b5829  894c240c             mov dword ptr [esp + 0xc], ecx
// 006b582d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006b5830  894c2418             mov dword ptr [esp + 0x18], ecx
// 006b5834  8d4c240c             lea ecx, [esp + 0xc]
// 006b5838  89442410             mov dword ptr [esp + 0x10], eax
// 006b583c  89542414             mov dword ptr [esp + 0x14], edx
// 006b5840  e83b2de8ff           call 0x538580
// 006b5845  8d442414             lea eax, [esp + 0x14]
// 006b5849  50                   push eax
// 006b584a  8d4c2410             lea ecx, [esp + 0x10]
// 006b584e  e80d6bf1ff           call 0x5cc360
// 006b5853  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b5857  84c0                 test al, al
// 006b5859  7507                 jne 0x6b5862
// 006b585b  8b17                 mov edx, dword ptr [edi]
// 006b585d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006b5860  7d3e                 jge 0x6b58a0
// 006b5862  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b5866  8b5008               mov edx, dword ptr [eax + 8]
// 006b5869  807a1900             cmp byte ptr [edx + 0x19], 0
// 006b586d  57                   push edi
// 006b586e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006b5872  7416                 je 0x6b588a
// 006b5874  50                   push eax
// 006b5875  6a00                 push 0
// 006b5877  57                   push edi
// 006b5878  8bce                 mov ecx, esi
// 006b587a  e8716fe8ff           call 0x53c7f0
// 006b587f  5b                   pop ebx
// 006b5880  8bc7                 mov eax, edi
// 006b5882  5f                   pop edi
// 006b5883  5e                   pop esi
// 006b5884  83c414               add esp, 0x14
// 006b5887  c21000               ret 0x10
// 006b588a  51                   push ecx
// 006b588b  6a01                 push 1
// 006b588d  57                   push edi
// 006b588e  8bce                 mov ecx, esi
// 006b5890  e85b6fe8ff           call 0x53c7f0
// 006b5895  5b                   pop ebx
// 006b5896  8bc7                 mov eax, edi
// 006b5898  5f                   pop edi
// 006b5899  5e                   pop esi
// 006b589a  83c414               add esp, 0x14
// 006b589d  c21000               ret 0x10
// 006b58a0  57                   push edi
// 006b58a1  8d442418             lea eax, [esp + 0x18]
// 006b58a5  50                   push eax
// 006b58a6  8bce                 mov ecx, esi
// 006b58a8  e863fcffff           call 0x6b5510
// 006b58ad  8b10                 mov edx, dword ptr [eax]
// 006b58af  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006b58b3  5b                   pop ebx
// 006b58b4  8911                 mov dword ptr [ecx], edx
// 006b58b6  8b4004               mov eax, dword ptr [eax + 4]
// 006b58b9  5f                   pop edi
// 006b58ba  894104               mov dword ptr [ecx + 4], eax
// 006b58bd  8bc1                 mov eax, ecx
// 006b58bf  5e                   pop esi
// 006b58c0  83c414               add esp, 0x14
// 006b58c3  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
