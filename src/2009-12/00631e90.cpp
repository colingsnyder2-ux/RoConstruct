// from server: 100% by auto
// roc 2009-12 00631e90  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00631e90
//
// 00631e90  83ec14               sub esp, 0x14
// 00631e93  56                   push esi
// 00631e94  8bf1                 mov esi, ecx
// 00631e96  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00631e9a  57                   push edi
// 00631e9b  7521                 jne 0x631ebe
// 00631e9d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00631ea1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00631ea4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00631ea8  50                   push eax
// 00631ea9  51                   push ecx
// 00631eaa  6a01                 push 1
// 00631eac  57                   push edi
// 00631ead  8bce                 mov ecx, esi
// 00631eaf  e82c8ce4ff           call 0x47aae0
// 00631eb4  8bc7                 mov eax, edi
// 00631eb6  5f                   pop edi
// 00631eb7  5e                   pop esi
// 00631eb8  83c414               add esp, 0x14
// 00631ebb  c21000               ret 0x10
// 00631ebe  8b442424             mov eax, dword ptr [esp + 0x24]
// 00631ec2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00631ec5  8b3a                 mov edi, dword ptr [edx]
// 00631ec7  8b0e                 mov ecx, dword ptr [esi]
// 00631ec9  53                   push ebx
// 00631eca  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00631ed0  85c0                 test eax, eax
// 00631ed2  7404                 je 0x631ed8
// 00631ed4  3bc1                 cmp eax, ecx
// 00631ed6  7406                 je 0x631ede
// 00631ed8  ffd3                 call ebx
// 00631eda  8b442428             mov eax, dword ptr [esp + 0x28]
// 00631ede  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00631ee2  55                   push ebp
// 00631ee3  3bd7                 cmp edx, edi
// 00631ee5  753a                 jne 0x631f21
// 00631ee7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00631eeb  83c20c               add edx, 0xc
// 00631eee  52                   push edx
// 00631eef  57                   push edi
// 00631ef0  ff15d8b59800         call dword ptr [0x98b5d8]
// 00631ef6  83c408               add esp, 8
// 00631ef9  84c0                 test al, al
// 00631efb  0f849a010000         je 0x63209b
// 00631f01  8b442430             mov eax, dword ptr [esp + 0x30]
// 00631f05  57                   push edi
// 00631f06  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00631f0a  50                   push eax
// 00631f0b  6a01                 push 1
// 00631f0d  57                   push edi
// 00631f0e  8bce                 mov ecx, esi
// 00631f10  e8cb8be4ff           call 0x47aae0
// 00631f15  5d                   pop ebp
// 00631f16  5b                   pop ebx
// 00631f17  8bc7                 mov eax, edi
// 00631f19  5f                   pop edi
// 00631f1a  5e                   pop esi
// 00631f1b  83c414               add esp, 0x14
// 00631f1e  c21000               ret 0x10
// 00631f21  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00631f24  8b0e                 mov ecx, dword ptr [esi]
// 00631f26  85c0                 test eax, eax
// 00631f28  7404                 je 0x631f2e
// 00631f2a  3bc1                 cmp eax, ecx
// 00631f2c  7406                 je 0x631f34
// 00631f2e  ffd3                 call ebx
// 00631f30  8b542430             mov edx, dword ptr [esp + 0x30]
// 00631f34  3bd7                 cmp edx, edi
// 00631f36  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00631f3a  753e                 jne 0x631f7a
// 00631f3c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00631f3f  8b4108               mov eax, dword ptr [ecx + 8]
// 00631f42  83c00c               add eax, 0xc
// 00631f45  57                   push edi
// 00631f46  50                   push eax
// 00631f47  ff15d8b59800         call dword ptr [0x98b5d8]
// 00631f4d  83c408               add esp, 8
// 00631f50  84c0                 test al, al
// 00631f52  0f8443010000         je 0x63209b
// 00631f58  8b5618               mov edx, dword ptr [esi + 0x18]
// 00631f5b  8b4208               mov eax, dword ptr [edx + 8]
// 00631f5e  57                   push edi
// 00631f5f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00631f63  50                   push eax
// 00631f64  6a00                 push 0
// 00631f66  57                   push edi
// 00631f67  8bce                 mov ecx, esi
// 00631f69  e8728be4ff           call 0x47aae0
// 00631f6e  5d                   pop ebp
// 00631f6f  5b                   pop ebx
// 00631f70  8bc7                 mov eax, edi
// 00631f72  5f                   pop edi
// 00631f73  5e                   pop esi
// 00631f74  83c414               add esp, 0x14
// 00631f77  c21000               ret 0x10
// 00631f7a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00631f80  83c20c               add edx, 0xc
// 00631f83  52                   push edx
// 00631f84  57                   push edi
// 00631f85  ffd5                 call ebp
// 00631f87  83c408               add esp, 8
// 00631f8a  84c0                 test al, al
// 00631f8c  746c                 je 0x631ffa
// 00631f8e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00631f92  8b542430             mov edx, dword ptr [esp + 0x30]
// 00631f96  894c2410             mov dword ptr [esp + 0x10], ecx
// 00631f9a  8d4c2410             lea ecx, [esp + 0x10]
// 00631f9e  89542414             mov dword ptr [esp + 0x14], edx
// 00631fa2  e859690500           call 0x688900
// 00631fa7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00631fab  57                   push edi
// 00631fac  8d430c               lea eax, [ebx + 0xc]
// 00631faf  50                   push eax
// 00631fb0  8d4e08               lea ecx, [esi + 8]
// 00631fb3  e89888e4ff           call 0x47a850
// 00631fb8  84c0                 test al, al
// 00631fba  743e                 je 0x631ffa
// 00631fbc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00631fbf  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00631fc3  57                   push edi
// 00631fc4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00631fc8  8bce                 mov ecx, esi
// 00631fca  7415                 je 0x631fe1
// 00631fcc  53                   push ebx
// 00631fcd  6a00                 push 0
// 00631fcf  57                   push edi
// 00631fd0  e80b8be4ff           call 0x47aae0
// 00631fd5  5d                   pop ebp
// 00631fd6  5b                   pop ebx
// 00631fd7  8bc7                 mov eax, edi
// 00631fd9  5f                   pop edi
// 00631fda  5e                   pop esi
// 00631fdb  83c414               add esp, 0x14
// 00631fde  c21000               ret 0x10
// 00631fe1  8b542434             mov edx, dword ptr [esp + 0x34]
// 00631fe5  52                   push edx
// 00631fe6  6a01                 push 1
// 00631fe8  57                   push edi
// 00631fe9  e8f28ae4ff           call 0x47aae0
// 00631fee  5d                   pop ebp
// 00631fef  5b                   pop ebx
// 00631ff0  8bc7                 mov eax, edi
// 00631ff2  5f                   pop edi
// 00631ff3  5e                   pop esi
// 00631ff4  83c414               add esp, 0x14
// 00631ff7  c21000               ret 0x10
// 00631ffa  8b442430             mov eax, dword ptr [esp + 0x30]
// 00631ffe  83c00c               add eax, 0xc
// 00632001  57                   push edi
// 00632002  50                   push eax
// 00632003  ffd5                 call ebp
// 00632005  83c408               add esp, 8
// 00632008  84c0                 test al, al
// 0063200a  0f848b000000         je 0x63209b
// 00632010  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00632014  8b542430             mov edx, dword ptr [esp + 0x30]
// 00632018  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063201b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0063201f  8b0e                 mov ecx, dword ptr [esi]
// 00632021  894c2418             mov dword ptr [esp + 0x18], ecx
// 00632025  8d4c2410             lea ecx, [esp + 0x10]
// 00632029  89542414             mov dword ptr [esp + 0x14], edx
// 0063202d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00632031  e8da88e4ff           call 0x47a910
// 00632036  8d542418             lea edx, [esp + 0x18]
// 0063203a  52                   push edx
// 0063203b  8d4c2414             lea ecx, [esp + 0x14]
// 0063203f  e81ca3f9ff           call 0x5cc360
// 00632044  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00632048  84c0                 test al, al
// 0063204a  7511                 jne 0x63205d
// 0063204c  8d430c               lea eax, [ebx + 0xc]
// 0063204f  50                   push eax
// 00632050  57                   push edi
// 00632051  8d4e08               lea ecx, [esi + 8]
// 00632054  e8f787e4ff           call 0x47a850
// 00632059  84c0                 test al, al
// 0063205b  743e                 je 0x63209b
// 0063205d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00632061  8b4808               mov ecx, dword ptr [eax + 8]
// 00632064  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00632068  57                   push edi
// 00632069  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0063206d  8bce                 mov ecx, esi
// 0063206f  7415                 je 0x632086
// 00632071  50                   push eax
// 00632072  6a00                 push 0
// 00632074  57                   push edi
// 00632075  e8668ae4ff           call 0x47aae0
// 0063207a  5d                   pop ebp
// 0063207b  5b                   pop ebx
// 0063207c  8bc7                 mov eax, edi
// 0063207e  5f                   pop edi
// 0063207f  5e                   pop esi
// 00632080  83c414               add esp, 0x14
// 00632083  c21000               ret 0x10
// 00632086  53                   push ebx
// 00632087  6a01                 push 1
// 00632089  57                   push edi
// 0063208a  e8518ae4ff           call 0x47aae0
// 0063208f  5d                   pop ebp
// 00632090  5b                   pop ebx
// 00632091  8bc7                 mov eax, edi
// 00632093  5f                   pop edi
// 00632094  5e                   pop esi
// 00632095  83c414               add esp, 0x14
// 00632098  c21000               ret 0x10
// 0063209b  57                   push edi
// 0063209c  8d54241c             lea edx, [esp + 0x1c]
// 006320a0  52                   push edx
// 006320a1  8bce                 mov ecx, esi
// 006320a3  e8388ce4ff           call 0x47ace0
// 006320a8  8b10                 mov edx, dword ptr [eax]
// 006320aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006320ae  5d                   pop ebp
// 006320af  5b                   pop ebx
// 006320b0  8911                 mov dword ptr [ecx], edx
// 006320b2  8b4004               mov eax, dword ptr [eax + 4]
// 006320b5  5f                   pop edi
// 006320b6  894104               mov dword ptr [ecx + 4], eax
// 006320b9  8bc1                 mov eax, ecx
// 006320bb  5e                   pop esi
// 006320bc  83c414               add esp, 0x14
// 006320bf  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
