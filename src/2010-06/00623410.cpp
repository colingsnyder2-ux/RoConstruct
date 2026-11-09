// from server: 100% by auto
// roc 2010-06 00623410  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00623410
//
// 00623410  83ec14               sub esp, 0x14
// 00623413  56                   push esi
// 00623414  8bf1                 mov esi, ecx
// 00623416  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0062341a  57                   push edi
// 0062341b  7521                 jne 0x62343e
// 0062341d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00623421  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00623424  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00623428  50                   push eax
// 00623429  51                   push ecx
// 0062342a  6a01                 push 1
// 0062342c  57                   push edi
// 0062342d  8bce                 mov ecx, esi
// 0062342f  e8bc78ecff           call 0x4eacf0
// 00623434  8bc7                 mov eax, edi
// 00623436  5f                   pop edi
// 00623437  5e                   pop esi
// 00623438  83c414               add esp, 0x14
// 0062343b  c21000               ret 0x10
// 0062343e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00623442  8b5618               mov edx, dword ptr [esi + 0x18]
// 00623445  8b3a                 mov edi, dword ptr [edx]
// 00623447  8b06                 mov eax, dword ptr [esi]
// 00623449  53                   push ebx
// 0062344a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00623450  85c9                 test ecx, ecx
// 00623452  7404                 je 0x623458
// 00623454  3bc8                 cmp ecx, eax
// 00623456  7406                 je 0x62345e
// 00623458  ffd3                 call ebx
// 0062345a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0062345e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00623462  3bc7                 cmp eax, edi
// 00623464  752a                 jne 0x623490
// 00623466  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0062346a  8b0f                 mov ecx, dword ptr [edi]
// 0062346c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0062346f  0f8d4b010000         jge 0x6235c0
// 00623475  57                   push edi
// 00623476  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0062347a  50                   push eax
// 0062347b  6a01                 push 1
// 0062347d  57                   push edi
// 0062347e  8bce                 mov ecx, esi
// 00623480  e86b78ecff           call 0x4eacf0
// 00623485  5b                   pop ebx
// 00623486  8bc7                 mov eax, edi
// 00623488  5f                   pop edi
// 00623489  5e                   pop esi
// 0062348a  83c414               add esp, 0x14
// 0062348d  c21000               ret 0x10
// 00623490  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00623493  8b16                 mov edx, dword ptr [esi]
// 00623495  85c9                 test ecx, ecx
// 00623497  7404                 je 0x62349d
// 00623499  3bca                 cmp ecx, edx
// 0062349b  740a                 je 0x6234a7
// 0062349d  ffd3                 call ebx
// 0062349f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006234a3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006234a7  3bc7                 cmp eax, edi
// 006234a9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006234ad  752c                 jne 0x6234db
// 006234af  8b5618               mov edx, dword ptr [esi + 0x18]
// 006234b2  8b4208               mov eax, dword ptr [edx + 8]
// 006234b5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006234b8  3b0f                 cmp ecx, dword ptr [edi]
// 006234ba  0f8d00010000         jge 0x6235c0
// 006234c0  57                   push edi
// 006234c1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006234c5  50                   push eax
// 006234c6  6a00                 push 0
// 006234c8  57                   push edi
// 006234c9  8bce                 mov ecx, esi
// 006234cb  e82078ecff           call 0x4eacf0
// 006234d0  5b                   pop ebx
// 006234d1  8bc7                 mov eax, edi
// 006234d3  5f                   pop edi
// 006234d4  5e                   pop esi
// 006234d5  83c414               add esp, 0x14
// 006234d8  c21000               ret 0x10
// 006234db  8b17                 mov edx, dword ptr [edi]
// 006234dd  39500c               cmp dword ptr [eax + 0xc], edx
// 006234e0  7e63                 jle 0x623545
// 006234e2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006234e6  8d4c240c             lea ecx, [esp + 0xc]
// 006234ea  89442410             mov dword ptr [esp + 0x10], eax
// 006234ee  e8cd0de1ff           call 0x4342c0
// 006234f3  8b17                 mov edx, dword ptr [edi]
// 006234f5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006234f9  39500c               cmp dword ptr [eax + 0xc], edx
// 006234fc  7d3c                 jge 0x62353a
// 006234fe  8b5008               mov edx, dword ptr [eax + 8]
// 00623501  807a1900             cmp byte ptr [edx + 0x19], 0
// 00623505  57                   push edi
// 00623506  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0062350a  8bce                 mov ecx, esi
// 0062350c  7414                 je 0x623522
// 0062350e  50                   push eax
// 0062350f  6a00                 push 0
// 00623511  57                   push edi
// 00623512  e8d977ecff           call 0x4eacf0
// 00623517  5b                   pop ebx
// 00623518  8bc7                 mov eax, edi
// 0062351a  5f                   pop edi
// 0062351b  5e                   pop esi
// 0062351c  83c414               add esp, 0x14
// 0062351f  c21000               ret 0x10
// 00623522  8b442430             mov eax, dword ptr [esp + 0x30]
// 00623526  50                   push eax
// 00623527  6a01                 push 1
// 00623529  57                   push edi
// 0062352a  e8c177ecff           call 0x4eacf0
// 0062352f  5b                   pop ebx
// 00623530  8bc7                 mov eax, edi
// 00623532  5f                   pop edi
// 00623533  5e                   pop esi
// 00623534  83c414               add esp, 0x14
// 00623537  c21000               ret 0x10
// 0062353a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0062353e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00623542  39500c               cmp dword ptr [eax + 0xc], edx
// 00623545  7d79                 jge 0x6235c0
// 00623547  8b16                 mov edx, dword ptr [esi]
// 00623549  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062354d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00623550  894c2418             mov dword ptr [esp + 0x18], ecx
// 00623554  8d4c240c             lea ecx, [esp + 0xc]
// 00623558  89442410             mov dword ptr [esp + 0x10], eax
// 0062355c  89542414             mov dword ptr [esp + 0x14], edx
// 00623560  e8cb34ecff           call 0x4e6a30
// 00623565  8d442414             lea eax, [esp + 0x14]
// 00623569  50                   push eax
// 0062356a  8d4c2410             lea ecx, [esp + 0x10]
// 0062356e  e80d3ae4ff           call 0x466f80
// 00623573  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00623577  84c0                 test al, al
// 00623579  7507                 jne 0x623582
// 0062357b  8b17                 mov edx, dword ptr [edi]
// 0062357d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00623580  7d3e                 jge 0x6235c0
// 00623582  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00623586  8b5008               mov edx, dword ptr [eax + 8]
// 00623589  807a1900             cmp byte ptr [edx + 0x19], 0
// 0062358d  57                   push edi
// 0062358e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00623592  7416                 je 0x6235aa
// 00623594  50                   push eax
// 00623595  6a00                 push 0
// 00623597  57                   push edi
// 00623598  8bce                 mov ecx, esi
// 0062359a  e85177ecff           call 0x4eacf0
// 0062359f  5b                   pop ebx
// 006235a0  8bc7                 mov eax, edi
// 006235a2  5f                   pop edi
// 006235a3  5e                   pop esi
// 006235a4  83c414               add esp, 0x14
// 006235a7  c21000               ret 0x10
// 006235aa  51                   push ecx
// 006235ab  6a01                 push 1
// 006235ad  57                   push edi
// 006235ae  8bce                 mov ecx, esi
// 006235b0  e83b77ecff           call 0x4eacf0
// 006235b5  5b                   pop ebx
// 006235b6  8bc7                 mov eax, edi
// 006235b8  5f                   pop edi
// 006235b9  5e                   pop esi
// 006235ba  83c414               add esp, 0x14
// 006235bd  c21000               ret 0x10
// 006235c0  57                   push edi
// 006235c1  8d442418             lea eax, [esp + 0x18]
// 006235c5  50                   push eax
// 006235c6  8bce                 mov ecx, esi
// 006235c8  e853cdfaff           call 0x5d0320
// 006235cd  8b10                 mov edx, dword ptr [eax]
// 006235cf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006235d3  5b                   pop ebx
// 006235d4  8911                 mov dword ptr [ecx], edx
// 006235d6  8b4004               mov eax, dword ptr [eax + 4]
// 006235d9  5f                   pop edi
// 006235da  894104               mov dword ptr [ecx + 4], eax
// 006235dd  8bc1                 mov eax, ecx
// 006235df  5e                   pop esi
// 006235e0  83c414               add esp, 0x14
// 006235e3  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
