// from server: 100% by auto
// roc 2010-06 004c6b60  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c6b60
//
// 004c6b60  55                   push ebp
// 004c6b61  8bec                 mov ebp, esp
// 004c6b63  6aff                 push -1
// 004c6b65  6828a39800           push 0x98a328
// 004c6b6a  64a100000000         mov eax, dword ptr fs:[0]
// 004c6b70  50                   push eax
// 004c6b71  64892500000000       mov dword ptr fs:[0], esp
// 004c6b78  83ec10               sub esp, 0x10
// 004c6b7b  53                   push ebx
// 004c6b7c  56                   push esi
// 004c6b7d  57                   push edi
// 004c6b7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004c6b81  8bf1                 mov esi, ecx
// 004c6b83  6a04                 push 4
// 004c6b85  8975ec               mov dword ptr [ebp - 0x14], esi
// 004c6b88  e8130e2e00           call 0x7a79a0
// 004c6b8d  83c404               add esp, 4
// 004c6b90  85c0                 test eax, eax
// 004c6b92  7404                 je 0x4c6b98
// 004c6b94  8930                 mov dword ptr [eax], esi
// 004c6b96  eb02                 jmp 0x4c6b9a
// 004c6b98  33c0                 xor eax, eax
// 004c6b9a  8906                 mov dword ptr [esi], eax
// 004c6b9c  8bce                 mov ecx, esi
// 004c6b9e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004c6ba5  e816a9ffff           call 0x4c14c0
// 004c6baa  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004c6bad  8b3e                 mov edi, dword ptr [esi]
// 004c6baf  894614               mov dword ptr [esi + 0x14], eax
// 004c6bb2  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c6bb9  8b10                 mov edx, dword ptr [eax]
// 004c6bbb  8b4114               mov eax, dword ptr [ecx + 0x14]
// 004c6bbe  8b18                 mov ebx, dword ptr [eax]
// 004c6bc0  8b09                 mov ecx, dword ptr [ecx]
// 004c6bc2  895de8               mov dword ptr [ebp - 0x18], ebx
// 004c6bc5  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004c6bc8  53                   push ebx
// 004c6bc9  50                   push eax
// 004c6bca  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004c6bcd  51                   push ecx
// 004c6bce  50                   push eax
// 004c6bcf  51                   push ecx
// 004c6bd0  52                   push edx
// 004c6bd1  57                   push edi
// 004c6bd2  8bce                 mov ecx, esi
// 004c6bd4  c645fc01             mov byte ptr [ebp - 4], 1
// 004c6bd8  e8f3eaffff           call 0x4c56d0
// 004c6bdd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004c6be0  5f                   pop edi
// 004c6be1  8bc6                 mov eax, esi
// 004c6be3  5e                   pop esi
// 004c6be4  64890d00000000       mov dword ptr fs:[0], ecx
// 004c6beb  5b                   pop ebx
// 004c6bec  8be5                 mov esp, ebp
// 004c6bee  5d                   pop ebp
// 004c6bef  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
