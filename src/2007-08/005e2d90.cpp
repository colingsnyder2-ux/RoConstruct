// from server: 100% by auto
// roc 2007-08 005e2d90  unit: RBX::IMovingManager  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e2d90
//
// 005e2d90  83ec0c               sub esp, 0xc
// 005e2d93  56                   push esi
// 005e2d94  8bf1                 mov esi, ecx
// 005e2d96  837e0800             cmp dword ptr [esi + 8], 0
// 005e2d9a  57                   push edi
// 005e2d9b  7521                 jne 0x5e2dbe
// 005e2d9d  8b442424             mov eax, dword ptr [esp + 0x24]
// 005e2da1  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2da4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005e2da8  50                   push eax
// 005e2da9  51                   push ecx
// 005e2daa  6a01                 push 1
// 005e2dac  57                   push edi
// 005e2dad  8bce                 mov ecx, esi
// 005e2daf  e8cc38f8ff           call 0x566680
// 005e2db4  8bc7                 mov eax, edi
// 005e2db6  5f                   pop edi
// 005e2db7  5e                   pop esi
// 005e2db8  83c40c               add esp, 0xc
// 005e2dbb  c21000               ret 0x10
// 005e2dbe  8b5604               mov edx, dword ptr [esi + 4]
// 005e2dc1  8b3a                 mov edi, dword ptr [edx]
// 005e2dc3  55                   push ebp
// 005e2dc4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005e2dc8  85ed                 test ebp, ebp
// 005e2dca  7404                 je 0x5e2dd0
// 005e2dcc  3bee                 cmp ebp, esi
// 005e2dce  7406                 je 0x5e2dd6
// 005e2dd0  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e2dd6  53                   push ebx
// 005e2dd7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005e2ddb  3bdf                 cmp ebx, edi
// 005e2ddd  7536                 jne 0x5e2e15
// 005e2ddf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005e2de3  8d430c               lea eax, [ebx + 0xc]
// 005e2de6  50                   push eax
// 005e2de7  57                   push edi
// 005e2de8  ff1520e67700         call dword ptr [0x77e620]
// 005e2dee  83c408               add esp, 8
// 005e2df1  84c0                 test al, al
// 005e2df3  0f8476010000         je 0x5e2f6f
// 005e2df9  57                   push edi
// 005e2dfa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005e2dfe  53                   push ebx
// 005e2dff  6a01                 push 1
// 005e2e01  57                   push edi
// 005e2e02  8bce                 mov ecx, esi
// 005e2e04  e87738f8ff           call 0x566680
// 005e2e09  5b                   pop ebx
// 005e2e0a  5d                   pop ebp
// 005e2e0b  8bc7                 mov eax, edi
// 005e2e0d  5f                   pop edi
// 005e2e0e  5e                   pop esi
// 005e2e0f  83c40c               add esp, 0xc
// 005e2e12  c21000               ret 0x10
// 005e2e15  85ed                 test ebp, ebp
// 005e2e17  8b7e04               mov edi, dword ptr [esi + 4]
// 005e2e1a  7404                 je 0x5e2e20
// 005e2e1c  3bee                 cmp ebp, esi
// 005e2e1e  7406                 je 0x5e2e26
// 005e2e20  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e2e26  3bdf                 cmp ebx, edi
// 005e2e28  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005e2e2c  753e                 jne 0x5e2e6c
// 005e2e2e  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2e31  8b4108               mov eax, dword ptr [ecx + 8]
// 005e2e34  83c00c               add eax, 0xc
// 005e2e37  57                   push edi
// 005e2e38  50                   push eax
// 005e2e39  ff1520e67700         call dword ptr [0x77e620]
// 005e2e3f  83c408               add esp, 8
// 005e2e42  84c0                 test al, al
// 005e2e44  0f8425010000         je 0x5e2f6f
// 005e2e4a  8b5604               mov edx, dword ptr [esi + 4]
// 005e2e4d  8b4208               mov eax, dword ptr [edx + 8]
// 005e2e50  57                   push edi
// 005e2e51  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005e2e55  50                   push eax
// 005e2e56  6a00                 push 0
// 005e2e58  57                   push edi
// 005e2e59  8bce                 mov ecx, esi
// 005e2e5b  e82038f8ff           call 0x566680
// 005e2e60  5b                   pop ebx
// 005e2e61  5d                   pop ebp
// 005e2e62  8bc7                 mov eax, edi
// 005e2e64  5f                   pop edi
// 005e2e65  5e                   pop esi
// 005e2e66  83c40c               add esp, 0xc
// 005e2e69  c21000               ret 0x10
// 005e2e6c  8d430c               lea eax, [ebx + 0xc]
// 005e2e6f  50                   push eax
// 005e2e70  57                   push edi
// 005e2e71  ff1520e67700         call dword ptr [0x77e620]
// 005e2e77  83c408               add esp, 8
// 005e2e7a  84c0                 test al, al
// 005e2e7c  7463                 je 0x5e2ee1
// 005e2e7e  8d4c2424             lea ecx, [esp + 0x24]
// 005e2e82  896c2424             mov dword ptr [esp + 0x24], ebp
// 005e2e86  895c2428             mov dword ptr [esp + 0x28], ebx
// 005e2e8a  e89105faff           call 0x583420
// 005e2e8f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005e2e93  83c10c               add ecx, 0xc
// 005e2e96  57                   push edi
// 005e2e97  51                   push ecx
// 005e2e98  8bce                 mov ecx, esi
// 005e2e9a  e8611fe6ff           call 0x444e00
// 005e2e9f  84c0                 test al, al
// 005e2ea1  743e                 je 0x5e2ee1
// 005e2ea3  8b442428             mov eax, dword ptr [esp + 0x28]
// 005e2ea7  8b5008               mov edx, dword ptr [eax + 8]
// 005e2eaa  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005e2eae  57                   push edi
// 005e2eaf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005e2eb3  8bce                 mov ecx, esi
// 005e2eb5  7415                 je 0x5e2ecc
// 005e2eb7  50                   push eax
// 005e2eb8  6a00                 push 0
// 005e2eba  57                   push edi
// 005e2ebb  e8c037f8ff           call 0x566680
// 005e2ec0  5b                   pop ebx
// 005e2ec1  5d                   pop ebp
// 005e2ec2  8bc7                 mov eax, edi
// 005e2ec4  5f                   pop edi
// 005e2ec5  5e                   pop esi
// 005e2ec6  83c40c               add esp, 0xc
// 005e2ec9  c21000               ret 0x10
// 005e2ecc  53                   push ebx
// 005e2ecd  6a01                 push 1
// 005e2ecf  57                   push edi
// 005e2ed0  e8ab37f8ff           call 0x566680
// 005e2ed5  5b                   pop ebx
// 005e2ed6  5d                   pop ebp
// 005e2ed7  8bc7                 mov eax, edi
// 005e2ed9  5f                   pop edi
// 005e2eda  5e                   pop esi
// 005e2edb  83c40c               add esp, 0xc
// 005e2ede  c21000               ret 0x10
// 005e2ee1  8d430c               lea eax, [ebx + 0xc]
// 005e2ee4  57                   push edi
// 005e2ee5  50                   push eax
// 005e2ee6  ff1520e67700         call dword ptr [0x77e620]
// 005e2eec  83c408               add esp, 8
// 005e2eef  84c0                 test al, al
// 005e2ef1  747c                 je 0x5e2f6f
// 005e2ef3  8b4604               mov eax, dword ptr [esi + 4]
// 005e2ef6  8d4c2424             lea ecx, [esp + 0x24]
// 005e2efa  896c2424             mov dword ptr [esp + 0x24], ebp
// 005e2efe  895c2428             mov dword ptr [esp + 0x28], ebx
// 005e2f02  89442414             mov dword ptr [esp + 0x14], eax
// 005e2f06  89742410             mov dword ptr [esp + 0x10], esi
// 005e2f0a  e81170ffff           call 0x5d9f20
// 005e2f0f  8d4c2410             lea ecx, [esp + 0x10]
// 005e2f13  51                   push ecx
// 005e2f14  8d4c2428             lea ecx, [esp + 0x28]
// 005e2f18  e8933be8ff           call 0x466ab0
// 005e2f1d  84c0                 test al, al
// 005e2f1f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005e2f23  7510                 jne 0x5e2f35
// 005e2f25  8d550c               lea edx, [ebp + 0xc]
// 005e2f28  52                   push edx
// 005e2f29  57                   push edi
// 005e2f2a  8bce                 mov ecx, esi
// 005e2f2c  e8cf1ee6ff           call 0x444e00
// 005e2f31  84c0                 test al, al
// 005e2f33  743a                 je 0x5e2f6f
// 005e2f35  8b4308               mov eax, dword ptr [ebx + 8]
// 005e2f38  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005e2f3c  57                   push edi
// 005e2f3d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005e2f41  8bce                 mov ecx, esi
// 005e2f43  7415                 je 0x5e2f5a
// 005e2f45  53                   push ebx
// 005e2f46  6a00                 push 0
// 005e2f48  57                   push edi
// 005e2f49  e83237f8ff           call 0x566680
// 005e2f4e  5b                   pop ebx
// 005e2f4f  5d                   pop ebp
// 005e2f50  8bc7                 mov eax, edi
// 005e2f52  5f                   pop edi
// 005e2f53  5e                   pop esi
// 005e2f54  83c40c               add esp, 0xc
// 005e2f57  c21000               ret 0x10
// 005e2f5a  55                   push ebp
// 005e2f5b  6a01                 push 1
// 005e2f5d  57                   push edi
// 005e2f5e  e81d37f8ff           call 0x566680
// 005e2f63  5b                   pop ebx
// 005e2f64  5d                   pop ebp
// 005e2f65  8bc7                 mov eax, edi
// 005e2f67  5f                   pop edi
// 005e2f68  5e                   pop esi
// 005e2f69  83c40c               add esp, 0xc
// 005e2f6c  c21000               ret 0x10
// 005e2f6f  57                   push edi
// 005e2f70  8d4c2414             lea ecx, [esp + 0x14]
// 005e2f74  51                   push ecx
// 005e2f75  8bce                 mov ecx, esi
// 005e2f77  e81401f6ff           call 0x543090
// 005e2f7c  8b10                 mov edx, dword ptr [eax]
// 005e2f7e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005e2f82  5b                   pop ebx
// 005e2f83  5d                   pop ebp
// 005e2f84  8911                 mov dword ptr [ecx], edx
// 005e2f86  8b4004               mov eax, dword ptr [eax + 4]
// 005e2f89  5f                   pop edi
// 005e2f8a  894104               mov dword ptr [ecx + 4], eax
// 005e2f8d  8bc1                 mov eax, ecx
// 005e2f8f  5e                   pop esi
// 005e2f90  83c40c               add esp, 0xc
// 005e2f93  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
