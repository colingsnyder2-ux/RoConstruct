// from server: 100% by auto
// roc 2010-06 00739c80  unit: seg_00730000  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00739c80
//
// 00739c80  83ec14               sub esp, 0x14
// 00739c83  56                   push esi
// 00739c84  8bf1                 mov esi, ecx
// 00739c86  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00739c8a  57                   push edi
// 00739c8b  7521                 jne 0x739cae
// 00739c8d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00739c91  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00739c94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00739c98  50                   push eax
// 00739c99  51                   push ecx
// 00739c9a  6a01                 push 1
// 00739c9c  57                   push edi
// 00739c9d  8bce                 mov ecx, esi
// 00739c9f  e8acfcffff           call 0x739950
// 00739ca4  8bc7                 mov eax, edi
// 00739ca6  5f                   pop edi
// 00739ca7  5e                   pop esi
// 00739ca8  83c414               add esp, 0x14
// 00739cab  c21000               ret 0x10
// 00739cae  8b442424             mov eax, dword ptr [esp + 0x24]
// 00739cb2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00739cb5  8b3a                 mov edi, dword ptr [edx]
// 00739cb7  8b0e                 mov ecx, dword ptr [esi]
// 00739cb9  53                   push ebx
// 00739cba  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00739cc0  85c0                 test eax, eax
// 00739cc2  7404                 je 0x739cc8
// 00739cc4  3bc1                 cmp eax, ecx
// 00739cc6  7406                 je 0x739cce
// 00739cc8  ffd3                 call ebx
// 00739cca  8b442428             mov eax, dword ptr [esp + 0x28]
// 00739cce  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00739cd2  55                   push ebp
// 00739cd3  3bd7                 cmp edx, edi
// 00739cd5  753a                 jne 0x739d11
// 00739cd7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00739cdb  83c20c               add edx, 0xc
// 00739cde  52                   push edx
// 00739cdf  57                   push edi
// 00739ce0  ff151ca59e00         call dword ptr [0x9ea51c]
// 00739ce6  83c408               add esp, 8
// 00739ce9  84c0                 test al, al
// 00739ceb  0f849a010000         je 0x739e8b
// 00739cf1  8b442430             mov eax, dword ptr [esp + 0x30]
// 00739cf5  57                   push edi
// 00739cf6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00739cfa  50                   push eax
// 00739cfb  6a01                 push 1
// 00739cfd  57                   push edi
// 00739cfe  8bce                 mov ecx, esi
// 00739d00  e84bfcffff           call 0x739950
// 00739d05  5d                   pop ebp
// 00739d06  5b                   pop ebx
// 00739d07  8bc7                 mov eax, edi
// 00739d09  5f                   pop edi
// 00739d0a  5e                   pop esi
// 00739d0b  83c414               add esp, 0x14
// 00739d0e  c21000               ret 0x10
// 00739d11  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00739d14  8b0e                 mov ecx, dword ptr [esi]
// 00739d16  85c0                 test eax, eax
// 00739d18  7404                 je 0x739d1e
// 00739d1a  3bc1                 cmp eax, ecx
// 00739d1c  7406                 je 0x739d24
// 00739d1e  ffd3                 call ebx
// 00739d20  8b542430             mov edx, dword ptr [esp + 0x30]
// 00739d24  3bd7                 cmp edx, edi
// 00739d26  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00739d2a  753e                 jne 0x739d6a
// 00739d2c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00739d2f  8b4108               mov eax, dword ptr [ecx + 8]
// 00739d32  83c00c               add eax, 0xc
// 00739d35  57                   push edi
// 00739d36  50                   push eax
// 00739d37  ff151ca59e00         call dword ptr [0x9ea51c]
// 00739d3d  83c408               add esp, 8
// 00739d40  84c0                 test al, al
// 00739d42  0f8443010000         je 0x739e8b
// 00739d48  8b5618               mov edx, dword ptr [esi + 0x18]
// 00739d4b  8b4208               mov eax, dword ptr [edx + 8]
// 00739d4e  57                   push edi
// 00739d4f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00739d53  50                   push eax
// 00739d54  6a00                 push 0
// 00739d56  57                   push edi
// 00739d57  8bce                 mov ecx, esi
// 00739d59  e8f2fbffff           call 0x739950
// 00739d5e  5d                   pop ebp
// 00739d5f  5b                   pop ebx
// 00739d60  8bc7                 mov eax, edi
// 00739d62  5f                   pop edi
// 00739d63  5e                   pop esi
// 00739d64  83c414               add esp, 0x14
// 00739d67  c21000               ret 0x10
// 00739d6a  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 00739d70  83c20c               add edx, 0xc
// 00739d73  52                   push edx
// 00739d74  57                   push edi
// 00739d75  ffd5                 call ebp
// 00739d77  83c408               add esp, 8
// 00739d7a  84c0                 test al, al
// 00739d7c  746c                 je 0x739dea
// 00739d7e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00739d82  8b542430             mov edx, dword ptr [esp + 0x30]
// 00739d86  894c2410             mov dword ptr [esp + 0x10], ecx
// 00739d8a  8d4c2410             lea ecx, [esp + 0x10]
// 00739d8e  89542414             mov dword ptr [esp + 0x14], edx
// 00739d92  e889faffff           call 0x739820
// 00739d97  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00739d9b  57                   push edi
// 00739d9c  8d430c               lea eax, [ebx + 0xc]
// 00739d9f  50                   push eax
// 00739da0  8d4e08               lea ecx, [esi + 8]
// 00739da3  e8a894d3ff           call 0x473250
// 00739da8  84c0                 test al, al
// 00739daa  743e                 je 0x739dea
// 00739dac  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00739daf  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00739db3  57                   push edi
// 00739db4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00739db8  8bce                 mov ecx, esi
// 00739dba  7415                 je 0x739dd1
// 00739dbc  53                   push ebx
// 00739dbd  6a00                 push 0
// 00739dbf  57                   push edi
// 00739dc0  e88bfbffff           call 0x739950
// 00739dc5  5d                   pop ebp
// 00739dc6  5b                   pop ebx
// 00739dc7  8bc7                 mov eax, edi
// 00739dc9  5f                   pop edi
// 00739dca  5e                   pop esi
// 00739dcb  83c414               add esp, 0x14
// 00739dce  c21000               ret 0x10
// 00739dd1  8b542434             mov edx, dword ptr [esp + 0x34]
// 00739dd5  52                   push edx
// 00739dd6  6a01                 push 1
// 00739dd8  57                   push edi
// 00739dd9  e872fbffff           call 0x739950
// 00739dde  5d                   pop ebp
// 00739ddf  5b                   pop ebx
// 00739de0  8bc7                 mov eax, edi
// 00739de2  5f                   pop edi
// 00739de3  5e                   pop esi
// 00739de4  83c414               add esp, 0x14
// 00739de7  c21000               ret 0x10
// 00739dea  8b442430             mov eax, dword ptr [esp + 0x30]
// 00739dee  83c00c               add eax, 0xc
// 00739df1  57                   push edi
// 00739df2  50                   push eax
// 00739df3  ffd5                 call ebp
// 00739df5  83c408               add esp, 8
// 00739df8  84c0                 test al, al
// 00739dfa  0f848b000000         je 0x739e8b
// 00739e00  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00739e04  8b542430             mov edx, dword ptr [esp + 0x30]
// 00739e08  8b4618               mov eax, dword ptr [esi + 0x18]
// 00739e0b  894c2410             mov dword ptr [esp + 0x10], ecx
// 00739e0f  8b0e                 mov ecx, dword ptr [esi]
// 00739e11  894c2418             mov dword ptr [esp + 0x18], ecx
// 00739e15  8d4c2410             lea ecx, [esp + 0x10]
// 00739e19  89542414             mov dword ptr [esp + 0x14], edx
// 00739e1d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00739e21  e81ac41800           call 0x8c6240
// 00739e26  8d542418             lea edx, [esp + 0x18]
// 00739e2a  52                   push edx
// 00739e2b  8d4c2414             lea ecx, [esp + 0x14]
// 00739e2f  e84cd1d2ff           call 0x466f80
// 00739e34  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00739e38  84c0                 test al, al
// 00739e3a  7511                 jne 0x739e4d
// 00739e3c  8d430c               lea eax, [ebx + 0xc]
// 00739e3f  50                   push eax
// 00739e40  57                   push edi
// 00739e41  8d4e08               lea ecx, [esi + 8]
// 00739e44  e80794d3ff           call 0x473250
// 00739e49  84c0                 test al, al
// 00739e4b  743e                 je 0x739e8b
// 00739e4d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00739e51  8b4808               mov ecx, dword ptr [eax + 8]
// 00739e54  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00739e58  57                   push edi
// 00739e59  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00739e5d  8bce                 mov ecx, esi
// 00739e5f  7415                 je 0x739e76
// 00739e61  50                   push eax
// 00739e62  6a00                 push 0
// 00739e64  57                   push edi
// 00739e65  e8e6faffff           call 0x739950
// 00739e6a  5d                   pop ebp
// 00739e6b  5b                   pop ebx
// 00739e6c  8bc7                 mov eax, edi
// 00739e6e  5f                   pop edi
// 00739e6f  5e                   pop esi
// 00739e70  83c414               add esp, 0x14
// 00739e73  c21000               ret 0x10
// 00739e76  53                   push ebx
// 00739e77  6a01                 push 1
// 00739e79  57                   push edi
// 00739e7a  e8d1faffff           call 0x739950
// 00739e7f  5d                   pop ebp
// 00739e80  5b                   pop ebx
// 00739e81  8bc7                 mov eax, edi
// 00739e83  5f                   pop edi
// 00739e84  5e                   pop esi
// 00739e85  83c414               add esp, 0x14
// 00739e88  c21000               ret 0x10
// 00739e8b  57                   push edi
// 00739e8c  8d54241c             lea edx, [esp + 0x1c]
// 00739e90  52                   push edx
// 00739e91  8bce                 mov ecx, esi
// 00739e93  e8b8fcffff           call 0x739b50
// 00739e98  8b10                 mov edx, dword ptr [eax]
// 00739e9a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00739e9e  5d                   pop ebp
// 00739e9f  5b                   pop ebx
// 00739ea0  8911                 mov dword ptr [ecx], edx
// 00739ea2  8b4004               mov eax, dword ptr [eax + 4]
// 00739ea5  5f                   pop edi
// 00739ea6  894104               mov dword ptr [ecx + 4], eax
// 00739ea9  8bc1                 mov eax, ecx
// 00739eab  5e                   pop esi
// 00739eac  83c414               add esp, 0x14
// 00739eaf  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
