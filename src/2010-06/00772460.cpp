// from server: 100% by auto
// roc 2010-06 00772460  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00772460
//
// 00772460  83ec14               sub esp, 0x14
// 00772463  56                   push esi
// 00772464  8bf1                 mov esi, ecx
// 00772466  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0077246a  57                   push edi
// 0077246b  7521                 jne 0x77248e
// 0077246d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00772471  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00772474  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772478  50                   push eax
// 00772479  51                   push ecx
// 0077247a  6a01                 push 1
// 0077247c  57                   push edi
// 0077247d  8bce                 mov ecx, esi
// 0077247f  e87ce9ffff           call 0x770e00
// 00772484  8bc7                 mov eax, edi
// 00772486  5f                   pop edi
// 00772487  5e                   pop esi
// 00772488  83c414               add esp, 0x14
// 0077248b  c21000               ret 0x10
// 0077248e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00772492  8b5618               mov edx, dword ptr [esi + 0x18]
// 00772495  8b3a                 mov edi, dword ptr [edx]
// 00772497  8b06                 mov eax, dword ptr [esi]
// 00772499  53                   push ebx
// 0077249a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 007724a0  85c9                 test ecx, ecx
// 007724a2  7404                 je 0x7724a8
// 007724a4  3bc8                 cmp ecx, eax
// 007724a6  7406                 je 0x7724ae
// 007724a8  ffd3                 call ebx
// 007724aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007724ae  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007724b2  3bc7                 cmp eax, edi
// 007724b4  752a                 jne 0x7724e0
// 007724b6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007724ba  8b0f                 mov ecx, dword ptr [edi]
// 007724bc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007724bf  0f834b010000         jae 0x772610
// 007724c5  57                   push edi
// 007724c6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007724ca  50                   push eax
// 007724cb  6a01                 push 1
// 007724cd  57                   push edi
// 007724ce  8bce                 mov ecx, esi
// 007724d0  e82be9ffff           call 0x770e00
// 007724d5  5b                   pop ebx
// 007724d6  8bc7                 mov eax, edi
// 007724d8  5f                   pop edi
// 007724d9  5e                   pop esi
// 007724da  83c414               add esp, 0x14
// 007724dd  c21000               ret 0x10
// 007724e0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007724e3  8b16                 mov edx, dword ptr [esi]
// 007724e5  85c9                 test ecx, ecx
// 007724e7  7404                 je 0x7724ed
// 007724e9  3bca                 cmp ecx, edx
// 007724eb  740a                 je 0x7724f7
// 007724ed  ffd3                 call ebx
// 007724ef  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007724f3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007724f7  3bc7                 cmp eax, edi
// 007724f9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007724fd  752c                 jne 0x77252b
// 007724ff  8b5618               mov edx, dword ptr [esi + 0x18]
// 00772502  8b4208               mov eax, dword ptr [edx + 8]
// 00772505  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00772508  3b0f                 cmp ecx, dword ptr [edi]
// 0077250a  0f8300010000         jae 0x772610
// 00772510  57                   push edi
// 00772511  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00772515  50                   push eax
// 00772516  6a00                 push 0
// 00772518  57                   push edi
// 00772519  8bce                 mov ecx, esi
// 0077251b  e8e0e8ffff           call 0x770e00
// 00772520  5b                   pop ebx
// 00772521  8bc7                 mov eax, edi
// 00772523  5f                   pop edi
// 00772524  5e                   pop esi
// 00772525  83c414               add esp, 0x14
// 00772528  c21000               ret 0x10
// 0077252b  8b17                 mov edx, dword ptr [edi]
// 0077252d  39500c               cmp dword ptr [eax + 0xc], edx
// 00772530  7663                 jbe 0x772595
// 00772532  894c240c             mov dword ptr [esp + 0xc], ecx
// 00772536  8d4c240c             lea ecx, [esp + 0xc]
// 0077253a  89442410             mov dword ptr [esp + 0x10], eax
// 0077253e  e89d0fd0ff           call 0x4734e0
// 00772543  8b17                 mov edx, dword ptr [edi]
// 00772545  8b442410             mov eax, dword ptr [esp + 0x10]
// 00772549  39500c               cmp dword ptr [eax + 0xc], edx
// 0077254c  733c                 jae 0x77258a
// 0077254e  8b5008               mov edx, dword ptr [eax + 8]
// 00772551  807a3100             cmp byte ptr [edx + 0x31], 0
// 00772555  57                   push edi
// 00772556  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0077255a  8bce                 mov ecx, esi
// 0077255c  7414                 je 0x772572
// 0077255e  50                   push eax
// 0077255f  6a00                 push 0
// 00772561  57                   push edi
// 00772562  e899e8ffff           call 0x770e00
// 00772567  5b                   pop ebx
// 00772568  8bc7                 mov eax, edi
// 0077256a  5f                   pop edi
// 0077256b  5e                   pop esi
// 0077256c  83c414               add esp, 0x14
// 0077256f  c21000               ret 0x10
// 00772572  8b442430             mov eax, dword ptr [esp + 0x30]
// 00772576  50                   push eax
// 00772577  6a01                 push 1
// 00772579  57                   push edi
// 0077257a  e881e8ffff           call 0x770e00
// 0077257f  5b                   pop ebx
// 00772580  8bc7                 mov eax, edi
// 00772582  5f                   pop edi
// 00772583  5e                   pop esi
// 00772584  83c414               add esp, 0x14
// 00772587  c21000               ret 0x10
// 0077258a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0077258e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00772592  39500c               cmp dword ptr [eax + 0xc], edx
// 00772595  7379                 jae 0x772610
// 00772597  8b16                 mov edx, dword ptr [esi]
// 00772599  894c240c             mov dword ptr [esp + 0xc], ecx
// 0077259d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007725a0  894c2418             mov dword ptr [esp + 0x18], ecx
// 007725a4  8d4c240c             lea ecx, [esp + 0xc]
// 007725a8  89442410             mov dword ptr [esp + 0x10], eax
// 007725ac  89542414             mov dword ptr [esp + 0x14], edx
// 007725b0  e8fbceeeff           call 0x65f4b0
// 007725b5  8d442414             lea eax, [esp + 0x14]
// 007725b9  50                   push eax
// 007725ba  8d4c2410             lea ecx, [esp + 0x10]
// 007725be  e8bd49cfff           call 0x466f80
// 007725c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007725c7  84c0                 test al, al
// 007725c9  7507                 jne 0x7725d2
// 007725cb  8b17                 mov edx, dword ptr [edi]
// 007725cd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007725d0  733e                 jae 0x772610
// 007725d2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007725d6  8b5008               mov edx, dword ptr [eax + 8]
// 007725d9  807a3100             cmp byte ptr [edx + 0x31], 0
// 007725dd  57                   push edi
// 007725de  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007725e2  7416                 je 0x7725fa
// 007725e4  50                   push eax
// 007725e5  6a00                 push 0
// 007725e7  57                   push edi
// 007725e8  8bce                 mov ecx, esi
// 007725ea  e811e8ffff           call 0x770e00
// 007725ef  5b                   pop ebx
// 007725f0  8bc7                 mov eax, edi
// 007725f2  5f                   pop edi
// 007725f3  5e                   pop esi
// 007725f4  83c414               add esp, 0x14
// 007725f7  c21000               ret 0x10
// 007725fa  51                   push ecx
// 007725fb  6a01                 push 1
// 007725fd  57                   push edi
// 007725fe  8bce                 mov ecx, esi
// 00772600  e8fbe7ffff           call 0x770e00
// 00772605  5b                   pop ebx
// 00772606  8bc7                 mov eax, edi
// 00772608  5f                   pop edi
// 00772609  5e                   pop esi
// 0077260a  83c414               add esp, 0x14
// 0077260d  c21000               ret 0x10
// 00772610  57                   push edi
// 00772611  8d442418             lea eax, [esp + 0x18]
// 00772615  50                   push eax
// 00772616  8bce                 mov ecx, esi
// 00772618  e8e3f2ffff           call 0x771900
// 0077261d  8b10                 mov edx, dword ptr [eax]
// 0077261f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00772623  5b                   pop ebx
// 00772624  8911                 mov dword ptr [ecx], edx
// 00772626  8b4004               mov eax, dword ptr [eax + 4]
// 00772629  5f                   pop edi
// 0077262a  894104               mov dword ptr [ecx + 4], eax
// 0077262d  8bc1                 mov eax, ecx
// 0077262f  5e                   pop esi
// 00772630  83c414               add esp, 0x14
// 00772633  c21000               ret 0x10
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
