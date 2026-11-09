// from server: 100% by auto
// roc 2009-12 00518f70  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00518f70
//
// 00518f70  55                   push ebp
// 00518f71  8bec                 mov ebp, esp
// 00518f73  6aff                 push -1
// 00518f75  68687d9300           push 0x937d68
// 00518f7a  64a100000000         mov eax, dword ptr fs:[0]
// 00518f80  50                   push eax
// 00518f81  64892500000000       mov dword ptr fs:[0], esp
// 00518f88  83ec10               sub esp, 0x10
// 00518f8b  53                   push ebx
// 00518f8c  56                   push esi
// 00518f8d  57                   push edi
// 00518f8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00518f91  8bf1                 mov esi, ecx
// 00518f93  6a04                 push 4
// 00518f95  8975ec               mov dword ptr [ebp - 0x14], esi
// 00518f98  e8c3a82d00           call 0x7f3860
// 00518f9d  83c404               add esp, 4
// 00518fa0  85c0                 test eax, eax
// 00518fa2  7404                 je 0x518fa8
// 00518fa4  8930                 mov dword ptr [eax], esi
// 00518fa6  eb02                 jmp 0x518faa
// 00518fa8  33c0                 xor eax, eax
// 00518faa  8906                 mov dword ptr [esi], eax
// 00518fac  8bce                 mov ecx, esi
// 00518fae  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00518fb5  e886b0ffff           call 0x514040
// 00518fba  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00518fbd  8b3e                 mov edi, dword ptr [esi]
// 00518fbf  894614               mov dword ptr [esi + 0x14], eax
// 00518fc2  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00518fc9  8b10                 mov edx, dword ptr [eax]
// 00518fcb  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00518fce  8b18                 mov ebx, dword ptr [eax]
// 00518fd0  8b09                 mov ecx, dword ptr [ecx]
// 00518fd2  895de8               mov dword ptr [ebp - 0x18], ebx
// 00518fd5  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00518fd8  53                   push ebx
// 00518fd9  50                   push eax
// 00518fda  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00518fdd  51                   push ecx
// 00518fde  50                   push eax
// 00518fdf  51                   push ecx
// 00518fe0  52                   push edx
// 00518fe1  57                   push edi
// 00518fe2  8bce                 mov ecx, esi
// 00518fe4  c645fc01             mov byte ptr [ebp - 4], 1
// 00518fe8  e863edffff           call 0x517d50
// 00518fed  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00518ff0  5f                   pop edi
// 00518ff1  8bc6                 mov eax, esi
// 00518ff3  5e                   pop esi
// 00518ff4  64890d00000000       mov dword ptr fs:[0], ecx
// 00518ffb  5b                   pop ebx
// 00518ffc  8be5                 mov esp, ebp
// 00518ffe  5d                   pop ebp
// 00518fff  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
