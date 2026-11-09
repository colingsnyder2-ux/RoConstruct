// from server: 100% by auto
// roc 2008-06 0064b2a0  unit: RBX::SleepStage  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064b2a0
//
// 0064b2a0  6aff                 push -1
// 0064b2a2  68e8727d00           push 0x7d72e8
// 0064b2a7  64a100000000         mov eax, dword ptr fs:[0]
// 0064b2ad  50                   push eax
// 0064b2ae  64892500000000       mov dword ptr fs:[0], esp
// 0064b2b5  51                   push ecx
// 0064b2b6  56                   push esi
// 0064b2b7  8bf1                 mov esi, ecx
// 0064b2b9  6a04                 push 4
// 0064b2bb  89742408             mov dword ptr [esp + 8], esi
// 0064b2bf  e85c560500           call 0x6a0920
// 0064b2c4  83c404               add esp, 4
// 0064b2c7  85c0                 test eax, eax
// 0064b2c9  7404                 je 0x64b2cf
// 0064b2cb  8930                 mov dword ptr [eax], esi
// 0064b2cd  eb02                 jmp 0x64b2d1
// 0064b2cf  33c0                 xor eax, eax
// 0064b2d1  8906                 mov dword ptr [esi], eax
// 0064b2d3  8bce                 mov ecx, esi
// 0064b2d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064b2dd  e86efae7ff           call 0x4cad50
// 0064b2e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064b2e6  894618               mov dword ptr [esi + 0x18], eax
// 0064b2e9  c6401101             mov byte ptr [eax + 0x11], 1
// 0064b2ed  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064b2f0  894004               mov dword ptr [eax + 4], eax
// 0064b2f3  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064b2f6  8900                 mov dword ptr [eax], eax
// 0064b2f8  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064b2fb  894008               mov dword ptr [eax + 8], eax
// 0064b2fe  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0064b305  8bc6                 mov eax, esi
// 0064b307  5e                   pop esi
// 0064b308  64890d00000000       mov dword ptr fs:[0], ecx
// 0064b30f  83c410               add esp, 0x10
// 0064b312  c20800               ret 8
// standard library set<ptr> (function ??0?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@ABU?$less@PAUT@@@1@ABV?$allocator@PAUT@@@1@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
