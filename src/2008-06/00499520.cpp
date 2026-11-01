// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00499520  unit: RBX::Network::VPlayers::?$SignalDesc  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00499520
//
// 00499520  55                   push ebp
// 00499521  8bec                 mov ebp, esp
// 00499523  6aff                 push -1
// 00499525  68986e7c00           push 0x7c6e98
// 0049952a  64a100000000         mov eax, dword ptr fs:[0]
// 00499530  50                   push eax
// 00499531  64892500000000       mov dword ptr fs:[0], esp
// 00499538  83ec10               sub esp, 0x10
// 0049953b  53                   push ebx
// 0049953c  56                   push esi
// 0049953d  57                   push edi
// 0049953e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00499541  8bf1                 mov esi, ecx
// 00499543  6a04                 push 4
// 00499545  8975ec               mov dword ptr [ebp - 0x14], esi
// 00499548  e8d3732000           call 0x6a0920
// 0049954d  83c404               add esp, 4
// 00499550  85c0                 test eax, eax
// 00499552  7404                 je 0x499558
// 00499554  8930                 mov dword ptr [eax], esi
// 00499556  eb02                 jmp 0x49955a
// 00499558  33c0                 xor eax, eax
// 0049955a  8906                 mov dword ptr [esi], eax
// 0049955c  8bce                 mov ecx, esi
// 0049955e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00499565  e846d9ffff           call 0x496eb0
// 0049956a  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0049956d  8b3e                 mov edi, dword ptr [esi]
// 0049956f  894614               mov dword ptr [esi + 0x14], eax
// 00499572  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00499579  8b10                 mov edx, dword ptr [eax]
// 0049957b  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0049957e  8b18                 mov ebx, dword ptr [eax]
// 00499580  8b09                 mov ecx, dword ptr [ecx]
// 00499582  895de8               mov dword ptr [ebp - 0x18], ebx
// 00499585  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00499588  53                   push ebx
// 00499589  50                   push eax
// 0049958a  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0049958d  51                   push ecx
// 0049958e  50                   push eax
// 0049958f  51                   push ecx
// 00499590  52                   push edx
// 00499591  57                   push edi
// 00499592  8bce                 mov ecx, esi
// 00499594  c645fc01             mov byte ptr [ebp - 4], 1
// 00499598  e863f9ffff           call 0x498f00
// 0049959d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004995a0  5f                   pop edi
// 004995a1  8bc6                 mov eax, esi
// 004995a3  5e                   pop esi
// 004995a4  64890d00000000       mov dword ptr fs:[0], ecx
// 004995ab  5b                   pop ebx
// 004995ac  8be5                 mov esp, ebp
// 004995ae  5d                   pop ebp
// 004995af  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
