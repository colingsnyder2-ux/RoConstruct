// from server: 100% by auto
// roc 2009-12 007645a0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007645a0
//
// 007645a0  83ec14               sub esp, 0x14
// 007645a3  56                   push esi
// 007645a4  8bf1                 mov esi, ecx
// 007645a6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007645aa  57                   push edi
// 007645ab  7521                 jne 0x7645ce
// 007645ad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007645b1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007645b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007645b8  50                   push eax
// 007645b9  51                   push ecx
// 007645ba  6a01                 push 1
// 007645bc  57                   push edi
// 007645bd  8bce                 mov ecx, esi
// 007645bf  e89ce8ffff           call 0x762e60
// 007645c4  8bc7                 mov eax, edi
// 007645c6  5f                   pop edi
// 007645c7  5e                   pop esi
// 007645c8  83c414               add esp, 0x14
// 007645cb  c21000               ret 0x10
// 007645ce  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007645d2  8b5618               mov edx, dword ptr [esi + 0x18]
// 007645d5  8b3a                 mov edi, dword ptr [edx]
// 007645d7  8b06                 mov eax, dword ptr [esi]
// 007645d9  53                   push ebx
// 007645da  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007645e0  85c9                 test ecx, ecx
// 007645e2  7404                 je 0x7645e8
// 007645e4  3bc8                 cmp ecx, eax
// 007645e6  7406                 je 0x7645ee
// 007645e8  ffd3                 call ebx
// 007645ea  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007645ee  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007645f2  3bc7                 cmp eax, edi
// 007645f4  752a                 jne 0x764620
// 007645f6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007645fa  8b0f                 mov ecx, dword ptr [edi]
// 007645fc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007645ff  0f8d4b010000         jge 0x764750
// 00764605  57                   push edi
// 00764606  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0076460a  50                   push eax
// 0076460b  6a01                 push 1
// 0076460d  57                   push edi
// 0076460e  8bce                 mov ecx, esi
// 00764610  e84be8ffff           call 0x762e60
// 00764615  5b                   pop ebx
// 00764616  8bc7                 mov eax, edi
// 00764618  5f                   pop edi
// 00764619  5e                   pop esi
// 0076461a  83c414               add esp, 0x14
// 0076461d  c21000               ret 0x10
// 00764620  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00764623  8b16                 mov edx, dword ptr [esi]
// 00764625  85c9                 test ecx, ecx
// 00764627  7404                 je 0x76462d
// 00764629  3bca                 cmp ecx, edx
// 0076462b  740a                 je 0x764637
// 0076462d  ffd3                 call ebx
// 0076462f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00764633  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00764637  3bc7                 cmp eax, edi
// 00764639  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0076463d  752c                 jne 0x76466b
// 0076463f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00764642  8b4208               mov eax, dword ptr [edx + 8]
// 00764645  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00764648  3b0f                 cmp ecx, dword ptr [edi]
// 0076464a  0f8d00010000         jge 0x764750
// 00764650  57                   push edi
// 00764651  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00764655  50                   push eax
// 00764656  6a00                 push 0
// 00764658  57                   push edi
// 00764659  8bce                 mov ecx, esi
// 0076465b  e800e8ffff           call 0x762e60
// 00764660  5b                   pop ebx
// 00764661  8bc7                 mov eax, edi
// 00764663  5f                   pop edi
// 00764664  5e                   pop esi
// 00764665  83c414               add esp, 0x14
// 00764668  c21000               ret 0x10
// 0076466b  8b17                 mov edx, dword ptr [edi]
// 0076466d  39500c               cmp dword ptr [eax + 0xc], edx
// 00764670  7e63                 jle 0x7646d5
// 00764672  894c240c             mov dword ptr [esp + 0xc], ecx
// 00764676  8d4c240c             lea ecx, [esp + 0xc]
// 0076467a  89442410             mov dword ptr [esp + 0x10], eax
// 0076467e  e8ddf1daff           call 0x513860
// 00764683  8b17                 mov edx, dword ptr [edi]
// 00764685  8b442410             mov eax, dword ptr [esp + 0x10]
// 00764689  39500c               cmp dword ptr [eax + 0xc], edx
// 0076468c  7d3c                 jge 0x7646ca
// 0076468e  8b5008               mov edx, dword ptr [eax + 8]
// 00764691  807a3100             cmp byte ptr [edx + 0x31], 0
// 00764695  57                   push edi
// 00764696  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0076469a  8bce                 mov ecx, esi
// 0076469c  7414                 je 0x7646b2
// 0076469e  50                   push eax
// 0076469f  6a00                 push 0
// 007646a1  57                   push edi
// 007646a2  e8b9e7ffff           call 0x762e60
// 007646a7  5b                   pop ebx
// 007646a8  8bc7                 mov eax, edi
// 007646aa  5f                   pop edi
// 007646ab  5e                   pop esi
// 007646ac  83c414               add esp, 0x14
// 007646af  c21000               ret 0x10
// 007646b2  8b442430             mov eax, dword ptr [esp + 0x30]
// 007646b6  50                   push eax
// 007646b7  6a01                 push 1
// 007646b9  57                   push edi
// 007646ba  e8a1e7ffff           call 0x762e60
// 007646bf  5b                   pop ebx
// 007646c0  8bc7                 mov eax, edi
// 007646c2  5f                   pop edi
// 007646c3  5e                   pop esi
// 007646c4  83c414               add esp, 0x14
// 007646c7  c21000               ret 0x10
// 007646ca  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007646ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007646d2  39500c               cmp dword ptr [eax + 0xc], edx
// 007646d5  7d79                 jge 0x764750
// 007646d7  8b16                 mov edx, dword ptr [esi]
// 007646d9  894c240c             mov dword ptr [esp + 0xc], ecx
// 007646dd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007646e0  894c2418             mov dword ptr [esp + 0x18], ecx
// 007646e4  8d4c240c             lea ecx, [esp + 0xc]
// 007646e8  89442410             mov dword ptr [esp + 0x10], eax
// 007646ec  89542414             mov dword ptr [esp + 0x14], edx
// 007646f0  e8fbf1daff           call 0x5138f0
// 007646f5  8d442414             lea eax, [esp + 0x14]
// 007646f9  50                   push eax
// 007646fa  8d4c2410             lea ecx, [esp + 0x10]
// 007646fe  e85d7ce6ff           call 0x5cc360
// 00764703  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00764707  84c0                 test al, al
// 00764709  7507                 jne 0x764712
// 0076470b  8b17                 mov edx, dword ptr [edi]
// 0076470d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00764710  7d3e                 jge 0x764750
// 00764712  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00764716  8b5008               mov edx, dword ptr [eax + 8]
// 00764719  807a3100             cmp byte ptr [edx + 0x31], 0
// 0076471d  57                   push edi
// 0076471e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00764722  7416                 je 0x76473a
// 00764724  50                   push eax
// 00764725  6a00                 push 0
// 00764727  57                   push edi
// 00764728  8bce                 mov ecx, esi
// 0076472a  e831e7ffff           call 0x762e60
// 0076472f  5b                   pop ebx
// 00764730  8bc7                 mov eax, edi
// 00764732  5f                   pop edi
// 00764733  5e                   pop esi
// 00764734  83c414               add esp, 0x14
// 00764737  c21000               ret 0x10
// 0076473a  51                   push ecx
// 0076473b  6a01                 push 1
// 0076473d  57                   push edi
// 0076473e  8bce                 mov ecx, esi
// 00764740  e81be7ffff           call 0x762e60
// 00764745  5b                   pop ebx
// 00764746  8bc7                 mov eax, edi
// 00764748  5f                   pop edi
// 00764749  5e                   pop esi
// 0076474a  83c414               add esp, 0x14
// 0076474d  c21000               ret 0x10
// 00764750  57                   push edi
// 00764751  8d442418             lea eax, [esp + 0x18]
// 00764755  50                   push eax
// 00764756  8bce                 mov ecx, esi
// 00764758  e853f6ffff           call 0x763db0
// 0076475d  8b10                 mov edx, dword ptr [eax]
// 0076475f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00764763  5b                   pop ebx
// 00764764  8911                 mov dword ptr [ecx], edx
// 00764766  8b4004               mov eax, dword ptr [eax + 4]
// 00764769  5f                   pop edi
// 0076476a  894104               mov dword ptr [ecx + 4], eax
// 0076476d  8bc1                 mov eax, ecx
// 0076476f  5e                   pop esi
// 00764770  83c414               add esp, 0x14
// 00764773  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
