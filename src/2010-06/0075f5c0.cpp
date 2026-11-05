// from server: 100% by auto
// roc 2010-06 0075f5c0  unit: RBX::SleepStage  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075f5c0
//
// 0075f5c0  6aff                 push -1
// 0075f5c2  6858a29900           push 0x99a258
// 0075f5c7  64a100000000         mov eax, dword ptr fs:[0]
// 0075f5cd  50                   push eax
// 0075f5ce  64892500000000       mov dword ptr fs:[0], esp
// 0075f5d5  51                   push ecx
// 0075f5d6  56                   push esi
// 0075f5d7  8bf1                 mov esi, ecx
// 0075f5d9  6a04                 push 4
// 0075f5db  89742408             mov dword ptr [esp + 8], esi
// 0075f5df  e8bc830400           call 0x7a79a0
// 0075f5e4  83c404               add esp, 4
// 0075f5e7  85c0                 test eax, eax
// 0075f5e9  7404                 je 0x75f5ef
// 0075f5eb  8930                 mov dword ptr [eax], esi
// 0075f5ed  eb02                 jmp 0x75f5f1
// 0075f5ef  33c0                 xor eax, eax
// 0075f5f1  8906                 mov dword ptr [esi], eax
// 0075f5f3  8bce                 mov ecx, esi
// 0075f5f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0075f5fd  e85e85f8ff           call 0x6e7b60
// 0075f602  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0075f606  894618               mov dword ptr [esi + 0x18], eax
// 0075f609  c6401101             mov byte ptr [eax + 0x11], 1
// 0075f60d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075f610  894004               mov dword ptr [eax + 4], eax
// 0075f613  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075f616  8900                 mov dword ptr [eax], eax
// 0075f618  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075f61b  894008               mov dword ptr [eax + 8], eax
// 0075f61e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0075f625  8bc6                 mov eax, esi
// 0075f627  5e                   pop esi
// 0075f628  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f62f  83c410               add esp, 0x10
// 0075f632  c20800               ret 8
// standard library set<ptr> (function ??0?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@ABU?$less@PAUT@@@1@ABV?$allocator@PAUT@@@1@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
