// from server: 100% by auto
// roc 2009-06 004c87e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c87e0
//
// 004c87e0  55                   push ebp
// 004c87e1  8bec                 mov ebp, esp
// 004c87e3  6aff                 push -1
// 004c87e5  6858a18500           push 0x85a158
// 004c87ea  64a100000000         mov eax, dword ptr fs:[0]
// 004c87f0  50                   push eax
// 004c87f1  64892500000000       mov dword ptr fs:[0], esp
// 004c87f8  83ec10               sub esp, 0x10
// 004c87fb  53                   push ebx
// 004c87fc  56                   push esi
// 004c87fd  57                   push edi
// 004c87fe  8965f0               mov dword ptr [ebp - 0x10], esp
// 004c8801  8bf1                 mov esi, ecx
// 004c8803  6a04                 push 4
// 004c8805  8975ec               mov dword ptr [ebp - 0x14], esi
// 004c8808  e82b022500           call 0x718a38
// 004c880d  83c404               add esp, 4
// 004c8810  85c0                 test eax, eax
// 004c8812  7404                 je 0x4c8818
// 004c8814  8930                 mov dword ptr [eax], esi
// 004c8816  eb02                 jmp 0x4c881a
// 004c8818  33c0                 xor eax, eax
// 004c881a  8906                 mov dword ptr [esi], eax
// 004c881c  8bce                 mov ecx, esi
// 004c881e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004c8825  e8c6c5ffff           call 0x4c4df0
// 004c882a  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004c882d  8b3e                 mov edi, dword ptr [esi]
// 004c882f  894614               mov dword ptr [esi + 0x14], eax
// 004c8832  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c8839  8b10                 mov edx, dword ptr [eax]
// 004c883b  8b4114               mov eax, dword ptr [ecx + 0x14]
// 004c883e  8b18                 mov ebx, dword ptr [eax]
// 004c8840  8b09                 mov ecx, dword ptr [ecx]
// 004c8842  895de8               mov dword ptr [ebp - 0x18], ebx
// 004c8845  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004c8848  53                   push ebx
// 004c8849  50                   push eax
// 004c884a  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004c884d  51                   push ecx
// 004c884e  50                   push eax
// 004c884f  51                   push ecx
// 004c8850  52                   push edx
// 004c8851  57                   push edi
// 004c8852  8bce                 mov ecx, esi
// 004c8854  c645fc01             mov byte ptr [ebp - 4], 1
// 004c8858  e8d3f3ffff           call 0x4c7c30
// 004c885d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004c8860  5f                   pop edi
// 004c8861  8bc6                 mov eax, esi
// 004c8863  5e                   pop esi
// 004c8864  64890d00000000       mov dword ptr fs:[0], ecx
// 004c886b  5b                   pop ebx
// 004c886c  8be5                 mov esp, ebp
// 004c886e  5d                   pop ebp
// 004c886f  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
