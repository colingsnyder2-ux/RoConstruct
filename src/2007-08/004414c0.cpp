// from server: 100% by auto
// roc 2007-08 004414c0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004414c0
//
// 004414c0  83ec0c               sub esp, 0xc
// 004414c3  56                   push esi
// 004414c4  8bf1                 mov esi, ecx
// 004414c6  837e0800             cmp dword ptr [esi + 8], 0
// 004414ca  57                   push edi
// 004414cb  7521                 jne 0x4414ee
// 004414cd  8b442424             mov eax, dword ptr [esp + 0x24]
// 004414d1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004414d4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004414d8  50                   push eax
// 004414d9  51                   push ecx
// 004414da  6a01                 push 1
// 004414dc  57                   push edi
// 004414dd  8bce                 mov ecx, esi
// 004414df  e85cdfffff           call 0x43f440
// 004414e4  8bc7                 mov eax, edi
// 004414e6  5f                   pop edi
// 004414e7  5e                   pop esi
// 004414e8  83c40c               add esp, 0xc
// 004414eb  c21000               ret 0x10
// 004414ee  8b5604               mov edx, dword ptr [esi + 4]
// 004414f1  8b3a                 mov edi, dword ptr [edx]
// 004414f3  55                   push ebp
// 004414f4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004414f8  85ed                 test ebp, ebp
// 004414fa  7404                 je 0x441500
// 004414fc  3bee                 cmp ebp, esi
// 004414fe  7406                 je 0x441506
// 00441500  ff15d8e67700         call dword ptr [0x77e6d8]
// 00441506  53                   push ebx
// 00441507  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0044150b  3bdf                 cmp ebx, edi
// 0044150d  752b                 jne 0x44153a
// 0044150f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00441513  8b07                 mov eax, dword ptr [edi]
// 00441515  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00441518  0f8339010000         jae 0x441657
// 0044151e  57                   push edi
// 0044151f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00441523  53                   push ebx
// 00441524  6a01                 push 1
// 00441526  57                   push edi
// 00441527  8bce                 mov ecx, esi
// 00441529  e812dfffff           call 0x43f440
// 0044152e  5b                   pop ebx
// 0044152f  5d                   pop ebp
// 00441530  8bc7                 mov eax, edi
// 00441532  5f                   pop edi
// 00441533  5e                   pop esi
// 00441534  83c40c               add esp, 0xc
// 00441537  c21000               ret 0x10
// 0044153a  85ed                 test ebp, ebp
// 0044153c  8b7e04               mov edi, dword ptr [esi + 4]
// 0044153f  7404                 je 0x441545
// 00441541  3bee                 cmp ebp, esi
// 00441543  7406                 je 0x44154b
// 00441545  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044154b  3bdf                 cmp ebx, edi
// 0044154d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00441551  752d                 jne 0x441580
// 00441553  8b4e04               mov ecx, dword ptr [esi + 4]
// 00441556  8b4108               mov eax, dword ptr [ecx + 8]
// 00441559  8b500c               mov edx, dword ptr [eax + 0xc]
// 0044155c  3b17                 cmp edx, dword ptr [edi]
// 0044155e  0f83f3000000         jae 0x441657
// 00441564  57                   push edi
// 00441565  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00441569  50                   push eax
// 0044156a  6a00                 push 0
// 0044156c  57                   push edi
// 0044156d  8bce                 mov ecx, esi
// 0044156f  e8ccdeffff           call 0x43f440
// 00441574  5b                   pop ebx
// 00441575  5d                   pop ebp
// 00441576  8bc7                 mov eax, edi
// 00441578  5f                   pop edi
// 00441579  5e                   pop esi
// 0044157a  83c40c               add esp, 0xc
// 0044157d  c21000               ret 0x10
// 00441580  8b07                 mov eax, dword ptr [edi]
// 00441582  39430c               cmp dword ptr [ebx + 0xc], eax
// 00441585  765b                 jbe 0x4415e2
// 00441587  8d4c2424             lea ecx, [esp + 0x24]
// 0044158b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0044158f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00441593  e818ee0500           call 0x4a03b0
// 00441598  8b07                 mov eax, dword ptr [edi]
// 0044159a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044159e  39410c               cmp dword ptr [ecx + 0xc], eax
// 004415a1  733c                 jae 0x4415df
// 004415a3  8b4108               mov eax, dword ptr [ecx + 8]
// 004415a6  80782100             cmp byte ptr [eax + 0x21], 0
// 004415aa  57                   push edi
// 004415ab  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004415af  7417                 je 0x4415c8
// 004415b1  51                   push ecx
// 004415b2  6a00                 push 0
// 004415b4  57                   push edi
// 004415b5  8bce                 mov ecx, esi
// 004415b7  e884deffff           call 0x43f440
// 004415bc  5b                   pop ebx
// 004415bd  5d                   pop ebp
// 004415be  8bc7                 mov eax, edi
// 004415c0  5f                   pop edi
// 004415c1  5e                   pop esi
// 004415c2  83c40c               add esp, 0xc
// 004415c5  c21000               ret 0x10
// 004415c8  53                   push ebx
// 004415c9  6a01                 push 1
// 004415cb  57                   push edi
// 004415cc  8bce                 mov ecx, esi
// 004415ce  e86ddeffff           call 0x43f440
// 004415d3  5b                   pop ebx
// 004415d4  5d                   pop ebp
// 004415d5  8bc7                 mov eax, edi
// 004415d7  5f                   pop edi
// 004415d8  5e                   pop esi
// 004415d9  83c40c               add esp, 0xc
// 004415dc  c21000               ret 0x10
// 004415df  39430c               cmp dword ptr [ebx + 0xc], eax
// 004415e2  7373                 jae 0x441657
// 004415e4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004415e7  894c2414             mov dword ptr [esp + 0x14], ecx
// 004415eb  8d4c2424             lea ecx, [esp + 0x24]
// 004415ef  896c2424             mov dword ptr [esp + 0x24], ebp
// 004415f3  895c2428             mov dword ptr [esp + 0x28], ebx
// 004415f7  89742410             mov dword ptr [esp + 0x10], esi
// 004415fb  e870f20800           call 0x4d0870
// 00441600  8d542410             lea edx, [esp + 0x10]
// 00441604  52                   push edx
// 00441605  8d4c2428             lea ecx, [esp + 0x28]
// 00441609  e8a2540200           call 0x466ab0
// 0044160e  84c0                 test al, al
// 00441610  8b442428             mov eax, dword ptr [esp + 0x28]
// 00441614  7507                 jne 0x44161d
// 00441616  8b0f                 mov ecx, dword ptr [edi]
// 00441618  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0044161b  733a                 jae 0x441657
// 0044161d  8b5308               mov edx, dword ptr [ebx + 8]
// 00441620  807a2100             cmp byte ptr [edx + 0x21], 0
// 00441624  57                   push edi
// 00441625  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00441629  8bce                 mov ecx, esi
// 0044162b  7415                 je 0x441642
// 0044162d  53                   push ebx
// 0044162e  6a00                 push 0
// 00441630  57                   push edi
// 00441631  e80adeffff           call 0x43f440
// 00441636  5b                   pop ebx
// 00441637  5d                   pop ebp
// 00441638  8bc7                 mov eax, edi
// 0044163a  5f                   pop edi
// 0044163b  5e                   pop esi
// 0044163c  83c40c               add esp, 0xc
// 0044163f  c21000               ret 0x10
// 00441642  50                   push eax
// 00441643  6a01                 push 1
// 00441645  57                   push edi
// 00441646  e8f5ddffff           call 0x43f440
// 0044164b  5b                   pop ebx
// 0044164c  5d                   pop ebp
// 0044164d  8bc7                 mov eax, edi
// 0044164f  5f                   pop edi
// 00441650  5e                   pop esi
// 00441651  83c40c               add esp, 0xc
// 00441654  c21000               ret 0x10
// 00441657  57                   push edi
// 00441658  8d442414             lea eax, [esp + 0x14]
// 0044165c  50                   push eax
// 0044165d  8bce                 mov ecx, esi
// 0044165f  e8bcf5ffff           call 0x440c20
// 00441664  8b10                 mov edx, dword ptr [eax]
// 00441666  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0044166a  5b                   pop ebx
// 0044166b  5d                   pop ebp
// 0044166c  8911                 mov dword ptr [ecx], edx
// 0044166e  8b4004               mov eax, dword ptr [eax + 4]
// 00441671  5f                   pop edi
// 00441672  894104               mov dword ptr [ecx + 4], eax
// 00441675  8bc1                 mov eax, ecx
// 00441677  5e                   pop esi
// 00441678  83c40c               add esp, 0xc
// 0044167b  c21000               ret 0x10
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
