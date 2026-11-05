// from server: 100% by auto
// roc 2009-06 0063f7e0  unit: RBX::Accoutrement  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f7e0
//
// 0063f7e0  83ec14               sub esp, 0x14
// 0063f7e3  56                   push esi
// 0063f7e4  8bf1                 mov esi, ecx
// 0063f7e6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0063f7ea  57                   push edi
// 0063f7eb  7521                 jne 0x63f80e
// 0063f7ed  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0063f7f1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063f7f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063f7f8  50                   push eax
// 0063f7f9  51                   push ecx
// 0063f7fa  6a01                 push 1
// 0063f7fc  57                   push edi
// 0063f7fd  8bce                 mov ecx, esi
// 0063f7ff  e80cf4ffff           call 0x63ec10
// 0063f804  8bc7                 mov eax, edi
// 0063f806  5f                   pop edi
// 0063f807  5e                   pop esi
// 0063f808  83c414               add esp, 0x14
// 0063f80b  c21000               ret 0x10
// 0063f80e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0063f812  8b5618               mov edx, dword ptr [esi + 0x18]
// 0063f815  8b3a                 mov edi, dword ptr [edx]
// 0063f817  8b06                 mov eax, dword ptr [esi]
// 0063f819  53                   push ebx
// 0063f81a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 0063f820  85c9                 test ecx, ecx
// 0063f822  7404                 je 0x63f828
// 0063f824  3bc8                 cmp ecx, eax
// 0063f826  7406                 je 0x63f82e
// 0063f828  ffd3                 call ebx
// 0063f82a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0063f82e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0063f832  3bc7                 cmp eax, edi
// 0063f834  752a                 jne 0x63f860
// 0063f836  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0063f83a  8b0f                 mov ecx, dword ptr [edi]
// 0063f83c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0063f83f  0f8d4b010000         jge 0x63f990
// 0063f845  57                   push edi
// 0063f846  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0063f84a  50                   push eax
// 0063f84b  6a01                 push 1
// 0063f84d  57                   push edi
// 0063f84e  8bce                 mov ecx, esi
// 0063f850  e8bbf3ffff           call 0x63ec10
// 0063f855  5b                   pop ebx
// 0063f856  8bc7                 mov eax, edi
// 0063f858  5f                   pop edi
// 0063f859  5e                   pop esi
// 0063f85a  83c414               add esp, 0x14
// 0063f85d  c21000               ret 0x10
// 0063f860  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0063f863  8b16                 mov edx, dword ptr [esi]
// 0063f865  85c9                 test ecx, ecx
// 0063f867  7404                 je 0x63f86d
// 0063f869  3bca                 cmp ecx, edx
// 0063f86b  740a                 je 0x63f877
// 0063f86d  ffd3                 call ebx
// 0063f86f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0063f873  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0063f877  3bc7                 cmp eax, edi
// 0063f879  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0063f87d  752c                 jne 0x63f8ab
// 0063f87f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0063f882  8b4208               mov eax, dword ptr [edx + 8]
// 0063f885  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0063f888  3b0f                 cmp ecx, dword ptr [edi]
// 0063f88a  0f8d00010000         jge 0x63f990
// 0063f890  57                   push edi
// 0063f891  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0063f895  50                   push eax
// 0063f896  6a00                 push 0
// 0063f898  57                   push edi
// 0063f899  8bce                 mov ecx, esi
// 0063f89b  e870f3ffff           call 0x63ec10
// 0063f8a0  5b                   pop ebx
// 0063f8a1  8bc7                 mov eax, edi
// 0063f8a3  5f                   pop edi
// 0063f8a4  5e                   pop esi
// 0063f8a5  83c414               add esp, 0x14
// 0063f8a8  c21000               ret 0x10
// 0063f8ab  8b17                 mov edx, dword ptr [edi]
// 0063f8ad  39500c               cmp dword ptr [eax + 0xc], edx
// 0063f8b0  7e63                 jle 0x63f915
// 0063f8b2  894c240c             mov dword ptr [esp + 0xc], ecx
// 0063f8b6  8d4c240c             lea ecx, [esp + 0xc]
// 0063f8ba  89442410             mov dword ptr [esp + 0x10], eax
// 0063f8be  e8cd7eedff           call 0x517790
// 0063f8c3  8b17                 mov edx, dword ptr [edi]
// 0063f8c5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0063f8c9  39500c               cmp dword ptr [eax + 0xc], edx
// 0063f8cc  7d3c                 jge 0x63f90a
// 0063f8ce  8b5008               mov edx, dword ptr [eax + 8]
// 0063f8d1  807a2100             cmp byte ptr [edx + 0x21], 0
// 0063f8d5  57                   push edi
// 0063f8d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0063f8da  8bce                 mov ecx, esi
// 0063f8dc  7414                 je 0x63f8f2
// 0063f8de  50                   push eax
// 0063f8df  6a00                 push 0
// 0063f8e1  57                   push edi
// 0063f8e2  e829f3ffff           call 0x63ec10
// 0063f8e7  5b                   pop ebx
// 0063f8e8  8bc7                 mov eax, edi
// 0063f8ea  5f                   pop edi
// 0063f8eb  5e                   pop esi
// 0063f8ec  83c414               add esp, 0x14
// 0063f8ef  c21000               ret 0x10
// 0063f8f2  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063f8f6  50                   push eax
// 0063f8f7  6a01                 push 1
// 0063f8f9  57                   push edi
// 0063f8fa  e811f3ffff           call 0x63ec10
// 0063f8ff  5b                   pop ebx
// 0063f900  8bc7                 mov eax, edi
// 0063f902  5f                   pop edi
// 0063f903  5e                   pop esi
// 0063f904  83c414               add esp, 0x14
// 0063f907  c21000               ret 0x10
// 0063f90a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0063f90e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0063f912  39500c               cmp dword ptr [eax + 0xc], edx
// 0063f915  7d79                 jge 0x63f990
// 0063f917  8b16                 mov edx, dword ptr [esi]
// 0063f919  894c240c             mov dword ptr [esp + 0xc], ecx
// 0063f91d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063f920  894c2418             mov dword ptr [esp + 0x18], ecx
// 0063f924  8d4c240c             lea ecx, [esp + 0xc]
// 0063f928  89442410             mov dword ptr [esp + 0x10], eax
// 0063f92c  89542414             mov dword ptr [esp + 0x14], edx
// 0063f930  e8db71edff           call 0x516b10
// 0063f935  8d442414             lea eax, [esp + 0x14]
// 0063f939  50                   push eax
// 0063f93a  8d4c2410             lea ecx, [esp + 0x10]
// 0063f93e  e85d3b0000           call 0x6434a0
// 0063f943  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f947  84c0                 test al, al
// 0063f949  7507                 jne 0x63f952
// 0063f94b  8b17                 mov edx, dword ptr [edi]
// 0063f94d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0063f950  7d3e                 jge 0x63f990
// 0063f952  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0063f956  8b5008               mov edx, dword ptr [eax + 8]
// 0063f959  807a2100             cmp byte ptr [edx + 0x21], 0
// 0063f95d  57                   push edi
// 0063f95e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0063f962  7416                 je 0x63f97a
// 0063f964  50                   push eax
// 0063f965  6a00                 push 0
// 0063f967  57                   push edi
// 0063f968  8bce                 mov ecx, esi
// 0063f96a  e8a1f2ffff           call 0x63ec10
// 0063f96f  5b                   pop ebx
// 0063f970  8bc7                 mov eax, edi
// 0063f972  5f                   pop edi
// 0063f973  5e                   pop esi
// 0063f974  83c414               add esp, 0x14
// 0063f977  c21000               ret 0x10
// 0063f97a  51                   push ecx
// 0063f97b  6a01                 push 1
// 0063f97d  57                   push edi
// 0063f97e  8bce                 mov ecx, esi
// 0063f980  e88bf2ffff           call 0x63ec10
// 0063f985  5b                   pop ebx
// 0063f986  8bc7                 mov eax, edi
// 0063f988  5f                   pop edi
// 0063f989  5e                   pop esi
// 0063f98a  83c414               add esp, 0x14
// 0063f98d  c21000               ret 0x10
// 0063f990  57                   push edi
// 0063f991  8d442418             lea eax, [esp + 0x18]
// 0063f995  50                   push eax
// 0063f996  8bce                 mov ecx, esi
// 0063f998  e813fbffff           call 0x63f4b0
// 0063f99d  8b10                 mov edx, dword ptr [eax]
// 0063f99f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0063f9a3  5b                   pop ebx
// 0063f9a4  8911                 mov dword ptr [ecx], edx
// 0063f9a6  8b4004               mov eax, dword ptr [eax + 4]
// 0063f9a9  5f                   pop edi
// 0063f9aa  894104               mov dword ptr [ecx + 4], eax
// 0063f9ad  8bc1                 mov eax, ecx
// 0063f9af  5e                   pop esi
// 0063f9b0  83c414               add esp, 0x14
// 0063f9b3  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
