// from server: 100% by auto
// roc 2007-03 00584ec0  unit: seg_00580000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00584ec0
//
// 00584ec0  83ec0c               sub esp, 0xc
// 00584ec3  56                   push esi
// 00584ec4  8bf1                 mov esi, ecx
// 00584ec6  837e0800             cmp dword ptr [esi + 8], 0
// 00584eca  57                   push edi
// 00584ecb  7521                 jne 0x584eee
// 00584ecd  8b442424             mov eax, dword ptr [esp + 0x24]
// 00584ed1  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584ed4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00584ed8  50                   push eax
// 00584ed9  51                   push ecx
// 00584eda  6a01                 push 1
// 00584edc  57                   push edi
// 00584edd  8bce                 mov ecx, esi
// 00584edf  e83cadfeff           call 0x56fc20
// 00584ee4  8bc7                 mov eax, edi
// 00584ee6  5f                   pop edi
// 00584ee7  5e                   pop esi
// 00584ee8  83c40c               add esp, 0xc
// 00584eeb  c21000               ret 0x10
// 00584eee  8b5604               mov edx, dword ptr [esi + 4]
// 00584ef1  8b3a                 mov edi, dword ptr [edx]
// 00584ef3  55                   push ebp
// 00584ef4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00584ef8  85ed                 test ebp, ebp
// 00584efa  7404                 je 0x584f00
// 00584efc  3bee                 cmp ebp, esi
// 00584efe  7406                 je 0x584f06
// 00584f00  ff1544e97700         call dword ptr [0x77e944]
// 00584f06  53                   push ebx
// 00584f07  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00584f0b  3bdf                 cmp ebx, edi
// 00584f0d  752b                 jne 0x584f3a
// 00584f0f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584f13  8b07                 mov eax, dword ptr [edi]
// 00584f15  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00584f18  0f8d39010000         jge 0x585057
// 00584f1e  57                   push edi
// 00584f1f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584f23  53                   push ebx
// 00584f24  6a01                 push 1
// 00584f26  57                   push edi
// 00584f27  8bce                 mov ecx, esi
// 00584f29  e8f2acfeff           call 0x56fc20
// 00584f2e  5b                   pop ebx
// 00584f2f  5d                   pop ebp
// 00584f30  8bc7                 mov eax, edi
// 00584f32  5f                   pop edi
// 00584f33  5e                   pop esi
// 00584f34  83c40c               add esp, 0xc
// 00584f37  c21000               ret 0x10
// 00584f3a  85ed                 test ebp, ebp
// 00584f3c  8b7e04               mov edi, dword ptr [esi + 4]
// 00584f3f  7404                 je 0x584f45
// 00584f41  3bee                 cmp ebp, esi
// 00584f43  7406                 je 0x584f4b
// 00584f45  ff1544e97700         call dword ptr [0x77e944]
// 00584f4b  3bdf                 cmp ebx, edi
// 00584f4d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584f51  752d                 jne 0x584f80
// 00584f53  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584f56  8b4108               mov eax, dword ptr [ecx + 8]
// 00584f59  8b500c               mov edx, dword ptr [eax + 0xc]
// 00584f5c  3b17                 cmp edx, dword ptr [edi]
// 00584f5e  0f8df3000000         jge 0x585057
// 00584f64  57                   push edi
// 00584f65  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584f69  50                   push eax
// 00584f6a  6a00                 push 0
// 00584f6c  57                   push edi
// 00584f6d  8bce                 mov ecx, esi
// 00584f6f  e8acacfeff           call 0x56fc20
// 00584f74  5b                   pop ebx
// 00584f75  5d                   pop ebp
// 00584f76  8bc7                 mov eax, edi
// 00584f78  5f                   pop edi
// 00584f79  5e                   pop esi
// 00584f7a  83c40c               add esp, 0xc
// 00584f7d  c21000               ret 0x10
// 00584f80  8b07                 mov eax, dword ptr [edi]
// 00584f82  39430c               cmp dword ptr [ebx + 0xc], eax
// 00584f85  7e5b                 jle 0x584fe2
// 00584f87  8d4c2424             lea ecx, [esp + 0x24]
// 00584f8b  896c2424             mov dword ptr [esp + 0x24], ebp
// 00584f8f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00584f93  e878bf0600           call 0x5f0f10
// 00584f98  8b07                 mov eax, dword ptr [edi]
// 00584f9a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00584f9e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00584fa1  7d3c                 jge 0x584fdf
// 00584fa3  8b4108               mov eax, dword ptr [ecx + 8]
// 00584fa6  80781900             cmp byte ptr [eax + 0x19], 0
// 00584faa  57                   push edi
// 00584fab  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584faf  7417                 je 0x584fc8
// 00584fb1  51                   push ecx
// 00584fb2  6a00                 push 0
// 00584fb4  57                   push edi
// 00584fb5  8bce                 mov ecx, esi
// 00584fb7  e864acfeff           call 0x56fc20
// 00584fbc  5b                   pop ebx
// 00584fbd  5d                   pop ebp
// 00584fbe  8bc7                 mov eax, edi
// 00584fc0  5f                   pop edi
// 00584fc1  5e                   pop esi
// 00584fc2  83c40c               add esp, 0xc
// 00584fc5  c21000               ret 0x10
// 00584fc8  53                   push ebx
// 00584fc9  6a01                 push 1
// 00584fcb  57                   push edi
// 00584fcc  8bce                 mov ecx, esi
// 00584fce  e84dacfeff           call 0x56fc20
// 00584fd3  5b                   pop ebx
// 00584fd4  5d                   pop ebp
// 00584fd5  8bc7                 mov eax, edi
// 00584fd7  5f                   pop edi
// 00584fd8  5e                   pop esi
// 00584fd9  83c40c               add esp, 0xc
// 00584fdc  c21000               ret 0x10
// 00584fdf  39430c               cmp dword ptr [ebx + 0xc], eax
// 00584fe2  7d73                 jge 0x585057
// 00584fe4  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584fe7  894c2414             mov dword ptr [esp + 0x14], ecx
// 00584feb  8d4c2424             lea ecx, [esp + 0x24]
// 00584fef  896c2424             mov dword ptr [esp + 0x24], ebp
// 00584ff3  895c2428             mov dword ptr [esp + 0x28], ebx
// 00584ff7  89742410             mov dword ptr [esp + 0x10], esi
// 00584ffb  e800c20600           call 0x5f1200
// 00585000  8d542410             lea edx, [esp + 0x10]
// 00585004  52                   push edx
// 00585005  8d4c2428             lea ecx, [esp + 0x28]
// 00585009  e8526cecff           call 0x44bc60
// 0058500e  84c0                 test al, al
// 00585010  8b442428             mov eax, dword ptr [esp + 0x28]
// 00585014  7507                 jne 0x58501d
// 00585016  8b0f                 mov ecx, dword ptr [edi]
// 00585018  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0058501b  7d3a                 jge 0x585057
// 0058501d  8b5308               mov edx, dword ptr [ebx + 8]
// 00585020  807a1900             cmp byte ptr [edx + 0x19], 0
// 00585024  57                   push edi
// 00585025  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00585029  8bce                 mov ecx, esi
// 0058502b  7415                 je 0x585042
// 0058502d  53                   push ebx
// 0058502e  6a00                 push 0
// 00585030  57                   push edi
// 00585031  e8eaabfeff           call 0x56fc20
// 00585036  5b                   pop ebx
// 00585037  5d                   pop ebp
// 00585038  8bc7                 mov eax, edi
// 0058503a  5f                   pop edi
// 0058503b  5e                   pop esi
// 0058503c  83c40c               add esp, 0xc
// 0058503f  c21000               ret 0x10
// 00585042  50                   push eax
// 00585043  6a01                 push 1
// 00585045  57                   push edi
// 00585046  e8d5abfeff           call 0x56fc20
// 0058504b  5b                   pop ebx
// 0058504c  5d                   pop ebp
// 0058504d  8bc7                 mov eax, edi
// 0058504f  5f                   pop edi
// 00585050  5e                   pop esi
// 00585051  83c40c               add esp, 0xc
// 00585054  c21000               ret 0x10
// 00585057  57                   push edi
// 00585058  8d442414             lea eax, [esp + 0x14]
// 0058505c  50                   push eax
// 0058505d  8bce                 mov ecx, esi
// 0058505f  e89cfdffff           call 0x584e00
// 00585064  8b10                 mov edx, dword ptr [eax]
// 00585066  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0058506a  5b                   pop ebx
// 0058506b  5d                   pop ebp
// 0058506c  8911                 mov dword ptr [ecx], edx
// 0058506e  8b4004               mov eax, dword ptr [eax + 4]
// 00585071  5f                   pop edi
// 00585072  894104               mov dword ptr [ecx + 4], eax
// 00585075  8bc1                 mov eax, ecx
// 00585077  5e                   pop esi
// 00585078  83c40c               add esp, 0xc
// 0058507b  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
