// from server: 100% by auto
// roc 2010-06 00623390  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00623390
//
// 00623390  6aff                 push -1
// 00623392  6858a29900           push 0x99a258
// 00623397  64a100000000         mov eax, dword ptr fs:[0]
// 0062339d  50                   push eax
// 0062339e  64892500000000       mov dword ptr fs:[0], esp
// 006233a5  51                   push ecx
// 006233a6  56                   push esi
// 006233a7  8bf1                 mov esi, ecx
// 006233a9  6a04                 push 4
// 006233ab  89742408             mov dword ptr [esp + 8], esi
// 006233af  e8ec451800           call 0x7a79a0
// 006233b4  83c404               add esp, 4
// 006233b7  85c0                 test eax, eax
// 006233b9  7404                 je 0x6233bf
// 006233bb  8930                 mov dword ptr [eax], esi
// 006233bd  eb02                 jmp 0x6233c1
// 006233bf  33c0                 xor eax, eax
// 006233c1  8906                 mov dword ptr [esi], eax
// 006233c3  8bce                 mov ecx, esi
// 006233c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006233cd  e80e48ecff           call 0x4e7be0
// 006233d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006233d6  894618               mov dword ptr [esi + 0x18], eax
// 006233d9  c6401901             mov byte ptr [eax + 0x19], 1
// 006233dd  8b4618               mov eax, dword ptr [esi + 0x18]
// 006233e0  894004               mov dword ptr [eax + 4], eax
// 006233e3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006233e6  8900                 mov dword ptr [eax], eax
// 006233e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006233eb  894008               mov dword ptr [eax + 8], eax
// 006233ee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006233f5  8bc6                 mov eax, esi
// 006233f7  5e                   pop esi
// 006233f8  64890d00000000       mov dword ptr fs:[0], ecx
// 006233ff  83c410               add esp, 0x10
// 00623402  c20800               ret 8
// standard library set<double> (function ??0?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE@ABU?$less@N@1@ABV?$allocator@N@1@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
