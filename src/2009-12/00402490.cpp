// from server: 100% by auto
// roc 2009-12 00402490  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402490
//
// 00402490  6aff                 push -1
// 00402492  68d8c59300           push 0x93c5d8
// 00402497  64a100000000         mov eax, dword ptr fs:[0]
// 0040249d  50                   push eax
// 0040249e  64892500000000       mov dword ptr fs:[0], esp
// 004024a5  51                   push ecx
// 004024a6  56                   push esi
// 004024a7  8bf1                 mov esi, ecx
// 004024a9  6a04                 push 4
// 004024ab  89742408             mov dword ptr [esp + 8], esi
// 004024af  e8ac133f00           call 0x7f3860
// 004024b4  83c404               add esp, 4
// 004024b7  85c0                 test eax, eax
// 004024b9  7404                 je 0x4024bf
// 004024bb  8930                 mov dword ptr [eax], esi
// 004024bd  eb02                 jmp 0x4024c1
// 004024bf  33c0                 xor eax, eax
// 004024c1  8906                 mov dword ptr [esi], eax
// 004024c3  8bce                 mov ecx, esi
// 004024c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004024cd  e87e7f3100           call 0x71a450
// 004024d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004024d6  894618               mov dword ptr [esi + 0x18], eax
// 004024d9  c6401101             mov byte ptr [eax + 0x11], 1
// 004024dd  8b4618               mov eax, dword ptr [esi + 0x18]
// 004024e0  894004               mov dword ptr [eax + 4], eax
// 004024e3  8b4618               mov eax, dword ptr [esi + 0x18]
// 004024e6  8900                 mov dword ptr [eax], eax
// 004024e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004024eb  894008               mov dword ptr [eax + 8], eax
// 004024ee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004024f5  8bc6                 mov eax, esi
// 004024f7  5e                   pop esi
// 004024f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004024ff  83c410               add esp, 0x10
// 00402502  c20800               ret 8
// standard library set<ptr> (function ??0?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@ABU?$less@PAUT@@@1@ABV?$allocator@PAUT@@@1@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
