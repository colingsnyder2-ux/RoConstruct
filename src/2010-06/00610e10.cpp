// from server: 100% by auto
// roc 2010-06 00610e10  unit: RBX::VScriptContext::?$FactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00610e10
//
// 00610e10  83ec14               sub esp, 0x14
// 00610e13  56                   push esi
// 00610e14  8bf1                 mov esi, ecx
// 00610e16  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00610e1a  57                   push edi
// 00610e1b  7521                 jne 0x610e3e
// 00610e1d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00610e21  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00610e24  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00610e28  50                   push eax
// 00610e29  51                   push ecx
// 00610e2a  6a01                 push 1
// 00610e2c  57                   push edi
// 00610e2d  8bce                 mov ecx, esi
// 00610e2f  e8ece8ffff           call 0x60f720
// 00610e34  8bc7                 mov eax, edi
// 00610e36  5f                   pop edi
// 00610e37  5e                   pop esi
// 00610e38  83c414               add esp, 0x14
// 00610e3b  c21000               ret 0x10
// 00610e3e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00610e42  8b5618               mov edx, dword ptr [esi + 0x18]
// 00610e45  8b3a                 mov edi, dword ptr [edx]
// 00610e47  8b0e                 mov ecx, dword ptr [esi]
// 00610e49  53                   push ebx
// 00610e4a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00610e50  85c0                 test eax, eax
// 00610e52  7404                 je 0x610e58
// 00610e54  3bc1                 cmp eax, ecx
// 00610e56  7406                 je 0x610e5e
// 00610e58  ffd3                 call ebx
// 00610e5a  8b442428             mov eax, dword ptr [esp + 0x28]
// 00610e5e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00610e62  55                   push ebp
// 00610e63  3bd7                 cmp edx, edi
// 00610e65  753a                 jne 0x610ea1
// 00610e67  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00610e6b  83c20c               add edx, 0xc
// 00610e6e  52                   push edx
// 00610e6f  57                   push edi
// 00610e70  ff151ca59e00         call dword ptr [0x9ea51c]
// 00610e76  83c408               add esp, 8
// 00610e79  84c0                 test al, al
// 00610e7b  0f849a010000         je 0x61101b
// 00610e81  8b442430             mov eax, dword ptr [esp + 0x30]
// 00610e85  57                   push edi
// 00610e86  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00610e8a  50                   push eax
// 00610e8b  6a01                 push 1
// 00610e8d  57                   push edi
// 00610e8e  8bce                 mov ecx, esi
// 00610e90  e88be8ffff           call 0x60f720
// 00610e95  5d                   pop ebp
// 00610e96  5b                   pop ebx
// 00610e97  8bc7                 mov eax, edi
// 00610e99  5f                   pop edi
// 00610e9a  5e                   pop esi
// 00610e9b  83c414               add esp, 0x14
// 00610e9e  c21000               ret 0x10
// 00610ea1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00610ea4  8b0e                 mov ecx, dword ptr [esi]
// 00610ea6  85c0                 test eax, eax
// 00610ea8  7404                 je 0x610eae
// 00610eaa  3bc1                 cmp eax, ecx
// 00610eac  7406                 je 0x610eb4
// 00610eae  ffd3                 call ebx
// 00610eb0  8b542430             mov edx, dword ptr [esp + 0x30]
// 00610eb4  3bd7                 cmp edx, edi
// 00610eb6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00610eba  753e                 jne 0x610efa
// 00610ebc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00610ebf  8b4108               mov eax, dword ptr [ecx + 8]
// 00610ec2  83c00c               add eax, 0xc
// 00610ec5  57                   push edi
// 00610ec6  50                   push eax
// 00610ec7  ff151ca59e00         call dword ptr [0x9ea51c]
// 00610ecd  83c408               add esp, 8
// 00610ed0  84c0                 test al, al
// 00610ed2  0f8443010000         je 0x61101b
// 00610ed8  8b5618               mov edx, dword ptr [esi + 0x18]
// 00610edb  8b4208               mov eax, dword ptr [edx + 8]
// 00610ede  57                   push edi
// 00610edf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00610ee3  50                   push eax
// 00610ee4  6a00                 push 0
// 00610ee6  57                   push edi
// 00610ee7  8bce                 mov ecx, esi
// 00610ee9  e832e8ffff           call 0x60f720
// 00610eee  5d                   pop ebp
// 00610eef  5b                   pop ebx
// 00610ef0  8bc7                 mov eax, edi
// 00610ef2  5f                   pop edi
// 00610ef3  5e                   pop esi
// 00610ef4  83c414               add esp, 0x14
// 00610ef7  c21000               ret 0x10
// 00610efa  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 00610f00  83c20c               add edx, 0xc
// 00610f03  52                   push edx
// 00610f04  57                   push edi
// 00610f05  ffd5                 call ebp
// 00610f07  83c408               add esp, 8
// 00610f0a  84c0                 test al, al
// 00610f0c  746c                 je 0x610f7a
// 00610f0e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00610f12  8b542430             mov edx, dword ptr [esp + 0x30]
// 00610f16  894c2410             mov dword ptr [esp + 0x10], ecx
// 00610f1a  8d4c2410             lea ecx, [esp + 0x10]
// 00610f1e  89542414             mov dword ptr [esp + 0x14], edx
// 00610f22  e8098afdff           call 0x5e9930
// 00610f27  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00610f2b  57                   push edi
// 00610f2c  8d430c               lea eax, [ebx + 0xc]
// 00610f2f  50                   push eax
// 00610f30  8d4e08               lea ecx, [esi + 8]
// 00610f33  e81823e6ff           call 0x473250
// 00610f38  84c0                 test al, al
// 00610f3a  743e                 je 0x610f7a
// 00610f3c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00610f3f  80794900             cmp byte ptr [ecx + 0x49], 0
// 00610f43  57                   push edi
// 00610f44  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00610f48  8bce                 mov ecx, esi
// 00610f4a  7415                 je 0x610f61
// 00610f4c  53                   push ebx
// 00610f4d  6a00                 push 0
// 00610f4f  57                   push edi
// 00610f50  e8cbe7ffff           call 0x60f720
// 00610f55  5d                   pop ebp
// 00610f56  5b                   pop ebx
// 00610f57  8bc7                 mov eax, edi
// 00610f59  5f                   pop edi
// 00610f5a  5e                   pop esi
// 00610f5b  83c414               add esp, 0x14
// 00610f5e  c21000               ret 0x10
// 00610f61  8b542434             mov edx, dword ptr [esp + 0x34]
// 00610f65  52                   push edx
// 00610f66  6a01                 push 1
// 00610f68  57                   push edi
// 00610f69  e8b2e7ffff           call 0x60f720
// 00610f6e  5d                   pop ebp
// 00610f6f  5b                   pop ebx
// 00610f70  8bc7                 mov eax, edi
// 00610f72  5f                   pop edi
// 00610f73  5e                   pop esi
// 00610f74  83c414               add esp, 0x14
// 00610f77  c21000               ret 0x10
// 00610f7a  8b442430             mov eax, dword ptr [esp + 0x30]
// 00610f7e  83c00c               add eax, 0xc
// 00610f81  57                   push edi
// 00610f82  50                   push eax
// 00610f83  ffd5                 call ebp
// 00610f85  83c408               add esp, 8
// 00610f88  84c0                 test al, al
// 00610f8a  0f848b000000         je 0x61101b
// 00610f90  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00610f94  8b542430             mov edx, dword ptr [esp + 0x30]
// 00610f98  8b4618               mov eax, dword ptr [esi + 0x18]
// 00610f9b  894c2410             mov dword ptr [esp + 0x10], ecx
// 00610f9f  8b0e                 mov ecx, dword ptr [esi]
// 00610fa1  894c2418             mov dword ptr [esp + 0x18], ecx
// 00610fa5  8d4c2410             lea ecx, [esp + 0x10]
// 00610fa9  89542414             mov dword ptr [esp + 0x14], edx
// 00610fad  8944241c             mov dword ptr [esp + 0x1c], eax
// 00610fb1  e88aa6ffff           call 0x60b640
// 00610fb6  8d542418             lea edx, [esp + 0x18]
// 00610fba  52                   push edx
// 00610fbb  8d4c2414             lea ecx, [esp + 0x14]
// 00610fbf  e8bc5fe5ff           call 0x466f80
// 00610fc4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00610fc8  84c0                 test al, al
// 00610fca  7511                 jne 0x610fdd
// 00610fcc  8d430c               lea eax, [ebx + 0xc]
// 00610fcf  50                   push eax
// 00610fd0  57                   push edi
// 00610fd1  8d4e08               lea ecx, [esi + 8]
// 00610fd4  e87722e6ff           call 0x473250
// 00610fd9  84c0                 test al, al
// 00610fdb  743e                 je 0x61101b
// 00610fdd  8b442430             mov eax, dword ptr [esp + 0x30]
// 00610fe1  8b4808               mov ecx, dword ptr [eax + 8]
// 00610fe4  80794900             cmp byte ptr [ecx + 0x49], 0
// 00610fe8  57                   push edi
// 00610fe9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00610fed  8bce                 mov ecx, esi
// 00610fef  7415                 je 0x611006
// 00610ff1  50                   push eax
// 00610ff2  6a00                 push 0
// 00610ff4  57                   push edi
// 00610ff5  e826e7ffff           call 0x60f720
// 00610ffa  5d                   pop ebp
// 00610ffb  5b                   pop ebx
// 00610ffc  8bc7                 mov eax, edi
// 00610ffe  5f                   pop edi
// 00610fff  5e                   pop esi
// 00611000  83c414               add esp, 0x14
// 00611003  c21000               ret 0x10
// 00611006  53                   push ebx
// 00611007  6a01                 push 1
// 00611009  57                   push edi
// 0061100a  e811e7ffff           call 0x60f720
// 0061100f  5d                   pop ebp
// 00611010  5b                   pop ebx
// 00611011  8bc7                 mov eax, edi
// 00611013  5f                   pop edi
// 00611014  5e                   pop esi
// 00611015  83c414               add esp, 0x14
// 00611018  c21000               ret 0x10
// 0061101b  57                   push edi
// 0061101c  8d54241c             lea edx, [esp + 0x1c]
// 00611020  52                   push edx
// 00611021  8bce                 mov ecx, esi
// 00611023  e8f8eeffff           call 0x60ff20
// 00611028  8b10                 mov edx, dword ptr [eax]
// 0061102a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061102e  5d                   pop ebp
// 0061102f  5b                   pop ebx
// 00611030  8911                 mov dword ptr [ecx], edx
// 00611032  8b4004               mov eax, dword ptr [eax + 4]
// 00611035  5f                   pop edi
// 00611036  894104               mov dword ptr [ecx + 4], eax
// 00611039  8bc1                 mov eax, ecx
// 0061103b  5e                   pop esi
// 0061103c  83c414               add esp, 0x14
// 0061103f  c21000               ret 0x10
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
