// from server: 100% by auto
// roc 2010-06 004e2500  unit: RBX::Network::IdSerializer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e2500
//
// 004e2500  55                   push ebp
// 004e2501  8bec                 mov ebp, esp
// 004e2503  6aff                 push -1
// 004e2505  6831bb9800           push 0x98bb31
// 004e250a  64a100000000         mov eax, dword ptr fs:[0]
// 004e2510  50                   push eax
// 004e2511  64892500000000       mov dword ptr fs:[0], esp
// 004e2518  83ec0c               sub esp, 0xc
// 004e251b  53                   push ebx
// 004e251c  56                   push esi
// 004e251d  57                   push edi
// 004e251e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004e2521  6a30                 push 0x30
// 004e2523  e878542c00           call 0x7a79a0
// 004e2528  8bf0                 mov esi, eax
// 004e252a  83c404               add esp, 4
// 004e252d  8975ec               mov dword ptr [ebp - 0x14], esi
// 004e2530  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004e2537  8975e8               mov dword ptr [ebp - 0x18], esi
// 004e253a  c645fc01             mov byte ptr [ebp - 4], 1
// 004e253e  85f6                 test esi, esi
// 004e2540  7430                 je 0x4e2572
// 004e2542  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004e2545  8b4508               mov eax, dword ptr [ebp + 8]
// 004e2548  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004e254b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004e254e  894e04               mov dword ptr [esi + 4], ecx
// 004e2551  8d7e0c               lea edi, [esi + 0xc]
// 004e2554  53                   push ebx
// 004e2555  8bcf                 mov ecx, edi
// 004e2557  8906                 mov dword ptr [esi], eax
// 004e2559  895608               mov dword ptr [esi + 8], edx
// 004e255c  ff150ca49e00         call dword ptr [0x9ea40c]
// 004e2562  8a431c               mov al, byte ptr [ebx + 0x1c]
// 004e2565  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004e2568  88471c               mov byte ptr [edi + 0x1c], al
// 004e256b  884e2c               mov byte ptr [esi + 0x2c], cl
// 004e256e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004e2572  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e2575  5f                   pop edi
// 004e2576  8bc6                 mov eax, esi
// 004e2578  5e                   pop esi
// 004e2579  64890d00000000       mov dword ptr fs:[0], ecx
// 004e2580  5b                   pop ebx
// 004e2581  8be5                 mov esp, ebp
// 004e2583  5d                   pop ebp
// 004e2584  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
