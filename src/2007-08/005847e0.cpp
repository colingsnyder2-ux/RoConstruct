// from server: 100% by auto
// roc 2007-08 005847e0  unit: RBX::VHat::?$FactoryProduct  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005847e0
//
// 005847e0  83ec0c               sub esp, 0xc
// 005847e3  56                   push esi
// 005847e4  8bf1                 mov esi, ecx
// 005847e6  837e0800             cmp dword ptr [esi + 8], 0
// 005847ea  57                   push edi
// 005847eb  7521                 jne 0x58480e
// 005847ed  8b442424             mov eax, dword ptr [esp + 0x24]
// 005847f1  8b4e04               mov ecx, dword ptr [esi + 4]
// 005847f4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005847f8  50                   push eax
// 005847f9  51                   push ecx
// 005847fa  6a01                 push 1
// 005847fc  57                   push edi
// 005847fd  8bce                 mov ecx, esi
// 005847ff  e82cf2ffff           call 0x583a30
// 00584804  8bc7                 mov eax, edi
// 00584806  5f                   pop edi
// 00584807  5e                   pop esi
// 00584808  83c40c               add esp, 0xc
// 0058480b  c21000               ret 0x10
// 0058480e  8b5604               mov edx, dword ptr [esi + 4]
// 00584811  8b3a                 mov edi, dword ptr [edx]
// 00584813  55                   push ebp
// 00584814  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00584818  85ed                 test ebp, ebp
// 0058481a  7404                 je 0x584820
// 0058481c  3bee                 cmp ebp, esi
// 0058481e  7406                 je 0x584826
// 00584820  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584826  53                   push ebx
// 00584827  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058482b  3bdf                 cmp ebx, edi
// 0058482d  752b                 jne 0x58485a
// 0058482f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584833  8b07                 mov eax, dword ptr [edi]
// 00584835  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00584838  0f8d39010000         jge 0x584977
// 0058483e  57                   push edi
// 0058483f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584843  53                   push ebx
// 00584844  6a01                 push 1
// 00584846  57                   push edi
// 00584847  8bce                 mov ecx, esi
// 00584849  e8e2f1ffff           call 0x583a30
// 0058484e  5b                   pop ebx
// 0058484f  5d                   pop ebp
// 00584850  8bc7                 mov eax, edi
// 00584852  5f                   pop edi
// 00584853  5e                   pop esi
// 00584854  83c40c               add esp, 0xc
// 00584857  c21000               ret 0x10
// 0058485a  85ed                 test ebp, ebp
// 0058485c  8b7e04               mov edi, dword ptr [esi + 4]
// 0058485f  7404                 je 0x584865
// 00584861  3bee                 cmp ebp, esi
// 00584863  7406                 je 0x58486b
// 00584865  ff15d8e67700         call dword ptr [0x77e6d8]
// 0058486b  3bdf                 cmp ebx, edi
// 0058486d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584871  752d                 jne 0x5848a0
// 00584873  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584876  8b4108               mov eax, dword ptr [ecx + 8]
// 00584879  8b500c               mov edx, dword ptr [eax + 0xc]
// 0058487c  3b17                 cmp edx, dword ptr [edi]
// 0058487e  0f8df3000000         jge 0x584977
// 00584884  57                   push edi
// 00584885  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584889  50                   push eax
// 0058488a  6a00                 push 0
// 0058488c  57                   push edi
// 0058488d  8bce                 mov ecx, esi
// 0058488f  e89cf1ffff           call 0x583a30
// 00584894  5b                   pop ebx
// 00584895  5d                   pop ebp
// 00584896  8bc7                 mov eax, edi
// 00584898  5f                   pop edi
// 00584899  5e                   pop esi
// 0058489a  83c40c               add esp, 0xc
// 0058489d  c21000               ret 0x10
// 005848a0  8b07                 mov eax, dword ptr [edi]
// 005848a2  39430c               cmp dword ptr [ebx + 0xc], eax
// 005848a5  7e5b                 jle 0x584902
// 005848a7  8d4c2424             lea ecx, [esp + 0x24]
// 005848ab  896c2424             mov dword ptr [esp + 0x24], ebp
// 005848af  895c2428             mov dword ptr [esp + 0x28], ebx
// 005848b3  e878a9f6ff           call 0x4ef230
// 005848b8  8b07                 mov eax, dword ptr [edi]
// 005848ba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005848be  39410c               cmp dword ptr [ecx + 0xc], eax
// 005848c1  7d3c                 jge 0x5848ff
// 005848c3  8b4108               mov eax, dword ptr [ecx + 8]
// 005848c6  80781500             cmp byte ptr [eax + 0x15], 0
// 005848ca  57                   push edi
// 005848cb  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005848cf  7417                 je 0x5848e8
// 005848d1  51                   push ecx
// 005848d2  6a00                 push 0
// 005848d4  57                   push edi
// 005848d5  8bce                 mov ecx, esi
// 005848d7  e854f1ffff           call 0x583a30
// 005848dc  5b                   pop ebx
// 005848dd  5d                   pop ebp
// 005848de  8bc7                 mov eax, edi
// 005848e0  5f                   pop edi
// 005848e1  5e                   pop esi
// 005848e2  83c40c               add esp, 0xc
// 005848e5  c21000               ret 0x10
// 005848e8  53                   push ebx
// 005848e9  6a01                 push 1
// 005848eb  57                   push edi
// 005848ec  8bce                 mov ecx, esi
// 005848ee  e83df1ffff           call 0x583a30
// 005848f3  5b                   pop ebx
// 005848f4  5d                   pop ebp
// 005848f5  8bc7                 mov eax, edi
// 005848f7  5f                   pop edi
// 005848f8  5e                   pop esi
// 005848f9  83c40c               add esp, 0xc
// 005848fc  c21000               ret 0x10
// 005848ff  39430c               cmp dword ptr [ebx + 0xc], eax
// 00584902  7d73                 jge 0x584977
// 00584904  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584907  894c2414             mov dword ptr [esp + 0x14], ecx
// 0058490b  8d4c2424             lea ecx, [esp + 0x24]
// 0058490f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00584913  895c2428             mov dword ptr [esp + 0x28], ebx
// 00584917  89742410             mov dword ptr [esp + 0x10], esi
// 0058491b  e89045ebff           call 0x438eb0
// 00584920  8d542410             lea edx, [esp + 0x10]
// 00584924  52                   push edx
// 00584925  8d4c2428             lea ecx, [esp + 0x28]
// 00584929  e88221eeff           call 0x466ab0
// 0058492e  84c0                 test al, al
// 00584930  8b442428             mov eax, dword ptr [esp + 0x28]
// 00584934  7507                 jne 0x58493d
// 00584936  8b0f                 mov ecx, dword ptr [edi]
// 00584938  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0058493b  7d3a                 jge 0x584977
// 0058493d  8b5308               mov edx, dword ptr [ebx + 8]
// 00584940  807a1500             cmp byte ptr [edx + 0x15], 0
// 00584944  57                   push edi
// 00584945  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584949  8bce                 mov ecx, esi
// 0058494b  7415                 je 0x584962
// 0058494d  53                   push ebx
// 0058494e  6a00                 push 0
// 00584950  57                   push edi
// 00584951  e8daf0ffff           call 0x583a30
// 00584956  5b                   pop ebx
// 00584957  5d                   pop ebp
// 00584958  8bc7                 mov eax, edi
// 0058495a  5f                   pop edi
// 0058495b  5e                   pop esi
// 0058495c  83c40c               add esp, 0xc
// 0058495f  c21000               ret 0x10
// 00584962  50                   push eax
// 00584963  6a01                 push 1
// 00584965  57                   push edi
// 00584966  e8c5f0ffff           call 0x583a30
// 0058496b  5b                   pop ebx
// 0058496c  5d                   pop ebp
// 0058496d  8bc7                 mov eax, edi
// 0058496f  5f                   pop edi
// 00584970  5e                   pop esi
// 00584971  83c40c               add esp, 0xc
// 00584974  c21000               ret 0x10
// 00584977  57                   push edi
// 00584978  8d442414             lea eax, [esp + 0x14]
// 0058497c  50                   push eax
// 0058497d  8bce                 mov ecx, esi
// 0058497f  e8ecf9ffff           call 0x584370
// 00584984  8b10                 mov edx, dword ptr [eax]
// 00584986  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0058498a  5b                   pop ebx
// 0058498b  5d                   pop ebp
// 0058498c  8911                 mov dword ptr [ecx], edx
// 0058498e  8b4004               mov eax, dword ptr [eax + 4]
// 00584991  5f                   pop edi
// 00584992  894104               mov dword ptr [ecx + 4], eax
// 00584995  8bc1                 mov eax, ecx
// 00584997  5e                   pop esi
// 00584998  83c40c               add esp, 0xc
// 0058499b  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
