// from server: 100% by auto
// roc 2010-06 006bed70  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006bed70
//
// 006bed70  83ec14               sub esp, 0x14
// 006bed73  56                   push esi
// 006bed74  8bf1                 mov esi, ecx
// 006bed76  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006bed7a  57                   push edi
// 006bed7b  7521                 jne 0x6bed9e
// 006bed7d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006bed81  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006bed84  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006bed88  50                   push eax
// 006bed89  51                   push ecx
// 006bed8a  6a01                 push 1
// 006bed8c  57                   push edi
// 006bed8d  8bce                 mov ecx, esi
// 006bed8f  e84cfbffff           call 0x6be8e0
// 006bed94  8bc7                 mov eax, edi
// 006bed96  5f                   pop edi
// 006bed97  5e                   pop esi
// 006bed98  83c414               add esp, 0x14
// 006bed9b  c21000               ret 0x10
// 006bed9e  8b442424             mov eax, dword ptr [esp + 0x24]
// 006beda2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006beda5  8b3a                 mov edi, dword ptr [edx]
// 006beda7  8b0e                 mov ecx, dword ptr [esi]
// 006beda9  53                   push ebx
// 006bedaa  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006bedb0  85c0                 test eax, eax
// 006bedb2  7404                 je 0x6bedb8
// 006bedb4  3bc1                 cmp eax, ecx
// 006bedb6  7406                 je 0x6bedbe
// 006bedb8  ffd3                 call ebx
// 006bedba  8b442428             mov eax, dword ptr [esp + 0x28]
// 006bedbe  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006bedc2  55                   push ebp
// 006bedc3  3bd7                 cmp edx, edi
// 006bedc5  753a                 jne 0x6bee01
// 006bedc7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006bedcb  83c20c               add edx, 0xc
// 006bedce  52                   push edx
// 006bedcf  57                   push edi
// 006bedd0  ff151ca59e00         call dword ptr [0x9ea51c]
// 006bedd6  83c408               add esp, 8
// 006bedd9  84c0                 test al, al
// 006beddb  0f849a010000         je 0x6bef7b
// 006bede1  8b442430             mov eax, dword ptr [esp + 0x30]
// 006bede5  57                   push edi
// 006bede6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006bedea  50                   push eax
// 006bedeb  6a01                 push 1
// 006beded  57                   push edi
// 006bedee  8bce                 mov ecx, esi
// 006bedf0  e8ebfaffff           call 0x6be8e0
// 006bedf5  5d                   pop ebp
// 006bedf6  5b                   pop ebx
// 006bedf7  8bc7                 mov eax, edi
// 006bedf9  5f                   pop edi
// 006bedfa  5e                   pop esi
// 006bedfb  83c414               add esp, 0x14
// 006bedfe  c21000               ret 0x10
// 006bee01  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006bee04  8b0e                 mov ecx, dword ptr [esi]
// 006bee06  85c0                 test eax, eax
// 006bee08  7404                 je 0x6bee0e
// 006bee0a  3bc1                 cmp eax, ecx
// 006bee0c  7406                 je 0x6bee14
// 006bee0e  ffd3                 call ebx
// 006bee10  8b542430             mov edx, dword ptr [esp + 0x30]
// 006bee14  3bd7                 cmp edx, edi
// 006bee16  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006bee1a  753e                 jne 0x6bee5a
// 006bee1c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006bee1f  8b4108               mov eax, dword ptr [ecx + 8]
// 006bee22  83c00c               add eax, 0xc
// 006bee25  57                   push edi
// 006bee26  50                   push eax
// 006bee27  ff151ca59e00         call dword ptr [0x9ea51c]
// 006bee2d  83c408               add esp, 8
// 006bee30  84c0                 test al, al
// 006bee32  0f8443010000         je 0x6bef7b
// 006bee38  8b5618               mov edx, dword ptr [esi + 0x18]
// 006bee3b  8b4208               mov eax, dword ptr [edx + 8]
// 006bee3e  57                   push edi
// 006bee3f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006bee43  50                   push eax
// 006bee44  6a00                 push 0
// 006bee46  57                   push edi
// 006bee47  8bce                 mov ecx, esi
// 006bee49  e892faffff           call 0x6be8e0
// 006bee4e  5d                   pop ebp
// 006bee4f  5b                   pop ebx
// 006bee50  8bc7                 mov eax, edi
// 006bee52  5f                   pop edi
// 006bee53  5e                   pop esi
// 006bee54  83c414               add esp, 0x14
// 006bee57  c21000               ret 0x10
// 006bee5a  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 006bee60  83c20c               add edx, 0xc
// 006bee63  52                   push edx
// 006bee64  57                   push edi
// 006bee65  ffd5                 call ebp
// 006bee67  83c408               add esp, 8
// 006bee6a  84c0                 test al, al
// 006bee6c  746c                 je 0x6beeda
// 006bee6e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006bee72  8b542430             mov edx, dword ptr [esp + 0x30]
// 006bee76  894c2410             mov dword ptr [esp + 0x10], ecx
// 006bee7a  8d4c2410             lea ecx, [esp + 0x10]
// 006bee7e  89542414             mov dword ptr [esp + 0x14], edx
// 006bee82  e85946dbff           call 0x4734e0
// 006bee87  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006bee8b  57                   push edi
// 006bee8c  8d430c               lea eax, [ebx + 0xc]
// 006bee8f  50                   push eax
// 006bee90  8d4e08               lea ecx, [esi + 8]
// 006bee93  e8b843dbff           call 0x473250
// 006bee98  84c0                 test al, al
// 006bee9a  743e                 je 0x6beeda
// 006bee9c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006bee9f  80793100             cmp byte ptr [ecx + 0x31], 0
// 006beea3  57                   push edi
// 006beea4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006beea8  8bce                 mov ecx, esi
// 006beeaa  7415                 je 0x6beec1
// 006beeac  53                   push ebx
// 006beead  6a00                 push 0
// 006beeaf  57                   push edi
// 006beeb0  e82bfaffff           call 0x6be8e0
// 006beeb5  5d                   pop ebp
// 006beeb6  5b                   pop ebx
// 006beeb7  8bc7                 mov eax, edi
// 006beeb9  5f                   pop edi
// 006beeba  5e                   pop esi
// 006beebb  83c414               add esp, 0x14
// 006beebe  c21000               ret 0x10
// 006beec1  8b542434             mov edx, dword ptr [esp + 0x34]
// 006beec5  52                   push edx
// 006beec6  6a01                 push 1
// 006beec8  57                   push edi
// 006beec9  e812faffff           call 0x6be8e0
// 006beece  5d                   pop ebp
// 006beecf  5b                   pop ebx
// 006beed0  8bc7                 mov eax, edi
// 006beed2  5f                   pop edi
// 006beed3  5e                   pop esi
// 006beed4  83c414               add esp, 0x14
// 006beed7  c21000               ret 0x10
// 006beeda  8b442430             mov eax, dword ptr [esp + 0x30]
// 006beede  83c00c               add eax, 0xc
// 006beee1  57                   push edi
// 006beee2  50                   push eax
// 006beee3  ffd5                 call ebp
// 006beee5  83c408               add esp, 8
// 006beee8  84c0                 test al, al
// 006beeea  0f848b000000         je 0x6bef7b
// 006beef0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006beef4  8b542430             mov edx, dword ptr [esp + 0x30]
// 006beef8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006beefb  894c2410             mov dword ptr [esp + 0x10], ecx
// 006beeff  8b0e                 mov ecx, dword ptr [esi]
// 006bef01  894c2418             mov dword ptr [esp + 0x18], ecx
// 006bef05  8d4c2410             lea ecx, [esp + 0x10]
// 006bef09  89542414             mov dword ptr [esp + 0x14], edx
// 006bef0d  8944241c             mov dword ptr [esp + 0x1c], eax
// 006bef11  e89a05faff           call 0x65f4b0
// 006bef16  8d542418             lea edx, [esp + 0x18]
// 006bef1a  52                   push edx
// 006bef1b  8d4c2414             lea ecx, [esp + 0x14]
// 006bef1f  e85c80daff           call 0x466f80
// 006bef24  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006bef28  84c0                 test al, al
// 006bef2a  7511                 jne 0x6bef3d
// 006bef2c  8d430c               lea eax, [ebx + 0xc]
// 006bef2f  50                   push eax
// 006bef30  57                   push edi
// 006bef31  8d4e08               lea ecx, [esi + 8]
// 006bef34  e81743dbff           call 0x473250
// 006bef39  84c0                 test al, al
// 006bef3b  743e                 je 0x6bef7b
// 006bef3d  8b442430             mov eax, dword ptr [esp + 0x30]
// 006bef41  8b4808               mov ecx, dword ptr [eax + 8]
// 006bef44  80793100             cmp byte ptr [ecx + 0x31], 0
// 006bef48  57                   push edi
// 006bef49  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006bef4d  8bce                 mov ecx, esi
// 006bef4f  7415                 je 0x6bef66
// 006bef51  50                   push eax
// 006bef52  6a00                 push 0
// 006bef54  57                   push edi
// 006bef55  e886f9ffff           call 0x6be8e0
// 006bef5a  5d                   pop ebp
// 006bef5b  5b                   pop ebx
// 006bef5c  8bc7                 mov eax, edi
// 006bef5e  5f                   pop edi
// 006bef5f  5e                   pop esi
// 006bef60  83c414               add esp, 0x14
// 006bef63  c21000               ret 0x10
// 006bef66  53                   push ebx
// 006bef67  6a01                 push 1
// 006bef69  57                   push edi
// 006bef6a  e871f9ffff           call 0x6be8e0
// 006bef6f  5d                   pop ebp
// 006bef70  5b                   pop ebx
// 006bef71  8bc7                 mov eax, edi
// 006bef73  5f                   pop edi
// 006bef74  5e                   pop esi
// 006bef75  83c414               add esp, 0x14
// 006bef78  c21000               ret 0x10
// 006bef7b  57                   push edi
// 006bef7c  8d54241c             lea edx, [esp + 0x1c]
// 006bef80  52                   push edx
// 006bef81  8bce                 mov ecx, esi
// 006bef83  e838fcffff           call 0x6bebc0
// 006bef88  8b10                 mov edx, dword ptr [eax]
// 006bef8a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006bef8e  5d                   pop ebp
// 006bef8f  5b                   pop ebx
// 006bef90  8911                 mov dword ptr [ecx], edx
// 006bef92  8b4004               mov eax, dword ptr [eax + 4]
// 006bef95  5f                   pop edi
// 006bef96  894104               mov dword ptr [ecx + 4], eax
// 006bef99  8bc1                 mov eax, ecx
// 006bef9b  5e                   pop esi
// 006bef9c  83c414               add esp, 0x14
// 006bef9f  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
