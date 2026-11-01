// from server: 100% by auto
// roc 2009-12 00517280  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00517280
//
// 00517280  6aff                 push -1
// 00517282  68d8c59300           push 0x93c5d8
// 00517287  64a100000000         mov eax, dword ptr fs:[0]
// 0051728d  50                   push eax
// 0051728e  64892500000000       mov dword ptr fs:[0], esp
// 00517295  51                   push ecx
// 00517296  56                   push esi
// 00517297  8bf1                 mov esi, ecx
// 00517299  6a04                 push 4
// 0051729b  89742408             mov dword ptr [esp + 8], esi
// 0051729f  e8bcc52d00           call 0x7f3860
// 005172a4  83c404               add esp, 4
// 005172a7  85c0                 test eax, eax
// 005172a9  7404                 je 0x5172af
// 005172ab  8930                 mov dword ptr [eax], esi
// 005172ad  eb02                 jmp 0x5172b1
// 005172af  33c0                 xor eax, eax
// 005172b1  8906                 mov dword ptr [esi], eax
// 005172b3  8bce                 mov ecx, esi
// 005172b5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005172bd  e89ecdffff           call 0x514060
// 005172c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005172c6  894614               mov dword ptr [esi + 0x14], eax
// 005172c9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005172d0  8bc6                 mov eax, esi
// 005172d2  5e                   pop esi
// 005172d3  64890d00000000       mov dword ptr fs:[0], ecx
// 005172da  83c410               add esp, 0x10
// 005172dd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
