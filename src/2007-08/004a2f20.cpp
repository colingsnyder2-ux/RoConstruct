// from server: 100% by auto
// roc 2007-08 004a2f20  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2f20
//
// 004a2f20  83ec0c               sub esp, 0xc
// 004a2f23  56                   push esi
// 004a2f24  8bf1                 mov esi, ecx
// 004a2f26  837e0800             cmp dword ptr [esi + 8], 0
// 004a2f2a  57                   push edi
// 004a2f2b  7521                 jne 0x4a2f4e
// 004a2f2d  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a2f31  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2f34  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004a2f38  50                   push eax
// 004a2f39  51                   push ecx
// 004a2f3a  6a01                 push 1
// 004a2f3c  57                   push edi
// 004a2f3d  8bce                 mov ecx, esi
// 004a2f3f  e83cfaffff           call 0x4a2980
// 004a2f44  8bc7                 mov eax, edi
// 004a2f46  5f                   pop edi
// 004a2f47  5e                   pop esi
// 004a2f48  83c40c               add esp, 0xc
// 004a2f4b  c21000               ret 0x10
// 004a2f4e  8b5604               mov edx, dword ptr [esi + 4]
// 004a2f51  8b3a                 mov edi, dword ptr [edx]
// 004a2f53  55                   push ebp
// 004a2f54  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004a2f58  85ed                 test ebp, ebp
// 004a2f5a  7404                 je 0x4a2f60
// 004a2f5c  3bee                 cmp ebp, esi
// 004a2f5e  7406                 je 0x4a2f66
// 004a2f60  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a2f66  53                   push ebx
// 004a2f67  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004a2f6b  3bdf                 cmp ebx, edi
// 004a2f6d  752b                 jne 0x4a2f9a
// 004a2f6f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a2f73  8b07                 mov eax, dword ptr [edi]
// 004a2f75  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 004a2f78  0f8d39010000         jge 0x4a30b7
// 004a2f7e  57                   push edi
// 004a2f7f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a2f83  53                   push ebx
// 004a2f84  6a01                 push 1
// 004a2f86  57                   push edi
// 004a2f87  8bce                 mov ecx, esi
// 004a2f89  e8f2f9ffff           call 0x4a2980
// 004a2f8e  5b                   pop ebx
// 004a2f8f  5d                   pop ebp
// 004a2f90  8bc7                 mov eax, edi
// 004a2f92  5f                   pop edi
// 004a2f93  5e                   pop esi
// 004a2f94  83c40c               add esp, 0xc
// 004a2f97  c21000               ret 0x10
// 004a2f9a  85ed                 test ebp, ebp
// 004a2f9c  8b7e04               mov edi, dword ptr [esi + 4]
// 004a2f9f  7404                 je 0x4a2fa5
// 004a2fa1  3bee                 cmp ebp, esi
// 004a2fa3  7406                 je 0x4a2fab
// 004a2fa5  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a2fab  3bdf                 cmp ebx, edi
// 004a2fad  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a2fb1  752d                 jne 0x4a2fe0
// 004a2fb3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2fb6  8b4108               mov eax, dword ptr [ecx + 8]
// 004a2fb9  8b500c               mov edx, dword ptr [eax + 0xc]
// 004a2fbc  3b17                 cmp edx, dword ptr [edi]
// 004a2fbe  0f8df3000000         jge 0x4a30b7
// 004a2fc4  57                   push edi
// 004a2fc5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a2fc9  50                   push eax
// 004a2fca  6a00                 push 0
// 004a2fcc  57                   push edi
// 004a2fcd  8bce                 mov ecx, esi
// 004a2fcf  e8acf9ffff           call 0x4a2980
// 004a2fd4  5b                   pop ebx
// 004a2fd5  5d                   pop ebp
// 004a2fd6  8bc7                 mov eax, edi
// 004a2fd8  5f                   pop edi
// 004a2fd9  5e                   pop esi
// 004a2fda  83c40c               add esp, 0xc
// 004a2fdd  c21000               ret 0x10
// 004a2fe0  8b07                 mov eax, dword ptr [edi]
// 004a2fe2  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a2fe5  7e5b                 jle 0x4a3042
// 004a2fe7  8d4c2424             lea ecx, [esp + 0x24]
// 004a2feb  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a2fef  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a2ff3  e8b8d3ffff           call 0x4a03b0
// 004a2ff8  8b07                 mov eax, dword ptr [edi]
// 004a2ffa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a2ffe  39410c               cmp dword ptr [ecx + 0xc], eax
// 004a3001  7d3c                 jge 0x4a303f
// 004a3003  8b4108               mov eax, dword ptr [ecx + 8]
// 004a3006  80782100             cmp byte ptr [eax + 0x21], 0
// 004a300a  57                   push edi
// 004a300b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a300f  7417                 je 0x4a3028
// 004a3011  51                   push ecx
// 004a3012  6a00                 push 0
// 004a3014  57                   push edi
// 004a3015  8bce                 mov ecx, esi
// 004a3017  e864f9ffff           call 0x4a2980
// 004a301c  5b                   pop ebx
// 004a301d  5d                   pop ebp
// 004a301e  8bc7                 mov eax, edi
// 004a3020  5f                   pop edi
// 004a3021  5e                   pop esi
// 004a3022  83c40c               add esp, 0xc
// 004a3025  c21000               ret 0x10
// 004a3028  53                   push ebx
// 004a3029  6a01                 push 1
// 004a302b  57                   push edi
// 004a302c  8bce                 mov ecx, esi
// 004a302e  e84df9ffff           call 0x4a2980
// 004a3033  5b                   pop ebx
// 004a3034  5d                   pop ebp
// 004a3035  8bc7                 mov eax, edi
// 004a3037  5f                   pop edi
// 004a3038  5e                   pop esi
// 004a3039  83c40c               add esp, 0xc
// 004a303c  c21000               ret 0x10
// 004a303f  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a3042  7d73                 jge 0x4a30b7
// 004a3044  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a3047  894c2414             mov dword ptr [esp + 0x14], ecx
// 004a304b  8d4c2424             lea ecx, [esp + 0x24]
// 004a304f  896c2424             mov dword ptr [esp + 0x24], ebp
// 004a3053  895c2428             mov dword ptr [esp + 0x28], ebx
// 004a3057  89742410             mov dword ptr [esp + 0x10], esi
// 004a305b  e810d80200           call 0x4d0870
// 004a3060  8d542410             lea edx, [esp + 0x10]
// 004a3064  52                   push edx
// 004a3065  8d4c2428             lea ecx, [esp + 0x28]
// 004a3069  e8423afcff           call 0x466ab0
// 004a306e  84c0                 test al, al
// 004a3070  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a3074  7507                 jne 0x4a307d
// 004a3076  8b0f                 mov ecx, dword ptr [edi]
// 004a3078  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004a307b  7d3a                 jge 0x4a30b7
// 004a307d  8b5308               mov edx, dword ptr [ebx + 8]
// 004a3080  807a2100             cmp byte ptr [edx + 0x21], 0
// 004a3084  57                   push edi
// 004a3085  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3089  8bce                 mov ecx, esi
// 004a308b  7415                 je 0x4a30a2
// 004a308d  53                   push ebx
// 004a308e  6a00                 push 0
// 004a3090  57                   push edi
// 004a3091  e8eaf8ffff           call 0x4a2980
// 004a3096  5b                   pop ebx
// 004a3097  5d                   pop ebp
// 004a3098  8bc7                 mov eax, edi
// 004a309a  5f                   pop edi
// 004a309b  5e                   pop esi
// 004a309c  83c40c               add esp, 0xc
// 004a309f  c21000               ret 0x10
// 004a30a2  50                   push eax
// 004a30a3  6a01                 push 1
// 004a30a5  57                   push edi
// 004a30a6  e8d5f8ffff           call 0x4a2980
// 004a30ab  5b                   pop ebx
// 004a30ac  5d                   pop ebp
// 004a30ad  8bc7                 mov eax, edi
// 004a30af  5f                   pop edi
// 004a30b0  5e                   pop esi
// 004a30b1  83c40c               add esp, 0xc
// 004a30b4  c21000               ret 0x10
// 004a30b7  57                   push edi
// 004a30b8  8d442414             lea eax, [esp + 0x14]
// 004a30bc  50                   push eax
// 004a30bd  8bce                 mov ecx, esi
// 004a30bf  e8acfaffff           call 0x4a2b70
// 004a30c4  8b10                 mov edx, dword ptr [eax]
// 004a30c6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a30ca  5b                   pop ebx
// 004a30cb  5d                   pop ebp
// 004a30cc  8911                 mov dword ptr [ecx], edx
// 004a30ce  8b4004               mov eax, dword ptr [eax + 4]
// 004a30d1  5f                   pop edi
// 004a30d2  894104               mov dword ptr [ecx + 4], eax
// 004a30d5  8bc1                 mov eax, ecx
// 004a30d7  5e                   pop esi
// 004a30d8  83c40c               add esp, 0xc
// 004a30db  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
