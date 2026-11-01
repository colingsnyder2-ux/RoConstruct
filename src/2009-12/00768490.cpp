// from server: 100% by auto
// roc 2009-12 00768490  unit: RBX::VInstance::?$NonFactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00768490
//
// 00768490  55                   push ebp
// 00768491  8bec                 mov ebp, esp
// 00768493  6aff                 push -1
// 00768495  6891259500           push 0x952591
// 0076849a  64a100000000         mov eax, dword ptr fs:[0]
// 007684a0  50                   push eax
// 007684a1  64892500000000       mov dword ptr fs:[0], esp
// 007684a8  83ec0c               sub esp, 0xc
// 007684ab  53                   push ebx
// 007684ac  56                   push esi
// 007684ad  57                   push edi
// 007684ae  8965f0               mov dword ptr [ebp - 0x10], esp
// 007684b1  6a34                 push 0x34
// 007684b3  e8a8b30800           call 0x7f3860
// 007684b8  8bf0                 mov esi, eax
// 007684ba  83c404               add esp, 4
// 007684bd  8975ec               mov dword ptr [ebp - 0x14], esi
// 007684c0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007684c7  8975e8               mov dword ptr [ebp - 0x18], esi
// 007684ca  c645fc01             mov byte ptr [ebp - 4], 1
// 007684ce  85f6                 test esi, esi
// 007684d0  7436                 je 0x768508
// 007684d2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 007684d5  8b4508               mov eax, dword ptr [ebp + 8]
// 007684d8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007684db  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 007684de  894e04               mov dword ptr [esi + 4], ecx
// 007684e1  8d7e0c               lea edi, [esi + 0xc]
// 007684e4  53                   push ebx
// 007684e5  8bcf                 mov ecx, edi
// 007684e7  8906                 mov dword ptr [esi], eax
// 007684e9  895608               mov dword ptr [esi + 8], edx
// 007684ec  ff15f0b69800         call dword ptr [0x98b6f0]
// 007684f2  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 007684f5  8a5518               mov dl, byte ptr [ebp + 0x18]
// 007684f8  89471c               mov dword ptr [edi + 0x1c], eax
// 007684fb  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 007684fe  894f20               mov dword ptr [edi + 0x20], ecx
// 00768501  885630               mov byte ptr [esi + 0x30], dl
// 00768504  c6463100             mov byte ptr [esi + 0x31], 0
// 00768508  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0076850b  5f                   pop edi
// 0076850c  8bc6                 mov eax, esi
// 0076850e  5e                   pop esi
// 0076850f  64890d00000000       mov dword ptr fs:[0], ecx
// 00768516  5b                   pop ebx
// 00768517  8be5                 mov esp, ebp
// 00768519  5d                   pop ebp
// 0076851a  c21400               ret 0x14
// standard library map_str<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
