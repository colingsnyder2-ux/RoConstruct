// from server: 100% by auto
// roc 2009-06 00619ba0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619ba0
//
// 00619ba0  83ec14               sub esp, 0x14
// 00619ba3  56                   push esi
// 00619ba4  8bf1                 mov esi, ecx
// 00619ba6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00619baa  57                   push edi
// 00619bab  7521                 jne 0x619bce
// 00619bad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00619bb1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00619bb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00619bb8  50                   push eax
// 00619bb9  51                   push ecx
// 00619bba  6a01                 push 1
// 00619bbc  57                   push edi
// 00619bbd  8bce                 mov ecx, esi
// 00619bbf  e8acecffff           call 0x618870
// 00619bc4  8bc7                 mov eax, edi
// 00619bc6  5f                   pop edi
// 00619bc7  5e                   pop esi
// 00619bc8  83c414               add esp, 0x14
// 00619bcb  c21000               ret 0x10
// 00619bce  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00619bd2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00619bd5  8b3a                 mov edi, dword ptr [edx]
// 00619bd7  8b06                 mov eax, dword ptr [esi]
// 00619bd9  53                   push ebx
// 00619bda  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00619be0  85c9                 test ecx, ecx
// 00619be2  7404                 je 0x619be8
// 00619be4  3bc8                 cmp ecx, eax
// 00619be6  7406                 je 0x619bee
// 00619be8  ffd3                 call ebx
// 00619bea  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00619bee  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00619bf2  3bc7                 cmp eax, edi
// 00619bf4  752a                 jne 0x619c20
// 00619bf6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00619bfa  8b0f                 mov ecx, dword ptr [edi]
// 00619bfc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00619bff  0f834b010000         jae 0x619d50
// 00619c05  57                   push edi
// 00619c06  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00619c0a  50                   push eax
// 00619c0b  6a01                 push 1
// 00619c0d  57                   push edi
// 00619c0e  8bce                 mov ecx, esi
// 00619c10  e85becffff           call 0x618870
// 00619c15  5b                   pop ebx
// 00619c16  8bc7                 mov eax, edi
// 00619c18  5f                   pop edi
// 00619c19  5e                   pop esi
// 00619c1a  83c414               add esp, 0x14
// 00619c1d  c21000               ret 0x10
// 00619c20  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00619c23  8b16                 mov edx, dword ptr [esi]
// 00619c25  85c9                 test ecx, ecx
// 00619c27  7404                 je 0x619c2d
// 00619c29  3bca                 cmp ecx, edx
// 00619c2b  740a                 je 0x619c37
// 00619c2d  ffd3                 call ebx
// 00619c2f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00619c33  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00619c37  3bc7                 cmp eax, edi
// 00619c39  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00619c3d  752c                 jne 0x619c6b
// 00619c3f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00619c42  8b4208               mov eax, dword ptr [edx + 8]
// 00619c45  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00619c48  3b0f                 cmp ecx, dword ptr [edi]
// 00619c4a  0f8300010000         jae 0x619d50
// 00619c50  57                   push edi
// 00619c51  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00619c55  50                   push eax
// 00619c56  6a00                 push 0
// 00619c58  57                   push edi
// 00619c59  8bce                 mov ecx, esi
// 00619c5b  e810ecffff           call 0x618870
// 00619c60  5b                   pop ebx
// 00619c61  8bc7                 mov eax, edi
// 00619c63  5f                   pop edi
// 00619c64  5e                   pop esi
// 00619c65  83c414               add esp, 0x14
// 00619c68  c21000               ret 0x10
// 00619c6b  8b17                 mov edx, dword ptr [edi]
// 00619c6d  39500c               cmp dword ptr [eax + 0xc], edx
// 00619c70  7663                 jbe 0x619cd5
// 00619c72  894c240c             mov dword ptr [esp + 0xc], ecx
// 00619c76  8d4c240c             lea ecx, [esp + 0xc]
// 00619c7a  89442410             mov dword ptr [esp + 0x10], eax
// 00619c7e  e82da2ecff           call 0x4e3eb0
// 00619c83  8b17                 mov edx, dword ptr [edi]
// 00619c85  8b442410             mov eax, dword ptr [esp + 0x10]
// 00619c89  39500c               cmp dword ptr [eax + 0xc], edx
// 00619c8c  733c                 jae 0x619cca
// 00619c8e  8b5008               mov edx, dword ptr [eax + 8]
// 00619c91  807a1900             cmp byte ptr [edx + 0x19], 0
// 00619c95  57                   push edi
// 00619c96  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00619c9a  8bce                 mov ecx, esi
// 00619c9c  7414                 je 0x619cb2
// 00619c9e  50                   push eax
// 00619c9f  6a00                 push 0
// 00619ca1  57                   push edi
// 00619ca2  e8c9ebffff           call 0x618870
// 00619ca7  5b                   pop ebx
// 00619ca8  8bc7                 mov eax, edi
// 00619caa  5f                   pop edi
// 00619cab  5e                   pop esi
// 00619cac  83c414               add esp, 0x14
// 00619caf  c21000               ret 0x10
// 00619cb2  8b442430             mov eax, dword ptr [esp + 0x30]
// 00619cb6  50                   push eax
// 00619cb7  6a01                 push 1
// 00619cb9  57                   push edi
// 00619cba  e8b1ebffff           call 0x618870
// 00619cbf  5b                   pop ebx
// 00619cc0  8bc7                 mov eax, edi
// 00619cc2  5f                   pop edi
// 00619cc3  5e                   pop esi
// 00619cc4  83c414               add esp, 0x14
// 00619cc7  c21000               ret 0x10
// 00619cca  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00619cce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00619cd2  39500c               cmp dword ptr [eax + 0xc], edx
// 00619cd5  7379                 jae 0x619d50
// 00619cd7  8b16                 mov edx, dword ptr [esi]
// 00619cd9  894c240c             mov dword ptr [esp + 0xc], ecx
// 00619cdd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00619ce0  894c2418             mov dword ptr [esp + 0x18], ecx
// 00619ce4  8d4c240c             lea ecx, [esp + 0xc]
// 00619ce8  89442410             mov dword ptr [esp + 0x10], eax
// 00619cec  89542414             mov dword ptr [esp + 0x14], edx
// 00619cf0  e8cb850000           call 0x6222c0
// 00619cf5  8d442414             lea eax, [esp + 0x14]
// 00619cf9  50                   push eax
// 00619cfa  8d4c2410             lea ecx, [esp + 0x10]
// 00619cfe  e89d970200           call 0x6434a0
// 00619d03  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00619d07  84c0                 test al, al
// 00619d09  7507                 jne 0x619d12
// 00619d0b  8b17                 mov edx, dword ptr [edi]
// 00619d0d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00619d10  733e                 jae 0x619d50
// 00619d12  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00619d16  8b5008               mov edx, dword ptr [eax + 8]
// 00619d19  807a1900             cmp byte ptr [edx + 0x19], 0
// 00619d1d  57                   push edi
// 00619d1e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00619d22  7416                 je 0x619d3a
// 00619d24  50                   push eax
// 00619d25  6a00                 push 0
// 00619d27  57                   push edi
// 00619d28  8bce                 mov ecx, esi
// 00619d2a  e841ebffff           call 0x618870
// 00619d2f  5b                   pop ebx
// 00619d30  8bc7                 mov eax, edi
// 00619d32  5f                   pop edi
// 00619d33  5e                   pop esi
// 00619d34  83c414               add esp, 0x14
// 00619d37  c21000               ret 0x10
// 00619d3a  51                   push ecx
// 00619d3b  6a01                 push 1
// 00619d3d  57                   push edi
// 00619d3e  8bce                 mov ecx, esi
// 00619d40  e82bebffff           call 0x618870
// 00619d45  5b                   pop ebx
// 00619d46  8bc7                 mov eax, edi
// 00619d48  5f                   pop edi
// 00619d49  5e                   pop esi
// 00619d4a  83c414               add esp, 0x14
// 00619d4d  c21000               ret 0x10
// 00619d50  57                   push edi
// 00619d51  8d442418             lea eax, [esp + 0x18]
// 00619d55  50                   push eax
// 00619d56  8bce                 mov ecx, esi
// 00619d58  e813f1ffff           call 0x618e70
// 00619d5d  8b10                 mov edx, dword ptr [eax]
// 00619d5f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00619d63  5b                   pop ebx
// 00619d64  8911                 mov dword ptr [ecx], edx
// 00619d66  8b4004               mov eax, dword ptr [eax + 4]
// 00619d69  5f                   pop edi
// 00619d6a  894104               mov dword ptr [ecx + 4], eax
// 00619d6d  8bc1                 mov eax, ecx
// 00619d6f  5e                   pop esi
// 00619d70  83c414               add esp, 0x14
// 00619d73  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
