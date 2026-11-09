// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005715a0  unit: RBX::Reflection::ClassDescriptor  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005715a0
//
// 005715a0  55                   push ebp
// 005715a1  8bec                 mov ebp, esp
// 005715a3  6aff                 push -1
// 005715a5  6818027d00           push 0x7d0218
// 005715aa  64a100000000         mov eax, dword ptr fs:[0]
// 005715b0  50                   push eax
// 005715b1  64892500000000       mov dword ptr fs:[0], esp
// 005715b8  83ec10               sub esp, 0x10
// 005715bb  53                   push ebx
// 005715bc  56                   push esi
// 005715bd  57                   push edi
// 005715be  8965f0               mov dword ptr [ebp - 0x10], esp
// 005715c1  8bf1                 mov esi, ecx
// 005715c3  6a04                 push 4
// 005715c5  8975ec               mov dword ptr [ebp - 0x14], esi
// 005715c8  e853f31200           call 0x6a0920
// 005715cd  83c404               add esp, 4
// 005715d0  85c0                 test eax, eax
// 005715d2  7404                 je 0x5715d8
// 005715d4  8930                 mov dword ptr [eax], esi
// 005715d6  eb02                 jmp 0x5715da
// 005715d8  33c0                 xor eax, eax
// 005715da  8906                 mov dword ptr [esi], eax
// 005715dc  8bce                 mov ecx, esi
// 005715de  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005715e5  e856f7ffff           call 0x570d40
// 005715ea  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005715ed  8b3e                 mov edi, dword ptr [esi]
// 005715ef  894614               mov dword ptr [esi + 0x14], eax
// 005715f2  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005715f9  8b10                 mov edx, dword ptr [eax]
// 005715fb  8b4114               mov eax, dword ptr [ecx + 0x14]
// 005715fe  8b18                 mov ebx, dword ptr [eax]
// 00571600  8b09                 mov ecx, dword ptr [ecx]
// 00571602  895de8               mov dword ptr [ebp - 0x18], ebx
// 00571605  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00571608  53                   push ebx
// 00571609  50                   push eax
// 0057160a  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0057160d  51                   push ecx
// 0057160e  50                   push eax
// 0057160f  51                   push ecx
// 00571610  52                   push edx
// 00571611  57                   push edi
// 00571612  8bce                 mov ecx, esi
// 00571614  c645fc01             mov byte ptr [ebp - 4], 1
// 00571618  e813fcffff           call 0x571230
// 0057161d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00571620  5f                   pop edi
// 00571621  8bc6                 mov eax, esi
// 00571623  5e                   pop esi
// 00571624  64890d00000000       mov dword ptr fs:[0], ecx
// 0057162b  5b                   pop ebx
// 0057162c  8be5                 mov esp, ebp
// 0057162e  5d                   pop ebp
// 0057162f  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
