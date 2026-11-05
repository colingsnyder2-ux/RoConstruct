// from server: 100% by auto
// roc 2008-06 00699b30  unit: Ogre::RbxSceneManager  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00699b30
//
// 00699b30  6aff                 push -1
// 00699b32  68e8727d00           push 0x7d72e8
// 00699b37  64a100000000         mov eax, dword ptr fs:[0]
// 00699b3d  50                   push eax
// 00699b3e  64892500000000       mov dword ptr fs:[0], esp
// 00699b45  51                   push ecx
// 00699b46  56                   push esi
// 00699b47  8bf1                 mov esi, ecx
// 00699b49  6a04                 push 4
// 00699b4b  89742408             mov dword ptr [esp + 8], esi
// 00699b4f  e8cc6d0000           call 0x6a0920
// 00699b54  83c404               add esp, 4
// 00699b57  85c0                 test eax, eax
// 00699b59  7404                 je 0x699b5f
// 00699b5b  8930                 mov dword ptr [eax], esi
// 00699b5d  eb02                 jmp 0x699b61
// 00699b5f  33c0                 xor eax, eax
// 00699b61  8906                 mov dword ptr [esi], eax
// 00699b63  8bce                 mov ecx, esi
// 00699b65  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00699b6d  e8ce6bfdff           call 0x670740
// 00699b72  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00699b76  894618               mov dword ptr [esi + 0x18], eax
// 00699b79  c6402d01             mov byte ptr [eax + 0x2d], 1
// 00699b7d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00699b80  894004               mov dword ptr [eax + 4], eax
// 00699b83  8b4618               mov eax, dword ptr [esi + 0x18]
// 00699b86  8900                 mov dword ptr [eax], eax
// 00699b88  8b4618               mov eax, dword ptr [esi + 0x18]
// 00699b8b  894008               mov dword ptr [eax + 8], eax
// 00699b8e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00699b95  8bc6                 mov eax, esi
// 00699b97  5e                   pop esi
// 00699b98  64890d00000000       mov dword ptr fs:[0], ecx
// 00699b9f  83c410               add esp, 0x10
// 00699ba2  c20800               ret 8
// standard library set<pod32> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
