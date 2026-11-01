// from server: 100% by auto
// roc 2009-12 007c7960  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7960
//
// 007c7960  83ec14               sub esp, 0x14
// 007c7963  56                   push esi
// 007c7964  8bf1                 mov esi, ecx
// 007c7966  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007c796a  57                   push edi
// 007c796b  7521                 jne 0x7c798e
// 007c796d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c7971  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c7974  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c7978  50                   push eax
// 007c7979  51                   push ecx
// 007c797a  6a01                 push 1
// 007c797c  57                   push edi
// 007c797d  8bce                 mov ecx, esi
// 007c797f  e86cf4ffff           call 0x7c6df0
// 007c7984  8bc7                 mov eax, edi
// 007c7986  5f                   pop edi
// 007c7987  5e                   pop esi
// 007c7988  83c414               add esp, 0x14
// 007c798b  c21000               ret 0x10
// 007c798e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c7992  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c7995  8b3a                 mov edi, dword ptr [edx]
// 007c7997  8b06                 mov eax, dword ptr [esi]
// 007c7999  53                   push ebx
// 007c799a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007c79a0  85c9                 test ecx, ecx
// 007c79a2  7404                 je 0x7c79a8
// 007c79a4  3bc8                 cmp ecx, eax
// 007c79a6  7406                 je 0x7c79ae
// 007c79a8  ffd3                 call ebx
// 007c79aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c79ae  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c79b2  3bc7                 cmp eax, edi
// 007c79b4  752a                 jne 0x7c79e0
// 007c79b6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007c79ba  8b0f                 mov ecx, dword ptr [edi]
// 007c79bc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007c79bf  0f834b010000         jae 0x7c7b10
// 007c79c5  57                   push edi
// 007c79c6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c79ca  50                   push eax
// 007c79cb  6a01                 push 1
// 007c79cd  57                   push edi
// 007c79ce  8bce                 mov ecx, esi
// 007c79d0  e81bf4ffff           call 0x7c6df0
// 007c79d5  5b                   pop ebx
// 007c79d6  8bc7                 mov eax, edi
// 007c79d8  5f                   pop edi
// 007c79d9  5e                   pop esi
// 007c79da  83c414               add esp, 0x14
// 007c79dd  c21000               ret 0x10
// 007c79e0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007c79e3  8b16                 mov edx, dword ptr [esi]
// 007c79e5  85c9                 test ecx, ecx
// 007c79e7  7404                 je 0x7c79ed
// 007c79e9  3bca                 cmp ecx, edx
// 007c79eb  740a                 je 0x7c79f7
// 007c79ed  ffd3                 call ebx
// 007c79ef  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c79f3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c79f7  3bc7                 cmp eax, edi
// 007c79f9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007c79fd  752c                 jne 0x7c7a2b
// 007c79ff  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c7a02  8b4208               mov eax, dword ptr [edx + 8]
// 007c7a05  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007c7a08  3b0f                 cmp ecx, dword ptr [edi]
// 007c7a0a  0f8300010000         jae 0x7c7b10
// 007c7a10  57                   push edi
// 007c7a11  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c7a15  50                   push eax
// 007c7a16  6a00                 push 0
// 007c7a18  57                   push edi
// 007c7a19  8bce                 mov ecx, esi
// 007c7a1b  e8d0f3ffff           call 0x7c6df0
// 007c7a20  5b                   pop ebx
// 007c7a21  8bc7                 mov eax, edi
// 007c7a23  5f                   pop edi
// 007c7a24  5e                   pop esi
// 007c7a25  83c414               add esp, 0x14
// 007c7a28  c21000               ret 0x10
// 007c7a2b  8b17                 mov edx, dword ptr [edi]
// 007c7a2d  39500c               cmp dword ptr [eax + 0xc], edx
// 007c7a30  7663                 jbe 0x7c7a95
// 007c7a32  894c240c             mov dword ptr [esp + 0xc], ecx
// 007c7a36  8d4c240c             lea ecx, [esp + 0xc]
// 007c7a3a  89442410             mov dword ptr [esp + 0x10], eax
// 007c7a3e  e88d57e0ff           call 0x5cd1d0
// 007c7a43  8b17                 mov edx, dword ptr [edi]
// 007c7a45  8b442410             mov eax, dword ptr [esp + 0x10]
// 007c7a49  39500c               cmp dword ptr [eax + 0xc], edx
// 007c7a4c  733c                 jae 0x7c7a8a
// 007c7a4e  8b5008               mov edx, dword ptr [eax + 8]
// 007c7a51  807a2900             cmp byte ptr [edx + 0x29], 0
// 007c7a55  57                   push edi
// 007c7a56  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c7a5a  8bce                 mov ecx, esi
// 007c7a5c  7414                 je 0x7c7a72
// 007c7a5e  50                   push eax
// 007c7a5f  6a00                 push 0
// 007c7a61  57                   push edi
// 007c7a62  e889f3ffff           call 0x7c6df0
// 007c7a67  5b                   pop ebx
// 007c7a68  8bc7                 mov eax, edi
// 007c7a6a  5f                   pop edi
// 007c7a6b  5e                   pop esi
// 007c7a6c  83c414               add esp, 0x14
// 007c7a6f  c21000               ret 0x10
// 007c7a72  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c7a76  50                   push eax
// 007c7a77  6a01                 push 1
// 007c7a79  57                   push edi
// 007c7a7a  e871f3ffff           call 0x7c6df0
// 007c7a7f  5b                   pop ebx
// 007c7a80  8bc7                 mov eax, edi
// 007c7a82  5f                   pop edi
// 007c7a83  5e                   pop esi
// 007c7a84  83c414               add esp, 0x14
// 007c7a87  c21000               ret 0x10
// 007c7a8a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c7a8e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c7a92  39500c               cmp dword ptr [eax + 0xc], edx
// 007c7a95  7379                 jae 0x7c7b10
// 007c7a97  8b16                 mov edx, dword ptr [esi]
// 007c7a99  894c240c             mov dword ptr [esp + 0xc], ecx
// 007c7a9d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c7aa0  894c2418             mov dword ptr [esp + 0x18], ecx
// 007c7aa4  8d4c240c             lea ecx, [esp + 0xc]
// 007c7aa8  89442410             mov dword ptr [esp + 0x10], eax
// 007c7aac  89542414             mov dword ptr [esp + 0x14], edx
// 007c7ab0  e8ab57e0ff           call 0x5cd260
// 007c7ab5  8d442414             lea eax, [esp + 0x14]
// 007c7ab9  50                   push eax
// 007c7aba  8d4c2410             lea ecx, [esp + 0x10]
// 007c7abe  e89d48e0ff           call 0x5cc360
// 007c7ac3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c7ac7  84c0                 test al, al
// 007c7ac9  7507                 jne 0x7c7ad2
// 007c7acb  8b17                 mov edx, dword ptr [edi]
// 007c7acd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007c7ad0  733e                 jae 0x7c7b10
// 007c7ad2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c7ad6  8b5008               mov edx, dword ptr [eax + 8]
// 007c7ad9  807a2900             cmp byte ptr [edx + 0x29], 0
// 007c7add  57                   push edi
// 007c7ade  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c7ae2  7416                 je 0x7c7afa
// 007c7ae4  50                   push eax
// 007c7ae5  6a00                 push 0
// 007c7ae7  57                   push edi
// 007c7ae8  8bce                 mov ecx, esi
// 007c7aea  e801f3ffff           call 0x7c6df0
// 007c7aef  5b                   pop ebx
// 007c7af0  8bc7                 mov eax, edi
// 007c7af2  5f                   pop edi
// 007c7af3  5e                   pop esi
// 007c7af4  83c414               add esp, 0x14
// 007c7af7  c21000               ret 0x10
// 007c7afa  51                   push ecx
// 007c7afb  6a01                 push 1
// 007c7afd  57                   push edi
// 007c7afe  8bce                 mov ecx, esi
// 007c7b00  e8ebf2ffff           call 0x7c6df0
// 007c7b05  5b                   pop ebx
// 007c7b06  8bc7                 mov eax, edi
// 007c7b08  5f                   pop edi
// 007c7b09  5e                   pop esi
// 007c7b0a  83c414               add esp, 0x14
// 007c7b0d  c21000               ret 0x10
// 007c7b10  57                   push edi
// 007c7b11  8d442418             lea eax, [esp + 0x18]
// 007c7b15  50                   push eax
// 007c7b16  8bce                 mov ecx, esi
// 007c7b18  e823f8ffff           call 0x7c7340
// 007c7b1d  8b10                 mov edx, dword ptr [eax]
// 007c7b1f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c7b23  5b                   pop ebx
// 007c7b24  8911                 mov dword ptr [ecx], edx
// 007c7b26  8b4004               mov eax, dword ptr [eax + 4]
// 007c7b29  5f                   pop edi
// 007c7b2a  894104               mov dword ptr [ecx + 4], eax
// 007c7b2d  8bc1                 mov eax, ecx
// 007c7b2f  5e                   pop esi
// 007c7b30  83c414               add esp, 0x14
// 007c7b33  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
