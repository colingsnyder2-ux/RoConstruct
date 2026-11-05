// from server: 100% by auto
// roc 2009-06 005fd940  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fd940
//
// 005fd940  83ec14               sub esp, 0x14
// 005fd943  56                   push esi
// 005fd944  8bf1                 mov esi, ecx
// 005fd946  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005fd94a  57                   push edi
// 005fd94b  7521                 jne 0x5fd96e
// 005fd94d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fd951  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005fd954  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005fd958  50                   push eax
// 005fd959  51                   push ecx
// 005fd95a  6a01                 push 1
// 005fd95c  57                   push edi
// 005fd95d  8bce                 mov ecx, esi
// 005fd95f  e8cceeffff           call 0x5fc830
// 005fd964  8bc7                 mov eax, edi
// 005fd966  5f                   pop edi
// 005fd967  5e                   pop esi
// 005fd968  83c414               add esp, 0x14
// 005fd96b  c21000               ret 0x10
// 005fd96e  8b442424             mov eax, dword ptr [esp + 0x24]
// 005fd972  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fd975  8b3a                 mov edi, dword ptr [edx]
// 005fd977  8b0e                 mov ecx, dword ptr [esi]
// 005fd979  53                   push ebx
// 005fd97a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 005fd980  85c0                 test eax, eax
// 005fd982  7404                 je 0x5fd988
// 005fd984  3bc1                 cmp eax, ecx
// 005fd986  7406                 je 0x5fd98e
// 005fd988  ffd3                 call ebx
// 005fd98a  8b442428             mov eax, dword ptr [esp + 0x28]
// 005fd98e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005fd992  55                   push ebp
// 005fd993  3bd7                 cmp edx, edi
// 005fd995  753a                 jne 0x5fd9d1
// 005fd997  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005fd99b  83c20c               add edx, 0xc
// 005fd99e  52                   push edx
// 005fd99f  57                   push edi
// 005fd9a0  ff15e0e48900         call dword ptr [0x89e4e0]
// 005fd9a6  83c408               add esp, 8
// 005fd9a9  84c0                 test al, al
// 005fd9ab  0f849a010000         je 0x5fdb4b
// 005fd9b1  8b442430             mov eax, dword ptr [esp + 0x30]
// 005fd9b5  57                   push edi
// 005fd9b6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005fd9ba  50                   push eax
// 005fd9bb  6a01                 push 1
// 005fd9bd  57                   push edi
// 005fd9be  8bce                 mov ecx, esi
// 005fd9c0  e86beeffff           call 0x5fc830
// 005fd9c5  5d                   pop ebp
// 005fd9c6  5b                   pop ebx
// 005fd9c7  8bc7                 mov eax, edi
// 005fd9c9  5f                   pop edi
// 005fd9ca  5e                   pop esi
// 005fd9cb  83c414               add esp, 0x14
// 005fd9ce  c21000               ret 0x10
// 005fd9d1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005fd9d4  8b0e                 mov ecx, dword ptr [esi]
// 005fd9d6  85c0                 test eax, eax
// 005fd9d8  7404                 je 0x5fd9de
// 005fd9da  3bc1                 cmp eax, ecx
// 005fd9dc  7406                 je 0x5fd9e4
// 005fd9de  ffd3                 call ebx
// 005fd9e0  8b542430             mov edx, dword ptr [esp + 0x30]
// 005fd9e4  3bd7                 cmp edx, edi
// 005fd9e6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005fd9ea  753e                 jne 0x5fda2a
// 005fd9ec  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005fd9ef  8b4108               mov eax, dword ptr [ecx + 8]
// 005fd9f2  83c00c               add eax, 0xc
// 005fd9f5  57                   push edi
// 005fd9f6  50                   push eax
// 005fd9f7  ff15e0e48900         call dword ptr [0x89e4e0]
// 005fd9fd  83c408               add esp, 8
// 005fda00  84c0                 test al, al
// 005fda02  0f8443010000         je 0x5fdb4b
// 005fda08  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fda0b  8b4208               mov eax, dword ptr [edx + 8]
// 005fda0e  57                   push edi
// 005fda0f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005fda13  50                   push eax
// 005fda14  6a00                 push 0
// 005fda16  57                   push edi
// 005fda17  8bce                 mov ecx, esi
// 005fda19  e812eeffff           call 0x5fc830
// 005fda1e  5d                   pop ebp
// 005fda1f  5b                   pop ebx
// 005fda20  8bc7                 mov eax, edi
// 005fda22  5f                   pop edi
// 005fda23  5e                   pop esi
// 005fda24  83c414               add esp, 0x14
// 005fda27  c21000               ret 0x10
// 005fda2a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 005fda30  83c20c               add edx, 0xc
// 005fda33  52                   push edx
// 005fda34  57                   push edi
// 005fda35  ffd5                 call ebp
// 005fda37  83c408               add esp, 8
// 005fda3a  84c0                 test al, al
// 005fda3c  746c                 je 0x5fdaaa
// 005fda3e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005fda42  8b542430             mov edx, dword ptr [esp + 0x30]
// 005fda46  894c2410             mov dword ptr [esp + 0x10], ecx
// 005fda4a  8d4c2410             lea ecx, [esp + 0x10]
// 005fda4e  89542414             mov dword ptr [esp + 0x14], edx
// 005fda52  e8f9daffff           call 0x5fb550
// 005fda57  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005fda5b  57                   push edi
// 005fda5c  8d430c               lea eax, [ebx + 0xc]
// 005fda5f  50                   push eax
// 005fda60  8d4e08               lea ecx, [esi + 8]
// 005fda63  e8a8b5fdff           call 0x5d9010
// 005fda68  84c0                 test al, al
// 005fda6a  743e                 je 0x5fdaaa
// 005fda6c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005fda6f  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005fda73  57                   push edi
// 005fda74  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005fda78  8bce                 mov ecx, esi
// 005fda7a  7415                 je 0x5fda91
// 005fda7c  53                   push ebx
// 005fda7d  6a00                 push 0
// 005fda7f  57                   push edi
// 005fda80  e8abedffff           call 0x5fc830
// 005fda85  5d                   pop ebp
// 005fda86  5b                   pop ebx
// 005fda87  8bc7                 mov eax, edi
// 005fda89  5f                   pop edi
// 005fda8a  5e                   pop esi
// 005fda8b  83c414               add esp, 0x14
// 005fda8e  c21000               ret 0x10
// 005fda91  8b542434             mov edx, dword ptr [esp + 0x34]
// 005fda95  52                   push edx
// 005fda96  6a01                 push 1
// 005fda98  57                   push edi
// 005fda99  e892edffff           call 0x5fc830
// 005fda9e  5d                   pop ebp
// 005fda9f  5b                   pop ebx
// 005fdaa0  8bc7                 mov eax, edi
// 005fdaa2  5f                   pop edi
// 005fdaa3  5e                   pop esi
// 005fdaa4  83c414               add esp, 0x14
// 005fdaa7  c21000               ret 0x10
// 005fdaaa  8b442430             mov eax, dword ptr [esp + 0x30]
// 005fdaae  83c00c               add eax, 0xc
// 005fdab1  57                   push edi
// 005fdab2  50                   push eax
// 005fdab3  ffd5                 call ebp
// 005fdab5  83c408               add esp, 8
// 005fdab8  84c0                 test al, al
// 005fdaba  0f848b000000         je 0x5fdb4b
// 005fdac0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005fdac4  8b542430             mov edx, dword ptr [esp + 0x30]
// 005fdac8  8b4618               mov eax, dword ptr [esi + 0x18]
// 005fdacb  894c2410             mov dword ptr [esp + 0x10], ecx
// 005fdacf  8b0e                 mov ecx, dword ptr [esi]
// 005fdad1  894c2418             mov dword ptr [esp + 0x18], ecx
// 005fdad5  8d4c2410             lea ecx, [esp + 0x10]
// 005fdad9  89542414             mov dword ptr [esp + 0x14], edx
// 005fdadd  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fdae1  e8ba92fbff           call 0x5b6da0
// 005fdae6  8d542418             lea edx, [esp + 0x18]
// 005fdaea  52                   push edx
// 005fdaeb  8d4c2414             lea ecx, [esp + 0x14]
// 005fdaef  e8ac39fcff           call 0x5c14a0
// 005fdaf4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005fdaf8  84c0                 test al, al
// 005fdafa  7511                 jne 0x5fdb0d
// 005fdafc  8d430c               lea eax, [ebx + 0xc]
// 005fdaff  50                   push eax
// 005fdb00  57                   push edi
// 005fdb01  8d4e08               lea ecx, [esi + 8]
// 005fdb04  e807b5fdff           call 0x5d9010
// 005fdb09  84c0                 test al, al
// 005fdb0b  743e                 je 0x5fdb4b
// 005fdb0d  8b442430             mov eax, dword ptr [esp + 0x30]
// 005fdb11  8b4808               mov ecx, dword ptr [eax + 8]
// 005fdb14  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005fdb18  57                   push edi
// 005fdb19  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005fdb1d  8bce                 mov ecx, esi
// 005fdb1f  7415                 je 0x5fdb36
// 005fdb21  50                   push eax
// 005fdb22  6a00                 push 0
// 005fdb24  57                   push edi
// 005fdb25  e806edffff           call 0x5fc830
// 005fdb2a  5d                   pop ebp
// 005fdb2b  5b                   pop ebx
// 005fdb2c  8bc7                 mov eax, edi
// 005fdb2e  5f                   pop edi
// 005fdb2f  5e                   pop esi
// 005fdb30  83c414               add esp, 0x14
// 005fdb33  c21000               ret 0x10
// 005fdb36  53                   push ebx
// 005fdb37  6a01                 push 1
// 005fdb39  57                   push edi
// 005fdb3a  e8f1ecffff           call 0x5fc830
// 005fdb3f  5d                   pop ebp
// 005fdb40  5b                   pop ebx
// 005fdb41  8bc7                 mov eax, edi
// 005fdb43  5f                   pop edi
// 005fdb44  5e                   pop esi
// 005fdb45  83c414               add esp, 0x14
// 005fdb48  c21000               ret 0x10
// 005fdb4b  57                   push edi
// 005fdb4c  8d54241c             lea edx, [esp + 0x1c]
// 005fdb50  52                   push edx
// 005fdb51  8bce                 mov ecx, esi
// 005fdb53  e888f7ffff           call 0x5fd2e0
// 005fdb58  8b10                 mov edx, dword ptr [eax]
// 005fdb5a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005fdb5e  5d                   pop ebp
// 005fdb5f  5b                   pop ebx
// 005fdb60  8911                 mov dword ptr [ecx], edx
// 005fdb62  8b4004               mov eax, dword ptr [eax + 4]
// 005fdb65  5f                   pop edi
// 005fdb66  894104               mov dword ptr [ecx + 4], eax
// 005fdb69  8bc1                 mov eax, ecx
// 005fdb6b  5e                   pop esi
// 005fdb6c  83c414               add esp, 0x14
// 005fdb6f  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
