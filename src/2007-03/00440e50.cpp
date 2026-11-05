// from server: 100% by auto
// roc 2007-03 00440e50  unit: seg_00440000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00440e50
//
// 00440e50  83ec0c               sub esp, 0xc
// 00440e53  56                   push esi
// 00440e54  8bf1                 mov esi, ecx
// 00440e56  837e0800             cmp dword ptr [esi + 8], 0
// 00440e5a  57                   push edi
// 00440e5b  7521                 jne 0x440e7e
// 00440e5d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00440e61  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440e64  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00440e68  50                   push eax
// 00440e69  51                   push ecx
// 00440e6a  6a01                 push 1
// 00440e6c  57                   push edi
// 00440e6d  8bce                 mov ecx, esi
// 00440e6f  e80ce0ffff           call 0x43ee80
// 00440e74  8bc7                 mov eax, edi
// 00440e76  5f                   pop edi
// 00440e77  5e                   pop esi
// 00440e78  83c40c               add esp, 0xc
// 00440e7b  c21000               ret 0x10
// 00440e7e  8b5604               mov edx, dword ptr [esi + 4]
// 00440e81  8b3a                 mov edi, dword ptr [edx]
// 00440e83  55                   push ebp
// 00440e84  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00440e88  85ed                 test ebp, ebp
// 00440e8a  7404                 je 0x440e90
// 00440e8c  3bee                 cmp ebp, esi
// 00440e8e  7406                 je 0x440e96
// 00440e90  ff1544e97700         call dword ptr [0x77e944]
// 00440e96  53                   push ebx
// 00440e97  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00440e9b  3bdf                 cmp ebx, edi
// 00440e9d  752b                 jne 0x440eca
// 00440e9f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00440ea3  8b07                 mov eax, dword ptr [edi]
// 00440ea5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00440ea8  0f8339010000         jae 0x440fe7
// 00440eae  57                   push edi
// 00440eaf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00440eb3  53                   push ebx
// 00440eb4  6a01                 push 1
// 00440eb6  57                   push edi
// 00440eb7  8bce                 mov ecx, esi
// 00440eb9  e8c2dfffff           call 0x43ee80
// 00440ebe  5b                   pop ebx
// 00440ebf  5d                   pop ebp
// 00440ec0  8bc7                 mov eax, edi
// 00440ec2  5f                   pop edi
// 00440ec3  5e                   pop esi
// 00440ec4  83c40c               add esp, 0xc
// 00440ec7  c21000               ret 0x10
// 00440eca  85ed                 test ebp, ebp
// 00440ecc  8b7e04               mov edi, dword ptr [esi + 4]
// 00440ecf  7404                 je 0x440ed5
// 00440ed1  3bee                 cmp ebp, esi
// 00440ed3  7406                 je 0x440edb
// 00440ed5  ff1544e97700         call dword ptr [0x77e944]
// 00440edb  3bdf                 cmp ebx, edi
// 00440edd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00440ee1  752d                 jne 0x440f10
// 00440ee3  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440ee6  8b4108               mov eax, dword ptr [ecx + 8]
// 00440ee9  8b500c               mov edx, dword ptr [eax + 0xc]
// 00440eec  3b17                 cmp edx, dword ptr [edi]
// 00440eee  0f83f3000000         jae 0x440fe7
// 00440ef4  57                   push edi
// 00440ef5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00440ef9  50                   push eax
// 00440efa  6a00                 push 0
// 00440efc  57                   push edi
// 00440efd  8bce                 mov ecx, esi
// 00440eff  e87cdfffff           call 0x43ee80
// 00440f04  5b                   pop ebx
// 00440f05  5d                   pop ebp
// 00440f06  8bc7                 mov eax, edi
// 00440f08  5f                   pop edi
// 00440f09  5e                   pop esi
// 00440f0a  83c40c               add esp, 0xc
// 00440f0d  c21000               ret 0x10
// 00440f10  8b07                 mov eax, dword ptr [edi]
// 00440f12  39430c               cmp dword ptr [ebx + 0xc], eax
// 00440f15  765b                 jbe 0x440f72
// 00440f17  8d4c2424             lea ecx, [esp + 0x24]
// 00440f1b  896c2424             mov dword ptr [esp + 0x24], ebp
// 00440f1f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00440f23  e8883d0800           call 0x4c4cb0
// 00440f28  8b07                 mov eax, dword ptr [edi]
// 00440f2a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00440f2e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00440f31  733c                 jae 0x440f6f
// 00440f33  8b4108               mov eax, dword ptr [ecx + 8]
// 00440f36  80782100             cmp byte ptr [eax + 0x21], 0
// 00440f3a  57                   push edi
// 00440f3b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00440f3f  7417                 je 0x440f58
// 00440f41  51                   push ecx
// 00440f42  6a00                 push 0
// 00440f44  57                   push edi
// 00440f45  8bce                 mov ecx, esi
// 00440f47  e834dfffff           call 0x43ee80
// 00440f4c  5b                   pop ebx
// 00440f4d  5d                   pop ebp
// 00440f4e  8bc7                 mov eax, edi
// 00440f50  5f                   pop edi
// 00440f51  5e                   pop esi
// 00440f52  83c40c               add esp, 0xc
// 00440f55  c21000               ret 0x10
// 00440f58  53                   push ebx
// 00440f59  6a01                 push 1
// 00440f5b  57                   push edi
// 00440f5c  8bce                 mov ecx, esi
// 00440f5e  e81ddfffff           call 0x43ee80
// 00440f63  5b                   pop ebx
// 00440f64  5d                   pop ebp
// 00440f65  8bc7                 mov eax, edi
// 00440f67  5f                   pop edi
// 00440f68  5e                   pop esi
// 00440f69  83c40c               add esp, 0xc
// 00440f6c  c21000               ret 0x10
// 00440f6f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00440f72  7373                 jae 0x440fe7
// 00440f74  8b4e04               mov ecx, dword ptr [esi + 4]
// 00440f77  894c2414             mov dword ptr [esp + 0x14], ecx
// 00440f7b  8d4c2424             lea ecx, [esp + 0x24]
// 00440f7f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00440f83  895c2428             mov dword ptr [esp + 0x28], ebx
// 00440f87  89742410             mov dword ptr [esp + 0x10], esi
// 00440f8b  e890720500           call 0x498220
// 00440f90  8d542410             lea edx, [esp + 0x10]
// 00440f94  52                   push edx
// 00440f95  8d4c2428             lea ecx, [esp + 0x28]
// 00440f99  e8c2ac0000           call 0x44bc60
// 00440f9e  84c0                 test al, al
// 00440fa0  8b442428             mov eax, dword ptr [esp + 0x28]
// 00440fa4  7507                 jne 0x440fad
// 00440fa6  8b0f                 mov ecx, dword ptr [edi]
// 00440fa8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00440fab  733a                 jae 0x440fe7
// 00440fad  8b5308               mov edx, dword ptr [ebx + 8]
// 00440fb0  807a2100             cmp byte ptr [edx + 0x21], 0
// 00440fb4  57                   push edi
// 00440fb5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00440fb9  8bce                 mov ecx, esi
// 00440fbb  7415                 je 0x440fd2
// 00440fbd  53                   push ebx
// 00440fbe  6a00                 push 0
// 00440fc0  57                   push edi
// 00440fc1  e8badeffff           call 0x43ee80
// 00440fc6  5b                   pop ebx
// 00440fc7  5d                   pop ebp
// 00440fc8  8bc7                 mov eax, edi
// 00440fca  5f                   pop edi
// 00440fcb  5e                   pop esi
// 00440fcc  83c40c               add esp, 0xc
// 00440fcf  c21000               ret 0x10
// 00440fd2  50                   push eax
// 00440fd3  6a01                 push 1
// 00440fd5  57                   push edi
// 00440fd6  e8a5deffff           call 0x43ee80
// 00440fdb  5b                   pop ebx
// 00440fdc  5d                   pop ebp
// 00440fdd  8bc7                 mov eax, edi
// 00440fdf  5f                   pop edi
// 00440fe0  5e                   pop esi
// 00440fe1  83c40c               add esp, 0xc
// 00440fe4  c21000               ret 0x10
// 00440fe7  57                   push edi
// 00440fe8  8d442414             lea eax, [esp + 0x14]
// 00440fec  50                   push eax
// 00440fed  8bce                 mov ecx, esi
// 00440fef  e8bcf5ffff           call 0x4405b0
// 00440ff4  8b10                 mov edx, dword ptr [eax]
// 00440ff6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00440ffa  5b                   pop ebx
// 00440ffb  5d                   pop ebp
// 00440ffc  8911                 mov dword ptr [ecx], edx
// 00440ffe  8b4004               mov eax, dword ptr [eax + 4]
// 00441001  5f                   pop edi
// 00441002  894104               mov dword ptr [ecx + 4], eax
// 00441005  8bc1                 mov eax, ecx
// 00441007  5e                   pop esi
// 00441008  83c40c               add esp, 0xc
// 0044100b  c21000               ret 0x10
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
