// from server: 100% by auto
// roc 2009-06 005dc2f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dc2f0
//
// 005dc2f0  6aff                 push -1
// 005dc2f2  6878ef8600           push 0x86ef78
// 005dc2f7  64a100000000         mov eax, dword ptr fs:[0]
// 005dc2fd  50                   push eax
// 005dc2fe  64892500000000       mov dword ptr fs:[0], esp
// 005dc305  51                   push ecx
// 005dc306  56                   push esi
// 005dc307  8bf1                 mov esi, ecx
// 005dc309  6a04                 push 4
// 005dc30b  89742408             mov dword ptr [esp + 8], esi
// 005dc30f  e824c71300           call 0x718a38
// 005dc314  83c404               add esp, 4
// 005dc317  85c0                 test eax, eax
// 005dc319  7404                 je 0x5dc31f
// 005dc31b  8930                 mov dword ptr [eax], esi
// 005dc31d  eb02                 jmp 0x5dc321
// 005dc31f  33c0                 xor eax, eax
// 005dc321  8906                 mov dword ptr [esi], eax
// 005dc323  8bce                 mov ecx, esi
// 005dc325  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005dc32d  e8dedfffff           call 0x5da310
// 005dc332  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005dc336  894618               mov dword ptr [esi + 0x18], eax
// 005dc339  c6403d01             mov byte ptr [eax + 0x3d], 1
// 005dc33d  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dc340  894004               mov dword ptr [eax + 4], eax
// 005dc343  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dc346  8900                 mov dword ptr [eax], eax
// 005dc348  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dc34b  894008               mov dword ptr [eax + 8], eax
// 005dc34e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005dc355  8bc6                 mov eax, esi
// 005dc357  5e                   pop esi
// 005dc358  64890d00000000       mov dword ptr fs:[0], ecx
// 005dc35f  83c410               add esp, 0x10
// 005dc362  c20800               ret 8
// standard library set<pod48> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
