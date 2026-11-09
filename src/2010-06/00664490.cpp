// from server: 100% by auto
// roc 2010-06 00664490  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00664490
//
// 00664490  83ec14               sub esp, 0x14
// 00664493  56                   push esi
// 00664494  8bf1                 mov esi, ecx
// 00664496  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0066449a  57                   push edi
// 0066449b  7521                 jne 0x6644be
// 0066449d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006644a1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006644a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006644a8  50                   push eax
// 006644a9  51                   push ecx
// 006644aa  6a01                 push 1
// 006644ac  57                   push edi
// 006644ad  8bce                 mov ecx, esi
// 006644af  e82cf0ffff           call 0x6634e0
// 006644b4  8bc7                 mov eax, edi
// 006644b6  5f                   pop edi
// 006644b7  5e                   pop esi
// 006644b8  83c414               add esp, 0x14
// 006644bb  c21000               ret 0x10
// 006644be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006644c2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006644c5  8b3a                 mov edi, dword ptr [edx]
// 006644c7  8b06                 mov eax, dword ptr [esi]
// 006644c9  53                   push ebx
// 006644ca  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006644d0  85c9                 test ecx, ecx
// 006644d2  7404                 je 0x6644d8
// 006644d4  3bc8                 cmp ecx, eax
// 006644d6  7406                 je 0x6644de
// 006644d8  ffd3                 call ebx
// 006644da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006644de  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006644e2  3bc7                 cmp eax, edi
// 006644e4  752a                 jne 0x664510
// 006644e6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006644ea  8b0f                 mov ecx, dword ptr [edi]
// 006644ec  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006644ef  0f8d4b010000         jge 0x664640
// 006644f5  57                   push edi
// 006644f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006644fa  50                   push eax
// 006644fb  6a01                 push 1
// 006644fd  57                   push edi
// 006644fe  8bce                 mov ecx, esi
// 00664500  e8dbefffff           call 0x6634e0
// 00664505  5b                   pop ebx
// 00664506  8bc7                 mov eax, edi
// 00664508  5f                   pop edi
// 00664509  5e                   pop esi
// 0066450a  83c414               add esp, 0x14
// 0066450d  c21000               ret 0x10
// 00664510  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00664513  8b16                 mov edx, dword ptr [esi]
// 00664515  85c9                 test ecx, ecx
// 00664517  7404                 je 0x66451d
// 00664519  3bca                 cmp ecx, edx
// 0066451b  740a                 je 0x664527
// 0066451d  ffd3                 call ebx
// 0066451f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00664523  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00664527  3bc7                 cmp eax, edi
// 00664529  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0066452d  752c                 jne 0x66455b
// 0066452f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00664532  8b4208               mov eax, dword ptr [edx + 8]
// 00664535  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00664538  3b0f                 cmp ecx, dword ptr [edi]
// 0066453a  0f8d00010000         jge 0x664640
// 00664540  57                   push edi
// 00664541  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00664545  50                   push eax
// 00664546  6a00                 push 0
// 00664548  57                   push edi
// 00664549  8bce                 mov ecx, esi
// 0066454b  e890efffff           call 0x6634e0
// 00664550  5b                   pop ebx
// 00664551  8bc7                 mov eax, edi
// 00664553  5f                   pop edi
// 00664554  5e                   pop esi
// 00664555  83c414               add esp, 0x14
// 00664558  c21000               ret 0x10
// 0066455b  8b17                 mov edx, dword ptr [edi]
// 0066455d  39500c               cmp dword ptr [eax + 0xc], edx
// 00664560  7e63                 jle 0x6645c5
// 00664562  894c240c             mov dword ptr [esp + 0xc], ecx
// 00664566  8d4c240c             lea ecx, [esp + 0xc]
// 0066456a  89442410             mov dword ptr [esp + 0x10], eax
// 0066456e  e86defe0ff           call 0x4734e0
// 00664573  8b17                 mov edx, dword ptr [edi]
// 00664575  8b442410             mov eax, dword ptr [esp + 0x10]
// 00664579  39500c               cmp dword ptr [eax + 0xc], edx
// 0066457c  7d3c                 jge 0x6645ba
// 0066457e  8b5008               mov edx, dword ptr [eax + 8]
// 00664581  807a3100             cmp byte ptr [edx + 0x31], 0
// 00664585  57                   push edi
// 00664586  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0066458a  8bce                 mov ecx, esi
// 0066458c  7414                 je 0x6645a2
// 0066458e  50                   push eax
// 0066458f  6a00                 push 0
// 00664591  57                   push edi
// 00664592  e849efffff           call 0x6634e0
// 00664597  5b                   pop ebx
// 00664598  8bc7                 mov eax, edi
// 0066459a  5f                   pop edi
// 0066459b  5e                   pop esi
// 0066459c  83c414               add esp, 0x14
// 0066459f  c21000               ret 0x10
// 006645a2  8b442430             mov eax, dword ptr [esp + 0x30]
// 006645a6  50                   push eax
// 006645a7  6a01                 push 1
// 006645a9  57                   push edi
// 006645aa  e831efffff           call 0x6634e0
// 006645af  5b                   pop ebx
// 006645b0  8bc7                 mov eax, edi
// 006645b2  5f                   pop edi
// 006645b3  5e                   pop esi
// 006645b4  83c414               add esp, 0x14
// 006645b7  c21000               ret 0x10
// 006645ba  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006645be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006645c2  39500c               cmp dword ptr [eax + 0xc], edx
// 006645c5  7d79                 jge 0x664640
// 006645c7  8b16                 mov edx, dword ptr [esi]
// 006645c9  894c240c             mov dword ptr [esp + 0xc], ecx
// 006645cd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006645d0  894c2418             mov dword ptr [esp + 0x18], ecx
// 006645d4  8d4c240c             lea ecx, [esp + 0xc]
// 006645d8  89442410             mov dword ptr [esp + 0x10], eax
// 006645dc  89542414             mov dword ptr [esp + 0x14], edx
// 006645e0  e8cbaeffff           call 0x65f4b0
// 006645e5  8d442414             lea eax, [esp + 0x14]
// 006645e9  50                   push eax
// 006645ea  8d4c2410             lea ecx, [esp + 0x10]
// 006645ee  e88d29e0ff           call 0x466f80
// 006645f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006645f7  84c0                 test al, al
// 006645f9  7507                 jne 0x664602
// 006645fb  8b17                 mov edx, dword ptr [edi]
// 006645fd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00664600  7d3e                 jge 0x664640
// 00664602  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00664606  8b5008               mov edx, dword ptr [eax + 8]
// 00664609  807a3100             cmp byte ptr [edx + 0x31], 0
// 0066460d  57                   push edi
// 0066460e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00664612  7416                 je 0x66462a
// 00664614  50                   push eax
// 00664615  6a00                 push 0
// 00664617  57                   push edi
// 00664618  8bce                 mov ecx, esi
// 0066461a  e8c1eeffff           call 0x6634e0
// 0066461f  5b                   pop ebx
// 00664620  8bc7                 mov eax, edi
// 00664622  5f                   pop edi
// 00664623  5e                   pop esi
// 00664624  83c414               add esp, 0x14
// 00664627  c21000               ret 0x10
// 0066462a  51                   push ecx
// 0066462b  6a01                 push 1
// 0066462d  57                   push edi
// 0066462e  8bce                 mov ecx, esi
// 00664630  e8abeeffff           call 0x6634e0
// 00664635  5b                   pop ebx
// 00664636  8bc7                 mov eax, edi
// 00664638  5f                   pop edi
// 00664639  5e                   pop esi
// 0066463a  83c414               add esp, 0x14
// 0066463d  c21000               ret 0x10
// 00664640  57                   push edi
// 00664641  8d442418             lea eax, [esp + 0x18]
// 00664645  50                   push eax
// 00664646  8bce                 mov ecx, esi
// 00664648  e893f6ffff           call 0x663ce0
// 0066464d  8b10                 mov edx, dword ptr [eax]
// 0066464f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00664653  5b                   pop ebx
// 00664654  8911                 mov dword ptr [ecx], edx
// 00664656  8b4004               mov eax, dword ptr [eax + 4]
// 00664659  5f                   pop edi
// 0066465a  894104               mov dword ptr [ecx + 4], eax
// 0066465d  8bc1                 mov eax, ecx
// 0066465f  5e                   pop esi
// 00664660  83c414               add esp, 0x14
// 00664663  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
