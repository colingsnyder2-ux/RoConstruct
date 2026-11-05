// from server: 100% by auto
// roc 2007-08 004938a0  unit: RBX::Network::VPlayers::?$Notifier  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004938a0
//
// 004938a0  55                   push ebp
// 004938a1  8bec                 mov ebp, esp
// 004938a3  6aff                 push -1
// 004938a5  68007f7400           push 0x747f00
// 004938aa  64a100000000         mov eax, dword ptr fs:[0]
// 004938b0  50                   push eax
// 004938b1  83ec08               sub esp, 8
// 004938b4  53                   push ebx
// 004938b5  56                   push esi
// 004938b6  57                   push edi
// 004938b7  a188518b00           mov eax, dword ptr [0x8b5188]
// 004938bc  33c5                 xor eax, ebp
// 004938be  50                   push eax
// 004938bf  8d45f4               lea eax, [ebp - 0xc]
// 004938c2  64a300000000         mov dword ptr fs:[0], eax
// 004938c8  8965f0               mov dword ptr [ebp - 0x10], esp
// 004938cb  8bf1                 mov esi, ecx
// 004938cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004938d0  e8ab230b00           call 0x545c80
// 004938d5  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004938d8  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004938db  53                   push ebx
// 004938dc  894604               mov dword ptr [esi + 4], eax
// 004938df  c7460800000000       mov dword ptr [esi + 8], 0
// 004938e6  8b5104               mov edx, dword ptr [ecx + 4]
// 004938e9  8b3a                 mov edi, dword ptr [edx]
// 004938eb  8b00                 mov eax, dword ptr [eax]
// 004938ed  52                   push edx
// 004938ee  51                   push ecx
// 004938ef  57                   push edi
// 004938f0  51                   push ecx
// 004938f1  50                   push eax
// 004938f2  56                   push esi
// 004938f3  8bce                 mov ecx, esi
// 004938f5  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004938fc  e83ffaffff           call 0x493340
// 00493901  8bc6                 mov eax, esi
// 00493903  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00493906  64890d00000000       mov dword ptr fs:[0], ecx
// 0049390d  59                   pop ecx
// 0049390e  5f                   pop edi
// 0049390f  5e                   pop esi
// 00493910  5b                   pop ebx
// 00493911  8be5                 mov esp, ebp
// 00493913  5d                   pop ebp
// 00493914  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
