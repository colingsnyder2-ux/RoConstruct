// from server: 100% by auto
// roc 2010-06 006efe00  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006efe00
//
// 006efe00  83ec14               sub esp, 0x14
// 006efe03  56                   push esi
// 006efe04  8bf1                 mov esi, ecx
// 006efe06  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006efe0a  57                   push edi
// 006efe0b  7521                 jne 0x6efe2e
// 006efe0d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006efe11  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006efe14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006efe18  50                   push eax
// 006efe19  51                   push ecx
// 006efe1a  6a01                 push 1
// 006efe1c  57                   push edi
// 006efe1d  8bce                 mov ecx, esi
// 006efe1f  e8bc3cd8ff           call 0x473ae0
// 006efe24  8bc7                 mov eax, edi
// 006efe26  5f                   pop edi
// 006efe27  5e                   pop esi
// 006efe28  83c414               add esp, 0x14
// 006efe2b  c21000               ret 0x10
// 006efe2e  8b442424             mov eax, dword ptr [esp + 0x24]
// 006efe32  8b5618               mov edx, dword ptr [esi + 0x18]
// 006efe35  8b3a                 mov edi, dword ptr [edx]
// 006efe37  8b0e                 mov ecx, dword ptr [esi]
// 006efe39  53                   push ebx
// 006efe3a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006efe40  85c0                 test eax, eax
// 006efe42  7404                 je 0x6efe48
// 006efe44  3bc1                 cmp eax, ecx
// 006efe46  7406                 je 0x6efe4e
// 006efe48  ffd3                 call ebx
// 006efe4a  8b442428             mov eax, dword ptr [esp + 0x28]
// 006efe4e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006efe52  55                   push ebp
// 006efe53  3bd7                 cmp edx, edi
// 006efe55  753a                 jne 0x6efe91
// 006efe57  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006efe5b  83c20c               add edx, 0xc
// 006efe5e  52                   push edx
// 006efe5f  57                   push edi
// 006efe60  ff151ca59e00         call dword ptr [0x9ea51c]
// 006efe66  83c408               add esp, 8
// 006efe69  84c0                 test al, al
// 006efe6b  0f849a010000         je 0x6f000b
// 006efe71  8b442430             mov eax, dword ptr [esp + 0x30]
// 006efe75  57                   push edi
// 006efe76  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006efe7a  50                   push eax
// 006efe7b  6a01                 push 1
// 006efe7d  57                   push edi
// 006efe7e  8bce                 mov ecx, esi
// 006efe80  e85b3cd8ff           call 0x473ae0
// 006efe85  5d                   pop ebp
// 006efe86  5b                   pop ebx
// 006efe87  8bc7                 mov eax, edi
// 006efe89  5f                   pop edi
// 006efe8a  5e                   pop esi
// 006efe8b  83c414               add esp, 0x14
// 006efe8e  c21000               ret 0x10
// 006efe91  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006efe94  8b0e                 mov ecx, dword ptr [esi]
// 006efe96  85c0                 test eax, eax
// 006efe98  7404                 je 0x6efe9e
// 006efe9a  3bc1                 cmp eax, ecx
// 006efe9c  7406                 je 0x6efea4
// 006efe9e  ffd3                 call ebx
// 006efea0  8b542430             mov edx, dword ptr [esp + 0x30]
// 006efea4  3bd7                 cmp edx, edi
// 006efea6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006efeaa  753e                 jne 0x6efeea
// 006efeac  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006efeaf  8b4108               mov eax, dword ptr [ecx + 8]
// 006efeb2  83c00c               add eax, 0xc
// 006efeb5  57                   push edi
// 006efeb6  50                   push eax
// 006efeb7  ff151ca59e00         call dword ptr [0x9ea51c]
// 006efebd  83c408               add esp, 8
// 006efec0  84c0                 test al, al
// 006efec2  0f8443010000         je 0x6f000b
// 006efec8  8b5618               mov edx, dword ptr [esi + 0x18]
// 006efecb  8b4208               mov eax, dword ptr [edx + 8]
// 006efece  57                   push edi
// 006efecf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006efed3  50                   push eax
// 006efed4  6a00                 push 0
// 006efed6  57                   push edi
// 006efed7  8bce                 mov ecx, esi
// 006efed9  e8023cd8ff           call 0x473ae0
// 006efede  5d                   pop ebp
// 006efedf  5b                   pop ebx
// 006efee0  8bc7                 mov eax, edi
// 006efee2  5f                   pop edi
// 006efee3  5e                   pop esi
// 006efee4  83c414               add esp, 0x14
// 006efee7  c21000               ret 0x10
// 006efeea  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 006efef0  83c20c               add edx, 0xc
// 006efef3  52                   push edx
// 006efef4  57                   push edi
// 006efef5  ffd5                 call ebp
// 006efef7  83c408               add esp, 8
// 006efefa  84c0                 test al, al
// 006efefc  746c                 je 0x6eff6a
// 006efefe  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006eff02  8b542430             mov edx, dword ptr [esp + 0x30]
// 006eff06  894c2410             mov dword ptr [esp + 0x10], ecx
// 006eff0a  8d4c2410             lea ecx, [esp + 0x10]
// 006eff0e  89542414             mov dword ptr [esp + 0x14], edx
// 006eff12  e8c935d8ff           call 0x4734e0
// 006eff17  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006eff1b  57                   push edi
// 006eff1c  8d430c               lea eax, [ebx + 0xc]
// 006eff1f  50                   push eax
// 006eff20  8d4e08               lea ecx, [esi + 8]
// 006eff23  e82833d8ff           call 0x473250
// 006eff28  84c0                 test al, al
// 006eff2a  743e                 je 0x6eff6a
// 006eff2c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006eff2f  80793100             cmp byte ptr [ecx + 0x31], 0
// 006eff33  57                   push edi
// 006eff34  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006eff38  8bce                 mov ecx, esi
// 006eff3a  7415                 je 0x6eff51
// 006eff3c  53                   push ebx
// 006eff3d  6a00                 push 0
// 006eff3f  57                   push edi
// 006eff40  e89b3bd8ff           call 0x473ae0
// 006eff45  5d                   pop ebp
// 006eff46  5b                   pop ebx
// 006eff47  8bc7                 mov eax, edi
// 006eff49  5f                   pop edi
// 006eff4a  5e                   pop esi
// 006eff4b  83c414               add esp, 0x14
// 006eff4e  c21000               ret 0x10
// 006eff51  8b542434             mov edx, dword ptr [esp + 0x34]
// 006eff55  52                   push edx
// 006eff56  6a01                 push 1
// 006eff58  57                   push edi
// 006eff59  e8823bd8ff           call 0x473ae0
// 006eff5e  5d                   pop ebp
// 006eff5f  5b                   pop ebx
// 006eff60  8bc7                 mov eax, edi
// 006eff62  5f                   pop edi
// 006eff63  5e                   pop esi
// 006eff64  83c414               add esp, 0x14
// 006eff67  c21000               ret 0x10
// 006eff6a  8b442430             mov eax, dword ptr [esp + 0x30]
// 006eff6e  83c00c               add eax, 0xc
// 006eff71  57                   push edi
// 006eff72  50                   push eax
// 006eff73  ffd5                 call ebp
// 006eff75  83c408               add esp, 8
// 006eff78  84c0                 test al, al
// 006eff7a  0f848b000000         je 0x6f000b
// 006eff80  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006eff84  8b542430             mov edx, dword ptr [esp + 0x30]
// 006eff88  8b4618               mov eax, dword ptr [esi + 0x18]
// 006eff8b  894c2410             mov dword ptr [esp + 0x10], ecx
// 006eff8f  8b0e                 mov ecx, dword ptr [esi]
// 006eff91  894c2418             mov dword ptr [esp + 0x18], ecx
// 006eff95  8d4c2410             lea ecx, [esp + 0x10]
// 006eff99  89542414             mov dword ptr [esp + 0x14], edx
// 006eff9d  8944241c             mov dword ptr [esp + 0x1c], eax
// 006effa1  e80af5f6ff           call 0x65f4b0
// 006effa6  8d542418             lea edx, [esp + 0x18]
// 006effaa  52                   push edx
// 006effab  8d4c2414             lea ecx, [esp + 0x14]
// 006effaf  e8cc6fd7ff           call 0x466f80
// 006effb4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006effb8  84c0                 test al, al
// 006effba  7511                 jne 0x6effcd
// 006effbc  8d430c               lea eax, [ebx + 0xc]
// 006effbf  50                   push eax
// 006effc0  57                   push edi
// 006effc1  8d4e08               lea ecx, [esi + 8]
// 006effc4  e88732d8ff           call 0x473250
// 006effc9  84c0                 test al, al
// 006effcb  743e                 je 0x6f000b
// 006effcd  8b442430             mov eax, dword ptr [esp + 0x30]
// 006effd1  8b4808               mov ecx, dword ptr [eax + 8]
// 006effd4  80793100             cmp byte ptr [ecx + 0x31], 0
// 006effd8  57                   push edi
// 006effd9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006effdd  8bce                 mov ecx, esi
// 006effdf  7415                 je 0x6efff6
// 006effe1  50                   push eax
// 006effe2  6a00                 push 0
// 006effe4  57                   push edi
// 006effe5  e8f63ad8ff           call 0x473ae0
// 006effea  5d                   pop ebp
// 006effeb  5b                   pop ebx
// 006effec  8bc7                 mov eax, edi
// 006effee  5f                   pop edi
// 006effef  5e                   pop esi
// 006efff0  83c414               add esp, 0x14
// 006efff3  c21000               ret 0x10
// 006efff6  53                   push ebx
// 006efff7  6a01                 push 1
// 006efff9  57                   push edi
// 006efffa  e8e13ad8ff           call 0x473ae0
// 006effff  5d                   pop ebp
// 006f0000  5b                   pop ebx
// 006f0001  8bc7                 mov eax, edi
// 006f0003  5f                   pop edi
// 006f0004  5e                   pop esi
// 006f0005  83c414               add esp, 0x14
// 006f0008  c21000               ret 0x10
// 006f000b  57                   push edi
// 006f000c  8d54241c             lea edx, [esp + 0x1c]
// 006f0010  52                   push edx
// 006f0011  8bce                 mov ecx, esi
// 006f0013  e8e83fd8ff           call 0x474000
// 006f0018  8b10                 mov edx, dword ptr [eax]
// 006f001a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f001e  5d                   pop ebp
// 006f001f  5b                   pop ebx
// 006f0020  8911                 mov dword ptr [ecx], edx
// 006f0022  8b4004               mov eax, dword ptr [eax + 4]
// 006f0025  5f                   pop edi
// 006f0026  894104               mov dword ptr [ecx + 4], eax
// 006f0029  8bc1                 mov eax, ecx
// 006f002b  5e                   pop esi
// 006f002c  83c414               add esp, 0x14
// 006f002f  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
