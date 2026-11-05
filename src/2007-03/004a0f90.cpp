// from server: 100% by auto
// roc 2007-03 004a0f90  unit: seg_004a0000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004a0f90
//
// 004a0f90  83ec0c               sub esp, 0xc
// 004a0f93  56                   push esi
// 004a0f94  8bf1                 mov esi, ecx
// 004a0f96  837e0800             cmp dword ptr [esi + 8], 0
// 004a0f9a  57                   push edi
// 004a0f9b  7521                 jne 0x4a0fbe
// 004a0f9d  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a0fa1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a0fa4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004a0fa8  50                   push eax
// 004a0fa9  51                   push ecx
// 004a0faa  6a01                 push 1
// 004a0fac  57                   push edi
// 004a0fad  8bce                 mov ecx, esi
// 004a0faf  e82ce5ffff           call 0x49f4e0
// 004a0fb4  8bc7                 mov eax, edi
// 004a0fb6  5f                   pop edi
// 004a0fb7  5e                   pop esi
// 004a0fb8  83c40c               add esp, 0xc
// 004a0fbb  c21000               ret 0x10
// 004a0fbe  8b5604               mov edx, dword ptr [esi + 4]
// 004a0fc1  8b3a                 mov edi, dword ptr [edx]
// 004a0fc3  55                   push ebp
// 004a0fc4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004a0fc8  85ed                 test ebp, ebp
// 004a0fca  7404                 je 0x4a0fd0
// 004a0fcc  3bee                 cmp ebp, esi
// 004a0fce  7406                 je 0x4a0fd6
// 004a0fd0  ff1544e97700         call dword ptr [0x77e944]
// 004a0fd6  53                   push ebx
// 004a0fd7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004a0fdb  3bdf                 cmp ebx, edi
// 004a0fdd  752b                 jne 0x4a100a
// 004a0fdf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a0fe3  8b07                 mov eax, dword ptr [edi]
// 004a0fe5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 004a0fe8  0f8339010000         jae 0x4a1127
// 004a0fee  57                   push edi
// 004a0fef  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a0ff3  53                   push ebx
// 004a0ff4  6a01                 push 1
// 004a0ff6  57                   push edi
// 004a0ff7  8bce                 mov ecx, esi
// 004a0ff9  e8e2e4ffff           call 0x49f4e0
// 004a0ffe  5b                   pop ebx
// 004a0fff  5d                   pop ebp
// 004a1000  8bc7                 mov eax, edi
// 004a1002  5f                   pop edi
// 004a1003  5e                   pop esi
// 004a1004  83c40c               add esp, 0xc
// 004a1007  c21000               ret 0x10
// 004a100a  85ed                 test ebp, ebp
// 004a100c  8b7e04               mov edi, dword ptr [esi + 4]
// 004a100f  7404                 je 0x4a1015
// 004a1011  3bee                 cmp ebp, esi
// 004a1013  7406                 je 0x4a101b
// 004a1015  ff1544e97700         call dword ptr [0x77e944]
// 004a101b  3bdf                 cmp ebx, edi
// 004a101d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a1021  752d                 jne 0x4a1050
// 004a1023  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a1026  8b4108               mov eax, dword ptr [ecx + 8]
// 004a1029  8b500c               mov edx, dword ptr [eax + 0xc]
// 004a102c  3b17                 cmp edx, dword ptr [edi]
// 004a102e  0f83f3000000         jae 0x4a1127
// 004a1034  57                   push edi
// 004a1035  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a1039  50                   push eax
// 004a103a  6a00                 push 0
// 004a103c  57                   push edi
// 004a103d  8bce                 mov ecx, esi
// 004a103f  e89ce4ffff           call 0x49f4e0
// 004a1044  5b                   pop ebx
// 004a1045  5d                   pop ebp
// 004a1046  8bc7                 mov eax, edi
// 004a1048  5f                   pop edi
// 004a1049  5e                   pop esi
// 004a104a  83c40c               add esp, 0xc
// 004a104d  c21000               ret 0x10
// 004a1050  8b07                 mov eax, dword ptr [edi]
// 004a1052  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a1055  765b                 jbe 0x4a10b2
// 004a1057  8d4c2424             lea ecx, [esp + 0x24]
// 004a105b  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a105f  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a1063  e8a8fe1400           call 0x5f0f10
// 004a1068  8b07                 mov eax, dword ptr [edi]
// 004a106a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a106e  39410c               cmp dword ptr [ecx + 0xc], eax
// 004a1071  733c                 jae 0x4a10af
// 004a1073  8b4108               mov eax, dword ptr [ecx + 8]
// 004a1076  80781900             cmp byte ptr [eax + 0x19], 0
// 004a107a  57                   push edi
// 004a107b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a107f  7417                 je 0x4a1098
// 004a1081  51                   push ecx
// 004a1082  6a00                 push 0
// 004a1084  57                   push edi
// 004a1085  8bce                 mov ecx, esi
// 004a1087  e854e4ffff           call 0x49f4e0
// 004a108c  5b                   pop ebx
// 004a108d  5d                   pop ebp
// 004a108e  8bc7                 mov eax, edi
// 004a1090  5f                   pop edi
// 004a1091  5e                   pop esi
// 004a1092  83c40c               add esp, 0xc
// 004a1095  c21000               ret 0x10
// 004a1098  53                   push ebx
// 004a1099  6a01                 push 1
// 004a109b  57                   push edi
// 004a109c  8bce                 mov ecx, esi
// 004a109e  e83de4ffff           call 0x49f4e0
// 004a10a3  5b                   pop ebx
// 004a10a4  5d                   pop ebp
// 004a10a5  8bc7                 mov eax, edi
// 004a10a7  5f                   pop edi
// 004a10a8  5e                   pop esi
// 004a10a9  83c40c               add esp, 0xc
// 004a10ac  c21000               ret 0x10
// 004a10af  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a10b2  7373                 jae 0x4a1127
// 004a10b4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a10b7  894c2414             mov dword ptr [esp + 0x14], ecx
// 004a10bb  8d4c2424             lea ecx, [esp + 0x24]
// 004a10bf  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a10c3  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a10c7  89742410             mov dword ptr [esp + 0x10], esi
// 004a10cb  e830011500           call 0x5f1200
// 004a10d0  8d542410             lea edx, [esp + 0x10]
// 004a10d4  52                   push edx
// 004a10d5  8d4c2428             lea ecx, [esp + 0x28]
// 004a10d9  e882abfaff           call 0x44bc60
// 004a10de  84c0                 test al, al
// 004a10e0  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a10e4  7507                 jne 0x4a10ed
// 004a10e6  8b0f                 mov ecx, dword ptr [edi]
// 004a10e8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004a10eb  733a                 jae 0x4a1127
// 004a10ed  8b5308               mov edx, dword ptr [ebx + 8]
// 004a10f0  807a1900             cmp byte ptr [edx + 0x19], 0
// 004a10f4  57                   push edi
// 004a10f5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a10f9  8bce                 mov ecx, esi
// 004a10fb  7415                 je 0x4a1112
// 004a10fd  53                   push ebx
// 004a10fe  6a00                 push 0
// 004a1100  57                   push edi
// 004a1101  e8dae3ffff           call 0x49f4e0
// 004a1106  5b                   pop ebx
// 004a1107  5d                   pop ebp
// 004a1108  8bc7                 mov eax, edi
// 004a110a  5f                   pop edi
// 004a110b  5e                   pop esi
// 004a110c  83c40c               add esp, 0xc
// 004a110f  c21000               ret 0x10
// 004a1112  50                   push eax
// 004a1113  6a01                 push 1
// 004a1115  57                   push edi
// 004a1116  e8c5e3ffff           call 0x49f4e0
// 004a111b  5b                   pop ebx
// 004a111c  5d                   pop ebp
// 004a111d  8bc7                 mov eax, edi
// 004a111f  5f                   pop edi
// 004a1120  5e                   pop esi
// 004a1121  83c40c               add esp, 0xc
// 004a1124  c21000               ret 0x10
// 004a1127  57                   push edi
// 004a1128  8d442414             lea eax, [esp + 0x14]
// 004a112c  50                   push eax
// 004a112d  8bce                 mov ecx, esi
// 004a112f  e85cf6ffff           call 0x4a0790
// 004a1134  8b10                 mov edx, dword ptr [eax]
// 004a1136  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a113a  5b                   pop ebx
// 004a113b  5d                   pop ebp
// 004a113c  8911                 mov dword ptr [ecx], edx
// 004a113e  8b4004               mov eax, dword ptr [eax + 4]
// 004a1141  5f                   pop edi
// 004a1142  894104               mov dword ptr [ecx + 4], eax
// 004a1145  8bc1                 mov eax, ecx
// 004a1147  5e                   pop esi
// 004a1148  83c40c               add esp, 0xc
// 004a114b  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
