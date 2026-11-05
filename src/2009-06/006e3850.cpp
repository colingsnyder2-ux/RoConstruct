// from server: 100% by auto
// roc 2009-06 006e3850  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3850
//
// 006e3850  83ec14               sub esp, 0x14
// 006e3853  56                   push esi
// 006e3854  8bf1                 mov esi, ecx
// 006e3856  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006e385a  57                   push edi
// 006e385b  7521                 jne 0x6e387e
// 006e385d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e3861  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e3864  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e3868  50                   push eax
// 006e3869  51                   push ecx
// 006e386a  6a01                 push 1
// 006e386c  57                   push edi
// 006e386d  8bce                 mov ecx, esi
// 006e386f  e87cf3ffff           call 0x6e2bf0
// 006e3874  8bc7                 mov eax, edi
// 006e3876  5f                   pop edi
// 006e3877  5e                   pop esi
// 006e3878  83c414               add esp, 0x14
// 006e387b  c21000               ret 0x10
// 006e387e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006e3882  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e3885  8b3a                 mov edi, dword ptr [edx]
// 006e3887  8b06                 mov eax, dword ptr [esi]
// 006e3889  53                   push ebx
// 006e388a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006e3890  85c9                 test ecx, ecx
// 006e3892  7404                 je 0x6e3898
// 006e3894  3bc8                 cmp ecx, eax
// 006e3896  7406                 je 0x6e389e
// 006e3898  ffd3                 call ebx
// 006e389a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e389e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e38a2  3bc7                 cmp eax, edi
// 006e38a4  752a                 jne 0x6e38d0
// 006e38a6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006e38aa  8b0f                 mov ecx, dword ptr [edi]
// 006e38ac  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006e38af  0f834b010000         jae 0x6e3a00
// 006e38b5  57                   push edi
// 006e38b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e38ba  50                   push eax
// 006e38bb  6a01                 push 1
// 006e38bd  57                   push edi
// 006e38be  8bce                 mov ecx, esi
// 006e38c0  e82bf3ffff           call 0x6e2bf0
// 006e38c5  5b                   pop ebx
// 006e38c6  8bc7                 mov eax, edi
// 006e38c8  5f                   pop edi
// 006e38c9  5e                   pop esi
// 006e38ca  83c414               add esp, 0x14
// 006e38cd  c21000               ret 0x10
// 006e38d0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006e38d3  8b16                 mov edx, dword ptr [esi]
// 006e38d5  85c9                 test ecx, ecx
// 006e38d7  7404                 je 0x6e38dd
// 006e38d9  3bca                 cmp ecx, edx
// 006e38db  740a                 je 0x6e38e7
// 006e38dd  ffd3                 call ebx
// 006e38df  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e38e3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e38e7  3bc7                 cmp eax, edi
// 006e38e9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006e38ed  752c                 jne 0x6e391b
// 006e38ef  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e38f2  8b4208               mov eax, dword ptr [edx + 8]
// 006e38f5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006e38f8  3b0f                 cmp ecx, dword ptr [edi]
// 006e38fa  0f8300010000         jae 0x6e3a00
// 006e3900  57                   push edi
// 006e3901  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e3905  50                   push eax
// 006e3906  6a00                 push 0
// 006e3908  57                   push edi
// 006e3909  8bce                 mov ecx, esi
// 006e390b  e8e0f2ffff           call 0x6e2bf0
// 006e3910  5b                   pop ebx
// 006e3911  8bc7                 mov eax, edi
// 006e3913  5f                   pop edi
// 006e3914  5e                   pop esi
// 006e3915  83c414               add esp, 0x14
// 006e3918  c21000               ret 0x10
// 006e391b  8b17                 mov edx, dword ptr [edi]
// 006e391d  39500c               cmp dword ptr [eax + 0xc], edx
// 006e3920  7663                 jbe 0x6e3985
// 006e3922  894c240c             mov dword ptr [esp + 0xc], ecx
// 006e3926  8d4c240c             lea ecx, [esp + 0xc]
// 006e392a  89442410             mov dword ptr [esp + 0x10], eax
// 006e392e  e8cd3de3ff           call 0x517700
// 006e3933  8b17                 mov edx, dword ptr [edi]
// 006e3935  8b442410             mov eax, dword ptr [esp + 0x10]
// 006e3939  39500c               cmp dword ptr [eax + 0xc], edx
// 006e393c  733c                 jae 0x6e397a
// 006e393e  8b5008               mov edx, dword ptr [eax + 8]
// 006e3941  807a2900             cmp byte ptr [edx + 0x29], 0
// 006e3945  57                   push edi
// 006e3946  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e394a  8bce                 mov ecx, esi
// 006e394c  7414                 je 0x6e3962
// 006e394e  50                   push eax
// 006e394f  6a00                 push 0
// 006e3951  57                   push edi
// 006e3952  e899f2ffff           call 0x6e2bf0
// 006e3957  5b                   pop ebx
// 006e3958  8bc7                 mov eax, edi
// 006e395a  5f                   pop edi
// 006e395b  5e                   pop esi
// 006e395c  83c414               add esp, 0x14
// 006e395f  c21000               ret 0x10
// 006e3962  8b442430             mov eax, dword ptr [esp + 0x30]
// 006e3966  50                   push eax
// 006e3967  6a01                 push 1
// 006e3969  57                   push edi
// 006e396a  e881f2ffff           call 0x6e2bf0
// 006e396f  5b                   pop ebx
// 006e3970  8bc7                 mov eax, edi
// 006e3972  5f                   pop edi
// 006e3973  5e                   pop esi
// 006e3974  83c414               add esp, 0x14
// 006e3977  c21000               ret 0x10
// 006e397a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e397e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e3982  39500c               cmp dword ptr [eax + 0xc], edx
// 006e3985  7379                 jae 0x6e3a00
// 006e3987  8b16                 mov edx, dword ptr [esi]
// 006e3989  894c240c             mov dword ptr [esp + 0xc], ecx
// 006e398d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e3990  894c2418             mov dword ptr [esp + 0x18], ecx
// 006e3994  8d4c240c             lea ecx, [esp + 0xc]
// 006e3998  89442410             mov dword ptr [esp + 0x10], eax
// 006e399c  89542414             mov dword ptr [esp + 0x14], edx
// 006e39a0  e8cb3ee3ff           call 0x517870
// 006e39a5  8d442414             lea eax, [esp + 0x14]
// 006e39a9  50                   push eax
// 006e39aa  8d4c2410             lea ecx, [esp + 0x10]
// 006e39ae  e8edfaf5ff           call 0x6434a0
// 006e39b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e39b7  84c0                 test al, al
// 006e39b9  7507                 jne 0x6e39c2
// 006e39bb  8b17                 mov edx, dword ptr [edi]
// 006e39bd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006e39c0  733e                 jae 0x6e3a00
// 006e39c2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e39c6  8b5008               mov edx, dword ptr [eax + 8]
// 006e39c9  807a2900             cmp byte ptr [edx + 0x29], 0
// 006e39cd  57                   push edi
// 006e39ce  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e39d2  7416                 je 0x6e39ea
// 006e39d4  50                   push eax
// 006e39d5  6a00                 push 0
// 006e39d7  57                   push edi
// 006e39d8  8bce                 mov ecx, esi
// 006e39da  e811f2ffff           call 0x6e2bf0
// 006e39df  5b                   pop ebx
// 006e39e0  8bc7                 mov eax, edi
// 006e39e2  5f                   pop edi
// 006e39e3  5e                   pop esi
// 006e39e4  83c414               add esp, 0x14
// 006e39e7  c21000               ret 0x10
// 006e39ea  51                   push ecx
// 006e39eb  6a01                 push 1
// 006e39ed  57                   push edi
// 006e39ee  8bce                 mov ecx, esi
// 006e39f0  e8fbf1ffff           call 0x6e2bf0
// 006e39f5  5b                   pop ebx
// 006e39f6  8bc7                 mov eax, edi
// 006e39f8  5f                   pop edi
// 006e39f9  5e                   pop esi
// 006e39fa  83c414               add esp, 0x14
// 006e39fd  c21000               ret 0x10
// 006e3a00  57                   push edi
// 006e3a01  8d442418             lea eax, [esp + 0x18]
// 006e3a05  50                   push eax
// 006e3a06  8bce                 mov ecx, esi
// 006e3a08  e833f7ffff           call 0x6e3140
// 006e3a0d  8b10                 mov edx, dword ptr [eax]
// 006e3a0f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006e3a13  5b                   pop ebx
// 006e3a14  8911                 mov dword ptr [ecx], edx
// 006e3a16  8b4004               mov eax, dword ptr [eax + 4]
// 006e3a19  5f                   pop edi
// 006e3a1a  894104               mov dword ptr [ecx + 4], eax
// 006e3a1d  8bc1                 mov eax, ecx
// 006e3a1f  5e                   pop esi
// 006e3a20  83c414               add esp, 0x14
// 006e3a23  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
