// from server: 100% by auto
// roc 2007-08 004459b0  unit: VCRenderSettings::?$FactoryProduct  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004459b0
//
// 004459b0  83ec0c               sub esp, 0xc
// 004459b3  56                   push esi
// 004459b4  8bf1                 mov esi, ecx
// 004459b6  837e0800             cmp dword ptr [esi + 8], 0
// 004459ba  57                   push edi
// 004459bb  7521                 jne 0x4459de
// 004459bd  8b442424             mov eax, dword ptr [esp + 0x24]
// 004459c1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004459c4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004459c8  50                   push eax
// 004459c9  51                   push ecx
// 004459ca  6a01                 push 1
// 004459cc  57                   push edi
// 004459cd  8bce                 mov ecx, esi
// 004459cf  e8bc3b0200           call 0x469590
// 004459d4  8bc7                 mov eax, edi
// 004459d6  5f                   pop edi
// 004459d7  5e                   pop esi
// 004459d8  83c40c               add esp, 0xc
// 004459db  c21000               ret 0x10
// 004459de  8b5604               mov edx, dword ptr [esi + 4]
// 004459e1  8b3a                 mov edi, dword ptr [edx]
// 004459e3  55                   push ebp
// 004459e4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004459e8  85ed                 test ebp, ebp
// 004459ea  7404                 je 0x4459f0
// 004459ec  3bee                 cmp ebp, esi
// 004459ee  7406                 je 0x4459f6
// 004459f0  ff15d8e67700         call dword ptr [0x77e6d8]
// 004459f6  53                   push ebx
// 004459f7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004459fb  3bdf                 cmp ebx, edi
// 004459fd  7536                 jne 0x445a35
// 004459ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00445a03  8d430c               lea eax, [ebx + 0xc]
// 00445a06  50                   push eax
// 00445a07  57                   push edi
// 00445a08  ff1520e67700         call dword ptr [0x77e620]
// 00445a0e  83c408               add esp, 8
// 00445a11  84c0                 test al, al
// 00445a13  0f8476010000         je 0x445b8f
// 00445a19  57                   push edi
// 00445a1a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445a1e  53                   push ebx
// 00445a1f  6a01                 push 1
// 00445a21  57                   push edi
// 00445a22  8bce                 mov ecx, esi
// 00445a24  e8673b0200           call 0x469590
// 00445a29  5b                   pop ebx
// 00445a2a  5d                   pop ebp
// 00445a2b  8bc7                 mov eax, edi
// 00445a2d  5f                   pop edi
// 00445a2e  5e                   pop esi
// 00445a2f  83c40c               add esp, 0xc
// 00445a32  c21000               ret 0x10
// 00445a35  85ed                 test ebp, ebp
// 00445a37  8b7e04               mov edi, dword ptr [esi + 4]
// 00445a3a  7404                 je 0x445a40
// 00445a3c  3bee                 cmp ebp, esi
// 00445a3e  7406                 je 0x445a46
// 00445a40  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445a46  3bdf                 cmp ebx, edi
// 00445a48  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00445a4c  753e                 jne 0x445a8c
// 00445a4e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445a51  8b4108               mov eax, dword ptr [ecx + 8]
// 00445a54  83c00c               add eax, 0xc
// 00445a57  57                   push edi
// 00445a58  50                   push eax
// 00445a59  ff1520e67700         call dword ptr [0x77e620]
// 00445a5f  83c408               add esp, 8
// 00445a62  84c0                 test al, al
// 00445a64  0f8425010000         je 0x445b8f
// 00445a6a  8b5604               mov edx, dword ptr [esi + 4]
// 00445a6d  8b4208               mov eax, dword ptr [edx + 8]
// 00445a70  57                   push edi
// 00445a71  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445a75  50                   push eax
// 00445a76  6a00                 push 0
// 00445a78  57                   push edi
// 00445a79  8bce                 mov ecx, esi
// 00445a7b  e8103b0200           call 0x469590
// 00445a80  5b                   pop ebx
// 00445a81  5d                   pop ebp
// 00445a82  8bc7                 mov eax, edi
// 00445a84  5f                   pop edi
// 00445a85  5e                   pop esi
// 00445a86  83c40c               add esp, 0xc
// 00445a89  c21000               ret 0x10
// 00445a8c  8d430c               lea eax, [ebx + 0xc]
// 00445a8f  50                   push eax
// 00445a90  57                   push edi
// 00445a91  ff1520e67700         call dword ptr [0x77e620]
// 00445a97  83c408               add esp, 8
// 00445a9a  84c0                 test al, al
// 00445a9c  7463                 je 0x445b01
// 00445a9e  8d4c2424             lea ecx, [esp + 0x24]
// 00445aa2  896c2424             mov dword ptr [esp + 0x24], ebp
// 00445aa6  895c2428             mov dword ptr [esp + 0x28], ebx
// 00445aaa  e871d91300           call 0x583420
// 00445aaf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00445ab3  83c10c               add ecx, 0xc
// 00445ab6  57                   push edi
// 00445ab7  51                   push ecx
// 00445ab8  8bce                 mov ecx, esi
// 00445aba  e841f3ffff           call 0x444e00
// 00445abf  84c0                 test al, al
// 00445ac1  743e                 je 0x445b01
// 00445ac3  8b442428             mov eax, dword ptr [esp + 0x28]
// 00445ac7  8b5008               mov edx, dword ptr [eax + 8]
// 00445aca  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00445ace  57                   push edi
// 00445acf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445ad3  8bce                 mov ecx, esi
// 00445ad5  7415                 je 0x445aec
// 00445ad7  50                   push eax
// 00445ad8  6a00                 push 0
// 00445ada  57                   push edi
// 00445adb  e8b03a0200           call 0x469590
// 00445ae0  5b                   pop ebx
// 00445ae1  5d                   pop ebp
// 00445ae2  8bc7                 mov eax, edi
// 00445ae4  5f                   pop edi
// 00445ae5  5e                   pop esi
// 00445ae6  83c40c               add esp, 0xc
// 00445ae9  c21000               ret 0x10
// 00445aec  53                   push ebx
// 00445aed  6a01                 push 1
// 00445aef  57                   push edi
// 00445af0  e89b3a0200           call 0x469590
// 00445af5  5b                   pop ebx
// 00445af6  5d                   pop ebp
// 00445af7  8bc7                 mov eax, edi
// 00445af9  5f                   pop edi
// 00445afa  5e                   pop esi
// 00445afb  83c40c               add esp, 0xc
// 00445afe  c21000               ret 0x10
// 00445b01  8d430c               lea eax, [ebx + 0xc]
// 00445b04  57                   push edi
// 00445b05  50                   push eax
// 00445b06  ff1520e67700         call dword ptr [0x77e620]
// 00445b0c  83c408               add esp, 8
// 00445b0f  84c0                 test al, al
// 00445b11  747c                 je 0x445b8f
// 00445b13  8b4604               mov eax, dword ptr [esi + 4]
// 00445b16  8d4c2424             lea ecx, [esp + 0x24]
// 00445b1a  896c2424             mov dword ptr [esp + 0x24], ebp
// 00445b1e  895c2428             mov dword ptr [esp + 0x28], ebx
// 00445b22  89442414             mov dword ptr [esp + 0x14], eax
// 00445b26  89742410             mov dword ptr [esp + 0x10], esi
// 00445b2a  e8f1431900           call 0x5d9f20
// 00445b2f  8d4c2410             lea ecx, [esp + 0x10]
// 00445b33  51                   push ecx
// 00445b34  8d4c2428             lea ecx, [esp + 0x28]
// 00445b38  e8730f0200           call 0x466ab0
// 00445b3d  84c0                 test al, al
// 00445b3f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00445b43  7510                 jne 0x445b55
// 00445b45  8d550c               lea edx, [ebp + 0xc]
// 00445b48  52                   push edx
// 00445b49  57                   push edi
// 00445b4a  8bce                 mov ecx, esi
// 00445b4c  e8aff2ffff           call 0x444e00
// 00445b51  84c0                 test al, al
// 00445b53  743a                 je 0x445b8f
// 00445b55  8b4308               mov eax, dword ptr [ebx + 8]
// 00445b58  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00445b5c  57                   push edi
// 00445b5d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445b61  8bce                 mov ecx, esi
// 00445b63  7415                 je 0x445b7a
// 00445b65  53                   push ebx
// 00445b66  6a00                 push 0
// 00445b68  57                   push edi
// 00445b69  e8223a0200           call 0x469590
// 00445b6e  5b                   pop ebx
// 00445b6f  5d                   pop ebp
// 00445b70  8bc7                 mov eax, edi
// 00445b72  5f                   pop edi
// 00445b73  5e                   pop esi
// 00445b74  83c40c               add esp, 0xc
// 00445b77  c21000               ret 0x10
// 00445b7a  55                   push ebp
// 00445b7b  6a01                 push 1
// 00445b7d  57                   push edi
// 00445b7e  e80d3a0200           call 0x469590
// 00445b83  5b                   pop ebx
// 00445b84  5d                   pop ebp
// 00445b85  8bc7                 mov eax, edi
// 00445b87  5f                   pop edi
// 00445b88  5e                   pop esi
// 00445b89  83c40c               add esp, 0xc
// 00445b8c  c21000               ret 0x10
// 00445b8f  57                   push edi
// 00445b90  8d4c2414             lea ecx, [esp + 0x14]
// 00445b94  51                   push ecx
// 00445b95  8bce                 mov ecx, esi
// 00445b97  e8043e0200           call 0x4699a0
// 00445b9c  8b10                 mov edx, dword ptr [eax]
// 00445b9e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00445ba2  5b                   pop ebx
// 00445ba3  5d                   pop ebp
// 00445ba4  8911                 mov dword ptr [ecx], edx
// 00445ba6  8b4004               mov eax, dword ptr [eax + 4]
// 00445ba9  5f                   pop edi
// 00445baa  894104               mov dword ptr [ecx + 4], eax
// 00445bad  8bc1                 mov eax, ecx
// 00445baf  5e                   pop esi
// 00445bb0  83c40c               add esp, 0xc
// 00445bb3  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
