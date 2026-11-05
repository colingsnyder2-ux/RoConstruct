// from server: 100% by auto
// roc 2009-06 0067f240  unit: RBX::Mechanism  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067f240
//
// 0067f240  6aff                 push -1
// 0067f242  6878ef8600           push 0x86ef78
// 0067f247  64a100000000         mov eax, dword ptr fs:[0]
// 0067f24d  50                   push eax
// 0067f24e  64892500000000       mov dword ptr fs:[0], esp
// 0067f255  51                   push ecx
// 0067f256  56                   push esi
// 0067f257  8bf1                 mov esi, ecx
// 0067f259  6a04                 push 4
// 0067f25b  89742408             mov dword ptr [esp + 8], esi
// 0067f25f  e8d4970900           call 0x718a38
// 0067f264  83c404               add esp, 4
// 0067f267  85c0                 test eax, eax
// 0067f269  7404                 je 0x67f26f
// 0067f26b  8930                 mov dword ptr [eax], esi
// 0067f26d  eb02                 jmp 0x67f271
// 0067f26f  33c0                 xor eax, eax
// 0067f271  8906                 mov dword ptr [esi], eax
// 0067f273  8bce                 mov ecx, esi
// 0067f275  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0067f27d  e8bef9ffff           call 0x67ec40
// 0067f282  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067f286  894618               mov dword ptr [esi + 0x18], eax
// 0067f289  c6401101             mov byte ptr [eax + 0x11], 1
// 0067f28d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f290  894004               mov dword ptr [eax + 4], eax
// 0067f293  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f296  8900                 mov dword ptr [eax], eax
// 0067f298  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f29b  894008               mov dword ptr [eax + 8], eax
// 0067f29e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0067f2a5  8bc6                 mov eax, esi
// 0067f2a7  5e                   pop esi
// 0067f2a8  64890d00000000       mov dword ptr fs:[0], ecx
// 0067f2af  83c410               add esp, 0x10
// 0067f2b2  c20800               ret 8
// standard library set<ptr> (function ??0?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@ABU?$less@PAUT@@@1@ABV?$allocator@PAUT@@@1@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
